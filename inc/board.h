/* $Id$ */
/* Pin manipulation functioms */
//
// Проект HF Dream Receiver (КВ приёмник мечты)
// автор Гена Завидовский mgs2001@mail.ru
// UA1ARN
//

#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void board_reset(void);			// выдача сигнала reset_n
void board_initialize(void);
//void board_init_io2(void);	// debug
void board_init_chips(void);
void board_init_chips2(void);

void board_rtc_getdate(
	uint_fast16_t * year,
	uint_fast8_t * month,
	uint_fast8_t * dayofmonth
	);
void board_rtc_gettime(
	uint_fast8_t * hour,
	uint_fast8_t * minute,
	uint_fast8_t * seconds
	);
void board_rtc_getdatetime(
	uint_fast16_t * year,
	uint_fast8_t * month,	// 01-12
	uint_fast8_t * dayofmonth,
	uint_fast8_t * hour,
	uint_fast8_t * minute,
	uint_fast8_t * seconds
	);
void board_rtc_getdatetime_low(
	volatile uint_fast16_t * year,
	volatile uint_fast8_t * month,	// 01-12
	volatile uint_fast8_t * dayofmonth,
	volatile uint_fast8_t * hour,
	volatile uint_fast8_t * minute,
	volatile uint_fast8_t * seconds
	);

// функции без задержек на чтение из аппаратного RTC
void board_rtc_cached_getdate(
	uint_fast16_t * year,
	uint_fast8_t * month,
	uint_fast8_t * dayofmonth
	);
void board_rtc_cached_gettime(
	uint_fast8_t * hour,
	uint_fast8_t * minute,
	uint_fast8_t * seconds
	);
void board_rtc_cached_getdatetime(
	uint_fast16_t * year,
	uint_fast8_t * month,	// 01-12
	uint_fast8_t * dayofmonth,
	uint_fast8_t * hour,
	uint_fast8_t * minute,
	uint_fast8_t * seconds
	);

void board_rtc_setdate(
	uint_fast16_t year,
	uint_fast8_t month,
	uint_fast8_t dayofmonth
	);
void board_rtc_settime(
	uint_fast8_t hour,
	uint_fast8_t minute,
	uint_fast8_t seconds
	);
void board_rtc_setdatetime(
	uint_fast16_t year,
	uint_fast8_t month,
	uint_fast8_t dayofmonth,
	uint_fast8_t hour,
	uint_fast8_t minute,
	uint_fast8_t seconds
	);
uint_fast8_t board_rtc_chip_initialize(void);
void board_get_compile_datetime(
	uint_fast16_t * year,
	uint_fast8_t * month,	// 01-12
	uint_fast8_t * dayofmonth,
	uint_fast8_t * hour,
	uint_fast8_t * minute,
	uint_fast8_t * seconds
	);

void board_get_serialnr(uint_fast32_t * sn);

#if defined (NVRAM_TYPE) && (NVRAM_TYPE != NVRAM_TYPE_NOTHING)

	void nvram_initialize(void);
	void nvram_set_abytes(uint_fast8_t v);
	#ifndef NVRAM_END
		#error NVRAM_END required, may be missing NVRAM_TYPE
	#endif
	#if (NVRAM_END > 255)
		typedef uint_least16_t nvramaddress_t;				/* можно сделать 8 бит. смещение в NVRAM. Если MENUNONVRAM - только меняем в памяти */
	#else /* (NVRAM_END > 255) */
		typedef uint_least8_t nvramaddress_t;				/* можно сделать 8 бит. смещение в NVRAM. Если MENUNONVRAM - только меняем в памяти */
	#endif /* (NVRAM_END > 255) */

#else /* defined (NVRAM_TYPE) && (NVRAM_TYPE != NVRAM_TYPE_NOTHING) */

	typedef uint_least16_t nvramaddress_t;				/* можно сделать 8 бит. смещение в NVRAM. Если MENUNONVRAM - только меняем в памяти */

#endif /* defined (NVRAM_TYPE) && (NVRAM_TYPE != NVRAM_TYPE_NOTHING) */

void save_i32(nvramaddress_t addr, uint_fast32_t v);	/* сохранение по указанному индексу в FRAM одного 32-битного слова */
uint_fast32_t restore_i32(nvramaddress_t addr); /* выборка по указанному индексу из FRAM одного 32-битного слова */
void save_i16(nvramaddress_t addr, uint_fast16_t v); /* сохранение по указанному индексу в FRAM одного 16-битного слова */
uint_fast16_t restore_i16(nvramaddress_t addr); /* выборка по указанному индексу из FRAM одного 16-битного слова */
void save_i8(nvramaddress_t addr, uint_fast8_t v); /* сохранение по указанному индексу в FRAM одного байта */
uint_fast8_t restore_i8(nvramaddress_t addr); /* выборка по указанному индексу из FRAM одного байта */


/* получить значение forward & reflected ADC */
adcvalholder_t board_getswrmeter(
	adcvalholder_t * reflected, 	// в знаяениях АЦП
	uint_fast8_t swrcalibr	// 90..110 - коррекция
	);
/* получить значение forward & reflected ADC - для работы автотюнера */
adcvalholder_t board_getswrmeter_unfiltered(
	adcvalholder_t * reflected, 	// в знаяениях АЦП
	uint_fast8_t swrcalibr	// 90..110 - коррекция
	);	
uint_fast8_t board_getpwrmeter(
	uint_fast8_t * toptrace	// peak hold
	); 

uint_fast16_t
mcp3208_read(
	spitarget_t target,
	uint_fast8_t diff,
	uint_fast8_t adci,
	uint_fast8_t * valid
	);

uint_fast16_t
mcp3208_read_low(
	spitarget_t target,
	uint_fast8_t diff,
	uint_fast8_t adci,
	uint_fast8_t * valid
	);

void board_adc_initialize(void);
void board_usb_initialize(void);
void board_usb_activate(void);
void board_usb_deactivate(void);
void board_usb_deinitialize(void);
void board_usb_spool(void);
void board_usbh_polling(void);

void board_gpu_initialize(void);	// Graphic processor unit


uint_fast8_t hardware_usbd_get_vbusnow(void);
uint_fast8_t hardware_usbd_get_vbusbefore(void);

uint_fast8_t board_get_adcinputs(void);	/* получить количество каналов АЦП, задействованных в устройстве */
uint_fast8_t board_get_adcch(uint_fast8_t index);	/* получить канал АЦП но индексу в таблице */

void board_adc_store_data(uint_fast8_t i, adcvalholder_t v);

adcvalholder_t filter_hyst(
	adcvalholder_t * pv0, 
	adcvalholder_t raw
	);

void 
modemchangefreq(
	uint_fast32_t f		// частота, которую устанавливаем по команде от modem
	);

void 
modemchangespeed(
	uint_fast32_t speed100		// скорость, которую устанавливаем по команде от modem
	);

void 
modemchangemode(
	uint_fast32_t modemmode		// режим, который устанавливаем по команде от modem
	);


uint_fast8_t board_getadc_filtered_u8(uint_fast8_t i, uint_fast8_t lower, uint_fast8_t upper);	/* получить значение от АЦП в диапазоне lower..upper (включая границы) */
uint_fast8_t board_getpot_filtered_u8(uint_fast8_t i, uint_fast8_t lower, uint_fast8_t upper, adcvalholder_t * data);	/* получить значение от АЦП в диапазоне lower..upper (включая границы) */
uint_fast16_t board_getadc_filtered_u16(uint_fast8_t i, uint_fast16_t lower, uint_fast16_t upper);	/* получить значение от АЦП в диапазоне lower..upper (включая границы) */
uint_fast16_t board_getpot_filtered_u16(uint_fast8_t i, uint_fast16_t lower, uint_fast16_t upper, adcvalholder_t * data);	/* получить значение от АЦП в диапазоне lower..upper (включая границы) */
uint_fast32_t board_getadc_filtered_u32(uint_fast8_t adci, uint_fast32_t lower, uint_fast32_t upper);	/* получить значение от АЦП в диапазоне lower..upper (включая границы) */
uint_fast8_t board_getadc_unfiltered_u8(uint_fast8_t i, uint_fast8_t lower, uint_fast8_t upper);	/* получить значение от АЦП в диапазоне lower..upper (включая границы) */
uint_fast16_t board_getadc_unfiltered_u16(uint_fast8_t i, uint_fast16_t lower, uint_fast16_t upper);	/* получить значение от АЦП в диапазоне lower..upper (включая границы) */
uint_fast32_t board_getadc_unfiltered_u32(uint_fast8_t i, uint_fast32_t lower, uint_fast32_t upper);	/* получить значение от АЦП в диапазоне 0..255 */
adcvalholder_t board_getadc_filtered_truevalue(uint_fast8_t i);	/* получить значение от АЦП */
adcvalholder_t board_getadc_unfiltered_truevalue(uint_fast8_t i);	/* получить значение от АЦП */
adcvalholder_t board_getadc_fsval(uint_fast8_t i);	/* получить максимальное возможное значение от АЦП */

const uint16_t * getrbfimage(size_t * count); /* получить расположение в памяти и количество элементов в массиве для загрузки FPGA */
const uint8_t * getrbfimagezip(size_t * count); /* получить расположение в памяти и количество элементов в массиве упакованного образа для загрузки FPGA */
const uint32_t * getbitimage(size_t * count); /* получить расположение в памяти и количество элементов в массиве для загрузки PS ZYNQ */

enum
{
	STTE_OK,		// можно переходить к следующему состоянию.
	STTE_BUSY,		// вложенная state machine еще выполняет свои фкнкции - требуется повторный вход.
	//
	STTE_count
};

typedef uint_fast8_t STTE_t;

void board_fpga_reset(void);

#if WITHIQSHIFT

uint8_t iq_shift_cic_rx(uint8_t val);
uint8_t iq_shift_fir_rx(uint8_t val);
uint8_t iq_shift_tx(uint8_t val);
void iq_cic_test(uint32_t val);
uint32_t iq_cic_test_process(void);

#endif /* WITHIQSHIFT */

int stpmic1_regulator_voltage_set(const char *name, uint16_t millivolts);
int stpmic1_regulator_enable(const char *name);
int stpmic1_regulator_disable(const char *name);
void stpmic1_dump_regulators(void);

void ulpi_chip_initialize(void);
void ulpi_chip_vbuson(uint_fast8_t state);
void ulpi_chip_sethost(uint_fast8_t state);
void ulpi_chip_debug(void);


/* система отказа от передачи при аварийных ситуациях */
typedef struct edgepin_tag
{
	LIST_ENTRY item;
	uint8_t outstate;	/* результирующее состояние */
	uint8_t prevstate;
	void * ctx;	/* контестный указатель, с которым вызывается функция проверуи состояния источника */
	uint_fast8_t (* getpin)(void * ctx);
} edgepin_t;

void edgepin_initialize(edgepin_t * egp, uint_fast8_t (* fn)(void *), void * ctx);
uint_fast8_t edgepin_get(edgepin_t * egp);

void nmeatuner_initialize(void);	/* сброс машины состояний парсера и инициализация последовательного пориа есои нужно */
void nmeatuner_onrxchar(uint_fast8_t c);				/* вызывается из обработчика прерываний */
void nmeatuner_rxoverflow(void);							/* вызывается из обработчика прерываний */
void nmeatuner_sendchar(void * ctx);							/* вызывается из обработчика прерываний */

void nmeagnss_parechar(uint_fast8_t c);				/* USER-MODE обработчик */

void nmeagnss_initialize(void);	/* сброс машины состояний парсера и инициализация последовательного пориа есои нужно */
void nmeagnss_onrxchar(uint_fast8_t c);				/* вызывается из обработчика прерываний */
void nmeagnss_rxoverflow(void);							/* вызывается из обработчика прерываний */
void nmeagnss_sendchar(void * ctx);							/* вызывается из обработчика прерываний */

void nmeamodem_initialize(void);	/* сброс машины состояний парсера и инициализация последовательного пориа есои нужно */
void nmeamodem_parsechar(uint_fast8_t c);				/* вызывается из обработчика прерываний */
void nmeamodem_rxoverflow(void);							/* вызывается из обработчика прерываний */
void nmeamodem_sendchar(void * ctx);							/* вызывается из обработчика прерываний */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* BOARD_H_INCLUDED */
