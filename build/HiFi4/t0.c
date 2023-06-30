#include "../../arch/t113s3/allwnr_t113s3.h"

void dbg_puts(const char * s);
void dbg_putchar(uint_fast8_t c);

void dbg_putchar(uint_fast8_t c)
{
	if (c == '\n')
		dbg_putchar('\r');

	while ((UART0->UART_USR & (1u << 1)) == 0)	// TX FIFO Not Full
		;
	UART0->UART_RBR_THR_DLL = c;
}


void dbg_puts(const char * s)
{
	char c;

	while ((c = * s ++) != '\n')
		dbg_putchar(c);
}

void xmain(int v1, int v2)
{
	(void) v1;
	(void) v2;
    dbg_putchar('H');
    dbg_putchar('e');
    dbg_putchar('l');
    dbg_putchar('l');
    dbg_putchar('o');
    dbg_putchar('!');
	for (;;)
		;

    dbg_puts("Hello, Word (HiFi4 DSP)!\n");
	for (;;)
		;
}
