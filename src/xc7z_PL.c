#include "hardware.h"
#include "board.h"
#include "audio.h"
#include "formats.h"
#include <math.h>

#if (CPUSTYLE_XC7Z) && ! WITHISBOOTLOADER

#include "xc7z_inc.h"

/* Audio register map definitions */
#define AUDIO_REG_I2S_RESET 		 0x00   //Write only
#define AUDIO_REG_I2S_CTRL			 0x04
#define AUDIO_REG_I2S_CLK_CTRL 		 0x08
#define AUDIO_REG_I2S_PERIOD 		 0x18
#define AUDIO_REG_I2S_RX_FIFO 		 0x28   //Read only
#define AUDIO_REG_I2S_TX_FIFO 		 0x2C	//Write only


/* I2S reset mask definitions  */
#define TX_FIFO_RESET_MASK 		 	0x00000002
#define RX_FIFO_RESET_MASK 		 	0x00000004

/* I2S Control mask definitions  */
#define TX_ENABLE_MASK 		 		0x00000001
#define RX_ENABLE_MASK 		 		0x00000002

/* I2S Clock Control mask definitions  */
#define BCLK_DIV_MASK 		 		0x000000FF
#define LRCLK_DIV_MASK 		 		0x00FF0000

void xcz_rxtx_state(uint8_t tx)
{
	Xil_Out32(XPAR_IQ_MODEM_TRX_CONTROL2_0_S00_AXI_BASEADDR + 0, (tx != 0));
}

void xcz_dds_ftw(const uint_least64_t * val)
{
	Xil_Out32(XPAR_IQ_MODEM_TRX_CONTROL2_0_S00_AXI_BASEADDR + 4, * val);
	mirror_nco1 = * val;
}

void xcz_dds_rts(const uint_least64_t * val)
{
	Xil_Out32(XPAR_IQ_MODEM_TRX_CONTROL2_0_S00_AXI_BASEADDR + 8, * val);
	mirror_ncorts = * val;
}

void xcz_rx_iq_shift(uint32_t val) // 48
{
	Xil_Out32(XPAR_IQ_MODEM_TRX_CONTROL2_0_S00_AXI_BASEADDR + 12, val);
}

void xcz_dds_ftw_sub(const uint_least64_t * val)
{
	Xil_Out32(XPAR_IQ_MODEM_TRX_CONTROL2_0_S00_AXI_BASEADDR + 28, * val);
	mirror_nco2 = * val;
}

void xcz_rx_cic_shift(uint32_t val)
{
	Xil_Out32(XPAR_IQ_MODEM_TRX_CONTROL2_0_S00_AXI_BASEADDR + 16, val);
}

void xcz_tx_shift(uint32_t val)
{
	Xil_Out32(XPAR_IQ_MODEM_TRX_CONTROL2_0_S00_AXI_BASEADDR + 20, val);
}

#if WITHRTS96

void xcz_ah_preinit(void)
{
#if defined (XPAR_AXI_I2S_ADI_0_BASEADDR)
	Xil_Out32(XPAR_AXI_I2S_ADI_0_BASEADDR + AUDIO_REG_I2S_CLK_CTRL, (64 / 2 - 1) << 16 | (4 / 2 - 1));
	Xil_Out32(XPAR_AXI_I2S_ADI_0_BASEADDR + AUDIO_REG_I2S_PERIOD, DMABUFFSIZE16TX);
	Xil_Out32(XPAR_AXI_I2S_ADI_0_BASEADDR + AUDIO_REG_I2S_CTRL, TX_ENABLE_MASK | RX_ENABLE_MASK);
#endif /* defined (XPAR_AXI_I2S_ADI_0_BASEADDR) */

	xcz_rxtx_state(1);
	xcz_rxtx_state(0);
	xcz_rx_iq_shift(CALIBRATION_IQ_RX_SHIFT);
	xcz_tx_shift(CALIBRATION_TX_SHIFT);
}

// ****************** IF RX ******************

static uintptr_t addr32rx;

void xcz_if_rx_init(void)
{
	addr32rx = allocate_dmabuffer32rx();
}

void xcz_fifo_if_rx_inthandler(void)
{
	uint32_t * r = (uint32_t *) addr32rx;

	for (uint16_t i = 0; i < DMABUFFSIZE32RX; i ++)
		r[i] = Xil_In32(XPAR_IQ_MODEM_AXI_FIFO_IQ_RX_BASEADDR);

	processing_dmabuffer32rx(addr32rx);
	processing_dmabuffer32rts(addr32rx);
}

void xcz_if_rx_enable(uint_fast8_t state)
{
	arm_hardware_set_handler_realtime(XPAR_FABRIC_AXI_FIFO_IQ_RX_IRQ_INTR, xcz_fifo_if_rx_inthandler);
}

// ****************** IF TX ******************

void xcz_if_tx_init(void)
{

}

void xcz_dma_if_tx_inthandler(void)
{
#if WITHTX
	const uintptr_t addr = getfilled_dmabuffer32tx_main();
	uint32_t * r = (uint32_t *) addr;

	for (uint16_t i = 0; i < DMABUFFSIZE32TX / 2; i ++)				// 16 bit
		Xil_Out32(XPAR_IQ_MODEM_AXI_FIFO_IQ_TX_BASEADDR, r[i]);

	release_dmabuffer32tx(addr);
#endif /* WITHTX */
}

void xcz_if_tx_enable(uint_fast8_t state)
{
#if WITHTX
	arm_hardware_set_handler_realtime(XPAR_FABRIC_AXI_FIFO_IQ_TX_IRQ_INTR, xcz_dma_if_tx_inthandler);
#endif /* WITHTX */
}

// ****************** Audio MIC receive ******************

void xcz_audio_rx_init(void)
{

}

void xcz_fifo_mic_inthandler(void)
{
#if WITHTX
	uintptr_t addr = allocate_dmabuffer16rx();
	uint32_t * r = (uint32_t *) addr;

	for (uint16_t i = 0; i < DMABUFFSIZE16RX; i ++)
		r[i] = Xil_In32(XPAR_AUDIO_AXI_FIFO_MIC_BASEADDR);

	processing_dmabuffer16rx(addr);
#endif /* WITHTX */
}

void xcz_audio_rx_enable(uint_fast8_t state)
{
#if WITHTX
	arm_hardware_set_handler_realtime(XPAR_FABRIC_AXI_FIFO_MIC_IRQ_INTR, xcz_fifo_mic_inthandler);
#endif /* WITHTX */
}

// ****************** Audio phones transmit ******************

void xcz_audio_tx_init(void)
{

}

void xcz_fifo_phones_inthandler(void)
{
	const uintptr_t addr = getfilled_dmabuffer16txphones();
	uint32_t * r = (uint32_t *) addr;

	for (uint16_t i = 0; i < DMABUFFSIZE16TX; i ++)
		Xil_Out32(XPAR_AUDIO_AXI_FIFO_PHONES_BASEADDR, r[i]);

	release_dmabuffer16tx(addr);
}

void xcz_audio_tx_enable(uint_fast8_t state)
{
	arm_hardware_set_handler_realtime(XPAR_FABRIC_AXI_FIFO_PHONES_IRQ_INTR, xcz_fifo_phones_inthandler);
}

#endif /* WITHRTS96 */

#else // заглушки для бутлоадера

void xcz_rxtx_state(uint8_t tx)
{

}

#endif /* CPUSTYLE_XC7Z */
