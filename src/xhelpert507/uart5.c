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

// давление
// RS-485

void user_uart5_onrxchar(uint_fast8_t c)
{

}

void user_uart5_ontxchar(void * ctx)
{

}

void user_uart5_initialize(void)
{
	hardware_uart5_initialize(1, 9600);
	hardware_uart5_set_speed(9600);
	hardware_uart5_enablerx(0);
	hardware_uart5_enabletx(0);
}

void uart5_spool(void)
{
}

#endif /* WITHCTRLBOARDT507 */
