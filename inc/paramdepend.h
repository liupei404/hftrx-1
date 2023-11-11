/* $Id$ */
//
// Проект HF Dream Receiver (КВ приёмник мечты)
// автор Гена Завидовский mgs2001@mail.ru
// UA1ARN
//
#ifndef PARAMDEPEND_H_INCLUDED
#define PARAMDEPEND_H_INCLUDED 1

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#if CPUSTYLE_AT91SAM7S

	//#define CPU_FREQ ((18432000u * 73) / 14 / 2)	// satmod9if_v0 ARM board
	#define CPU_FREQ 48000000u
	//#define CPU_FREQ 12000000u

	#define ADC_FREQ	500000u	/* тактовая частота SAR преобразователя АЦП. */

	#define TICKS_FREQUENCY		(200uL * 1) // at ARM - 400 Hz

	//#define SCL_CLOCK  100000u	/* 100 kHz I2C/TWI speed */
	#define SCL_CLOCK	400000u	/* 400 kHz I2C/TWI speed */

	#define SPISPEED (4UL * 1000 * 1000)	/* 4 MHz на SCLK - требуемая скорость передачи по SPI */
	#define	SPISPEED400k	400000u	/* 400 kHz для низкоскоростных микросхем */
	//#define	SPISPEED100k	100000u	/* 100 kHz для низкоскоростных микросхем */

	#define ARM_OVERREALTIME_PRIORITY	AT91C_AIC_PRIOR_HIGHEST
	#define ARM_REALTIME_PRIORITY		(AT91C_AIC_PRIOR_LOWEST + 1)
	#define ARM_SYSTEM_PRIORITY			AT91C_AIC_PRIOR_LOWEST

	#define ADCVREF_CPU	33		// 3.3 volt
	//#define HARDWARE_DACBITS 12	/* ЦАП работает с 12-битными значениями */
	#define HARDWARE_ADCBITS 8	/* АЦП работает с 8-битными значениями */
	//#define HARDWARE_ADCINPUTS	40	/* до 8-ти входов АЦП */
	/* тип для хранения данных, считанных с АЦП */
	typedef uint_fast16_t adcvalholder_t;		
	typedef int_fast16_t sadcvalholder_t;	// для хранения знаковых значений


#elif CPUSTYLE_STM32F0XX
	//
	// STM32F030F4P6, STM32F051C6T6 processors

	//#define REF1_DIV 1
	//#define REF1_MUL 1	// 8 MHz
	#define PLL_FREQ	(REFINFREQ / REF1_DIV * REF1_MUL)

	#define CPU_FREQ (PLL_FREQ / 1)	// 48 MHz
	//#define CPU_FREQ 180000000uL
	//#define CPU_FREQ 168000000uL
	/* частоты, подающиеся на периферию */
	#define	PCLK1_FREQ (CPU_FREQ / 1)	// 48 MHz PCLK1 frequency
	#define	PCLK2_FREQ (CPU_FREQ / 1)	// 48 MHz PCLK2 frequency
	//#define BOARD_SYSTICK_FREQ CPU_FREQ	// SysTick_Config устанавливает SysTick_CTRL_CLKSOURCE_Msk - используется частота процессора

	#define TICKS_FREQUENCY		(200u * 1) // at ARM - 400 Hz

	// ADC clock frequency: 0.6..14 MHz
	#define ADC_FREQ	12000000u	/* тактовая частота SAR преобразователя АЦП. */
	#define SCL_CLOCK	400000u	/* 400 kHz I2C/TWI speed */

	#define SPISPEED (PCLK1_FREQ / 4)	/* 12 MHz на SCLK - требуемая скорость передачи по SPI */
	#define	SPISPEED400k	400000u	/* 400 kHz для низкоскоростных микросхем */
	//#define	SPISPEED100k	100000u	/* 100 kHz для низкоскоростных микросхем */

	#define ADCVREF_CPU	33		// 3.3 volt
	#define DACVREF_CPU	33		// 3.3 volt
	#define HARDWARE_DACBITS 12	/* ЦАП работает с 12-битными значениями */
	#define HARDWARE_ADCBITS 12	/* АЦП работает с 12-битными значениями */
	//#define HARDWARE_ADCINPUTS	40	/* до 32-ти входов АЦП */
	/* тип для хранения данных, считанных с АЦП */
	typedef uint_fast16_t adcvalholder_t;		
	typedef int_fast16_t sadcvalholder_t;	// для хранения знаковых значений
	#define WITHREFSENSORVAL	1210	/* Reference voltage: STM32F746, STM32F429, STM32F446 = 1.21V */

#elif CPUSTYLE_STM32L0XX
	//
	// STM32L051K6T processor

	#define	REFINFREQ 16000000u 	/* definition from stm32f0xx.h нельзя использовать - SPISPEED использцтся в условной компиляции */
	//#define	REFINFREQ 4000000u 	/* definition from stm32f0xx.h нельзя использовать - SPISPEED использцтся в условной компиляции */
	//#define	REFINFREQ 2100000u 	/* definition from stm32f0xx.h нельзя использовать - SPISPEED использцтся в условной компиляции */
	//#define REF1_DIV 2
	//#define REF1_MUL 12	// 48 MHz
	// HSI without PLL
	#define REF1_DIV 1
	#define REF1_MUL 1	// 8 MHz
	#define PLL_FREQ	(REFINFREQ / REF1_DIV * REF1_MUL)

	#define CPU_FREQ (PLL_FREQ / 1)	// 48 MHz
	//#define CPU_FREQ 180000000uL
	//#define CPU_FREQ 168000000uL
	/* частоты, подающиеся на периферию */
	#define	PCLK1_FREQ (CPU_FREQ / 1)	// 48 MHz PCLK1 frequency
	#define	PCLK2_FREQ (CPU_FREQ / 1)	// 48 MHz PCLK2 frequency
	//#define BOARD_SYSTICK_FREQ CPU_FREQ	// SysTick_Config устанавливает SysTick_CTRL_CLKSOURCE_Msk - используется частота процессора

	#define TICKS_FREQUENCY		(200u * 1) // at ARM - 200 Hz

	#define BOARD_TIM21_FREQ PCLK1_FREQ

	// ADC clock frequency: 0.6..14 MHz
	#define ADC_FREQ	12000000u	/* тактовая частота SAR преобразователя АЦП. */
	#define SCL_CLOCK	400000u	/* 400 kHz I2C/TWI speed */

	#define SPISPEED (PCLK1_FREQ / 1)	/* 8 MHz на SCLK - требуемая скорость передачи по SPI */
	#define	SPISPEED400k	400000u	/* 400 kHz для низкоскоростных микросхем */
	//#define	SPISPEED100k	100000uL	/* 100 kHz для низкоскоростных микросхем */

	#define ADCVREF_CPU	30		// 3.3 volt
	#define DACVREF_CPU	33		// 3.3 volt
	#define HARDWARE_DACBITS 12	/* ЦАП работает с 12-битными значениями */
	#define HARDWARE_ADCBITS 12	/* АЦП работает с 12-битными значениями */
	//#define HARDWARE_ADCINPUTS	40	/* до 32-ти входов АЦП */
	/* тип для хранения данных, считанных с АЦП */
	typedef uint_fast16_t adcvalholder_t;		
	typedef int_fast16_t sadcvalholder_t;	// для хранения знаковых значений
	#define WITHREFSENSORVAL	1224	/* Reference voltage: STM32L031xx = 1.224V */

#elif CPUSTYLE_STM32F1XX
	//
	#define PLL_FREQ	(REFINFREQ / REF1_DIV * REF1_MUL)
	#define CPU_FREQ (PLL_FREQ / 1)

 	#if CPU_FREQ >= 48000000uL
		#define	PCLK1_FREQ (CPU_FREQ / 2)	// PCLK1 frequency
		#define	PCLK1_TIMERS_FREQ (CPU_FREQ / 2)
		#define	PCLK2_FREQ (CPU_FREQ / 1)	// PCLK2 frequency
	#else
		#define	PCLK1_FREQ (CPU_FREQ / 1)	// PCLK1 frequency
		#define	PCLK1_TIMERS_FREQ (CPU_FREQ / 1)
		#define	PCLK2_FREQ (CPU_FREQ / 1)	// PCLK2 frequency
	#endif
	//#define BOARD_SYSTICK_FREQ CPU_FREQ	// SysTick_Config устанавливает SysTick_CTRL_CLKSOURCE_Msk - используется частота процессора

	#define SPISPEED (PCLK1_FREQ / 4)	/* 9.0 MHz на SCLK - требуемая скорость передачи по SPI */
	#define TICKS_FREQUENCY		(200u * 1) // at ARM - 200 Hz
	#define	SPISPEED400k	400000u	/* 400 kHz для низкоскоростных микросхем */
	//#define	SPISPEED100k	100000uL	/* 100 kHz для низкоскоростных микросхем */


	// ADC clock frequency: 1..20 MHz
	#define ADC_FREQ	2000000u	/* тактовая частота SAR преобразователя АЦП. */
	//#define ADC_FREQ	16000000uL	/* тактовая частота SAR преобразователя АЦП. */

	#define SCL_CLOCK	400000u	/* 400 kHz I2C/TWI speed */

	#define ADCVREF_CPU	33		// 3.3 volt
	#define DACVREF_CPU	33		// 3.3 volt
	#define HARDWARE_DACBITS 12	/* ЦАП работает с 12-битными значениями */
	#define HARDWARE_ADCBITS 12	/* АЦП работает с 12-битными значениями */
	//#define HARDWARE_ADCINPUTS	40	/* до 32-ти входов АЦП */
	/* тип для хранения данных, считанных с АЦП */
	typedef uint_fast16_t adcvalholder_t;		
	typedef int_fast16_t sadcvalholder_t;	// для хранения знаковых значений
	#define WITHREFSENSORVAL	1210	/* Reference voltage: STM32F746, STM32F429, STM32F446 = 1.21V */

#elif CPUSTYLE_STM32F30X || CPUSTYLE_STM32F4XX || CPUSTYLE_STM32F7XX || CPUSTYLE_STM32H7XX

	#if CPUSTYLE_STM32F4XX || CPUSTYLE_STM32F7XX || CPUSTYLE_STM32H7XX

		//! GPIO Alternate Functions
		typedef enum {
			AF_SYSTEM,		//!< AF0 - SYSTEM*
			AF_TIM1,		//!< AF1 - TIM1/2
			AF_TIM2 = 1,	//!< AF1 - TIM1/2
			AF_TIM3,		//!< AF2 - TIM3/4/5
			AF_TIM4 = 2,	//!< AF2 - TIM3/4/5
			AF_TIM5 = 2,	//!< AF2 - TIM3/4/5
			AF_TIM8,		//!< AF3 - TIM9/10/11
			AF_TIM9 = 3,	//!< AF3 - TIM9/10/11
			AF_TIM10 = 3,	//!< AF3 - TIM9/10/11
			AF_TIM11 = 3,	//!< AF3 - TIM9/10/11
			AF_I2C1,		//!< AF4 - I2C1/2/3
			AF_I2C2 = 4,	//!< AF4 - I2C1/2/3
			AF_I2C3 = 4,	//!< AF4 - I2C1/2/3
			AF_SPI1,		//!< AF5 - SPI1/2
			AF_SPI2 = 5,	//!< AF5 - SPI1/2
			AF_SPI3,		//!< AF6 - SPI3
			AF_SPI2ext = 6,	//!< AF6 - SPI3
			AF_SAI = 6,		//!< AF6 - SAI1/SAI2
			AF_USART1,		//!< AF7 - USART1/2/3
			AF_USART2 = 7,	//!< AF7 - USART1/2/3
			AF_USART3 = 7,	//!< AF7 - USART1/2/3 
			AF_USART4,		//!< AF8 - USART4/5/6
			AF_USART5 = 8,	//!< AF8 - USART4/5/6
			AF_USART6 = 8,	//!< AF8 - USART4/5/6
			AF_CAN1,		//!< AF9 - CAN1/2
			AF_CAN2 = 9,	//!< AF9 - CAN1/2
			AF_TIM12 = 9,	//!< AF9 - TIM12/13/14
			AF_TIM13 = 9,	//!< AF9 - TIM12/13/14
			AF_TIM14 = 9,	//!< AF9 - TIM12/13/14
			AF_OTGFS,		//!< AF10 - OTGFS
			AF_OTGHS = 10,	//!< AF10 - OTGHS
			AF_SAI2 = 10,	//!< AF10 - SAI2
			AF_ETH,			//!< AF11 - ETH
			AF_FSMC,		//!< AF12 - FSMC
			AF_SDIO = 12,	//!< AF12 - SDIO
			AF_OTGHS_FS = 12, //!< AF12 - OTG HS configured in FS
			AF_DCMI,		//!< AF13 - DCMI
			AF_AF14,		//!< AF14 - RI
			AF_EVENT		//!< AF15 - SYSTEM (EVENTOUT)
		} GPIO_AFLH_t;

		//
		#if WITHCPUXOSC
			// с внешним генератором
			#define	REFINFREQ WITHCPUXOSC
		#elif WITHCPUXTAL
			// с внешним кварцевым резонатором
			#define	REFINFREQ WITHCPUXTAL
		#elif CPUSTYLE_STM32H7XX
			// На внутреннем RC генераторе
			#define	REFINFREQ 64000000u
		#else /* WITHCPUXTAL */
			// На внутреннем RC генераторе
			#define	REFINFREQ 16000000u
		#endif /* WITHCPUXTAL */

		#if defined(STM32F401xC)

			#define LSEFREQ 32768uL	// должно быть в файле конфигурации платы

			#define PLL_FREQ	(REFINFREQ / REF1_DIV * REF1_MUL)
			#define PLL2_FREQ	(REFINFREQ / REF2_DIV * REF2_MUL)	// STM32H7xxx
			#define PLL3_FREQ	(REFINFREQ / REF3_DIV * REF3_MUL)	// STM32H7xxx

			#define PLLI2S_FREQ (REFINFREQ / REF1_DIV * PLLI2SN_MUL)
			#define	PLLI2S_FREQ_OUT (PLLI2S_FREQ / 2)		// Frequency after PLLI2S_DivQ

			//#define PLLSAI_FREQ (REFINFREQ / REF1_DIV * SAIREF1_MUL)
			//#define PLLSAI_FREQ_OUT (PLLSAI_FREQ / 2)	// Frequency after PLLSAI_DivQ

			#define CPU_FREQ (stm32f4xx_get_sysclk_freq())	// 172032000uL

			/* частоты, подающиеся на периферию */
			//#define	PCLK1_FREQ (CPU_FREQ / 2)	// 42 MHz PCLK1 frequency - timer clocks is 85 MHz
			//#define	PCLK1_TIMERS_FREQ (CPU_FREQ / 1)	// 42 MHz PCLK1 frequency - timer clocks is 85 MHz
			//#define	PCLK2_FREQ (CPU_FREQ / 1)	// 84 MHz PCLK2 frequency
			//#define BOARD_SYSTICK_FREQ CPU_FREQ	// SysTick_Config устанавливает SysTick_CTRL_CLKSOURCE_Msk - используется частота процессора

 		#elif CPUSTYLE_STM32H7XX

			#define PLL_FREQ	(REFINFREQ / REF1_DIV * REF1_MUL)
			#define PLL2_FREQ	(REFINFREQ / REF2_DIV * REF2_MUL)	// STM32H7xxx
			#define PLL3_FREQ	(REFINFREQ / REF3_DIV * REF3_MUL)	// STM32H7xxx

			#define PLLI2S_FREQ (REFINFREQ / REF1_DIV * PLLI2SN_MUL)
			#define	PLLI2S_FREQ_OUT (PLLI2S_FREQ / 2)		// Frequency after PLLI2S_DivQ

			#define PLLSAI_FREQ (REFINFREQ / REF1_DIV * SAIREF1_MUL)
			#define PLLSAI_FREQ_OUT (PLLSAI_FREQ / 2)	// Frequency after PLLSAI_DivQ

			#define CPU_FREQ (PLL_FREQ / 2)	// 172032000uL

			#define HSIFREQ 64000000u
			#define HSI48FREQ 48000000u
			#if !defined  (CSI_VALUE)
			  #define CSI_VALUE    4000000U /*!< Value of the Internal oscillator in Hz*/
			#endif /* CSI_VALUE */

			#define LSEFREQ 32768u	// должно быть в файле конфигурации платы

			#define BOARD_SPI_FREQ (hardware_get_spi_freq())

			#define WITHCPUNAME "STM32H7xx"

		#elif CPUSTYLE_STM32F7XX

			#define LSEFREQ 32768u	// должно быть в файле конфигурации платы

			#define PLL_FREQ	(stm32f7xx_get_pll_freq())
			//#define PLL2_FREQ	(REFINFREQ / REF2_DIV * REF2_MUL)	// STM32H7xxx
			//#define PLL3_FREQ	(REFINFREQ / REF3_DIV * REF3_MUL)	// STM32H7xxx

			#define PLLI2S_FREQ (stm32f7xx_get_plli2s_freq())
			#define	PLLI2S_FREQ_OUT (PLLI2S_FREQ / 2)		// Frequency after PLLI2S_DivQ

			#define PLLSAI_FREQ (stm32f7xx_get_pllsai_freq())
			#define PLLSAI_FREQ_OUT (PLLSAI_FREQ / 2)	// Frequency after PLLSAI_DivQ

			#define CPU_FREQ (stm32f7xx_get_sys_freq())	// 172032000uL
			#define BOARD_SPI_FREQ (hardware_get_spi_freq())

			#define HSIFREQ 16000000u

			#define WITHCPUNAME "STM32F7xx"

		#elif CPUSTYLE_STM32F4XX

			#define LSEFREQ 32768u	// должно быть в файле конфигурации платы

			#define CPU_FREQ (stm32f4xx_get_sysclk_freq())	// 172032000uL
			#define BOARD_SPI_FREQ (stm32f4xx_get_spi1_freq())

			#define HSIFREQ 16000000u	// 16 MHz

			#define WITHCPUNAME "STM32F4xx"

		#endif

	#elif CPUSTYLE_STM32F30X
		//
		//#define WITHCPUXTAL 8000000uL	// Если есть внешний кварц на процессоре.
		#if WITHCPUXTAL
			#define	REFINFREQ WITHCPUXTAL
			#define REF1_DIV 1
			#define REF1_MUL 9	// Up to 16 supported - вынести в конфигурационный файл платы
		#else
			#define	REFINFREQ 8000000u
			#define REF1_DIV 2
			#define REF1_MUL 9	// Up to 16 supported - вынести в конфигурационный файл платы
		#endif

		#define PLL_FREQ	(REFINFREQ / REF1_DIV * REF1_MUL)
		#define CPU_FREQ (PLL_FREQ / 1)

 		#if CPU_FREQ >= 48000000u
			#define	PCLK1_FREQ (CPU_FREQ / 2)	// PCLK1 frequency
			#define	PCLK2_FREQ (CPU_FREQ / 1)	// PCLK2 frequency
		#else
			#define	PCLK1_FREQ (CPU_FREQ / 1)	// PCLK1 frequency
			#define	PCLK2_FREQ (CPU_FREQ / 1)	// PCLK2 frequency
		#endif
		//#define BOARD_SYSTICK_FREQ CPU_FREQ	// SysTick_Config устанавливает SysTick_CTRL_CLKSOURCE_Msk - используется частота процессора

	#endif

	#define TICKS_FREQUENCY		200uL	// at ARM - 200 Hz

	// ADC clock frequency: 1..20 MHz
	#define SCL_CLOCK	400000uL	/* 400 kHz I2C/TWI speed */

	//#define SPISPEED (PCLK1_FREQ / 16)	/* 3.5 MHz на SCLK - требуемая скорость передачи по SPI */
	//#define SPISPEED (PCLK1_FREQ / 8)	/* 7 MHz на SCLK - требуемая скорость передачи по SPI */
	#define SPISPEED (BOARD_SPI_FREQ / 4)	/* 14 MHz на SCLK - требуемая скорость передачи по SPI */
	#define SPISPEEDUFAST 12000000u//(PCLK1_FREQ / 2)	/* 28 на SCLK - требуемая скорость передачи по SPI */
	#define	SPISPEED400k	400000u	/* 400 kHz для низкоскоростных микросхем */
	//#define	SPISPEED100k	100000uL	/* 100 kHz для низкоскоростных микросхем */

	#define ADCVREF_CPU	33		// 3.3 volt
	#define DACVREF_CPU	33		// 3.3 volt
	#define HARDWARE_DACBITS 12	/* ЦАП работает с 12-битными значениями */
	//#define HARDWARE_ADCINPUTS	40	/* до 32-ти входов АЦП */
	/* тип для хранения данных, считанных с АЦП */
	typedef uint_fast16_t adcvalholder_t;	
	typedef int_fast16_t sadcvalholder_t;	// для хранения знаковых значений

	#if CPUSTYLE_STM32H7XX
		//#define HARDWARE_ADCBITS 8	/* АЦП работает с 8-битными значениями */
		//#define HARDWARE_ADCBITS 10	/* АЦП работает с 10-битными значениями */
		#define HARDWARE_ADCBITS 12	/* АЦП работает с 12-битными значениями */
		//#define HARDWARE_ADCBITS 14	/* АЦП работает с 14-битными значениями */
		//#define HARDWARE_ADCBITS 16	/* АЦП работает с 16-битными значениями */
		#define ADC_FREQ	10000000u	/* тактовая частота SAR преобразователя АЦП. */
		#define WITHREFSENSORVAL	1240	/* Reference voltage: STM32H743 1.180 1.216 1.255 */
	#elif CPUSTYLE_STM32F7XX || CPUSTYLE_STM32F4XX
		//#define HARDWARE_ADCBITS 6	/* АЦП работает с 6-битными значениями */
		//#define HARDWARE_ADCBITS 8	/* АЦП работает с 8-битными значениями */
		//#define HARDWARE_ADCBITS 10	/* АЦП работает с 10-битными значениями */
		#define HARDWARE_ADCBITS 12	/* АЦП работает с 12-битными значениями */
		#define ADC_FREQ	28000000u	/* тактовая частота SAR преобразователя АЦП. */
		#define WITHREFSENSORVAL	1210	/* Reference voltage: STM32F746, STM32F429, STM32F446 = 1.21V */
	#else
		#define HARDWARE_ADCBITS 12	/* АЦП работает с 12-битными значениями */
		#define ADC_FREQ	2000000u	/* тактовая частота SAR преобразователя АЦП. */
		#define WITHREFSENSORVAL	1210	/* Reference voltage: STM32F746, STM32F429, STM32F446 = 1.21V */
	#endif

#elif CPUSTYLE_ATSAM3S

	//#define CPU_FREQ ((18432000uL * 73) / 14 / 2)	// satmod9if_v0 ARM board
	#define CPU_FREQ 64000000uL
	//#define CPU_FREQ 48000000uL
	//#define CPU_FREQ 32000000uL
	//#define CPU_FREQ 12000000uL
	//#define BOARD_SYSTICK_FREQ CPU_FREQ	// SysTick_Config устанавливает SysTick_CTRL_CLKSOURCE_Msk - используется частота процессора

	// ADC clock frequency: 1..20 MHz
	#define ADC_FREQ	2000000uL	/* тактовая частота SAR преобразователя АЦП. */
	//#define ADC_FREQ	16000000uL	/* тактовая частота SAR преобразователя АЦП. */

	#define TICKS_FREQUENCY		(200uL * 1) // at ARM - 400 Hz

	//#define SCL_CLOCK  100000uL	/* 100 kHz I2C/TWI speed */
	#define SCL_CLOCK	400000uL	/* 400 kHz I2C/TWI speed */

	#define SPISPEED (4UL * 1000 * 1000)	/* 4 MHz на SCLK - требуемая скорость передачи по SPI */
	#define	SPISPEED400k	400000uL	/* 400 kHz для низкоскоростных микросхем */
	//#define	SPISPEED100k	100000uL	/* 100 kHz для низкоскоростных микросхем */

	#define ADCVREF_CPU	33		// 3.3 volt
	//#define HARDWARE_DACBITS 12	/* ЦАП работает с 12-битными значениями */
	#define HARDWARE_ADCBITS 10	/* АЦП работает с 10-битными значениями */
	//#define HARDWARE_ADCINPUTS	40	/* до 16-ти входов АЦП */
	/* тип для хранения данных, считанных с АЦП */
	typedef uint_fast16_t adcvalholder_t;		
	typedef int_fast16_t sadcvalholder_t;	// для хранения знаковых значений

	#define WITHCPUNAME "ATSAM3S"

#elif CPUSTYLE_ATSAM4S

	//#define CPU_FREQ ((18432000uL * 73) / 14 / 2)	// satmod9if_v0 ARM board
	#define CPU_FREQ 64000000uL
	//#define CPU_FREQ 48000000uL
	//#define CPU_FREQ 32000000uL
	//#define CPU_FREQ 12000000uL
	//#define BOARD_SYSTICK_FREQ CPU_FREQ	// SysTick_Config устанавливает SysTick_CTRL_CLKSOURCE_Msk - используется частота процессора

	// ADC clock frequency: 1..20 MHz
	#define ADC_FREQ	2000000u	/* тактовая частота SAR преобразователя АЦП. */
	//#define ADC_FREQ	16000000uL	/* тактовая частота SAR преобразователя АЦП. */

	#define TICKS_FREQUENCY		(200u * 1) // at ARM - 400 Hz

	//#define SCL_CLOCK  100000u	/* 100 kHz I2C/TWI speed */
	#define SCL_CLOCK	400000u	/* 400 kHz I2C/TWI speed */

	#define SPISPEED (4UL * 1000 * 1000)	/* 4 MHz на SCLK - требуемая скорость передачи по SPI */
	#define	SPISPEED400k	400000u	/* 400 kHz для низкоскоростных микросхем */
	//#define	SPISPEED100k	100000u	/* 100 kHz для низкоскоростных микросхем */

	#define ADCVREF_CPU	33		// 3.3 volt
	//#define HARDWARE_DACBITS 12	/* ЦАП работает с 12-битными значениями */
	#define HARDWARE_ADCBITS 10	/* АЦП работает с 10-битными значениями */
	//#define HARDWARE_ADCINPUTS	40	/* до 16-ти входов АЦП */
	/* тип для хранения данных, считанных с АЦП */
	typedef uint_fast16_t adcvalholder_t;		
	typedef int_fast16_t sadcvalholder_t;	// для хранения знаковых значений

	#define WITHCPUNAME "ATSAM4S"

#elif CPUSTYLE_AT91SAM9XE

	#define CPU_FREQ (196608000uL / 2)	// частота периферии (процессорная после деления).
	//#define CPU_FREQ 14400000uL
	//#define SCL_CLOCK  100000L	/* 100 kHz I2C/TWI speed */
	#define SCL_CLOCK  400000uL	/* 400 kHz I2C/TWI speed */

	#define SPISPEED (4UL * 1000 * 1000)	/* 4 MHz на SCLK - требуемая скорость передачи по SPI */
	#define	SPISPEED400k	400000uL	/* 400 kHz для низкоскоростных микросхем */
	//#define	SPISPEED100k	100000uL	/* 100 kHz для низкоскоростных микросхем */

	#define TICKS_FREQUENCY		200U // 200 Hz

	#define ARM_REALTIME_PRIORITY	AT91C_AIC_PRIOR_HIGHEST 
	#define ARM_SYSTEM_PRIORITY		AT91C_AIC_PRIOR_LOWEST 

	#define ADCVREF_CPU	33		// 3.3 volt
	//#define HARDWARE_DACBITS 12	/* ЦАП работает с 12-битными значениями */
	#define HARDWARE_ADCBITS 12	/* АЦП работает с 12-битными значениями */
	//#define HARDWARE_ADCINPUTS	40	/* до 8-ти входов АЦП */
	/* тип для хранения данных, считанных с АЦП */
	typedef uint_fast16_t adcvalholder_t;		
	typedef int_fast16_t sadcvalholder_t;	// для хранения знаковых значений

#elif CPUSTYLE_ATMEGA

	// ATMega processors

	#define CPU_FREQ (F_CPU)

	#define TICKS_FREQUENCY	 (200u)	// 200 Hz - use compare/match interrupt

	//#define SCL_CLOCK  100000u	/* 100 kHz I2C/TWI speed */
	//#define SCL_CLOCK  250000u		/* 250 kHz I2C/TWI speed */
	#define SCL_CLOCK  400000u	/* 400 kHz I2C/TWI speed */
	//#define SCL_CLOCK  40000u	/* 40 kHz I2C/TWI speed */

	#define SPISPEED (CPU_FREQ / 2) /* 4 (5) MHz на SCLK - требуемая скорость передачи по SPI */
	#define SPISPEEDUFAST SPISPEED
	#define	SPISPEED400k	400000u	/* 400 kHz для низкоскоростных микросхем */
	//#define	SPISPEED100k	100000uL	/* 100 kHz для низкоскоростных микросхем */

	#define ADC_FREQ	250000u	/* тактовая частота SAR преобразователя АЦП. */

	#define ADCVREF_CPU	33		// 3.3 volt
	//#define ADCVREF_CPU	50		// 5.0 volt

	//#define HARDWARE_DACBITS 12	/* ЦАП работает с 12-битными значениями */
	//#define HARDWARE_ADCBITS 8	/* АЦП работает с 8-битными значениями */
	#define HARDWARE_ADCBITS 10	/* АЦП работает с 10-битными значениями */

	//#define HARDWARE_ADCINPUTS	40	/* до 8-ти входов АЦП */

	#if HARDWARE_ADCBITS == 8
		/* тип для хранения данных, считанных с АЦП */
		typedef uint_fast16_t adcvalholder_t;
		typedef int_fast16_t sadcvalholder_t;	// для хранения знаковых значений
	#elif HARDWARE_ADCBITS == 10
		/* тип для хранения данных, считанных с АЦП */
		typedef uint_fast16_t adcvalholder_t;		
		typedef int_fast16_t sadcvalholder_t;	// для хранения знаковых значений
	#else
		#error Erong HARDWARE_ADCBITS value
	#endif

#elif CPUSTYLE_ATXMEGA

	// ATMega processors

	#define CPU_FREQ (F_CPU)

	#define TICKS_FREQUENCY	 (200U * 2)	// 400 Hz - use compare/match interrupt

	//#define SCL_CLOCK  100000uL	/* 100 kHz I2C/TWI speed */
	//#define SCL_CLOCK  250000uL		/* 250 kHz I2C/TWI speed */
	#define SCL_CLOCK  400000uL	/* 400 kHz I2C/TWI speed */

	#define SPISPEED (8000000) /* 4 (5) MHz на SCLK - требуемая скорость передачи по SPI */
	#define	SPISPEED400k	400000uL	/* 400 kHz для низкоскоростных микросхем */
	//#define	SPISPEED100k	100000uL	/* 100 kHz для низкоскоростных микросхем */

	#define ADC_FREQ	125000uL	/* тактовая частота SAR преобразователя АЦП. */


	#define ADCVREF_CPU	25		// 2.5 volt
	#define HARDWARE_ADCBITS 8	/* АЦП работает с 8-битными значениями */

	//#define HARDWARE_ADCINPUTS	40	/* до 8-ти входов АЦП */
	/* тип для хранения данных, считанных с АЦП */
	typedef uint_fast8_t adcvalholder_t;		
	typedef int_fast16_t sadcvalholder_t;	// для хранения знаковых значений

#elif CPUSTYLE_TMS320F2833X

	#define TICKS_FREQUENCY	 (200U * 2)	// 400 Hz - use compare/match interrupt
	#define HARDWARE_ADCBITS 12	/* АЦП работает с 12-битными значениями */
	/* тип для хранения данных, считанных с АЦП */
	typedef uint_fast16_t adcvalholder_t;		
	typedef int_fast16_t sadcvalholder_t;	// для хранения знаковых значений

#elif CPUSTYLE_R7S721

	//#define WITHCPUXTAL 12000000uL			/* На процессоре установлен кварц 12.000 МГц */
	#define CPU_FREQ	(30 * WITHCPUXTAL)		/* 12 MHz * 30 - clock mode 0, xtal 12 MHz */

	#define BCLOCK_FREQ		(CPU_FREQ / 3)		// 120 MHz
	#define P1CLOCK_FREQ	(CPU_FREQ / 6)		// 60 MHz
	#define P0CLOCK_FREQ	(CPU_FREQ / 12)		// 30 MHz

	#define TICKS_FREQUENCY		(200uL * 1) // at ARM - 400 Hz

	// ADC clock frequency: 1..20 MHz
	#define ADC_FREQ	2000000u	/* тактовая частота SAR преобразователя АЦП. */
	#define SCL_CLOCK	400000u		/* 400 kHz I2C/TWI speed */

	#define SPISPEED 8000000u	/* 8 MHz (10.5) на SCLK - требуемая скорость передачи по SPI */
	#define SPISPEEDUFAST (P1CLOCK_FREQ / 3)	// 20 MHz
	#define	SPISPEED400k	400000u				/* 400 kHz для низкоскоростных микросхем */
	//#define	SPISPEED100k	100000u			/* 100 kHz для низкоскоростных микросхем */

	#define ADCVREF_CPU	33		// 3.3 volt
	#define HARDWARE_ADCBITS 12	/* АЦП работает с 12-битными значениями */

	//#define HARDWARE_ADCINPUTS	40	/* до 8-ти входов АЦП */
	/* тип для хранения данных, считанных с АЦП */
	typedef uint_fast16_t adcvalholder_t;
	typedef int_fast16_t sadcvalholder_t;	// для хранения знаковых значений

	enum
	{
		R7S721_PIOALT_1	= 0x00,	/* 1st Alternative */
		R7S721_PIOALT_2	= 0x01,	/* 2nd Alternative */
		R7S721_PIOALT_3	= 0x02,	/* 3rd Alternative */
		R7S721_PIOALT_4	= 0x03,	/* 4th Alternative */
		R7S721_PIOALT_5	= 0x04,	/* 5th Alternative */
		R7S721_PIOALT_6	= 0x05,	/* 6th Alternative */
		R7S721_PIOALT_7	= 0x06,	/* 7th Alternative */
		R7S721_PIOALT_8	= 0x07	/* 8th Alternative */
	};

	/* видимые в контроллере прерывания регистры от ARM CORE */
	//#define GIC_PRIORITYSHIFT 3	/* ICCPMR[7:3] is valid bit */

	//#define GICC_PMR		(INTC.ICCPMR)	// 4.4.2 Interrupt Priority Mask Register, GICC_PMR
	//#define GICC_RPR		((uint32_t) INTC.ICCRPR)	// 4.4.6 Running Priority Register, GICC_RPR
	//#define GICC_HPPIR		(INTC.ICCHPIR)
	//#define GICC_IAR		(INTC.ICCIAR)
	//#define GICC_BPR		(INTC.ICCBPR)
	//#define GICC_CTLR		(INTC.ICCICR)
	//#define GICD_IPRIORITYRn(n) (((volatile uint8_t *) & INTC.ICDIPR0) [(n)])

	// GIC_SetConfiguration parameters
	#define GIC_CONFIG_EDGE 0x03
	#define GIC_CONFIG_LEVEL 0x01

	#define WITHCPUNAME "R7S721"

#elif CPUSTYLE_STM32MP1

	//! GPIO Alternate Functions
	typedef enum {
		AF_SYSTEM,		//!< AF0 - SYSTEM*
		AF_TIM1,		//!< AF1 - TIM1/2
		AF_TIM2 = 1,	//!< AF1 - TIM1/2
		AF_TIM17 = 1,	//!< AF1 - TIM17
		AF_TIM3,		//!< AF2 - TIM3/4/5
		AF_TIM4 = 2,	//!< AF2 - TIM3/4/5
		AF_TIM5 = 2,	//!< AF2 - TIM3/4/5
		AF_TIM8,		//!< AF3 - TIM9/10/11
		AF_TIM9 = 3,	//!< AF3 - TIM9/10/11
		AF_TIM10 = 3,	//!< AF3 - TIM9/10/11
		AF_TIM11 = 3,	//!< AF3 - TIM9/10/11
		AF_USART1,		//!< AF4 - USART1
		AF_I2C1 = 4,	//!< AF4 - I2C1/2/3
		AF_I2C2 = 4,	//!< AF4 - I2C1/2/3
		AF_I2C3 = 4,	//!< AF4 - I2C1/2/3
		AF_SPI1,		//!< AF5 - SPI1/2
		AF_SPI2 = 5,	//!< AF5 - SPI1/2
		AF_SPI3,		//!< AF6 - SPI3
		AF_SPI2ext = 6,	//!< AF6 - SPI3
		AF_SAI = 6,		//!< AF6 - SAI1/SAI2
		AF_USART2,		//!< AF7 - USART2/3
		AF_USART3 = 7,	//!< AF7 - USART1/2/3
		AF_USART4,		//!< AF8 - USART4/5/6
		AF_USART5 = 8,	//!< AF8 - USART4/5/6
		AF_USART6 = 8,	//!< AF8 - USART4/5/6
		AF_CAN1,		//!< AF9 - CAN1/2
		AF_CAN2 = 9,	//!< AF9 - CAN1/2
		AF_TIM12 = 9,	//!< AF9 - TIM12/13/14
		AF_TIM13 = 9,	//!< AF9 - TIM12/13/14
		AF_TIM14 = 9,	//!< AF9 - TIM12/13/14
		AF_QUADSPI_AF9 = 9,	//!< AF9 - AF_QUADSPI
		AF_OTGFS,		//!< AF10 - OTGFS
		AF_QUADSPI_AF10 = 10,	//!< AF10 - AF_QUADSPI
		AF_OTGHS = 10,	//!< AF10 - OTGHS
		AF_SAI2 = 10,	//!< AF10 - SAI2
		AF_ETH,			//!< AF11 - ETH
		AF_FSMC,		//!< AF12 - FSMC
		AF_SDIO = 12,	//!< AF12 - SDIO
		AF_OTGHS_FS = 12, //!< AF12 - OTG HS configured in FS
		AF_DCMI,		//!< AF13 - DCMI
		AF_AF14,		//!< AF14 - RI
		AF_EVENT		//!< AF15 - SYSTEM (EVENTOUT)
	} GPIO_AFLH_t;

	/* Частоты встроенных RC генераторов процессора */
	#define HSI64FREQ 64000000u
	#define CSI_VALUE 4000000U
	#define LSIFREQ 32000u

	//
	#if WITHCPUXOSC
		// с внешним генератором
		#define	REF1INFREQ WITHCPUXOSC
		#define	REF2INFREQ REF1INFREQ

	#elif WITHCPUXTAL
		// с внешним кварцевым резонатором
		#define	REF1INFREQ WITHCPUXTAL
		#define	REF2INFREQ REF1INFREQ

	#else /* WITHCPUXTAL */
		// На внутреннем RC генераторе
		#define	REF1INFREQ (stm32mp1_get_hsi_freq())
		#define	REF2INFREQ HSI64FREQ
	#endif /* WITHCPUXTAL */

	#define CPU_FREQ	(stm32mp1_get_mpuss_freq())
	#define DDR_FREQ	(stm32mp1_get_pll2_r_freq())
	#define AXISS_FREQ	(stm32mp1_get_axiss_freq())
	#define CPU_PL1_FREQ (stm32mp1_get_hsi_freq())	/* PL1 times source frequency */

	#define BOARD_SPI_FREQ (hardware_get_spi_freq())
	#define BOARD_QSPI_FREQ (stm32mp1_get_qspi_freq())

	#define TICKS_FREQUENCY	 (200U)	// 200 Hz

	// ADC clock frequency: 1..20 MHz
	#define SCL_CLOCK	400000u	/* 400 kHz I2C/TWI speed */

	#define SPISPEED (BOARD_SPI_FREQ / 4)	/* 14 MHz на SCLK - требуемая скорость передачи по SPI */
	#define SPISPEEDUFAST 24000000u			/* 2требуемая скорость передачи по SPI */
	#define	SPISPEED400k	400000u			/* 400 kHz для низкоскоростных микросхем */
	//#define	SPISPEED100k	100000u		/* 100 kHz для низкоскоростных микросхем */

	#define ADCVREF_CPU	33		// 3.3 volt
	#define DACVREF_CPU	33		// 3.3 volt
	#define HARDWARE_DACBITS 12	/* ЦАП работает с 12-битными значениями */
	//#define HARDWARE_ADCINPUTS	40	/* до 32-ти входов АЦП */
	/* тип для хранения данных, считанных с АЦП */
	typedef uint_fast16_t adcvalholder_t;
	typedef int_fast16_t sadcvalholder_t;	// для хранения знаковых значений
	//#define HARDWARE_ADCBITS 8	/* АЦП работает с 8-битными значениями */
	//#define HARDWARE_ADCBITS 10	/* АЦП работает с 10-битными значениями */
	#define HARDWARE_ADCBITS 12	/* АЦП работает с 12-битными значениями */
	//#define HARDWARE_ADCBITS 14	/* АЦП работает с 14-битными значениями */
	//#define HARDWARE_ADCBITS 16	/* АЦП работает с 16-битными значениями */
	#define ADC_FREQ	10000000uL	/* тактовая частота SAR преобразователя АЦП. */
	#define WITHREFSENSORVAL	1240	/* Reference voltage: STM32H743 1.180 1.216 1.255 */

	#define ADCVREF_CPU	33		// 3.3 volt
	#define HARDWARE_ADCBITS 12	/* АЦП работает с 12-битными значениями */

	//#define HARDWARE_ADCINPUTS	40	/* до 8-ти входов АЦП */

	#define DACVREF_CPU	33		// 3.3 volt
	#define HARDWARE_DACBITS 12	/* ЦАП работает с 12-битными значениями */

	#define HARDWARE_NCORES 2

#elif CPUSTYLE_XC7Z

	typedef uint_fast16_t adcvalholder_t;
	typedef int_fast16_t sadcvalholder_t;	// для хранения знаковых значений

	#if WITHCPUXOSC
		// с внешним генератором
		#define	REFINFREQ WITHCPUXOSC
	#elif WITHCPUXTAL
		// с внешним кварцевым резонатором
		#define	REFINFREQ WITHCPUXTAL
	#endif /* WITHCPUXTAL */

	#define CPU_FREQ	(xc7z_get_arm_freq())
	#define BOARD_SPI_FREQ (xc7z_get_spi_freq())

	#define TICKS_FREQUENCY 200
	#define ADCVREF_CPU	33		// 3.3 volt
	#define HARDWARE_ADCBITS 12

	#define SPISPEED (12000000u)	/* 14 MHz на SCLK - требуемая скорость передачи по SPI */
	#define SPISPEEDUFAST 12000000u		//(PCLK1_FREQ / 2)	/* 28 на SCLK - требуемая скорость передачи по SPI */
	//#define	SPISPEED400k	400000u			/* 400 kHz для низкоскоростных микросхем */
	//#define	SPISPEED100k	100000u		/* 100 kHz для низкоскоростных микросхем */

	#define HARDWARE_NCORES 2

#elif CPUSTYLE_A64

	typedef uint_fast16_t adcvalholder_t;
	typedef int_fast16_t sadcvalholder_t;	// для хранения знаковых значений

	#if WITHCPUXOSC
		// с внешним генератором
		#define	REFINFREQ WITHCPUXOSC
	#elif WITHCPUXTAL
		// с внешним кварцевым резонатором
		#define	REFINFREQ WITHCPUXTAL
	#endif /* WITHCPUXTAL */

	#define HARDWARE_CLK32K_FREQ 32000u
	#define HARDWARE_CLK16M_RC_FREQ 16000000u

	#define CPU_FREQ	(allwnr_a64_get_cpux_freq())
	#define BOARD_USART_FREQ (allwnrt113_get_uart_freq())
	#define CPU_PL1_FREQ (allwnrt113_get_hosc_freq())	/* PL1 times source frequency */

	#define TICKS_FREQUENCY 200
	#define ADCVREF_CPU	33		// 3.3 volt
	#define HARDWARE_ADCBITS 12

	#define SPISPEED 		12000000u	/* 12 MHz на SCLK - требуемая скорость передачи по SPI */
	#define SPISPEEDUFAST 	24000000u	/* 12 MHzна SCLK - требуемая скорость передачи по SPI */
	#define	SPISPEED400k	400000u	/* 400 kHz для низкоскоростных микросхем */
	//#define	SPISPEED100k	100000u	/* 100 kHz для низкоскоростных микросхем */


	typedef enum {
		GPIO_CFG_IN  = 0x00,
		GPIO_CFG_OUT = 0x01,
		GPIO_CFG_AF2 = 0x02,
		GPIO_CFG_AF3 = 0x03,
		GPIO_CFG_AF4 = 0x04,
		GPIO_CFG_AF5 = 0x05,
		GPIO_CFG_EINT = 0x06,	/* external interrupt sense (input) */
		GPIO_CFG_IODISABLE = 0x07,
	} GPIOMode_TypeDef;

	#define HARDWARE_NCORES 4
	#define WITHCPUNAME "Allw A64"


#elif CPUSTYLE_T507 || CPUSTYLE_H616

	typedef uint_fast16_t adcvalholder_t;
	typedef int_fast16_t sadcvalholder_t;	// для хранения знаковых значений

	#if WITHCPUXOSC
		// с внешним генератором
		#define	REFINFREQ WITHCPUXOSC
	#elif WITHCPUXTAL
		// с внешним кварцевым резонатором
		#define	REFINFREQ WITHCPUXTAL
	#endif /* WITHCPUXTAL */

	#define HARDWARE_CLK32K_FREQ 32000u
	#define HARDWARE_CLK16M_RC_FREQ 16000000u

	#define CPU_FREQ	(allwnr_t507_get_cpux_freq())
	#define BOARD_USART_FREQ (allwnrt113_get_uart_freq())
	#define CPU_PL1_FREQ (allwnrt113_get_hosc_freq())	/* PL1 times source frequency */

	#define TICKS_FREQUENCY 200
	#define ADCVREF_CPU	33		// 3.3 volt
	#define HARDWARE_ADCBITS 12

	#define SPISPEED 		12000000u	/* 12 MHz на SCLK - требуемая скорость передачи по SPI */
	#define SPISPEEDUFAST 	24000000u	/* 12 MHzна SCLK - требуемая скорость передачи по SPI */
	#define	SPISPEED400k	400000u	/* 400 kHz для низкоскоростных микросхем */
	//#define	SPISPEED100k	100000u	/* 100 kHz для низкоскоростных микросхем */


	typedef enum {
		GPIO_CFG_IN  = 0x00,
		GPIO_CFG_OUT = 0x01,
		GPIO_CFG_AF2 = 0x02,
		GPIO_CFG_AF3 = 0x03,
		GPIO_CFG_AF4 = 0x04,
		GPIO_CFG_AF5 = 0x05,
		GPIO_CFG_EINT = 0x06,	/* external interrupt sense (input) */
		GPIO_CFG_IODISABLE = 0x07,
	} GPIOMode_TypeDef;

	#define HARDWARE_NCORES 4
	#define WITHCPUNAME "Allw T507"

#elif CPUSTYLE_T113

	typedef uint_fast16_t adcvalholder_t;
	typedef int_fast16_t sadcvalholder_t;	// для хранения знаковых значений

	#if WITHCPUXOSC
		// с внешним генератором
		#define	REFINFREQ WITHCPUXOSC
	#elif WITHCPUXTAL
		// с внешним кварцевым резонатором
		#define	REFINFREQ WITHCPUXTAL
	#endif /* WITHCPUXTAL */

	#define HARDWARE_CLK32K_FREQ 32000uL
	#define HARDWARE_CLK16M_RC_FREQ 16000000uL

	#define CPU_FREQ	(allwnrt113_get_arm_freq())
	#define BOARD_USART_FREQ (allwnrt113_get_uart_freq())
	#define CPU_PL1_FREQ (allwnrt113_get_hosc_freq())	/* PL1 times source frequency */

	#define TICKS_FREQUENCY 200
	#define ADCVREF_CPU	33		// 3.3 volt
	#define HARDWARE_ADCBITS 12

	#define SPISPEED 		12000000u	/* 12 MHz на SCLK - требуемая скорость передачи по SPI */
	#define SPISPEEDUFAST 	24000000u	/* 12 MHzна SCLK - требуемая скорость передачи по SPI */
	#define	SPISPEED400k	400000u	/* 400 kHz для низкоскоростных микросхем */
	//#define	SPISPEED100k	100000u	/* 100 kHz для низкоскоростных микросхем */


	typedef enum {
		GPIO_CFG_IN  = 0x00,
		GPIO_CFG_OUT = 0x01,
		GPIO_CFG_AF2 = 0x02,
		GPIO_CFG_AF3 = 0x03,
		GPIO_CFG_AF4 = 0x04,
		GPIO_CFG_AF5 = 0x05,
		GPIO_CFG_AF6 = 0x06,
		GPIO_CFG_AF7 = 0x07,
		GPIO_CFG_AF8 = 0x08,
		GPIO_CFG_AF9 = 0x09,
		GPIO_CFG_AF10 = 0x0A,
		GPIO_CFG_AF11 = 0x0B,
		GPIO_CFG_AF12 = 0x0C,
		GPIO_CFG_AF13 = 0x0D,
		GPIO_CFG_EINT = 0x0E,	/* external interrupt sense (input) */
		GPIO_CFG_IODISABLE = 0x0F,
	} GPIOMode_TypeDef;

	#define HARDWARE_NCORES 2
	#define WITHCPUNAME "Allw T113-s3"

#elif CPUSTYLE_VM14

	typedef uint_fast16_t adcvalholder_t;
	typedef int_fast16_t sadcvalholder_t;	// для хранения знаковых значений

	#if WITHCPUXOSC
		// с внешним генератором
		#define	REFINFREQ WITHCPUXOSC
	#elif WITHCPUXTAL
		// с внешним кварцевым резонатором
		#define	REFINFREQ WITHCPUXTAL
	#endif /* WITHCPUXTAL */

	#define HARDWARE_CLK32K_FREQ 32000uL
	#define HARDWARE_CLK16M_RC_FREQ 16000000uL

	#define CPU_FREQ	(elveesvm14_get_arm_freq())
	#define BOARD_SPI_FREQ (elveesvm14_get_spi_freq())
	#define BOARD_USART_FREQ (elveesvm14_get_usart_freq())

	#define TICKS_FREQUENCY 200
	#define ADCVREF_CPU	33		// 3.3 volt
	#define HARDWARE_ADCBITS 12

	#define SPISPEED 		12000000u	/* 12 MHz на SCLK - требуемая скорость передачи по SPI */
	#define SPISPEEDUFAST 	24000000u	/* 12 MHzна SCLK - требуемая скорость передачи по SPI */
	#define	SPISPEED400k	400000u	/* 400 kHz для низкоскоростных микросхем */
	//#define	SPISPEED100k	100000u	/* 100 kHz для низкоскоростных микросхем */


	#define HARDWARE_NCORES 2
	#define WITHCPUNAME "Elvees VM14"

#elif CPUSTYLE_F133

	typedef uint_fast16_t adcvalholder_t;
	typedef int_fast16_t sadcvalholder_t;	// для хранения знаковых значений

	#if WITHCPUXOSC
		// с внешним генератором
		#define	REFINFREQ WITHCPUXOSC
	#elif WITHCPUXTAL
		// с внешним кварцевым резонатором
		#define	REFINFREQ WITHCPUXTAL
	#endif /* WITHCPUXTAL */

	#define HARDWARE_CLK32K_FREQ 32000uL
	#define HARDWARE_CLK16M_RC_FREQ 16000000uL

	#define CPU_FREQ	(allwnrf133_get_riscv_freq())
	#define BOARD_USART_FREQ (allwnrt113_get_uart_freq())

	#define TICKS_FREQUENCY 200
	#define ADCVREF_CPU	33		// 3.3 volt
	#define HARDWARE_ADCBITS 12

	#define SPISPEED 		12000000u	/* 12 MHz на SCLK - требуемая скорость передачи по SPI */
	#define SPISPEEDUFAST 	24000000u	/* 12 MHzна SCLK - требуемая скорость передачи по SPI */
	#define	SPISPEED400k	400000u		/* 400 kHz для низкоскоростных микросхем */
	//#define	SPISPEED100k	100000u	/* 100 kHz для низкоскоростных микросхем */


	typedef enum {
		GPIO_CFG_IN  = 0x00,
		GPIO_CFG_OUT = 0x01,
		GPIO_CFG_AF2 = 0x02,
		GPIO_CFG_AF3 = 0x03,
		GPIO_CFG_AF4 = 0x04,
		GPIO_CFG_AF5 = 0x05,
		GPIO_CFG_AF6 = 0x06,
		GPIO_CFG_AF7 = 0x07,
		GPIO_CFG_AF8 = 0x08,
		GPIO_CFG_AF9 = 0x09,
		GPIO_CFG_AF10 = 0x0A,
		GPIO_CFG_AF11 = 0x0B,
		GPIO_CFG_AF12 = 0x0C,
		GPIO_CFG_AF13 = 0x0D,
		GPIO_CFG_EINT = 0x0E,	/* external interrupt sense (input) */
		GPIO_CFG_IODISABLE = 0x0F,
	} GPIOMode_TypeDef;
	#define WITHCPUNAME "Allw F133-A"

#elif defined(_WIN32)

	#define ADCVREF_CPU	33		// 3.3 volt
	#define HARDWARE_ADCBITS 12	/* АЦП работает с 12-битными значениями */

	//#define HARDWARE_ADCINPUTS	40	/* до 8-ти входов АЦП */

	#define DACVREF_CPU	33		// 3.3 volt
	#define HARDWARE_DACBITS 12	/* ЦАП работает с 12-битными значениями */
	#define TICKS_FREQUENCY 200


#elif CPUSTYLE_UBLAZE


	#define ADCVREF_CPU	33		// 3.3 volt
	#define HARDWARE_ADCBITS 12	/* АЦП работает с 12-битными значениями */

	//#define HARDWARE_ADCINPUTS	40	/* до 8-ти входов АЦП */

	#define DACVREF_CPU	33		// 3.3 volt
	#define HARDWARE_DACBITS 12	/* ЦАП работает с 12-битными значениями */
	#define TICKS_FREQUENCY 200
	#define WITHCPUNAME "MicroBlaze"

#else

	#error Undefined CPUSTYLE_XXX

#endif

#if LINUX_SUBSYSTEM

	/* Linux targets: No any hardware IRQ control */

	typedef uint_fast32_t IRQL_t;

	#define IRQL_SYSTEM 			0
	#define IRQL_REALTIME 			0
	#define IRQL_OVERREALTIME 		0

	#define global_enableIRQ() do {  } while (0)
	#define global_disableIRQ() do {  } while (0)

#elif defined (__CORTEX_M)

	/* Cortex-M tergets */

	typedef uint_fast32_t IRQL_t;

	#if WITHNESTEDINTERRUPTS

		// The processor does not process any exception with a priority value greater than or equal to BASEPRI.
		extern uint32_t gARM_OVERREALTIME_PRIORITY;
		extern uint32_t gARM_REALTIME_PRIORITY;
		extern uint32_t gARM_SYSTEM_PRIORITY;
		extern uint32_t gARM_BASEPRI_ONLY_REALTIME;
		extern uint32_t gARM_BASEPRI_ONLY_OVERREALTIME;
		extern uint32_t gARM_BASEPRI_ALL_ENABLED;
		// See usage of functions NVIC_PriorityGroupConfig and NVIC_SetPriorityGrouping
		// A lower priority value indicating a higher priority of running handler
		#define ARM_OVERREALTIME_PRIORITY	((const uint32_t) gARM_OVERREALTIME_PRIORITY)
		#define ARM_REALTIME_PRIORITY	((const uint32_t) gARM_REALTIME_PRIORITY)
		#define ARM_SYSTEM_PRIORITY	((const uint32_t) gARM_SYSTEM_PRIORITY)

		#define IRQL_SYSTEM ((NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 2, 0) << (8 - __NVIC_PRIO_BITS)) & 0xff)	// value for __set_BASEPRI
		#define IRQL_REALTIME ((NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 1, 0) << (8 - __NVIC_PRIO_BITS)) & 0xff)	// value for __set_BASEPRI
		#define IRQL_OVERREALTIME ((NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 0, 0) << (8 - __NVIC_PRIO_BITS)) & 0xff)	// value for __set_BASEPRI
		
	#else /* WITHNESTEDINTERRUPTS */

		#define ARM_OVERREALTIME_PRIORITY	(0)
		#define ARM_REALTIME_PRIORITY	(0)
		#define ARM_SYSTEM_PRIORITY	(0)

	#endif /* WITHNESTEDINTERRUPTS */

	#define global_enableIRQ() do { __enable_irq(); } while (0)
	#define global_disableIRQ() do { __disable_irq(); } while (0)

	/* получение адреса для атомарного доступа к битам (с) demiurg_spb */
	/*
	static __attribute__( ( always_inline ) ) volatile uint32_t* bb_bit_address(volatile uint32_t* p, uint_fast8_t bit)
	{
		return ( (volatile uint32_t*) (((uint32_t) p & (uint32_t) 0xf0000000uL) + (uint32_t) 0x02000000uL
		          + (((uint32_t)p & (uint32_t) 0x000fffffUL)<<5) + ((uint32_t) bit<<2)));
	}
	*/

#elif CPUSTYLE_ATMEGA || CPUSTYLE_ATXMEGA

	typedef uint_fast8_t IRQL_t;

	#define global_enableIRQ() do { sei(); } while (0)
	#define global_disableIRQ() do { cli(); } while (0)

#elif (__GIC_PRESENT == 1)

	typedef uint_fast32_t IRQL_t;

	#define ICPIDR0	(* (const volatile uint32_t *) (GIC_DISTRIBUTOR_BASE + 0xFE0))
	#define ICPIDR1	(* (const volatile uint32_t *) (GIC_DISTRIBUTOR_BASE + 0xFE4))
	#define ICPIDR2	(* (const volatile uint32_t *) (GIC_DISTRIBUTOR_BASE + 0xFE8))

	#if WITHNESTEDINTERRUPTS

		// The processor does not process any exception with a priority value greater than or equal to BASEPRI.
		extern uint32_t gARM_OVERREALTIME_PRIORITY;
		extern uint32_t gARM_REALTIME_PRIORITY;
		extern uint32_t gARM_SYSTEM_PRIORITY;
		extern uint32_t gARM_BASEPRI_ONLY_REALTIME;
		extern uint32_t gARM_BASEPRI_ONLY_OVERREALTIME;
		extern uint32_t gARM_BASEPRI_ALL_ENABLED;

		#define GIC_ENCODE_PRIORITY(v) ((v) << (GIC_GetBinaryPoint() + 1))

		#define IRQL_SYSTEM GIC_ENCODE_PRIORITY(PRI_SYS)	// value for GIC_SetInterfacePriorityMask
		#define IRQL_REALTIME GIC_ENCODE_PRIORITY(PRI_RT)	// value for GIC_SetInterfacePriorityMask
		#define IRQL_OVERREALTIME GIC_ENCODE_PRIORITY(PRI_OVRT)	// value for GIC_SetInterfacePriorityMask
		/*
			GICC_PMR == INTC.ICCPMR

			Provides an interrupt priority filter. 
			Only interrupts with higher priority than the value in this
			register are signaled to the processor.

		*/
		enum
		{
			PRI_IPC,	/* Приоритет SGI прерывания для синхронизации приоритетов GIC на остальных процессорах */
			PRI_IPC_ONLY,
			PRI_OVRT,
			PRI_RT,
			PRI_SYS,
			PRI_USER,

//			gARM_OVERREALTIME_PRIORITY = GIC_ENCODE_PRIORITY(PRI_OVRT),	// value for GIC_SetPriority
//			gARM_REALTIME_PRIORITY = GIC_ENCODE_PRIORITY(PRI_RT),	// value for GIC_SetPriority
//			gARM_SYSTEM_PRIORITY = GIC_ENCODE_PRIORITY(PRI_SYS),		// value for GIC_SetPriority
//
//			gARM_BASEPRI_ONLY_REALTIME = GIC_ENCODE_PRIORITY(PRI_SYS),	// value for GIC_SetInterfacePriorityMask
//			gARM_BASEPRI_ALL_ENABLED = GIC_ENCODE_PRIORITY(PRI_USER)	// value for GIC_SetInterfacePriorityMask
			PRI_count
		};

		#define BOARD_SGI_IRQ SGI1_IRQn		/* Прерывание для синхронизации приоритетов GIC на остальных процессорах  */
		#define BOARD_SGI_PRIO	GIC_ENCODE_PRIORITY(PRI_IPC)

		#define RUNNING_PRI	((GICInterface->RPR & 0xFF) >> GIC_PRIORITYSHIFT) // The current running priority on the CPU interface.

		// A lower priority value indicating a higher priority
		#define ARM_OVERREALTIME_PRIORITY	((const uint32_t) gARM_OVERREALTIME_PRIORITY)
		#define ARM_REALTIME_PRIORITY	((const uint32_t) gARM_REALTIME_PRIORITY)
		#define ARM_SYSTEM_PRIORITY	((const uint32_t) gARM_SYSTEM_PRIORITY)

		#if defined(__aarch64__)

			#define global_enableIRQ() do { \
				} while (0)
			#define global_disableIRQ() do { \
			} while (0)

		#else /* defined(__aarch64__) */

			#define global_enableIRQ() do { \
				__enable_irq(); \
				} while (0)
			#define global_disableIRQ() do { \
				__disable_irq(); \
			} while (0)
		#endif /* defined(__aarch64__) */

	#else /* WITHNESTEDINTERRUPTS */

		#define ARM_OVERREALTIME_PRIORITY	0
		#define ARM_REALTIME_PRIORITY	0
		#define ARM_SYSTEM_PRIORITY		0

		#define BOARD_SGI_IRQ SGI1_IRQn		/* Прерывание для синхронизации приоритетов GIC на остальных процессорах  */
		#define BOARD_SGI_PRIO	0

		#define global_enableIRQ() do { \
			__enable_irq(); \
			} while (0)
		#define global_disableIRQ() do { \
			__disable_irq(); \
		} while (0)

	#endif /* WITHNESTEDINTERRUPTS */

#elif CPUSTYLE_RISCV

	typedef uint_xlen_t IRQL_t;

	#define ARM_IPC_PRIORITY			4
	#define ARM_OVERREALTIME_PRIORITY	3	/* валкодер */
	#define ARM_REALTIME_PRIORITY		2	/* звук */
	#define ARM_SYSTEM_PRIORITY			1	/* таймеры, USB */
	#define ARM_USER_PRIORITY			0	/*  Значение, на которое инициализируется PLIC->PLIC_MTH_REG */

	#define global_enableIRQ() do { csr_set_bits_mie(MIE_MEI_BIT_MASK); } while (0)
	#define global_disableIRQ() do { csr_clr_bits_mie(MIE_MEI_BIT_MASK); } while (0)

	#define IRQL_SYSTEM 			ARM_SYSTEM_PRIORITY
	#define IRQL_REALTIME 			ARM_REALTIME_PRIORITY
	#define IRQL_OVERREALTIME		ARM_OVERREALTIME_PRIORITY

#elif CPUSTYLE_UBLAZE

	typedef uint_fast32_t IRQL_t;

	#define global_enableIRQ() do { } while (0)
	#define global_disableIRQ() do { } while (0)

#else /* CPUSTYLE_ARM_CM3 || CPUSTYLE_ARM_CM4 */

	#warning Unsupported target IRQ control

	typedef uint_fast32_t IRQL_t;

	#define IRQL_SYSTEM 			0
	#define IRQL_REALTIME 		0
	#define IRQL_OVERREALTIME 		0

	#define global_enableIRQ() do {  } while (0)
	#define global_disableIRQ() do {  } while (0)

#endif /* CPUSTYLE_ARM_CM3 */

/* STM32: In HS mode and when the DMA is used, all variables and data structures dealing
   with the DMA during the transaction process should be 4-bytes aligned */    

#if defined   (__GNUC__)        /* GNU Compiler */
	#pragma GCC diagnostic ignored "-Wunused-function"
	#pragma GCC diagnostic ignored "-Wunused-variable"
	#pragma GCC diagnostic ignored "-Wunused-const-variable"
	#pragma GCC diagnostic error "-Wwrite-strings"

	#define __ALIGN4_END    __attribute__ ((aligned (4)))
	#define __ALIGN4_BEGIN         

	#define ATTRPACKED __attribute__ ((packed))
	#define ATTRNORETURN __attribute__ ((__noreturn__))
	#define KEYWORDPACKED __packed

#else                           
	#if defined   (__CC_ARM)      /* ARM Compiler */
		#define __ALIGN4_BEGIN    __align(4)  
		#define __ALIGN4_END
	#elif defined (__ICCARM__)    /* IAR Compiler */
		#define __ALIGN4_BEGIN 
		#define __ALIGN4_END
	#elif defined  (__TASKING__)  /* TASKING Compiler */
		#define __ALIGN4_BEGIN    __align(4) 
		#define __ALIGN4_END
	#endif /* __CC_ARM */  

	#define ATTRPACKED __attribute__ ((packed))
	#define ATTRNORETURN __attribute__ ((__noreturn__))
	#define KEYWORDPACKED __packed

#endif /* __GNUC__ */

#define WITHHARDINTERLOCK (WITHNESTEDINTERRUPTS && (CPUSTYLE_ARM_CM7 || CPUSTYLE_ARM_CM4 || CPUSTYLE_ARM_CM3 || CPUSTYLE_ARM_CM0 || (__CORTEX_A != 0)))

#define HARDWARE_DELAY_MS(t) do { local_delay_ms(t); } while (0)	//HAL_Delay(t)
#define HARDWARE_DELAY_US(t) do { local_delay_us(t); } while (0)
#define HARDWARE_GETTICK_MS() ((uint32_t) 0) // HAL_GetTick()

#define WITHSPECTRUMWF (WITHIF4DSP && (WITHRTS96 || WITHRTS192) && ! LCDMODE_HD44780 && ! LCDMODE_DUMMY)

/* Сброс мощности при запросе TUNE от автотюнера или извне */
#define WITHLOWPOWEREXTTUNE	(defined (HARDWARE_GET_TUNE) || WITHAUTOTUNER)
#define WITHNOTXDACCONTROL	1	/* в этой версии нет ЦАП управления смещением TXDAC передатчика */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* PARAMDEPEND_H_INCLUDED */
