/*
 * uart0.c
 *
 *  Created on: 21 сент. 2023 г.
 *      Author: User
 */

#include "hardware.h"
#include "formats.h"
#include "bootloader.h"
#include "board.h"
#include "gpio.h"

#include "xhelper507.h"

#if WITHCTRLBOARDT507

// БИНС основной
// RS-422
#define DEVADDR 1

// Очереди символов для обмена

static u8queue_t txq;
static u8queue_t rxq;

static int nmeaX_putc(int c)
{
	IRQL_t oldIrql;
	uint_fast8_t f;

	do {
		RiseIrql(IRQL_SYSTEM, & oldIrql);
		f = uint8_queue_put(& txq, c);
		LowerIrql(oldIrql);
	} while (! f);
	return c;
}

static void uartX_write(const uint8_t * buff, size_t n)
{
	while (n --)
	{
		const uint8_t c = * buff ++;
		nmeaX_putc(c);
	}
}

static void uartX_format(const char * format, ...)
{
	char b [256];
	int n, i;
	va_list	ap;
	va_start(ap, format);

	n = vsnprintf(b, sizeof b / sizeof b [0], format, ap);

	for (i = 0; i < n; ++ i)
		nmeaX_putc(b [i]);

	va_end(ap);
}



/* вызывается из обработчика прерываний */
// компорт готов передавать
void user_uart3_ontxchar(void * ctx)
{
	uint_fast8_t c;
	if (uint8_queue_get(& txq, & c))
	{
		hardware_uart3_tx(ctx, c);
		if (uint8_queue_empty(& txq))
			hardware_uart3_enabletx(0);
	}
	else
	{
		hardware_uart3_enabletx(0);
	}
}

void user_uart3_onrxchar(uint_fast8_t c)
{
	IRQL_t oldIrql;

	RiseIrql(IRQL_SYSTEM, & oldIrql);
	uint8_queue_put(& rxq, c);
	LowerIrql(oldIrql);
}

void user_uart3_initialize(void)
{
	uint8_queue_init(& txq);
	uint8_queue_init(& rxq);
	hardware_uart3_initialize(0, 921600);
	hardware_uart3_set_speed(921600);
	hardware_uart3_enablerx(1);
	hardware_uart3_enabletx(0);
}

static unsigned culateCRC8(unsigned v, unsigned wCRCWord) {

    static const uint8_t wCRCTable[] = {
        0x00 ,0x31 ,0x62 ,0x53 ,0xC4 ,0xF5 ,0xA6 ,0x97 ,0xB9 ,0x88 ,0xDB ,0xEA ,0x7D ,0x4C ,0x1F ,0x2E,
        0x43 ,0x72 ,0x21 ,0x10 ,0x87 ,0xB6 ,0xE5 ,0xD4 ,0xFA ,0xCB ,0x98 ,0xA9 ,0x3E ,0x0F ,0x5C ,0x6D,
        0x86 ,0xB7 ,0xE4 ,0xD5 ,0x42 ,0x73 ,0x20 ,0x11 ,0x3F ,0x0E ,0x5D ,0x6C ,0xFB ,0xCA ,0x99 ,0xA8,
        0xC5 ,0xF4 ,0xA7 ,0x96 ,0x01 ,0x30 ,0x63 ,0x52 ,0x7C ,0x4D ,0x1E ,0x2F ,0xB8 ,0x89 ,0xDA ,0xEB,
        0x3D ,0x0C ,0x5F ,0x6E ,0xF9 ,0xC8 ,0x9B ,0xAA ,0x84 ,0xB5 ,0xE6 ,0xD7 ,0x40 ,0x71 ,0x22 ,0x13,
        0x7E ,0x4F ,0x1C ,0x2D ,0xBA ,0x8B ,0xD8 ,0xE9 ,0xC7 ,0xF6 ,0xA5 ,0x94 ,0x03 ,0x32 ,0x61 ,0x50,
        0xBB ,0x8A ,0xD9 ,0xE8 ,0x7F ,0x4E ,0x1D ,0x2C ,0x02 ,0x33 ,0x60 ,0x51 ,0xC6 ,0xF7 ,0xA4 ,0x95,
        0xF8 ,0xC9 ,0x9A ,0xAB ,0x3C ,0x0D ,0x5E ,0x6F ,0x41 ,0x70 ,0x23 ,0x12 ,0x85 ,0xB4 ,0xE7 ,0xD6,
        0x7A ,0x4B ,0x18 ,0x29 ,0xBE ,0x8F ,0xDC ,0xED ,0xC3 ,0xF2 ,0xA1 ,0x90 ,0x07 ,0x36 ,0x65 ,0x54,
        0x39 ,0x08 ,0x5B ,0x6A ,0xFD ,0xCC ,0x9F ,0xAE ,0x80 ,0xB1 ,0xE2 ,0xD3 ,0x44 ,0x75 ,0x26 ,0x17,
        0xFC ,0xCD ,0x9E ,0xAF ,0x38 ,0x09 ,0x5A ,0x6B ,0x45 ,0x74 ,0x27 ,0x16 ,0x81 ,0xB0 ,0xE3 ,0xD2,
        0xBF ,0x8E ,0xDD ,0xEC ,0x7B ,0x4A ,0x19 ,0x28 ,0x06 ,0x37 ,0x64 ,0x55 ,0xC2 ,0xF3 ,0xA0 ,0x91,
        0x47 ,0x76 ,0x25 ,0x14 ,0x83 ,0xB2 ,0xE1 ,0xD0 ,0xFE ,0xCF ,0x9C ,0xAD ,0x3A ,0x0B ,0x58 ,0x69,
        0x04 ,0x35 ,0x66 ,0x57 ,0xC0 ,0xF1 ,0xA2 ,0x93 ,0xBD ,0x8C ,0xDF ,0xEE ,0x79 ,0x48 ,0x1B ,0x2A,
        0xC1 ,0xF0 ,0xA3 ,0x92 ,0x05 ,0x34 ,0x67 ,0x56 ,0x78 ,0x49 ,0x1A ,0x2B ,0xBC ,0x8D ,0xDE ,0xEF,
        0x82 ,0xB3 ,0xE0 ,0xD1 ,0x46 ,0x77 ,0x24 ,0x15 ,0x3B ,0x0A ,0x59 ,0x68 ,0xFF ,0xCE ,0x9D ,0xAC
    };

    return wCRCTable [(v ^ wCRCWord) & 0xFF];
}

static unsigned uartX_putc_crc8(int c, unsigned crc)
{
	nmeaX_putc(c);
	crc = culateCRC8(c, crc);
	return crc;
}

static void uartX_write_crc8(const uint8_t * buff, size_t n)
{
	unsigned crc = 0xFF;
	while (n --)
	{
		crc = uartX_putc_crc8(* buff ++, crc);
	}
	uartX_putc_crc8(crc, 0);
}

static unsigned mbuff_uint8(uint8_t * b, uint_fast8_t v)
{
	b [0] = v;
	return 1;
}

static unsigned mbuff_uint32(uint8_t * b, uint_fast32_t v)
{
	b [0] = v >> 0;
	b [1] = v >> 8;
	b [2] = v >> 16;
	b [3] = v >> 24;
	return 4;
}

static unsigned mbuff_float32(uint8_t * b, float v)
{
	union
	{
		float f;
		uint8_t b [sizeof (float)];
	} u;
	u.f = v;
	b [0] = u.b [0];
	b [1] = u.b [1];
	b [2] = u.b [2];
	b [3] = u.b [3];
	return 4;
}

void readregisters(unsigned devaddr, unsigned reg, unsigned numregs)
{
	uint8_t b [32];
	unsigned n = 0;

	n += mbuff_uint8(b + n, 0xFB);	// preamble
	n += mbuff_uint8(b + n, devaddr);	// address
	n += mbuff_uint8(b + n, reg);	// register address
	n += mbuff_uint8(b + n, numregs);	// read one register

	uartX_write_crc8(b, n);
}

// FB 01 01 01 02 00 00 00 7F
void read_HWVersion(void)
{
	readregisters(DEVADDR, 0x01, 1);
}

// CONTROL_0
// FB 01 03 01 01 54 00 01  03
void read_CONTROL_0(void)
{
	readregisters(DEVADDR, 0x03, 1);
}


void uart3_req(void)
{
	readregisters(DEVADDR, 0, 4);
	//readVersion();
	//read_CONTROL_0();
}

enum states
{
	WAITPREAMBLE,
	WAITDEVADDR,
	WAITDEVREG,
	WAITNUMREGS,
	RXREGS,
	WAITCRC

	//
	//allStates
};

enum states st = WAITPREAMBLE;
static unsigned rxcrc;
static unsigned rxregbase;
static unsigned rxreg;
static unsigned rxnumregs;
static uint8_t rxbuff [128];

void uart3_spool(void)
{
	uint_fast8_t c;
	uint_fast8_t f;
	IRQL_t oldIrql;

	RiseIrql(IRQL_SYSTEM, & oldIrql);
    f = uint8_queue_get(& rxq, & c);
	LowerIrql(oldIrql);

	if (f)
	{
		//PRINTF("%02X ", c);
		switch (st)
		{
		case WAITPREAMBLE:
			if (c == 0xFB)
			{
				rxcrc = culateCRC8(c, 0xFF);
				st = WAITDEVADDR;
			}
			break;
		case WAITDEVADDR:
			rxcrc = culateCRC8(c, rxcrc);
			if (c == DEVADDR)
				st = WAITDEVREG;
			else
				st = WAITPREAMBLE;
			break;
		case WAITDEVREG:
			rxcrc = culateCRC8(c, rxcrc);
			rxregbase = c;	// start register of device
			st = WAITNUMREGS;
			break;
		case WAITNUMREGS:
			rxcrc = culateCRC8(c, rxcrc);
			rxnumregs = (c & 0x7F);
			rxreg = 0;
			st = RXREGS;
			break;
		case RXREGS:
			rxcrc = culateCRC8(c, rxcrc);
			if (rxreg >= ARRAY_SIZE(rxbuff))
				st = WAITPREAMBLE;
			else
			{
				rxbuff [rxreg ++] = c;
				if (rxreg >= (rxnumregs * 4))
					st = WAITCRC;
			}
			break;
		case WAITCRC:
			rxcrc = culateCRC8(c, rxcrc);
			if (rxcrc == 0)
			{
				printhex(0, rxbuff, rxreg);
			}
			else
			{
				PRINTF("bad CRC\n");
			}
			st = WAITPREAMBLE;
			break;
		}
	}

}


#endif /* WITHCTRLBOARDT507 */

