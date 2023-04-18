/*
 * bootloader.c
 *
 *  Created on: 14 апр. 2023 г.
 *      Author: User
 */


#include "hardware.h"
#include "gui/gui.h"
#include "board.h"
#include "keyboard.h"
#include "encoder.h"
#include "display2.h"

#include "spi.h"	// bootloader_readimage definition
#include "formats.h"

#include "bootloader.h"

#include "audio.h"
#include "codecs.h"

#if WITHFT8
	#include "ft8.h"
#endif /* WITHFT8 */

#if WITHUSEFATFS
	#include "fatfs/ff.h"
#endif /* WITHUSEFATFS */
#if WITHUSEFATFS
	#include "sdcard.h"
#endif /* WITHUSEFATFS */

#include <string.h>
#include <ctype.h>
#include <math.h>


#if WITHISBOOTLOADER

struct stm32_header {
	uint32_t magic_number;
	uint8_t image_signature[64];
	uint32_t image_checksum;
	uint8_t  header_version[4];
	uint32_t image_length;
	uint32_t image_entry_point;
	uint32_t reserved1;
	uint32_t load_address;
	uint32_t reserved2;
	uint32_t version_number;
	uint32_t option_flags;
	uint32_t ecdsa_algorithm;
	uint8_t ecdsa_public_key[64];
	uint8_t padding[83];
	uint8_t binary_type;
} ATTRPACKED;

#define HEADER_MAGIC	0x324d5453  //	__be32_to_cpu(0x53544D32)

static uint_fast8_t bootloader_get_start(
		uintptr_t apparea,	/* целевой адрес для загрузки образа - здесь лежит заголовок файла */
		uintptr_t * ip)
{
	volatile struct stm32_header * const hdr = (volatile struct stm32_header *) apparea;
	uint_fast32_t checksum = hdr->image_checksum;
	uint_fast32_t length = hdr->image_length;
	const uint8_t * p = (const uint8_t *) (uintptr_t) hdr->load_address;
	if (hdr->magic_number != HEADER_MAGIC)
		return 1;
	* ip = hdr->image_entry_point;
	while (length --)
		checksum -= * p ++;
	return checksum != 0;	// возврат 0 если контрольная сумма совпала
}

static uint_fast8_t bootloader_copyapp(
		uint_fast32_t appoffset,	/* смещение заголовка приожения в накопителе */
		uintptr_t * ip
		)
{
	enum { HEADERSIZE = 256 };
	static uint8_t tmpbuff [HEADERSIZE];
	volatile struct stm32_header * const hdr = (volatile struct stm32_header *) tmpbuff;

	bootloader_readimage(appoffset, tmpbuff, HEADERSIZE);
	//printhex(appoffset, tmpbuff, HEADERSIZE);
	if (hdr->magic_number != HEADER_MAGIC)
		return 1;
	* ip = hdr->image_entry_point;
	PRINTF("bootloader_copyapp: ip=%08X (addr=%08X, len=%08X)\n", (unsigned) * ip, (unsigned) hdr->load_address, (unsigned) hdr->image_length);
	bootloader_readimage(appoffset + HEADERSIZE, (void *) (uintptr_t) hdr->load_address, hdr->image_length);
	PRINTF("bootloader_copyapp done.\n");
	return 0;
}

// Сюда попадаем из USB DFU клвсса при приходе команды
// DFU_Detach после USBD_Stop
static void
bootloader_launch_app(uintptr_t ip)
{
	global_disableIRQ();
#if WITHUSBHW
		board_usb_deinitialize();
#endif /* WITHUSBHW */
	dcache_clean_all();

#if (__L2C_PRESENT == 1)
	L2C_Disable();
#endif


#if (__GIC_PRESENT == 1)
	// keep enabled foe CPU1 start
	//GIC_DisableInterface();
	//GIC_DisableDistributor();

	// Disable all IRQs
	{
		// Get ITLinesNumber
		const unsigned n = ((GIC_DistributorInfo() & 0x1f) + 1) * 32;
		unsigned i;
		// 32 - skip SGI handlers (keep enabled for CPU1 start).
		for (i = 32; i < n; ++ i)
			IRQ_Disable(i);
	}
#endif

#if (__CORTEX_A != 0) && CPUSTYLE_ARM && (! defined(__aarch64__))

	MMU_Disable();
	MMU_InvalidateTLB();
	__ISB();
	__DSB();
#endif
	(* (void (*)(void)) ip)();


	for (;;)
		;
}

/* Вызов заказан вызывется из обработчика USB прерываний EP0 */
void bootloader_deffereddetach(void * arg)
{
#if defined (USBD_DFU_RAM_LOADER)
	uintptr_t ip;
	if (bootloader_get_start(USBD_DFU_RAM_LOADER, & ip) == 0)
	{
		PRINTF("bootloader_deffereddetach: ip=%08lX\n", (unsigned long) ip);
		/* Perform an Attach-Detach operation on USB bus */
#if WITHUSBHW
		board_usb_deactivate();
#endif /* WITHUSBHW */
		bootloader_launch_app(ip);
	}
	else
	{
		PRINTF("bootloader_deffereddetach: Header is not loaded to %08lX.\n", (unsigned long) USBD_DFU_RAM_LOADER);
	}
#endif /* defined (USBD_DFU_RAM_LOADER) */
}

#if WITHISBOOTLOADERFATFS

void bootloader_fatfs_mainloop(void)
{
	static const char IMAGENAME [] = WITHISBOOTLOADERIMAGE;
	static FATFSALIGN_BEGIN BYTE header [sizeof (struct stm32_header)] FATFSALIGN_END;
	static RAMNOINIT_D1 FATFS Fatfs;		/* File system object  - нельзя располагать в Cortex-M4 CCM */
	static RAMNOINIT_D1 FIL Fil;			/* Описатель открытого файла - нельзя располагать в Cortex-M4 CCM */
	FRESULT rc;
	UINT br = 0;		//  количество считанных байтов
	struct stm32_header * const hdr = (struct stm32_header *) & header;

	board_set_bglight(1, WITHLCDBACKLIGHTMIN);	// выключить подсветку
	board_update();
	PRINTF("bootloader_fatfs_mainloop start: '%s'\n", IMAGENAME);

	static BYTE targetdrv = 0;
	DSTATUS st = disk_initialize (targetdrv);				/* Physical drive nmuber (0..) */
	if (st != RES_OK)
	{
		PRINTF("disk_initialize code=%02X\n", st);
		PRINTF(" STA_NOINIT = %d\n", STA_NOINIT);
		PRINTF(" STA_NODISK = %d\n", STA_NODISK);
		PRINTF(" STA_PROTECT = %d\n", STA_PROTECT);
		for (;;)
			;
	}
	f_mount(& Fatfs, "", 0);		/* Register volume work area (never fails) */
	// чтение файла
	rc = f_open(& Fil, IMAGENAME, FA_READ);
	if (rc != FR_OK)
	{
		PRINTF("Can not open file '%s'\n", IMAGENAME);
		PRINTF("Failed with rc=%u.\n", rc);
		for (;;)
			;
	}
	rc = f_read(& Fil, header, sizeof header, & br);	/* Read a chunk of file */
	if (rc != FR_OK || br != sizeof (header))
	{
		PRINTF("Can not read header of file '%s'\n", IMAGENAME);
		PRINTF("Failed with rc=%u.\n", rc);
		for (;;)
			;
	}

	uint_fast32_t length = hdr->image_length;
	const uint8_t * p = (const uint8_t *) hdr->load_address;
	if (hdr->magic_number != HEADER_MAGIC)
	{
		PRINTF("Wrong header of file '%s'\n", IMAGENAME);
		for (;;)
			;
	}
	rc = f_read(& Fil, (BYTE *) hdr->load_address, hdr->image_length, & br);	/* Read a chunk of file */
	if (rc != FR_OK || br != hdr->image_length)
	{
		PRINTF("Can not read body of file '%s', rc=%d, hdr->image_length=%08lX, br=%08lX\n", IMAGENAME, (int) rc, (unsigned long) hdr->image_length, (unsigned long) br);
		PRINTF("Failed with rc=%u.\n", rc);
		for (;;)
			;
	}
	uint_fast32_t checksum = hdr->image_checksum;
	while (length --)
		checksum -= * p ++;
	if (checksum != 0)
	{
		PRINTF("Wrong body checksum of file '%s'\n", IMAGENAME);
		for (;;)
			;
	}
	rc = f_close(& Fil);
	if (rc != FR_OK)
	{
		PRINTF("Can not close file '%s'\n", IMAGENAME);
		PRINTF("Failed with rc=%u.\n", rc);
		for (;;)
			;
	}

#if BOOTLOADER_RAMSIZE
	uintptr_t ip;
	if (bootloader_get_start((uintptr_t) header, & ip) != 0)	/* проверка сигнатуры и получение стартового адреса */
	{
		PRINTF("bootloader_fatfs_mainloop start: can not load '%s'\n", IMAGENAME);
		for (;;)
			;
	}
#else
	ASSERT(0);
	for (;;)
		;
#endif /* BOOTLOADER_RAMSIZE */
#if WITHUSBHW
	board_usb_deactivate();
#endif /* WITHUSBHW */
#if BOOTLOADER_RAMSIZE
	PRINTF("bootloader_fatfs_mainloop start: run '%s' at %08lX\n", IMAGENAME, ip);
#if WITHDEBUG
	local_delay_ms(100);
#endif /* WITHDEBUG */
	bootloader_launch_app(ip);
#endif /* BOOTLOADER_RAMSIZE */
}

#else /* WITHISBOOTLOADERFATFS */

void bootloader_mainloop(void)
{
	PRINTF("bootloader_mainloop:\n");
	board_set_bglight(1, WITHLCDBACKLIGHTMIN);	// выключить подсветку
	board_update();

#if BOOTLOADER_RAMSIZE && defined (BOARD_IS_USERBOOT)

	if (BOARD_IS_USERBOOT() == 0)
	{
		/* Нет запроса на вход в режим загрузчика - грузим с QSPI FLASH */
		do
		{
			uintptr_t ip;
			if (bootloader_copyapp(BOOTLOADER_SELFSIZE, & ip) != 0)	/* копирование исполняемого образа (если есть) в требуемое место */
			{
				PRINTF("bootloader_mainloop: No application image\n");
				break;
			}
	#if WITHUSBHW
			board_usb_deactivate();
	#endif /* WITHUSBHW */
			PRINTF("bootloader_mainloop: ip=%08lX\n", (unsigned long) ip);
			bootloader_launch_app(ip);

		} while (0);
	}
#endif /* BOOTLOADER_RAMSIZE && defined (BOARD_IS_USERBOOT) */

	PRINTF("bootloader_mainloop: loop\n");
	/* Обеспечение работы USB DFU */
	for (;;)
	{
		uint_fast8_t kbch, kbready;
		processmessages(& kbch, & kbready, 0, NULL);
		{
			/* здесь можно добавить обработку каких-либо команд с debug порта */
			char c;
			if (dbg_getchar(& c))
			{
				switch (c)
				{
				case 0x00:
					break;
				default:
					PRINTF("key=%02X\n", (unsigned char) c);
					break;

				}
			}
		}
	}
}
#endif /* WITHISBOOTLOADERFATFS */

#endif /* WITHISBOOTLOADER */