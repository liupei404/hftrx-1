/* Generated section start */ 

/* Peripheral and RAM base address */

#define	GPIOBLOCK_BASE	0x02000000
#define	GPIOB_BASE	0x02000030
#define	GPIOC_BASE	0x02000060
#define	GPIOD_BASE	0x02000090
#define	GPIOE_BASE	0x020000C0
#define	GPIOF_BASE	0x020000F0
#define	GPIOG_BASE	0x02000120
#define	GPIOINTB_BASE	0x02000220
#define	GPIOINTC_BASE	0x02000240
#define	GPIOINTD_BASE	0x02000260
#define	GPIOINTE_BASE	0x02000280
#define	GPIOINTF_BASE	0x020002A0
#define	GPIOINTG_BASE	0x020002C0
#define	CCU_BASE	0x02001000
#define	AUDIO_CODEC_BASE	0x02030000
#define	OWA_BASE	0x02036000
#define	UART0_BASE	0x02500000
#define	UART1_BASE	0x02500400
#define	UART2_BASE	0x02500800
#define	UART3_BASE	0x02500C00
#define	UART4_BASE	0x02501000
#define	UART5_BASE	0x02501400
#define	TWI0_BASE	0x02502000
#define	TWI1_BASE	0x02502400
#define	TWI2_BASE	0x02502800
#define	TWI3_BASE	0x02502C00
#define	CAN0_BASE	0x02504000
#define	CAN1_BASE	0x02504400
#define	DDRPHYC_BASE	0x03103000
#define	SMHC0_BASE	0x04020000
#define	SMHC1_BASE	0x04021000
#define	SMHC2_BASE	0x04022000
#define	RISC_CFG_BASE	0x06010000
#define	RISC_WDG_BASE	0x06011000
#define	RISC_TIMESTAMP_BASE	0x06012000
#define	PLIC_BASE	0x10000000
/*
 * @brief RISC_CFG
 */
/*!< RISC_CFG Controller Interface */
typedef struct RISC_CFG_Type
{
	uint32_t reserved_0x000;
	__IO uint32_t RISC_STA_ADD0_REG;                     /*!< Offset 0x004 RISC Start Address0 Register */
	__IO uint32_t RISC_STA_ADD1_REG;                     /*!< Offset 0x008 RISC Start Address1 Register */
	uint32_t reserved_0x00C;
	__IO uint32_t RF1P_CFG_REG;                          /*!< Offset 0x010 RF1P Configuration Register */
	uint32_t reserved_0x014 [0x0002];
	__IO uint32_t ROM_CFG_REG;                           /*!< Offset 0x01C ROM Configuration Register */
	__IO uint32_t WAKEUP_EN_REG;                         /*!< Offset 0x020 Wakeup Enable Register */
	__IO uint32_t WAKEUP_MASK0_REG;                      /*!< Offset 0x024 Wakeup Mask0 Register */
	__IO uint32_t WAKEUP_MASK1_REG;                      /*!< Offset 0x028 Wakeup Mask1 Register */
	__IO uint32_t WAKEUP_MASK2_REG;                      /*!< Offset 0x02C Wakeup Mask2 Register */
	__IO uint32_t WAKEUP_MASK3_REG;                      /*!< Offset 0x030 Wakeup Mask3 Register */
	__IO uint32_t WAKEUP_MASK4_REG;                      /*!< Offset 0x034 Wakeup Mask4 Register */
	uint32_t reserved_0x038 [0x0002];
	__IO uint32_t TS_TMODE_SEL_REG;                      /*!< Offset 0x040 Timestamp Test Mode Select Register */
	__IO uint32_t SRAM_ADDR_TWIST_REG;                   /*!< Offset 0x044 SRAM Address Twist Register */
	__IO uint32_t WORK_MODE_REG;                         /*!< Offset 0x048 Work Mode Register */
	uint32_t reserved_0x04C;
	__IO uint32_t RETITE_PC0_REG;                        /*!< Offset 0x050 Retire PC0 Register */
	__IO uint32_t RETITE_PC1_REG;                        /*!< Offset 0x054 Retire PC1 Register */
	uint32_t reserved_0x058 [0x0002];
	__IO uint32_t IRQ_MODE0_REG;                         /*!< Offset 0x060 IRQ Mode0 Register */
	__IO uint32_t IRQ_MODE1_REG;                         /*!< Offset 0x064 IRQ Mode1 Register */
	__IO uint32_t IRQ_MODE2_REG;                         /*!< Offset 0x068 IRQ Mode2 Register */
	__IO uint32_t IRQ_MODE3_REG;                         /*!< Offset 0x06C IRQ Mode3 Register */
	__IO uint32_t IRQ_MODE4_REG;                         /*!< Offset 0x070 IRQ Mode4 Register */
	uint32_t reserved_0x074 [0x0024];
	__IO uint32_t RISC_AXI_PMU_CTRL;                     /*!< Offset 0x104 RISC AXI PMU Control Register */
	__IO uint32_t RISC_AXI_PMU_PRD;                      /*!< Offset 0x108 RISC AXI PMU Period Register */
	__IO uint32_t RISC_AXI_PMU_LAT_RD;                   /*!< Offset 0x10C RISC AXI PMU Read Latency Register */
	__IO uint32_t RISC_AXI_PMU_LAT_WR;                   /*!< Offset 0x110 RISC AXI PMU Write Latency Register */
	__IO uint32_t RISC_AXI_PMU_REQ_RD;                   /*!< Offset 0x114 RISC AXI PMU Read Request Register */
	__IO uint32_t RISC_AXI_PMU_REQ_WR;                   /*!< Offset 0x118 RISC AXI PMU Write Request Register */
	__IO uint32_t RISC_AXI_PMU_BW_RD;                    /*!< Offset 0x11C RISC AXI PMU Read Bandwidth Register */
	__IO uint32_t RISC_AXI_PMU_BW_WR;                    /*!< Offset 0x120 RISC AXI PMU Write Bandwidth Register */
} RISC_CFG_TypeDef; /* size of structure = 0x124 */
/*
 * @brief CCU
 */
/*!< CCU Controller Interface */
typedef struct CCU_Type
{
	__IO uint32_t PLL_CPU_CTRL_REG;                      /*!< Offset 0x000 PLL_CPU Control Register */
	uint32_t reserved_0x004 [0x0003];
	__IO uint32_t PLL_DDR_CTRL_REG;                      /*!< Offset 0x010 PLL_DDR Control Register */
	uint32_t reserved_0x014 [0x0003];
	__IO uint32_t PLL_PERI_CTRL_REG;                     /*!< Offset 0x020 PLL_PERI Control Register */
	uint32_t reserved_0x024 [0x0007];
	__IO uint32_t PLL_VIDEO0_CTRL_REG;                   /*!< Offset 0x040 PLL_VIDEO0 Control Register */
	uint32_t reserved_0x044;
	__IO uint32_t PLL_VIDEO1_CTRL_REG;                   /*!< Offset 0x048 PLL_VIDEO1 Control Register */
	uint32_t reserved_0x04C [0x0003];
	__IO uint32_t PLL_VE_CTRL_REG;                       /*!< Offset 0x058 PLL_VE Control Register */
	uint32_t reserved_0x05C [0x0007];
	__IO uint32_t PLL_AUDIO0_CTRL_REG;                   /*!< Offset 0x078 PLL_AUDIO0 Control Register */
	uint32_t reserved_0x07C;
	__IO uint32_t PLL_AUDIO1_CTRL_REG;                   /*!< Offset 0x080 PLL_AUDIO1 Control Register */
	uint32_t reserved_0x084 [0x0023];
	__IO uint32_t PLL_DDR_PAT0_CTRL_REG;                 /*!< Offset 0x110 PLL_DDR Pattern0 Control Register */
	__IO uint32_t PLL_DDR_PAT1_CTRL_REG;                 /*!< Offset 0x114 PLL_DDR Pattern1 Control Register */
	uint32_t reserved_0x118 [0x0002];
	__IO uint32_t PLL_PERI_PAT0_CTRL_REG;                /*!< Offset 0x120 PLL_PERI Pattern0 Control Register */
	__IO uint32_t PLL_PERI_PAT1_CTRL_REG;                /*!< Offset 0x124 PLL_PERI Pattern1 Control Register */
	uint32_t reserved_0x128 [0x0006];
	__IO uint32_t PLL_VIDEO0_PAT0_CTRL_REG;              /*!< Offset 0x140 PLL_VIDEO0 Pattern0 Control Register */
	__IO uint32_t PLL_VIDEO0_PAT1_CTRL_REG;              /*!< Offset 0x144 PLL_VIDEO0 Pattern1 Control Register */
	__IO uint32_t PLL_VIDEO1_PAT0_CTRL_REG;              /*!< Offset 0x148 PLL_VIDEO1 Pattern0 Control Register */
	__IO uint32_t PLL_VIDEO1_PAT1_CTRL_REG;              /*!< Offset 0x14C PLL_VIDEO1 Pattern1 Control Register */
	uint32_t reserved_0x150 [0x0002];
	__IO uint32_t PLL_VE_PAT0_CTRL_REG;                  /*!< Offset 0x158 PLL_VE Pattern0 Control Register */
	__IO uint32_t PLL_VE_PAT1_CTRL_REG;                  /*!< Offset 0x15C PLL_VE Pattern1 Control Register */
	uint32_t reserved_0x160 [0x0006];
	__IO uint32_t PLL_AUDIO0_PAT0_CTRL_REG;              /*!< Offset 0x178 PLL_AUDIO0 Pattern0 Control Register */
	__IO uint32_t PLL_AUDIO0_PAT1_CTRL_REG;              /*!< Offset 0x17C PLL_AUDIO0 Pattern1 Control Register */
	__IO uint32_t PLL_AUDIO1_PAT0_CTRL_REG;              /*!< Offset 0x180 PLL_AUDIO1 Pattern0 Control Register */
	__IO uint32_t PLL_AUDIO1_PAT1_CTRL_REG;              /*!< Offset 0x184 PLL_AUDIO1 Pattern1 Control Register */
	uint32_t reserved_0x188 [0x005E];
	__IO uint32_t PLL_CPU_BIAS_REG;                      /*!< Offset 0x300 PLL_CPU Bias Register */
	uint32_t reserved_0x304 [0x0003];
	__IO uint32_t PLL_DDR_BIAS_REG;                      /*!< Offset 0x310 PLL_DDR Bias Register */
	uint32_t reserved_0x314 [0x0003];
	__IO uint32_t PLL_PERI_BIAS_REG;                     /*!< Offset 0x320 PLL_PERI Bias Register */
	uint32_t reserved_0x324 [0x0007];
	__IO uint32_t PLL_VIDEO0_BIAS_REG;                   /*!< Offset 0x340 PLL_VIDEO0 Bias Register */
	uint32_t reserved_0x344;
	__IO uint32_t PLL_VIDEO1_BIAS_REG;                   /*!< Offset 0x348 PLL_VIDEO1 Bias Register */
	uint32_t reserved_0x34C [0x0003];
	__IO uint32_t PLL_VE_BIAS_REG;                       /*!< Offset 0x358 PLL_VE Bias Register */
	uint32_t reserved_0x35C [0x0007];
	__IO uint32_t PLL_AUDIO0_BIAS_REG;                   /*!< Offset 0x378 PLL_AUDIO0 Bias Register */
	uint32_t reserved_0x37C;
	__IO uint32_t PLL_AUDIO1_BIAS_REG;                   /*!< Offset 0x380 PLL_AUDIO1 Bias Register */
	uint32_t reserved_0x384 [0x001F];
	__IO uint32_t PLL_CPU_TUN_REG;                       /*!< Offset 0x400 PLL_CPU Tuning Register */
	uint32_t reserved_0x404 [0x0043];
	__IO uint32_t PSI_CLK_REG;                           /*!< Offset 0x510 PSI Clock Register */
	uint32_t reserved_0x514 [0x0003];
	__IO uint32_t APB0_CLK_REG;                          /*!< Offset 0x520 APB0 Clock Register */
	__IO uint32_t APB1_CLK_REG;                          /*!< Offset 0x524 APB1 Clock Register */
	uint32_t reserved_0x528 [0x0006];
	__IO uint32_t MBUS_CLK_REG;                          /*!< Offset 0x540 MBUS Clock Register */
	uint32_t reserved_0x544 [0x002F];
	__IO uint32_t DE_CLK_REG;                            /*!< Offset 0x600 DE Clock Register */
	uint32_t reserved_0x604 [0x0002];
	__IO uint32_t DE_BGR_REG;                            /*!< Offset 0x60C DE Bus Gating Reset Register */
	uint32_t reserved_0x610 [0x0004];
	__IO uint32_t DI_CLK_REG;                            /*!< Offset 0x620 DI Clock Register */
	uint32_t reserved_0x624 [0x0002];
	__IO uint32_t DI_BGR_REG;                            /*!< Offset 0x62C DI Bus Gating Reset Register */
	__IO uint32_t G2D_CLK_REG;                           /*!< Offset 0x630 G2D Clock Register */
	uint32_t reserved_0x634 [0x0002];
	__IO uint32_t G2D_BGR_REG;                           /*!< Offset 0x63C G2D Bus Gating Reset Register */
	uint32_t reserved_0x640 [0x0010];
	__IO uint32_t CE_CLK_REG;                            /*!< Offset 0x680 CE Clock Register */
	uint32_t reserved_0x684 [0x0002];
	__IO uint32_t CE_BGR_REG;                            /*!< Offset 0x68C CE Bus Gating Reset Register */
	__IO uint32_t VE_CLK_REG;                            /*!< Offset 0x690 VE Clock Register */
	uint32_t reserved_0x694 [0x0002];
	__IO uint32_t VE_BGR_REG;                            /*!< Offset 0x69C VE Bus Gating Reset Register */
	uint32_t reserved_0x6A0 [0x001B];
	__IO uint32_t DMA_BGR_REG;                           /*!< Offset 0x70C DMA Bus Gating Reset Register */
	uint32_t reserved_0x710 [0x000B];
	__IO uint32_t HSTIMER_BGR_REG;                       /*!< Offset 0x73C HSTIMER Bus Gating Reset Register */
	__IO uint32_t AVS_CLK_REG;                           /*!< Offset 0x740 AVS Clock Register */
	uint32_t reserved_0x744 [0x0012];
	__IO uint32_t DBGSYS_BGR_REG;                        /*!< Offset 0x78C DBGSYS Bus Gating Reset Register */
	uint32_t reserved_0x790 [0x0007];
	__IO uint32_t PWM_BGR_REG;                           /*!< Offset 0x7AC PWM Bus Gating Reset Register */
	uint32_t reserved_0x7B0 [0x0003];
	__IO uint32_t IOMMU_BGR_REG;                         /*!< Offset 0x7BC IOMMU Bus Gating Reset Register */
	uint32_t reserved_0x7C0 [0x0010];
	__IO uint32_t DRAM_CLK_REG;                          /*!< Offset 0x800 DRAM Clock Register */
	__IO uint32_t MBUS_MAT_CLK_GATING_REG;               /*!< Offset 0x804 MBUS Master Clock Gating Register */
	uint32_t reserved_0x808;
	__IO uint32_t DRAM_BGR_REG;                          /*!< Offset 0x80C DRAM Bus Gating Reset Register */
	uint32_t reserved_0x810 [0x0008];
	__IO uint32_t SMHC0_CLK_REG;                         /*!< Offset 0x830 SMHC0 Clock Register */
	__IO uint32_t SMHC1_CLK_REG;                         /*!< Offset 0x834 SMHC1 Clock Register */
	__IO uint32_t SMHC2_CLK_REG;                         /*!< Offset 0x838 SMHC2 Clock Register */
	uint32_t reserved_0x83C [0x0004];
	__IO uint32_t SMHC_BGR_REG;                          /*!< Offset 0x84C SMHC Bus Gating Reset Register */
	uint32_t reserved_0x850 [0x002F];
	__IO uint32_t UART_BGR_REG;                          /*!< Offset 0x90C UART Bus Gating Reset Register */
	uint32_t reserved_0x910 [0x0003];
	__IO uint32_t TWI_BGR_REG;                           /*!< Offset 0x91C TWI Bus Gating Reset Register */
	uint32_t reserved_0x920 [0x0003];
	__IO uint32_t CAN_BGR_REG;                           /*!< Offset 0x92C CAN Bus Gating Reset Register */
	uint32_t reserved_0x930 [0x0004];
	__IO uint32_t SPI0_CLK_REG;                          /*!< Offset 0x940 SPI0 Clock Register */
	__IO uint32_t SPI1_CLK_REG;                          /*!< Offset 0x944 SPI1 Clock Register */
	uint32_t reserved_0x948 [0x0009];
	__IO uint32_t SPI_BGR_REG;                           /*!< Offset 0x96C SPI Bus Gating Reset Register */
	__IO uint32_t EMAC_25M_CLK_REG;                      /*!< Offset 0x970 EMAC_25M Clock Register */
	uint32_t reserved_0x974 [0x0002];
	__IO uint32_t EMAC_BGR_REG;                          /*!< Offset 0x97C EMAC Bus Gating Reset Register */
	uint32_t reserved_0x980 [0x0010];
	__IO uint32_t IRTX_CLK_REG;                          /*!< Offset 0x9C0 IRTX Clock Register */
	uint32_t reserved_0x9C4 [0x0002];
	__IO uint32_t IRTX_BGR_REG;                          /*!< Offset 0x9CC IRTX Bus Gating Reset Register */
	uint32_t reserved_0x9D0 [0x0007];
	__IO uint32_t GPADC_BGR_REG;                         /*!< Offset 0x9EC GPADC Bus Gating Reset Register */
	uint32_t reserved_0x9F0 [0x0003];
	__IO uint32_t THS_BGR_REG;                           /*!< Offset 0x9FC THS Bus Gating Reset Register */
	uint32_t reserved_0xA00 [0x0005];
	__IO uint32_t I2S1_CLK_REG;                          /*!< Offset 0xA14 I2S1 Clock Register */
	__IO uint32_t I2S2_CLK_REG;                          /*!< Offset 0xA18 I2S2 Clock Register */
	__IO uint32_t I2S2_ASRC_CLK_REG;                     /*!< Offset 0xA1C I2S2_ASRC Clock Register */
	__IO uint32_t I2S_BGR_REG;                           /*!< Offset 0xA20 I2S Bus Gating Reset Register */
	__IO uint32_t OWA_TX_CLK_REG;                        /*!< Offset 0xA24 OWA_TX Clock Register */
	__IO uint32_t OWA_RX_CLK_REG;                        /*!< Offset 0xA28 OWA_RX Clock Register */
	__IO uint32_t OWA_BGR_REG;                           /*!< Offset 0xA2C OWA Bus Gating Reset Register */
	uint32_t reserved_0xA30 [0x0004];
	__IO uint32_t DMIC_CLK_REG;                          /*!< Offset 0xA40 DMIC Clock Register */
	uint32_t reserved_0xA44 [0x0002];
	__IO uint32_t DMIC_BGR_REG;                          /*!< Offset 0xA4C DMIC Bus Gating Reset Register */
	__IO uint32_t AUDIO_CODEC_DAC_CLK_REG;               /*!< Offset 0xA50 AUDIO_CODEC_DAC Clock Register */
	__IO uint32_t AUDIO_CODEC_ADC_CLK_REG;               /*!< Offset 0xA54 AUDIO_CODEC_ADC Clock Register */
	uint32_t reserved_0xA58;
	__IO uint32_t AUDIO_CODEC_BGR_REG;                   /*!< Offset 0xA5C AUDIO_CODEC Bus Gating Reset Register */
	uint32_t reserved_0xA60 [0x0004];
	__IO uint32_t USB0_CLK_REG;                          /*!< Offset 0xA70 USB0 Clock Register */
	__IO uint32_t USB1_CLK_REG;                          /*!< Offset 0xA74 USB1 Clock Register */
	uint32_t reserved_0xA78 [0x0005];
	__IO uint32_t USB_BGR_REG;                           /*!< Offset 0xA8C USB Bus Gating Reset Register */
	uint32_t reserved_0xA90 [0x000B];
	__IO uint32_t DPSS_TOP_BGR_REG;                      /*!< Offset 0xABC DPSS_TOP Bus Gating Reset Register */
	uint32_t reserved_0xAC0 [0x0019];
	__IO uint32_t DSI_CLK_REG;                           /*!< Offset 0xB24 DSI Clock Register */
	uint32_t reserved_0xB28 [0x0009];
	__IO uint32_t DSI_BGR_REG;                           /*!< Offset 0xB4C DSI Bus Gating Reset Register */
	uint32_t reserved_0xB50 [0x0004];
	__IO uint32_t TCONLCD_CLK_REG;                       /*!< Offset 0xB60 TCONLCD Clock Register */
	uint32_t reserved_0xB64 [0x0006];
	__IO uint32_t TCONLCD_BGR_REG;                       /*!< Offset 0xB7C TCONLCD Bus Gating Reset Register */
	__IO uint32_t TCONTV_CLK_REG;                        /*!< Offset 0xB80 TCONTV Clock Register */
	uint32_t reserved_0xB84 [0x0006];
	__IO uint32_t TCONTV_BGR_REG;                        /*!< Offset 0xB9C TCONTV Bus Gating Reset Register */
	uint32_t reserved_0xBA0 [0x0003];
	__IO uint32_t LVDS_BGR_REG;                          /*!< Offset 0xBAC LVDS Bus Gating Reset Register */
	__IO uint32_t TVE_CLK_REG;                           /*!< Offset 0xBB0 TVE Clock Register */
	uint32_t reserved_0xBB4 [0x0002];
	__IO uint32_t TVE_BGR_REG;                           /*!< Offset 0xBBC TVE Bus Gating Reset Register */
	__IO uint32_t TVD_CLK_REG;                           /*!< Offset 0xBC0 TVD Clock Register */
	uint32_t reserved_0xBC4 [0x0006];
	__IO uint32_t TVD_BGR_REG;                           /*!< Offset 0xBDC TVD Bus Gating Reset Register */
	uint32_t reserved_0xBE0 [0x0004];
	__IO uint32_t LEDC_CLK_REG;                          /*!< Offset 0xBF0 LEDC Clock Register */
	uint32_t reserved_0xBF4 [0x0002];
	__IO uint32_t LEDC_BGR_REG;                          /*!< Offset 0xBFC LEDC Bus Gating Reset Register */
	uint32_t reserved_0xC00;
	__IO uint32_t CSI_CLK_REG;                           /*!< Offset 0xC04 CSI Clock Register */
	__IO uint32_t CSI_MASTER_CLK_REG;                    /*!< Offset 0xC08 CSI Master Clock Register */
	uint32_t reserved_0xC0C [0x0004];
	__IO uint32_t CSI_BGR_REG;                           /*!< Offset 0xC1C CSI Bus Gating Reset Register */
	uint32_t reserved_0xC20 [0x000C];
	__IO uint32_t TPADC_CLK_REG;                         /*!< Offset 0xC50 TPADC Clock Register */
	uint32_t reserved_0xC54 [0x0002];
	__IO uint32_t TPADC_BGR_REG;                         /*!< Offset 0xC5C TPADC Bus Gating Reset Register */
	uint32_t reserved_0xC60 [0x0028];
	__IO uint32_t RISC_CLK_REG;                          /*!< Offset 0xD00 RISC Clock Register */
	__IO uint32_t RISC_GATING_REG;                       /*!< Offset 0xD04 RISC Gating Configuration Register */
	uint32_t reserved_0xD08;
	__IO uint32_t RISC_CFG_BGR_REG;                      /*!< Offset 0xD0C RISC_CFG Bus Gating Reset Register */
} CCU_TypeDef; /* size of structure = 0xD10 */
/*
 * @brief PLIC
 */
/*!< PLIC Controller Interface */
typedef struct PLIC_Type
{
	__IO uint32_t PLIC_PRIO_REGn [0x400];                /*!< Offset 0x000 (0<n<256) PLIC Priority Register n */
	__IO uint32_t PLIC_IP_REGn [0x020];                  /*!< Offset 0x1000 (0≤n<9) PLIC Interrupt Pending Register n */
	uint32_t reserved_0x1080 [0x03E0];
	__IO uint32_t PLIC_MIE_REGn [0x020];                 /*!< Offset 0x2000 (0≤n<9) PLIC Machine Mode Interrupt Enable Register n */
	__IO uint32_t PLIC_SIE_REGn [0x020];                 /*!< Offset 0x2080 (0≤n<9) PLIC Superuser Mode Interrupt Enable Register n */
	uint32_t reserved_0x2100 [0x7F7BF];
	__IO uint32_t PLIC_CTRL_REG;                         /*!< Offset 0x1FFFFC PLIC Control Register */
	__IO uint32_t PLIC_MTH_REG;                          /*!< Offset 0x200000 PLIC Machine Threshold Register */
	__IO uint32_t PLIC_MCLAIM_REG;                       /*!< Offset 0x200004 PLIC Machine Claim Register */
	uint32_t reserved_0x200008 [0x03FE];
	__IO uint32_t PLIC_STH_REG;                          /*!< Offset 0x201000 PLIC Superuser Threshold Register */
	__IO uint32_t PLIC_SCLAIM_REG;                       /*!< Offset 0x201004 PLIC Superuser Claim Register */
} PLIC_TypeDef; /* size of structure = 0x201008 */
/*
 * @brief SYS_CFG
 */
/*!< SYS_CFG Controller Interface */
typedef struct SYS_CFG_Type
{
	uint32_t reserved_0x000 [0x0002];
	__IO uint32_t DSP_BOOT_RAMMAP_REG;                   /*!< Offset 0x008 DSP Boot SRAM Remap Control Register */
	uint32_t reserved_0x00C [0x0006];
	__IO uint32_t VER_REG;                               /*!< Offset 0x024 Version Register */
	uint32_t reserved_0x028 [0x0002];
	__IO uint32_t EMAC_EPHY_CLK_REG0;                    /*!< Offset 0x030 EMAC-EPHY Clock Register 0 */
	uint32_t reserved_0x034 [0x0047];
	__IO uint32_t SYS_LDO_CTRL_REG;                      /*!< Offset 0x150 System LDO Control Register */
	uint32_t reserved_0x154 [0x0003];
	__IO uint32_t RESCAL_CTRL_REG;                       /*!< Offset 0x160 Resistor Calibration Control Register */
	uint32_t reserved_0x164;
	__IO uint32_t RES240_CTRL_REG;                       /*!< Offset 0x168 240ohms Resistor Manual Control Register */
	__IO uint32_t RESCAL_STATUS_REG;                     /*!< Offset 0x16C Resistor Calibration Status Register */
} SYS_CFG_TypeDef; /* size of structure = 0x170 */
/*
 * @brief UART
 */
/*!< UART Controller Interface */
typedef struct UART_Type
{
	__IO uint32_t DATA;                                  /*!< Offset 0x000 UART Receive Buffer Register/Transmit Holding Register */
	__IO uint32_t DLH_IER;                               /*!< Offset 0x004 UART Divisor Latch High Register/UART Interrupt Enable Register */
	__IO uint32_t IIR_FCR;                               /*!< Offset 0x008 UART Interrupt Identity Register/UART FIFO Control Register */
	__IO uint32_t UART_LCR;                              /*!< Offset 0x00C UART Line Control Register */
	__IO uint32_t UART_MCR;                              /*!< Offset 0x010 UART Modem Control Register */
	__IO uint32_t UART_LSR;                              /*!< Offset 0x014 UART Line Status Register */
	__IO uint32_t UART_MSR;                              /*!< Offset 0x018 UART Modem Status Register */
	__IO uint32_t UART_SCH;                              /*!< Offset 0x01C UART Scratch Register */
	uint32_t reserved_0x020 [0x0017];
	__IO uint32_t UART_USR;                              /*!< Offset 0x07C UART Status Register */
	__IO uint32_t UART_TFL;                              /*!< Offset 0x080 UART Transmit FIFO Level Register */
	__IO uint32_t UART_RFL;                              /*!< Offset 0x084 UART Receive FIFO Level Register */
	__IO uint32_t UART_HSK;                              /*!< Offset 0x088 UART DMA Handshake Configuration Register */
	__IO uint32_t UART_DMA_REQ_EN;                       /*!< Offset 0x08C UART DMA Request Enable Register */
	uint32_t reserved_0x090 [0x0005];
	__IO uint32_t UART_HALT;                             /*!< Offset 0x0A4 UART Halt TX Register */
	uint32_t reserved_0x0A8 [0x0002];
	__IO uint32_t UART_DBG_DLL;                          /*!< Offset 0x0B0 UART Debug DLL Register */
	__IO uint32_t UART_DBG_DLH;                          /*!< Offset 0x0B4 UART Debug DLH Register */
	uint32_t reserved_0x0B8 [0x000E];
	__IO uint32_t UART_A_FCC;                            /*!< Offset 0x0F0 UART FIFO Clock Control Register */
	uint32_t reserved_0x0F4 [0x0003];
	__IO uint32_t UART_A_RXDMA_CTRL;                     /*!< Offset 0x100 UART RXDMA Control Register */
	__IO uint32_t UART_A_RXDMA_STR;                      /*!< Offset 0x104 UART RXDMA Start Register */
	__IO uint32_t UART_A_RXDMA_STA;                      /*!< Offset 0x108 UART RXDMA Status Register */
	__IO uint32_t UART_A_RXDMA_LMT;                      /*!< Offset 0x10C UART RXDMA Limit Register */
	__IO uint32_t UART_A_RXDMA_SADDRL;                   /*!< Offset 0x110 UART RXDMA Buffer Start Address Low Register */
	__IO uint32_t UART_A_RXDMA_SADDRH;                   /*!< Offset 0x114 UART RXDMA Buffer Start Address High Register */
	__IO uint32_t UART_A_RXDMA_BL;                       /*!< Offset 0x118 UART RXDMA Buffer Length Register */
	uint32_t reserved_0x11C;
	__IO uint32_t UART_A_RXDMA_IE;                       /*!< Offset 0x120 UART RXDMA Interrupt Enable Register */
	__IO uint32_t UART_A_RXDMA_IS;                       /*!< Offset 0x124 UART RXDMA Interrupt Status Register */
	__IO uint32_t UART_A_RXDMA_WADDRL;                   /*!< Offset 0x128 UART RXDMA Write Address Low Register */
	__IO uint32_t UART_A_RXDMA_WADDRH;                   /*!< Offset 0x12C UART RXDMA Write Address high Register */
	__IO uint32_t UART_A_RXDMA_RADDRL;                   /*!< Offset 0x130 UART RXDMA Read Address Low Register */
	__IO uint32_t UART_A_RXDMA_RADDRH;                   /*!< Offset 0x134 UART RXDMA Read Address high Register */
	__IO uint32_t UART_A_RXDMA_DCNT;                     /*!< Offset 0x138 UART RADMA Data Count Register */
} UART_TypeDef; /* size of structure = 0x13C */
/*
 * @brief GPIO
 */
/*!< GPIO Controller Interface */
typedef struct GPIO_Type
{
	__IO uint32_t CFG [0x004];                           /*!< Offset 0x000 Configure Register */
	__IO uint32_t DATA;                                  /*!< Offset 0x010 Data Register */
	__IO uint32_t DRV [0x004];                           /*!< Offset 0x014 Multi_Driving Register */
	__IO uint32_t PULL [0x002];                          /*!< Offset 0x024 Pull Register */
	uint32_t reserved_0x02C;
} GPIO_TypeDef; /* size of structure = 0x030 */
/*
 * @brief GPIOINT
 */
/*!< GPIOINT Controller Interface */
typedef struct GPIOINT_Type
{
	__IO uint32_t EINT_CFG [0x004];                      /*!< Offset 0x000 External Interrupt Configure Registers */
	__IO uint32_t EINT_CTL;                              /*!< Offset 0x010 External Interrupt Control Register */
	__IO uint32_t EINT_STATUS;                           /*!< Offset 0x014 External Interrupt Status Register */
	__IO uint32_t EINT_DEB;                              /*!< Offset 0x018 External Interrupt Debounce Register */
	uint32_t reserved_0x01C;
} GPIOINT_TypeDef; /* size of structure = 0x020 */
/*
 * @brief GPIOBLOCK
 */
/*!< GPIOBLOCK Controller Interface */
typedef struct GPIOBLOCK_Type
{
	GPIO_TypeDef GPIO_PINS [0x007];                      /*!< Offset 0x000 GPIO pin control */
	uint32_t reserved_0x150 [0x002C];
	GPIOINT_TypeDef GPIO_INTS [0x007];                   /*!< Offset 0x200 GPIO interrupt control */
	uint32_t reserved_0x2E0 [0x0018];
	__IO uint32_t PIO_POW_MOD_SEL;                       /*!< Offset 0x340 PIO Group Withstand Voltage Mode Select Register */
	__IO uint32_t PIO_POW_MS_CTL;                        /*!< Offset 0x344 PIO Group Withstand Voltage Mode Select Control Register */
	__IO uint32_t PIO_POW_VAL;                           /*!< Offset 0x348 PIO Group Power Value Register */
} GPIOBLOCK_TypeDef; /* size of structure = 0x34C */
/*
 * @brief SMHC
 */
/*!< SMHC Controller Interface */
typedef struct SMHC_Type
{
	__IO uint32_t SMHC_CTRL;                             /*!< Offset 0x000 Control Register */
	__IO uint32_t SMHC_CLKDIV;                           /*!< Offset 0x004 Clock Control Register */
	__IO uint32_t SMHC_TMOUT;                            /*!< Offset 0x008 Time Out Register */
	__IO uint32_t SMHC_CTYPE;                            /*!< Offset 0x00C Bus Width Register */
	__IO uint32_t SMHC_BLKSIZ;                           /*!< Offset 0x010 Block Size Register */
	__IO uint32_t SMHC_BYTCNT;                           /*!< Offset 0x014 Byte Count Register */
	__IO uint32_t SMHC_CMD;                              /*!< Offset 0x018 Command Register */
	__IO uint32_t SMHC_CMDARG;                           /*!< Offset 0x01C Command Argument Register */
	__IO uint32_t SMHC_RESP0;                            /*!< Offset 0x020 Response 0 Register */
	__IO uint32_t SMHC_RESP1;                            /*!< Offset 0x024 Response 1 Register */
	__IO uint32_t SMHC_RESP2;                            /*!< Offset 0x028 Response 2 Register */
	__IO uint32_t SMHC_RESP3;                            /*!< Offset 0x02C Response 3 Register */
	__IO uint32_t SMHC_INTMASK;                          /*!< Offset 0x030 Interrupt Mask Register */
	__IO uint32_t SMHC_MINTSTS;                          /*!< Offset 0x034 Masked Interrupt Status Register */
	__IO uint32_t SMHC_RINTSTS;                          /*!< Offset 0x038 Raw Interrupt Status Register */
	__IO uint32_t SMHC_STATUS;                           /*!< Offset 0x03C Status Register */
	__IO uint32_t SMHC_FIFOTH;                           /*!< Offset 0x040 FIFO Water Level Register */
	__IO uint32_t SMHC_FUNS;                             /*!< Offset 0x044 FIFO Function Select Register */
	__IO uint32_t SMHC_TCBCNT;                           /*!< Offset 0x048 Transferred Byte Count between Controller and Card */
	__IO uint32_t SMHC_TBBCNT;                           /*!< Offset 0x04C Transferred Byte Count between Host Memory and Internal FIFO */
	__IO uint32_t SMHC_DBGC;                             /*!< Offset 0x050 Current Debug Control Register */
	__IO uint32_t SMHC_CSDC;                             /*!< Offset 0x054 CRC Status Detect Control Registers */
	__IO uint32_t SMHC_A12A;                             /*!< Offset 0x058 Auto Command 12 Argument Register */
	__IO uint32_t SMHC_NTSR;                             /*!< Offset 0x05C SD New Timing Set Register */
	uint32_t reserved_0x060 [0x0006];
	__IO uint32_t SMHC_HWRST;                            /*!< Offset 0x078 Hardware Reset Register */
	uint32_t reserved_0x07C;
	__IO uint32_t SMHC_IDMAC;                            /*!< Offset 0x080 IDMAC Control Register */
	__IO uint32_t SMHC_DLBA;                             /*!< Offset 0x084 Descriptor List Base Address Register */
	__IO uint32_t SMHC_IDST;                             /*!< Offset 0x088 IDMAC Status Register */
	__IO uint32_t SMHC_IDIE;                             /*!< Offset 0x08C IDMAC Interrupt Enable Register */
	uint32_t reserved_0x090 [0x001C];
	__IO uint32_t SMHC_THLD;                             /*!< Offset 0x100 Card Threshold Control Register */
	__IO uint32_t SMHC_SFC;                              /*!< Offset 0x104 Sample FIFO Control Register */
	__IO uint32_t SMHC_A23A;                             /*!< Offset 0x108 Auto Command 23 Argument Register */
	__IO uint32_t EMMC_DDR_SBIT_DET;                     /*!< Offset 0x10C eMMC4.5 DDR Start Bit Detection Control Register */
	uint32_t reserved_0x110 [0x000A];
	__IO uint32_t SMHC_EXT_CMD;                          /*!< Offset 0x138 Extended Command Register */
	__IO uint32_t SMHC_EXT_RESP;                         /*!< Offset 0x13C Extended Response Register */
	__IO uint32_t SMHC_DRV_DL;                           /*!< Offset 0x140 Drive Delay Control Register */
	__IO uint32_t SMHC_SMAP_DL;                          /*!< Offset 0x144 Sample Delay Control Register */
	__IO uint32_t SMHC_DS_DL;                            /*!< Offset 0x148 Data Strobe Delay Control Register */
	__IO uint32_t SMHC_HS400_DL;                         /*!< Offset 0x14C HS400 Delay Control Register */
	uint32_t reserved_0x150 [0x002C];
	__IO uint32_t SMHC_FIFO;                             /*!< Offset 0x200 Read/Write FIFO */
} SMHC_TypeDef; /* size of structure = 0x204 */
/*
 * @brief I2S_PCM
 */
/*!< I2S_PCM Controller Interface */
typedef struct I2S_PCM_Type
{
	__IO uint32_t I2S_PCM_CTL;                           /*!< Offset 0x000 I2S/PCM Control Register */
	__IO uint32_t I2S_PCM_FMT0;                          /*!< Offset 0x004 I2S/PCM Format Register 0 */
	__IO uint32_t I2S_PCM_FMT1;                          /*!< Offset 0x008 I2S/PCM Format Register 1 */
	__IO uint32_t I2S_PCM_ISTA;                          /*!< Offset 0x00C I2S/PCM Interrupt Status Register */
	__IO uint32_t I2S_PCM_RXFIFO;                        /*!< Offset 0x010 I2S/PCM RXFIFO Register */
	__IO uint32_t I2S_PCM_FCTL;                          /*!< Offset 0x014 I2S/PCM FIFO Control Register */
	__IO uint32_t I2S_PCM_FSTA;                          /*!< Offset 0x018 I2S/PCM FIFO Status Register */
	__IO uint32_t I2S_PCM_INT;                           /*!< Offset 0x01C I2S/PCM DMA & Interrupt Control Register */
	__IO uint32_t I2S_PCM_TXFIFO;                        /*!< Offset 0x020 I2S/PCM TXFIFO Register */
	__IO uint32_t I2S_PCM_CLKD;                          /*!< Offset 0x024 I2S/PCM Clock Divide Register */
	__IO uint32_t I2S_PCM_TXCNT;                         /*!< Offset 0x028 I2S/PCM TX Sample Counter Register */
	__IO uint32_t I2S_PCM_RXCNT;                         /*!< Offset 0x02C I2S/PCM RX Sample Counter Register */
	__IO uint32_t I2S_PCM_CHCFG;                         /*!< Offset 0x030 I2S/PCM Channel Configuration Register */
	__IO uint32_t I2S_PCM_TX0CHSEL;                      /*!< Offset 0x034 I2S/PCM TX0 Channel Select Register */
	__IO uint32_t I2S_PCM_TX1CHSEL;                      /*!< Offset 0x038 I2S/PCM TX1 Channel Select Register */
	__IO uint32_t I2S_PCM_TX2CHSEL;                      /*!< Offset 0x03C I2S/PCM TX2 Channel Select Register */
	__IO uint32_t I2S_PCM_TX3CHSEL;                      /*!< Offset 0x040 I2S/PCM TX3 Channel Select Register */
	__IO uint32_t I2S_PCM_TX0CHMAP0;                     /*!< Offset 0x044 I2S/PCM TX0 Channel Mapping Register0 */
	__IO uint32_t I2S_PCM_TX0CHMAP1;                     /*!< Offset 0x048 I2S/PCM TX0 Channel Mapping Register1 */
	__IO uint32_t I2S_PCM_TX1CHMAP0;                     /*!< Offset 0x04C I2S/PCM TX1 Channel Mapping Register0 */
	__IO uint32_t I2S_PCM_TX1CHMAP1;                     /*!< Offset 0x050 I2S/PCM TX1 Channel Mapping Register1 */
	__IO uint32_t I2S_PCM_TX2CHMAP0;                     /*!< Offset 0x054 I2S/PCM TX2 Channel Mapping Register0 */
	__IO uint32_t I2S_PCM_TX2CHMAP1;                     /*!< Offset 0x058 I2S/PCM TX2 Channel Mapping Register1 */
	__IO uint32_t I2S_PCM_TX3CHMAP0;                     /*!< Offset 0x05C I2S/PCM TX3 Channel Mapping Register0 */
	__IO uint32_t I2S_PCM_TX3CHMAP1;                     /*!< Offset 0x060 I2S/PCM TX3 Channel Mapping Register1 */
	__IO uint32_t I2S_PCM_RXCHSEL;                       /*!< Offset 0x064 I2S/PCM RX Channel Select Register */
	__IO uint32_t I2S_PCM_RXCHMAP0;                      /*!< Offset 0x068 I2S/PCM RX Channel Mapping Register0 */
	__IO uint32_t I2S_PCM_RXCHMAP1;                      /*!< Offset 0x06C I2S/PCM RX Channel Mapping Register1 */
	__IO uint32_t I2S_PCM_RXCHMAP2;                      /*!< Offset 0x070 I2S/PCM RX Channel Mapping Register2 */
	__IO uint32_t I2S_PCM_RXCHMAP3;                      /*!< Offset 0x074 I2S/PCM RX Channel Mapping Register3 */
	uint32_t reserved_0x078 [0x0002];
	__IO uint32_t MCLKCFG;                               /*!< Offset 0x080 ASRC MCLK Configuration Register */
	__IO uint32_t FsoutCFG;                              /*!< Offset 0x084 ASRC Out Sample Rate Configuration Register */
	__IO uint32_t FsinEXTCFG;                            /*!< Offset 0x088 ASRC Input Sample Pulse Extend Configuration Register */
	__IO uint32_t ASRCCFG;                               /*!< Offset 0x08C ASRC Enable Register */
	__IO uint32_t ASRCMANCFG;                            /*!< Offset 0x090 ASRC Manual Ratio Configuration Register */
	__IO uint32_t ASRCRATIOSTAT;                         /*!< Offset 0x094 ASRC Status Register */
	__IO uint32_t ASRCFIFOSTAT;                          /*!< Offset 0x098 ASRC FIFO Level Status Register */
	__IO uint32_t ASRCMBISTCFG;                          /*!< Offset 0x09C ASRC MBIST Test Configuration Register */
	__IO uint32_t ASRCMBISTSTAT;                         /*!< Offset 0x0A0 ASRC MBIST Test Status Register */
} I2S_PCM_TypeDef; /* size of structure = 0x0A4 */
/*
 * @brief DMIC
 */
/*!< DMIC Controller Interface */
typedef struct DMIC_Type
{
	__IO uint32_t DMIC_EN;                               /*!< Offset 0x000 DMIC Enable Control Register */
	__IO uint32_t DMIC_SR;                               /*!< Offset 0x004 DMIC Sample Rate Register */
	__IO uint32_t DMIC_CTR;                              /*!< Offset 0x008 DMIC Control Register */
	uint32_t reserved_0x00C;
	__IO uint32_t DMIC_DATA;                             /*!< Offset 0x010 DMIC Data Register */
	__IO uint32_t DMIC_INTC;                             /*!< Offset 0x014 MIC Interrupt Control Register */
	__IO uint32_t DMIC_INTS;                             /*!< Offset 0x018 DMIC Interrupt Status Register */
	__IO uint32_t DMIC_RXFIFO_CTR;                       /*!< Offset 0x01C DMIC RXFIFO Control Register */
	__IO uint32_t DMIC_RXFIFO_STA;                       /*!< Offset 0x020 DMIC RXFIFO Status Register */
	__IO uint32_t DMIC_CH_NUM;                           /*!< Offset 0x024 DMIC Channel Numbers Register */
	__IO uint32_t DMIC_CH_MAP;                           /*!< Offset 0x028 DMIC Channel Mapping Register */
	__IO uint32_t DMIC_CNT;                              /*!< Offset 0x02C DMIC Counter Register */
	__IO uint32_t DATA0_DATA1_VOL_CTR;                   /*!< Offset 0x030 Data0 and Data1 Volume Control Register */
	__IO uint32_t DATA2_DATA3_VOL_CTR;                   /*!< Offset 0x034 Data2 And Data3 Volume Control Register */
	__IO uint32_t HPF_EN_CTR;                            /*!< Offset 0x038 High Pass Filter Enable Control Register */
	__IO uint32_t HPF_COEF_REG;                          /*!< Offset 0x03C High Pass Filter Coefficient Register */
	__IO uint32_t HPF_GAIN_REG;                          /*!< Offset 0x040 High Pass Filter Gain Register */
} DMIC_TypeDef; /* size of structure = 0x044 */
/*
 * @brief OWA
 */
/*!< OWA Controller Interface */
typedef struct OWA_Type
{
	__IO uint32_t OWA_GEN_CTL;                           /*!< Offset 0x000 OWA General Control Register */
	__IO uint32_t OWA_TX_CFIG;                           /*!< Offset 0x004 OWA TX Configuration Register */
	__IO uint32_t OWA_RX_CFIG;                           /*!< Offset 0x008 OWA RX Configuration Register */
	__IO uint32_t OWA_ISTA;                              /*!< Offset 0x00C OWA Interrupt Status Register */
	__IO uint32_t OWA_RXFIFO;                            /*!< Offset 0x010 OWA RXFIFO Register */
	__IO uint32_t OWA_FCTL;                              /*!< Offset 0x014 OWA FIFO Control Register */
	__IO uint32_t OWA_FSTA;                              /*!< Offset 0x018 OWA FIFO Status Register */
	__IO uint32_t OWA_INT;                               /*!< Offset 0x01C OWA Interrupt Control Register */
	__IO uint32_t OWA_TX_FIFO;                           /*!< Offset 0x020 OWA TX FIFO Register */
	__IO uint32_t OWA_TX_CNT;                            /*!< Offset 0x024 OWA TX Counter Register */
	__IO uint32_t OWA_RX_CNT;                            /*!< Offset 0x028 OWA RX Counter Register */
	__IO uint32_t OWA_TX_CHSTA0;                         /*!< Offset 0x02C OWA TX Channel Status Register0 */
	__IO uint32_t OWA_TX_CHSTA1;                         /*!< Offset 0x030 OWA TX Channel Status Register1 */
	__IO uint32_t OWA_RXCHSTA0;                          /*!< Offset 0x034 OWA RX Channel Status Register0 */
	__IO uint32_t OWA_RXCHSTA1;                          /*!< Offset 0x038 OWA RX Channel Status Register1 */
	uint32_t reserved_0x03C;
	__IO uint32_t OWA_EXP_CTL;                           /*!< Offset 0x040 OWA Expand Control Register */
	__IO uint32_t OWA_EXP_ISTA;                          /*!< Offset 0x044 OWA Expand Interrupt Status Register */
	__IO uint32_t OWA_EXP_INFO_0;                        /*!< Offset 0x048 OWA Expand Infomation Register0 */
	__IO uint32_t OWA_EXP_INFO_1;                        /*!< Offset 0x04C OWA Expand Infomation Register1 */
	__IO uint32_t OWA_EXP_DBG_0;                         /*!< Offset 0x050 OWA Expand Debug Register0 */
	__IO uint32_t OWA_EXP_DBG_1;                         /*!< Offset 0x054 OWA Expand Debug Register1 */
} OWA_TypeDef; /* size of structure = 0x058 */
/*
 * @brief AUDIO_CODEC
 */
/*!< AUDIO_CODEC Controller Interface */
typedef struct AUDIO_CODEC_Type
{
	__IO uint32_t AC_DAC_DPC;                            /*!< Offset 0x000 DAC Digital Part Control Register */
	__IO uint32_t DAC_VOL_CTRL;                          /*!< Offset 0x004 DAC Volume Control Register */
	uint32_t reserved_0x008 [0x0002];
	__IO uint32_t AC_DAC_FIFOC;                          /*!< Offset 0x010 DAC FIFO Control Register */
	__IO uint32_t AC_DAC_FIFOS;                          /*!< Offset 0x014 DAC FIFO Status Register */
	uint32_t reserved_0x018 [0x0002];
	__IO uint32_t AC_DAC_TXDATA;                         /*!< Offset 0x020 DAC TX DATA Register */
	__IO uint32_t AC_DAC_CNT;                            /*!< Offset 0x024 DAC TX FIFO Counter Register */
	__IO uint32_t AC_DAC_DG;                             /*!< Offset 0x028 DAC Debug Register */
	uint32_t reserved_0x02C;
	__IO uint32_t AC_ADC_FIFOC;                          /*!< Offset 0x030 ADC FIFO Control Register */
	__IO uint32_t ADC_VOL_CTRL1;                         /*!< Offset 0x034 ADC Volume Control1 Register */
	__IO uint32_t AC_ADC_FIFOS;                          /*!< Offset 0x038 ADC FIFO Status Register */
	uint32_t reserved_0x03C;
	__IO uint32_t AC_ADC_RXDATA;                         /*!< Offset 0x040 ADC RX Data Register */
	__IO uint32_t AC_ADC_CNT;                            /*!< Offset 0x044 ADC RX Counter Register */
	uint32_t reserved_0x048;
	__IO uint32_t AC_ADC_DG;                             /*!< Offset 0x04C ADC Debug Register */
	__IO uint32_t ADC_DIG_CTRL;                          /*!< Offset 0x050 ADC Digtial Control Register */
	__IO uint32_t VRA1SPEEDUP_DOWN_CTRL;                 /*!< Offset 0x054 VRA1 Speedup Down Control Register */
	uint32_t reserved_0x058 [0x0026];
	__IO uint32_t AC_DAC_DAP_CTRL;                       /*!< Offset 0x0F0 DAC DAP Control Register */
	uint32_t reserved_0x0F4;
	__IO uint32_t AC_ADC_DAP_CTR;                        /*!< Offset 0x0F8 ADC DAP Control Register */
	uint32_t reserved_0x0FC;
	__IO uint32_t AC_DAC_DRC_HHPFC;                      /*!< Offset 0x100 DAC DRC High HPF Coef Register */
	__IO uint32_t AC_DAC_DRC_LHPFC;                      /*!< Offset 0x104 DAC DRC Low HPF Coef Register */
	__IO uint32_t AC_DAC_DRC_CTRL;                       /*!< Offset 0x108 DAC DRC Control Register */
	__IO uint32_t AC_DAC_DRC_LPFHAT;                     /*!< Offset 0x10C DAC DRC Left Peak Filter High Attack Time Coef Register */
	__IO uint32_t AC_DAC_DRC_LPFLAT;                     /*!< Offset 0x110 DAC DRC Left Peak Filter Low Attack Time Coef Register */
	__IO uint32_t AC_DAC_DRC_RPFHAT;                     /*!< Offset 0x114 DAC DRC Right Peak Filter High Attack Time Coef Register */
	__IO uint32_t AC_DAC_DRC_RPFLAT;                     /*!< Offset 0x118 DAC DRC Peak Filter Low Attack Time Coef Register */
	__IO uint32_t AC_DAC_DRC_LPFHRT;                     /*!< Offset 0x11C DAC DRC Left Peak Filter High Release Time Coef Register */
	__IO uint32_t AC_DAC_DRC_LPFLRT;                     /*!< Offset 0x120 DAC DRC Left Peak Filter Low Release Time Coef Register */
	__IO uint32_t AC_DAC_DRC_RPFHRT;                     /*!< Offset 0x124 DAC DRC Right Peak filter High Release Time Coef Register */
	__IO uint32_t AC_DAC_DRC_RPFLRT;                     /*!< Offset 0x128 DAC DRC Right Peak filter Low Release Time Coef Register */
	__IO uint32_t AC_DAC_DRC_LRMSHAT;                    /*!< Offset 0x12C DAC DRC Left RMS Filter High Coef Register */
	__IO uint32_t AC_DAC_DRC_LRMSLAT;                    /*!< Offset 0x130 DAC DRC Left RMS Filter Low Coef Register */
	__IO uint32_t AC_DAC_DRC_RRMSHAT;                    /*!< Offset 0x134 DAC DRC Right RMS Filter High Coef Register */
	__IO uint32_t AC_DAC_DRC_RRMSLAT;                    /*!< Offset 0x138 DAC DRC Right RMS Filter Low Coef Register */
	__IO uint32_t AC_DAC_DRC_HCT;                        /*!< Offset 0x13C DAC DRC Compressor Threshold High Setting Register */
	__IO uint32_t AC_DAC_DRC_LCT;                        /*!< Offset 0x140 DAC DRC Compressor Slope High Setting Register */
	__IO uint32_t AC_DAC_DRC_HKC;                        /*!< Offset 0x144 DAC DRC Compressor Slope High Setting Register */
	__IO uint32_t AC_DAC_DRC_LKC;                        /*!< Offset 0x148 DAC DRC Compressor Slope Low Setting Register */
	__IO uint32_t AC_DAC_DRC_HOPC;                       /*!< Offset 0x14C DAC DRC Compresso */
	__IO uint32_t AC_DAC_DRC_LOPC;                       /*!< Offset 0x150 DAC DRC Compressor Low Output at Compressor Threshold Register */
	__IO uint32_t AC_DAC_DRC_HLT;                        /*!< Offset 0x154 DAC DRC Limiter Threshold High Setting Register */
	__IO uint32_t AC_DAC_DRC_LLT;                        /*!< Offset 0x158 DAC DRC Limiter Threshold Low Setting Register */
	__IO uint32_t AC_DAC_DRC_HKl;                        /*!< Offset 0x15C DAC DRC Limiter Slope High Setting Register */
	__IO uint32_t AC_DAC_DRC_LKl;                        /*!< Offset 0x160 DAC DRC Limiter Slope Low Setting Register */
	__IO uint32_t AC_DAC_DRC_HOPL;                       /*!< Offset 0x164 DAC DRC Limiter High Output at Limiter Threshold */
	__IO uint32_t AC_DAC_DRC_LOPL;                       /*!< Offset 0x168 DAC DRC Limiter Low Output at Limiter Threshold */
	__IO uint32_t AC_DAC_DRC_HET;                        /*!< Offset 0x16C DAC DRC Expander Threshold High Setting Register */
	__IO uint32_t AC_DAC_DRC_LET;                        /*!< Offset 0x170 DAC DRC Expander Threshold Low Setting Register */
	__IO uint32_t AC_DAC_DRC_HKE;                        /*!< Offset 0x174 DAC DRC Expander Slope High Setting Register */
	__IO uint32_t AC_DAC_DRC_LKE;                        /*!< Offset 0x178 DAC DRC Expander Slope Low Setting Register */
	__IO uint32_t AC_DAC_DRC_HOPE;                       /*!< Offset 0x17C DAC DRC Expander High Output at Expander Threshold */
	__IO uint32_t AC_DAC_DRC_LOPE;                       /*!< Offset 0x180 DAC DRC Expander Low Output at Expander Threshold */
	__IO uint32_t AC_DAC_DRC_HKN;                        /*!< Offset 0x184 DAC DRC Linear Slope High Setting Register */
	__IO uint32_t AC_DAC_DRC_LKN;                        /*!< Offset 0x188 DAC DRC Linear Slope Low Setting Register */
	__IO uint32_t AC_DAC_DRC_SFHAT;                      /*!< Offset 0x18C DAC DRC Smooth filter Gain High Attack Time Coef Register */
	__IO uint32_t AC_DAC_DRC_SFLAT;                      /*!< Offset 0x190 DAC DRC Smooth filter Gain Low Attack Time Coef Register */
	__IO uint32_t AC_DAC_DRC_SFHRT;                      /*!< Offset 0x194 DAC DRC Smooth filter Gain High Release Time Coef Register */
	__IO uint32_t AC_DAC_DRC_SFLRT;                      /*!< Offset 0x198 DAC DRC Smooth filter Gain Low Release Time Coef Register */
	__IO uint32_t AC_DAC_DRC_MXGHS;                      /*!< Offset 0x19C DAC DRC MAX Gain High Setting Register */
	__IO uint32_t AC_DAC_DRC_MXGLS;                      /*!< Offset 0x1A0 DAC DRC MAX Gain Low Setting Register */
	__IO uint32_t AC_DAC_DRC_MNGHS;                      /*!< Offset 0x1A4 DAC DRC MIN Gain High Setting Register */
	__IO uint32_t AC_DAC_DRC_MNGLS;                      /*!< Offset 0x1A8 DAC DRC MIN Gain Low Setting Register */
	__IO uint32_t AC_DAC_DRC_EPSHC;                      /*!< Offset 0x1AC DAC DRC Expander Smooth Time High Coef Register */
	__IO uint32_t AC_DAC_DRC_EPSLC;                      /*!< Offset 0x1B0 DAC DRC Expander Smooth Time Low Coef Register */
	uint32_t reserved_0x1B4;
	__IO uint32_t AC_DAC_DRC_HPFHGAIN;                   /*!< Offset 0x1B8 DAC DRC HPF Gain High Coef Register */
	__IO uint32_t AC_DAC_DRC_HPFLGAIN;                   /*!< Offset 0x1BC DAC DRC HPF Gain Low Coef Register */
	uint32_t reserved_0x1C0 [0x0010];
	__IO uint32_t AC_ADC_DRC_HHPFC;                      /*!< Offset 0x200 ADC DRC High HPF Coef Register */
	__IO uint32_t AC_ADC_DRC_LHPFC;                      /*!< Offset 0x204 ADC DRC Low HPF Coef Register */
	__IO uint32_t AC_ADC_DRC_CTRL;                       /*!< Offset 0x208 ADC DRC Control Register */
	__IO uint32_t AC_ADC_DRC_LPFHAT;                     /*!< Offset 0x20C ADC DRC Left Peak Filter High Attack Time Coef Register */
	__IO uint32_t AC_ADC_DRC_LPFLAT;                     /*!< Offset 0x210 ADC DRC Left Peak Filter Low Attack Time Coef Register */
	__IO uint32_t AC_ADC_DRC_RPFHAT;                     /*!< Offset 0x214 ADC DRC Right Peak Filter High Attack Time Coef Register */
	__IO uint32_t AC_ADC_DRC_RPFLAT;                     /*!< Offset 0x218 ADC DRC Right Peak Filter Low Attack Time Coef Register */
	__IO uint32_t AC_ADC_DRC_LPFHRT;                     /*!< Offset 0x21C ADC DRC Left Peak Filter High Release Time Coef Register */
	__IO uint32_t AC_ADC_DRC_LPFLRT;                     /*!< Offset 0x220 ADC DRC Left Peak Filter Low Release Time Coef Register */
	__IO uint32_t AC_ADC_DRC_RPFHRT;                     /*!< Offset 0x224 ADC DRC Right Peak Filter High Release Time Coef Register */
	__IO uint32_t AC_ADC_DRC_RPFLRT;                     /*!< Offset 0x228 ADC DRC Right Peak Filter Low Release Time Coef Register */
	__IO uint32_t AC_ADC_DRC_LRMSHAT;                    /*!< Offset 0x22C ADC DRC Left RMS Filter High Coef Register */
	__IO uint32_t AC_ADC_DRC_LRMSLAT;                    /*!< Offset 0x230 ADC DRC Left RMS Filter Low Coef Register */
	__IO uint32_t AC_ADC_DRC_RRMSHAT;                    /*!< Offset 0x234 ADC DRC Right RMS Filter High Coef Register */
	__IO uint32_t AC_ADC_DRC_RRMSLAT;                    /*!< Offset 0x238 ADC DRC Right RMS Filter Low Coef Register */
	__IO uint32_t AC_ADC_DRC_HCT;                        /*!< Offset 0x23C ADC DRC Compressor Threshold High Setting Register */
	__IO uint32_t AC_ADC_DRC_LCT;                        /*!< Offset 0x240 ADC DRC Compressor Slope High Setting Register */
	__IO uint32_t AC_ADC_DRC_HKC;                        /*!< Offset 0x244 ADC DRC Compressor Slope High Setting Register */
	__IO uint32_t AC_ADC_DRC_LKC;                        /*!< Offset 0x248 ADC DRC Compressor Slope Low Setting Register */
	__IO uint32_t AC_ADC_DRC_HOPC;                       /*!< Offset 0x24C ADC DRC Compressor High Output at Compressor Threshold Register */
	__IO uint32_t AC_ADC_DRC_LOPC;                       /*!< Offset 0x250 ADC DRC Compressor Low Output at Compressor Threshold Register */
	__IO uint32_t AC_ADC_DRC_HLT;                        /*!< Offset 0x254 ADC DRC Limiter Threshold High Setting Register */
	__IO uint32_t AC_ADC_DRC_LLT;                        /*!< Offset 0x258 ADC DRC Limiter Threshold Low Setting Register */
	__IO uint32_t AC_ADC_DRC_HKl;                        /*!< Offset 0x25C ADC DRC Limiter Slope High Setting Register */
	__IO uint32_t AC_ADC_DRC_LKl;                        /*!< Offset 0x260 ADC DRC Limiter Slope Low Setting Register */
	__IO uint32_t AC_ADC_DRC_HOPL;                       /*!< Offset 0x264 ADC DRC Limiter High Output at Limiter Threshold */
	__IO uint32_t AC_ADC_DRC_LOPL;                       /*!< Offset 0x268 ADC DRC Limiter Low Output at Limiter Threshold */
	__IO uint32_t AC_ADC_DRC_HET;                        /*!< Offset 0x26C ADC DRC Expander Threshold High Setting Register */
	__IO uint32_t AC_ADC_DRC_LET;                        /*!< Offset 0x270 ADC DRC Expander Threshold Low Setting Register */
	__IO uint32_t AC_ADC_DRC_HKE;                        /*!< Offset 0x274 ADC DRC Expander Slope High Setting Register */
	__IO uint32_t AC_ADC_DRC_LKE;                        /*!< Offset 0x278 ADC DRC Expander Slope Low Setting Register */
	__IO uint32_t AC_ADC_DRC_HOPE;                       /*!< Offset 0x27C ADC DRC Expander High Output at Expander Threshold */
	__IO uint32_t AC_ADC_DRC_LOPE;                       /*!< Offset 0x280 ADC DRC Expander Low Output at Expander Threshold */
	__IO uint32_t AC_ADC_DRC_HKN;                        /*!< Offset 0x284 ADC DRC Linear Slope High Setting Register */
	__IO uint32_t AC_ADC_DRC_LKN;                        /*!< Offset 0x288 ADC DRC Linear Slope Low Setting Register */
	__IO uint32_t AC_ADC_DRC_SFHAT;                      /*!< Offset 0x28C ADC DRC Smooth filter Gain High Attack Time Coef Register */
	__IO uint32_t AC_ADC_DRC_SFLAT;                      /*!< Offset 0x290 ADC DRC Smooth filter Gain Low Attack Time Coef Register */
	__IO uint32_t AC_ADC_DRC_SFHRT;                      /*!< Offset 0x294 ADC DRC Smooth filter Gain High Release Time Coef Register */
	__IO uint32_t AC_ADC_DRC_SFLRT;                      /*!< Offset 0x298 ADC DRC Smooth filter Gain Low Release Time Coef Register */
	__IO uint32_t AC_ADC_DRC_MXGHS;                      /*!< Offset 0x29C ADC DRC MAX Gain High Setting Register */
	__IO uint32_t AC_ADC_DRC_MXGLS;                      /*!< Offset 0x2A0 ADC DRC MAX Gain Low Setting Register */
	__IO uint32_t AC_ADC_DRC_MNGHS;                      /*!< Offset 0x2A4 ADC DRC MIN Gain High Setting Register */
	__IO uint32_t AC_ADC_DRC_MNGLS;                      /*!< Offset 0x2A8 ADC DRC MIN Gain Low Setting Register */
	__IO uint32_t AC_ADC_DRC_EPSHC;                      /*!< Offset 0x2AC ADC DRC Expander Smooth Time High Coef Register */
	__IO uint32_t AC_ADC_DRC_EPSLC;                      /*!< Offset 0x2B0 ADC DRC Expander Smooth Time Low Coef Register */
	uint32_t reserved_0x2B4;
	__IO uint32_t AC_ADC_DRC_HPFHGAIN;                   /*!< Offset 0x2B8 ADC DRC HPF Gain High Coef Register */
	__IO uint32_t AC_ADC_DRC_HPFLGAIN;                   /*!< Offset 0x2BC ADC DRC HPF Gain Low Coef Register */
	uint32_t reserved_0x2C0 [0x0010];
	__IO uint32_t ADC1_REG;                              /*!< Offset 0x300 ADC1 Analog Control Register */
	__IO uint32_t ADC2_REG;                              /*!< Offset 0x304 ADC2 Analog Control Register */
	__IO uint32_t ADC3_REG;                              /*!< Offset 0x308 ADC3 Analog Control Register */
	uint32_t reserved_0x30C;
	__IO uint32_t DAC_REG;                               /*!< Offset 0x310 DAC Analog Control Register */
	uint32_t reserved_0x314;
	__IO uint32_t MICBIAS_REG;                           /*!< Offset 0x318 MICBIAS Analog Control Register */
	__IO uint32_t RAMP_REG;                              /*!< Offset 0x31C BIAS Analog Control Register */
	__IO uint32_t BIAS_REG;                              /*!< Offset 0x320 BIAS Analog Control Register */
	uint32_t reserved_0x324 [0x0003];
	__IO uint32_t ADC5_REG;                              /*!< Offset 0x330 ADC5 Analog Control Register */
} AUDIO_CODEC_TypeDef; /* size of structure = 0x334 */
/*
 * @brief TWI
 */
/*!< TWI Controller Interface */
typedef struct TWI_Type
{
	__IO uint32_t TWI_ADDR;                              /*!< Offset 0x000 TWI Slave Address Register */
	__IO uint32_t TWI_XADDR;                             /*!< Offset 0x004 TWI Extended Slave Address Register */
	__IO uint32_t TWI_DATA;                              /*!< Offset 0x008 TWI Data Byte Register */
	__IO uint32_t TWI_CNTR;                              /*!< Offset 0x00C TWI Control Register */
	__IO uint32_t TWI_STAT;                              /*!< Offset 0x010 TWI Status Register */
	__IO uint32_t TWI_CCR;                               /*!< Offset 0x014 TWI Clock Control Register */
	__IO uint32_t TWI_SRST;                              /*!< Offset 0x018 TWI Software Reset Register */
	__IO uint32_t TWI_EFR;                               /*!< Offset 0x01C TWI Enhance Feature Register */
	__IO uint32_t TWI_LCR;                               /*!< Offset 0x020 TWI Line Control Register */
	uint32_t reserved_0x024 [0x0077];
	__IO uint32_t TWI_DRV_CTRL;                          /*!< Offset 0x200 TWI_DRV Control Register */
	__IO uint32_t TWI_DRV_CFG;                           /*!< Offset 0x204 TWI_DRV Transmission Configuration Register */
	__IO uint32_t TWI_DRV_SLV;                           /*!< Offset 0x208 TWI_DRV Slave ID Register */
	__IO uint32_t TWI_DRV_FMT;                           /*!< Offset 0x20C TWI_DRV Packet Format Register */
	__IO uint32_t TWI_DRV_BUS_CTRL;                      /*!< Offset 0x210 TWI_DRV Bus Control Register */
	__IO uint32_t TWI_DRV_INT_CTRL;                      /*!< Offset 0x214 TWI_DRV Interrupt Control Register */
	__IO uint32_t TWI_DRV_DMA_CFG;                       /*!< Offset 0x218 TWI_DRV DMA Configure Register */
	__IO uint32_t TWI_DRV_FIFO_CON;                      /*!< Offset 0x21C TWI_DRV FIFO Content Register */
	uint32_t reserved_0x220 [0x0038];
	__IO uint32_t TWI_DRV_SEND_FIFO_ACC;                 /*!< Offset 0x300 TWI_DRV Send Data FIFO Access Register */
	__IO uint32_t TWI_DRV_RECV_FIFO_ACC;                 /*!< Offset 0x304 TWI_DRV Receive Data FIFO Access Register */
} TWI_TypeDef; /* size of structure = 0x308 */
/*
 * @brief SPI
 */
/*!< SPI Controller Interface */
typedef struct SPI_Type
{
	uint32_t reserved_0x000;
	__IO uint32_t SPI_GCR;                               /*!< Offset 0x004 SPI Global Control Register */
	__IO uint32_t SPI_TCR;                               /*!< Offset 0x008 SPI Transfer Control Register */
	uint32_t reserved_0x00C;
	__IO uint32_t SPI_IER;                               /*!< Offset 0x010 SPI Interrupt Control Register */
	__IO uint32_t SPI_ISR;                               /*!< Offset 0x014 SPI Interrupt Status Register */
	__IO uint32_t SPI_FCR;                               /*!< Offset 0x018 SPI FIFO Control Register */
	__IO uint32_t SPI_FSR;                               /*!< Offset 0x01C SPI FIFO Status Register */
	__IO uint32_t SPI_WCR;                               /*!< Offset 0x020 SPI Wait Clock Register */
	uint32_t reserved_0x024;
	__IO uint32_t SPI_SAMP_DL;                           /*!< Offset 0x028 SPI Sample Delay Control Register */
	uint32_t reserved_0x02C;
	__IO uint32_t SPI_MBC;                               /*!< Offset 0x030 SPI Master Burst Counter Register */
	__IO uint32_t SPI_MTC;                               /*!< Offset 0x034 SPI Master Transmit Counter Register */
	__IO uint32_t SPI_BCC;                               /*!< Offset 0x038 SPI Master Burst Control Register */
	uint32_t reserved_0x03C;
	__IO uint32_t SPI_BATCR;                             /*!< Offset 0x040 SPI Bit-Aligned Transfer Configure Register */
	__IO uint32_t SPI_BA_CCR;                            /*!< Offset 0x044 SPI Bit-Aligned Clock Configuration Register */
	__IO uint32_t SPI_TBR;                               /*!< Offset 0x048 SPI TX Bit Register */
	__IO uint32_t SPI_RBR;                               /*!< Offset 0x04C SPI RX Bit Register */
	uint32_t reserved_0x050 [0x000E];
	__IO uint32_t SPI_NDMA_MODE_CTL;                     /*!< Offset 0x088 SPI Normal DMA Mode Control Register */
	uint32_t reserved_0x08C [0x005D];
	__IO uint32_t SPI_TXD;                               /*!< Offset 0x200 SPI TX Data Register */
	uint32_t reserved_0x204 [0x003F];
	__IO uint32_t SPI_RXD;                               /*!< Offset 0x300 SPI RX Data Register */
} SPI_TypeDef; /* size of structure = 0x304 */
/*
 * @brief CIR_RX
 */
/*!< CIR_RX Controller Interface */
typedef struct CIR_RX_Type
{
	__IO uint32_t CIR_CTL;                               /*!< Offset 0x000 CIR Control Register */
	uint32_t reserved_0x004 [0x0003];
	__IO uint32_t CIR_RXPCFG;                            /*!< Offset 0x010 CIR Receiver Pulse Configure Register */
	uint32_t reserved_0x014 [0x0003];
	__IO uint32_t CIR_RXFIFO;                            /*!< Offset 0x020 CIR Receiver FIFO Register */
	uint32_t reserved_0x024 [0x0002];
	__IO uint32_t CIR_RXINT;                             /*!< Offset 0x02C CIR Receiver Interrupt Control Register */
	__IO uint32_t CIR_RXSTA;                             /*!< Offset 0x030 CIR Receiver Status Register */
	__IO uint32_t CIR_RXCFG;                             /*!< Offset 0x034 CIR Receiver Configure Register */
} CIR_RX_TypeDef; /* size of structure = 0x038 */
/*
 * @brief CIR_TX
 */
/*!< CIR_TX Controller Interface */
typedef struct CIR_TX_Type
{
	__IO uint32_t CIR_TGLR;                              /*!< Offset 0x000 CIR Transmit Global Register */
	__IO uint32_t CIR_TMCR;                              /*!< Offset 0x004 CIR Transmit Modulation Control Register */
	__IO uint32_t CIR_TCR;                               /*!< Offset 0x008 CIR Transmit Control Register */
	__IO uint32_t CIR_IDC_H;                             /*!< Offset 0x00C CIR Transmit Idle Duration Threshold High Bit Register */
	__IO uint32_t CIR_IDC_L;                             /*!< Offset 0x010 CIR Transmit Idle Duration Threshold Low Bit Register */
	__IO uint32_t CIR_TICR_H;                            /*!< Offset 0x014 CIR Transmit Idle Counter High Bit Register */
	__IO uint32_t CIR_TICR_L;                            /*!< Offset 0x018 CIR Transmit Idle Counter Low Bit Register */
	uint32_t reserved_0x01C;
	__IO uint32_t CIR_TEL;                               /*!< Offset 0x020 CIR TX FIFO Empty Level Register */
	__IO uint32_t CIR_TXINT;                             /*!< Offset 0x024 CIR Transmit Interrupt Control Register */
	__IO uint32_t CIR_TAC;                               /*!< Offset 0x028 CIR Transmit FIFO Available Counter Register */
	__IO uint32_t CIR_TXSTA;                             /*!< Offset 0x02C CIR Transmit Status Register */
	__IO uint32_t CIR_TXT;                               /*!< Offset 0x030 CIR Transmit Threshold Register */
	__IO uint32_t CIR_DMA;                               /*!< Offset 0x034 CIR DMA Control Register */
	uint32_t reserved_0x038 [0x0012];
	__IO uint32_t CIR_TXFIFO;                            /*!< Offset 0x080 CIR Transmit FIFO Data Register */
} CIR_TX_TypeDef; /* size of structure = 0x084 */
/*
 * @brief LEDC
 */
/*!< LEDC Controller Interface */
typedef struct LEDC_Type
{
	__IO uint32_t LEDC_CTRL_REG;                         /*!< Offset 0x000 LEDC Control Register */
	__IO uint32_t LED_T01_TIMING_CTRL_REG;               /*!< Offset 0x004 LEDC T0 & T1 Timing Control Register */
	__IO uint32_t LEDC_DATA_FINISH_CNT_REG;              /*!< Offset 0x008 LEDC Data Finish Counter Register */
	__IO uint32_t LED_RESET_TIMING_CTRL_REG;             /*!< Offset 0x00C LEDC Reset Timing Control Register */
	__IO uint32_t LEDC_WAIT_TIME0_CTRL_REG;              /*!< Offset 0x010 LEDC Wait Time0 Control Register */
	__IO uint32_t LEDC_DATA_REG;                         /*!< Offset 0x014 LEDC Data Register */
	__IO uint32_t LEDC_DMA_CTRL_REG;                     /*!< Offset 0x018 LEDC DMA Control Register */
	__IO uint32_t LEDC_INT_CTRL_REG;                     /*!< Offset 0x01C LEDC Interrupt Control Register */
	__IO uint32_t LEDC_INT_STS_REG;                      /*!< Offset 0x020 LEDC Interrupt Status Register */
	uint32_t reserved_0x024;
	__IO uint32_t LEDC_WAIT_TIME1_CTRL_REG;              /*!< Offset 0x028 LEDC Wait Time1 Control Register */
	uint32_t reserved_0x02C;
	__IO uint32_t LEDC_FIFO_DATA_REG [0x020];            /*!< Offset 0x030 LEDC FIFO Data Registers array */
} LEDC_TypeDef; /* size of structure = 0x0B0 */
/*
 * @brief TPADC
 */
/*!< TPADC Controller Interface */
typedef struct TPADC_Type
{
	__IO uint32_t TP_CTRL_REG0;                          /*!< Offset 0x000 TP Control Register 0 */
	__IO uint32_t TP_CTRL_REG1;                          /*!< Offset 0x004 TP Control Register 1 */
	__IO uint32_t TP_CTRL_REG2;                          /*!< Offset 0x008 TP Control Register 2 */
	__IO uint32_t TP_CTRL_REG3;                          /*!< Offset 0x00C TP Control Register 3 */
	__IO uint32_t TP_INT_FIFO_CTRL_REG;                  /*!< Offset 0x010 TP Interrupt FIFO Control Register */
	__IO uint32_t TP_INT_FIFO_STAT_REG;                  /*!< Offset 0x014 TP Interrupt FIFO Status Register */
	uint32_t reserved_0x018;
	__IO uint32_t TP_CALI_DATA_REG;                      /*!< Offset 0x01C TP Calibration Data Register */
	uint32_t reserved_0x020;
	__IO uint32_t TP_DATA_REG;                           /*!< Offset 0x024 TP Data Register */
} TPADC_TypeDef; /* size of structure = 0x028 */
/*
 * @brief GPADC
 */
/*!< GPADC Controller Interface */
typedef struct GPADC_Type
{
	__IO uint32_t GP_SR_CON;                             /*!< Offset 0x000 GPADC Sample Rate Configure Register */
	__IO uint32_t GP_CTRL;                               /*!< Offset 0x004 GPADC Control Register */
	__IO uint32_t GP_CS_EN;                              /*!< Offset 0x008 GPADC Compare and Select Enable Register */
	__IO uint32_t GP_FIFO_INTC;                          /*!< Offset 0x00C GPADC FIFO Interrupt Control Register */
	__IO uint32_t GP_FIFO_INTS;                          /*!< Offset 0x010 GPADC FIFO Interrupt Status Register */
	__IO uint32_t GP_FIFO_DATA;                          /*!< Offset 0x014 GPADC FIFO Data Register */
	__IO uint32_t GP_CDATA;                              /*!< Offset 0x018 GPADC Calibration Data Register */
	uint32_t reserved_0x01C;
	__IO uint32_t GP_DATAL_INTC;                         /*!< Offset 0x020 GPADC Data Low Interrupt Configure Register */
	__IO uint32_t GP_DATAH_INTC;                         /*!< Offset 0x024 GPADC Data High Interrupt Configure Register */
	__IO uint32_t GP_DATA_INTC;                          /*!< Offset 0x028 GPADC Data Interrupt Configure Register */
	uint32_t reserved_0x02C;
	__IO uint32_t GP_DATAL_INTS;                         /*!< Offset 0x030 GPADC Data Low Interrupt Status Register */
	__IO uint32_t GP_DATAH_INTS;                         /*!< Offset 0x034 GPADC Data High Interrupt Status Register */
	__IO uint32_t GP_DATA_INTS;                          /*!< Offset 0x038 GPADC Data Interrupt Status Register */
	uint32_t reserved_0x03C;
	__IO uint32_t GP_CH0_CMP_DATA;                       /*!< Offset 0x040 GPADC CH0 Compare Data Register */
	uint32_t reserved_0x044 [0x000F];
	__IO uint32_t GP_CH0_DATA;                           /*!< Offset 0x080 GPADC CH0 Data Register */
} GPADC_TypeDef; /* size of structure = 0x084 */
/*
 * @brief SPI_DBI
 */
/*!< SPI_DBI Controller Interface */
typedef struct SPI_DBI_Type
{
	uint32_t reserved_0x000;
	__IO uint32_t SPI_GCR;                               /*!< Offset 0x004 SPI Global Control Register */
	__IO uint32_t SPI_TCR;                               /*!< Offset 0x008 SPI Transfer Control Register */
	uint32_t reserved_0x00C;
	__IO uint32_t SPI_IER;                               /*!< Offset 0x010 SPI Interrupt Control Register */
	__IO uint32_t SPI_ISR;                               /*!< Offset 0x014 SPI Interrupt Status Register */
	__IO uint32_t SPI_FCR;                               /*!< Offset 0x018 SPI FIFO Control Register */
	__IO uint32_t SPI_FSR;                               /*!< Offset 0x01C SPI FIFO Status Register */
	__IO uint32_t SPI_WCR;                               /*!< Offset 0x020 SPI Wait Clock Register */
	uint32_t reserved_0x024;
	__IO uint32_t SPI_SAMP_DL;                           /*!< Offset 0x028 SPI Sample Delay Control Register */
	uint32_t reserved_0x02C;
	__IO uint32_t SPI_MBC;                               /*!< Offset 0x030 SPI Master Burst Counter Register */
	__IO uint32_t SPI_MTC;                               /*!< Offset 0x034 SPI Master Transmit Counter Register */
	__IO uint32_t SPI_BCC;                               /*!< Offset 0x038 SPI Master Burst Control Register */
	uint32_t reserved_0x03C;
	__IO uint32_t SPI_BATCR;                             /*!< Offset 0x040 SPI Bit-Aligned Transfer Configure Register */
	__IO uint32_t SPI_BA_CCR;                            /*!< Offset 0x044 SPI Bit-Aligned Clock Configuration Register */
	__IO uint32_t SPI_TBR;                               /*!< Offset 0x048 SPI TX Bit Register */
	__IO uint32_t SPI_RBR;                               /*!< Offset 0x04C SPI RX Bit Register */
	uint32_t reserved_0x050 [0x000E];
	__IO uint32_t SPI_NDMA_MODE_CTL;                     /*!< Offset 0x088 SPI Normal DMA Mode Control Register */
	uint32_t reserved_0x08C [0x001D];
	__IO uint32_t DBI_CTL_0;                             /*!< Offset 0x100 DBI Control Register 0 */
	__IO uint32_t DBI_CTL_1;                             /*!< Offset 0x104 DBI Control Register 1 */
	__IO uint32_t DBI_CTL_2;                             /*!< Offset 0x108 DBI Control Register 2 */
	__IO uint32_t DBI_TIMER;                             /*!< Offset 0x10C DBI Timer Control Register */
	__IO uint32_t DBI_VIDEO_SZIE;                        /*!< Offset 0x110 DBI Video Size Configuration Register */
	uint32_t reserved_0x114 [0x0003];
	__IO uint32_t DBI_INT;                               /*!< Offset 0x120 DBI Interrupt Register */
	__IO uint32_t DBI_DEBUG_0;                           /*!< Offset 0x124 DBI BEBUG 0 Register */
	__IO uint32_t DBI_DEBUG_1;                           /*!< Offset 0x128 DBI BEBUG 1 Register */
	uint32_t reserved_0x12C [0x0035];
	__IO uint32_t SPI_TXD;                               /*!< Offset 0x200 SPI TX Data register */
	uint32_t reserved_0x204 [0x003F];
	__IO uint32_t SPI_RXD;                               /*!< Offset 0x300 SPI RX Data register */
} SPI_DBI_TypeDef; /* size of structure = 0x304 */
/*
 * @brief CE
 */
/*!< CE Controller Interface */
typedef struct CE_Type
{
	__IO uint32_t CE_TDA;                                /*!< Offset 0x000 Task Descriptor Address */
	uint32_t reserved_0x004;
	__IO uint32_t CE_ICR;                                /*!< Offset 0x008 Interrupt Control Register */
	__IO uint32_t CE_ISR;                                /*!< Offset 0x00C Interrupt Status Register */
	__IO uint32_t CE_TLR;                                /*!< Offset 0x010 Task Load Register */
	__IO uint32_t CE_TSR;                                /*!< Offset 0x014 Task Status Register */
	__IO uint32_t CE_ESR;                                /*!< Offset 0x018 Error Status Register */
	uint32_t reserved_0x01C [0x0002];
	__IO uint32_t CE_CSA;                                /*!< Offset 0x024 DMA Current Source Address */
	__IO uint32_t CE_CDA;                                /*!< Offset 0x028 DMA Current Destination Address */
	__IO uint32_t CE_TPR;                                /*!< Offset 0x02C Throughput Register */
} CE_TypeDef; /* size of structure = 0x030 */
/*
 * @brief RTC
 */
/*!< RTC Controller Interface */
typedef struct RTC_Type
{
	__IO uint32_t LOSC_CTRL_REG;                         /*!< Offset 0x000 Low Oscillator Control Register */
	__IO uint32_t LOSC_AUTO_SWT_STA_REG;                 /*!< Offset 0x004 Low Oscillator Auto Switch Status Register */
	__IO uint32_t INTOSC_CLK_PRESCAL_REG;                /*!< Offset 0x008 Internal OSC Clock Pre-scaler Register */
	uint32_t reserved_0x00C;
	__IO uint32_t RTC_DAY_REG;                           /*!< Offset 0x010 RTC Year-Month-Day Register */
	__IO uint32_t RTC_HH_MM_SS_REG;                      /*!< Offset 0x014 RTC Hour-Minute-Second Register */
	uint32_t reserved_0x018 [0x0002];
	__IO uint32_t ALARM0_DAY_SET_REG;                    /*!< Offset 0x020 Alarm 0 Day Setting Register */
	__IO uint32_t ALARM0_CUR_VLU_REG;                    /*!< Offset 0x024 Alarm 0 Counter Current Value Register */
	__IO uint32_t ALARM0_ENABLE_REG;                     /*!< Offset 0x028 Alarm 0 Enable Register */
	__IO uint32_t ALARM0_IRQ_EN;                         /*!< Offset 0x02C Alarm 0 IRQ Enable Register */
	__IO uint32_t ALARM0_IRQ_STA_REG;                    /*!< Offset 0x030 Alarm 0 IRQ Status Register */
	uint32_t reserved_0x034 [0x0007];
	__IO uint32_t ALARM_CONFIG_REG;                      /*!< Offset 0x050 Alarm Configuration Register */
	uint32_t reserved_0x054 [0x0003];
	__IO uint32_t F32K_FOUT_CTRL_GATING_REG;             /*!< Offset 0x060 32K Fanout Control Gating Register */
	uint32_t reserved_0x064 [0x0027];
	__IO uint32_t GP_DATA_REG [0x008];                   /*!< Offset 0x100 General Purpose Register (N=0 to 7) */
	__IO uint32_t FBOOT_INFO_REG0;                       /*!< Offset 0x120 Fast Boot Information Register0 */
	__IO uint32_t FBOOT_INFO_REG1;                       /*!< Offset 0x124 Fast Boot Information Register1 */
	uint32_t reserved_0x128 [0x000E];
	__IO uint32_t DCXO_CTRL_REG;                         /*!< Offset 0x160 DCXO Control Register */
	uint32_t reserved_0x164 [0x000B];
	__IO uint32_t RTC_VIO_REG;                           /*!< Offset 0x190 RTC_VIO Regulation Register */
	uint32_t reserved_0x194 [0x0017];
	__IO uint32_t IC_CHARA_REG;                          /*!< Offset 0x1F0 IC Characteristic Register */
	__IO uint32_t VDD_OFF_GATING_CTRL_REG;               /*!< Offset 0x1F4 VDD Off Gating Control Register */
	uint32_t reserved_0x1F8 [0x0003];
	__IO uint32_t EFUSE_HV_PWRSWT_CTRL_REG;              /*!< Offset 0x204 Efuse High Voltage Power Switch Control Register */
	uint32_t reserved_0x208 [0x0042];
	__IO uint32_t RTC_SPI_CLK_CTRL_REG;                  /*!< Offset 0x310 RTC SPI Clock Control Register */
} RTC_TypeDef; /* size of structure = 0x314 */
/*
 * @brief IOMMU
 */
/*!< IOMMU Controller Interface */
typedef struct IOMMU_Type
{
	uint32_t reserved_0x000 [0x0004];
	__IO uint32_t IOMMU_RESET_REG;                       /*!< Offset 0x010 IOMMU Reset Register */
	uint32_t reserved_0x014 [0x0003];
	__IO uint32_t IOMMU_ENABLE_REG;                      /*!< Offset 0x020 IOMMU Enable Register */
	uint32_t reserved_0x024 [0x0003];
	__IO uint32_t IOMMU_BYPASS_REG;                      /*!< Offset 0x030 IOMMU Bypass Register */
	uint32_t reserved_0x034 [0x0003];
	__IO uint32_t IOMMU_AUTO_GATING_REG;                 /*!< Offset 0x040 IOMMU Auto Gating Register */
	__IO uint32_t IOMMU_WBUF_CTRL_REG;                   /*!< Offset 0x044 IOMMU Write Buffer Control Register */
	__IO uint32_t IOMMU_OOO_CTRL_REG;                    /*!< Offset 0x048 IOMMU Out of Order Control Register */
	__IO uint32_t IOMMU_4KB_BDY_PRT_CTRL_REG;            /*!< Offset 0x04C IOMMU 4KB Boundary Protect Control Register */
	__IO uint32_t IOMMU_TTB_REG;                         /*!< Offset 0x050 IOMMU Translation Table Base Register */
	uint32_t reserved_0x054 [0x0003];
	__IO uint32_t IOMMU_TLB_ENABLE_REG;                  /*!< Offset 0x060 IOMMU TLB Enable Register */
	uint32_t reserved_0x064 [0x0003];
	__IO uint32_t IOMMU_TLB_PREFETCH_REG;                /*!< Offset 0x070 IOMMU TLB Prefetch Register */
	uint32_t reserved_0x074 [0x0003];
	__IO uint32_t IOMMU_TLB_FLUSH_ENABLE_REG;            /*!< Offset 0x080 IOMMU TLB Flush Enable Register */
	__IO uint32_t IOMMU_TLB_IVLD_MODE_SEL_REG;           /*!< Offset 0x084 IOMMU TLB Invalidation Mode Select Register */
	__IO uint32_t IOMMU_TLB_IVLD_STA_ADDR_REG;           /*!< Offset 0x088 IOMMU TLB Invalidation Start Address Register */
	__IO uint32_t IOMMU_TLB_IVLD_END_ADDR_REG;           /*!< Offset 0x08C IOMMU TLB Invalidation End Address Register */
	__IO uint32_t IOMMU_TLB_IVLD_ADDR_REG;               /*!< Offset 0x090 IOMMU TLB Invalidation Address Register */
	__IO uint32_t IOMMU_TLB_IVLD_ADDR_MASK_REG;          /*!< Offset 0x094 IOMMU TLB Invalidation Address Mask Register */
	__IO uint32_t IOMMU_TLB_IVLD_ENABLE_REG;             /*!< Offset 0x098 IOMMU TLB Invalidation Enable Register */
	__IO uint32_t IOMMU_PC_IVLD_MODE_SEL_REG;            /*!< Offset 0x09C IOMMU PC Invalidation Mode Select Register */
	__IO uint32_t IOMMU_PC_IVLD_ADDR_REG;                /*!< Offset 0x0A0 IOMMU PC Invalidation Address Register */
	__IO uint32_t IOMMU_PC_IVLD_STA_ADDR_REG;            /*!< Offset 0x0A4 IOMMU PC Invalidation Start Address Register */
	__IO uint32_t IOMMU_PC_IVLD_ENABLE_REG;              /*!< Offset 0x0A8 IOMMU PC Invalidation Enable Register */
	__IO uint32_t IOMMU_PC_IVLD_END_ADDR_REG;            /*!< Offset 0x0AC IOMMU PC Invalidation End Address Register */
	__IO uint32_t IOMMU_DM_AUT_CTRL0_REG;                /*!< Offset 0x0B0 IOMMU Domain Authority Control 0 Register */
	__IO uint32_t IOMMU_DM_AUT_CTRL1_REG;                /*!< Offset 0x0B4 IOMMU Domain Authority Control 1 Register */
	__IO uint32_t IOMMU_DM_AUT_CTRL2_REG;                /*!< Offset 0x0B8 IOMMU Domain Authority Control 2 Register */
	__IO uint32_t IOMMU_DM_AUT_CTRL3_REG;                /*!< Offset 0x0BC IOMMU Domain Authority Control 3 Register */
	__IO uint32_t IOMMU_DM_AUT_CTRL4_REG;                /*!< Offset 0x0C0 IOMMU Domain Authority Control 4 Register */
	__IO uint32_t IOMMU_DM_AUT_CTRL5_REG;                /*!< Offset 0x0C4 IOMMU Domain Authority Control 5 Register */
	__IO uint32_t IOMMU_DM_AUT_CTRL6_REG;                /*!< Offset 0x0C8 IOMMU Domain Authority Control 6 Register */
	__IO uint32_t IOMMU_DM_AUT_CTRL7_REG;                /*!< Offset 0x0CC IOMMU Domain Authority Control 7 Register */
	__IO uint32_t IOMMU_DM_AUT_OVWT_REG;                 /*!< Offset 0x0D0 IOMMU Domain Authority Overwrite Register */
	uint32_t reserved_0x0D4 [0x000B];
	__IO uint32_t IOMMU_INT_ENABLE_REG;                  /*!< Offset 0x100 IOMMU Interrupt Enable Register */
	__IO uint32_t IOMMU_INT_CLR_REG;                     /*!< Offset 0x104 IOMMU Interrupt Clear Register */
	__IO uint32_t IOMMU_INT_STA_REG;                     /*!< Offset 0x108 IOMMU Interrupt Status Register */
	uint32_t reserved_0x10C;
	__IO uint32_t IOMMU_INT_ERR_ADDR0_REG;               /*!< Offset 0x110 IOMMU Interrupt Error Address 0 Register */
	__IO uint32_t IOMMU_INT_ERR_ADDR1_REG;               /*!< Offset 0x114 IOMMU Interrupt Error Address 1 Register */
	__IO uint32_t IOMMU_INT_ERR_ADDR2_REG;               /*!< Offset 0x118 IOMMU Interrupt Error Address 2 Register */
	__IO uint32_t IOMMU_INT_ERR_ADDR3_REG;               /*!< Offset 0x11C IOMMU Interrupt Error Address 3 Register */
	__IO uint32_t IOMMU_INT_ERR_ADDR4_REG;               /*!< Offset 0x120 IOMMU Interrupt Error Address 4 Register */
	__IO uint32_t IOMMU_INT_ERR_ADDR5_REG;               /*!< Offset 0x124 IOMMU Interrupt Error Address 5 Register */
	__IO uint32_t IOMMU_INT_ERR_ADDR6_REG;               /*!< Offset 0x128 IOMMU Interrupt Error Address 6 Register */
	uint32_t reserved_0x12C;
	__IO uint32_t IOMMU_INT_ERR_ADDR7_REG;               /*!< Offset 0x130 IOMMU Interrupt Error Address 7 Register */
	__IO uint32_t IOMMU_INT_ERR_ADDR8_REG;               /*!< Offset 0x134 IOMMU Interrupt Error Address 8 Register */
	uint32_t reserved_0x138 [0x0006];
	__IO uint32_t IOMMU_INT_ERR_DATA0_REG;               /*!< Offset 0x150 IOMMU Interrupt Error Data 0 Register */
	__IO uint32_t IOMMU_INT_ERR_DATA1_REG;               /*!< Offset 0x154 IOMMU Interrupt Error Data 1 Register */
	__IO uint32_t IOMMU_INT_ERR_DATA2_REG;               /*!< Offset 0x158 IOMMU Interrupt Error Data 2 Register */
	__IO uint32_t IOMMU_INT_ERR_DATA3_REG;               /*!< Offset 0x15C IOMMU Interrupt Error Data 3 Register */
	__IO uint32_t IOMMU_INT_ERR_DATA4_REG;               /*!< Offset 0x160 IOMMU Interrupt Error Data 4 Register */
	__IO uint32_t IOMMU_INT_ERR_DATA5_REG;               /*!< Offset 0x164 IOMMU Interrupt Error Data 5 Register */
	__IO uint32_t IOMMU_INT_ERR_DATA6_REG;               /*!< Offset 0x168 IOMMU Interrupt Error Data 6 Register */
	uint32_t reserved_0x16C;
	__IO uint32_t IOMMU_INT_ERR_DATA7_REG;               /*!< Offset 0x170 IOMMU Interrupt Error Data 7 Register */
	__IO uint32_t IOMMU_INT_ERR_DATA8_REG;               /*!< Offset 0x174 IOMMU Interrupt Error Data 8 Register */
	uint32_t reserved_0x178 [0x0002];
	__IO uint32_t IOMMU_L1PG_INT_REG;                    /*!< Offset 0x180 IOMMU L1 Page Table Interrupt Register */
	__IO uint32_t IOMMU_L2PG_INT_REG;                    /*!< Offset 0x184 IOMMU L2 Page Table Interrupt Register */
	uint32_t reserved_0x188 [0x0002];
	__IO uint32_t IOMMU_VA_REG;                          /*!< Offset 0x190 IOMMU Virtual Address Register */
	__IO uint32_t IOMMU_VA_DATA_REG;                     /*!< Offset 0x194 IOMMU Virtual Address Data Register */
	__IO uint32_t IOMMU_VA_CONFIG_REG;                   /*!< Offset 0x198 IOMMU Virtual Address Configuration Register */
	uint32_t reserved_0x19C [0x0019];
	__IO uint32_t IOMMU_PMU_ENABLE_REG;                  /*!< Offset 0x200 IOMMU PMU Enable Register */
	uint32_t reserved_0x204 [0x0003];
	__IO uint32_t IOMMU_PMU_CLR_REG;                     /*!< Offset 0x210 IOMMU PMU Clear Register */
	uint32_t reserved_0x214 [0x0007];
	__IO uint32_t IOMMU_PMU_ACCESS_LOW0_REG;             /*!< Offset 0x230 IOMMU PMU Access Low 0 Register */
	__IO uint32_t IOMMU_PMU_ACCESS_HIGH0_REG;            /*!< Offset 0x234 IOMMU PMU Access High 0 Register */
	__IO uint32_t IOMMU_PMU_HIT_LOW0_REG;                /*!< Offset 0x238 IOMMU PMU Hit Low 0 Register */
	__IO uint32_t IOMMU_PMU_HIT_HIGH0_REG;               /*!< Offset 0x23C IOMMU PMU Hit High 0 Register */
	__IO uint32_t IOMMU_PMU_ACCESS_LOW1_REG;             /*!< Offset 0x240 IOMMU PMU Access Low 1 Register */
	__IO uint32_t IOMMU_PMU_ACCESS_HIGH1_REG;            /*!< Offset 0x244 IOMMU PMU Access High 1 Register */
	__IO uint32_t IOMMU_PMU_HIT_LOW1_REG;                /*!< Offset 0x248 IOMMU PMU Hit Low 1 Register */
	__IO uint32_t IOMMU_PMU_HIT_HIGH1_REG;               /*!< Offset 0x24C IOMMU PMU Hit High 1 Register */
	__IO uint32_t IOMMU_PMU_ACCESS_LOW2_REG;             /*!< Offset 0x250 IOMMU PMU Access Low 2 Register */
	__IO uint32_t IOMMU_PMU_ACCESS_HIGH2_REG;            /*!< Offset 0x254 IOMMU PMU Access High 2 Register */
	__IO uint32_t IOMMU_PMU_HIT_LOW2_REG;                /*!< Offset 0x258 IOMMU PMU Hit Low 2 Register */
	__IO uint32_t IOMMU_PMU_HIT_HIGH2_REG;               /*!< Offset 0x25C IOMMU PMU Hit High 2 Register */
	__IO uint32_t IOMMU_PMU_ACCESS_LOW3_REG;             /*!< Offset 0x260 IOMMU PMU Access Low 3 Register */
	__IO uint32_t IOMMU_PMU_ACCESS_HIGH3_REG;            /*!< Offset 0x264 IOMMU PMU Access High 3 Register */
	__IO uint32_t IOMMU_PMU_HIT_LOW3_REG;                /*!< Offset 0x268 IOMMU PMU Hit Low 3 Register */
	__IO uint32_t IOMMU_PMU_HIT_HIGH3_REG;               /*!< Offset 0x26C IOMMU PMU Hit High 3 Register */
	__IO uint32_t IOMMU_PMU_ACCESS_LOW4_REG;             /*!< Offset 0x270 IOMMU PMU Access Low 4 Register */
	__IO uint32_t IOMMU_PMU_ACCESS_HIGH4_REG;            /*!< Offset 0x274 IOMMU PMU Access High 4 Register */
	__IO uint32_t IOMMU_PMU_HIT_LOW4_REG;                /*!< Offset 0x278 IOMMU PMU Hit Low 4 Register */
	__IO uint32_t IOMMU_PMU_HIT_HIGH4_REG;               /*!< Offset 0x27C IOMMU PMU Hit High 4 Register */
	__IO uint32_t IOMMU_PMU_ACCESS_LOW5_REG;             /*!< Offset 0x280 IOMMU PMU Access Low 5 Register */
	__IO uint32_t IOMMU_PMU_ACCESS_HIGH5_REG;            /*!< Offset 0x284 IOMMU PMU Access High 5 Register */
	__IO uint32_t IOMMU_PMU_HIT_LOW5_REG;                /*!< Offset 0x288 IOMMU PMU Hit Low 5 Register */
	__IO uint32_t IOMMU_PMU_HIT_HIGH5_REG;               /*!< Offset 0x28C IOMMU PMU Hit High 5 Register */
	__IO uint32_t IOMMU_PMU_ACCESS_LOW6_REG;             /*!< Offset 0x290 IOMMU PMU Access Low 6 Register */
	__IO uint32_t IOMMU_PMU_ACCESS_HIGH6_REG;            /*!< Offset 0x294 IOMMU PMU Access High 6 Register */
	__IO uint32_t IOMMU_PMU_HIT_LOW6_REG;                /*!< Offset 0x298 IOMMU PMU Hit Low 6 Register */
	__IO uint32_t IOMMU_PMU_HIT_HIGH6_REG;               /*!< Offset 0x29C IOMMU PMU Hit High 6 Register */
	uint32_t reserved_0x2A0 [0x000C];
	__IO uint32_t IOMMU_PMU_ACCESS_LOW7_REG;             /*!< Offset 0x2D0 IOMMU PMU Access Low 7 Register */
	__IO uint32_t IOMMU_PMU_ACCESS_HIGH7_REG;            /*!< Offset 0x2D4 IOMMU PMU Access High 7 Register */
	__IO uint32_t IOMMU_PMU_HIT_LOW7_REG;                /*!< Offset 0x2D8 IOMMU PMU Hit Low 7 Register */
	__IO uint32_t IOMMU_PMU_HIT_HIGH7_REG;               /*!< Offset 0x2DC IOMMU PMU Hit High 7 Register */
	__IO uint32_t IOMMU_PMU_ACCESS_LOW8_REG;             /*!< Offset 0x2E0 IOMMU PMU Access Low 8 Register */
	__IO uint32_t IOMMU_PMU_ACCESS_HIGH8_REG;            /*!< Offset 0x2E4 IOMMU PMU Access High 8 Register */
	__IO uint32_t IOMMU_PMU_HIT_LOW8_REG;                /*!< Offset 0x2E8 IOMMU PMU Hit Low 8 Register */
	__IO uint32_t IOMMU_PMU_HIT_HIGH8_REG;               /*!< Offset 0x2EC IOMMU PMU Hit High 8 Register */
	uint32_t reserved_0x2F0 [0x0004];
	__IO uint32_t IOMMU_PMU_TL_LOW0_REG;                 /*!< Offset 0x300 IOMMU Total Latency Low 0 Register */
	__IO uint32_t IOMMU_PMU_TL_HIGH0_REG;                /*!< Offset 0x304 IOMMU Total Latency High 0 Register */
	__IO uint32_t IOMMU_PMU_ML0_REG;                     /*!< Offset 0x308 IOMMU Max Latency 0 Register */
	uint32_t reserved_0x30C;
	__IO uint32_t IOMMU_PMU_TL_LOW1_REG;                 /*!< Offset 0x310 IOMMU Total Latency Low 1 Register */
	__IO uint32_t IOMMU_PMU_TL_HIGH1_REG;                /*!< Offset 0x314 IOMMU Total Latency High 1 Register */
	__IO uint32_t IOMMU_PMU_ML1_REG;                     /*!< Offset 0x318 IOMMU Max Latency 1 Register */
	uint32_t reserved_0x31C;
	__IO uint32_t IOMMU_PMU_TL_LOW2_REG;                 /*!< Offset 0x320 IOMMU Total Latency Low 2 Register */
	__IO uint32_t IOMMU_PMU_TL_HIGH2_REG;                /*!< Offset 0x324 IOMMU Total Latency High 2 Register */
	__IO uint32_t IOMMU_PMU_ML2_REG;                     /*!< Offset 0x328 IOMMU Max Latency 2 Register */
	uint32_t reserved_0x32C;
	__IO uint32_t IOMMU_PMU_TL_LOW3_REG;                 /*!< Offset 0x330 IOMMU Total Latency Low 3 Register */
	__IO uint32_t IOMMU_PMU_TL_HIGH3_REG;                /*!< Offset 0x334 IOMMU Total Latency High 3 Register */
	__IO uint32_t IOMMU_PMU_ML3_REG;                     /*!< Offset 0x338 IOMMU Max Latency 3 Register */
	uint32_t reserved_0x33C;
	__IO uint32_t IOMMU_PMU_TL_LOW4_REG;                 /*!< Offset 0x340 IOMMU Total Latency Low 4 Register */
	__IO uint32_t IOMMU_PMU_TL_HIGH4_REG;                /*!< Offset 0x344 IOMMU Total Latency High 4 Register */
	__IO uint32_t IOMMU_PMU_ML4_REG;                     /*!< Offset 0x348 IOMMU Max Latency 4 Register */
	uint32_t reserved_0x34C;
	__IO uint32_t IOMMU_PMU_TL_LOW5_REG;                 /*!< Offset 0x350 IOMMU Total Latency Low 5 Register */
	__IO uint32_t IOMMU_PMU_TL_HIGH5_REG;                /*!< Offset 0x354 IOMMU Total Latency High 5 Register */
	__IO uint32_t IOMMU_PMU_ML5_REG;                     /*!< Offset 0x358 IOMMU Max Latency 5 Register */
	uint32_t reserved_0x35C;
	__IO uint32_t IOMMU_PMU_TL_LOW6_REG;                 /*!< Offset 0x360 IOMMU Total Latency Low 6 Register */
	__IO uint32_t IOMMU_PMU_TL_HIGH6_REG;                /*!< Offset 0x364 IOMMU Total Latency High 6 Register */
	__IO uint32_t IOMMU_PMU_ML6_REG;                     /*!< Offset 0x368 IOMMU Max Latency 6 Register */
} IOMMU_TypeDef; /* size of structure = 0x36C */
/*
 * @brief THS
 */
/*!< THS Controller Interface */
typedef struct THS_Type
{
	__IO uint32_t THS_CTRL;                              /*!< Offset 0x000 THS Control Register */
	__IO uint32_t THS_EN;                                /*!< Offset 0x004 THS Enable Register */
	__IO uint32_t THS_PER;                               /*!< Offset 0x008 THS Period Control Register */
	uint32_t reserved_0x00C;
	__IO uint32_t THS_DATA_INTC;                         /*!< Offset 0x010 THS Data Interrupt Control Register */
	__IO uint32_t THS_SHUT_INTC;                         /*!< Offset 0x014 THS Shut Interrupt Control Register */
	__IO uint32_t THS_ALARM_INTC;                        /*!< Offset 0x018 THS Alarm Interrupt Control Register */
	uint32_t reserved_0x01C;
	__IO uint32_t THS_DATA_INTS;                         /*!< Offset 0x020 THS Data Interrupt Status Register */
	__IO uint32_t THS_SHUT_INTS;                         /*!< Offset 0x024 THS Shut Interrupt Status Register */
	__IO uint32_t THS_ALARMO_INTS;                       /*!< Offset 0x028 THS Alarm off Interrupt Status Register */
	__IO uint32_t THS_ALARM_INTS;                        /*!< Offset 0x02C THS Alarm Interrupt Status Register */
	__IO uint32_t THS_FILTER;                            /*!< Offset 0x030 THS Median Filter Control Register */
	uint32_t reserved_0x034 [0x0003];
	__IO uint32_t THS_ALARM_CTRL;                        /*!< Offset 0x040 THS Alarm Threshold Control Register */
	uint32_t reserved_0x044 [0x000F];
	__IO uint32_t THS_SHUTDOWN_CTRL;                     /*!< Offset 0x080 THS Shutdown Threshold Control Register */
	uint32_t reserved_0x084 [0x0007];
	__IO uint32_t THS_CDATA;                             /*!< Offset 0x0A0 THS Calibration Data */
	uint32_t reserved_0x0A4 [0x0007];
	__IO uint32_t THS_DATA;                              /*!< Offset 0x0C0 THS Data Register */
} THS_TypeDef; /* size of structure = 0x0C4 */
/*
 * @brief TIMER
 */
/*!< TIMER Controller Interface */
typedef struct TIMER_Type
{
	__IO uint32_t TMR_IRQ_EN_REG;                        /*!< Offset 0x000 Timer IRQ Enable Register */
	__IO uint32_t TMR_IRQ_STA_REG;                       /*!< Offset 0x004 Timer Status Register */
	uint32_t reserved_0x008 [0x0002];
	__IO uint32_t TMR0_CTRL_REG;                         /*!< Offset 0x010 Timer0 Control Register */
	__IO uint32_t TMR0_INTV_VALUE_REG;                   /*!< Offset 0x014 Timer0 Interval Value Register */
	__IO uint32_t TMR0_CUR_VALUE_REG;                    /*!< Offset 0x018 Timer0 Current Value Register */
	uint32_t reserved_0x01C;
	__IO uint32_t TMR1_CTRL_REG;                         /*!< Offset 0x020 Timer1 Control Register */
	__IO uint32_t TMR1_INTV_VALUE_REG;                   /*!< Offset 0x024 Timer1 Interval Value Register */
	__IO uint32_t TMR1_CUR_VALUE_REG;                    /*!< Offset 0x028 Timer1 Current Value Register */
	uint32_t reserved_0x02C [0x001D];
	__IO uint32_t WDOG_IRQ_EN_REG;                       /*!< Offset 0x0A0 Watchdog IRQ Enable Register */
	__IO uint32_t WDOG_IRQ_STA_REG;                      /*!< Offset 0x0A4 Watchdog Status Register */
	__IO uint32_t WDOG_SOFT_RST_REG;                     /*!< Offset 0x0A8 Watchdog Software Reset Register */
	uint32_t reserved_0x0AC;
	__IO uint32_t WDOG_CTRL_REG;                         /*!< Offset 0x0B0 Watchdog Control Register */
	__IO uint32_t WDOG_CFG_REG;                          /*!< Offset 0x0B4 Watchdog Configuration Register */
	__IO uint32_t WDOG_MODE_REG;                         /*!< Offset 0x0B8 Watchdog Mode Register */
	__IO uint32_t WDOG_OUTPUT_CFG_REG;                   /*!< Offset 0x0BC Watchdog Output Configuration Register */
	__IO uint32_t AVS_CNT_CTL_REG;                       /*!< Offset 0x0C0 AVS Control Register */
	__IO uint32_t AVS_CNT0_REG;                          /*!< Offset 0x0C4 AVS Counter 0 Register */
	__IO uint32_t AVS_CNT1_REG;                          /*!< Offset 0x0C8 AVS Counter 1 Register */
	__IO uint32_t AVS_CNT_DIV_REG;                       /*!< Offset 0x0CC AVS Divisor Register */
} TIMER_TypeDef; /* size of structure = 0x0D0 */
/*
 * @brief HSTIMER
 */
/*!< HSTIMER Controller Interface */
typedef struct HSTIMER_Type
{
	__IO uint32_t HS_TMR_IRQ_EN_REG;                     /*!< Offset 0x000 HS Timer IRQ Enable Register */
	__IO uint32_t HS_TMR_IRQ_STAS_REG;                   /*!< Offset 0x004 HS Timer Status Register */
	uint32_t reserved_0x008 [0x0006];
	__IO uint32_t HS_TMR0_CTRL_REG;                      /*!< Offset 0x020 HS Timer0 Control Register */
	__IO uint32_t HS_TMR0_INTV_LO_REG;                   /*!< Offset 0x024 HS Timer0 Interval Value Low Register */
	__IO uint32_t HS_TMR0_INTV_HI_REG;                   /*!< Offset 0x028 HS Timer0 Interval Value High Register */
	__IO uint32_t HS_TMR0_CURNT_LO_REG;                  /*!< Offset 0x02C HS Timer0 Current Value Low Register */
	__IO uint32_t HS_TMR0_CURNT_HI_REG;                  /*!< Offset 0x030 HS Timer0 Current Value High Register */
	uint32_t reserved_0x034 [0x0003];
	__IO uint32_t HS_TMR1_CTRL_REG;                      /*!< Offset 0x040 HS Timer1 Control Register */
	__IO uint32_t HS_TMR1_INTV_LO_REG;                   /*!< Offset 0x044 HS Timer1 Interval Value Low Register */
	__IO uint32_t HS_TMR1_INTV_HI_REG;                   /*!< Offset 0x048 HS Timer1 Interval Value High Register */
	__IO uint32_t HS_TMR1_CURNT_LO_REG;                  /*!< Offset 0x04C HS Timer1 Current Value Low Register */
	__IO uint32_t HS_TMR1_CURNT_HI_REG;                  /*!< Offset 0x050 HS Timer1 Current Value High Register */
} HSTIMER_TypeDef; /* size of structure = 0x054 */
/*
 * @brief CAN
 */
/*!< CAN Controller Interface */
typedef struct CAN_Type
{
	__IO uint32_t CAN_MSEL;                              /*!< Offset 0x000 CAN mode select register */
	__IO uint32_t CAN_CMD;                               /*!< Offset 0x004 CAN command register */
	__IO uint32_t CAN_STA;                               /*!< Offset 0x008 CAN status register */
	__IO uint32_t CAN_INT;                               /*!< Offset 0x00C CAN interrupt register */
	__IO uint32_t CAN_INTEN;                             /*!< Offset 0x010 CAN interrupt enable register */
	__IO uint32_t CAN_BUSTIME;                           /*!< Offset 0x014 CAN bus timing register */
	__IO uint32_t CAN_TEWL;                              /*!< Offset 0x018 CAN TX error warning limit register */
	__IO uint32_t CAN_ERRC;                              /*!< Offset 0x01C CAN error counter register */
	__IO uint32_t CAN_RMCNT;                             /*!< Offset 0x020 CAN receive message counter register */
	__IO uint32_t CAN_RBUF_SADDR;                        /*!< Offset 0x024 CAN receive buffer start address register */
	__IO uint32_t CAN_ACPC;                              /*!< Offset 0x028 CAN acceptance code 0 register(reset mode) */
	__IO uint32_t CAN_ACPM;                              /*!< Offset 0x02C CAN acceptance mask 0 register(reset mode) */
	uint32_t reserved_0x030 [0x0004];
	__IO uint32_t CAN_TRBUF [0x00D];                     /*!< Offset 0x040 CAN TX/RX message buffer N (n=0..12) register */
	uint32_t reserved_0x074 [0x0043];
	__IO uint32_t CAN_RBUF_RBACK [0x030];                /*!< Offset 0x180 CAN transmit buffer for read back register (0x0180 ~0x1b0) */
	uint32_t reserved_0x240 [0x0030];
	__IO uint32_t CAN_VERSION;                           /*!< Offset 0x300 CAN Version Register */
} CAN_TypeDef; /* size of structure = 0x304 */
/*
 * @brief USBEHCI
 */
/*!< USBEHCI Controller Interface */
typedef struct USBEHCI_Type
{
	__IO uint16_t E_CAPLENGTH;                           /*!< Offset 0x000 EHCI Capability Register Length Register */
	__IO uint16_t E_HCIVERSION;                          /*!< Offset 0x002 EHCI Host Interface Version Number Register */
	__IO uint32_t E_HCSPARAMS;                           /*!< Offset 0x004 EHCI Host Control Structural Parameter Register */
	__IO uint32_t E_HCCPARAMS;                           /*!< Offset 0x008 EHCI Host Control Capability Parameter Register */
	__IO uint32_t E_HCSPPORTROUTE;                       /*!< Offset 0x00C EHCI Companion Port Route Description */
	__IO uint32_t E_USBCMD;                              /*!< Offset 0x010 EHCI USB Command Register */
	__IO uint32_t E_USBSTS;                              /*!< Offset 0x014 EHCI USB Status Register */
	__IO uint32_t E_USBINTR;                             /*!< Offset 0x018 EHCI USB Interrupt Enable Register */
	__IO uint32_t E_FRINDEX;                             /*!< Offset 0x01C EHCI USB Frame Index Register */
	__IO uint32_t E_CTRLDSSEGMENT;                       /*!< Offset 0x020 EHCI 4G Segment Selector Register */
	__IO uint32_t E_PERIODICLISTBASE;                    /*!< Offset 0x024 EHCI Frame List Base Address Register */
	__IO uint32_t E_ASYNCLISTADDR;                       /*!< Offset 0x028 EHCI Next Asynchronous List Address Register */
	uint32_t reserved_0x02C [0x0009];
	__IO uint32_t E_CONFIGFLAG;                          /*!< Offset 0x050 EHCI Configured Flag Register */
	__IO uint32_t E_PORTSC;                              /*!< Offset 0x054 EHCI Port Status/Control Register */
	uint32_t reserved_0x058 [0x00EA];
	__IO uint32_t O_HcRevision;                          /*!< Offset 0x400 OHCI Revision Register (not documented) */
	__IO uint32_t O_HcControl;                           /*!< Offset 0x404 OHCI Control Register */
	__IO uint32_t O_HcCommandStatus;                     /*!< Offset 0x408 OHCI Command Status Register */
	__IO uint32_t O_HcInterruptStatus;                   /*!< Offset 0x40C OHCI Interrupt Status Register */
	__IO uint32_t O_HcInterruptEnable;                   /*!< Offset 0x410 OHCI Interrupt Enable Register */
	__IO uint32_t O_HcInterruptDisable;                  /*!< Offset 0x414 OHCI Interrupt Disable Register */
	__IO uint32_t O_HcHCCA;                              /*!< Offset 0x418 OHCI HCCA Base */
	__IO uint32_t O_HcPeriodCurrentED;                   /*!< Offset 0x41C OHCI Period Current ED Base */
	__IO uint32_t O_HcControlHeadED;                     /*!< Offset 0x420 OHCI Control Head ED Base */
	__IO uint32_t O_HcControlCurrentED;                  /*!< Offset 0x424 OHCI Control Current ED Base */
	__IO uint32_t O_HcBulkHeadED;                        /*!< Offset 0x428 OHCI Bulk Head ED Base */
	__IO uint32_t O_HcBulkCurrentED;                     /*!< Offset 0x42C OHCI Bulk Current ED Base */
	__IO uint32_t O_HcDoneHead;                          /*!< Offset 0x430 OHCI Done Head Base */
	__IO uint32_t O_HcFmInterval;                        /*!< Offset 0x434 OHCI Frame Interval Register */
	__IO uint32_t O_HcFmRemaining;                       /*!< Offset 0x438 OHCI Frame Remaining Register */
	__IO uint32_t O_HcFmNumber;                          /*!< Offset 0x43C OHCI Frame Number Register */
	__IO uint32_t O_HcPerioddicStart;                    /*!< Offset 0x440 OHCI Periodic Start Register */
	__IO uint32_t O_HcLSThreshold;                       /*!< Offset 0x444 OHCI LS Threshold Register */
	__IO uint32_t O_HcRhDescriptorA;                     /*!< Offset 0x448 OHCI Root Hub Descriptor Register A */
	__IO uint32_t O_HcRhDesriptorB;                      /*!< Offset 0x44C OHCI Root Hub Descriptor Register B */
	__IO uint32_t O_HcRhStatus;                          /*!< Offset 0x450 OHCI Root Hub Status Register */
	__IO uint32_t O_HcRhPortStatus;                      /*!< Offset 0x454 OHCI Root Hub Port Status Register */
} USBEHCI_TypeDef; /* size of structure = 0x458 */
/*
 * @brief USBOTGFIFO
 */
/*!< USBOTGFIFO Controller Interface */
typedef struct USBOTGFIFO_Type
{
	__IO uint16_t USB_TXFADDR;                           /*!< Offset 0x000 USB_TXFADDR */
	__IO uint8_t  USB_TXHADDR;                           /*!< Offset 0x002 USB_TXHADDR */
	__IO uint8_t  USB_TXHUBPORT;                         /*!< Offset 0x003 USB_TXHUBPORT */
	__IO uint8_t  USB_RXFADDR;                           /*!< Offset 0x004 USB_RXFADDR */
	uint8_t reserved_0x005 [0x0001];
	__IO uint8_t  USB_RXHADDR;                           /*!< Offset 0x006 USB_RXHADDR */
	__IO uint8_t  USB_RXHUBPORT;                         /*!< Offset 0x007 USB_RXHUBPORT */
} USBOTGFIFO_TypeDef; /* size of structure = 0x008 */
/*
 * @brief USBOTG
 */
/*!< USBOTG Controller Interface */
typedef struct USBOTG_Type
{
	__IO uint32_t USB_EPFIFO [0x006];                    /*!< Offset 0x000 USB_EPFIFO [0..5] */
	uint32_t reserved_0x018 [0x000A];
	__IO uint8_t  USB_POWER;                             /*!< Offset 0x040 USB_POWER */
	__IO uint8_t  USB_DEVCTL;                            /*!< Offset 0x041 USB_DEVCTL */
	__IO uint8_t  USB_EPINDEX;                           /*!< Offset 0x042 USB_EPINDEX */
	__IO uint8_t  USB_DMACTL;                            /*!< Offset 0x043 USB_DMACTL */
	__IO uint16_t USB_INTTX;                             /*!< Offset 0x044 USB_INTTX */
	__IO uint16_t USB_INTRX;                             /*!< Offset 0x046 USB_INTRX */
	__IO uint16_t USB_INTTXE;                            /*!< Offset 0x048 USB_INTTXE */
	__IO uint16_t USB_INTRXE;                            /*!< Offset 0x04A USB_INTRXE */
	__IO uint32_t USB_INTUSB;                            /*!< Offset 0x04C USB_INTUSB */
	__IO uint32_t USB_INTUSBE;                           /*!< Offset 0x050 USB_INTUSBE */
	__IO uint16_t USB_FRAME;                             /*!< Offset 0x054 USB_FRAME */
	uint8_t reserved_0x056 [0x0026];
	__IO uint8_t  USB_TESTMODE;                          /*!< Offset 0x07C USB_TESTMODE */
	uint8_t reserved_0x07D [0x0001];
	__IO uint8_t  USB_FSM;                               /*!< Offset 0x07E USB_FSM */
	uint8_t reserved_0x07F [0x0001];
	__IO uint16_t USB_TXMAXP;                            /*!< Offset 0x080 USB_TXMAXP */
	__IO uint16_t USB_CSR0;                              /*!< Offset 0x082 [15:8]: USB_TXCSRH, [7:0]: USB_TXCSRL */
	__IO uint16_t USB_RXMAXP;                            /*!< Offset 0x084 USB_RXMAXP */
	__IO uint16_t USB_RXCSR;                             /*!< Offset 0x086 USB_RXCSR */
	__IO uint16_t USB_RXCOUNT;                           /*!< Offset 0x088 USB_RXCOUNT */
	__IO uint16_t USB_RXPKTCNT;                          /*!< Offset 0x08A USB_RXPKTCNT */
	__IO uint8_t  USB_TXTI;                              /*!< Offset 0x08C USB_TXTI */
	__IO uint8_t  USB_TXNAKLIMIT;                        /*!< Offset 0x08D USB_TXNAKLIMIT */
	__IO uint8_t  USB_RXTI;                              /*!< Offset 0x08E USB_RXTI */
	__IO uint8_t  USB_RXNAKLIMIT;                        /*!< Offset 0x08F USB_RXNAKLIMIT */
	__IO uint16_t USB_TXFIFOSZ;                          /*!< Offset 0x090 USB_TXFIFOSZ */
	__IO uint16_t USB_TXFIFOADD;                         /*!< Offset 0x092 USB_TXFIFOADD */
	__IO uint16_t USB_RXFIFOSZ;                          /*!< Offset 0x094 USB_RXFIFOSZ */
	__IO uint16_t USB_RXFIFOADD;                         /*!< Offset 0x096 USB_RXFIFOADD */
	USBOTGFIFO_TypeDef FIFO [0x006];                     /*!< Offset 0x098 FIFOs [0..5] */
	uint32_t reserved_0x0C8 [0x00CE];
	__IO uint32_t USB_ISCR;                              /*!< Offset 0x400 HCI Interface Register (HCI_Interface) */
	__IO uint32_t USBPHY_PHYCTL;                         /*!< Offset 0x404 USBPHY_PHYCTL */
	__IO uint32_t HCI_CTRL3;                             /*!< Offset 0x408 HCI Control 3 Register (bist) */
	uint32_t reserved_0x40C;
	__IO uint32_t PHY_CTRL;                              /*!< Offset 0x410 PHY Control Register (PHY_Control) */
	uint32_t reserved_0x414 [0x0003];
	__IO uint32_t PHY_OTGCTL;                            /*!< Offset 0x420 Control PHY routing to EHCI or OTG */
	__IO uint32_t PHY_STATUS;                            /*!< Offset 0x424 PHY Status Register */
	__IO uint32_t USB_SPDCR;                             /*!< Offset 0x428 HCI SIE Port Disable Control Register */
} USBOTG_TypeDef; /* size of structure = 0x42C */
/*
 * @brief USBPHYC
 */
/*!< USBPHYC Controller Interface */
typedef struct USBPHYC_Type
{
	__IO uint32_t USB_CTRL;                              /*!< Offset 0x000 HCI Interface Register (HCI_Interface) */
	__IO uint32_t USBPHY_PHYCTL;                         /*!< Offset 0x004 USBPHY_PHYCTL */
	__IO uint32_t HCI_CTRL3;                             /*!< Offset 0x008 HCI Control 3 Register (bist) */
	uint32_t reserved_0x00C;
	__IO uint32_t PHY_CTRL;                              /*!< Offset 0x010 PHY Control Register (PHY_Control) */
	uint32_t reserved_0x014 [0x0003];
	__IO uint32_t PHY_OTGCTL;                            /*!< Offset 0x020 Control PHY routing to EHCI or OTG */
	__IO uint32_t PHY_STATUS;                            /*!< Offset 0x024 PHY Status Register */
	__IO uint32_t USB_SPDCR;                             /*!< Offset 0x028 HCI SIE Port Disable Control Register */
} USBPHYC_TypeDef; /* size of structure = 0x02C */
/*
 * @brief G2D_TOP
 */
/*!< G2D_TOP Controller Interface */
typedef struct G2D_TOP_Type
{
	__IO uint32_t G2D_SCLK_GATE;                         /*!< Offset 0x000 G2D SCLK gate   */
	__IO uint32_t G2D_HCLK_GATE;                         /*!< Offset 0x004 g2d HCLK gate   */
	__IO uint32_t G2D_AHB_RESET;                         /*!< Offset 0x008 G2D AHB reset   */
	__IO uint32_t G2D_SCLK_DIV;                          /*!< Offset 0x00C G2D SCLK div    */
} G2D_TOP_TypeDef; /* size of structure = 0x010 */
/*
 * @brief G2D_MIXER
 */
/*!< G2D_MIXER Controller Interface */
typedef struct G2D_MIXER_Type
{
	__IO uint32_t G2D_MIXER_CTL;                         /*!< Offset 0x000 G2D mixer control */
	__IO uint32_t G2D_MIXER_INT;                         /*!< Offset 0x004 G2D mixer interrupt */
	__IO uint32_t G2D_MIXER_CLK;                         /*!< Offset 0x008 G2D mixer clock */
} G2D_MIXER_TypeDef; /* size of structure = 0x00C */
/*
 * @brief G2D_LAY
 */
/*!< G2D_LAY Controller Interface */
typedef struct G2D_LAY_Type
{
	__IO uint32_t V0_ATTCTL;                             /*!< Offset 0x000 V0_ATTCTL */
	__IO uint32_t V0_MBSIZE;                             /*!< Offset 0x004 Source rectangle size (may be empty) */
	__IO uint32_t V0_COOR;                               /*!< Offset 0x008 Target window position */
	__IO uint32_t V0_PITCH0;                             /*!< Offset 0x00C V0_PITCH0 */
	__IO uint32_t V0_PITCH1;                             /*!< Offset 0x010 V0_PITCH1 */
	__IO uint32_t V0_PITCH2;                             /*!< Offset 0x014 V0_PITCH2 */
	__IO uint32_t V0_LADD0;                              /*!< Offset 0x018 V0_LADD0 */
	__IO uint32_t V0_LADD1;                              /*!< Offset 0x01C V0_LADD1 */
	__IO uint32_t V0_LADD2;                              /*!< Offset 0x020 V0_LADD2 */
	__IO uint32_t V0_FILLC;                              /*!< Offset 0x024 V0_FILLC */
	__IO uint32_t V0_HADD;                               /*!< Offset 0x028 [31:24]: 0, [23:16]: LADD2 bits 40..32, [15:8]: LADD1 bits 40..32, [7:0]: LADD0 bits 40..32 */
	__IO uint32_t V0_SIZE;                               /*!< Offset 0x02C Source window size (may not be empty) */
	__IO uint32_t V0_HDS_CTL0;                           /*!< Offset 0x030 V0_HDS_CTL0 */
	__IO uint32_t V0_HDS_CTL1;                           /*!< Offset 0x034 V0_HDS_CTL1 */
	__IO uint32_t V0_VDS_CTL0;                           /*!< Offset 0x038 V0_VDS_CTL0 */
	__IO uint32_t V0_VDS_CTL1;                           /*!< Offset 0x03C V0_VDS_CTL1 */
} G2D_LAY_TypeDef; /* size of structure = 0x040 */
/*
 * @brief G2D_UI
 */
/*!< G2D_UI Controller Interface */
typedef struct G2D_UI_Type
{
	__IO uint32_t UI_ATTR;                               /*!< Offset 0x000 UIx_ATTR */
	__IO uint32_t UI_MBSIZE;                             /*!< Offset 0x004 UIx_MBSIZE */
	__IO uint32_t UI_COOR;                               /*!< Offset 0x008 UIx_COOR */
	__IO uint32_t UI_PITCH;                              /*!< Offset 0x00C UIx_PITCH */
	__IO uint32_t UI_LADD;                               /*!< Offset 0x010 UIx_LADD */
	__IO uint32_t UI_FILLC;                              /*!< Offset 0x014 UIx_FILLC */
	__IO uint32_t UI_HADD;                               /*!< Offset 0x018 UIx_HADD */
	__IO uint32_t UI_SIZE;                               /*!< Offset 0x01C UIx_SIZE */
} G2D_UI_TypeDef; /* size of structure = 0x020 */
/*
 * @brief G2D_VSU
 */
/*!< G2D_VSU Controller Interface */
typedef struct G2D_VSU_Type
{
	__IO uint32_t VS_CTRL;                               /*!< Offset 0x000 VS_CTRL */
	uint32_t reserved_0x004 [0x000F];
	__IO uint32_t VS_OUT_SIZE;                           /*!< Offset 0x040 VS_OUT_SIZE */
	__IO uint32_t VS_GLB_ALPHA;                          /*!< Offset 0x044 VS_GLB_ALPHA */
	uint32_t reserved_0x048 [0x000E];
	__IO uint32_t VS_Y_SIZE;                             /*!< Offset 0x080 VS_Y_SIZE */
	uint32_t reserved_0x084;
	__IO uint32_t VS_Y_HSTEP;                            /*!< Offset 0x088 VS_Y_HSTEP */
	__IO uint32_t VS_Y_VSTEP;                            /*!< Offset 0x08C VS_Y_VSTEP */
	__IO uint32_t VS_Y_HPHASE;                           /*!< Offset 0x090 VS_Y_HPHASE */
	uint32_t reserved_0x094;
	__IO uint32_t VS_Y_VPHASE0;                          /*!< Offset 0x098 VS_Y_VPHASE0 */
	uint32_t reserved_0x09C [0x0009];
	__IO uint32_t VS_C_SIZE;                             /*!< Offset 0x0C0 VS_C_SIZE */
	uint32_t reserved_0x0C4;
	__IO uint32_t VS_C_HSTEP;                            /*!< Offset 0x0C8 VS_C_HSTEP */
	__IO uint32_t VS_C_VSTEP;                            /*!< Offset 0x0CC VS_C_VSTEP */
	__IO uint32_t VS_C_HPHASE;                           /*!< Offset 0x0D0 VS_C_HPHASE */
	uint32_t reserved_0x0D4;
	__IO uint32_t VS_C_VPHASE0;                          /*!< Offset 0x0D8 VS_C_VPHASE0 */
	uint32_t reserved_0x0DC [0x0049];
	__IO uint32_t VS_Y_HCOEF [0x020];                    /*!< Offset 0x200 VS_Y_HCOEF[N]. N=0..31 */
	uint32_t reserved_0x280 [0x0020];
	__IO uint32_t VS_Y_VCOEF [0x020];                    /*!< Offset 0x300 VS_Y_VCOEF[N]. N=0..31 */
	uint32_t reserved_0x380 [0x0020];
	__IO uint32_t VS_C_HCOEF [0x020];                    /*!< Offset 0x400 VS_C_HCOEF[N]. N=0..31 */
} G2D_VSU_TypeDef; /* size of structure = 0x480 */
/*
 * @brief G2D_BLD
 */
/*!< G2D_BLD Controller Interface */
typedef struct G2D_BLD_Type
{
	__IO uint32_t BLD_EN_CTL;                            /*!< Offset 0x000 BLD_EN_CTL          */
	uint32_t reserved_0x004 [0x0003];
	__IO uint32_t BLD_FILLC0;                            /*!< Offset 0x010 BLD_FILLC0          */
	__IO uint32_t BLD_FILLC1;                            /*!< Offset 0x014 BLD_FILLC1          */
	uint32_t reserved_0x018 [0x0002];
	__IO uint32_t BLD_CH_ISIZE0;                         /*!< Offset 0x020 BLD_CH_ISIZE0       */
	__IO uint32_t BLD_CH_ISIZE1;                         /*!< Offset 0x024 BLD_CH_ISIZE1       */
	uint32_t reserved_0x028 [0x0002];
	__IO uint32_t BLD_CH_OFFSET0;                        /*!< Offset 0x030 BLD_CH_OFFSET0      */
	__IO uint32_t BLD_CH_OFFSET1;                        /*!< Offset 0x034 BLD_CH_OFFSET1      */
	uint32_t reserved_0x038 [0x0002];
	__IO uint32_t BLD_PREMUL_CTL;                        /*!< Offset 0x040 BLD_PREMUL_CTL      */
	__IO uint32_t BLD_BK_COLOR;                          /*!< Offset 0x044 BLD_BK_COLOR        */
	__IO uint32_t BLD_SIZE;                              /*!< Offset 0x048 BLD_SIZE            */
	__IO uint32_t BLD_CTL;                               /*!< Offset 0x04C BLD_CTL             */
	__IO uint32_t BLD_KEY_CTL;                           /*!< Offset 0x050 BLD_KEY_CTL         */
	__IO uint32_t BLD_KEY_CON;                           /*!< Offset 0x054 BLD_KEY_CON         */
	__IO uint32_t BLD_KEY_MAX;                           /*!< Offset 0x058 BLD_KEY_MAX         */
	__IO uint32_t BLD_KEY_MIN;                           /*!< Offset 0x05C BLD_KEY_MIN         */
	__IO uint32_t BLD_OUT_COLOR;                         /*!< Offset 0x060 BLD_OUT_COLOR       */
	uint32_t reserved_0x064 [0x0007];
	__IO uint32_t ROP_CTL;                               /*!< Offset 0x080 ROP_CTL             */
	__IO uint32_t ROP_INDEX0;                            /*!< Offset 0x084 ROP_INDEX0          */
	__IO uint32_t ROP_INDEX1;                            /*!< Offset 0x088 ROP_INDEX1          */
	uint32_t reserved_0x08C [0x001D];
	__IO uint32_t BLD_CSC_CTL;                           /*!< Offset 0x100 BLD_CSC_CTL         */
	uint32_t reserved_0x104 [0x0003];
	__IO uint32_t BLD_CSC0_COEF00;                       /*!< Offset 0x110 BLD_CSC0_COEF00     */
	__IO uint32_t BLD_CSC0_COEF01;                       /*!< Offset 0x114 BLD_CSC0_COEF01     */
	__IO uint32_t BLD_CSC0_COEF02;                       /*!< Offset 0x118 BLD_CSC0_COEF02     */
	__IO uint32_t BLD_CSC0_CONST0;                       /*!< Offset 0x11C BLD_CSC0_CONST0     */
	__IO uint32_t BLD_CSC0_COEF10;                       /*!< Offset 0x120 BLD_CSC0_COEF10     */
	__IO uint32_t BLD_CSC0_COEF11;                       /*!< Offset 0x124 BLD_CSC0_COEF11     */
	__IO uint32_t BLD_CSC0_COEF12;                       /*!< Offset 0x128 BLD_CSC0_COEF12     */
	__IO uint32_t BLD_CSC0_CONST1;                       /*!< Offset 0x12C BLD_CSC0_CONST1     */
	__IO uint32_t BLD_CSC0_COEF20;                       /*!< Offset 0x130 BLD_CSC0_COEF20     */
	__IO uint32_t BLD_CSC0_COEF21;                       /*!< Offset 0x134 BLD_CSC0_COEF21     */
	__IO uint32_t BLD_CSC0_COEF22;                       /*!< Offset 0x138 BLD_CSC0_COEF22     */
	__IO uint32_t BLD_CSC0_CONST2;                       /*!< Offset 0x13C BLD_CSC0_CONST2     */
	__IO uint32_t BLD_CSC1_COEF00;                       /*!< Offset 0x140 BLD_CSC1_COEF00     */
	__IO uint32_t BLD_CSC1_COEF01;                       /*!< Offset 0x144 BLD_CSC1_COEF01     */
	__IO uint32_t BLD_CSC1_COEF02;                       /*!< Offset 0x148 BLD_CSC1_COEF02     */
	__IO uint32_t BLD_CSC1_CONST0;                       /*!< Offset 0x14C BLD_CSC1_CONST0     */
	__IO uint32_t BLD_CSC1_COEF10;                       /*!< Offset 0x150 BLD_CSC1_COEF10     */
	__IO uint32_t BLD_CSC1_COEF11;                       /*!< Offset 0x154 BLD_CSC1_COEF11     */
	__IO uint32_t BLD_CSC1_COEF12;                       /*!< Offset 0x158 BLD_CSC1_COEF12     */
	__IO uint32_t BLD_CSC1_CONST1;                       /*!< Offset 0x15C BLD_CSC1_CONST1     */
	__IO uint32_t BLD_CSC1_COEF20;                       /*!< Offset 0x160 BLD_CSC1_COEF20     */
	__IO uint32_t BLD_CSC1_COEF21;                       /*!< Offset 0x164 BLD_CSC1_COEF21     */
	__IO uint32_t BLD_CSC1_COEF22;                       /*!< Offset 0x168 BLD_CSC1_COEF22     */
	__IO uint32_t BLD_CSC1_CONST2;                       /*!< Offset 0x16C BLD_CSC1_CONST2     */
	__IO uint32_t BLD_CSC2_COEF00;                       /*!< Offset 0x170 BLD_CSC2_COEF00     */
	__IO uint32_t BLD_CSC2_COEF01;                       /*!< Offset 0x174 BLD_CSC2_COEF01     */
	__IO uint32_t BLD_CSC2_COEF02;                       /*!< Offset 0x178 BLD_CSC2_COEF02     */
	__IO uint32_t BLD_CSC2_CONST0;                       /*!< Offset 0x17C BLD_CSC2_CONST0     */
	__IO uint32_t BLD_CSC2_COEF10;                       /*!< Offset 0x180 BLD_CSC2_COEF10     */
	__IO uint32_t BLD_CSC2_COEF11;                       /*!< Offset 0x184 BLD_CSC2_COEF11     */
	__IO uint32_t BLD_CSC2_COEF12;                       /*!< Offset 0x188 BLD_CSC2_COEF12     */
	__IO uint32_t BLD_CSC2_CONST1;                       /*!< Offset 0x18C BLD_CSC2_CONST1     */
	__IO uint32_t BLD_CSC2_COEF20;                       /*!< Offset 0x190 BLD_CSC2_COEF20     */
	__IO uint32_t BLD_CSC2_COEF21;                       /*!< Offset 0x194 BLD_CSC2_COEF21     */
	__IO uint32_t BLD_CSC2_COEF22;                       /*!< Offset 0x198 BLD_CSC2_COEF22     */
	__IO uint32_t BLD_CSC2_CONST2;                       /*!< Offset 0x19C BLD_CSC2_CONST2     */
} G2D_BLD_TypeDef; /* size of structure = 0x1A0 */
/*
 * @brief G2D_WB
 */
/*!< G2D_WB Controller Interface */
typedef struct G2D_WB_Type
{
	__IO uint32_t WB_ATT;                                /*!< Offset 0x000 WB_ATT */
	__IO uint32_t WB_SIZE;                               /*!< Offset 0x004 WB_SIZE */
	__IO uint32_t WB_PITCH0;                             /*!< Offset 0x008 WB_PITCH0 */
	__IO uint32_t WB_PITCH1;                             /*!< Offset 0x00C WB_PITCH1 */
	__IO uint32_t WB_PITCH2;                             /*!< Offset 0x010 WB_PITCH2 */
	__IO uint32_t WB_LADD0;                              /*!< Offset 0x014 WB_LADD0 */
	__IO uint32_t WB_HADD0;                              /*!< Offset 0x018 WB_HADD0 */
	__IO uint32_t WB_LADD1;                              /*!< Offset 0x01C WB_LADD1 */
	__IO uint32_t WB_HADD1;                              /*!< Offset 0x020 WB_HADD1 */
	__IO uint32_t WB_LADD2;                              /*!< Offset 0x024 WB_LADD2 */
	__IO uint32_t WB_HADD2;                              /*!< Offset 0x028 WB_HADD2 */
} G2D_WB_TypeDef; /* size of structure = 0x02C */
/*
 * @brief G2D_ROT
 */
/*!< G2D_ROT Controller Interface */
typedef struct G2D_ROT_Type
{
	__IO uint32_t ROT_CTL;                               /*!< Offset 0x000 ROT_CTL */
	__IO uint32_t ROT_INT;                               /*!< Offset 0x004 ROT_INT */
	__IO uint32_t ROT_TIMEOUT;                           /*!< Offset 0x008 ROT_TIMEOUT */
	uint32_t reserved_0x00C [0x0005];
	__IO uint32_t ROT_IFMT;                              /*!< Offset 0x020 ROT_IFMT */
	__IO uint32_t ROT_ISIZE;                             /*!< Offset 0x024 ROT_ISIZE */
	uint32_t reserved_0x028 [0x0002];
	__IO uint32_t ROT_IPITCH0;                           /*!< Offset 0x030 ROT_IPITCH0 */
	__IO uint32_t ROT_IPITCH1;                           /*!< Offset 0x034 ROT_IPITCH1 */
	__IO uint32_t ROT_IPITCH2;                           /*!< Offset 0x038 ROT_IPITCH2 */
	uint32_t reserved_0x03C;
	__IO uint32_t ROT_ILADD0;                            /*!< Offset 0x040 ROT_ILADD0 */
	__IO uint32_t ROT_IHADD0;                            /*!< Offset 0x044 ROT_IHADD0 */
	__IO uint32_t ROT_ILADD1;                            /*!< Offset 0x048 ROT_ILADD1 */
	__IO uint32_t ROT_IHADD1;                            /*!< Offset 0x04C ROT_IHADD1 */
	__IO uint32_t ROT_ILADD2;                            /*!< Offset 0x050 ROT_ILADD2 */
	__IO uint32_t ROT_IHADD2;                            /*!< Offset 0x054 ROT_IHADD2 */
	uint32_t reserved_0x058 [0x000B];
	__IO uint32_t ROT_OSIZE;                             /*!< Offset 0x084 ROT_OSIZE */
	uint32_t reserved_0x088 [0x0002];
	__IO uint32_t ROT_OPITCH0;                           /*!< Offset 0x090 ROT_OPITCH0 */
	__IO uint32_t ROT_OPITCH1;                           /*!< Offset 0x094 ROT_OPITCH1 */
	__IO uint32_t ROT_OPITCH2;                           /*!< Offset 0x098 ROT_OPITCH2 */
	uint32_t reserved_0x09C;
	__IO uint32_t ROT_OLADD0;                            /*!< Offset 0x0A0 ROT_OLADD0 */
	__IO uint32_t ROT_OHADD0;                            /*!< Offset 0x0A4 ROT_OHADD0 */
	__IO uint32_t ROT_OLADD1;                            /*!< Offset 0x0A8 ROT_OLADD1 */
	__IO uint32_t ROT_OHADD1;                            /*!< Offset 0x0AC ROT_OHADD1 */
	__IO uint32_t ROT_OLADD2;                            /*!< Offset 0x0B0 ROT_OLADD2 */
	__IO uint32_t ROT_OHADD2;                            /*!< Offset 0x0B4 ROT_OHADD2 */
} G2D_ROT_TypeDef; /* size of structure = 0x0B8 */
/*
 * @brief TCON_LCD
 */
/*!< TCON_LCD Controller Interface */
typedef struct TCON_LCD_Type
{
	__IO uint32_t LCD_GCTL_REG;                          /*!< Offset 0x000 LCD Global Control Register */
	__IO uint32_t LCD_GINT0_REG;                         /*!< Offset 0x004 LCD Global Interrupt Register0 */
	__IO uint32_t LCD_GINT1_REG;                         /*!< Offset 0x008 LCD Global Interrupt Register1 */
	uint32_t reserved_0x00C;
	__IO uint32_t LCD_FRM_CTL_REG;                       /*!< Offset 0x010 LCD FRM Control Register */
	__IO uint32_t LCD_FRM_SEED_REG [0x006];              /*!< Offset 0x014 LCD FRM Seed Register (N=0,1,2,3,4,5) */
	__IO uint32_t LCD_FRM_TAB_REG [0x004];               /*!< Offset 0x02C LCD FRM Table Register (N=0,1,2,3) */
	__IO uint32_t LCD_3D_FIFO_REG;                       /*!< Offset 0x03C LCD 3D FIFO Register */
	__IO uint32_t LCD_CTL_REG;                           /*!< Offset 0x040 LCD Control Register */
	__IO uint32_t LCD_DCLK_REG;                          /*!< Offset 0x044 LCD Data Clock Register */
	__IO uint32_t LCD_BASIC0_REG;                        /*!< Offset 0x048 LCD Basic Timing Register0 */
	__IO uint32_t LCD_BASIC1_REG;                        /*!< Offset 0x04C LCD Basic Timing Register1 */
	__IO uint32_t LCD_BASIC2_REG;                        /*!< Offset 0x050 LCD Basic Timing Register2 */
	__IO uint32_t LCD_BASIC3_REG;                        /*!< Offset 0x054 LCD Basic Timing Register3 */
	__IO uint32_t LCD_HV_IF_REG;                         /*!< Offset 0x058 LCD HV Panel Interface Register */
	uint32_t reserved_0x05C;
	__IO uint32_t LCD_CPU_IF_REG;                        /*!< Offset 0x060 LCD CPU Panel Interface Register */
	__IO uint32_t LCD_CPU_WR_REG;                        /*!< Offset 0x064 LCD CPU Panel Write Data Register */
	__IO uint32_t LCD_CPU_RD0_REG;                       /*!< Offset 0x068 LCD CPU Panel Read Data Register0 */
	__IO uint32_t LCD_CPU_RD1_REG;                       /*!< Offset 0x06C LCD CPU Panel Read Data Register1 */
	uint32_t reserved_0x070 [0x0005];
	__IO uint32_t LCD_LVDS_IF_REG;                       /*!< Offset 0x084 LCD LVDS Configure Register */
	__IO uint32_t LCD_IO_POL_REG;                        /*!< Offset 0x088 LCD IO Polarity Register */
	__IO uint32_t LCD_IO_TRI_REG;                        /*!< Offset 0x08C LCD IO Control Register */
	uint32_t reserved_0x090 [0x001B];
	__IO uint32_t LCD_DEBUG_REG;                         /*!< Offset 0x0FC LCD Debug Register */
	__IO uint32_t LCD_CEU_CTL_REG;                       /*!< Offset 0x100 LCD CEU Control Register */
	uint32_t reserved_0x104 [0x0003];
	__IO uint32_t LCD_CEU_COEF_MUL_REG [0x003];          /*!< Offset 0x110 LCD CEU Coefficient Register0 0x0110+N*0x04 (N=0..10) */
	__IO uint32_t LCD_CEU_COEF_ADD_REG [0x003];          /*!< Offset 0x11C LCD CEU Coefficient Register1 0x011C+N*0x10 (N=0,1,2) */
	uint32_t reserved_0x128 [0x0006];
	__IO uint32_t LCD_CEU_COEF_RANG_REG [0x003];         /*!< Offset 0x140 LCD CEU Coefficient Register2 0x0140+N*0x04 (N=0,1,2) */
	uint32_t reserved_0x14C [0x0005];
	__IO uint32_t LCD_CPU_TRI0_REG;                      /*!< Offset 0x160 LCD CPU Panel Trigger Register0 */
	__IO uint32_t LCD_CPU_TRI1_REG;                      /*!< Offset 0x164 LCD CPU Panel Trigger Register1 */
	__IO uint32_t LCD_CPU_TRI2_REG;                      /*!< Offset 0x168 LCD CPU Panel Trigger Register2 */
	__IO uint32_t LCD_CPU_TRI3_REG;                      /*!< Offset 0x16C LCD CPU Panel Trigger Register3 */
	__IO uint32_t LCD_CPU_TRI4_REG;                      /*!< Offset 0x170 LCD CPU Panel Trigger Register4 */
	__IO uint32_t LCD_CPU_TRI5_REG;                      /*!< Offset 0x174 LCD CPU Panel Trigger Register5 */
	uint32_t reserved_0x178 [0x0002];
	__IO uint32_t LCD_CMAP_CTL_REG;                      /*!< Offset 0x180 LCD Color Map Control Register */
	uint32_t reserved_0x184 [0x0003];
	__IO uint32_t LCD_CMAP_ODD0_REG;                     /*!< Offset 0x190 LCD Color Map Odd Line Register0 */
	__IO uint32_t LCD_CMAP_ODD1_REG;                     /*!< Offset 0x194 LCD Color Map Odd Line Register1 */
	__IO uint32_t LCD_CMAP_EVEN0_REG;                    /*!< Offset 0x198 LCD Color Map Even Line Register0 */
	__IO uint32_t LCD_CMAP_EVEN1_REG;                    /*!< Offset 0x19C LCD Color Map Even Line Register1 */
	uint32_t reserved_0x1A0 [0x0014];
	__IO uint32_t LCD_SAFE_PERIOD_REG;                   /*!< Offset 0x1F0 LCD Safe Period Register */
	uint32_t reserved_0x1F4 [0x000B];
	__IO uint32_t LCD_LVDS0_ANA_REG;                     /*!< Offset 0x220 LCD LVDS Analog Register 0 */
	__IO uint32_t LCD_LVDS1_ANA_REG;                     /*!< Offset 0x224 LCD LVDS Analog Register 1 */
	uint32_t reserved_0x228 [0x0002];
	__IO uint32_t LCD_SYNC_CTL_REG;                      /*!< Offset 0x230 LCD Sync Control Register */
	__IO uint32_t LCD_SYNC_POS_REG;                      /*!< Offset 0x234 LCD Sync Position Register */
	__IO uint32_t LCD_SLAVE_STOP_POS_REG;                /*!< Offset 0x238 LCD Slave Stop Position Register */
	uint32_t reserved_0x23C [0x0071];
	__IO uint32_t LCD_GAMMA_TABLE_REG [0x100];           /*!< Offset 0x400 LCD Gamma Table Register */
} TCON_LCD_TypeDef; /* size of structure = 0x800 */
/*
 * @brief TVE_TOP
 */
/*!< TVE_TOP Controller Interface */
typedef struct TVE_TOP_Type
{
	uint32_t reserved_0x000 [0x0008];
	__IO uint32_t TVE_DAC_MAP;                           /*!< Offset 0x020 TV Encoder DAC MAP Register */
	__IO uint32_t TVE_DAC_STATUS;                        /*!< Offset 0x024 TV Encoder DAC STAUTS Register */
	__IO uint32_t TVE_DAC_CFG0;                          /*!< Offset 0x028 TV Encoder DAC CFG0 Register */
	__IO uint32_t TVE_DAC_CFG1;                          /*!< Offset 0x02C TV Encoder DAC CFG1 Register */
	__IO uint32_t TVE_DAC_CFG2;                          /*!< Offset 0x030 TV Encoder DAC CFG2 Register */
	__IO uint32_t TVE_DAC_CFG3;                          /*!< Offset 0x034 TV Encoder DAC CFG2 Register */
	uint32_t reserved_0x038 [0x002E];
	__IO uint32_t TVE_DAC_TEST;                          /*!< Offset 0x0F0 TV Encoder DAC TEST Register */
} TVE_TOP_TypeDef; /* size of structure = 0x0F4 */
/*
 * @brief TVE
 */
/*!< TVE Controller Interface */
typedef struct TVE_Type
{
	__IO uint32_t TVE_000_REG;                           /*!< Offset 0x000 TV Encoder Clock Gating Register */
	__IO uint32_t TVE_004_REG;                           /*!< Offset 0x004 TV Encoder Configuration Register */
	__IO uint32_t TVE_008_REG;                           /*!< Offset 0x008 TV Encoder DAC Register1 */
	__IO uint32_t TVE_00C_REG;                           /*!< Offset 0x00C TV Encoder Notch and DAC Delay Register */
	__IO uint32_t TVE_010_REG;                           /*!< Offset 0x010 TV Encoder Chroma Frequency Register */
	__IO uint32_t TVE_014_REG;                           /*!< Offset 0x014 TV Encoder Front/Back Porch Register */
	__IO uint32_t TVE_018_REG;                           /*!< Offset 0x018 TV Encoder HD Mode VSYNC Register */
	__IO uint32_t TVE_01C_REG;                           /*!< Offset 0x01C TV Encoder Line Number Register */
	__IO uint32_t TVE_020_REG;                           /*!< Offset 0x020 TV Encoder Level Register */
	__IO uint32_t TVE_024_REG;                           /*!< Offset 0x024 TV Encoder DAC Register2 */
	uint32_t reserved_0x028 [0x0002];
	__IO uint32_t TVE_030_REG;                           /*!< Offset 0x030 TV Encoder Auto Detection Enable Register */
	__IO uint32_t TVE_034_REG;                           /*!< Offset 0x034 TV Encoder Auto Detection Interrupt Status Register */
	__IO uint32_t TVE_038_REG;                           /*!< Offset 0x038 TV Encoder Auto Detection Status Register */
	__IO uint32_t TVE_03C_REG;                           /*!< Offset 0x03C TV Encoder Auto Detection De-bounce Setting Register */
	uint32_t reserved_0x040 [0x002E];
	__IO uint32_t TVE_0F8_REG;                           /*!< Offset 0x0F8 TV Encoder Auto Detect Configuration Register0 */
	__IO uint32_t TVE_0FC_REG;                           /*!< Offset 0x0FC TV Encoder Auto Detect Configuration Register1 */
	__IO uint32_t TVE_100_REG;                           /*!< Offset 0x100 TV Encoder Color Burst Phase Reset Configuration Register */
	__IO uint32_t TVE_104_REG;                           /*!< Offset 0x104 TV Encoder VSYNC Number Register */
	__IO uint32_t TVE_108_REG;                           /*!< Offset 0x108 TV Encoder Notch Filter Frequency Register */
	__IO uint32_t TVE_10C_REG;                           /*!< Offset 0x10C TV Encoder Cb/Cr Level/Gain Register */
	__IO uint32_t TVE_110_REG;                           /*!< Offset 0x110 TV Encoder Tint and Color Burst Phase Register */
	__IO uint32_t TVE_114_REG;                           /*!< Offset 0x114 TV Encoder Burst Width Register */
	__IO uint32_t TVE_118_REG;                           /*!< Offset 0x118 TV Encoder Cb/Cr Gain Register */
	__IO uint32_t TVE_11C_REG;                           /*!< Offset 0x11C TV Encoder Sync and VBI Level Register */
	__IO uint32_t TVE_120_REG;                           /*!< Offset 0x120 TV Encoder White Level Register */
	__IO uint32_t TVE_124_REG;                           /*!< Offset 0x124 TV Encoder Video Active Line Register */
	__IO uint32_t TVE_128_REG;                           /*!< Offset 0x128 TV Encoder Video Chroma BW and CompGain Register */
	__IO uint32_t TVE_12C_REG;                           /*!< Offset 0x12C TV Encoder Register */
	__IO uint32_t TVE_130_REG;                           /*!< Offset 0x130 TV Encoder Re-sync Parameters Register */
	__IO uint32_t TVE_134_REG;                           /*!< Offset 0x134 TV Encoder Slave Parameter Register */
	__IO uint32_t TVE_138_REG;                           /*!< Offset 0x138 TV Encoder Configuration Register0 */
	__IO uint32_t TVE_13C_REG;                           /*!< Offset 0x13C TV Encoder Configuration Register1 */
	uint32_t reserved_0x140 [0x0090];
	__IO uint32_t TVE_380_REG;                           /*!< Offset 0x380 TV Encoder Low Pass Control Register */
	__IO uint32_t TVE_384_REG;                           /*!< Offset 0x384 TV Encoder Low Pass Filter Control Register */
	__IO uint32_t TVE_388_REG;                           /*!< Offset 0x388 TV Encoder Low Pass Gain Register */
	__IO uint32_t TVE_38C_REG;                           /*!< Offset 0x38C TV Encoder Low Pass Gain Control Register */
	__IO uint32_t TVE_390_REG;                           /*!< Offset 0x390 TV Encoder Low Pass Shoot Control Register */
	__IO uint32_t TVE_394_REG;                           /*!< Offset 0x394 TV Encoder Low Pass Coring Register */
	uint32_t reserved_0x398 [0x0002];
	__IO uint32_t TVE_3A0_REG;                           /*!< Offset 0x3A0 TV Encoder Noise Reduction Register */
} TVE_TypeDef; /* size of structure = 0x3A4 */
/*
 * @brief CSIC_CCU
 */
/*!< CSIC_CCU Controller Interface */
typedef struct CSIC_CCU_Type
{
	__IO uint32_t CCU_CLK_MODE_REG;                      /*!< Offset 0x000 CCU Clock Mode Register */
	__IO uint32_t CCU_PARSER_CLK_EN_REG;                 /*!< Offset 0x004 CCU Parser Clock Enable Register */
	uint32_t reserved_0x008;
	__IO uint32_t CCU_POST0_CLK_EN_REG;                  /*!< Offset 0x00C CCU Post0 Clock Enable Register */
} CSIC_CCU_TypeDef; /* size of structure = 0x010 */
/*
 * @brief CSIC_TOP
 */
/*!< CSIC_TOP Controller Interface */
typedef struct CSIC_TOP_Type
{
	__IO uint32_t CSIC_TOP_EN_REG;                       /*!< Offset 0x000 CSIC TOP Enable Register */
	__IO uint32_t CSIC_PTN_GEN_EN_REG;                   /*!< Offset 0x004 CSIC Pattern Generation Enable Register */
	__IO uint32_t CSIC_PTN_CTRL_REG;                     /*!< Offset 0x008 CSIC Pattern Control Register */
	uint32_t reserved_0x00C [0x0005];
	__IO uint32_t CSIC_PTN_LEN_REG;                      /*!< Offset 0x020 CSIC Pattern Generation Length Register */
	__IO uint32_t CSIC_PTN_ADDR_REG;                     /*!< Offset 0x024 CSIC Pattern Generation Address Register */
	__IO uint32_t CSIC_PTN_ISP_SIZE_REG;                 /*!< Offset 0x028 CSIC Pattern ISP Size Register */
	uint32_t reserved_0x02C [0x001D];
	__IO uint32_t CSIC_DMA0_INPUT_SEL_REG;               /*!< Offset 0x0A0 CSIC DMA0 Input Select Register */
	__IO uint32_t CSIC_DMA1_INPUT_SEL_REG;               /*!< Offset 0x0A4 CSIC DMA1 Input Select Register */
	uint32_t reserved_0x0A8 [0x000D];
	__IO uint32_t CSIC_BIST_CS_REG;                      /*!< Offset 0x0DC CSIC BIST CS Register */
	__IO uint32_t CSIC_BIST_CONTROL_REG;                 /*!< Offset 0x0E0 CSIC BIST Control Register */
	__IO uint32_t CSIC_BIST_START_REG;                   /*!< Offset 0x0E4 CSIC BIST Start Register */
	__IO uint32_t CSIC_BIST_END_REG;                     /*!< Offset 0x0E8 CSIC BIST End Register */
	__IO uint32_t CSIC_BIST_DATA_MASK_REG;               /*!< Offset 0x0EC CSIC BIST Data Mask Register */
	__IO uint32_t CSIC_MBUS_REQ_MAX_REG;                 /*!< Offset 0x0F0 CSIC MBUS REQ MAX Register */
	uint32_t reserved_0x0F4 [0x0003];
	__IO uint32_t CSIC_MULF_MOD_REG;                     /*!< Offset 0x100 CSIC Multi-Frame Mode Register */
	__IO uint32_t CSIC_MULF_INT_REG;                     /*!< Offset 0x104 CSIC Multi-Frame Interrupt Register */
} CSIC_TOP_TypeDef; /* size of structure = 0x108 */
/*
 * @brief CSIC_PARSER
 */
/*!< CSIC_PARSER Controller Interface */
typedef struct CSIC_PARSER_Type
{
	__IO uint32_t PRS_EN_REG;                            /*!< Offset 0x000 Parser Enable Register */
	__IO uint32_t PRS_NCSIC_IF_CFG_REG;                  /*!< Offset 0x004 Parser NCSIC Interface Configuration Register */
	uint32_t reserved_0x008;
	__IO uint32_t PRS_CAP_REG;                           /*!< Offset 0x00C Parser Capture Register */
	__IO uint32_t CSIC_PRS_SIGNAL_STA_REG;               /*!< Offset 0x010 CSIC Parser Signal Status Register */
	__IO uint32_t CSIC_PRS_NCSIC_BT656_HEAD_CFG_REG;     /*!< Offset 0x014 CSIC Parser NCSIC BT656 Header Configuration Register */
	uint32_t reserved_0x018 [0x0003];
	__IO uint32_t PRS_C0_INFMT_REG;                      /*!< Offset 0x024 Parser Channel_0 Input Format Register */
	__IO uint32_t PRS_C0_OUTPUT_HSIZE_REG;               /*!< Offset 0x028 Parser Channel_0 Output Horizontal Size Register */
	__IO uint32_t PRS_C0_OUTPUT_VSIZE_REG;               /*!< Offset 0x02C Parser Channel_0 Output Vertical Size Register */
	__IO uint32_t PRS_C0_INPUT_PARA0_REG;                /*!< Offset 0x030 Parser Channel_0 Input Parameter0 Register */
	__IO uint32_t PRS_C0_INPUT_PARA1_REG;                /*!< Offset 0x034 Parser Channel_0 Input Parameter1 Register */
	__IO uint32_t PRS_C0_INPUT_PARA2_REG;                /*!< Offset 0x038 Parser Channel_0 Input Parameter2 Register */
	__IO uint32_t PRS_C0_INPUT_PARA3_REG;                /*!< Offset 0x03C Parser Channel_0 Input Parameter3 Register */
	__IO uint32_t PRS_C0_INT_EN_REG;                     /*!< Offset 0x040 Parser Channel_0 Interrupt Enable Register */
	__IO uint32_t PRS_C0_INT_STA_REG;                    /*!< Offset 0x044 Parser Channel_0 Interrupt Status Register */
	__IO uint32_t PRS_CH0_LINE_TIME_REG;                 /*!< Offset 0x048 Parser Channel_0 Line Time Register */
	uint32_t reserved_0x04C [0x0036];
	__IO uint32_t PRS_C1_INFMT_REG;                      /*!< Offset 0x124 Parser Channel_1 Input Format Register */
	__IO uint32_t PRS_C1_OUTPUT_HSIZE_REG;               /*!< Offset 0x128 Parser Channel_1 Output Horizontal Size Register */
	__IO uint32_t PRS_C1_OUTPUT_VSIZE_REG;               /*!< Offset 0x12C Parser Channel_1 Output Vertical Size Register */
	__IO uint32_t PRS_C1_INPUT_PARA0_REG;                /*!< Offset 0x130 Parser Channel_1 Input Parameter0 Register */
	__IO uint32_t PRS_C1_INPUT_PARA1_REG;                /*!< Offset 0x134 Parser Channel_1 Input Parameter1 Register */
	__IO uint32_t PRS_C1_INPUT_PARA2_REG;                /*!< Offset 0x138 Parser Channel_1 Input Parameter2 Register */
	__IO uint32_t PRS_C1_INPUT_PARA3_REG;                /*!< Offset 0x13C Parser Channel_1 Input Parameter3 Register */
	__IO uint32_t PRS_C1_INT_EN_REG;                     /*!< Offset 0x140 Parser Channel_1 Interrupt Enable Register */
	__IO uint32_t PRS_C1_INT_STA_REG;                    /*!< Offset 0x144 Parser Channel_1 Interrupt Status Register */
	__IO uint32_t PRS_CH1_LINE_TIME_REG;                 /*!< Offset 0x148 Parser Channel_1 Line Time Register */
	uint32_t reserved_0x14C [0x0036];
	__IO uint32_t PRS_C2_INFMT_REG;                      /*!< Offset 0x224 Parser Channel_2 Input Format Register */
	__IO uint32_t PRS_C2_OUTPUT_HSIZE_REG;               /*!< Offset 0x228 Parser Channel_2 Output Horizontal Size Register */
	__IO uint32_t PRS_C2_OUTPUT_VSIZE_REG;               /*!< Offset 0x22C Parser Channel_2 Output Vertical Size Register */
	__IO uint32_t PRS_C2_INPUT_PARA0_REG;                /*!< Offset 0x230 Parser Channel_2 Input Parameter0 Register */
	__IO uint32_t PRS_C2_INPUT_PARA1_REG;                /*!< Offset 0x234 Parser Channel_2 Input Parameter1 Register */
	__IO uint32_t PRS_C2_INPUT_PARA2_REG;                /*!< Offset 0x238 Parser Channel_2 Input Parameter2 Register */
	__IO uint32_t PRS_C2_INPUT_PARA3_REG;                /*!< Offset 0x23C Parser Channel_2 Input Parameter3 Register */
	__IO uint32_t PRS_C2_INT_EN_REG;                     /*!< Offset 0x240 Parser Channel_2 Interrupt Enable Register */
	__IO uint32_t PRS_C2_INT_STA_REG;                    /*!< Offset 0x244 Parser Channel_2 Interrupt Status Register */
	__IO uint32_t PRS_CH2_LINE_TIME_REG;                 /*!< Offset 0x248 Parser Channel_2 Line Time Register */
	uint32_t reserved_0x24C [0x0036];
	__IO uint32_t PRS_C3_INFMT_REG;                      /*!< Offset 0x324 Parser Channel_3 Input Format Register */
	__IO uint32_t PRS_C3_OUTPUT_HSIZE_REG;               /*!< Offset 0x328 Parser Channel_3 Output Horizontal Size Register */
	__IO uint32_t PRS_C3_OUTPUT_VSIZE_REG;               /*!< Offset 0x32C Parser Channel_3 Output Vertical Size Register */
	__IO uint32_t PRS_C3_INPUT_PARA0_REG;                /*!< Offset 0x330 Parser Channel_3 Input Parameter0 Register */
	__IO uint32_t PRS_C3_INPUT_PARA1_REG;                /*!< Offset 0x334 Parser Channel_3 Input Parameter1 Register */
	__IO uint32_t PRS_C3_INPUT_PARA2_REG;                /*!< Offset 0x338 Parser Channel_3 Input Parameter2 Register */
	__IO uint32_t PRS_C3_INPUT_PARA3_REG;                /*!< Offset 0x33C Parser Channel_3 Input Parameter3 Register */
	__IO uint32_t PRS_C3_INT_EN_REG;                     /*!< Offset 0x340 Parser Channel_3 Interrupt Enable Register */
	__IO uint32_t PRS_C3_INT_STA_REG;                    /*!< Offset 0x344 Parser Channel_3 Interrupt Status Register */
	__IO uint32_t PRS_CH3_LINE_TIME_REG;                 /*!< Offset 0x348 Parser Channel_3 Line Time Register */
	uint32_t reserved_0x34C [0x006D];
	__IO uint32_t CSIC_PRS_NCSIC_RX_SIGNAL0_DLY_ADJ_REG; /*!< Offset 0x500 CSIC Parser NCSIC RX Signal0 Delay Adjust Register */
	uint32_t reserved_0x504 [0x0004];
	__IO uint32_t CSIC_PRS_NCSIC_RX_SIGNAL5_DLY_ADJ_REG; /*!< Offset 0x514 CSIC Parser NCSIC RX Signal5 Delay Adjust Register */
	__IO uint32_t CSIC_PRS_NCSIC_RX_SIGNAL6_DLY_ADJ_REG; /*!< Offset 0x518 CSIC Parser NCSIC RX Signal6 Delay Adjust Register */
} CSIC_PARSER_TypeDef; /* size of structure = 0x51C */
/*
 * @brief CSIC_DMA
 */
/*!< CSIC_DMA Controller Interface */
typedef struct CSIC_DMA_Type
{
	__IO uint32_t CSIC_DMA_EN_REG;                       /*!< Offset 0x000 CSIC DMA Enable Register */
	__IO uint32_t CSIC_DMA_CFG_REG;                      /*!< Offset 0x004 CSIC DMA Configuration Register */
	uint32_t reserved_0x008 [0x0002];
	__IO uint32_t CSIC_DMA_HSIZE_REG;                    /*!< Offset 0x010 CSIC DMA Horizontal Size Register */
	__IO uint32_t CSIC_DMA_VSIZE_REG;                    /*!< Offset 0x014 CSIC DMA Vertical Size Register */
	uint32_t reserved_0x018 [0x0002];
	__IO uint32_t CSIC_DMA_F0_BUFA_REG;                  /*!< Offset 0x020 CSIC DMA FIFO 0 Output Buffer-A Address Register */
	__IO uint32_t CSIC_DMA_F0_BUFA_RESULT_REG;           /*!< Offset 0x024 CSIC DMA FIFO 0 Output Buffer-A Address Result Register */
	__IO uint32_t CSIC_DMA_F1_BUFA_REG;                  /*!< Offset 0x028 CSIC DMA FIFO 1 Output Buffer-A Address Register */
	__IO uint32_t CSIC_DMA_F1_BUFA_RESULT_REG;           /*!< Offset 0x02C CSIC DMA FIFO 1 Output Buffer-A Address Result Register */
	__IO uint32_t CSIC_DMA_F2_BUFA_REG;                  /*!< Offset 0x030 CSIC DMA FIFO 2 Output Buffer-A Address Register */
	__IO uint32_t CSIC_DMA_F2_BUFA_RESULT_REG;           /*!< Offset 0x034 CSIC DMA FIFO 2 Output Buffer-A Address Result Register */
	__IO uint32_t CSIC_DMA_BUF_LEN_REG;                  /*!< Offset 0x038 CSIC DMA Buffer Length Register */
	__IO uint32_t CSIC_DMA_FLIP_SIZE_REG;                /*!< Offset 0x03C CSIC DMA Flip Size Register */
	__IO uint32_t CSIC_DMA_VI_TO_TH0_REG;                /*!< Offset 0x040 CSIC DMA Video Input Timeout Threshold0 Register */
	__IO uint32_t CSIC_DMA_VI_TO_TH1_REG;                /*!< Offset 0x044 CSIC DMA Video Input Timeout Threshold1 Register */
	__IO uint32_t CSIC_DMA_VI_TO_CNT_VAL_REG;            /*!< Offset 0x048 CSIC DMA Video Input Timeout Counter Value Register */
	__IO uint32_t CSIC_DMA_CAP_STA_REG;                  /*!< Offset 0x04C CSIC DMA Capture Status Register */
	__IO uint32_t CSIC_DMA_INT_EN_REG;                   /*!< Offset 0x050 CSIC DMA Interrupt Enable Register */
	__IO uint32_t CSIC_DMA_INT_STA_REG;                  /*!< Offset 0x054 CSIC DMA Interrupt Status Register */
	__IO uint32_t CSIC_DMA_LINE_CNT_REG;                 /*!< Offset 0x058 CSIC DMA LINE Counter Register */
	__IO uint32_t CSIC_DMA_FRM_CNT_REG;                  /*!< Offset 0x05C CSIC DMA Frame Counter Register */
	__IO uint32_t CSIC_DMA_FRM_CLK_CNT_REG;              /*!< Offset 0x060 CSIC DMA Frame Clock Counter Register */
	__IO uint32_t CSIC_DMA_ACC_ITNL_CLK_CNT_REG;         /*!< Offset 0x064 CSIC DMA Accumulated And Internal Clock Counter Register */
	__IO uint32_t CSIC_DMA_FIFO_STAT_REG;                /*!< Offset 0x068 CSIC DMA FIFO Statistic Register */
	__IO uint32_t CSIC_DMA_FIFO_THRS_REG;                /*!< Offset 0x06C CSIC DMA FIFO Threshold Register */
	__IO uint32_t CSIC_DMA_PCLK_STAT_REG;                /*!< Offset 0x070 CSIC DMA PCLK Statistic Register */
	uint32_t reserved_0x074 [0x0003];
	__IO uint32_t CSIC_DMA_BUF_ADDR_FIFO0_ENTRY_REG;     /*!< Offset 0x080 CSIC DMA BUF Address FIFO0 Entry Register */
	__IO uint32_t CSIC_DMA_BUF_ADDR_FIFO1_ENTRY_REG;     /*!< Offset 0x084 CSIC DMA BUF Address FIFO1 Entry Register */
	__IO uint32_t CSIC_DMA_BUF_ADDR_FIFO2_ENTRY_REG;     /*!< Offset 0x088 CSIC DMA BUF Address FIFO2 Entry Register */
	__IO uint32_t CSIC_DMA_BUF_TH_REG;                   /*!< Offset 0x08C CSIC DMA BUF Threshold Register */
	__IO uint32_t CSIC_DMA_BUF_ADDR_FIFO_CON_REG;        /*!< Offset 0x090 CSIC DMA BUF Address FIFO Content Register */
	__IO uint32_t CSIC_DMA_STORED_FRM_CNT_REG;           /*!< Offset 0x094 CSIC DMA Stored Frame Counter Register */
	uint32_t reserved_0x098 [0x0057];
	__IO uint32_t CSIC_FEATURE_REG;                      /*!< Offset 0x1F4 CSIC DMA Feature List Register */
} CSIC_DMA_TypeDef; /* size of structure = 0x1F8 */
/*
 * @brief TVD_ADC
 */
/*!< TVD_ADC Controller Interface */
typedef struct TVD_ADC_Type
{
	uint32_t reserved_0x000;
	__IO uint32_t TVD_TOP_CTL;                           /*!< Offset 0x004 TVD TOP CONTROL Register */
	__IO uint32_t TVD_ADC_CTL;                           /*!< Offset 0x008 TVD ADC CONTROL Register */
	__IO uint32_t TVD_ADC_CFG;                           /*!< Offset 0x00C TVD ADC CONFIGURATION Register */
	uint32_t reserved_0x010 [0x0004];
} TVD_ADC_TypeDef; /* size of structure = 0x020 */
/*
 * @brief TVD_TOP
 */
/*!< TVD_TOP Controller Interface */
typedef struct TVD_TOP_Type
{
	__IO uint32_t TVD_TOP_MAP;                           /*!< Offset 0x000 TVD TOP MAP Register */
	uint32_t reserved_0x004;
	__IO uint32_t TVD_3D_CTL1;                           /*!< Offset 0x008 TVD 3D DMA CONTROL Register1 */
	__IO uint32_t TVD_3D_CTL2;                           /*!< Offset 0x00C TVD 3D DMA CONTROL Register2 */
	__IO uint32_t TVD_3D_CTL3;                           /*!< Offset 0x010 TVD 3D DMA CONTROL Register3 */
	__IO uint32_t TVD_3D_CTL4;                           /*!< Offset 0x014 TVD 3D DMA CONTROL Register4 */
	__IO uint32_t TVD_3D_CTL5;                           /*!< Offset 0x018 TVD 3D DMA CONTROL Register5 */
	uint32_t reserved_0x01C;
	TVD_ADC_TypeDef TVD_ADC [0x004];                     /*!< Offset 0x020 TVD ADC Registers N (N = 0 to 3) */
} TVD_TOP_TypeDef; /* size of structure = 0x0A0 */
/*
 * @brief TVD
 */
/*!< TVD Controller Interface */
typedef struct TVD_Type
{
	__IO uint32_t TVD_EN;                                /*!< Offset 0x000 TVD MODULE CONTROL Register */
	__IO uint32_t TVD_MODE;                              /*!< Offset 0x004 TVD MODE CONTROL Register */
	__IO uint32_t TVD_CLAMP_AGC1;                        /*!< Offset 0x008 TVD CLAMP & AGC CONTROL Register1 */
	__IO uint32_t TVD_CLAMP_AGC2;                        /*!< Offset 0x00C TVD CLAMP & AGC CONTROL Register2 */
	__IO uint32_t TVD_HLOCK1;                            /*!< Offset 0x010 TVD HLOCK CONTROL Register1 */
	__IO uint32_t TVD_HLOCK2;                            /*!< Offset 0x014 TVD HLOCK CONTROL Register2 */
	__IO uint32_t TVD_HLOCK3;                            /*!< Offset 0x018 TVD HLOCK CONTROL Register3 */
	__IO uint32_t TVD_HLOCK4;                            /*!< Offset 0x01C TVD HLOCK CONTROL Register4 */
	__IO uint32_t TVD_HLOCK5;                            /*!< Offset 0x020 TVD HLOCK CONTROL Register5 */
	__IO uint32_t TVD_VLOCK1;                            /*!< Offset 0x024 TVD VLOCK CONTROL Register1 */
	__IO uint32_t TVD_VLOCK2;                            /*!< Offset 0x028 TVD VLOCK CONTROL Register2 */
	uint32_t reserved_0x02C;
	__IO uint32_t TVD_CLOCK1;                            /*!< Offset 0x030 TVD CHROMA LOCK CONTROL Register1 */
	__IO uint32_t TVD_CLOCK2;                            /*!< Offset 0x034 TVD CHROMA LOCK CONTROL Register2 */
	uint32_t reserved_0x038 [0x0002];
	__IO uint32_t TVD_YC_SEP1;                           /*!< Offset 0x040 TVD YC SEPERATION CONROL Register1 */
	__IO uint32_t TVD_YC_SEP2;                           /*!< Offset 0x044 TVD YC SEPERATION CONROL Register2 */
	uint32_t reserved_0x048 [0x0002];
	__IO uint32_t TVD_ENHANCE1;                          /*!< Offset 0x050 TVD ENHANCEMENT CONTROL Register1 */
	__IO uint32_t TVD_ENHANCE2;                          /*!< Offset 0x054 TVD ENHANCEMENT CONTROL Register2 */
	__IO uint32_t TVD_ENHANCE3;                          /*!< Offset 0x058 TVD ENHANCEMENT CONTROL Register3 */
	uint32_t reserved_0x05C;
	__IO uint32_t TVD_WB1;                               /*!< Offset 0x060 TVD WB DMA CONTROL Register1 */
	__IO uint32_t TVD_WB2;                               /*!< Offset 0x064 TVD WB DMA CONTROL Register2 */
	__IO uint32_t TVD_WB3;                               /*!< Offset 0x068 TVD WB DMA CONTROL Register3 */
	__IO uint32_t TVD_WB4;                               /*!< Offset 0x06C TVD WB DMA CONTROL Register4 */
	uint32_t reserved_0x070 [0x0004];
	__IO uint32_t TVD_IRQ_CTL;                           /*!< Offset 0x080 TVD DMA Interrupt Control Register */
	uint32_t reserved_0x084 [0x0003];
	__IO uint32_t TVD_IRQ_STATUS;                        /*!< Offset 0x090 TVD DMA Interrupt Status Register */
	uint32_t reserved_0x094 [0x001B];
	__IO uint32_t TVD_DEBUG1;                            /*!< Offset 0x100 TVD DEBUG CONTROL Register1 */
	uint32_t reserved_0x104 [0x001F];
	__IO uint32_t TVD_STATUS1;                           /*!< Offset 0x180 TVD DEBUG STATUS Register1 */
	__IO uint32_t TVD_STATUS2;                           /*!< Offset 0x184 TVD DEBUG STATUS Register2 */
	__IO uint32_t TVD_STATUS3;                           /*!< Offset 0x188 TVD DEBUG STATUS Register3 */
	__IO uint32_t TVD_STATUS4;                           /*!< Offset 0x18C TVD DEBUG STATUS Register4 */
	__IO uint32_t TVD_STATUS5;                           /*!< Offset 0x190 TVD DEBUG STATUS Register5 */
	__IO uint32_t TVD_STATUS6;                           /*!< Offset 0x194 TVD DEBUG STATUS Register6 */
} TVD_TypeDef; /* size of structure = 0x198 */
/*
 * @brief DDRPHYC
 */
/*!< DDRPHYC Controller Interface */
typedef struct DDRPHYC_Type
{
	__IO uint32_t PHYC_REG_000;                          /*!< Offset 0x000 Reg_000 */
	__IO uint32_t PHYC_REG_004;                          /*!< Offset 0x004 Reg_004 */
	uint32_t reserved_0x008;
	__IO uint32_t PHYC_REG_00C;                          /*!< Offset 0x00C Reg_00C */
	__IO uint32_t PHYC_REG_010;                          /*!< Offset 0x010 Reg_010 */
	uint32_t reserved_0x014;
	__IO uint32_t PHYC_REG_018;                          /*!< Offset 0x018 Reg_018 */
	uint32_t reserved_0x01C [0x0004];
	__IO uint32_t PHYC_REG_02C;                          /*!< Offset 0x02C Reg_02C */
	__IO uint32_t PHYC_REG_030;                          /*!< Offset 0x030 Reg_030 */
	__IO uint32_t PHYC_REG_034;                          /*!< Offset 0x034 Reg_034 */
	__IO uint32_t PHYC_REG_038;                          /*!< Offset 0x038 Reg_038 */
	__IO uint32_t PHYC_REG_03C;                          /*!< Offset 0x03C Reg_03C */
	uint32_t reserved_0x040 [0x0004];
	__IO uint32_t PHYC_REG_050;                          /*!< Offset 0x050 Reg_050 */
	__IO uint32_t PHYC_REG_054;                          /*!< Offset 0x054 Reg_054 */
	__IO uint32_t PHYC_REG_058;                          /*!< Offset 0x058 Reg_058 */
	__IO uint32_t PHYC_REG_05C;                          /*!< Offset 0x05C Reg_05C */
	__IO uint32_t PHYC_REG_060;                          /*!< Offset 0x060 Reg_060 */
	__IO uint32_t PHYC_REG_064;                          /*!< Offset 0x064 Reg_064 */
	__IO uint32_t PHYC_REG_068;                          /*!< Offset 0x068 Reg_068 */
	__IO uint32_t PHYC_REG_06C;                          /*!< Offset 0x06C Reg_06C */
	uint32_t reserved_0x070 [0x0002];
	__IO uint32_t PHYC_REG_078;                          /*!< Offset 0x078 Reg_078 */
	__IO uint32_t PHYC_REG_07C;                          /*!< Offset 0x07C Reg_07c */
	__IO uint32_t PHYC_REG_080;                          /*!< Offset 0x080 Reg_080 */
	uint32_t reserved_0x084 [0x0002];
	__IO uint32_t PHYC_REG_08C;                          /*!< Offset 0x08C Reg_08C */
	__IO uint32_t PHYC_REG_090;                          /*!< Offset 0x090 Reg_090 */
	__IO uint32_t PHYC_REG_094;                          /*!< Offset 0x094 Reg_094 */
	uint32_t reserved_0x098;
	__IO uint32_t PHYC_REG_09C;                          /*!< Offset 0x09C Reg_09C */
	__IO uint32_t PHYC_REG_0A0;                          /*!< Offset 0x0A0 Reg_0a0 */
	uint32_t reserved_0x0A4 [0x0005];
	__IO uint32_t PHYC_REG_0B8;                          /*!< Offset 0x0B8 Reg_0B8 */
	__IO uint32_t PHYC_REG_0BC;                          /*!< Offset 0x0BC Reg_0BC */
	__IO uint32_t PHYC_REG_0C0;                          /*!< Offset 0x0C0 Reg_0C0 */
	uint32_t reserved_0x0C4 [0x000F];
	__IO uint32_t PHYC_REG_100;                          /*!< Offset 0x100 Reg_100 */
	uint32_t reserved_0x104;
	__IO uint32_t PHYC_REG_108;                          /*!< Offset 0x108 Reg_108 */
	__IO uint32_t PHYC_REG_10C;                          /*!< Offset 0x10C Reg_10C */
	__IO uint32_t PHYC_REG_110;                          /*!< Offset 0x110 Reg_110 */
	__IO uint32_t PHYC_REG_114;                          /*!< Offset 0x114 Reg_114 */
	uint32_t reserved_0x118;
	__IO uint32_t PHYC_REG_11C;                          /*!< Offset 0x11C Reg_11C */
	__IO uint32_t PHYC_REG_120;                          /*!< Offset 0x120 Reg_120 */
	uint32_t reserved_0x124 [0x0007];
	__IO uint32_t PHYC_REG_140;                          /*!< Offset 0x140 Reg_140 */
	uint32_t reserved_0x144 [0x0031];
	__IO uint32_t PHYC_REG_208;                          /*!< Offset 0x208 Reg_208 */
	uint32_t reserved_0x20C [0x0003];
	__IO uint32_t PHYC_REG_218;                          /*!< Offset 0x218 Reg_218 */
	__IO uint32_t PHYC_REG_21C;                          /*!< Offset 0x21C Reg_21C */
	uint32_t reserved_0x220 [0x0002];
	__IO uint32_t PHYC_REG_228 [0x006];                  /*!< Offset 0x228 Reg_228 */
	__IO uint32_t PHYC_REG_240 [0x010];                  /*!< Offset 0x240 Reg_240 */
	__IO uint32_t PHYC_REG_280;                          /*!< Offset 0x280 Reg_280 */
	uint32_t reserved_0x284 [0x0023];
	__IO uint32_t PHYC_REG_310 [0x009];                  /*!< Offset 0x310 Reg_310 Rank 0 */
	__IO uint32_t PHYC_REG_334;                          /*!< Offset 0x334 Reg_334 Rank 0 */
	__IO uint32_t PHYC_REG_338;                          /*!< Offset 0x338 Reg_338 Rank 0 */
	__IO uint32_t PHYC_REG_33C;                          /*!< Offset 0x33C Reg_33C Rank 0 */
	uint32_t reserved_0x340;
	__IO uint32_t PHYC_REG_344;                          /*!< Offset 0x344 Reg_344 Rank 0 */
	__IO uint32_t PHYC_REG_348;                          /*!< Offset 0x348 Reg_348 Rank 0 */
	uint32_t reserved_0x34C [0x0011];
	__IO uint32_t PHYC_REG_390 [0x009];                  /*!< Offset 0x390 Reg_390 */
	__IO uint32_t PHYC_REG_3B4;                          /*!< Offset 0x3B4 Reg_3B4 Rank 1 */
	__IO uint32_t PHYC_REG_3B8;                          /*!< Offset 0x3B8 Reg_3B8 Rank 1 */
	__IO uint32_t PHYC_REG_3BC;                          /*!< Offset 0x3BC Reg_3BC Rank 1 */
	uint32_t reserved_0x3C0;
	__IO uint32_t PHYC_REG_3C4;                          /*!< Offset 0x3C4 Reg_3C4 Rank 1 */
	__IO uint32_t PHYC_REG_3C8;                          /*!< Offset 0x3C8 Reg_3C8 Rank 1 */
} DDRPHYC_TypeDef; /* size of structure = 0x3CC */
/*
 * @brief MSI_MEMC
 */
/*!< MSI_MEMC Controller Interface */
typedef struct MSI_MEMC_Type
{
	__IO uint32_t MEMC_REG_000;                          /*!< Offset 0x000 Reg_000 */
	__IO uint32_t MEMC_REG_004;                          /*!< Offset 0x004 Reg_004 */
	__IO uint32_t MEMC_REG_008;                          /*!< Offset 0x008 Reg_008 */
	__IO uint32_t MEMC_REG_00C;                          /*!< Offset 0x00C Reg_00C */
	uint32_t reserved_0x010 [0x0004];
	__IO uint32_t MEMC_REG_020;                          /*!< Offset 0x020 Reg_020 */
	__IO uint32_t MEMC_REG_024;                          /*!< Offset 0x024 Reg_024 */
	__IO uint32_t MEMC_REG_028;                          /*!< Offset 0x028 Reg_028 */
} MSI_MEMC_TypeDef; /* size of structure = 0x02C */
/*
 * @brief SID
 */
/*!< SID Controller Interface */
typedef struct SID_Type
{
	uint32_t reserved_0x000 [0x0005];
	__IO uint32_t THS;                                   /*!< Offset 0x014 [27:16]: The calibration value of the T-sensor. */
	uint32_t reserved_0x018 [0x007E];
	__IO uint32_t BOOT_MODE;                             /*!< Offset 0x210 [27:16]: eFUSE boot select status, [0]: 0: GPIO boot select, 1: eFuse boot select */
} SID_TypeDef; /* size of structure = 0x214 */
/*
 * @brief USB_EHCI_Capability
 */
/*!< USB_EHCI_Capability Controller Interface */
typedef struct USB_EHCI_Capability_Type
{
	__IO uint32_t HCCAPBASE;                             /*!< Offset 0x000 EHCI Capability Register (HCIVERSION and CAPLENGTH) register */
	__IO uint32_t HCSPARAMS;                             /*!< Offset 0x004 EHCI Host Control Structural Parameter Register */
	__IO uint32_t HCCPARAMS;                             /*!< Offset 0x008 EHCI Host Control Capability Parameter Register */
	__IO uint32_t HCSPPORTROUTE;                         /*!< Offset 0x00C EHCI Companion Port Route Description */
	__IO uint32_t USBCMD;                                /*!< Offset 0x010 EHCI USB Command Register */
	__IO uint32_t USBSTS;                                /*!< Offset 0x014 EHCI USB Status Register */
	__IO uint32_t USBINTR;                               /*!< Offset 0x018 EHCI USB Interrupt Enable Register */
	__IO uint32_t FRINDEX;                               /*!< Offset 0x01C EHCI USB Frame Index Register */
	__IO uint32_t CTRLDSSEGMENT;                         /*!< Offset 0x020 EHCI 4G Segment Selector Register */
	__IO uint32_t PERIODICLISTBASE;                      /*!< Offset 0x024 EHCI Frame List Base Address Register */
	__IO uint32_t ASYNCLISTADDR;                         /*!< Offset 0x028 EHCI Next Asynchronous List Address Register */
} USB_EHCI_Capability_TypeDef; /* size of structure = 0x02C */
/*
 * @brief DMAC_CH
 */
/*!< DMAC_CH Controller Interface */
typedef struct DMAC_CH_Type
{
	__IO uint32_t DMAC_EN_REGN;                          /*!< Offset 0x000 DMAC Channel Enable Register N (N = 0 to 15) 0x0100 + N*0x0040 */
	__IO uint32_t DMAC_PAU_REGN;                         /*!< Offset 0x004 DMAC Channel Pause Register N (N = 0 to 15) 0x0104 + N*0x0040 */
	__IO uint32_t DMAC_DESC_ADDR_REGN;                   /*!< Offset 0x008 DMAC Channel Start Address Register N (N = 0 to 15) 0x0108 + N*0x0040 */
	__IO uint32_t DMAC_CFG_REGN;                         /*!< Offset 0x00C DMAC Channel Configuration Register N (N = 0 to 15) 0x010C + N*0x0040 */
	__IO uint32_t DMAC_CUR_SRC_REGN;                     /*!< Offset 0x010 DMAC Channel Current Source Register N (N = 0 to 15) 0x0110 + N*0x0040 */
	__IO uint32_t DMAC_CUR_DEST_REGN;                    /*!< Offset 0x014 DMAC Channel Current Destination Register N (N = 0 to 15) 0x0114 + N*0x0040 */
	__IO uint32_t DMAC_BCNT_LEFT_REGN;                   /*!< Offset 0x018 DMAC Channel Byte Counter Left Register N (N = 0 to 15) 0x0118 + N*0x0040 */
	__IO uint32_t DMAC_PARA_REGN;                        /*!< Offset 0x01C DMAC Channel Parameter Register N (N = 0 to 15) 0x011C + N*0x0040 */
	uint32_t reserved_0x020 [0x0002];
	__IO uint32_t DMAC_MODE_REGN;                        /*!< Offset 0x028 DMAC Mode Register N (N = 0 to 15) 0x0128 + N*0x0040 */
	__IO uint32_t DMAC_FDESC_ADDR_REGN;                  /*!< Offset 0x02C DMAC Former Descriptor Address Register N (N = 0 to 15) 0x012C + N*0x0040 */
	__IO uint32_t DMAC_PKG_NUM_REGN;                     /*!< Offset 0x030 DMAC Package Number Register N (N = 0 to 15) 0x0130 + N*0x0040 */
	uint32_t reserved_0x034 [0x0003];
} DMAC_CH_TypeDef; /* size of structure = 0x040 */
/*
 * @brief DMAC
 */
/*!< DMAC Controller Interface */
typedef struct DMAC_Type
{
	__IO uint32_t DMAC_IRQ_EN_REG0;                      /*!< Offset 0x000 DMAC IRQ Enable Register 0 */
	__IO uint32_t DMAC_IRQ_EN_REG1;                      /*!< Offset 0x004 DMAC IRQ Enable Register 1 */
	uint32_t reserved_0x008 [0x0002];
	__IO uint32_t DMAC_IRQ_PEND_REG0;                    /*!< Offset 0x010 DMAC IRQ Pending Register 0 */
	__IO uint32_t DMAC_IRQ_PEND_REG1;                    /*!< Offset 0x014 DMAC IRQ Pending Register 1 */
	uint32_t reserved_0x018 [0x0004];
	__IO uint32_t DMAC_AUTO_GATE_REG;                    /*!< Offset 0x028 DMAC Auto Gating Register */
	uint32_t reserved_0x02C;
	__IO uint32_t DMAC_STA_REG;                          /*!< Offset 0x030 DMAC Status Register */
	uint32_t reserved_0x034 [0x0033];
	DMAC_CH_TypeDef CH [0x010];                          /*!< Offset 0x100 Channel [0..15] */
} DMAC_TypeDef; /* size of structure = 0x500 */
/*
 * @brief PWM_CH
 */
/*!< PWM_CH Controller Interface */
typedef struct PWM_CH_Type
{
	__IO uint32_t PCR;                                   /*!< Offset 0x000 PWM Control Register */
	__IO uint32_t PPR;                                   /*!< Offset 0x004 PWM Period Register */
	__IO uint32_t PCNTR;                                 /*!< Offset 0x008 PWM Count Register */
	__IO uint32_t PPCNTR;                                /*!< Offset 0x00C PWM Pulse Count Register */
	__IO uint32_t CCR;                                   /*!< Offset 0x010 Capture Control Register */
	__IO uint32_t CRLR;                                  /*!< Offset 0x014 Capture Rise Lock Register */
	__IO uint32_t CFLR;                                  /*!< Offset 0x018 Capture Fall Lock Register */
	uint32_t reserved_0x01C;
} PWM_CH_TypeDef; /* size of structure = 0x020 */
/*
 * @brief PWM
 */
/*!< PWM Controller Interface */
typedef struct PWM_Type
{
	__IO uint32_t PIER;                                  /*!< Offset 0x000 PWM IRQ Enable Register */
	__IO uint32_t PISR;                                  /*!< Offset 0x004 PWM IRQ Status Register */
	uint32_t reserved_0x008 [0x0002];
	__IO uint32_t CIER;                                  /*!< Offset 0x010 Capture IRQ Enable Register */
	__IO uint32_t CISR;                                  /*!< Offset 0x014 Capture IRQ Status Register */
	uint32_t reserved_0x018 [0x0002];
	__IO uint32_t PCCR [0x004];                          /*!< Offset 0x020 PWM01, PWM23, PWM45, PWM67 Clock Configuration Register */
	uint32_t reserved_0x030 [0x0004];
	__IO uint32_t PCGR;                                  /*!< Offset 0x040 PWM Clock Gating Register */
	uint32_t reserved_0x044 [0x0007];
	__IO uint32_t PDZCR [0x004];                         /*!< Offset 0x060 PWM01, PWM23, PWM45, PWM67 Dead Zone Control Register */
	uint32_t reserved_0x070 [0x0004];
	__IO uint32_t PER;                                   /*!< Offset 0x080 PWM Enable Register */
	uint32_t reserved_0x084 [0x0003];
	__IO uint32_t PGR0 [0x004];                          /*!< Offset 0x090 PWM Group0, Group1, Group2, Group3 Register */
	uint32_t reserved_0x0A0 [0x0008];
	__IO uint32_t CER;                                   /*!< Offset 0x0C0 Capture Enable Register */
	uint32_t reserved_0x0C4 [0x000F];
	PWM_CH_TypeDef CH [0x008];                           /*!< Offset 0x100 Channels[0..7] */
} PWM_TypeDef; /* size of structure = 0x200 */
/*
 * @brief EMAC_ADDR
 */
/*!< EMAC_ADDR Controller Interface */
typedef struct EMAC_ADDR_Type
{
	__IO uint32_t HIGH;                                  /*!< Offset 0x000 EMAC MAC Address High Register */
	__IO uint32_t LOW;                                   /*!< Offset 0x004 EMAC MAC Address Low Register */
} EMAC_ADDR_TypeDef; /* size of structure = 0x008 */
/*
 * @brief EMAC
 */
/*!< EMAC Controller Interface */
typedef struct EMAC_Type
{
	__IO uint32_t EMAC_BASIC_CTL0;                       /*!< Offset 0x000 EMAC Basic Control Register0 */
	__IO uint32_t EMAC_BASIC_CTL1;                       /*!< Offset 0x004 EMAC Basic Control Register1 */
	__IO uint32_t EMAC_INT_STA;                          /*!< Offset 0x008 EMAC Interrupt Status Register */
	__IO uint32_t EMAC_INT_EN;                           /*!< Offset 0x00C EMAC Interrupt Enable Register */
	__IO uint32_t EMAC_TX_CTL0;                          /*!< Offset 0x010 EMAC Transmit Control Register0 */
	__IO uint32_t EMAC_TX_CTL1;                          /*!< Offset 0x014 EMAC Transmit Control Register1 */
	uint32_t reserved_0x018;
	__IO uint32_t EMAC_TX_FLOW_CTL;                      /*!< Offset 0x01C EMAC Transmit Flow Control Register */
	__IO uint32_t EMAC_TX_DMA_DESC_LIST;                 /*!< Offset 0x020 EMAC Transmit Descriptor List Address Register */
	__IO uint32_t EMAC_RX_CTL0;                          /*!< Offset 0x024 EMAC Receive Control Register0 */
	__IO uint32_t EMAC_RX_CTL1;                          /*!< Offset 0x028 EMAC Receive Control Register1 */
	uint32_t reserved_0x02C [0x0002];
	__IO uint32_t EMAC_RX_DMA_DESC_LIST;                 /*!< Offset 0x034 EMAC Receive Descriptor List Address Register */
	__IO uint32_t EMAC_RX_FRM_FLT;                       /*!< Offset 0x038 EMAC Receive Frame Filter Register */
	uint32_t reserved_0x03C;
	__IO uint32_t EMAC_RX_HASH0;                         /*!< Offset 0x040 EMAC Hash Table Register0 */
	__IO uint32_t EMAC_RX_HASH1;                         /*!< Offset 0x044 EMAC Hash Table Register1 */
	__IO uint32_t EMAC_MII_CMD;                          /*!< Offset 0x048 EMAC Management Interface Command Register */
	__IO uint32_t EMAC_MII_DATA;                         /*!< Offset 0x04C EMAC Management Interface Data Register */
	EMAC_ADDR_TypeDef EMAC_ADDR [0x008];                 /*!< Offset 0x050 EMAC MAC Address N (N=0-7) */
	uint32_t reserved_0x090 [0x0008];
	__IO uint32_t EMAC_TX_DMA_STA;                       /*!< Offset 0x0B0 EMAC Transmit DMA Status Register */
	__IO uint32_t EMAC_TX_CUR_DESC;                      /*!< Offset 0x0B4 EMAC Current Transmit Descriptor Register */
	__IO uint32_t EMAC_TX_CUR_BUF;                       /*!< Offset 0x0B8 EMAC Current Transmit Buffer Address Register */
	uint32_t reserved_0x0BC;
	__IO uint32_t EMAC_RX_DMA_STA;                       /*!< Offset 0x0C0 EMAC Receive DMA Status Register */
	__IO uint32_t EMAC_RX_CUR_DESC;                      /*!< Offset 0x0C4 EMAC Current Receive Descriptor Register */
	__IO uint32_t EMAC_RX_CUR_BUF;                       /*!< Offset 0x0C8 EMAC Current Receive Buffer Address Register */
	uint32_t reserved_0x0CC;
	__IO uint32_t EMAC_RGMII_STA;                        /*!< Offset 0x0D0 EMAC RGMII Status Register */
} EMAC_TypeDef; /* size of structure = 0x0D4 */

/* Access pointers */

#define	RISC_CFG	((RISC_CFG_TypeDef *) RISC_CFG_BASE)	/*!< \brief RISC_CFG Interface register set access pointer */
#define	CCU	((CCU_TypeDef *) CCU_BASE)	/*!< \brief CCU Interface register set access pointer */
#define	PLIC	((PLIC_TypeDef *) PLIC_BASE)	/*!< \brief PLIC Interface register set access pointer */
#define	UART0	((UART_TypeDef *) UART0_BASE)	/*!< \brief UART0 Interface register set access pointer */
#define	UART1	((UART_TypeDef *) UART1_BASE)	/*!< \brief UART1 Interface register set access pointer */
#define	UART2	((UART_TypeDef *) UART2_BASE)	/*!< \brief UART2 Interface register set access pointer */
#define	UART3	((UART_TypeDef *) UART3_BASE)	/*!< \brief UART3 Interface register set access pointer */
#define	UART4	((UART_TypeDef *) UART4_BASE)	/*!< \brief UART4 Interface register set access pointer */
#define	UART5	((UART_TypeDef *) UART5_BASE)	/*!< \brief UART5 Interface register set access pointer */
#define	GPIOB	((GPIO_TypeDef *) GPIOB_BASE)	/*!< \brief GPIOB Interface register set access pointer */
#define	GPIOC	((GPIO_TypeDef *) GPIOC_BASE)	/*!< \brief GPIOC Interface register set access pointer */
#define	GPIOD	((GPIO_TypeDef *) GPIOD_BASE)	/*!< \brief GPIOD Interface register set access pointer */
#define	GPIOE	((GPIO_TypeDef *) GPIOE_BASE)	/*!< \brief GPIOE Interface register set access pointer */
#define	GPIOF	((GPIO_TypeDef *) GPIOF_BASE)	/*!< \brief GPIOF Interface register set access pointer */
#define	GPIOG	((GPIO_TypeDef *) GPIOG_BASE)	/*!< \brief GPIOG Interface register set access pointer */
#define	GPIOINTB	((GPIOINT_TypeDef *) GPIOINTB_BASE)	/*!< \brief GPIOINTB Interface register set access pointer */
#define	GPIOINTC	((GPIOINT_TypeDef *) GPIOINTC_BASE)	/*!< \brief GPIOINTC Interface register set access pointer */
#define	GPIOINTD	((GPIOINT_TypeDef *) GPIOINTD_BASE)	/*!< \brief GPIOINTD Interface register set access pointer */
#define	GPIOINTE	((GPIOINT_TypeDef *) GPIOINTE_BASE)	/*!< \brief GPIOINTE Interface register set access pointer */
#define	GPIOINTF	((GPIOINT_TypeDef *) GPIOINTF_BASE)	/*!< \brief GPIOINTF Interface register set access pointer */
#define	GPIOINTG	((GPIOINT_TypeDef *) GPIOINTG_BASE)	/*!< \brief GPIOINTG Interface register set access pointer */
#define	GPIOBLOCK	((GPIOBLOCK_TypeDef *) GPIOBLOCK_BASE)	/*!< \brief GPIOBLOCK Interface register set access pointer */
#define	SMHC0	((SMHC_TypeDef *) SMHC0_BASE)	/*!< \brief SMHC0 Interface register set access pointer */
#define	SMHC1	((SMHC_TypeDef *) SMHC1_BASE)	/*!< \brief SMHC1 Interface register set access pointer */
#define	SMHC2	((SMHC_TypeDef *) SMHC2_BASE)	/*!< \brief SMHC2 Interface register set access pointer */
#define	OWA	((OWA_TypeDef *) OWA_BASE)	/*!< \brief OWA Interface register set access pointer */
#define	AUDIO_CODEC	((AUDIO_CODEC_TypeDef *) AUDIO_CODEC_BASE)	/*!< \brief AUDIO_CODEC Interface register set access pointer */
#define	TWI0	((TWI_TypeDef *) TWI0_BASE)	/*!< \brief TWI0 Interface register set access pointer */
#define	TWI1	((TWI_TypeDef *) TWI1_BASE)	/*!< \brief TWI1 Interface register set access pointer */
#define	TWI2	((TWI_TypeDef *) TWI2_BASE)	/*!< \brief TWI2 Interface register set access pointer */
#define	TWI3	((TWI_TypeDef *) TWI3_BASE)	/*!< \brief TWI3 Interface register set access pointer */
#define	CAN0	((CAN_TypeDef *) CAN0_BASE)	/*!< \brief CAN0 Interface register set access pointer */
#define	CAN1	((CAN_TypeDef *) CAN1_BASE)	/*!< \brief CAN1 Interface register set access pointer */
#define	DDRPHYC	((DDRPHYC_TypeDef *) DDRPHYC_BASE)	/*!< \brief DDRPHYC Interface register set access pointer */
#ifdef PRINTF
/* Print RISC_CFG */
static void RISC_CFG_Type_print(const RISC_CFG_TypeDef * p)
{
	PRINTF("%s->RISC_STA_ADD0_REG=0x%08X\n", p);	/*!< Offset 0x004 RISC Start Address0 Register */
	PRINTF("%s->RISC_STA_ADD1_REG=0x%08X\n", p);	/*!< Offset 0x008 RISC Start Address1 Register */
	PRINTF("%s->RF1P_CFG_REG=0x%08X\n", p);	/*!< Offset 0x010 RF1P Configuration Register */
	PRINTF("%s->ROM_CFG_REG=0x%08X\n", p);	/*!< Offset 0x01C ROM Configuration Register */
	PRINTF("%s->WAKEUP_EN_REG=0x%08X\n", p);	/*!< Offset 0x020 Wakeup Enable Register */
	PRINTF("%s->WAKEUP_MASK0_REG=0x%08X\n", p);	/*!< Offset 0x024 Wakeup Mask0 Register */
	PRINTF("%s->WAKEUP_MASK1_REG=0x%08X\n", p);	/*!< Offset 0x028 Wakeup Mask1 Register */
	PRINTF("%s->WAKEUP_MASK2_REG=0x%08X\n", p);	/*!< Offset 0x02C Wakeup Mask2 Register */
	PRINTF("%s->WAKEUP_MASK3_REG=0x%08X\n", p);	/*!< Offset 0x030 Wakeup Mask3 Register */
	PRINTF("%s->WAKEUP_MASK4_REG=0x%08X\n", p);	/*!< Offset 0x034 Wakeup Mask4 Register */
	PRINTF("%s->TS_TMODE_SEL_REG=0x%08X\n", p);	/*!< Offset 0x040 Timestamp Test Mode Select Register */
	PRINTF("%s->SRAM_ADDR_TWIST_REG=0x%08X\n", p);	/*!< Offset 0x044 SRAM Address Twist Register */
	PRINTF("%s->WORK_MODE_REG=0x%08X\n", p);	/*!< Offset 0x048 Work Mode Register */
	PRINTF("%s->RETITE_PC0_REG=0x%08X\n", p);	/*!< Offset 0x050 Retire PC0 Register */
	PRINTF("%s->RETITE_PC1_REG=0x%08X\n", p);	/*!< Offset 0x054 Retire PC1 Register */
	PRINTF("%s->IRQ_MODE0_REG=0x%08X\n", p);	/*!< Offset 0x060 IRQ Mode0 Register */
	PRINTF("%s->IRQ_MODE1_REG=0x%08X\n", p);	/*!< Offset 0x064 IRQ Mode1 Register */
	PRINTF("%s->IRQ_MODE2_REG=0x%08X\n", p);	/*!< Offset 0x068 IRQ Mode2 Register */
	PRINTF("%s->IRQ_MODE3_REG=0x%08X\n", p);	/*!< Offset 0x06C IRQ Mode3 Register */
	PRINTF("%s->IRQ_MODE4_REG=0x%08X\n", p);	/*!< Offset 0x070 IRQ Mode4 Register */
	PRINTF("%s->RISC_AXI_PMU_CTRL=0x%08X\n", p);	/*!< Offset 0x104 RISC AXI PMU Control Register */
	PRINTF("%s->RISC_AXI_PMU_PRD=0x%08X\n", p);	/*!< Offset 0x108 RISC AXI PMU Period Register */
	PRINTF("%s->RISC_AXI_PMU_LAT_RD=0x%08X\n", p);	/*!< Offset 0x10C RISC AXI PMU Read Latency Register */
	PRINTF("%s->RISC_AXI_PMU_LAT_WR=0x%08X\n", p);	/*!< Offset 0x110 RISC AXI PMU Write Latency Register */
	PRINTF("%s->RISC_AXI_PMU_REQ_RD=0x%08X\n", p);	/*!< Offset 0x114 RISC AXI PMU Read Request Register */
	PRINTF("%s->RISC_AXI_PMU_REQ_WR=0x%08X\n", p);	/*!< Offset 0x118 RISC AXI PMU Write Request Register */
	PRINTF("%s->RISC_AXI_PMU_BW_RD=0x%08X\n", p);	/*!< Offset 0x11C RISC AXI PMU Read Bandwidth Register */
	PRINTF("%s->RISC_AXI_PMU_BW_WR=0x%08X\n", p);	/*!< Offset 0x120 RISC AXI PMU Write Bandwidth Register */
}
/* Print CCU */
static void CCU_Type_print(const CCU_TypeDef * p)
{
	PRINTF("%s->PLL_CPU_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x000 PLL_CPU Control Register */
	PRINTF("%s->PLL_DDR_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x010 PLL_DDR Control Register */
	PRINTF("%s->PLL_PERI_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x020 PLL_PERI Control Register */
	PRINTF("%s->PLL_VIDEO0_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x040 PLL_VIDEO0 Control Register */
	PRINTF("%s->PLL_VIDEO1_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x048 PLL_VIDEO1 Control Register */
	PRINTF("%s->PLL_VE_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x058 PLL_VE Control Register */
	PRINTF("%s->PLL_AUDIO0_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x078 PLL_AUDIO0 Control Register */
	PRINTF("%s->PLL_AUDIO1_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x080 PLL_AUDIO1 Control Register */
	PRINTF("%s->PLL_DDR_PAT0_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x110 PLL_DDR Pattern0 Control Register */
	PRINTF("%s->PLL_DDR_PAT1_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x114 PLL_DDR Pattern1 Control Register */
	PRINTF("%s->PLL_PERI_PAT0_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x120 PLL_PERI Pattern0 Control Register */
	PRINTF("%s->PLL_PERI_PAT1_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x124 PLL_PERI Pattern1 Control Register */
	PRINTF("%s->PLL_VIDEO0_PAT0_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x140 PLL_VIDEO0 Pattern0 Control Register */
	PRINTF("%s->PLL_VIDEO0_PAT1_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x144 PLL_VIDEO0 Pattern1 Control Register */
	PRINTF("%s->PLL_VIDEO1_PAT0_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x148 PLL_VIDEO1 Pattern0 Control Register */
	PRINTF("%s->PLL_VIDEO1_PAT1_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x14C PLL_VIDEO1 Pattern1 Control Register */
	PRINTF("%s->PLL_VE_PAT0_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x158 PLL_VE Pattern0 Control Register */
	PRINTF("%s->PLL_VE_PAT1_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x15C PLL_VE Pattern1 Control Register */
	PRINTF("%s->PLL_AUDIO0_PAT0_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x178 PLL_AUDIO0 Pattern0 Control Register */
	PRINTF("%s->PLL_AUDIO0_PAT1_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x17C PLL_AUDIO0 Pattern1 Control Register */
	PRINTF("%s->PLL_AUDIO1_PAT0_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x180 PLL_AUDIO1 Pattern0 Control Register */
	PRINTF("%s->PLL_AUDIO1_PAT1_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x184 PLL_AUDIO1 Pattern1 Control Register */
	PRINTF("%s->PLL_CPU_BIAS_REG=0x%08X\n", p);	/*!< Offset 0x300 PLL_CPU Bias Register */
	PRINTF("%s->PLL_DDR_BIAS_REG=0x%08X\n", p);	/*!< Offset 0x310 PLL_DDR Bias Register */
	PRINTF("%s->PLL_PERI_BIAS_REG=0x%08X\n", p);	/*!< Offset 0x320 PLL_PERI Bias Register */
	PRINTF("%s->PLL_VIDEO0_BIAS_REG=0x%08X\n", p);	/*!< Offset 0x340 PLL_VIDEO0 Bias Register */
	PRINTF("%s->PLL_VIDEO1_BIAS_REG=0x%08X\n", p);	/*!< Offset 0x348 PLL_VIDEO1 Bias Register */
	PRINTF("%s->PLL_VE_BIAS_REG=0x%08X\n", p);	/*!< Offset 0x358 PLL_VE Bias Register */
	PRINTF("%s->PLL_AUDIO0_BIAS_REG=0x%08X\n", p);	/*!< Offset 0x378 PLL_AUDIO0 Bias Register */
	PRINTF("%s->PLL_AUDIO1_BIAS_REG=0x%08X\n", p);	/*!< Offset 0x380 PLL_AUDIO1 Bias Register */
	PRINTF("%s->PLL_CPU_TUN_REG=0x%08X\n", p);	/*!< Offset 0x400 PLL_CPU Tuning Register */
	PRINTF("%s->PSI_CLK_REG=0x%08X\n", p);	/*!< Offset 0x510 PSI Clock Register */
	PRINTF("%s->APB0_CLK_REG=0x%08X\n", p);	/*!< Offset 0x520 APB0 Clock Register */
	PRINTF("%s->APB1_CLK_REG=0x%08X\n", p);	/*!< Offset 0x524 APB1 Clock Register */
	PRINTF("%s->MBUS_CLK_REG=0x%08X\n", p);	/*!< Offset 0x540 MBUS Clock Register */
	PRINTF("%s->DE_CLK_REG=0x%08X\n", p);	/*!< Offset 0x600 DE Clock Register */
	PRINTF("%s->DE_BGR_REG=0x%08X\n", p);	/*!< Offset 0x60C DE Bus Gating Reset Register */
	PRINTF("%s->DI_CLK_REG=0x%08X\n", p);	/*!< Offset 0x620 DI Clock Register */
	PRINTF("%s->DI_BGR_REG=0x%08X\n", p);	/*!< Offset 0x62C DI Bus Gating Reset Register */
	PRINTF("%s->G2D_CLK_REG=0x%08X\n", p);	/*!< Offset 0x630 G2D Clock Register */
	PRINTF("%s->G2D_BGR_REG=0x%08X\n", p);	/*!< Offset 0x63C G2D Bus Gating Reset Register */
	PRINTF("%s->CE_CLK_REG=0x%08X\n", p);	/*!< Offset 0x680 CE Clock Register */
	PRINTF("%s->CE_BGR_REG=0x%08X\n", p);	/*!< Offset 0x68C CE Bus Gating Reset Register */
	PRINTF("%s->VE_CLK_REG=0x%08X\n", p);	/*!< Offset 0x690 VE Clock Register */
	PRINTF("%s->VE_BGR_REG=0x%08X\n", p);	/*!< Offset 0x69C VE Bus Gating Reset Register */
	PRINTF("%s->DMA_BGR_REG=0x%08X\n", p);	/*!< Offset 0x70C DMA Bus Gating Reset Register */
	PRINTF("%s->HSTIMER_BGR_REG=0x%08X\n", p);	/*!< Offset 0x73C HSTIMER Bus Gating Reset Register */
	PRINTF("%s->AVS_CLK_REG=0x%08X\n", p);	/*!< Offset 0x740 AVS Clock Register */
	PRINTF("%s->DBGSYS_BGR_REG=0x%08X\n", p);	/*!< Offset 0x78C DBGSYS Bus Gating Reset Register */
	PRINTF("%s->PWM_BGR_REG=0x%08X\n", p);	/*!< Offset 0x7AC PWM Bus Gating Reset Register */
	PRINTF("%s->IOMMU_BGR_REG=0x%08X\n", p);	/*!< Offset 0x7BC IOMMU Bus Gating Reset Register */
	PRINTF("%s->DRAM_CLK_REG=0x%08X\n", p);	/*!< Offset 0x800 DRAM Clock Register */
	PRINTF("%s->MBUS_MAT_CLK_GATING_REG=0x%08X\n", p);	/*!< Offset 0x804 MBUS Master Clock Gating Register */
	PRINTF("%s->DRAM_BGR_REG=0x%08X\n", p);	/*!< Offset 0x80C DRAM Bus Gating Reset Register */
	PRINTF("%s->SMHC0_CLK_REG=0x%08X\n", p);	/*!< Offset 0x830 SMHC0 Clock Register */
	PRINTF("%s->SMHC1_CLK_REG=0x%08X\n", p);	/*!< Offset 0x834 SMHC1 Clock Register */
	PRINTF("%s->SMHC2_CLK_REG=0x%08X\n", p);	/*!< Offset 0x838 SMHC2 Clock Register */
	PRINTF("%s->SMHC_BGR_REG=0x%08X\n", p);	/*!< Offset 0x84C SMHC Bus Gating Reset Register */
	PRINTF("%s->UART_BGR_REG=0x%08X\n", p);	/*!< Offset 0x90C UART Bus Gating Reset Register */
	PRINTF("%s->TWI_BGR_REG=0x%08X\n", p);	/*!< Offset 0x91C TWI Bus Gating Reset Register */
	PRINTF("%s->CAN_BGR_REG=0x%08X\n", p);	/*!< Offset 0x92C CAN Bus Gating Reset Register */
	PRINTF("%s->SPI0_CLK_REG=0x%08X\n", p);	/*!< Offset 0x940 SPI0 Clock Register */
	PRINTF("%s->SPI1_CLK_REG=0x%08X\n", p);	/*!< Offset 0x944 SPI1 Clock Register */
	PRINTF("%s->SPI_BGR_REG=0x%08X\n", p);	/*!< Offset 0x96C SPI Bus Gating Reset Register */
	PRINTF("%s->EMAC_25M_CLK_REG=0x%08X\n", p);	/*!< Offset 0x970 EMAC_25M Clock Register */
	PRINTF("%s->EMAC_BGR_REG=0x%08X\n", p);	/*!< Offset 0x97C EMAC Bus Gating Reset Register */
	PRINTF("%s->IRTX_CLK_REG=0x%08X\n", p);	/*!< Offset 0x9C0 IRTX Clock Register */
	PRINTF("%s->IRTX_BGR_REG=0x%08X\n", p);	/*!< Offset 0x9CC IRTX Bus Gating Reset Register */
	PRINTF("%s->GPADC_BGR_REG=0x%08X\n", p);	/*!< Offset 0x9EC GPADC Bus Gating Reset Register */
	PRINTF("%s->THS_BGR_REG=0x%08X\n", p);	/*!< Offset 0x9FC THS Bus Gating Reset Register */
	PRINTF("%s->I2S1_CLK_REG=0x%08X\n", p);	/*!< Offset 0xA14 I2S1 Clock Register */
	PRINTF("%s->I2S2_CLK_REG=0x%08X\n", p);	/*!< Offset 0xA18 I2S2 Clock Register */
	PRINTF("%s->I2S2_ASRC_CLK_REG=0x%08X\n", p);	/*!< Offset 0xA1C I2S2_ASRC Clock Register */
	PRINTF("%s->I2S_BGR_REG=0x%08X\n", p);	/*!< Offset 0xA20 I2S Bus Gating Reset Register */
	PRINTF("%s->OWA_TX_CLK_REG=0x%08X\n", p);	/*!< Offset 0xA24 OWA_TX Clock Register */
	PRINTF("%s->OWA_RX_CLK_REG=0x%08X\n", p);	/*!< Offset 0xA28 OWA_RX Clock Register */
	PRINTF("%s->OWA_BGR_REG=0x%08X\n", p);	/*!< Offset 0xA2C OWA Bus Gating Reset Register */
	PRINTF("%s->DMIC_CLK_REG=0x%08X\n", p);	/*!< Offset 0xA40 DMIC Clock Register */
	PRINTF("%s->DMIC_BGR_REG=0x%08X\n", p);	/*!< Offset 0xA4C DMIC Bus Gating Reset Register */
	PRINTF("%s->AUDIO_CODEC_DAC_CLK_REG=0x%08X\n", p);	/*!< Offset 0xA50 AUDIO_CODEC_DAC Clock Register */
	PRINTF("%s->AUDIO_CODEC_ADC_CLK_REG=0x%08X\n", p);	/*!< Offset 0xA54 AUDIO_CODEC_ADC Clock Register */
	PRINTF("%s->AUDIO_CODEC_BGR_REG=0x%08X\n", p);	/*!< Offset 0xA5C AUDIO_CODEC Bus Gating Reset Register */
	PRINTF("%s->USB0_CLK_REG=0x%08X\n", p);	/*!< Offset 0xA70 USB0 Clock Register */
	PRINTF("%s->USB1_CLK_REG=0x%08X\n", p);	/*!< Offset 0xA74 USB1 Clock Register */
	PRINTF("%s->USB_BGR_REG=0x%08X\n", p);	/*!< Offset 0xA8C USB Bus Gating Reset Register */
	PRINTF("%s->DPSS_TOP_BGR_REG=0x%08X\n", p);	/*!< Offset 0xABC DPSS_TOP Bus Gating Reset Register */
	PRINTF("%s->DSI_CLK_REG=0x%08X\n", p);	/*!< Offset 0xB24 DSI Clock Register */
	PRINTF("%s->DSI_BGR_REG=0x%08X\n", p);	/*!< Offset 0xB4C DSI Bus Gating Reset Register */
	PRINTF("%s->TCONLCD_CLK_REG=0x%08X\n", p);	/*!< Offset 0xB60 TCONLCD Clock Register */
	PRINTF("%s->TCONLCD_BGR_REG=0x%08X\n", p);	/*!< Offset 0xB7C TCONLCD Bus Gating Reset Register */
	PRINTF("%s->TCONTV_CLK_REG=0x%08X\n", p);	/*!< Offset 0xB80 TCONTV Clock Register */
	PRINTF("%s->TCONTV_BGR_REG=0x%08X\n", p);	/*!< Offset 0xB9C TCONTV Bus Gating Reset Register */
	PRINTF("%s->LVDS_BGR_REG=0x%08X\n", p);	/*!< Offset 0xBAC LVDS Bus Gating Reset Register */
	PRINTF("%s->TVE_CLK_REG=0x%08X\n", p);	/*!< Offset 0xBB0 TVE Clock Register */
	PRINTF("%s->TVE_BGR_REG=0x%08X\n", p);	/*!< Offset 0xBBC TVE Bus Gating Reset Register */
	PRINTF("%s->TVD_CLK_REG=0x%08X\n", p);	/*!< Offset 0xBC0 TVD Clock Register */
	PRINTF("%s->TVD_BGR_REG=0x%08X\n", p);	/*!< Offset 0xBDC TVD Bus Gating Reset Register */
	PRINTF("%s->LEDC_CLK_REG=0x%08X\n", p);	/*!< Offset 0xBF0 LEDC Clock Register */
	PRINTF("%s->LEDC_BGR_REG=0x%08X\n", p);	/*!< Offset 0xBFC LEDC Bus Gating Reset Register */
	PRINTF("%s->CSI_CLK_REG=0x%08X\n", p);	/*!< Offset 0xC04 CSI Clock Register */
	PRINTF("%s->CSI_MASTER_CLK_REG=0x%08X\n", p);	/*!< Offset 0xC08 CSI Master Clock Register */
	PRINTF("%s->CSI_BGR_REG=0x%08X\n", p);	/*!< Offset 0xC1C CSI Bus Gating Reset Register */
	PRINTF("%s->TPADC_CLK_REG=0x%08X\n", p);	/*!< Offset 0xC50 TPADC Clock Register */
	PRINTF("%s->TPADC_BGR_REG=0x%08X\n", p);	/*!< Offset 0xC5C TPADC Bus Gating Reset Register */
	PRINTF("%s->RISC_CLK_REG=0x%08X\n", p);	/*!< Offset 0xD00 RISC Clock Register */
	PRINTF("%s->RISC_GATING_REG=0x%08X\n", p);	/*!< Offset 0xD04 RISC Gating Configuration Register */
	PRINTF("%s->RISC_CFG_BGR_REG=0x%08X\n", p);	/*!< Offset 0xD0C RISC_CFG Bus Gating Reset Register */
}
/* Print PLIC */
static void PLIC_Type_print(const PLIC_TypeDef * p)
{
	PRINTF("%s->PLIC_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x1FFFFC PLIC Control Register */
	PRINTF("%s->PLIC_MTH_REG=0x%08X\n", p);	/*!< Offset 0x200000 PLIC Machine Threshold Register */
	PRINTF("%s->PLIC_MCLAIM_REG=0x%08X\n", p);	/*!< Offset 0x200004 PLIC Machine Claim Register */
	PRINTF("%s->PLIC_STH_REG=0x%08X\n", p);	/*!< Offset 0x201000 PLIC Superuser Threshold Register */
	PRINTF("%s->PLIC_SCLAIM_REG=0x%08X\n", p);	/*!< Offset 0x201004 PLIC Superuser Claim Register */
}
/* Print SYS_CFG */
static void SYS_CFG_Type_print(const SYS_CFG_TypeDef * p)
{
	PRINTF("%s->DSP_BOOT_RAMMAP_REG=0x%08X\n", p);	/*!< Offset 0x008 DSP Boot SRAM Remap Control Register */
	PRINTF("%s->VER_REG=0x%08X\n", p);	/*!< Offset 0x024 Version Register */
	PRINTF("%s->EMAC_EPHY_CLK_REG0=0x%08X\n", p);	/*!< Offset 0x030 EMAC-EPHY Clock Register 0 */
	PRINTF("%s->SYS_LDO_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x150 System LDO Control Register */
	PRINTF("%s->RESCAL_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x160 Resistor Calibration Control Register */
	PRINTF("%s->RES240_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x168 240ohms Resistor Manual Control Register */
	PRINTF("%s->RESCAL_STATUS_REG=0x%08X\n", p);	/*!< Offset 0x16C Resistor Calibration Status Register */
}
/* Print UART */
static void UART_Type_print(const UART_TypeDef * p)
{
	PRINTF("%s->DATA=0x%08X\n", p);	/*!< Offset 0x000 UART Receive Buffer Register/Transmit Holding Register */
	PRINTF("%s->DLH_IER=0x%08X\n", p);	/*!< Offset 0x004 UART Divisor Latch High Register/UART Interrupt Enable Register */
	PRINTF("%s->IIR_FCR=0x%08X\n", p);	/*!< Offset 0x008 UART Interrupt Identity Register/UART FIFO Control Register */
	PRINTF("%s->UART_LCR=0x%08X\n", p);	/*!< Offset 0x00C UART Line Control Register */
	PRINTF("%s->UART_MCR=0x%08X\n", p);	/*!< Offset 0x010 UART Modem Control Register */
	PRINTF("%s->UART_LSR=0x%08X\n", p);	/*!< Offset 0x014 UART Line Status Register */
	PRINTF("%s->UART_MSR=0x%08X\n", p);	/*!< Offset 0x018 UART Modem Status Register */
	PRINTF("%s->UART_SCH=0x%08X\n", p);	/*!< Offset 0x01C UART Scratch Register */
	PRINTF("%s->UART_USR=0x%08X\n", p);	/*!< Offset 0x07C UART Status Register */
	PRINTF("%s->UART_TFL=0x%08X\n", p);	/*!< Offset 0x080 UART Transmit FIFO Level Register */
	PRINTF("%s->UART_RFL=0x%08X\n", p);	/*!< Offset 0x084 UART Receive FIFO Level Register */
	PRINTF("%s->UART_HSK=0x%08X\n", p);	/*!< Offset 0x088 UART DMA Handshake Configuration Register */
	PRINTF("%s->UART_DMA_REQ_EN=0x%08X\n", p);	/*!< Offset 0x08C UART DMA Request Enable Register */
	PRINTF("%s->UART_HALT=0x%08X\n", p);	/*!< Offset 0x0A4 UART Halt TX Register */
	PRINTF("%s->UART_DBG_DLL=0x%08X\n", p);	/*!< Offset 0x0B0 UART Debug DLL Register */
	PRINTF("%s->UART_DBG_DLH=0x%08X\n", p);	/*!< Offset 0x0B4 UART Debug DLH Register */
	PRINTF("%s->UART_A_FCC=0x%08X\n", p);	/*!< Offset 0x0F0 UART FIFO Clock Control Register */
	PRINTF("%s->UART_A_RXDMA_CTRL=0x%08X\n", p);	/*!< Offset 0x100 UART RXDMA Control Register */
	PRINTF("%s->UART_A_RXDMA_STR=0x%08X\n", p);	/*!< Offset 0x104 UART RXDMA Start Register */
	PRINTF("%s->UART_A_RXDMA_STA=0x%08X\n", p);	/*!< Offset 0x108 UART RXDMA Status Register */
	PRINTF("%s->UART_A_RXDMA_LMT=0x%08X\n", p);	/*!< Offset 0x10C UART RXDMA Limit Register */
	PRINTF("%s->UART_A_RXDMA_SADDRL=0x%08X\n", p);	/*!< Offset 0x110 UART RXDMA Buffer Start Address Low Register */
	PRINTF("%s->UART_A_RXDMA_SADDRH=0x%08X\n", p);	/*!< Offset 0x114 UART RXDMA Buffer Start Address High Register */
	PRINTF("%s->UART_A_RXDMA_BL=0x%08X\n", p);	/*!< Offset 0x118 UART RXDMA Buffer Length Register */
	PRINTF("%s->UART_A_RXDMA_IE=0x%08X\n", p);	/*!< Offset 0x120 UART RXDMA Interrupt Enable Register */
	PRINTF("%s->UART_A_RXDMA_IS=0x%08X\n", p);	/*!< Offset 0x124 UART RXDMA Interrupt Status Register */
	PRINTF("%s->UART_A_RXDMA_WADDRL=0x%08X\n", p);	/*!< Offset 0x128 UART RXDMA Write Address Low Register */
	PRINTF("%s->UART_A_RXDMA_WADDRH=0x%08X\n", p);	/*!< Offset 0x12C UART RXDMA Write Address high Register */
	PRINTF("%s->UART_A_RXDMA_RADDRL=0x%08X\n", p);	/*!< Offset 0x130 UART RXDMA Read Address Low Register */
	PRINTF("%s->UART_A_RXDMA_RADDRH=0x%08X\n", p);	/*!< Offset 0x134 UART RXDMA Read Address high Register */
	PRINTF("%s->UART_A_RXDMA_DCNT=0x%08X\n", p);	/*!< Offset 0x138 UART RADMA Data Count Register */
}
/* Print GPIO */
static void GPIO_Type_print(const GPIO_TypeDef * p)
{
	PRINTF("%s->DATA=0x%08X\n", p);	/*!< Offset 0x010 Data Register */
}
/* Print GPIOINT */
static void GPIOINT_Type_print(const GPIOINT_TypeDef * p)
{
	PRINTF("%s->EINT_CTL=0x%08X\n", p);	/*!< Offset 0x010 External Interrupt Control Register */
	PRINTF("%s->EINT_STATUS=0x%08X\n", p);	/*!< Offset 0x014 External Interrupt Status Register */
	PRINTF("%s->EINT_DEB=0x%08X\n", p);	/*!< Offset 0x018 External Interrupt Debounce Register */
}
/* Print GPIOBLOCK */
static void GPIOBLOCK_Type_print(const GPIOBLOCK_TypeDef * p)
{
	PRINTF("%s->PIO_POW_MOD_SEL=0x%08X\n", p);	/*!< Offset 0x340 PIO Group Withstand Voltage Mode Select Register */
	PRINTF("%s->PIO_POW_MS_CTL=0x%08X\n", p);	/*!< Offset 0x344 PIO Group Withstand Voltage Mode Select Control Register */
	PRINTF("%s->PIO_POW_VAL=0x%08X\n", p);	/*!< Offset 0x348 PIO Group Power Value Register */
}
/* Print SMHC */
static void SMHC_Type_print(const SMHC_TypeDef * p)
{
	PRINTF("%s->SMHC_CTRL=0x%08X\n", p);	/*!< Offset 0x000 Control Register */
	PRINTF("%s->SMHC_CLKDIV=0x%08X\n", p);	/*!< Offset 0x004 Clock Control Register */
	PRINTF("%s->SMHC_TMOUT=0x%08X\n", p);	/*!< Offset 0x008 Time Out Register */
	PRINTF("%s->SMHC_CTYPE=0x%08X\n", p);	/*!< Offset 0x00C Bus Width Register */
	PRINTF("%s->SMHC_BLKSIZ=0x%08X\n", p);	/*!< Offset 0x010 Block Size Register */
	PRINTF("%s->SMHC_BYTCNT=0x%08X\n", p);	/*!< Offset 0x014 Byte Count Register */
	PRINTF("%s->SMHC_CMD=0x%08X\n", p);	/*!< Offset 0x018 Command Register */
	PRINTF("%s->SMHC_CMDARG=0x%08X\n", p);	/*!< Offset 0x01C Command Argument Register */
	PRINTF("%s->SMHC_RESP0=0x%08X\n", p);	/*!< Offset 0x020 Response 0 Register */
	PRINTF("%s->SMHC_RESP1=0x%08X\n", p);	/*!< Offset 0x024 Response 1 Register */
	PRINTF("%s->SMHC_RESP2=0x%08X\n", p);	/*!< Offset 0x028 Response 2 Register */
	PRINTF("%s->SMHC_RESP3=0x%08X\n", p);	/*!< Offset 0x02C Response 3 Register */
	PRINTF("%s->SMHC_INTMASK=0x%08X\n", p);	/*!< Offset 0x030 Interrupt Mask Register */
	PRINTF("%s->SMHC_MINTSTS=0x%08X\n", p);	/*!< Offset 0x034 Masked Interrupt Status Register */
	PRINTF("%s->SMHC_RINTSTS=0x%08X\n", p);	/*!< Offset 0x038 Raw Interrupt Status Register */
	PRINTF("%s->SMHC_STATUS=0x%08X\n", p);	/*!< Offset 0x03C Status Register */
	PRINTF("%s->SMHC_FIFOTH=0x%08X\n", p);	/*!< Offset 0x040 FIFO Water Level Register */
	PRINTF("%s->SMHC_FUNS=0x%08X\n", p);	/*!< Offset 0x044 FIFO Function Select Register */
	PRINTF("%s->SMHC_TCBCNT=0x%08X\n", p);	/*!< Offset 0x048 Transferred Byte Count between Controller and Card */
	PRINTF("%s->SMHC_TBBCNT=0x%08X\n", p);	/*!< Offset 0x04C Transferred Byte Count between Host Memory and Internal FIFO */
	PRINTF("%s->SMHC_DBGC=0x%08X\n", p);	/*!< Offset 0x050 Current Debug Control Register */
	PRINTF("%s->SMHC_CSDC=0x%08X\n", p);	/*!< Offset 0x054 CRC Status Detect Control Registers */
	PRINTF("%s->SMHC_A12A=0x%08X\n", p);	/*!< Offset 0x058 Auto Command 12 Argument Register */
	PRINTF("%s->SMHC_NTSR=0x%08X\n", p);	/*!< Offset 0x05C SD New Timing Set Register */
	PRINTF("%s->SMHC_HWRST=0x%08X\n", p);	/*!< Offset 0x078 Hardware Reset Register */
	PRINTF("%s->SMHC_IDMAC=0x%08X\n", p);	/*!< Offset 0x080 IDMAC Control Register */
	PRINTF("%s->SMHC_DLBA=0x%08X\n", p);	/*!< Offset 0x084 Descriptor List Base Address Register */
	PRINTF("%s->SMHC_IDST=0x%08X\n", p);	/*!< Offset 0x088 IDMAC Status Register */
	PRINTF("%s->SMHC_IDIE=0x%08X\n", p);	/*!< Offset 0x08C IDMAC Interrupt Enable Register */
	PRINTF("%s->SMHC_THLD=0x%08X\n", p);	/*!< Offset 0x100 Card Threshold Control Register */
	PRINTF("%s->SMHC_SFC=0x%08X\n", p);	/*!< Offset 0x104 Sample FIFO Control Register */
	PRINTF("%s->SMHC_A23A=0x%08X\n", p);	/*!< Offset 0x108 Auto Command 23 Argument Register */
	PRINTF("%s->EMMC_DDR_SBIT_DET=0x%08X\n", p);	/*!< Offset 0x10C eMMC4.5 DDR Start Bit Detection Control Register */
	PRINTF("%s->SMHC_EXT_CMD=0x%08X\n", p);	/*!< Offset 0x138 Extended Command Register */
	PRINTF("%s->SMHC_EXT_RESP=0x%08X\n", p);	/*!< Offset 0x13C Extended Response Register */
	PRINTF("%s->SMHC_DRV_DL=0x%08X\n", p);	/*!< Offset 0x140 Drive Delay Control Register */
	PRINTF("%s->SMHC_SMAP_DL=0x%08X\n", p);	/*!< Offset 0x144 Sample Delay Control Register */
	PRINTF("%s->SMHC_DS_DL=0x%08X\n", p);	/*!< Offset 0x148 Data Strobe Delay Control Register */
	PRINTF("%s->SMHC_HS400_DL=0x%08X\n", p);	/*!< Offset 0x14C HS400 Delay Control Register */
	PRINTF("%s->SMHC_FIFO=0x%08X\n", p);	/*!< Offset 0x200 Read/Write FIFO */
}
/* Print I2S_PCM */
static void I2S_PCM_Type_print(const I2S_PCM_TypeDef * p)
{
	PRINTF("%s->I2S_PCM_CTL=0x%08X\n", p);	/*!< Offset 0x000 I2S/PCM Control Register */
	PRINTF("%s->I2S_PCM_FMT0=0x%08X\n", p);	/*!< Offset 0x004 I2S/PCM Format Register 0 */
	PRINTF("%s->I2S_PCM_FMT1=0x%08X\n", p);	/*!< Offset 0x008 I2S/PCM Format Register 1 */
	PRINTF("%s->I2S_PCM_ISTA=0x%08X\n", p);	/*!< Offset 0x00C I2S/PCM Interrupt Status Register */
	PRINTF("%s->I2S_PCM_RXFIFO=0x%08X\n", p);	/*!< Offset 0x010 I2S/PCM RXFIFO Register */
	PRINTF("%s->I2S_PCM_FCTL=0x%08X\n", p);	/*!< Offset 0x014 I2S/PCM FIFO Control Register */
	PRINTF("%s->I2S_PCM_FSTA=0x%08X\n", p);	/*!< Offset 0x018 I2S/PCM FIFO Status Register */
	PRINTF("%s->I2S_PCM_INT=0x%08X\n", p);	/*!< Offset 0x01C I2S/PCM DMA & Interrupt Control Register */
	PRINTF("%s->I2S_PCM_TXFIFO=0x%08X\n", p);	/*!< Offset 0x020 I2S/PCM TXFIFO Register */
	PRINTF("%s->I2S_PCM_CLKD=0x%08X\n", p);	/*!< Offset 0x024 I2S/PCM Clock Divide Register */
	PRINTF("%s->I2S_PCM_TXCNT=0x%08X\n", p);	/*!< Offset 0x028 I2S/PCM TX Sample Counter Register */
	PRINTF("%s->I2S_PCM_RXCNT=0x%08X\n", p);	/*!< Offset 0x02C I2S/PCM RX Sample Counter Register */
	PRINTF("%s->I2S_PCM_CHCFG=0x%08X\n", p);	/*!< Offset 0x030 I2S/PCM Channel Configuration Register */
	PRINTF("%s->I2S_PCM_TX0CHSEL=0x%08X\n", p);	/*!< Offset 0x034 I2S/PCM TX0 Channel Select Register */
	PRINTF("%s->I2S_PCM_TX1CHSEL=0x%08X\n", p);	/*!< Offset 0x038 I2S/PCM TX1 Channel Select Register */
	PRINTF("%s->I2S_PCM_TX2CHSEL=0x%08X\n", p);	/*!< Offset 0x03C I2S/PCM TX2 Channel Select Register */
	PRINTF("%s->I2S_PCM_TX3CHSEL=0x%08X\n", p);	/*!< Offset 0x040 I2S/PCM TX3 Channel Select Register */
	PRINTF("%s->I2S_PCM_TX0CHMAP0=0x%08X\n", p);	/*!< Offset 0x044 I2S/PCM TX0 Channel Mapping Register0 */
	PRINTF("%s->I2S_PCM_TX0CHMAP1=0x%08X\n", p);	/*!< Offset 0x048 I2S/PCM TX0 Channel Mapping Register1 */
	PRINTF("%s->I2S_PCM_TX1CHMAP0=0x%08X\n", p);	/*!< Offset 0x04C I2S/PCM TX1 Channel Mapping Register0 */
	PRINTF("%s->I2S_PCM_TX1CHMAP1=0x%08X\n", p);	/*!< Offset 0x050 I2S/PCM TX1 Channel Mapping Register1 */
	PRINTF("%s->I2S_PCM_TX2CHMAP0=0x%08X\n", p);	/*!< Offset 0x054 I2S/PCM TX2 Channel Mapping Register0 */
	PRINTF("%s->I2S_PCM_TX2CHMAP1=0x%08X\n", p);	/*!< Offset 0x058 I2S/PCM TX2 Channel Mapping Register1 */
	PRINTF("%s->I2S_PCM_TX3CHMAP0=0x%08X\n", p);	/*!< Offset 0x05C I2S/PCM TX3 Channel Mapping Register0 */
	PRINTF("%s->I2S_PCM_TX3CHMAP1=0x%08X\n", p);	/*!< Offset 0x060 I2S/PCM TX3 Channel Mapping Register1 */
	PRINTF("%s->I2S_PCM_RXCHSEL=0x%08X\n", p);	/*!< Offset 0x064 I2S/PCM RX Channel Select Register */
	PRINTF("%s->I2S_PCM_RXCHMAP0=0x%08X\n", p);	/*!< Offset 0x068 I2S/PCM RX Channel Mapping Register0 */
	PRINTF("%s->I2S_PCM_RXCHMAP1=0x%08X\n", p);	/*!< Offset 0x06C I2S/PCM RX Channel Mapping Register1 */
	PRINTF("%s->I2S_PCM_RXCHMAP2=0x%08X\n", p);	/*!< Offset 0x070 I2S/PCM RX Channel Mapping Register2 */
	PRINTF("%s->I2S_PCM_RXCHMAP3=0x%08X\n", p);	/*!< Offset 0x074 I2S/PCM RX Channel Mapping Register3 */
	PRINTF("%s->MCLKCFG=0x%08X\n", p);	/*!< Offset 0x080 ASRC MCLK Configuration Register */
	PRINTF("%s->FsoutCFG=0x%08X\n", p);	/*!< Offset 0x084 ASRC Out Sample Rate Configuration Register */
	PRINTF("%s->FsinEXTCFG=0x%08X\n", p);	/*!< Offset 0x088 ASRC Input Sample Pulse Extend Configuration Register */
	PRINTF("%s->ASRCCFG=0x%08X\n", p);	/*!< Offset 0x08C ASRC Enable Register */
	PRINTF("%s->ASRCMANCFG=0x%08X\n", p);	/*!< Offset 0x090 ASRC Manual Ratio Configuration Register */
	PRINTF("%s->ASRCRATIOSTAT=0x%08X\n", p);	/*!< Offset 0x094 ASRC Status Register */
	PRINTF("%s->ASRCFIFOSTAT=0x%08X\n", p);	/*!< Offset 0x098 ASRC FIFO Level Status Register */
	PRINTF("%s->ASRCMBISTCFG=0x%08X\n", p);	/*!< Offset 0x09C ASRC MBIST Test Configuration Register */
	PRINTF("%s->ASRCMBISTSTAT=0x%08X\n", p);	/*!< Offset 0x0A0 ASRC MBIST Test Status Register */
}
/* Print DMIC */
static void DMIC_Type_print(const DMIC_TypeDef * p)
{
	PRINTF("%s->DMIC_EN=0x%08X\n", p);	/*!< Offset 0x000 DMIC Enable Control Register */
	PRINTF("%s->DMIC_SR=0x%08X\n", p);	/*!< Offset 0x004 DMIC Sample Rate Register */
	PRINTF("%s->DMIC_CTR=0x%08X\n", p);	/*!< Offset 0x008 DMIC Control Register */
	PRINTF("%s->DMIC_DATA=0x%08X\n", p);	/*!< Offset 0x010 DMIC Data Register */
	PRINTF("%s->DMIC_INTC=0x%08X\n", p);	/*!< Offset 0x014 MIC Interrupt Control Register */
	PRINTF("%s->DMIC_INTS=0x%08X\n", p);	/*!< Offset 0x018 DMIC Interrupt Status Register */
	PRINTF("%s->DMIC_RXFIFO_CTR=0x%08X\n", p);	/*!< Offset 0x01C DMIC RXFIFO Control Register */
	PRINTF("%s->DMIC_RXFIFO_STA=0x%08X\n", p);	/*!< Offset 0x020 DMIC RXFIFO Status Register */
	PRINTF("%s->DMIC_CH_NUM=0x%08X\n", p);	/*!< Offset 0x024 DMIC Channel Numbers Register */
	PRINTF("%s->DMIC_CH_MAP=0x%08X\n", p);	/*!< Offset 0x028 DMIC Channel Mapping Register */
	PRINTF("%s->DMIC_CNT=0x%08X\n", p);	/*!< Offset 0x02C DMIC Counter Register */
	PRINTF("%s->DATA0_DATA1_VOL_CTR=0x%08X\n", p);	/*!< Offset 0x030 Data0 and Data1 Volume Control Register */
	PRINTF("%s->DATA2_DATA3_VOL_CTR=0x%08X\n", p);	/*!< Offset 0x034 Data2 And Data3 Volume Control Register */
	PRINTF("%s->HPF_EN_CTR=0x%08X\n", p);	/*!< Offset 0x038 High Pass Filter Enable Control Register */
	PRINTF("%s->HPF_COEF_REG=0x%08X\n", p);	/*!< Offset 0x03C High Pass Filter Coefficient Register */
	PRINTF("%s->HPF_GAIN_REG=0x%08X\n", p);	/*!< Offset 0x040 High Pass Filter Gain Register */
}
/* Print OWA */
static void OWA_Type_print(const OWA_TypeDef * p)
{
	PRINTF("%s->OWA_GEN_CTL=0x%08X\n", p);	/*!< Offset 0x000 OWA General Control Register */
	PRINTF("%s->OWA_TX_CFIG=0x%08X\n", p);	/*!< Offset 0x004 OWA TX Configuration Register */
	PRINTF("%s->OWA_RX_CFIG=0x%08X\n", p);	/*!< Offset 0x008 OWA RX Configuration Register */
	PRINTF("%s->OWA_ISTA=0x%08X\n", p);	/*!< Offset 0x00C OWA Interrupt Status Register */
	PRINTF("%s->OWA_RXFIFO=0x%08X\n", p);	/*!< Offset 0x010 OWA RXFIFO Register */
	PRINTF("%s->OWA_FCTL=0x%08X\n", p);	/*!< Offset 0x014 OWA FIFO Control Register */
	PRINTF("%s->OWA_FSTA=0x%08X\n", p);	/*!< Offset 0x018 OWA FIFO Status Register */
	PRINTF("%s->OWA_INT=0x%08X\n", p);	/*!< Offset 0x01C OWA Interrupt Control Register */
	PRINTF("%s->OWA_TX_FIFO=0x%08X\n", p);	/*!< Offset 0x020 OWA TX FIFO Register */
	PRINTF("%s->OWA_TX_CNT=0x%08X\n", p);	/*!< Offset 0x024 OWA TX Counter Register */
	PRINTF("%s->OWA_RX_CNT=0x%08X\n", p);	/*!< Offset 0x028 OWA RX Counter Register */
	PRINTF("%s->OWA_TX_CHSTA0=0x%08X\n", p);	/*!< Offset 0x02C OWA TX Channel Status Register0 */
	PRINTF("%s->OWA_TX_CHSTA1=0x%08X\n", p);	/*!< Offset 0x030 OWA TX Channel Status Register1 */
	PRINTF("%s->OWA_RXCHSTA0=0x%08X\n", p);	/*!< Offset 0x034 OWA RX Channel Status Register0 */
	PRINTF("%s->OWA_RXCHSTA1=0x%08X\n", p);	/*!< Offset 0x038 OWA RX Channel Status Register1 */
	PRINTF("%s->OWA_EXP_CTL=0x%08X\n", p);	/*!< Offset 0x040 OWA Expand Control Register */
	PRINTF("%s->OWA_EXP_ISTA=0x%08X\n", p);	/*!< Offset 0x044 OWA Expand Interrupt Status Register */
	PRINTF("%s->OWA_EXP_INFO_0=0x%08X\n", p);	/*!< Offset 0x048 OWA Expand Infomation Register0 */
	PRINTF("%s->OWA_EXP_INFO_1=0x%08X\n", p);	/*!< Offset 0x04C OWA Expand Infomation Register1 */
	PRINTF("%s->OWA_EXP_DBG_0=0x%08X\n", p);	/*!< Offset 0x050 OWA Expand Debug Register0 */
	PRINTF("%s->OWA_EXP_DBG_1=0x%08X\n", p);	/*!< Offset 0x054 OWA Expand Debug Register1 */
}
/* Print AUDIO_CODEC */
static void AUDIO_CODEC_Type_print(const AUDIO_CODEC_TypeDef * p)
{
	PRINTF("%s->AC_DAC_DPC=0x%08X\n", p);	/*!< Offset 0x000 DAC Digital Part Control Register */
	PRINTF("%s->DAC_VOL_CTRL=0x%08X\n", p);	/*!< Offset 0x004 DAC Volume Control Register */
	PRINTF("%s->AC_DAC_FIFOC=0x%08X\n", p);	/*!< Offset 0x010 DAC FIFO Control Register */
	PRINTF("%s->AC_DAC_FIFOS=0x%08X\n", p);	/*!< Offset 0x014 DAC FIFO Status Register */
	PRINTF("%s->AC_DAC_TXDATA=0x%08X\n", p);	/*!< Offset 0x020 DAC TX DATA Register */
	PRINTF("%s->AC_DAC_CNT=0x%08X\n", p);	/*!< Offset 0x024 DAC TX FIFO Counter Register */
	PRINTF("%s->AC_DAC_DG=0x%08X\n", p);	/*!< Offset 0x028 DAC Debug Register */
	PRINTF("%s->AC_ADC_FIFOC=0x%08X\n", p);	/*!< Offset 0x030 ADC FIFO Control Register */
	PRINTF("%s->ADC_VOL_CTRL1=0x%08X\n", p);	/*!< Offset 0x034 ADC Volume Control1 Register */
	PRINTF("%s->AC_ADC_FIFOS=0x%08X\n", p);	/*!< Offset 0x038 ADC FIFO Status Register */
	PRINTF("%s->AC_ADC_RXDATA=0x%08X\n", p);	/*!< Offset 0x040 ADC RX Data Register */
	PRINTF("%s->AC_ADC_CNT=0x%08X\n", p);	/*!< Offset 0x044 ADC RX Counter Register */
	PRINTF("%s->AC_ADC_DG=0x%08X\n", p);	/*!< Offset 0x04C ADC Debug Register */
	PRINTF("%s->ADC_DIG_CTRL=0x%08X\n", p);	/*!< Offset 0x050 ADC Digtial Control Register */
	PRINTF("%s->VRA1SPEEDUP_DOWN_CTRL=0x%08X\n", p);	/*!< Offset 0x054 VRA1 Speedup Down Control Register */
	PRINTF("%s->AC_DAC_DAP_CTRL=0x%08X\n", p);	/*!< Offset 0x0F0 DAC DAP Control Register */
	PRINTF("%s->AC_ADC_DAP_CTR=0x%08X\n", p);	/*!< Offset 0x0F8 ADC DAP Control Register */
	PRINTF("%s->AC_DAC_DRC_HHPFC=0x%08X\n", p);	/*!< Offset 0x100 DAC DRC High HPF Coef Register */
	PRINTF("%s->AC_DAC_DRC_LHPFC=0x%08X\n", p);	/*!< Offset 0x104 DAC DRC Low HPF Coef Register */
	PRINTF("%s->AC_DAC_DRC_CTRL=0x%08X\n", p);	/*!< Offset 0x108 DAC DRC Control Register */
	PRINTF("%s->AC_DAC_DRC_LPFHAT=0x%08X\n", p);	/*!< Offset 0x10C DAC DRC Left Peak Filter High Attack Time Coef Register */
	PRINTF("%s->AC_DAC_DRC_LPFLAT=0x%08X\n", p);	/*!< Offset 0x110 DAC DRC Left Peak Filter Low Attack Time Coef Register */
	PRINTF("%s->AC_DAC_DRC_RPFHAT=0x%08X\n", p);	/*!< Offset 0x114 DAC DRC Right Peak Filter High Attack Time Coef Register */
	PRINTF("%s->AC_DAC_DRC_RPFLAT=0x%08X\n", p);	/*!< Offset 0x118 DAC DRC Peak Filter Low Attack Time Coef Register */
	PRINTF("%s->AC_DAC_DRC_LPFHRT=0x%08X\n", p);	/*!< Offset 0x11C DAC DRC Left Peak Filter High Release Time Coef Register */
	PRINTF("%s->AC_DAC_DRC_LPFLRT=0x%08X\n", p);	/*!< Offset 0x120 DAC DRC Left Peak Filter Low Release Time Coef Register */
	PRINTF("%s->AC_DAC_DRC_RPFHRT=0x%08X\n", p);	/*!< Offset 0x124 DAC DRC Right Peak filter High Release Time Coef Register */
	PRINTF("%s->AC_DAC_DRC_RPFLRT=0x%08X\n", p);	/*!< Offset 0x128 DAC DRC Right Peak filter Low Release Time Coef Register */
	PRINTF("%s->AC_DAC_DRC_LRMSHAT=0x%08X\n", p);	/*!< Offset 0x12C DAC DRC Left RMS Filter High Coef Register */
	PRINTF("%s->AC_DAC_DRC_LRMSLAT=0x%08X\n", p);	/*!< Offset 0x130 DAC DRC Left RMS Filter Low Coef Register */
	PRINTF("%s->AC_DAC_DRC_RRMSHAT=0x%08X\n", p);	/*!< Offset 0x134 DAC DRC Right RMS Filter High Coef Register */
	PRINTF("%s->AC_DAC_DRC_RRMSLAT=0x%08X\n", p);	/*!< Offset 0x138 DAC DRC Right RMS Filter Low Coef Register */
	PRINTF("%s->AC_DAC_DRC_HCT=0x%08X\n", p);	/*!< Offset 0x13C DAC DRC Compressor Threshold High Setting Register */
	PRINTF("%s->AC_DAC_DRC_LCT=0x%08X\n", p);	/*!< Offset 0x140 DAC DRC Compressor Slope High Setting Register */
	PRINTF("%s->AC_DAC_DRC_HKC=0x%08X\n", p);	/*!< Offset 0x144 DAC DRC Compressor Slope High Setting Register */
	PRINTF("%s->AC_DAC_DRC_LKC=0x%08X\n", p);	/*!< Offset 0x148 DAC DRC Compressor Slope Low Setting Register */
	PRINTF("%s->AC_DAC_DRC_HOPC=0x%08X\n", p);	/*!< Offset 0x14C DAC DRC Compresso */
	PRINTF("%s->AC_DAC_DRC_LOPC=0x%08X\n", p);	/*!< Offset 0x150 DAC DRC Compressor Low Output at Compressor Threshold Register */
	PRINTF("%s->AC_DAC_DRC_HLT=0x%08X\n", p);	/*!< Offset 0x154 DAC DRC Limiter Threshold High Setting Register */
	PRINTF("%s->AC_DAC_DRC_LLT=0x%08X\n", p);	/*!< Offset 0x158 DAC DRC Limiter Threshold Low Setting Register */
	PRINTF("%s->AC_DAC_DRC_HKl=0x%08X\n", p);	/*!< Offset 0x15C DAC DRC Limiter Slope High Setting Register */
	PRINTF("%s->AC_DAC_DRC_LKl=0x%08X\n", p);	/*!< Offset 0x160 DAC DRC Limiter Slope Low Setting Register */
	PRINTF("%s->AC_DAC_DRC_HOPL=0x%08X\n", p);	/*!< Offset 0x164 DAC DRC Limiter High Output at Limiter Threshold */
	PRINTF("%s->AC_DAC_DRC_LOPL=0x%08X\n", p);	/*!< Offset 0x168 DAC DRC Limiter Low Output at Limiter Threshold */
	PRINTF("%s->AC_DAC_DRC_HET=0x%08X\n", p);	/*!< Offset 0x16C DAC DRC Expander Threshold High Setting Register */
	PRINTF("%s->AC_DAC_DRC_LET=0x%08X\n", p);	/*!< Offset 0x170 DAC DRC Expander Threshold Low Setting Register */
	PRINTF("%s->AC_DAC_DRC_HKE=0x%08X\n", p);	/*!< Offset 0x174 DAC DRC Expander Slope High Setting Register */
	PRINTF("%s->AC_DAC_DRC_LKE=0x%08X\n", p);	/*!< Offset 0x178 DAC DRC Expander Slope Low Setting Register */
	PRINTF("%s->AC_DAC_DRC_HOPE=0x%08X\n", p);	/*!< Offset 0x17C DAC DRC Expander High Output at Expander Threshold */
	PRINTF("%s->AC_DAC_DRC_LOPE=0x%08X\n", p);	/*!< Offset 0x180 DAC DRC Expander Low Output at Expander Threshold */
	PRINTF("%s->AC_DAC_DRC_HKN=0x%08X\n", p);	/*!< Offset 0x184 DAC DRC Linear Slope High Setting Register */
	PRINTF("%s->AC_DAC_DRC_LKN=0x%08X\n", p);	/*!< Offset 0x188 DAC DRC Linear Slope Low Setting Register */
	PRINTF("%s->AC_DAC_DRC_SFHAT=0x%08X\n", p);	/*!< Offset 0x18C DAC DRC Smooth filter Gain High Attack Time Coef Register */
	PRINTF("%s->AC_DAC_DRC_SFLAT=0x%08X\n", p);	/*!< Offset 0x190 DAC DRC Smooth filter Gain Low Attack Time Coef Register */
	PRINTF("%s->AC_DAC_DRC_SFHRT=0x%08X\n", p);	/*!< Offset 0x194 DAC DRC Smooth filter Gain High Release Time Coef Register */
	PRINTF("%s->AC_DAC_DRC_SFLRT=0x%08X\n", p);	/*!< Offset 0x198 DAC DRC Smooth filter Gain Low Release Time Coef Register */
	PRINTF("%s->AC_DAC_DRC_MXGHS=0x%08X\n", p);	/*!< Offset 0x19C DAC DRC MAX Gain High Setting Register */
	PRINTF("%s->AC_DAC_DRC_MXGLS=0x%08X\n", p);	/*!< Offset 0x1A0 DAC DRC MAX Gain Low Setting Register */
	PRINTF("%s->AC_DAC_DRC_MNGHS=0x%08X\n", p);	/*!< Offset 0x1A4 DAC DRC MIN Gain High Setting Register */
	PRINTF("%s->AC_DAC_DRC_MNGLS=0x%08X\n", p);	/*!< Offset 0x1A8 DAC DRC MIN Gain Low Setting Register */
	PRINTF("%s->AC_DAC_DRC_EPSHC=0x%08X\n", p);	/*!< Offset 0x1AC DAC DRC Expander Smooth Time High Coef Register */
	PRINTF("%s->AC_DAC_DRC_EPSLC=0x%08X\n", p);	/*!< Offset 0x1B0 DAC DRC Expander Smooth Time Low Coef Register */
	PRINTF("%s->AC_DAC_DRC_HPFHGAIN=0x%08X\n", p);	/*!< Offset 0x1B8 DAC DRC HPF Gain High Coef Register */
	PRINTF("%s->AC_DAC_DRC_HPFLGAIN=0x%08X\n", p);	/*!< Offset 0x1BC DAC DRC HPF Gain Low Coef Register */
	PRINTF("%s->AC_ADC_DRC_HHPFC=0x%08X\n", p);	/*!< Offset 0x200 ADC DRC High HPF Coef Register */
	PRINTF("%s->AC_ADC_DRC_LHPFC=0x%08X\n", p);	/*!< Offset 0x204 ADC DRC Low HPF Coef Register */
	PRINTF("%s->AC_ADC_DRC_CTRL=0x%08X\n", p);	/*!< Offset 0x208 ADC DRC Control Register */
	PRINTF("%s->AC_ADC_DRC_LPFHAT=0x%08X\n", p);	/*!< Offset 0x20C ADC DRC Left Peak Filter High Attack Time Coef Register */
	PRINTF("%s->AC_ADC_DRC_LPFLAT=0x%08X\n", p);	/*!< Offset 0x210 ADC DRC Left Peak Filter Low Attack Time Coef Register */
	PRINTF("%s->AC_ADC_DRC_RPFHAT=0x%08X\n", p);	/*!< Offset 0x214 ADC DRC Right Peak Filter High Attack Time Coef Register */
	PRINTF("%s->AC_ADC_DRC_RPFLAT=0x%08X\n", p);	/*!< Offset 0x218 ADC DRC Right Peak Filter Low Attack Time Coef Register */
	PRINTF("%s->AC_ADC_DRC_LPFHRT=0x%08X\n", p);	/*!< Offset 0x21C ADC DRC Left Peak Filter High Release Time Coef Register */
	PRINTF("%s->AC_ADC_DRC_LPFLRT=0x%08X\n", p);	/*!< Offset 0x220 ADC DRC Left Peak Filter Low Release Time Coef Register */
	PRINTF("%s->AC_ADC_DRC_RPFHRT=0x%08X\n", p);	/*!< Offset 0x224 ADC DRC Right Peak Filter High Release Time Coef Register */
	PRINTF("%s->AC_ADC_DRC_RPFLRT=0x%08X\n", p);	/*!< Offset 0x228 ADC DRC Right Peak Filter Low Release Time Coef Register */
	PRINTF("%s->AC_ADC_DRC_LRMSHAT=0x%08X\n", p);	/*!< Offset 0x22C ADC DRC Left RMS Filter High Coef Register */
	PRINTF("%s->AC_ADC_DRC_LRMSLAT=0x%08X\n", p);	/*!< Offset 0x230 ADC DRC Left RMS Filter Low Coef Register */
	PRINTF("%s->AC_ADC_DRC_RRMSHAT=0x%08X\n", p);	/*!< Offset 0x234 ADC DRC Right RMS Filter High Coef Register */
	PRINTF("%s->AC_ADC_DRC_RRMSLAT=0x%08X\n", p);	/*!< Offset 0x238 ADC DRC Right RMS Filter Low Coef Register */
	PRINTF("%s->AC_ADC_DRC_HCT=0x%08X\n", p);	/*!< Offset 0x23C ADC DRC Compressor Threshold High Setting Register */
	PRINTF("%s->AC_ADC_DRC_LCT=0x%08X\n", p);	/*!< Offset 0x240 ADC DRC Compressor Slope High Setting Register */
	PRINTF("%s->AC_ADC_DRC_HKC=0x%08X\n", p);	/*!< Offset 0x244 ADC DRC Compressor Slope High Setting Register */
	PRINTF("%s->AC_ADC_DRC_LKC=0x%08X\n", p);	/*!< Offset 0x248 ADC DRC Compressor Slope Low Setting Register */
	PRINTF("%s->AC_ADC_DRC_HOPC=0x%08X\n", p);	/*!< Offset 0x24C ADC DRC Compressor High Output at Compressor Threshold Register */
	PRINTF("%s->AC_ADC_DRC_LOPC=0x%08X\n", p);	/*!< Offset 0x250 ADC DRC Compressor Low Output at Compressor Threshold Register */
	PRINTF("%s->AC_ADC_DRC_HLT=0x%08X\n", p);	/*!< Offset 0x254 ADC DRC Limiter Threshold High Setting Register */
	PRINTF("%s->AC_ADC_DRC_LLT=0x%08X\n", p);	/*!< Offset 0x258 ADC DRC Limiter Threshold Low Setting Register */
	PRINTF("%s->AC_ADC_DRC_HKl=0x%08X\n", p);	/*!< Offset 0x25C ADC DRC Limiter Slope High Setting Register */
	PRINTF("%s->AC_ADC_DRC_LKl=0x%08X\n", p);	/*!< Offset 0x260 ADC DRC Limiter Slope Low Setting Register */
	PRINTF("%s->AC_ADC_DRC_HOPL=0x%08X\n", p);	/*!< Offset 0x264 ADC DRC Limiter High Output at Limiter Threshold */
	PRINTF("%s->AC_ADC_DRC_LOPL=0x%08X\n", p);	/*!< Offset 0x268 ADC DRC Limiter Low Output at Limiter Threshold */
	PRINTF("%s->AC_ADC_DRC_HET=0x%08X\n", p);	/*!< Offset 0x26C ADC DRC Expander Threshold High Setting Register */
	PRINTF("%s->AC_ADC_DRC_LET=0x%08X\n", p);	/*!< Offset 0x270 ADC DRC Expander Threshold Low Setting Register */
	PRINTF("%s->AC_ADC_DRC_HKE=0x%08X\n", p);	/*!< Offset 0x274 ADC DRC Expander Slope High Setting Register */
	PRINTF("%s->AC_ADC_DRC_LKE=0x%08X\n", p);	/*!< Offset 0x278 ADC DRC Expander Slope Low Setting Register */
	PRINTF("%s->AC_ADC_DRC_HOPE=0x%08X\n", p);	/*!< Offset 0x27C ADC DRC Expander High Output at Expander Threshold */
	PRINTF("%s->AC_ADC_DRC_LOPE=0x%08X\n", p);	/*!< Offset 0x280 ADC DRC Expander Low Output at Expander Threshold */
	PRINTF("%s->AC_ADC_DRC_HKN=0x%08X\n", p);	/*!< Offset 0x284 ADC DRC Linear Slope High Setting Register */
	PRINTF("%s->AC_ADC_DRC_LKN=0x%08X\n", p);	/*!< Offset 0x288 ADC DRC Linear Slope Low Setting Register */
	PRINTF("%s->AC_ADC_DRC_SFHAT=0x%08X\n", p);	/*!< Offset 0x28C ADC DRC Smooth filter Gain High Attack Time Coef Register */
	PRINTF("%s->AC_ADC_DRC_SFLAT=0x%08X\n", p);	/*!< Offset 0x290 ADC DRC Smooth filter Gain Low Attack Time Coef Register */
	PRINTF("%s->AC_ADC_DRC_SFHRT=0x%08X\n", p);	/*!< Offset 0x294 ADC DRC Smooth filter Gain High Release Time Coef Register */
	PRINTF("%s->AC_ADC_DRC_SFLRT=0x%08X\n", p);	/*!< Offset 0x298 ADC DRC Smooth filter Gain Low Release Time Coef Register */
	PRINTF("%s->AC_ADC_DRC_MXGHS=0x%08X\n", p);	/*!< Offset 0x29C ADC DRC MAX Gain High Setting Register */
	PRINTF("%s->AC_ADC_DRC_MXGLS=0x%08X\n", p);	/*!< Offset 0x2A0 ADC DRC MAX Gain Low Setting Register */
	PRINTF("%s->AC_ADC_DRC_MNGHS=0x%08X\n", p);	/*!< Offset 0x2A4 ADC DRC MIN Gain High Setting Register */
	PRINTF("%s->AC_ADC_DRC_MNGLS=0x%08X\n", p);	/*!< Offset 0x2A8 ADC DRC MIN Gain Low Setting Register */
	PRINTF("%s->AC_ADC_DRC_EPSHC=0x%08X\n", p);	/*!< Offset 0x2AC ADC DRC Expander Smooth Time High Coef Register */
	PRINTF("%s->AC_ADC_DRC_EPSLC=0x%08X\n", p);	/*!< Offset 0x2B0 ADC DRC Expander Smooth Time Low Coef Register */
	PRINTF("%s->AC_ADC_DRC_HPFHGAIN=0x%08X\n", p);	/*!< Offset 0x2B8 ADC DRC HPF Gain High Coef Register */
	PRINTF("%s->AC_ADC_DRC_HPFLGAIN=0x%08X\n", p);	/*!< Offset 0x2BC ADC DRC HPF Gain Low Coef Register */
	PRINTF("%s->ADC1_REG=0x%08X\n", p);	/*!< Offset 0x300 ADC1 Analog Control Register */
	PRINTF("%s->ADC2_REG=0x%08X\n", p);	/*!< Offset 0x304 ADC2 Analog Control Register */
	PRINTF("%s->ADC3_REG=0x%08X\n", p);	/*!< Offset 0x308 ADC3 Analog Control Register */
	PRINTF("%s->DAC_REG=0x%08X\n", p);	/*!< Offset 0x310 DAC Analog Control Register */
	PRINTF("%s->MICBIAS_REG=0x%08X\n", p);	/*!< Offset 0x318 MICBIAS Analog Control Register */
	PRINTF("%s->RAMP_REG=0x%08X\n", p);	/*!< Offset 0x31C BIAS Analog Control Register */
	PRINTF("%s->BIAS_REG=0x%08X\n", p);	/*!< Offset 0x320 BIAS Analog Control Register */
	PRINTF("%s->ADC5_REG=0x%08X\n", p);	/*!< Offset 0x330 ADC5 Analog Control Register */
}
/* Print TWI */
static void TWI_Type_print(const TWI_TypeDef * p)
{
	PRINTF("%s->TWI_ADDR=0x%08X\n", p);	/*!< Offset 0x000 TWI Slave Address Register */
	PRINTF("%s->TWI_XADDR=0x%08X\n", p);	/*!< Offset 0x004 TWI Extended Slave Address Register */
	PRINTF("%s->TWI_DATA=0x%08X\n", p);	/*!< Offset 0x008 TWI Data Byte Register */
	PRINTF("%s->TWI_CNTR=0x%08X\n", p);	/*!< Offset 0x00C TWI Control Register */
	PRINTF("%s->TWI_STAT=0x%08X\n", p);	/*!< Offset 0x010 TWI Status Register */
	PRINTF("%s->TWI_CCR=0x%08X\n", p);	/*!< Offset 0x014 TWI Clock Control Register */
	PRINTF("%s->TWI_SRST=0x%08X\n", p);	/*!< Offset 0x018 TWI Software Reset Register */
	PRINTF("%s->TWI_EFR=0x%08X\n", p);	/*!< Offset 0x01C TWI Enhance Feature Register */
	PRINTF("%s->TWI_LCR=0x%08X\n", p);	/*!< Offset 0x020 TWI Line Control Register */
	PRINTF("%s->TWI_DRV_CTRL=0x%08X\n", p);	/*!< Offset 0x200 TWI_DRV Control Register */
	PRINTF("%s->TWI_DRV_CFG=0x%08X\n", p);	/*!< Offset 0x204 TWI_DRV Transmission Configuration Register */
	PRINTF("%s->TWI_DRV_SLV=0x%08X\n", p);	/*!< Offset 0x208 TWI_DRV Slave ID Register */
	PRINTF("%s->TWI_DRV_FMT=0x%08X\n", p);	/*!< Offset 0x20C TWI_DRV Packet Format Register */
	PRINTF("%s->TWI_DRV_BUS_CTRL=0x%08X\n", p);	/*!< Offset 0x210 TWI_DRV Bus Control Register */
	PRINTF("%s->TWI_DRV_INT_CTRL=0x%08X\n", p);	/*!< Offset 0x214 TWI_DRV Interrupt Control Register */
	PRINTF("%s->TWI_DRV_DMA_CFG=0x%08X\n", p);	/*!< Offset 0x218 TWI_DRV DMA Configure Register */
	PRINTF("%s->TWI_DRV_FIFO_CON=0x%08X\n", p);	/*!< Offset 0x21C TWI_DRV FIFO Content Register */
	PRINTF("%s->TWI_DRV_SEND_FIFO_ACC=0x%08X\n", p);	/*!< Offset 0x300 TWI_DRV Send Data FIFO Access Register */
	PRINTF("%s->TWI_DRV_RECV_FIFO_ACC=0x%08X\n", p);	/*!< Offset 0x304 TWI_DRV Receive Data FIFO Access Register */
}
/* Print SPI */
static void SPI_Type_print(const SPI_TypeDef * p)
{
	PRINTF("%s->SPI_GCR=0x%08X\n", p);	/*!< Offset 0x004 SPI Global Control Register */
	PRINTF("%s->SPI_TCR=0x%08X\n", p);	/*!< Offset 0x008 SPI Transfer Control Register */
	PRINTF("%s->SPI_IER=0x%08X\n", p);	/*!< Offset 0x010 SPI Interrupt Control Register */
	PRINTF("%s->SPI_ISR=0x%08X\n", p);	/*!< Offset 0x014 SPI Interrupt Status Register */
	PRINTF("%s->SPI_FCR=0x%08X\n", p);	/*!< Offset 0x018 SPI FIFO Control Register */
	PRINTF("%s->SPI_FSR=0x%08X\n", p);	/*!< Offset 0x01C SPI FIFO Status Register */
	PRINTF("%s->SPI_WCR=0x%08X\n", p);	/*!< Offset 0x020 SPI Wait Clock Register */
	PRINTF("%s->SPI_SAMP_DL=0x%08X\n", p);	/*!< Offset 0x028 SPI Sample Delay Control Register */
	PRINTF("%s->SPI_MBC=0x%08X\n", p);	/*!< Offset 0x030 SPI Master Burst Counter Register */
	PRINTF("%s->SPI_MTC=0x%08X\n", p);	/*!< Offset 0x034 SPI Master Transmit Counter Register */
	PRINTF("%s->SPI_BCC=0x%08X\n", p);	/*!< Offset 0x038 SPI Master Burst Control Register */
	PRINTF("%s->SPI_BATCR=0x%08X\n", p);	/*!< Offset 0x040 SPI Bit-Aligned Transfer Configure Register */
	PRINTF("%s->SPI_BA_CCR=0x%08X\n", p);	/*!< Offset 0x044 SPI Bit-Aligned Clock Configuration Register */
	PRINTF("%s->SPI_TBR=0x%08X\n", p);	/*!< Offset 0x048 SPI TX Bit Register */
	PRINTF("%s->SPI_RBR=0x%08X\n", p);	/*!< Offset 0x04C SPI RX Bit Register */
	PRINTF("%s->SPI_NDMA_MODE_CTL=0x%08X\n", p);	/*!< Offset 0x088 SPI Normal DMA Mode Control Register */
	PRINTF("%s->SPI_TXD=0x%08X\n", p);	/*!< Offset 0x200 SPI TX Data Register */
	PRINTF("%s->SPI_RXD=0x%08X\n", p);	/*!< Offset 0x300 SPI RX Data Register */
}
/* Print CIR_RX */
static void CIR_RX_Type_print(const CIR_RX_TypeDef * p)
{
	PRINTF("%s->CIR_CTL=0x%08X\n", p);	/*!< Offset 0x000 CIR Control Register */
	PRINTF("%s->CIR_RXPCFG=0x%08X\n", p);	/*!< Offset 0x010 CIR Receiver Pulse Configure Register */
	PRINTF("%s->CIR_RXFIFO=0x%08X\n", p);	/*!< Offset 0x020 CIR Receiver FIFO Register */
	PRINTF("%s->CIR_RXINT=0x%08X\n", p);	/*!< Offset 0x02C CIR Receiver Interrupt Control Register */
	PRINTF("%s->CIR_RXSTA=0x%08X\n", p);	/*!< Offset 0x030 CIR Receiver Status Register */
	PRINTF("%s->CIR_RXCFG=0x%08X\n", p);	/*!< Offset 0x034 CIR Receiver Configure Register */
}
/* Print CIR_TX */
static void CIR_TX_Type_print(const CIR_TX_TypeDef * p)
{
	PRINTF("%s->CIR_TGLR=0x%08X\n", p);	/*!< Offset 0x000 CIR Transmit Global Register */
	PRINTF("%s->CIR_TMCR=0x%08X\n", p);	/*!< Offset 0x004 CIR Transmit Modulation Control Register */
	PRINTF("%s->CIR_TCR=0x%08X\n", p);	/*!< Offset 0x008 CIR Transmit Control Register */
	PRINTF("%s->CIR_IDC_H=0x%08X\n", p);	/*!< Offset 0x00C CIR Transmit Idle Duration Threshold High Bit Register */
	PRINTF("%s->CIR_IDC_L=0x%08X\n", p);	/*!< Offset 0x010 CIR Transmit Idle Duration Threshold Low Bit Register */
	PRINTF("%s->CIR_TICR_H=0x%08X\n", p);	/*!< Offset 0x014 CIR Transmit Idle Counter High Bit Register */
	PRINTF("%s->CIR_TICR_L=0x%08X\n", p);	/*!< Offset 0x018 CIR Transmit Idle Counter Low Bit Register */
	PRINTF("%s->CIR_TEL=0x%08X\n", p);	/*!< Offset 0x020 CIR TX FIFO Empty Level Register */
	PRINTF("%s->CIR_TXINT=0x%08X\n", p);	/*!< Offset 0x024 CIR Transmit Interrupt Control Register */
	PRINTF("%s->CIR_TAC=0x%08X\n", p);	/*!< Offset 0x028 CIR Transmit FIFO Available Counter Register */
	PRINTF("%s->CIR_TXSTA=0x%08X\n", p);	/*!< Offset 0x02C CIR Transmit Status Register */
	PRINTF("%s->CIR_TXT=0x%08X\n", p);	/*!< Offset 0x030 CIR Transmit Threshold Register */
	PRINTF("%s->CIR_DMA=0x%08X\n", p);	/*!< Offset 0x034 CIR DMA Control Register */
	PRINTF("%s->CIR_TXFIFO=0x%08X\n", p);	/*!< Offset 0x080 CIR Transmit FIFO Data Register */
}
/* Print LEDC */
static void LEDC_Type_print(const LEDC_TypeDef * p)
{
	PRINTF("%s->LEDC_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x000 LEDC Control Register */
	PRINTF("%s->LED_T01_TIMING_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x004 LEDC T0 & T1 Timing Control Register */
	PRINTF("%s->LEDC_DATA_FINISH_CNT_REG=0x%08X\n", p);	/*!< Offset 0x008 LEDC Data Finish Counter Register */
	PRINTF("%s->LED_RESET_TIMING_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x00C LEDC Reset Timing Control Register */
	PRINTF("%s->LEDC_WAIT_TIME0_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x010 LEDC Wait Time0 Control Register */
	PRINTF("%s->LEDC_DATA_REG=0x%08X\n", p);	/*!< Offset 0x014 LEDC Data Register */
	PRINTF("%s->LEDC_DMA_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x018 LEDC DMA Control Register */
	PRINTF("%s->LEDC_INT_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x01C LEDC Interrupt Control Register */
	PRINTF("%s->LEDC_INT_STS_REG=0x%08X\n", p);	/*!< Offset 0x020 LEDC Interrupt Status Register */
	PRINTF("%s->LEDC_WAIT_TIME1_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x028 LEDC Wait Time1 Control Register */
}
/* Print TPADC */
static void TPADC_Type_print(const TPADC_TypeDef * p)
{
	PRINTF("%s->TP_CTRL_REG0=0x%08X\n", p);	/*!< Offset 0x000 TP Control Register 0 */
	PRINTF("%s->TP_CTRL_REG1=0x%08X\n", p);	/*!< Offset 0x004 TP Control Register 1 */
	PRINTF("%s->TP_CTRL_REG2=0x%08X\n", p);	/*!< Offset 0x008 TP Control Register 2 */
	PRINTF("%s->TP_CTRL_REG3=0x%08X\n", p);	/*!< Offset 0x00C TP Control Register 3 */
	PRINTF("%s->TP_INT_FIFO_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x010 TP Interrupt FIFO Control Register */
	PRINTF("%s->TP_INT_FIFO_STAT_REG=0x%08X\n", p);	/*!< Offset 0x014 TP Interrupt FIFO Status Register */
	PRINTF("%s->TP_CALI_DATA_REG=0x%08X\n", p);	/*!< Offset 0x01C TP Calibration Data Register */
	PRINTF("%s->TP_DATA_REG=0x%08X\n", p);	/*!< Offset 0x024 TP Data Register */
}
/* Print GPADC */
static void GPADC_Type_print(const GPADC_TypeDef * p)
{
	PRINTF("%s->GP_SR_CON=0x%08X\n", p);	/*!< Offset 0x000 GPADC Sample Rate Configure Register */
	PRINTF("%s->GP_CTRL=0x%08X\n", p);	/*!< Offset 0x004 GPADC Control Register */
	PRINTF("%s->GP_CS_EN=0x%08X\n", p);	/*!< Offset 0x008 GPADC Compare and Select Enable Register */
	PRINTF("%s->GP_FIFO_INTC=0x%08X\n", p);	/*!< Offset 0x00C GPADC FIFO Interrupt Control Register */
	PRINTF("%s->GP_FIFO_INTS=0x%08X\n", p);	/*!< Offset 0x010 GPADC FIFO Interrupt Status Register */
	PRINTF("%s->GP_FIFO_DATA=0x%08X\n", p);	/*!< Offset 0x014 GPADC FIFO Data Register */
	PRINTF("%s->GP_CDATA=0x%08X\n", p);	/*!< Offset 0x018 GPADC Calibration Data Register */
	PRINTF("%s->GP_DATAL_INTC=0x%08X\n", p);	/*!< Offset 0x020 GPADC Data Low Interrupt Configure Register */
	PRINTF("%s->GP_DATAH_INTC=0x%08X\n", p);	/*!< Offset 0x024 GPADC Data High Interrupt Configure Register */
	PRINTF("%s->GP_DATA_INTC=0x%08X\n", p);	/*!< Offset 0x028 GPADC Data Interrupt Configure Register */
	PRINTF("%s->GP_DATAL_INTS=0x%08X\n", p);	/*!< Offset 0x030 GPADC Data Low Interrupt Status Register */
	PRINTF("%s->GP_DATAH_INTS=0x%08X\n", p);	/*!< Offset 0x034 GPADC Data High Interrupt Status Register */
	PRINTF("%s->GP_DATA_INTS=0x%08X\n", p);	/*!< Offset 0x038 GPADC Data Interrupt Status Register */
	PRINTF("%s->GP_CH0_CMP_DATA=0x%08X\n", p);	/*!< Offset 0x040 GPADC CH0 Compare Data Register */
	PRINTF("%s->GP_CH0_DATA=0x%08X\n", p);	/*!< Offset 0x080 GPADC CH0 Data Register */
}
/* Print SPI_DBI */
static void SPI_DBI_Type_print(const SPI_DBI_TypeDef * p)
{
	PRINTF("%s->SPI_GCR=0x%08X\n", p);	/*!< Offset 0x004 SPI Global Control Register */
	PRINTF("%s->SPI_TCR=0x%08X\n", p);	/*!< Offset 0x008 SPI Transfer Control Register */
	PRINTF("%s->SPI_IER=0x%08X\n", p);	/*!< Offset 0x010 SPI Interrupt Control Register */
	PRINTF("%s->SPI_ISR=0x%08X\n", p);	/*!< Offset 0x014 SPI Interrupt Status Register */
	PRINTF("%s->SPI_FCR=0x%08X\n", p);	/*!< Offset 0x018 SPI FIFO Control Register */
	PRINTF("%s->SPI_FSR=0x%08X\n", p);	/*!< Offset 0x01C SPI FIFO Status Register */
	PRINTF("%s->SPI_WCR=0x%08X\n", p);	/*!< Offset 0x020 SPI Wait Clock Register */
	PRINTF("%s->SPI_SAMP_DL=0x%08X\n", p);	/*!< Offset 0x028 SPI Sample Delay Control Register */
	PRINTF("%s->SPI_MBC=0x%08X\n", p);	/*!< Offset 0x030 SPI Master Burst Counter Register */
	PRINTF("%s->SPI_MTC=0x%08X\n", p);	/*!< Offset 0x034 SPI Master Transmit Counter Register */
	PRINTF("%s->SPI_BCC=0x%08X\n", p);	/*!< Offset 0x038 SPI Master Burst Control Register */
	PRINTF("%s->SPI_BATCR=0x%08X\n", p);	/*!< Offset 0x040 SPI Bit-Aligned Transfer Configure Register */
	PRINTF("%s->SPI_BA_CCR=0x%08X\n", p);	/*!< Offset 0x044 SPI Bit-Aligned Clock Configuration Register */
	PRINTF("%s->SPI_TBR=0x%08X\n", p);	/*!< Offset 0x048 SPI TX Bit Register */
	PRINTF("%s->SPI_RBR=0x%08X\n", p);	/*!< Offset 0x04C SPI RX Bit Register */
	PRINTF("%s->SPI_NDMA_MODE_CTL=0x%08X\n", p);	/*!< Offset 0x088 SPI Normal DMA Mode Control Register */
	PRINTF("%s->DBI_CTL_0=0x%08X\n", p);	/*!< Offset 0x100 DBI Control Register 0 */
	PRINTF("%s->DBI_CTL_1=0x%08X\n", p);	/*!< Offset 0x104 DBI Control Register 1 */
	PRINTF("%s->DBI_CTL_2=0x%08X\n", p);	/*!< Offset 0x108 DBI Control Register 2 */
	PRINTF("%s->DBI_TIMER=0x%08X\n", p);	/*!< Offset 0x10C DBI Timer Control Register */
	PRINTF("%s->DBI_VIDEO_SZIE=0x%08X\n", p);	/*!< Offset 0x110 DBI Video Size Configuration Register */
	PRINTF("%s->DBI_INT=0x%08X\n", p);	/*!< Offset 0x120 DBI Interrupt Register */
	PRINTF("%s->DBI_DEBUG_0=0x%08X\n", p);	/*!< Offset 0x124 DBI BEBUG 0 Register */
	PRINTF("%s->DBI_DEBUG_1=0x%08X\n", p);	/*!< Offset 0x128 DBI BEBUG 1 Register */
	PRINTF("%s->SPI_TXD=0x%08X\n", p);	/*!< Offset 0x200 SPI TX Data register */
	PRINTF("%s->SPI_RXD=0x%08X\n", p);	/*!< Offset 0x300 SPI RX Data register */
}
/* Print CE */
static void CE_Type_print(const CE_TypeDef * p)
{
	PRINTF("%s->CE_TDA=0x%08X\n", p);	/*!< Offset 0x000 Task Descriptor Address */
	PRINTF("%s->CE_ICR=0x%08X\n", p);	/*!< Offset 0x008 Interrupt Control Register */
	PRINTF("%s->CE_ISR=0x%08X\n", p);	/*!< Offset 0x00C Interrupt Status Register */
	PRINTF("%s->CE_TLR=0x%08X\n", p);	/*!< Offset 0x010 Task Load Register */
	PRINTF("%s->CE_TSR=0x%08X\n", p);	/*!< Offset 0x014 Task Status Register */
	PRINTF("%s->CE_ESR=0x%08X\n", p);	/*!< Offset 0x018 Error Status Register */
	PRINTF("%s->CE_CSA=0x%08X\n", p);	/*!< Offset 0x024 DMA Current Source Address */
	PRINTF("%s->CE_CDA=0x%08X\n", p);	/*!< Offset 0x028 DMA Current Destination Address */
	PRINTF("%s->CE_TPR=0x%08X\n", p);	/*!< Offset 0x02C Throughput Register */
}
/* Print RTC */
static void RTC_Type_print(const RTC_TypeDef * p)
{
	PRINTF("%s->LOSC_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x000 Low Oscillator Control Register */
	PRINTF("%s->LOSC_AUTO_SWT_STA_REG=0x%08X\n", p);	/*!< Offset 0x004 Low Oscillator Auto Switch Status Register */
	PRINTF("%s->INTOSC_CLK_PRESCAL_REG=0x%08X\n", p);	/*!< Offset 0x008 Internal OSC Clock Pre-scaler Register */
	PRINTF("%s->RTC_DAY_REG=0x%08X\n", p);	/*!< Offset 0x010 RTC Year-Month-Day Register */
	PRINTF("%s->RTC_HH_MM_SS_REG=0x%08X\n", p);	/*!< Offset 0x014 RTC Hour-Minute-Second Register */
	PRINTF("%s->ALARM0_DAY_SET_REG=0x%08X\n", p);	/*!< Offset 0x020 Alarm 0 Day Setting Register */
	PRINTF("%s->ALARM0_CUR_VLU_REG=0x%08X\n", p);	/*!< Offset 0x024 Alarm 0 Counter Current Value Register */
	PRINTF("%s->ALARM0_ENABLE_REG=0x%08X\n", p);	/*!< Offset 0x028 Alarm 0 Enable Register */
	PRINTF("%s->ALARM0_IRQ_EN=0x%08X\n", p);	/*!< Offset 0x02C Alarm 0 IRQ Enable Register */
	PRINTF("%s->ALARM0_IRQ_STA_REG=0x%08X\n", p);	/*!< Offset 0x030 Alarm 0 IRQ Status Register */
	PRINTF("%s->ALARM_CONFIG_REG=0x%08X\n", p);	/*!< Offset 0x050 Alarm Configuration Register */
	PRINTF("%s->F32K_FOUT_CTRL_GATING_REG=0x%08X\n", p);	/*!< Offset 0x060 32K Fanout Control Gating Register */
	PRINTF("%s->FBOOT_INFO_REG0=0x%08X\n", p);	/*!< Offset 0x120 Fast Boot Information Register0 */
	PRINTF("%s->FBOOT_INFO_REG1=0x%08X\n", p);	/*!< Offset 0x124 Fast Boot Information Register1 */
	PRINTF("%s->DCXO_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x160 DCXO Control Register */
	PRINTF("%s->RTC_VIO_REG=0x%08X\n", p);	/*!< Offset 0x190 RTC_VIO Regulation Register */
	PRINTF("%s->IC_CHARA_REG=0x%08X\n", p);	/*!< Offset 0x1F0 IC Characteristic Register */
	PRINTF("%s->VDD_OFF_GATING_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x1F4 VDD Off Gating Control Register */
	PRINTF("%s->EFUSE_HV_PWRSWT_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x204 Efuse High Voltage Power Switch Control Register */
	PRINTF("%s->RTC_SPI_CLK_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x310 RTC SPI Clock Control Register */
}
/* Print IOMMU */
static void IOMMU_Type_print(const IOMMU_TypeDef * p)
{
	PRINTF("%s->IOMMU_RESET_REG=0x%08X\n", p);	/*!< Offset 0x010 IOMMU Reset Register */
	PRINTF("%s->IOMMU_ENABLE_REG=0x%08X\n", p);	/*!< Offset 0x020 IOMMU Enable Register */
	PRINTF("%s->IOMMU_BYPASS_REG=0x%08X\n", p);	/*!< Offset 0x030 IOMMU Bypass Register */
	PRINTF("%s->IOMMU_AUTO_GATING_REG=0x%08X\n", p);	/*!< Offset 0x040 IOMMU Auto Gating Register */
	PRINTF("%s->IOMMU_WBUF_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x044 IOMMU Write Buffer Control Register */
	PRINTF("%s->IOMMU_OOO_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x048 IOMMU Out of Order Control Register */
	PRINTF("%s->IOMMU_4KB_BDY_PRT_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x04C IOMMU 4KB Boundary Protect Control Register */
	PRINTF("%s->IOMMU_TTB_REG=0x%08X\n", p);	/*!< Offset 0x050 IOMMU Translation Table Base Register */
	PRINTF("%s->IOMMU_TLB_ENABLE_REG=0x%08X\n", p);	/*!< Offset 0x060 IOMMU TLB Enable Register */
	PRINTF("%s->IOMMU_TLB_PREFETCH_REG=0x%08X\n", p);	/*!< Offset 0x070 IOMMU TLB Prefetch Register */
	PRINTF("%s->IOMMU_TLB_FLUSH_ENABLE_REG=0x%08X\n", p);	/*!< Offset 0x080 IOMMU TLB Flush Enable Register */
	PRINTF("%s->IOMMU_TLB_IVLD_MODE_SEL_REG=0x%08X\n", p);	/*!< Offset 0x084 IOMMU TLB Invalidation Mode Select Register */
	PRINTF("%s->IOMMU_TLB_IVLD_STA_ADDR_REG=0x%08X\n", p);	/*!< Offset 0x088 IOMMU TLB Invalidation Start Address Register */
	PRINTF("%s->IOMMU_TLB_IVLD_END_ADDR_REG=0x%08X\n", p);	/*!< Offset 0x08C IOMMU TLB Invalidation End Address Register */
	PRINTF("%s->IOMMU_TLB_IVLD_ADDR_REG=0x%08X\n", p);	/*!< Offset 0x090 IOMMU TLB Invalidation Address Register */
	PRINTF("%s->IOMMU_TLB_IVLD_ADDR_MASK_REG=0x%08X\n", p);	/*!< Offset 0x094 IOMMU TLB Invalidation Address Mask Register */
	PRINTF("%s->IOMMU_TLB_IVLD_ENABLE_REG=0x%08X\n", p);	/*!< Offset 0x098 IOMMU TLB Invalidation Enable Register */
	PRINTF("%s->IOMMU_PC_IVLD_MODE_SEL_REG=0x%08X\n", p);	/*!< Offset 0x09C IOMMU PC Invalidation Mode Select Register */
	PRINTF("%s->IOMMU_PC_IVLD_ADDR_REG=0x%08X\n", p);	/*!< Offset 0x0A0 IOMMU PC Invalidation Address Register */
	PRINTF("%s->IOMMU_PC_IVLD_STA_ADDR_REG=0x%08X\n", p);	/*!< Offset 0x0A4 IOMMU PC Invalidation Start Address Register */
	PRINTF("%s->IOMMU_PC_IVLD_ENABLE_REG=0x%08X\n", p);	/*!< Offset 0x0A8 IOMMU PC Invalidation Enable Register */
	PRINTF("%s->IOMMU_PC_IVLD_END_ADDR_REG=0x%08X\n", p);	/*!< Offset 0x0AC IOMMU PC Invalidation End Address Register */
	PRINTF("%s->IOMMU_DM_AUT_CTRL0_REG=0x%08X\n", p);	/*!< Offset 0x0B0 IOMMU Domain Authority Control 0 Register */
	PRINTF("%s->IOMMU_DM_AUT_CTRL1_REG=0x%08X\n", p);	/*!< Offset 0x0B4 IOMMU Domain Authority Control 1 Register */
	PRINTF("%s->IOMMU_DM_AUT_CTRL2_REG=0x%08X\n", p);	/*!< Offset 0x0B8 IOMMU Domain Authority Control 2 Register */
	PRINTF("%s->IOMMU_DM_AUT_CTRL3_REG=0x%08X\n", p);	/*!< Offset 0x0BC IOMMU Domain Authority Control 3 Register */
	PRINTF("%s->IOMMU_DM_AUT_CTRL4_REG=0x%08X\n", p);	/*!< Offset 0x0C0 IOMMU Domain Authority Control 4 Register */
	PRINTF("%s->IOMMU_DM_AUT_CTRL5_REG=0x%08X\n", p);	/*!< Offset 0x0C4 IOMMU Domain Authority Control 5 Register */
	PRINTF("%s->IOMMU_DM_AUT_CTRL6_REG=0x%08X\n", p);	/*!< Offset 0x0C8 IOMMU Domain Authority Control 6 Register */
	PRINTF("%s->IOMMU_DM_AUT_CTRL7_REG=0x%08X\n", p);	/*!< Offset 0x0CC IOMMU Domain Authority Control 7 Register */
	PRINTF("%s->IOMMU_DM_AUT_OVWT_REG=0x%08X\n", p);	/*!< Offset 0x0D0 IOMMU Domain Authority Overwrite Register */
	PRINTF("%s->IOMMU_INT_ENABLE_REG=0x%08X\n", p);	/*!< Offset 0x100 IOMMU Interrupt Enable Register */
	PRINTF("%s->IOMMU_INT_CLR_REG=0x%08X\n", p);	/*!< Offset 0x104 IOMMU Interrupt Clear Register */
	PRINTF("%s->IOMMU_INT_STA_REG=0x%08X\n", p);	/*!< Offset 0x108 IOMMU Interrupt Status Register */
	PRINTF("%s->IOMMU_INT_ERR_ADDR0_REG=0x%08X\n", p);	/*!< Offset 0x110 IOMMU Interrupt Error Address 0 Register */
	PRINTF("%s->IOMMU_INT_ERR_ADDR1_REG=0x%08X\n", p);	/*!< Offset 0x114 IOMMU Interrupt Error Address 1 Register */
	PRINTF("%s->IOMMU_INT_ERR_ADDR2_REG=0x%08X\n", p);	/*!< Offset 0x118 IOMMU Interrupt Error Address 2 Register */
	PRINTF("%s->IOMMU_INT_ERR_ADDR3_REG=0x%08X\n", p);	/*!< Offset 0x11C IOMMU Interrupt Error Address 3 Register */
	PRINTF("%s->IOMMU_INT_ERR_ADDR4_REG=0x%08X\n", p);	/*!< Offset 0x120 IOMMU Interrupt Error Address 4 Register */
	PRINTF("%s->IOMMU_INT_ERR_ADDR5_REG=0x%08X\n", p);	/*!< Offset 0x124 IOMMU Interrupt Error Address 5 Register */
	PRINTF("%s->IOMMU_INT_ERR_ADDR6_REG=0x%08X\n", p);	/*!< Offset 0x128 IOMMU Interrupt Error Address 6 Register */
	PRINTF("%s->IOMMU_INT_ERR_ADDR7_REG=0x%08X\n", p);	/*!< Offset 0x130 IOMMU Interrupt Error Address 7 Register */
	PRINTF("%s->IOMMU_INT_ERR_ADDR8_REG=0x%08X\n", p);	/*!< Offset 0x134 IOMMU Interrupt Error Address 8 Register */
	PRINTF("%s->IOMMU_INT_ERR_DATA0_REG=0x%08X\n", p);	/*!< Offset 0x150 IOMMU Interrupt Error Data 0 Register */
	PRINTF("%s->IOMMU_INT_ERR_DATA1_REG=0x%08X\n", p);	/*!< Offset 0x154 IOMMU Interrupt Error Data 1 Register */
	PRINTF("%s->IOMMU_INT_ERR_DATA2_REG=0x%08X\n", p);	/*!< Offset 0x158 IOMMU Interrupt Error Data 2 Register */
	PRINTF("%s->IOMMU_INT_ERR_DATA3_REG=0x%08X\n", p);	/*!< Offset 0x15C IOMMU Interrupt Error Data 3 Register */
	PRINTF("%s->IOMMU_INT_ERR_DATA4_REG=0x%08X\n", p);	/*!< Offset 0x160 IOMMU Interrupt Error Data 4 Register */
	PRINTF("%s->IOMMU_INT_ERR_DATA5_REG=0x%08X\n", p);	/*!< Offset 0x164 IOMMU Interrupt Error Data 5 Register */
	PRINTF("%s->IOMMU_INT_ERR_DATA6_REG=0x%08X\n", p);	/*!< Offset 0x168 IOMMU Interrupt Error Data 6 Register */
	PRINTF("%s->IOMMU_INT_ERR_DATA7_REG=0x%08X\n", p);	/*!< Offset 0x170 IOMMU Interrupt Error Data 7 Register */
	PRINTF("%s->IOMMU_INT_ERR_DATA8_REG=0x%08X\n", p);	/*!< Offset 0x174 IOMMU Interrupt Error Data 8 Register */
	PRINTF("%s->IOMMU_L1PG_INT_REG=0x%08X\n", p);	/*!< Offset 0x180 IOMMU L1 Page Table Interrupt Register */
	PRINTF("%s->IOMMU_L2PG_INT_REG=0x%08X\n", p);	/*!< Offset 0x184 IOMMU L2 Page Table Interrupt Register */
	PRINTF("%s->IOMMU_VA_REG=0x%08X\n", p);	/*!< Offset 0x190 IOMMU Virtual Address Register */
	PRINTF("%s->IOMMU_VA_DATA_REG=0x%08X\n", p);	/*!< Offset 0x194 IOMMU Virtual Address Data Register */
	PRINTF("%s->IOMMU_VA_CONFIG_REG=0x%08X\n", p);	/*!< Offset 0x198 IOMMU Virtual Address Configuration Register */
	PRINTF("%s->IOMMU_PMU_ENABLE_REG=0x%08X\n", p);	/*!< Offset 0x200 IOMMU PMU Enable Register */
	PRINTF("%s->IOMMU_PMU_CLR_REG=0x%08X\n", p);	/*!< Offset 0x210 IOMMU PMU Clear Register */
	PRINTF("%s->IOMMU_PMU_ACCESS_LOW0_REG=0x%08X\n", p);	/*!< Offset 0x230 IOMMU PMU Access Low 0 Register */
	PRINTF("%s->IOMMU_PMU_ACCESS_HIGH0_REG=0x%08X\n", p);	/*!< Offset 0x234 IOMMU PMU Access High 0 Register */
	PRINTF("%s->IOMMU_PMU_HIT_LOW0_REG=0x%08X\n", p);	/*!< Offset 0x238 IOMMU PMU Hit Low 0 Register */
	PRINTF("%s->IOMMU_PMU_HIT_HIGH0_REG=0x%08X\n", p);	/*!< Offset 0x23C IOMMU PMU Hit High 0 Register */
	PRINTF("%s->IOMMU_PMU_ACCESS_LOW1_REG=0x%08X\n", p);	/*!< Offset 0x240 IOMMU PMU Access Low 1 Register */
	PRINTF("%s->IOMMU_PMU_ACCESS_HIGH1_REG=0x%08X\n", p);	/*!< Offset 0x244 IOMMU PMU Access High 1 Register */
	PRINTF("%s->IOMMU_PMU_HIT_LOW1_REG=0x%08X\n", p);	/*!< Offset 0x248 IOMMU PMU Hit Low 1 Register */
	PRINTF("%s->IOMMU_PMU_HIT_HIGH1_REG=0x%08X\n", p);	/*!< Offset 0x24C IOMMU PMU Hit High 1 Register */
	PRINTF("%s->IOMMU_PMU_ACCESS_LOW2_REG=0x%08X\n", p);	/*!< Offset 0x250 IOMMU PMU Access Low 2 Register */
	PRINTF("%s->IOMMU_PMU_ACCESS_HIGH2_REG=0x%08X\n", p);	/*!< Offset 0x254 IOMMU PMU Access High 2 Register */
	PRINTF("%s->IOMMU_PMU_HIT_LOW2_REG=0x%08X\n", p);	/*!< Offset 0x258 IOMMU PMU Hit Low 2 Register */
	PRINTF("%s->IOMMU_PMU_HIT_HIGH2_REG=0x%08X\n", p);	/*!< Offset 0x25C IOMMU PMU Hit High 2 Register */
	PRINTF("%s->IOMMU_PMU_ACCESS_LOW3_REG=0x%08X\n", p);	/*!< Offset 0x260 IOMMU PMU Access Low 3 Register */
	PRINTF("%s->IOMMU_PMU_ACCESS_HIGH3_REG=0x%08X\n", p);	/*!< Offset 0x264 IOMMU PMU Access High 3 Register */
	PRINTF("%s->IOMMU_PMU_HIT_LOW3_REG=0x%08X\n", p);	/*!< Offset 0x268 IOMMU PMU Hit Low 3 Register */
	PRINTF("%s->IOMMU_PMU_HIT_HIGH3_REG=0x%08X\n", p);	/*!< Offset 0x26C IOMMU PMU Hit High 3 Register */
	PRINTF("%s->IOMMU_PMU_ACCESS_LOW4_REG=0x%08X\n", p);	/*!< Offset 0x270 IOMMU PMU Access Low 4 Register */
	PRINTF("%s->IOMMU_PMU_ACCESS_HIGH4_REG=0x%08X\n", p);	/*!< Offset 0x274 IOMMU PMU Access High 4 Register */
	PRINTF("%s->IOMMU_PMU_HIT_LOW4_REG=0x%08X\n", p);	/*!< Offset 0x278 IOMMU PMU Hit Low 4 Register */
	PRINTF("%s->IOMMU_PMU_HIT_HIGH4_REG=0x%08X\n", p);	/*!< Offset 0x27C IOMMU PMU Hit High 4 Register */
	PRINTF("%s->IOMMU_PMU_ACCESS_LOW5_REG=0x%08X\n", p);	/*!< Offset 0x280 IOMMU PMU Access Low 5 Register */
	PRINTF("%s->IOMMU_PMU_ACCESS_HIGH5_REG=0x%08X\n", p);	/*!< Offset 0x284 IOMMU PMU Access High 5 Register */
	PRINTF("%s->IOMMU_PMU_HIT_LOW5_REG=0x%08X\n", p);	/*!< Offset 0x288 IOMMU PMU Hit Low 5 Register */
	PRINTF("%s->IOMMU_PMU_HIT_HIGH5_REG=0x%08X\n", p);	/*!< Offset 0x28C IOMMU PMU Hit High 5 Register */
	PRINTF("%s->IOMMU_PMU_ACCESS_LOW6_REG=0x%08X\n", p);	/*!< Offset 0x290 IOMMU PMU Access Low 6 Register */
	PRINTF("%s->IOMMU_PMU_ACCESS_HIGH6_REG=0x%08X\n", p);	/*!< Offset 0x294 IOMMU PMU Access High 6 Register */
	PRINTF("%s->IOMMU_PMU_HIT_LOW6_REG=0x%08X\n", p);	/*!< Offset 0x298 IOMMU PMU Hit Low 6 Register */
	PRINTF("%s->IOMMU_PMU_HIT_HIGH6_REG=0x%08X\n", p);	/*!< Offset 0x29C IOMMU PMU Hit High 6 Register */
	PRINTF("%s->IOMMU_PMU_ACCESS_LOW7_REG=0x%08X\n", p);	/*!< Offset 0x2D0 IOMMU PMU Access Low 7 Register */
	PRINTF("%s->IOMMU_PMU_ACCESS_HIGH7_REG=0x%08X\n", p);	/*!< Offset 0x2D4 IOMMU PMU Access High 7 Register */
	PRINTF("%s->IOMMU_PMU_HIT_LOW7_REG=0x%08X\n", p);	/*!< Offset 0x2D8 IOMMU PMU Hit Low 7 Register */
	PRINTF("%s->IOMMU_PMU_HIT_HIGH7_REG=0x%08X\n", p);	/*!< Offset 0x2DC IOMMU PMU Hit High 7 Register */
	PRINTF("%s->IOMMU_PMU_ACCESS_LOW8_REG=0x%08X\n", p);	/*!< Offset 0x2E0 IOMMU PMU Access Low 8 Register */
	PRINTF("%s->IOMMU_PMU_ACCESS_HIGH8_REG=0x%08X\n", p);	/*!< Offset 0x2E4 IOMMU PMU Access High 8 Register */
	PRINTF("%s->IOMMU_PMU_HIT_LOW8_REG=0x%08X\n", p);	/*!< Offset 0x2E8 IOMMU PMU Hit Low 8 Register */
	PRINTF("%s->IOMMU_PMU_HIT_HIGH8_REG=0x%08X\n", p);	/*!< Offset 0x2EC IOMMU PMU Hit High 8 Register */
	PRINTF("%s->IOMMU_PMU_TL_LOW0_REG=0x%08X\n", p);	/*!< Offset 0x300 IOMMU Total Latency Low 0 Register */
	PRINTF("%s->IOMMU_PMU_TL_HIGH0_REG=0x%08X\n", p);	/*!< Offset 0x304 IOMMU Total Latency High 0 Register */
	PRINTF("%s->IOMMU_PMU_ML0_REG=0x%08X\n", p);	/*!< Offset 0x308 IOMMU Max Latency 0 Register */
	PRINTF("%s->IOMMU_PMU_TL_LOW1_REG=0x%08X\n", p);	/*!< Offset 0x310 IOMMU Total Latency Low 1 Register */
	PRINTF("%s->IOMMU_PMU_TL_HIGH1_REG=0x%08X\n", p);	/*!< Offset 0x314 IOMMU Total Latency High 1 Register */
	PRINTF("%s->IOMMU_PMU_ML1_REG=0x%08X\n", p);	/*!< Offset 0x318 IOMMU Max Latency 1 Register */
	PRINTF("%s->IOMMU_PMU_TL_LOW2_REG=0x%08X\n", p);	/*!< Offset 0x320 IOMMU Total Latency Low 2 Register */
	PRINTF("%s->IOMMU_PMU_TL_HIGH2_REG=0x%08X\n", p);	/*!< Offset 0x324 IOMMU Total Latency High 2 Register */
	PRINTF("%s->IOMMU_PMU_ML2_REG=0x%08X\n", p);	/*!< Offset 0x328 IOMMU Max Latency 2 Register */
	PRINTF("%s->IOMMU_PMU_TL_LOW3_REG=0x%08X\n", p);	/*!< Offset 0x330 IOMMU Total Latency Low 3 Register */
	PRINTF("%s->IOMMU_PMU_TL_HIGH3_REG=0x%08X\n", p);	/*!< Offset 0x334 IOMMU Total Latency High 3 Register */
	PRINTF("%s->IOMMU_PMU_ML3_REG=0x%08X\n", p);	/*!< Offset 0x338 IOMMU Max Latency 3 Register */
	PRINTF("%s->IOMMU_PMU_TL_LOW4_REG=0x%08X\n", p);	/*!< Offset 0x340 IOMMU Total Latency Low 4 Register */
	PRINTF("%s->IOMMU_PMU_TL_HIGH4_REG=0x%08X\n", p);	/*!< Offset 0x344 IOMMU Total Latency High 4 Register */
	PRINTF("%s->IOMMU_PMU_ML4_REG=0x%08X\n", p);	/*!< Offset 0x348 IOMMU Max Latency 4 Register */
	PRINTF("%s->IOMMU_PMU_TL_LOW5_REG=0x%08X\n", p);	/*!< Offset 0x350 IOMMU Total Latency Low 5 Register */
	PRINTF("%s->IOMMU_PMU_TL_HIGH5_REG=0x%08X\n", p);	/*!< Offset 0x354 IOMMU Total Latency High 5 Register */
	PRINTF("%s->IOMMU_PMU_ML5_REG=0x%08X\n", p);	/*!< Offset 0x358 IOMMU Max Latency 5 Register */
	PRINTF("%s->IOMMU_PMU_TL_LOW6_REG=0x%08X\n", p);	/*!< Offset 0x360 IOMMU Total Latency Low 6 Register */
	PRINTF("%s->IOMMU_PMU_TL_HIGH6_REG=0x%08X\n", p);	/*!< Offset 0x364 IOMMU Total Latency High 6 Register */
	PRINTF("%s->IOMMU_PMU_ML6_REG=0x%08X\n", p);	/*!< Offset 0x368 IOMMU Max Latency 6 Register */
}
/* Print THS */
static void THS_Type_print(const THS_TypeDef * p)
{
	PRINTF("%s->THS_CTRL=0x%08X\n", p);	/*!< Offset 0x000 THS Control Register */
	PRINTF("%s->THS_EN=0x%08X\n", p);	/*!< Offset 0x004 THS Enable Register */
	PRINTF("%s->THS_PER=0x%08X\n", p);	/*!< Offset 0x008 THS Period Control Register */
	PRINTF("%s->THS_DATA_INTC=0x%08X\n", p);	/*!< Offset 0x010 THS Data Interrupt Control Register */
	PRINTF("%s->THS_SHUT_INTC=0x%08X\n", p);	/*!< Offset 0x014 THS Shut Interrupt Control Register */
	PRINTF("%s->THS_ALARM_INTC=0x%08X\n", p);	/*!< Offset 0x018 THS Alarm Interrupt Control Register */
	PRINTF("%s->THS_DATA_INTS=0x%08X\n", p);	/*!< Offset 0x020 THS Data Interrupt Status Register */
	PRINTF("%s->THS_SHUT_INTS=0x%08X\n", p);	/*!< Offset 0x024 THS Shut Interrupt Status Register */
	PRINTF("%s->THS_ALARMO_INTS=0x%08X\n", p);	/*!< Offset 0x028 THS Alarm off Interrupt Status Register */
	PRINTF("%s->THS_ALARM_INTS=0x%08X\n", p);	/*!< Offset 0x02C THS Alarm Interrupt Status Register */
	PRINTF("%s->THS_FILTER=0x%08X\n", p);	/*!< Offset 0x030 THS Median Filter Control Register */
	PRINTF("%s->THS_ALARM_CTRL=0x%08X\n", p);	/*!< Offset 0x040 THS Alarm Threshold Control Register */
	PRINTF("%s->THS_SHUTDOWN_CTRL=0x%08X\n", p);	/*!< Offset 0x080 THS Shutdown Threshold Control Register */
	PRINTF("%s->THS_CDATA=0x%08X\n", p);	/*!< Offset 0x0A0 THS Calibration Data */
	PRINTF("%s->THS_DATA=0x%08X\n", p);	/*!< Offset 0x0C0 THS Data Register */
}
/* Print TIMER */
static void TIMER_Type_print(const TIMER_TypeDef * p)
{
	PRINTF("%s->TMR_IRQ_EN_REG=0x%08X\n", p);	/*!< Offset 0x000 Timer IRQ Enable Register */
	PRINTF("%s->TMR_IRQ_STA_REG=0x%08X\n", p);	/*!< Offset 0x004 Timer Status Register */
	PRINTF("%s->TMR0_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x010 Timer0 Control Register */
	PRINTF("%s->TMR0_INTV_VALUE_REG=0x%08X\n", p);	/*!< Offset 0x014 Timer0 Interval Value Register */
	PRINTF("%s->TMR0_CUR_VALUE_REG=0x%08X\n", p);	/*!< Offset 0x018 Timer0 Current Value Register */
	PRINTF("%s->TMR1_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x020 Timer1 Control Register */
	PRINTF("%s->TMR1_INTV_VALUE_REG=0x%08X\n", p);	/*!< Offset 0x024 Timer1 Interval Value Register */
	PRINTF("%s->TMR1_CUR_VALUE_REG=0x%08X\n", p);	/*!< Offset 0x028 Timer1 Current Value Register */
	PRINTF("%s->WDOG_IRQ_EN_REG=0x%08X\n", p);	/*!< Offset 0x0A0 Watchdog IRQ Enable Register */
	PRINTF("%s->WDOG_IRQ_STA_REG=0x%08X\n", p);	/*!< Offset 0x0A4 Watchdog Status Register */
	PRINTF("%s->WDOG_SOFT_RST_REG=0x%08X\n", p);	/*!< Offset 0x0A8 Watchdog Software Reset Register */
	PRINTF("%s->WDOG_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x0B0 Watchdog Control Register */
	PRINTF("%s->WDOG_CFG_REG=0x%08X\n", p);	/*!< Offset 0x0B4 Watchdog Configuration Register */
	PRINTF("%s->WDOG_MODE_REG=0x%08X\n", p);	/*!< Offset 0x0B8 Watchdog Mode Register */
	PRINTF("%s->WDOG_OUTPUT_CFG_REG=0x%08X\n", p);	/*!< Offset 0x0BC Watchdog Output Configuration Register */
	PRINTF("%s->AVS_CNT_CTL_REG=0x%08X\n", p);	/*!< Offset 0x0C0 AVS Control Register */
	PRINTF("%s->AVS_CNT0_REG=0x%08X\n", p);	/*!< Offset 0x0C4 AVS Counter 0 Register */
	PRINTF("%s->AVS_CNT1_REG=0x%08X\n", p);	/*!< Offset 0x0C8 AVS Counter 1 Register */
	PRINTF("%s->AVS_CNT_DIV_REG=0x%08X\n", p);	/*!< Offset 0x0CC AVS Divisor Register */
}
/* Print HSTIMER */
static void HSTIMER_Type_print(const HSTIMER_TypeDef * p)
{
	PRINTF("%s->HS_TMR_IRQ_EN_REG=0x%08X\n", p);	/*!< Offset 0x000 HS Timer IRQ Enable Register */
	PRINTF("%s->HS_TMR_IRQ_STAS_REG=0x%08X\n", p);	/*!< Offset 0x004 HS Timer Status Register */
	PRINTF("%s->HS_TMR0_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x020 HS Timer0 Control Register */
	PRINTF("%s->HS_TMR0_INTV_LO_REG=0x%08X\n", p);	/*!< Offset 0x024 HS Timer0 Interval Value Low Register */
	PRINTF("%s->HS_TMR0_INTV_HI_REG=0x%08X\n", p);	/*!< Offset 0x028 HS Timer0 Interval Value High Register */
	PRINTF("%s->HS_TMR0_CURNT_LO_REG=0x%08X\n", p);	/*!< Offset 0x02C HS Timer0 Current Value Low Register */
	PRINTF("%s->HS_TMR0_CURNT_HI_REG=0x%08X\n", p);	/*!< Offset 0x030 HS Timer0 Current Value High Register */
	PRINTF("%s->HS_TMR1_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x040 HS Timer1 Control Register */
	PRINTF("%s->HS_TMR1_INTV_LO_REG=0x%08X\n", p);	/*!< Offset 0x044 HS Timer1 Interval Value Low Register */
	PRINTF("%s->HS_TMR1_INTV_HI_REG=0x%08X\n", p);	/*!< Offset 0x048 HS Timer1 Interval Value High Register */
	PRINTF("%s->HS_TMR1_CURNT_LO_REG=0x%08X\n", p);	/*!< Offset 0x04C HS Timer1 Current Value Low Register */
	PRINTF("%s->HS_TMR1_CURNT_HI_REG=0x%08X\n", p);	/*!< Offset 0x050 HS Timer1 Current Value High Register */
}
/* Print CAN */
static void CAN_Type_print(const CAN_TypeDef * p)
{
	PRINTF("%s->CAN_MSEL=0x%08X\n", p);	/*!< Offset 0x000 CAN mode select register */
	PRINTF("%s->CAN_CMD=0x%08X\n", p);	/*!< Offset 0x004 CAN command register */
	PRINTF("%s->CAN_STA=0x%08X\n", p);	/*!< Offset 0x008 CAN status register */
	PRINTF("%s->CAN_INT=0x%08X\n", p);	/*!< Offset 0x00C CAN interrupt register */
	PRINTF("%s->CAN_INTEN=0x%08X\n", p);	/*!< Offset 0x010 CAN interrupt enable register */
	PRINTF("%s->CAN_BUSTIME=0x%08X\n", p);	/*!< Offset 0x014 CAN bus timing register */
	PRINTF("%s->CAN_TEWL=0x%08X\n", p);	/*!< Offset 0x018 CAN TX error warning limit register */
	PRINTF("%s->CAN_ERRC=0x%08X\n", p);	/*!< Offset 0x01C CAN error counter register */
	PRINTF("%s->CAN_RMCNT=0x%08X\n", p);	/*!< Offset 0x020 CAN receive message counter register */
	PRINTF("%s->CAN_RBUF_SADDR=0x%08X\n", p);	/*!< Offset 0x024 CAN receive buffer start address register */
	PRINTF("%s->CAN_ACPC=0x%08X\n", p);	/*!< Offset 0x028 CAN acceptance code 0 register(reset mode) */
	PRINTF("%s->CAN_ACPM=0x%08X\n", p);	/*!< Offset 0x02C CAN acceptance mask 0 register(reset mode) */
	PRINTF("%s->CAN_VERSION=0x%08X\n", p);	/*!< Offset 0x300 CAN Version Register */
}
/* Print USBEHCI */
static void USBEHCI_Type_print(const USBEHCI_TypeDef * p)
{
	PRINTF("%s->E_CAPLENGTH=0x%08X\n", p);	/*!< Offset 0x000 EHCI Capability Register Length Register */
	PRINTF("%s->E_HCIVERSION=0x%08X\n", p);	/*!< Offset 0x002 EHCI Host Interface Version Number Register */
	PRINTF("%s->E_HCSPARAMS=0x%08X\n", p);	/*!< Offset 0x004 EHCI Host Control Structural Parameter Register */
	PRINTF("%s->E_HCCPARAMS=0x%08X\n", p);	/*!< Offset 0x008 EHCI Host Control Capability Parameter Register */
	PRINTF("%s->E_HCSPPORTROUTE=0x%08X\n", p);	/*!< Offset 0x00C EHCI Companion Port Route Description */
	PRINTF("%s->E_USBCMD=0x%08X\n", p);	/*!< Offset 0x010 EHCI USB Command Register */
	PRINTF("%s->E_USBSTS=0x%08X\n", p);	/*!< Offset 0x014 EHCI USB Status Register */
	PRINTF("%s->E_USBINTR=0x%08X\n", p);	/*!< Offset 0x018 EHCI USB Interrupt Enable Register */
	PRINTF("%s->E_FRINDEX=0x%08X\n", p);	/*!< Offset 0x01C EHCI USB Frame Index Register */
	PRINTF("%s->E_CTRLDSSEGMENT=0x%08X\n", p);	/*!< Offset 0x020 EHCI 4G Segment Selector Register */
	PRINTF("%s->E_PERIODICLISTBASE=0x%08X\n", p);	/*!< Offset 0x024 EHCI Frame List Base Address Register */
	PRINTF("%s->E_ASYNCLISTADDR=0x%08X\n", p);	/*!< Offset 0x028 EHCI Next Asynchronous List Address Register */
	PRINTF("%s->E_CONFIGFLAG=0x%08X\n", p);	/*!< Offset 0x050 EHCI Configured Flag Register */
	PRINTF("%s->E_PORTSC=0x%08X\n", p);	/*!< Offset 0x054 EHCI Port Status/Control Register */
	PRINTF("%s->O_HcRevision=0x%08X\n", p);	/*!< Offset 0x400 OHCI Revision Register (not documented) */
	PRINTF("%s->O_HcControl=0x%08X\n", p);	/*!< Offset 0x404 OHCI Control Register */
	PRINTF("%s->O_HcCommandStatus=0x%08X\n", p);	/*!< Offset 0x408 OHCI Command Status Register */
	PRINTF("%s->O_HcInterruptStatus=0x%08X\n", p);	/*!< Offset 0x40C OHCI Interrupt Status Register */
	PRINTF("%s->O_HcInterruptEnable=0x%08X\n", p);	/*!< Offset 0x410 OHCI Interrupt Enable Register */
	PRINTF("%s->O_HcInterruptDisable=0x%08X\n", p);	/*!< Offset 0x414 OHCI Interrupt Disable Register */
	PRINTF("%s->O_HcHCCA=0x%08X\n", p);	/*!< Offset 0x418 OHCI HCCA Base */
	PRINTF("%s->O_HcPeriodCurrentED=0x%08X\n", p);	/*!< Offset 0x41C OHCI Period Current ED Base */
	PRINTF("%s->O_HcControlHeadED=0x%08X\n", p);	/*!< Offset 0x420 OHCI Control Head ED Base */
	PRINTF("%s->O_HcControlCurrentED=0x%08X\n", p);	/*!< Offset 0x424 OHCI Control Current ED Base */
	PRINTF("%s->O_HcBulkHeadED=0x%08X\n", p);	/*!< Offset 0x428 OHCI Bulk Head ED Base */
	PRINTF("%s->O_HcBulkCurrentED=0x%08X\n", p);	/*!< Offset 0x42C OHCI Bulk Current ED Base */
	PRINTF("%s->O_HcDoneHead=0x%08X\n", p);	/*!< Offset 0x430 OHCI Done Head Base */
	PRINTF("%s->O_HcFmInterval=0x%08X\n", p);	/*!< Offset 0x434 OHCI Frame Interval Register */
	PRINTF("%s->O_HcFmRemaining=0x%08X\n", p);	/*!< Offset 0x438 OHCI Frame Remaining Register */
	PRINTF("%s->O_HcFmNumber=0x%08X\n", p);	/*!< Offset 0x43C OHCI Frame Number Register */
	PRINTF("%s->O_HcPerioddicStart=0x%08X\n", p);	/*!< Offset 0x440 OHCI Periodic Start Register */
	PRINTF("%s->O_HcLSThreshold=0x%08X\n", p);	/*!< Offset 0x444 OHCI LS Threshold Register */
	PRINTF("%s->O_HcRhDescriptorA=0x%08X\n", p);	/*!< Offset 0x448 OHCI Root Hub Descriptor Register A */
	PRINTF("%s->O_HcRhDesriptorB=0x%08X\n", p);	/*!< Offset 0x44C OHCI Root Hub Descriptor Register B */
	PRINTF("%s->O_HcRhStatus=0x%08X\n", p);	/*!< Offset 0x450 OHCI Root Hub Status Register */
	PRINTF("%s->O_HcRhPortStatus=0x%08X\n", p);	/*!< Offset 0x454 OHCI Root Hub Port Status Register */
}
/* Print USBOTGFIFO */
static void USBOTGFIFO_Type_print(const USBOTGFIFO_TypeDef * p)
{
	PRINTF("%s->USB_TXFADDR=0x%08X\n", p);	/*!< Offset 0x000 USB_TXFADDR */
	PRINTF("%s->USB_TXHADDR=0x%08X\n", p);	/*!< Offset 0x002 USB_TXHADDR */
	PRINTF("%s->USB_TXHUBPORT=0x%08X\n", p);	/*!< Offset 0x003 USB_TXHUBPORT */
	PRINTF("%s->USB_RXFADDR=0x%08X\n", p);	/*!< Offset 0x004 USB_RXFADDR */
	PRINTF("%s->USB_RXHADDR=0x%08X\n", p);	/*!< Offset 0x006 USB_RXHADDR */
	PRINTF("%s->USB_RXHUBPORT=0x%08X\n", p);	/*!< Offset 0x007 USB_RXHUBPORT */
}
/* Print USBOTG */
static void USBOTG_Type_print(const USBOTG_TypeDef * p)
{
	PRINTF("%s->USB_POWER=0x%08X\n", p);	/*!< Offset 0x040 USB_POWER */
	PRINTF("%s->USB_DEVCTL=0x%08X\n", p);	/*!< Offset 0x041 USB_DEVCTL */
	PRINTF("%s->USB_EPINDEX=0x%08X\n", p);	/*!< Offset 0x042 USB_EPINDEX */
	PRINTF("%s->USB_DMACTL=0x%08X\n", p);	/*!< Offset 0x043 USB_DMACTL */
	PRINTF("%s->USB_INTTX=0x%08X\n", p);	/*!< Offset 0x044 USB_INTTX */
	PRINTF("%s->USB_INTRX=0x%08X\n", p);	/*!< Offset 0x046 USB_INTRX */
	PRINTF("%s->USB_INTTXE=0x%08X\n", p);	/*!< Offset 0x048 USB_INTTXE */
	PRINTF("%s->USB_INTRXE=0x%08X\n", p);	/*!< Offset 0x04A USB_INTRXE */
	PRINTF("%s->USB_INTUSB=0x%08X\n", p);	/*!< Offset 0x04C USB_INTUSB */
	PRINTF("%s->USB_INTUSBE=0x%08X\n", p);	/*!< Offset 0x050 USB_INTUSBE */
	PRINTF("%s->USB_FRAME=0x%08X\n", p);	/*!< Offset 0x054 USB_FRAME */
	PRINTF("%s->USB_TESTMODE=0x%08X\n", p);	/*!< Offset 0x07C USB_TESTMODE */
	PRINTF("%s->USB_FSM=0x%08X\n", p);	/*!< Offset 0x07E USB_FSM */
	PRINTF("%s->USB_TXMAXP=0x%08X\n", p);	/*!< Offset 0x080 USB_TXMAXP */
	PRINTF("%s->USB_CSR0=0x%08X\n", p);	/*!< Offset 0x082 [15:8]: USB_TXCSRH, [7:0]: USB_TXCSRL */
	PRINTF("%s->USB_RXMAXP=0x%08X\n", p);	/*!< Offset 0x084 USB_RXMAXP */
	PRINTF("%s->USB_RXCSR=0x%08X\n", p);	/*!< Offset 0x086 USB_RXCSR */
	PRINTF("%s->USB_RXCOUNT=0x%08X\n", p);	/*!< Offset 0x088 USB_RXCOUNT */
	PRINTF("%s->USB_RXPKTCNT=0x%08X\n", p);	/*!< Offset 0x08A USB_RXPKTCNT */
	PRINTF("%s->USB_TXTI=0x%08X\n", p);	/*!< Offset 0x08C USB_TXTI */
	PRINTF("%s->USB_TXNAKLIMIT=0x%08X\n", p);	/*!< Offset 0x08D USB_TXNAKLIMIT */
	PRINTF("%s->USB_RXTI=0x%08X\n", p);	/*!< Offset 0x08E USB_RXTI */
	PRINTF("%s->USB_RXNAKLIMIT=0x%08X\n", p);	/*!< Offset 0x08F USB_RXNAKLIMIT */
	PRINTF("%s->USB_TXFIFOSZ=0x%08X\n", p);	/*!< Offset 0x090 USB_TXFIFOSZ */
	PRINTF("%s->USB_TXFIFOADD=0x%08X\n", p);	/*!< Offset 0x092 USB_TXFIFOADD */
	PRINTF("%s->USB_RXFIFOSZ=0x%08X\n", p);	/*!< Offset 0x094 USB_RXFIFOSZ */
	PRINTF("%s->USB_RXFIFOADD=0x%08X\n", p);	/*!< Offset 0x096 USB_RXFIFOADD */
	PRINTF("%s->USB_ISCR=0x%08X\n", p);	/*!< Offset 0x400 HCI Interface Register (HCI_Interface) */
	PRINTF("%s->USBPHY_PHYCTL=0x%08X\n", p);	/*!< Offset 0x404 USBPHY_PHYCTL */
	PRINTF("%s->HCI_CTRL3=0x%08X\n", p);	/*!< Offset 0x408 HCI Control 3 Register (bist) */
	PRINTF("%s->PHY_CTRL=0x%08X\n", p);	/*!< Offset 0x410 PHY Control Register (PHY_Control) */
	PRINTF("%s->PHY_OTGCTL=0x%08X\n", p);	/*!< Offset 0x420 Control PHY routing to EHCI or OTG */
	PRINTF("%s->PHY_STATUS=0x%08X\n", p);	/*!< Offset 0x424 PHY Status Register */
	PRINTF("%s->USB_SPDCR=0x%08X\n", p);	/*!< Offset 0x428 HCI SIE Port Disable Control Register */
}
/* Print USBPHYC */
static void USBPHYC_Type_print(const USBPHYC_TypeDef * p)
{
	PRINTF("%s->USB_CTRL=0x%08X\n", p);	/*!< Offset 0x000 HCI Interface Register (HCI_Interface) */
	PRINTF("%s->USBPHY_PHYCTL=0x%08X\n", p);	/*!< Offset 0x004 USBPHY_PHYCTL */
	PRINTF("%s->HCI_CTRL3=0x%08X\n", p);	/*!< Offset 0x008 HCI Control 3 Register (bist) */
	PRINTF("%s->PHY_CTRL=0x%08X\n", p);	/*!< Offset 0x010 PHY Control Register (PHY_Control) */
	PRINTF("%s->PHY_OTGCTL=0x%08X\n", p);	/*!< Offset 0x020 Control PHY routing to EHCI or OTG */
	PRINTF("%s->PHY_STATUS=0x%08X\n", p);	/*!< Offset 0x024 PHY Status Register */
	PRINTF("%s->USB_SPDCR=0x%08X\n", p);	/*!< Offset 0x028 HCI SIE Port Disable Control Register */
}
/* Print G2D_TOP */
static void G2D_TOP_Type_print(const G2D_TOP_TypeDef * p)
{
	PRINTF("%s->G2D_SCLK_GATE=0x%08X\n", p);	/*!< Offset 0x000 G2D SCLK gate   */
	PRINTF("%s->G2D_HCLK_GATE=0x%08X\n", p);	/*!< Offset 0x004 g2d HCLK gate   */
	PRINTF("%s->G2D_AHB_RESET=0x%08X\n", p);	/*!< Offset 0x008 G2D AHB reset   */
	PRINTF("%s->G2D_SCLK_DIV=0x%08X\n", p);	/*!< Offset 0x00C G2D SCLK div    */
}
/* Print G2D_MIXER */
static void G2D_MIXER_Type_print(const G2D_MIXER_TypeDef * p)
{
	PRINTF("%s->G2D_MIXER_CTL=0x%08X\n", p);	/*!< Offset 0x000 G2D mixer control */
	PRINTF("%s->G2D_MIXER_INT=0x%08X\n", p);	/*!< Offset 0x004 G2D mixer interrupt */
	PRINTF("%s->G2D_MIXER_CLK=0x%08X\n", p);	/*!< Offset 0x008 G2D mixer clock */
}
/* Print G2D_LAY */
static void G2D_LAY_Type_print(const G2D_LAY_TypeDef * p)
{
	PRINTF("%s->V0_ATTCTL=0x%08X\n", p);	/*!< Offset 0x000 V0_ATTCTL */
	PRINTF("%s->V0_MBSIZE=0x%08X\n", p);	/*!< Offset 0x004 Source rectangle size (may be empty) */
	PRINTF("%s->V0_COOR=0x%08X\n", p);	/*!< Offset 0x008 Target window position */
	PRINTF("%s->V0_PITCH0=0x%08X\n", p);	/*!< Offset 0x00C V0_PITCH0 */
	PRINTF("%s->V0_PITCH1=0x%08X\n", p);	/*!< Offset 0x010 V0_PITCH1 */
	PRINTF("%s->V0_PITCH2=0x%08X\n", p);	/*!< Offset 0x014 V0_PITCH2 */
	PRINTF("%s->V0_LADD0=0x%08X\n", p);	/*!< Offset 0x018 V0_LADD0 */
	PRINTF("%s->V0_LADD1=0x%08X\n", p);	/*!< Offset 0x01C V0_LADD1 */
	PRINTF("%s->V0_LADD2=0x%08X\n", p);	/*!< Offset 0x020 V0_LADD2 */
	PRINTF("%s->V0_FILLC=0x%08X\n", p);	/*!< Offset 0x024 V0_FILLC */
	PRINTF("%s->V0_HADD=0x%08X\n", p);	/*!< Offset 0x028 [31:24]: 0, [23:16]: LADD2 bits 40..32, [15:8]: LADD1 bits 40..32, [7:0]: LADD0 bits 40..32 */
	PRINTF("%s->V0_SIZE=0x%08X\n", p);	/*!< Offset 0x02C Source window size (may not be empty) */
	PRINTF("%s->V0_HDS_CTL0=0x%08X\n", p);	/*!< Offset 0x030 V0_HDS_CTL0 */
	PRINTF("%s->V0_HDS_CTL1=0x%08X\n", p);	/*!< Offset 0x034 V0_HDS_CTL1 */
	PRINTF("%s->V0_VDS_CTL0=0x%08X\n", p);	/*!< Offset 0x038 V0_VDS_CTL0 */
	PRINTF("%s->V0_VDS_CTL1=0x%08X\n", p);	/*!< Offset 0x03C V0_VDS_CTL1 */
}
/* Print G2D_UI */
static void G2D_UI_Type_print(const G2D_UI_TypeDef * p)
{
	PRINTF("%s->UI_ATTR=0x%08X\n", p);	/*!< Offset 0x000 UIx_ATTR */
	PRINTF("%s->UI_MBSIZE=0x%08X\n", p);	/*!< Offset 0x004 UIx_MBSIZE */
	PRINTF("%s->UI_COOR=0x%08X\n", p);	/*!< Offset 0x008 UIx_COOR */
	PRINTF("%s->UI_PITCH=0x%08X\n", p);	/*!< Offset 0x00C UIx_PITCH */
	PRINTF("%s->UI_LADD=0x%08X\n", p);	/*!< Offset 0x010 UIx_LADD */
	PRINTF("%s->UI_FILLC=0x%08X\n", p);	/*!< Offset 0x014 UIx_FILLC */
	PRINTF("%s->UI_HADD=0x%08X\n", p);	/*!< Offset 0x018 UIx_HADD */
	PRINTF("%s->UI_SIZE=0x%08X\n", p);	/*!< Offset 0x01C UIx_SIZE */
}
/* Print G2D_VSU */
static void G2D_VSU_Type_print(const G2D_VSU_TypeDef * p)
{
	PRINTF("%s->VS_CTRL=0x%08X\n", p);	/*!< Offset 0x000 VS_CTRL */
	PRINTF("%s->VS_OUT_SIZE=0x%08X\n", p);	/*!< Offset 0x040 VS_OUT_SIZE */
	PRINTF("%s->VS_GLB_ALPHA=0x%08X\n", p);	/*!< Offset 0x044 VS_GLB_ALPHA */
	PRINTF("%s->VS_Y_SIZE=0x%08X\n", p);	/*!< Offset 0x080 VS_Y_SIZE */
	PRINTF("%s->VS_Y_HSTEP=0x%08X\n", p);	/*!< Offset 0x088 VS_Y_HSTEP */
	PRINTF("%s->VS_Y_VSTEP=0x%08X\n", p);	/*!< Offset 0x08C VS_Y_VSTEP */
	PRINTF("%s->VS_Y_HPHASE=0x%08X\n", p);	/*!< Offset 0x090 VS_Y_HPHASE */
	PRINTF("%s->VS_Y_VPHASE0=0x%08X\n", p);	/*!< Offset 0x098 VS_Y_VPHASE0 */
	PRINTF("%s->VS_C_SIZE=0x%08X\n", p);	/*!< Offset 0x0C0 VS_C_SIZE */
	PRINTF("%s->VS_C_HSTEP=0x%08X\n", p);	/*!< Offset 0x0C8 VS_C_HSTEP */
	PRINTF("%s->VS_C_VSTEP=0x%08X\n", p);	/*!< Offset 0x0CC VS_C_VSTEP */
	PRINTF("%s->VS_C_HPHASE=0x%08X\n", p);	/*!< Offset 0x0D0 VS_C_HPHASE */
	PRINTF("%s->VS_C_VPHASE0=0x%08X\n", p);	/*!< Offset 0x0D8 VS_C_VPHASE0 */
}
/* Print G2D_BLD */
static void G2D_BLD_Type_print(const G2D_BLD_TypeDef * p)
{
	PRINTF("%s->BLD_EN_CTL=0x%08X\n", p);	/*!< Offset 0x000 BLD_EN_CTL          */
	PRINTF("%s->BLD_FILLC0=0x%08X\n", p);	/*!< Offset 0x010 BLD_FILLC0          */
	PRINTF("%s->BLD_FILLC1=0x%08X\n", p);	/*!< Offset 0x014 BLD_FILLC1          */
	PRINTF("%s->BLD_CH_ISIZE0=0x%08X\n", p);	/*!< Offset 0x020 BLD_CH_ISIZE0       */
	PRINTF("%s->BLD_CH_ISIZE1=0x%08X\n", p);	/*!< Offset 0x024 BLD_CH_ISIZE1       */
	PRINTF("%s->BLD_CH_OFFSET0=0x%08X\n", p);	/*!< Offset 0x030 BLD_CH_OFFSET0      */
	PRINTF("%s->BLD_CH_OFFSET1=0x%08X\n", p);	/*!< Offset 0x034 BLD_CH_OFFSET1      */
	PRINTF("%s->BLD_PREMUL_CTL=0x%08X\n", p);	/*!< Offset 0x040 BLD_PREMUL_CTL      */
	PRINTF("%s->BLD_BK_COLOR=0x%08X\n", p);	/*!< Offset 0x044 BLD_BK_COLOR        */
	PRINTF("%s->BLD_SIZE=0x%08X\n", p);	/*!< Offset 0x048 BLD_SIZE            */
	PRINTF("%s->BLD_CTL=0x%08X\n", p);	/*!< Offset 0x04C BLD_CTL             */
	PRINTF("%s->BLD_KEY_CTL=0x%08X\n", p);	/*!< Offset 0x050 BLD_KEY_CTL         */
	PRINTF("%s->BLD_KEY_CON=0x%08X\n", p);	/*!< Offset 0x054 BLD_KEY_CON         */
	PRINTF("%s->BLD_KEY_MAX=0x%08X\n", p);	/*!< Offset 0x058 BLD_KEY_MAX         */
	PRINTF("%s->BLD_KEY_MIN=0x%08X\n", p);	/*!< Offset 0x05C BLD_KEY_MIN         */
	PRINTF("%s->BLD_OUT_COLOR=0x%08X\n", p);	/*!< Offset 0x060 BLD_OUT_COLOR       */
	PRINTF("%s->ROP_CTL=0x%08X\n", p);	/*!< Offset 0x080 ROP_CTL             */
	PRINTF("%s->ROP_INDEX0=0x%08X\n", p);	/*!< Offset 0x084 ROP_INDEX0          */
	PRINTF("%s->ROP_INDEX1=0x%08X\n", p);	/*!< Offset 0x088 ROP_INDEX1          */
	PRINTF("%s->BLD_CSC_CTL=0x%08X\n", p);	/*!< Offset 0x100 BLD_CSC_CTL         */
	PRINTF("%s->BLD_CSC0_COEF00=0x%08X\n", p);	/*!< Offset 0x110 BLD_CSC0_COEF00     */
	PRINTF("%s->BLD_CSC0_COEF01=0x%08X\n", p);	/*!< Offset 0x114 BLD_CSC0_COEF01     */
	PRINTF("%s->BLD_CSC0_COEF02=0x%08X\n", p);	/*!< Offset 0x118 BLD_CSC0_COEF02     */
	PRINTF("%s->BLD_CSC0_CONST0=0x%08X\n", p);	/*!< Offset 0x11C BLD_CSC0_CONST0     */
	PRINTF("%s->BLD_CSC0_COEF10=0x%08X\n", p);	/*!< Offset 0x120 BLD_CSC0_COEF10     */
	PRINTF("%s->BLD_CSC0_COEF11=0x%08X\n", p);	/*!< Offset 0x124 BLD_CSC0_COEF11     */
	PRINTF("%s->BLD_CSC0_COEF12=0x%08X\n", p);	/*!< Offset 0x128 BLD_CSC0_COEF12     */
	PRINTF("%s->BLD_CSC0_CONST1=0x%08X\n", p);	/*!< Offset 0x12C BLD_CSC0_CONST1     */
	PRINTF("%s->BLD_CSC0_COEF20=0x%08X\n", p);	/*!< Offset 0x130 BLD_CSC0_COEF20     */
	PRINTF("%s->BLD_CSC0_COEF21=0x%08X\n", p);	/*!< Offset 0x134 BLD_CSC0_COEF21     */
	PRINTF("%s->BLD_CSC0_COEF22=0x%08X\n", p);	/*!< Offset 0x138 BLD_CSC0_COEF22     */
	PRINTF("%s->BLD_CSC0_CONST2=0x%08X\n", p);	/*!< Offset 0x13C BLD_CSC0_CONST2     */
	PRINTF("%s->BLD_CSC1_COEF00=0x%08X\n", p);	/*!< Offset 0x140 BLD_CSC1_COEF00     */
	PRINTF("%s->BLD_CSC1_COEF01=0x%08X\n", p);	/*!< Offset 0x144 BLD_CSC1_COEF01     */
	PRINTF("%s->BLD_CSC1_COEF02=0x%08X\n", p);	/*!< Offset 0x148 BLD_CSC1_COEF02     */
	PRINTF("%s->BLD_CSC1_CONST0=0x%08X\n", p);	/*!< Offset 0x14C BLD_CSC1_CONST0     */
	PRINTF("%s->BLD_CSC1_COEF10=0x%08X\n", p);	/*!< Offset 0x150 BLD_CSC1_COEF10     */
	PRINTF("%s->BLD_CSC1_COEF11=0x%08X\n", p);	/*!< Offset 0x154 BLD_CSC1_COEF11     */
	PRINTF("%s->BLD_CSC1_COEF12=0x%08X\n", p);	/*!< Offset 0x158 BLD_CSC1_COEF12     */
	PRINTF("%s->BLD_CSC1_CONST1=0x%08X\n", p);	/*!< Offset 0x15C BLD_CSC1_CONST1     */
	PRINTF("%s->BLD_CSC1_COEF20=0x%08X\n", p);	/*!< Offset 0x160 BLD_CSC1_COEF20     */
	PRINTF("%s->BLD_CSC1_COEF21=0x%08X\n", p);	/*!< Offset 0x164 BLD_CSC1_COEF21     */
	PRINTF("%s->BLD_CSC1_COEF22=0x%08X\n", p);	/*!< Offset 0x168 BLD_CSC1_COEF22     */
	PRINTF("%s->BLD_CSC1_CONST2=0x%08X\n", p);	/*!< Offset 0x16C BLD_CSC1_CONST2     */
	PRINTF("%s->BLD_CSC2_COEF00=0x%08X\n", p);	/*!< Offset 0x170 BLD_CSC2_COEF00     */
	PRINTF("%s->BLD_CSC2_COEF01=0x%08X\n", p);	/*!< Offset 0x174 BLD_CSC2_COEF01     */
	PRINTF("%s->BLD_CSC2_COEF02=0x%08X\n", p);	/*!< Offset 0x178 BLD_CSC2_COEF02     */
	PRINTF("%s->BLD_CSC2_CONST0=0x%08X\n", p);	/*!< Offset 0x17C BLD_CSC2_CONST0     */
	PRINTF("%s->BLD_CSC2_COEF10=0x%08X\n", p);	/*!< Offset 0x180 BLD_CSC2_COEF10     */
	PRINTF("%s->BLD_CSC2_COEF11=0x%08X\n", p);	/*!< Offset 0x184 BLD_CSC2_COEF11     */
	PRINTF("%s->BLD_CSC2_COEF12=0x%08X\n", p);	/*!< Offset 0x188 BLD_CSC2_COEF12     */
	PRINTF("%s->BLD_CSC2_CONST1=0x%08X\n", p);	/*!< Offset 0x18C BLD_CSC2_CONST1     */
	PRINTF("%s->BLD_CSC2_COEF20=0x%08X\n", p);	/*!< Offset 0x190 BLD_CSC2_COEF20     */
	PRINTF("%s->BLD_CSC2_COEF21=0x%08X\n", p);	/*!< Offset 0x194 BLD_CSC2_COEF21     */
	PRINTF("%s->BLD_CSC2_COEF22=0x%08X\n", p);	/*!< Offset 0x198 BLD_CSC2_COEF22     */
	PRINTF("%s->BLD_CSC2_CONST2=0x%08X\n", p);	/*!< Offset 0x19C BLD_CSC2_CONST2     */
}
/* Print G2D_WB */
static void G2D_WB_Type_print(const G2D_WB_TypeDef * p)
{
	PRINTF("%s->WB_ATT=0x%08X\n", p);	/*!< Offset 0x000 WB_ATT */
	PRINTF("%s->WB_SIZE=0x%08X\n", p);	/*!< Offset 0x004 WB_SIZE */
	PRINTF("%s->WB_PITCH0=0x%08X\n", p);	/*!< Offset 0x008 WB_PITCH0 */
	PRINTF("%s->WB_PITCH1=0x%08X\n", p);	/*!< Offset 0x00C WB_PITCH1 */
	PRINTF("%s->WB_PITCH2=0x%08X\n", p);	/*!< Offset 0x010 WB_PITCH2 */
	PRINTF("%s->WB_LADD0=0x%08X\n", p);	/*!< Offset 0x014 WB_LADD0 */
	PRINTF("%s->WB_HADD0=0x%08X\n", p);	/*!< Offset 0x018 WB_HADD0 */
	PRINTF("%s->WB_LADD1=0x%08X\n", p);	/*!< Offset 0x01C WB_LADD1 */
	PRINTF("%s->WB_HADD1=0x%08X\n", p);	/*!< Offset 0x020 WB_HADD1 */
	PRINTF("%s->WB_LADD2=0x%08X\n", p);	/*!< Offset 0x024 WB_LADD2 */
	PRINTF("%s->WB_HADD2=0x%08X\n", p);	/*!< Offset 0x028 WB_HADD2 */
}
/* Print G2D_ROT */
static void G2D_ROT_Type_print(const G2D_ROT_TypeDef * p)
{
	PRINTF("%s->ROT_CTL=0x%08X\n", p);	/*!< Offset 0x000 ROT_CTL */
	PRINTF("%s->ROT_INT=0x%08X\n", p);	/*!< Offset 0x004 ROT_INT */
	PRINTF("%s->ROT_TIMEOUT=0x%08X\n", p);	/*!< Offset 0x008 ROT_TIMEOUT */
	PRINTF("%s->ROT_IFMT=0x%08X\n", p);	/*!< Offset 0x020 ROT_IFMT */
	PRINTF("%s->ROT_ISIZE=0x%08X\n", p);	/*!< Offset 0x024 ROT_ISIZE */
	PRINTF("%s->ROT_IPITCH0=0x%08X\n", p);	/*!< Offset 0x030 ROT_IPITCH0 */
	PRINTF("%s->ROT_IPITCH1=0x%08X\n", p);	/*!< Offset 0x034 ROT_IPITCH1 */
	PRINTF("%s->ROT_IPITCH2=0x%08X\n", p);	/*!< Offset 0x038 ROT_IPITCH2 */
	PRINTF("%s->ROT_ILADD0=0x%08X\n", p);	/*!< Offset 0x040 ROT_ILADD0 */
	PRINTF("%s->ROT_IHADD0=0x%08X\n", p);	/*!< Offset 0x044 ROT_IHADD0 */
	PRINTF("%s->ROT_ILADD1=0x%08X\n", p);	/*!< Offset 0x048 ROT_ILADD1 */
	PRINTF("%s->ROT_IHADD1=0x%08X\n", p);	/*!< Offset 0x04C ROT_IHADD1 */
	PRINTF("%s->ROT_ILADD2=0x%08X\n", p);	/*!< Offset 0x050 ROT_ILADD2 */
	PRINTF("%s->ROT_IHADD2=0x%08X\n", p);	/*!< Offset 0x054 ROT_IHADD2 */
	PRINTF("%s->ROT_OSIZE=0x%08X\n", p);	/*!< Offset 0x084 ROT_OSIZE */
	PRINTF("%s->ROT_OPITCH0=0x%08X\n", p);	/*!< Offset 0x090 ROT_OPITCH0 */
	PRINTF("%s->ROT_OPITCH1=0x%08X\n", p);	/*!< Offset 0x094 ROT_OPITCH1 */
	PRINTF("%s->ROT_OPITCH2=0x%08X\n", p);	/*!< Offset 0x098 ROT_OPITCH2 */
	PRINTF("%s->ROT_OLADD0=0x%08X\n", p);	/*!< Offset 0x0A0 ROT_OLADD0 */
	PRINTF("%s->ROT_OHADD0=0x%08X\n", p);	/*!< Offset 0x0A4 ROT_OHADD0 */
	PRINTF("%s->ROT_OLADD1=0x%08X\n", p);	/*!< Offset 0x0A8 ROT_OLADD1 */
	PRINTF("%s->ROT_OHADD1=0x%08X\n", p);	/*!< Offset 0x0AC ROT_OHADD1 */
	PRINTF("%s->ROT_OLADD2=0x%08X\n", p);	/*!< Offset 0x0B0 ROT_OLADD2 */
	PRINTF("%s->ROT_OHADD2=0x%08X\n", p);	/*!< Offset 0x0B4 ROT_OHADD2 */
}
/* Print TCON_LCD */
static void TCON_LCD_Type_print(const TCON_LCD_TypeDef * p)
{
	PRINTF("%s->LCD_GCTL_REG=0x%08X\n", p);	/*!< Offset 0x000 LCD Global Control Register */
	PRINTF("%s->LCD_GINT0_REG=0x%08X\n", p);	/*!< Offset 0x004 LCD Global Interrupt Register0 */
	PRINTF("%s->LCD_GINT1_REG=0x%08X\n", p);	/*!< Offset 0x008 LCD Global Interrupt Register1 */
	PRINTF("%s->LCD_FRM_CTL_REG=0x%08X\n", p);	/*!< Offset 0x010 LCD FRM Control Register */
	PRINTF("%s->LCD_3D_FIFO_REG=0x%08X\n", p);	/*!< Offset 0x03C LCD 3D FIFO Register */
	PRINTF("%s->LCD_CTL_REG=0x%08X\n", p);	/*!< Offset 0x040 LCD Control Register */
	PRINTF("%s->LCD_DCLK_REG=0x%08X\n", p);	/*!< Offset 0x044 LCD Data Clock Register */
	PRINTF("%s->LCD_BASIC0_REG=0x%08X\n", p);	/*!< Offset 0x048 LCD Basic Timing Register0 */
	PRINTF("%s->LCD_BASIC1_REG=0x%08X\n", p);	/*!< Offset 0x04C LCD Basic Timing Register1 */
	PRINTF("%s->LCD_BASIC2_REG=0x%08X\n", p);	/*!< Offset 0x050 LCD Basic Timing Register2 */
	PRINTF("%s->LCD_BASIC3_REG=0x%08X\n", p);	/*!< Offset 0x054 LCD Basic Timing Register3 */
	PRINTF("%s->LCD_HV_IF_REG=0x%08X\n", p);	/*!< Offset 0x058 LCD HV Panel Interface Register */
	PRINTF("%s->LCD_CPU_IF_REG=0x%08X\n", p);	/*!< Offset 0x060 LCD CPU Panel Interface Register */
	PRINTF("%s->LCD_CPU_WR_REG=0x%08X\n", p);	/*!< Offset 0x064 LCD CPU Panel Write Data Register */
	PRINTF("%s->LCD_CPU_RD0_REG=0x%08X\n", p);	/*!< Offset 0x068 LCD CPU Panel Read Data Register0 */
	PRINTF("%s->LCD_CPU_RD1_REG=0x%08X\n", p);	/*!< Offset 0x06C LCD CPU Panel Read Data Register1 */
	PRINTF("%s->LCD_LVDS_IF_REG=0x%08X\n", p);	/*!< Offset 0x084 LCD LVDS Configure Register */
	PRINTF("%s->LCD_IO_POL_REG=0x%08X\n", p);	/*!< Offset 0x088 LCD IO Polarity Register */
	PRINTF("%s->LCD_IO_TRI_REG=0x%08X\n", p);	/*!< Offset 0x08C LCD IO Control Register */
	PRINTF("%s->LCD_DEBUG_REG=0x%08X\n", p);	/*!< Offset 0x0FC LCD Debug Register */
	PRINTF("%s->LCD_CEU_CTL_REG=0x%08X\n", p);	/*!< Offset 0x100 LCD CEU Control Register */
	PRINTF("%s->LCD_CPU_TRI0_REG=0x%08X\n", p);	/*!< Offset 0x160 LCD CPU Panel Trigger Register0 */
	PRINTF("%s->LCD_CPU_TRI1_REG=0x%08X\n", p);	/*!< Offset 0x164 LCD CPU Panel Trigger Register1 */
	PRINTF("%s->LCD_CPU_TRI2_REG=0x%08X\n", p);	/*!< Offset 0x168 LCD CPU Panel Trigger Register2 */
	PRINTF("%s->LCD_CPU_TRI3_REG=0x%08X\n", p);	/*!< Offset 0x16C LCD CPU Panel Trigger Register3 */
	PRINTF("%s->LCD_CPU_TRI4_REG=0x%08X\n", p);	/*!< Offset 0x170 LCD CPU Panel Trigger Register4 */
	PRINTF("%s->LCD_CPU_TRI5_REG=0x%08X\n", p);	/*!< Offset 0x174 LCD CPU Panel Trigger Register5 */
	PRINTF("%s->LCD_CMAP_CTL_REG=0x%08X\n", p);	/*!< Offset 0x180 LCD Color Map Control Register */
	PRINTF("%s->LCD_CMAP_ODD0_REG=0x%08X\n", p);	/*!< Offset 0x190 LCD Color Map Odd Line Register0 */
	PRINTF("%s->LCD_CMAP_ODD1_REG=0x%08X\n", p);	/*!< Offset 0x194 LCD Color Map Odd Line Register1 */
	PRINTF("%s->LCD_CMAP_EVEN0_REG=0x%08X\n", p);	/*!< Offset 0x198 LCD Color Map Even Line Register0 */
	PRINTF("%s->LCD_CMAP_EVEN1_REG=0x%08X\n", p);	/*!< Offset 0x19C LCD Color Map Even Line Register1 */
	PRINTF("%s->LCD_SAFE_PERIOD_REG=0x%08X\n", p);	/*!< Offset 0x1F0 LCD Safe Period Register */
	PRINTF("%s->LCD_LVDS0_ANA_REG=0x%08X\n", p);	/*!< Offset 0x220 LCD LVDS Analog Register 0 */
	PRINTF("%s->LCD_LVDS1_ANA_REG=0x%08X\n", p);	/*!< Offset 0x224 LCD LVDS Analog Register 1 */
	PRINTF("%s->LCD_SYNC_CTL_REG=0x%08X\n", p);	/*!< Offset 0x230 LCD Sync Control Register */
	PRINTF("%s->LCD_SYNC_POS_REG=0x%08X\n", p);	/*!< Offset 0x234 LCD Sync Position Register */
	PRINTF("%s->LCD_SLAVE_STOP_POS_REG=0x%08X\n", p);	/*!< Offset 0x238 LCD Slave Stop Position Register */
}
/* Print TVE_TOP */
static void TVE_TOP_Type_print(const TVE_TOP_TypeDef * p)
{
	PRINTF("%s->TVE_DAC_MAP=0x%08X\n", p);	/*!< Offset 0x020 TV Encoder DAC MAP Register */
	PRINTF("%s->TVE_DAC_STATUS=0x%08X\n", p);	/*!< Offset 0x024 TV Encoder DAC STAUTS Register */
	PRINTF("%s->TVE_DAC_CFG0=0x%08X\n", p);	/*!< Offset 0x028 TV Encoder DAC CFG0 Register */
	PRINTF("%s->TVE_DAC_CFG1=0x%08X\n", p);	/*!< Offset 0x02C TV Encoder DAC CFG1 Register */
	PRINTF("%s->TVE_DAC_CFG2=0x%08X\n", p);	/*!< Offset 0x030 TV Encoder DAC CFG2 Register */
	PRINTF("%s->TVE_DAC_CFG3=0x%08X\n", p);	/*!< Offset 0x034 TV Encoder DAC CFG2 Register */
	PRINTF("%s->TVE_DAC_TEST=0x%08X\n", p);	/*!< Offset 0x0F0 TV Encoder DAC TEST Register */
}
/* Print TVE */
static void TVE_Type_print(const TVE_TypeDef * p)
{
	PRINTF("%s->TVE_000_REG=0x%08X\n", p);	/*!< Offset 0x000 TV Encoder Clock Gating Register */
	PRINTF("%s->TVE_004_REG=0x%08X\n", p);	/*!< Offset 0x004 TV Encoder Configuration Register */
	PRINTF("%s->TVE_008_REG=0x%08X\n", p);	/*!< Offset 0x008 TV Encoder DAC Register1 */
	PRINTF("%s->TVE_00C_REG=0x%08X\n", p);	/*!< Offset 0x00C TV Encoder Notch and DAC Delay Register */
	PRINTF("%s->TVE_010_REG=0x%08X\n", p);	/*!< Offset 0x010 TV Encoder Chroma Frequency Register */
	PRINTF("%s->TVE_014_REG=0x%08X\n", p);	/*!< Offset 0x014 TV Encoder Front/Back Porch Register */
	PRINTF("%s->TVE_018_REG=0x%08X\n", p);	/*!< Offset 0x018 TV Encoder HD Mode VSYNC Register */
	PRINTF("%s->TVE_01C_REG=0x%08X\n", p);	/*!< Offset 0x01C TV Encoder Line Number Register */
	PRINTF("%s->TVE_020_REG=0x%08X\n", p);	/*!< Offset 0x020 TV Encoder Level Register */
	PRINTF("%s->TVE_024_REG=0x%08X\n", p);	/*!< Offset 0x024 TV Encoder DAC Register2 */
	PRINTF("%s->TVE_030_REG=0x%08X\n", p);	/*!< Offset 0x030 TV Encoder Auto Detection Enable Register */
	PRINTF("%s->TVE_034_REG=0x%08X\n", p);	/*!< Offset 0x034 TV Encoder Auto Detection Interrupt Status Register */
	PRINTF("%s->TVE_038_REG=0x%08X\n", p);	/*!< Offset 0x038 TV Encoder Auto Detection Status Register */
	PRINTF("%s->TVE_03C_REG=0x%08X\n", p);	/*!< Offset 0x03C TV Encoder Auto Detection De-bounce Setting Register */
	PRINTF("%s->TVE_0F8_REG=0x%08X\n", p);	/*!< Offset 0x0F8 TV Encoder Auto Detect Configuration Register0 */
	PRINTF("%s->TVE_0FC_REG=0x%08X\n", p);	/*!< Offset 0x0FC TV Encoder Auto Detect Configuration Register1 */
	PRINTF("%s->TVE_100_REG=0x%08X\n", p);	/*!< Offset 0x100 TV Encoder Color Burst Phase Reset Configuration Register */
	PRINTF("%s->TVE_104_REG=0x%08X\n", p);	/*!< Offset 0x104 TV Encoder VSYNC Number Register */
	PRINTF("%s->TVE_108_REG=0x%08X\n", p);	/*!< Offset 0x108 TV Encoder Notch Filter Frequency Register */
	PRINTF("%s->TVE_10C_REG=0x%08X\n", p);	/*!< Offset 0x10C TV Encoder Cb/Cr Level/Gain Register */
	PRINTF("%s->TVE_110_REG=0x%08X\n", p);	/*!< Offset 0x110 TV Encoder Tint and Color Burst Phase Register */
	PRINTF("%s->TVE_114_REG=0x%08X\n", p);	/*!< Offset 0x114 TV Encoder Burst Width Register */
	PRINTF("%s->TVE_118_REG=0x%08X\n", p);	/*!< Offset 0x118 TV Encoder Cb/Cr Gain Register */
	PRINTF("%s->TVE_11C_REG=0x%08X\n", p);	/*!< Offset 0x11C TV Encoder Sync and VBI Level Register */
	PRINTF("%s->TVE_120_REG=0x%08X\n", p);	/*!< Offset 0x120 TV Encoder White Level Register */
	PRINTF("%s->TVE_124_REG=0x%08X\n", p);	/*!< Offset 0x124 TV Encoder Video Active Line Register */
	PRINTF("%s->TVE_128_REG=0x%08X\n", p);	/*!< Offset 0x128 TV Encoder Video Chroma BW and CompGain Register */
	PRINTF("%s->TVE_12C_REG=0x%08X\n", p);	/*!< Offset 0x12C TV Encoder Register */
	PRINTF("%s->TVE_130_REG=0x%08X\n", p);	/*!< Offset 0x130 TV Encoder Re-sync Parameters Register */
	PRINTF("%s->TVE_134_REG=0x%08X\n", p);	/*!< Offset 0x134 TV Encoder Slave Parameter Register */
	PRINTF("%s->TVE_138_REG=0x%08X\n", p);	/*!< Offset 0x138 TV Encoder Configuration Register0 */
	PRINTF("%s->TVE_13C_REG=0x%08X\n", p);	/*!< Offset 0x13C TV Encoder Configuration Register1 */
	PRINTF("%s->TVE_380_REG=0x%08X\n", p);	/*!< Offset 0x380 TV Encoder Low Pass Control Register */
	PRINTF("%s->TVE_384_REG=0x%08X\n", p);	/*!< Offset 0x384 TV Encoder Low Pass Filter Control Register */
	PRINTF("%s->TVE_388_REG=0x%08X\n", p);	/*!< Offset 0x388 TV Encoder Low Pass Gain Register */
	PRINTF("%s->TVE_38C_REG=0x%08X\n", p);	/*!< Offset 0x38C TV Encoder Low Pass Gain Control Register */
	PRINTF("%s->TVE_390_REG=0x%08X\n", p);	/*!< Offset 0x390 TV Encoder Low Pass Shoot Control Register */
	PRINTF("%s->TVE_394_REG=0x%08X\n", p);	/*!< Offset 0x394 TV Encoder Low Pass Coring Register */
	PRINTF("%s->TVE_3A0_REG=0x%08X\n", p);	/*!< Offset 0x3A0 TV Encoder Noise Reduction Register */
}
/* Print CSIC_CCU */
static void CSIC_CCU_Type_print(const CSIC_CCU_TypeDef * p)
{
	PRINTF("%s->CCU_CLK_MODE_REG=0x%08X\n", p);	/*!< Offset 0x000 CCU Clock Mode Register */
	PRINTF("%s->CCU_PARSER_CLK_EN_REG=0x%08X\n", p);	/*!< Offset 0x004 CCU Parser Clock Enable Register */
	PRINTF("%s->CCU_POST0_CLK_EN_REG=0x%08X\n", p);	/*!< Offset 0x00C CCU Post0 Clock Enable Register */
}
/* Print CSIC_TOP */
static void CSIC_TOP_Type_print(const CSIC_TOP_TypeDef * p)
{
	PRINTF("%s->CSIC_TOP_EN_REG=0x%08X\n", p);	/*!< Offset 0x000 CSIC TOP Enable Register */
	PRINTF("%s->CSIC_PTN_GEN_EN_REG=0x%08X\n", p);	/*!< Offset 0x004 CSIC Pattern Generation Enable Register */
	PRINTF("%s->CSIC_PTN_CTRL_REG=0x%08X\n", p);	/*!< Offset 0x008 CSIC Pattern Control Register */
	PRINTF("%s->CSIC_PTN_LEN_REG=0x%08X\n", p);	/*!< Offset 0x020 CSIC Pattern Generation Length Register */
	PRINTF("%s->CSIC_PTN_ADDR_REG=0x%08X\n", p);	/*!< Offset 0x024 CSIC Pattern Generation Address Register */
	PRINTF("%s->CSIC_PTN_ISP_SIZE_REG=0x%08X\n", p);	/*!< Offset 0x028 CSIC Pattern ISP Size Register */
	PRINTF("%s->CSIC_DMA0_INPUT_SEL_REG=0x%08X\n", p);	/*!< Offset 0x0A0 CSIC DMA0 Input Select Register */
	PRINTF("%s->CSIC_DMA1_INPUT_SEL_REG=0x%08X\n", p);	/*!< Offset 0x0A4 CSIC DMA1 Input Select Register */
	PRINTF("%s->CSIC_BIST_CS_REG=0x%08X\n", p);	/*!< Offset 0x0DC CSIC BIST CS Register */
	PRINTF("%s->CSIC_BIST_CONTROL_REG=0x%08X\n", p);	/*!< Offset 0x0E0 CSIC BIST Control Register */
	PRINTF("%s->CSIC_BIST_START_REG=0x%08X\n", p);	/*!< Offset 0x0E4 CSIC BIST Start Register */
	PRINTF("%s->CSIC_BIST_END_REG=0x%08X\n", p);	/*!< Offset 0x0E8 CSIC BIST End Register */
	PRINTF("%s->CSIC_BIST_DATA_MASK_REG=0x%08X\n", p);	/*!< Offset 0x0EC CSIC BIST Data Mask Register */
	PRINTF("%s->CSIC_MBUS_REQ_MAX_REG=0x%08X\n", p);	/*!< Offset 0x0F0 CSIC MBUS REQ MAX Register */
	PRINTF("%s->CSIC_MULF_MOD_REG=0x%08X\n", p);	/*!< Offset 0x100 CSIC Multi-Frame Mode Register */
	PRINTF("%s->CSIC_MULF_INT_REG=0x%08X\n", p);	/*!< Offset 0x104 CSIC Multi-Frame Interrupt Register */
}
/* Print CSIC_PARSER */
static void CSIC_PARSER_Type_print(const CSIC_PARSER_TypeDef * p)
{
	PRINTF("%s->PRS_EN_REG=0x%08X\n", p);	/*!< Offset 0x000 Parser Enable Register */
	PRINTF("%s->PRS_NCSIC_IF_CFG_REG=0x%08X\n", p);	/*!< Offset 0x004 Parser NCSIC Interface Configuration Register */
	PRINTF("%s->PRS_CAP_REG=0x%08X\n", p);	/*!< Offset 0x00C Parser Capture Register */
	PRINTF("%s->CSIC_PRS_SIGNAL_STA_REG=0x%08X\n", p);	/*!< Offset 0x010 CSIC Parser Signal Status Register */
	PRINTF("%s->CSIC_PRS_NCSIC_BT656_HEAD_CFG_REG=0x%08X\n", p);	/*!< Offset 0x014 CSIC Parser NCSIC BT656 Header Configuration Register */
	PRINTF("%s->PRS_C0_INFMT_REG=0x%08X\n", p);	/*!< Offset 0x024 Parser Channel_0 Input Format Register */
	PRINTF("%s->PRS_C0_OUTPUT_HSIZE_REG=0x%08X\n", p);	/*!< Offset 0x028 Parser Channel_0 Output Horizontal Size Register */
	PRINTF("%s->PRS_C0_OUTPUT_VSIZE_REG=0x%08X\n", p);	/*!< Offset 0x02C Parser Channel_0 Output Vertical Size Register */
	PRINTF("%s->PRS_C0_INPUT_PARA0_REG=0x%08X\n", p);	/*!< Offset 0x030 Parser Channel_0 Input Parameter0 Register */
	PRINTF("%s->PRS_C0_INPUT_PARA1_REG=0x%08X\n", p);	/*!< Offset 0x034 Parser Channel_0 Input Parameter1 Register */
	PRINTF("%s->PRS_C0_INPUT_PARA2_REG=0x%08X\n", p);	/*!< Offset 0x038 Parser Channel_0 Input Parameter2 Register */
	PRINTF("%s->PRS_C0_INPUT_PARA3_REG=0x%08X\n", p);	/*!< Offset 0x03C Parser Channel_0 Input Parameter3 Register */
	PRINTF("%s->PRS_C0_INT_EN_REG=0x%08X\n", p);	/*!< Offset 0x040 Parser Channel_0 Interrupt Enable Register */
	PRINTF("%s->PRS_C0_INT_STA_REG=0x%08X\n", p);	/*!< Offset 0x044 Parser Channel_0 Interrupt Status Register */
	PRINTF("%s->PRS_CH0_LINE_TIME_REG=0x%08X\n", p);	/*!< Offset 0x048 Parser Channel_0 Line Time Register */
	PRINTF("%s->PRS_C1_INFMT_REG=0x%08X\n", p);	/*!< Offset 0x124 Parser Channel_1 Input Format Register */
	PRINTF("%s->PRS_C1_OUTPUT_HSIZE_REG=0x%08X\n", p);	/*!< Offset 0x128 Parser Channel_1 Output Horizontal Size Register */
	PRINTF("%s->PRS_C1_OUTPUT_VSIZE_REG=0x%08X\n", p);	/*!< Offset 0x12C Parser Channel_1 Output Vertical Size Register */
	PRINTF("%s->PRS_C1_INPUT_PARA0_REG=0x%08X\n", p);	/*!< Offset 0x130 Parser Channel_1 Input Parameter0 Register */
	PRINTF("%s->PRS_C1_INPUT_PARA1_REG=0x%08X\n", p);	/*!< Offset 0x134 Parser Channel_1 Input Parameter1 Register */
	PRINTF("%s->PRS_C1_INPUT_PARA2_REG=0x%08X\n", p);	/*!< Offset 0x138 Parser Channel_1 Input Parameter2 Register */
	PRINTF("%s->PRS_C1_INPUT_PARA3_REG=0x%08X\n", p);	/*!< Offset 0x13C Parser Channel_1 Input Parameter3 Register */
	PRINTF("%s->PRS_C1_INT_EN_REG=0x%08X\n", p);	/*!< Offset 0x140 Parser Channel_1 Interrupt Enable Register */
	PRINTF("%s->PRS_C1_INT_STA_REG=0x%08X\n", p);	/*!< Offset 0x144 Parser Channel_1 Interrupt Status Register */
	PRINTF("%s->PRS_CH1_LINE_TIME_REG=0x%08X\n", p);	/*!< Offset 0x148 Parser Channel_1 Line Time Register */
	PRINTF("%s->PRS_C2_INFMT_REG=0x%08X\n", p);	/*!< Offset 0x224 Parser Channel_2 Input Format Register */
	PRINTF("%s->PRS_C2_OUTPUT_HSIZE_REG=0x%08X\n", p);	/*!< Offset 0x228 Parser Channel_2 Output Horizontal Size Register */
	PRINTF("%s->PRS_C2_OUTPUT_VSIZE_REG=0x%08X\n", p);	/*!< Offset 0x22C Parser Channel_2 Output Vertical Size Register */
	PRINTF("%s->PRS_C2_INPUT_PARA0_REG=0x%08X\n", p);	/*!< Offset 0x230 Parser Channel_2 Input Parameter0 Register */
	PRINTF("%s->PRS_C2_INPUT_PARA1_REG=0x%08X\n", p);	/*!< Offset 0x234 Parser Channel_2 Input Parameter1 Register */
	PRINTF("%s->PRS_C2_INPUT_PARA2_REG=0x%08X\n", p);	/*!< Offset 0x238 Parser Channel_2 Input Parameter2 Register */
	PRINTF("%s->PRS_C2_INPUT_PARA3_REG=0x%08X\n", p);	/*!< Offset 0x23C Parser Channel_2 Input Parameter3 Register */
	PRINTF("%s->PRS_C2_INT_EN_REG=0x%08X\n", p);	/*!< Offset 0x240 Parser Channel_2 Interrupt Enable Register */
	PRINTF("%s->PRS_C2_INT_STA_REG=0x%08X\n", p);	/*!< Offset 0x244 Parser Channel_2 Interrupt Status Register */
	PRINTF("%s->PRS_CH2_LINE_TIME_REG=0x%08X\n", p);	/*!< Offset 0x248 Parser Channel_2 Line Time Register */
	PRINTF("%s->PRS_C3_INFMT_REG=0x%08X\n", p);	/*!< Offset 0x324 Parser Channel_3 Input Format Register */
	PRINTF("%s->PRS_C3_OUTPUT_HSIZE_REG=0x%08X\n", p);	/*!< Offset 0x328 Parser Channel_3 Output Horizontal Size Register */
	PRINTF("%s->PRS_C3_OUTPUT_VSIZE_REG=0x%08X\n", p);	/*!< Offset 0x32C Parser Channel_3 Output Vertical Size Register */
	PRINTF("%s->PRS_C3_INPUT_PARA0_REG=0x%08X\n", p);	/*!< Offset 0x330 Parser Channel_3 Input Parameter0 Register */
	PRINTF("%s->PRS_C3_INPUT_PARA1_REG=0x%08X\n", p);	/*!< Offset 0x334 Parser Channel_3 Input Parameter1 Register */
	PRINTF("%s->PRS_C3_INPUT_PARA2_REG=0x%08X\n", p);	/*!< Offset 0x338 Parser Channel_3 Input Parameter2 Register */
	PRINTF("%s->PRS_C3_INPUT_PARA3_REG=0x%08X\n", p);	/*!< Offset 0x33C Parser Channel_3 Input Parameter3 Register */
	PRINTF("%s->PRS_C3_INT_EN_REG=0x%08X\n", p);	/*!< Offset 0x340 Parser Channel_3 Interrupt Enable Register */
	PRINTF("%s->PRS_C3_INT_STA_REG=0x%08X\n", p);	/*!< Offset 0x344 Parser Channel_3 Interrupt Status Register */
	PRINTF("%s->PRS_CH3_LINE_TIME_REG=0x%08X\n", p);	/*!< Offset 0x348 Parser Channel_3 Line Time Register */
	PRINTF("%s->CSIC_PRS_NCSIC_RX_SIGNAL0_DLY_ADJ_REG=0x%08X\n", p);	/*!< Offset 0x500 CSIC Parser NCSIC RX Signal0 Delay Adjust Register */
	PRINTF("%s->CSIC_PRS_NCSIC_RX_SIGNAL5_DLY_ADJ_REG=0x%08X\n", p);	/*!< Offset 0x514 CSIC Parser NCSIC RX Signal5 Delay Adjust Register */
	PRINTF("%s->CSIC_PRS_NCSIC_RX_SIGNAL6_DLY_ADJ_REG=0x%08X\n", p);	/*!< Offset 0x518 CSIC Parser NCSIC RX Signal6 Delay Adjust Register */
}
/* Print CSIC_DMA */
static void CSIC_DMA_Type_print(const CSIC_DMA_TypeDef * p)
{
	PRINTF("%s->CSIC_DMA_EN_REG=0x%08X\n", p);	/*!< Offset 0x000 CSIC DMA Enable Register */
	PRINTF("%s->CSIC_DMA_CFG_REG=0x%08X\n", p);	/*!< Offset 0x004 CSIC DMA Configuration Register */
	PRINTF("%s->CSIC_DMA_HSIZE_REG=0x%08X\n", p);	/*!< Offset 0x010 CSIC DMA Horizontal Size Register */
	PRINTF("%s->CSIC_DMA_VSIZE_REG=0x%08X\n", p);	/*!< Offset 0x014 CSIC DMA Vertical Size Register */
	PRINTF("%s->CSIC_DMA_F0_BUFA_REG=0x%08X\n", p);	/*!< Offset 0x020 CSIC DMA FIFO 0 Output Buffer-A Address Register */
	PRINTF("%s->CSIC_DMA_F0_BUFA_RESULT_REG=0x%08X\n", p);	/*!< Offset 0x024 CSIC DMA FIFO 0 Output Buffer-A Address Result Register */
	PRINTF("%s->CSIC_DMA_F1_BUFA_REG=0x%08X\n", p);	/*!< Offset 0x028 CSIC DMA FIFO 1 Output Buffer-A Address Register */
	PRINTF("%s->CSIC_DMA_F1_BUFA_RESULT_REG=0x%08X\n", p);	/*!< Offset 0x02C CSIC DMA FIFO 1 Output Buffer-A Address Result Register */
	PRINTF("%s->CSIC_DMA_F2_BUFA_REG=0x%08X\n", p);	/*!< Offset 0x030 CSIC DMA FIFO 2 Output Buffer-A Address Register */
	PRINTF("%s->CSIC_DMA_F2_BUFA_RESULT_REG=0x%08X\n", p);	/*!< Offset 0x034 CSIC DMA FIFO 2 Output Buffer-A Address Result Register */
	PRINTF("%s->CSIC_DMA_BUF_LEN_REG=0x%08X\n", p);	/*!< Offset 0x038 CSIC DMA Buffer Length Register */
	PRINTF("%s->CSIC_DMA_FLIP_SIZE_REG=0x%08X\n", p);	/*!< Offset 0x03C CSIC DMA Flip Size Register */
	PRINTF("%s->CSIC_DMA_VI_TO_TH0_REG=0x%08X\n", p);	/*!< Offset 0x040 CSIC DMA Video Input Timeout Threshold0 Register */
	PRINTF("%s->CSIC_DMA_VI_TO_TH1_REG=0x%08X\n", p);	/*!< Offset 0x044 CSIC DMA Video Input Timeout Threshold1 Register */
	PRINTF("%s->CSIC_DMA_VI_TO_CNT_VAL_REG=0x%08X\n", p);	/*!< Offset 0x048 CSIC DMA Video Input Timeout Counter Value Register */
	PRINTF("%s->CSIC_DMA_CAP_STA_REG=0x%08X\n", p);	/*!< Offset 0x04C CSIC DMA Capture Status Register */
	PRINTF("%s->CSIC_DMA_INT_EN_REG=0x%08X\n", p);	/*!< Offset 0x050 CSIC DMA Interrupt Enable Register */
	PRINTF("%s->CSIC_DMA_INT_STA_REG=0x%08X\n", p);	/*!< Offset 0x054 CSIC DMA Interrupt Status Register */
	PRINTF("%s->CSIC_DMA_LINE_CNT_REG=0x%08X\n", p);	/*!< Offset 0x058 CSIC DMA LINE Counter Register */
	PRINTF("%s->CSIC_DMA_FRM_CNT_REG=0x%08X\n", p);	/*!< Offset 0x05C CSIC DMA Frame Counter Register */
	PRINTF("%s->CSIC_DMA_FRM_CLK_CNT_REG=0x%08X\n", p);	/*!< Offset 0x060 CSIC DMA Frame Clock Counter Register */
	PRINTF("%s->CSIC_DMA_ACC_ITNL_CLK_CNT_REG=0x%08X\n", p);	/*!< Offset 0x064 CSIC DMA Accumulated And Internal Clock Counter Register */
	PRINTF("%s->CSIC_DMA_FIFO_STAT_REG=0x%08X\n", p);	/*!< Offset 0x068 CSIC DMA FIFO Statistic Register */
	PRINTF("%s->CSIC_DMA_FIFO_THRS_REG=0x%08X\n", p);	/*!< Offset 0x06C CSIC DMA FIFO Threshold Register */
	PRINTF("%s->CSIC_DMA_PCLK_STAT_REG=0x%08X\n", p);	/*!< Offset 0x070 CSIC DMA PCLK Statistic Register */
	PRINTF("%s->CSIC_DMA_BUF_ADDR_FIFO0_ENTRY_REG=0x%08X\n", p);	/*!< Offset 0x080 CSIC DMA BUF Address FIFO0 Entry Register */
	PRINTF("%s->CSIC_DMA_BUF_ADDR_FIFO1_ENTRY_REG=0x%08X\n", p);	/*!< Offset 0x084 CSIC DMA BUF Address FIFO1 Entry Register */
	PRINTF("%s->CSIC_DMA_BUF_ADDR_FIFO2_ENTRY_REG=0x%08X\n", p);	/*!< Offset 0x088 CSIC DMA BUF Address FIFO2 Entry Register */
	PRINTF("%s->CSIC_DMA_BUF_TH_REG=0x%08X\n", p);	/*!< Offset 0x08C CSIC DMA BUF Threshold Register */
	PRINTF("%s->CSIC_DMA_BUF_ADDR_FIFO_CON_REG=0x%08X\n", p);	/*!< Offset 0x090 CSIC DMA BUF Address FIFO Content Register */
	PRINTF("%s->CSIC_DMA_STORED_FRM_CNT_REG=0x%08X\n", p);	/*!< Offset 0x094 CSIC DMA Stored Frame Counter Register */
	PRINTF("%s->CSIC_FEATURE_REG=0x%08X\n", p);	/*!< Offset 0x1F4 CSIC DMA Feature List Register */
}
/* Print TVD_ADC */
static void TVD_ADC_Type_print(const TVD_ADC_TypeDef * p)
{
	PRINTF("%s->TVD_TOP_CTL=0x%08X\n", p);	/*!< Offset 0x004 TVD TOP CONTROL Register */
	PRINTF("%s->TVD_ADC_CTL=0x%08X\n", p);	/*!< Offset 0x008 TVD ADC CONTROL Register */
	PRINTF("%s->TVD_ADC_CFG=0x%08X\n", p);	/*!< Offset 0x00C TVD ADC CONFIGURATION Register */
}
/* Print TVD_TOP */
static void TVD_TOP_Type_print(const TVD_TOP_TypeDef * p)
{
	PRINTF("%s->TVD_TOP_MAP=0x%08X\n", p);	/*!< Offset 0x000 TVD TOP MAP Register */
	PRINTF("%s->TVD_3D_CTL1=0x%08X\n", p);	/*!< Offset 0x008 TVD 3D DMA CONTROL Register1 */
	PRINTF("%s->TVD_3D_CTL2=0x%08X\n", p);	/*!< Offset 0x00C TVD 3D DMA CONTROL Register2 */
	PRINTF("%s->TVD_3D_CTL3=0x%08X\n", p);	/*!< Offset 0x010 TVD 3D DMA CONTROL Register3 */
	PRINTF("%s->TVD_3D_CTL4=0x%08X\n", p);	/*!< Offset 0x014 TVD 3D DMA CONTROL Register4 */
	PRINTF("%s->TVD_3D_CTL5=0x%08X\n", p);	/*!< Offset 0x018 TVD 3D DMA CONTROL Register5 */
}
/* Print TVD */
static void TVD_Type_print(const TVD_TypeDef * p)
{
	PRINTF("%s->TVD_EN=0x%08X\n", p);	/*!< Offset 0x000 TVD MODULE CONTROL Register */
	PRINTF("%s->TVD_MODE=0x%08X\n", p);	/*!< Offset 0x004 TVD MODE CONTROL Register */
	PRINTF("%s->TVD_CLAMP_AGC1=0x%08X\n", p);	/*!< Offset 0x008 TVD CLAMP & AGC CONTROL Register1 */
	PRINTF("%s->TVD_CLAMP_AGC2=0x%08X\n", p);	/*!< Offset 0x00C TVD CLAMP & AGC CONTROL Register2 */
	PRINTF("%s->TVD_HLOCK1=0x%08X\n", p);	/*!< Offset 0x010 TVD HLOCK CONTROL Register1 */
	PRINTF("%s->TVD_HLOCK2=0x%08X\n", p);	/*!< Offset 0x014 TVD HLOCK CONTROL Register2 */
	PRINTF("%s->TVD_HLOCK3=0x%08X\n", p);	/*!< Offset 0x018 TVD HLOCK CONTROL Register3 */
	PRINTF("%s->TVD_HLOCK4=0x%08X\n", p);	/*!< Offset 0x01C TVD HLOCK CONTROL Register4 */
	PRINTF("%s->TVD_HLOCK5=0x%08X\n", p);	/*!< Offset 0x020 TVD HLOCK CONTROL Register5 */
	PRINTF("%s->TVD_VLOCK1=0x%08X\n", p);	/*!< Offset 0x024 TVD VLOCK CONTROL Register1 */
	PRINTF("%s->TVD_VLOCK2=0x%08X\n", p);	/*!< Offset 0x028 TVD VLOCK CONTROL Register2 */
	PRINTF("%s->TVD_CLOCK1=0x%08X\n", p);	/*!< Offset 0x030 TVD CHROMA LOCK CONTROL Register1 */
	PRINTF("%s->TVD_CLOCK2=0x%08X\n", p);	/*!< Offset 0x034 TVD CHROMA LOCK CONTROL Register2 */
	PRINTF("%s->TVD_YC_SEP1=0x%08X\n", p);	/*!< Offset 0x040 TVD YC SEPERATION CONROL Register1 */
	PRINTF("%s->TVD_YC_SEP2=0x%08X\n", p);	/*!< Offset 0x044 TVD YC SEPERATION CONROL Register2 */
	PRINTF("%s->TVD_ENHANCE1=0x%08X\n", p);	/*!< Offset 0x050 TVD ENHANCEMENT CONTROL Register1 */
	PRINTF("%s->TVD_ENHANCE2=0x%08X\n", p);	/*!< Offset 0x054 TVD ENHANCEMENT CONTROL Register2 */
	PRINTF("%s->TVD_ENHANCE3=0x%08X\n", p);	/*!< Offset 0x058 TVD ENHANCEMENT CONTROL Register3 */
	PRINTF("%s->TVD_WB1=0x%08X\n", p);	/*!< Offset 0x060 TVD WB DMA CONTROL Register1 */
	PRINTF("%s->TVD_WB2=0x%08X\n", p);	/*!< Offset 0x064 TVD WB DMA CONTROL Register2 */
	PRINTF("%s->TVD_WB3=0x%08X\n", p);	/*!< Offset 0x068 TVD WB DMA CONTROL Register3 */
	PRINTF("%s->TVD_WB4=0x%08X\n", p);	/*!< Offset 0x06C TVD WB DMA CONTROL Register4 */
	PRINTF("%s->TVD_IRQ_CTL=0x%08X\n", p);	/*!< Offset 0x080 TVD DMA Interrupt Control Register */
	PRINTF("%s->TVD_IRQ_STATUS=0x%08X\n", p);	/*!< Offset 0x090 TVD DMA Interrupt Status Register */
	PRINTF("%s->TVD_DEBUG1=0x%08X\n", p);	/*!< Offset 0x100 TVD DEBUG CONTROL Register1 */
	PRINTF("%s->TVD_STATUS1=0x%08X\n", p);	/*!< Offset 0x180 TVD DEBUG STATUS Register1 */
	PRINTF("%s->TVD_STATUS2=0x%08X\n", p);	/*!< Offset 0x184 TVD DEBUG STATUS Register2 */
	PRINTF("%s->TVD_STATUS3=0x%08X\n", p);	/*!< Offset 0x188 TVD DEBUG STATUS Register3 */
	PRINTF("%s->TVD_STATUS4=0x%08X\n", p);	/*!< Offset 0x18C TVD DEBUG STATUS Register4 */
	PRINTF("%s->TVD_STATUS5=0x%08X\n", p);	/*!< Offset 0x190 TVD DEBUG STATUS Register5 */
	PRINTF("%s->TVD_STATUS6=0x%08X\n", p);	/*!< Offset 0x194 TVD DEBUG STATUS Register6 */
}
/* Print DDRPHYC */
static void DDRPHYC_Type_print(const DDRPHYC_TypeDef * p)
{
	PRINTF("%s->PHYC_REG_000=0x%08X\n", p);	/*!< Offset 0x000 Reg_000 */
	PRINTF("%s->PHYC_REG_004=0x%08X\n", p);	/*!< Offset 0x004 Reg_004 */
	PRINTF("%s->PHYC_REG_00C=0x%08X\n", p);	/*!< Offset 0x00C Reg_00C */
	PRINTF("%s->PHYC_REG_010=0x%08X\n", p);	/*!< Offset 0x010 Reg_010 */
	PRINTF("%s->PHYC_REG_018=0x%08X\n", p);	/*!< Offset 0x018 Reg_018 */
	PRINTF("%s->PHYC_REG_02C=0x%08X\n", p);	/*!< Offset 0x02C Reg_02C */
	PRINTF("%s->PHYC_REG_030=0x%08X\n", p);	/*!< Offset 0x030 Reg_030 */
	PRINTF("%s->PHYC_REG_034=0x%08X\n", p);	/*!< Offset 0x034 Reg_034 */
	PRINTF("%s->PHYC_REG_038=0x%08X\n", p);	/*!< Offset 0x038 Reg_038 */
	PRINTF("%s->PHYC_REG_03C=0x%08X\n", p);	/*!< Offset 0x03C Reg_03C */
	PRINTF("%s->PHYC_REG_050=0x%08X\n", p);	/*!< Offset 0x050 Reg_050 */
	PRINTF("%s->PHYC_REG_054=0x%08X\n", p);	/*!< Offset 0x054 Reg_054 */
	PRINTF("%s->PHYC_REG_058=0x%08X\n", p);	/*!< Offset 0x058 Reg_058 */
	PRINTF("%s->PHYC_REG_05C=0x%08X\n", p);	/*!< Offset 0x05C Reg_05C */
	PRINTF("%s->PHYC_REG_060=0x%08X\n", p);	/*!< Offset 0x060 Reg_060 */
	PRINTF("%s->PHYC_REG_064=0x%08X\n", p);	/*!< Offset 0x064 Reg_064 */
	PRINTF("%s->PHYC_REG_068=0x%08X\n", p);	/*!< Offset 0x068 Reg_068 */
	PRINTF("%s->PHYC_REG_06C=0x%08X\n", p);	/*!< Offset 0x06C Reg_06C */
	PRINTF("%s->PHYC_REG_078=0x%08X\n", p);	/*!< Offset 0x078 Reg_078 */
	PRINTF("%s->PHYC_REG_07C=0x%08X\n", p);	/*!< Offset 0x07C Reg_07c */
	PRINTF("%s->PHYC_REG_080=0x%08X\n", p);	/*!< Offset 0x080 Reg_080 */
	PRINTF("%s->PHYC_REG_08C=0x%08X\n", p);	/*!< Offset 0x08C Reg_08C */
	PRINTF("%s->PHYC_REG_090=0x%08X\n", p);	/*!< Offset 0x090 Reg_090 */
	PRINTF("%s->PHYC_REG_094=0x%08X\n", p);	/*!< Offset 0x094 Reg_094 */
	PRINTF("%s->PHYC_REG_09C=0x%08X\n", p);	/*!< Offset 0x09C Reg_09C */
	PRINTF("%s->PHYC_REG_0A0=0x%08X\n", p);	/*!< Offset 0x0A0 Reg_0a0 */
	PRINTF("%s->PHYC_REG_0B8=0x%08X\n", p);	/*!< Offset 0x0B8 Reg_0B8 */
	PRINTF("%s->PHYC_REG_0BC=0x%08X\n", p);	/*!< Offset 0x0BC Reg_0BC */
	PRINTF("%s->PHYC_REG_0C0=0x%08X\n", p);	/*!< Offset 0x0C0 Reg_0C0 */
	PRINTF("%s->PHYC_REG_100=0x%08X\n", p);	/*!< Offset 0x100 Reg_100 */
	PRINTF("%s->PHYC_REG_108=0x%08X\n", p);	/*!< Offset 0x108 Reg_108 */
	PRINTF("%s->PHYC_REG_10C=0x%08X\n", p);	/*!< Offset 0x10C Reg_10C */
	PRINTF("%s->PHYC_REG_110=0x%08X\n", p);	/*!< Offset 0x110 Reg_110 */
	PRINTF("%s->PHYC_REG_114=0x%08X\n", p);	/*!< Offset 0x114 Reg_114 */
	PRINTF("%s->PHYC_REG_11C=0x%08X\n", p);	/*!< Offset 0x11C Reg_11C */
	PRINTF("%s->PHYC_REG_120=0x%08X\n", p);	/*!< Offset 0x120 Reg_120 */
	PRINTF("%s->PHYC_REG_140=0x%08X\n", p);	/*!< Offset 0x140 Reg_140 */
	PRINTF("%s->PHYC_REG_208=0x%08X\n", p);	/*!< Offset 0x208 Reg_208 */
	PRINTF("%s->PHYC_REG_218=0x%08X\n", p);	/*!< Offset 0x218 Reg_218 */
	PRINTF("%s->PHYC_REG_21C=0x%08X\n", p);	/*!< Offset 0x21C Reg_21C */
	PRINTF("%s->PHYC_REG_280=0x%08X\n", p);	/*!< Offset 0x280 Reg_280 */
	PRINTF("%s->PHYC_REG_334=0x%08X\n", p);	/*!< Offset 0x334 Reg_334 Rank 0 */
	PRINTF("%s->PHYC_REG_338=0x%08X\n", p);	/*!< Offset 0x338 Reg_338 Rank 0 */
	PRINTF("%s->PHYC_REG_33C=0x%08X\n", p);	/*!< Offset 0x33C Reg_33C Rank 0 */
	PRINTF("%s->PHYC_REG_344=0x%08X\n", p);	/*!< Offset 0x344 Reg_344 Rank 0 */
	PRINTF("%s->PHYC_REG_348=0x%08X\n", p);	/*!< Offset 0x348 Reg_348 Rank 0 */
	PRINTF("%s->PHYC_REG_3B4=0x%08X\n", p);	/*!< Offset 0x3B4 Reg_3B4 Rank 1 */
	PRINTF("%s->PHYC_REG_3B8=0x%08X\n", p);	/*!< Offset 0x3B8 Reg_3B8 Rank 1 */
	PRINTF("%s->PHYC_REG_3BC=0x%08X\n", p);	/*!< Offset 0x3BC Reg_3BC Rank 1 */
	PRINTF("%s->PHYC_REG_3C4=0x%08X\n", p);	/*!< Offset 0x3C4 Reg_3C4 Rank 1 */
	PRINTF("%s->PHYC_REG_3C8=0x%08X\n", p);	/*!< Offset 0x3C8 Reg_3C8 Rank 1 */
}
/* Print MSI_MEMC */
static void MSI_MEMC_Type_print(const MSI_MEMC_TypeDef * p)
{
	PRINTF("%s->MEMC_REG_000=0x%08X\n", p);	/*!< Offset 0x000 Reg_000 */
	PRINTF("%s->MEMC_REG_004=0x%08X\n", p);	/*!< Offset 0x004 Reg_004 */
	PRINTF("%s->MEMC_REG_008=0x%08X\n", p);	/*!< Offset 0x008 Reg_008 */
	PRINTF("%s->MEMC_REG_00C=0x%08X\n", p);	/*!< Offset 0x00C Reg_00C */
	PRINTF("%s->MEMC_REG_020=0x%08X\n", p);	/*!< Offset 0x020 Reg_020 */
	PRINTF("%s->MEMC_REG_024=0x%08X\n", p);	/*!< Offset 0x024 Reg_024 */
	PRINTF("%s->MEMC_REG_028=0x%08X\n", p);	/*!< Offset 0x028 Reg_028 */
}
/* Print SID */
static void SID_Type_print(const SID_TypeDef * p)
{
	PRINTF("%s->THS=0x%08X\n", p);	/*!< Offset 0x014 [27:16]: The calibration value of the T-sensor. */
	PRINTF("%s->BOOT_MODE=0x%08X\n", p);	/*!< Offset 0x210 [27:16]: eFUSE boot select status, [0]: 0: GPIO boot select, 1: eFuse boot select */
}
/* Print USB_EHCI_Capability */
static void USB_EHCI_Capability_Type_print(const USB_EHCI_Capability_TypeDef * p)
{
	PRINTF("%s->HCCAPBASE=0x%08X\n", p);	/*!< Offset 0x000 EHCI Capability Register (HCIVERSION and CAPLENGTH) register */
	PRINTF("%s->HCSPARAMS=0x%08X\n", p);	/*!< Offset 0x004 EHCI Host Control Structural Parameter Register */
	PRINTF("%s->HCCPARAMS=0x%08X\n", p);	/*!< Offset 0x008 EHCI Host Control Capability Parameter Register */
	PRINTF("%s->HCSPPORTROUTE=0x%08X\n", p);	/*!< Offset 0x00C EHCI Companion Port Route Description */
	PRINTF("%s->USBCMD=0x%08X\n", p);	/*!< Offset 0x010 EHCI USB Command Register */
	PRINTF("%s->USBSTS=0x%08X\n", p);	/*!< Offset 0x014 EHCI USB Status Register */
	PRINTF("%s->USBINTR=0x%08X\n", p);	/*!< Offset 0x018 EHCI USB Interrupt Enable Register */
	PRINTF("%s->FRINDEX=0x%08X\n", p);	/*!< Offset 0x01C EHCI USB Frame Index Register */
	PRINTF("%s->CTRLDSSEGMENT=0x%08X\n", p);	/*!< Offset 0x020 EHCI 4G Segment Selector Register */
	PRINTF("%s->PERIODICLISTBASE=0x%08X\n", p);	/*!< Offset 0x024 EHCI Frame List Base Address Register */
	PRINTF("%s->ASYNCLISTADDR=0x%08X\n", p);	/*!< Offset 0x028 EHCI Next Asynchronous List Address Register */
}
/* Print DMAC_CH */
static void DMAC_CH_Type_print(const DMAC_CH_TypeDef * p)
{
	PRINTF("%s->DMAC_EN_REGN=0x%08X\n", p);	/*!< Offset 0x000 DMAC Channel Enable Register N (N = 0 to 15) 0x0100 + N*0x0040 */
	PRINTF("%s->DMAC_PAU_REGN=0x%08X\n", p);	/*!< Offset 0x004 DMAC Channel Pause Register N (N = 0 to 15) 0x0104 + N*0x0040 */
	PRINTF("%s->DMAC_DESC_ADDR_REGN=0x%08X\n", p);	/*!< Offset 0x008 DMAC Channel Start Address Register N (N = 0 to 15) 0x0108 + N*0x0040 */
	PRINTF("%s->DMAC_CFG_REGN=0x%08X\n", p);	/*!< Offset 0x00C DMAC Channel Configuration Register N (N = 0 to 15) 0x010C + N*0x0040 */
	PRINTF("%s->DMAC_CUR_SRC_REGN=0x%08X\n", p);	/*!< Offset 0x010 DMAC Channel Current Source Register N (N = 0 to 15) 0x0110 + N*0x0040 */
	PRINTF("%s->DMAC_CUR_DEST_REGN=0x%08X\n", p);	/*!< Offset 0x014 DMAC Channel Current Destination Register N (N = 0 to 15) 0x0114 + N*0x0040 */
	PRINTF("%s->DMAC_BCNT_LEFT_REGN=0x%08X\n", p);	/*!< Offset 0x018 DMAC Channel Byte Counter Left Register N (N = 0 to 15) 0x0118 + N*0x0040 */
	PRINTF("%s->DMAC_PARA_REGN=0x%08X\n", p);	/*!< Offset 0x01C DMAC Channel Parameter Register N (N = 0 to 15) 0x011C + N*0x0040 */
	PRINTF("%s->DMAC_MODE_REGN=0x%08X\n", p);	/*!< Offset 0x028 DMAC Mode Register N (N = 0 to 15) 0x0128 + N*0x0040 */
	PRINTF("%s->DMAC_FDESC_ADDR_REGN=0x%08X\n", p);	/*!< Offset 0x02C DMAC Former Descriptor Address Register N (N = 0 to 15) 0x012C + N*0x0040 */
	PRINTF("%s->DMAC_PKG_NUM_REGN=0x%08X\n", p);	/*!< Offset 0x030 DMAC Package Number Register N (N = 0 to 15) 0x0130 + N*0x0040 */
}
/* Print DMAC */
static void DMAC_Type_print(const DMAC_TypeDef * p)
{
	PRINTF("%s->DMAC_IRQ_EN_REG0=0x%08X\n", p);	/*!< Offset 0x000 DMAC IRQ Enable Register 0 */
	PRINTF("%s->DMAC_IRQ_EN_REG1=0x%08X\n", p);	/*!< Offset 0x004 DMAC IRQ Enable Register 1 */
	PRINTF("%s->DMAC_IRQ_PEND_REG0=0x%08X\n", p);	/*!< Offset 0x010 DMAC IRQ Pending Register 0 */
	PRINTF("%s->DMAC_IRQ_PEND_REG1=0x%08X\n", p);	/*!< Offset 0x014 DMAC IRQ Pending Register 1 */
	PRINTF("%s->DMAC_AUTO_GATE_REG=0x%08X\n", p);	/*!< Offset 0x028 DMAC Auto Gating Register */
	PRINTF("%s->DMAC_STA_REG=0x%08X\n", p);	/*!< Offset 0x030 DMAC Status Register */
}
/* Print PWM_CH */
static void PWM_CH_Type_print(const PWM_CH_TypeDef * p)
{
	PRINTF("%s->PCR=0x%08X\n", p);	/*!< Offset 0x000 PWM Control Register */
	PRINTF("%s->PPR=0x%08X\n", p);	/*!< Offset 0x004 PWM Period Register */
	PRINTF("%s->PCNTR=0x%08X\n", p);	/*!< Offset 0x008 PWM Count Register */
	PRINTF("%s->PPCNTR=0x%08X\n", p);	/*!< Offset 0x00C PWM Pulse Count Register */
	PRINTF("%s->CCR=0x%08X\n", p);	/*!< Offset 0x010 Capture Control Register */
	PRINTF("%s->CRLR=0x%08X\n", p);	/*!< Offset 0x014 Capture Rise Lock Register */
	PRINTF("%s->CFLR=0x%08X\n", p);	/*!< Offset 0x018 Capture Fall Lock Register */
}
/* Print PWM */
static void PWM_Type_print(const PWM_TypeDef * p)
{
	PRINTF("%s->PIER=0x%08X\n", p);	/*!< Offset 0x000 PWM IRQ Enable Register */
	PRINTF("%s->PISR=0x%08X\n", p);	/*!< Offset 0x004 PWM IRQ Status Register */
	PRINTF("%s->CIER=0x%08X\n", p);	/*!< Offset 0x010 Capture IRQ Enable Register */
	PRINTF("%s->CISR=0x%08X\n", p);	/*!< Offset 0x014 Capture IRQ Status Register */
	PRINTF("%s->PCGR=0x%08X\n", p);	/*!< Offset 0x040 PWM Clock Gating Register */
	PRINTF("%s->PER=0x%08X\n", p);	/*!< Offset 0x080 PWM Enable Register */
	PRINTF("%s->CER=0x%08X\n", p);	/*!< Offset 0x0C0 Capture Enable Register */
}
/* Print EMAC_ADDR */
static void EMAC_ADDR_Type_print(const EMAC_ADDR_TypeDef * p)
{
	PRINTF("%s->HIGH=0x%08X\n", p);	/*!< Offset 0x000 EMAC MAC Address High Register */
	PRINTF("%s->LOW=0x%08X\n", p);	/*!< Offset 0x004 EMAC MAC Address Low Register */
}
/* Print EMAC */
static void EMAC_Type_print(const EMAC_TypeDef * p)
{
	PRINTF("%s->EMAC_BASIC_CTL0=0x%08X\n", p);	/*!< Offset 0x000 EMAC Basic Control Register0 */
	PRINTF("%s->EMAC_BASIC_CTL1=0x%08X\n", p);	/*!< Offset 0x004 EMAC Basic Control Register1 */
	PRINTF("%s->EMAC_INT_STA=0x%08X\n", p);	/*!< Offset 0x008 EMAC Interrupt Status Register */
	PRINTF("%s->EMAC_INT_EN=0x%08X\n", p);	/*!< Offset 0x00C EMAC Interrupt Enable Register */
	PRINTF("%s->EMAC_TX_CTL0=0x%08X\n", p);	/*!< Offset 0x010 EMAC Transmit Control Register0 */
	PRINTF("%s->EMAC_TX_CTL1=0x%08X\n", p);	/*!< Offset 0x014 EMAC Transmit Control Register1 */
	PRINTF("%s->EMAC_TX_FLOW_CTL=0x%08X\n", p);	/*!< Offset 0x01C EMAC Transmit Flow Control Register */
	PRINTF("%s->EMAC_TX_DMA_DESC_LIST=0x%08X\n", p);	/*!< Offset 0x020 EMAC Transmit Descriptor List Address Register */
	PRINTF("%s->EMAC_RX_CTL0=0x%08X\n", p);	/*!< Offset 0x024 EMAC Receive Control Register0 */
	PRINTF("%s->EMAC_RX_CTL1=0x%08X\n", p);	/*!< Offset 0x028 EMAC Receive Control Register1 */
	PRINTF("%s->EMAC_RX_DMA_DESC_LIST=0x%08X\n", p);	/*!< Offset 0x034 EMAC Receive Descriptor List Address Register */
	PRINTF("%s->EMAC_RX_FRM_FLT=0x%08X\n", p);	/*!< Offset 0x038 EMAC Receive Frame Filter Register */
	PRINTF("%s->EMAC_RX_HASH0=0x%08X\n", p);	/*!< Offset 0x040 EMAC Hash Table Register0 */
	PRINTF("%s->EMAC_RX_HASH1=0x%08X\n", p);	/*!< Offset 0x044 EMAC Hash Table Register1 */
	PRINTF("%s->EMAC_MII_CMD=0x%08X\n", p);	/*!< Offset 0x048 EMAC Management Interface Command Register */
	PRINTF("%s->EMAC_MII_DATA=0x%08X\n", p);	/*!< Offset 0x04C EMAC Management Interface Data Register */
	PRINTF("%s->EMAC_TX_DMA_STA=0x%08X\n", p);	/*!< Offset 0x0B0 EMAC Transmit DMA Status Register */
	PRINTF("%s->EMAC_TX_CUR_DESC=0x%08X\n", p);	/*!< Offset 0x0B4 EMAC Current Transmit Descriptor Register */
	PRINTF("%s->EMAC_TX_CUR_BUF=0x%08X\n", p);	/*!< Offset 0x0B8 EMAC Current Transmit Buffer Address Register */
	PRINTF("%s->EMAC_RX_DMA_STA=0x%08X\n", p);	/*!< Offset 0x0C0 EMAC Receive DMA Status Register */
	PRINTF("%s->EMAC_RX_CUR_DESC=0x%08X\n", p);	/*!< Offset 0x0C4 EMAC Current Receive Descriptor Register */
	PRINTF("%s->EMAC_RX_CUR_BUF=0x%08X\n", p);	/*!< Offset 0x0C8 EMAC Current Receive Buffer Address Register */
	PRINTF("%s->EMAC_RGMII_STA=0x%08X\n", p);	/*!< Offset 0x0D0 EMAC RGMII Status Register */
}
#endif /* PRINTF */
/* Generated section end */ 
