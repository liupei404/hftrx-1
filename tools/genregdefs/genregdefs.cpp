// genregdefs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "genregdefs.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;


struct ddd
{
	char * fldname;
	unsigned fldoffs;
	char * comment;
	unsigned fldrept;   // 0 - plain field, 1..n - array
};


void genstruct(const struct ddd * regs, unsigned szregs, const char * bname)
{
	unsigned reservers = 0;
	unsigned i;

	printf("/*\n");
	printf(" * @brief %s\n", bname);
	printf(" */\n");

	printf("/*!< %s Controller Interface */\n", bname);
	printf("typedef struct %s_Type\n", bname);
	printf("{\n");
	unsigned offs = 0;
	for (i = 0; i < szregs; ++ i)
	{
		int commentspos = 54;
		const struct ddd * p = & regs [i];
		if (p->fldoffs > offs)
		{
			// reserving
			unsigned sz = p->fldoffs - offs;


			printf("\t" "         " "uint8_t reserved%u [0x%04X];\n", ++ reservers, sz);
			offs = p->fldoffs;
		}
		if (p->fldoffs == offs)
		{
			int eolpos;
            if (p->fldrept)
            {
                // Array forming
  			    printf("    " "volatile uint32_t %s [0x%03X];%n", p->fldname, p->fldrept, & eolpos);

 			    offs += 4 * p->fldrept;
            }
            else
            {
                // Plain field
  			    printf("    " "volatile uint32_t %s;%n", p->fldname, & eolpos);
 			    offs += 4;
            }
			if (eolpos < commentspos)
			{
				int pad = commentspos - eolpos;
				printf("%*.*s", pad, pad, "");
			}
			printf("/*!< Offset 0x%04X %s */\n", p->fldoffs, p->comment);
		}
		else
		{
			printf("WRONG offset at %s (%04x)\n",  p->fldname, p->fldoffs);
			break;
		}
	}
	printf("} %s_TypeDef;\n", bname);
}

const struct ddd regsCCU [] =
{
	{ "PLL_CPU_CTRL_REG", 0x0000, "PLL_CPU Control Register",  }, 
	{ "PLL_DDR_CTRL_REG", 0x0010, "PLL_DDR Control Register",  }, 
	{ "PLL_PERI_CTRL_REG", 0x0020, "PLL_PERI Control Register",  }, 
	{ "PLL_VIDEO0_CTRL_REG", 0x0040, "PLL_VIDEO0 Control Register",  }, 
	{ "PLL_VIDEO1_CTRL_REG", 0x0048, "PLL_VIDEO1 Control Register",  }, 
	{ "PLL_VE_CTRL_REG", 0x0058, "PLL_VE Control Register",  }, 
	{ "PLL_AUDIO0_CTRL_REG", 0x0078, "PLL_AUDIO0 Control Register",  }, 
	{ "PLL_AUDIO1_CTRL_REG", 0x0080, "PLL_AUDIO1 Control Register",  }, 
	{ "PLL_DDR_PAT0_CTRL_REG", 0x0110, "PLL_DDR Pattern0 Control Register",  }, 
	{ "PLL_DDR_PAT1_CTRL_REG", 0x0114, "PLL_DDR Pattern1 Control Register",  }, 
	{ "PLL_PERI_PAT0_CTRL_REG", 0x0120, "PLL_PERI Pattern0 Control Register",  }, 
	{ "PLL_PERI_PAT1_CTRL_REG", 0x0124, "PLL_PERI Pattern1 Control Register",  }, 
	{ "PLL_VIDEO0_PAT0_CTRL_REG", 0x0140, "PLL_VIDEO0 Pattern0 Control Register",  }, 
	{ "PLL_VIDEO0_PAT1_CTRL_REG", 0x0144, "PLL_VIDEO0 Pattern1 Control Register",  }, 
	{ "PLL_VIDEO1_PAT0_CTRL_REG", 0x0148, "PLL_VIDEO1 Pattern0 Control Register",  }, 
	{ "PLL_VIDEO1_PAT1_CTRL_REG", 0x014C, "PLL_VIDEO1 Pattern1 Control Register",  }, 
	{ "PLL_VE_PAT0_CTRL_REG", 0x0158, "PLL_VE Pattern0 Control Register",  }, 
	{ "PLL_VE_PAT1_CTRL_REG", 0x015C, "PLL_VE Pattern1 Control Register",  }, 
	{ "PLL_AUDIO0_PAT0_CTRL_REG", 0x0178, "PLL_AUDIO0 Pattern0 Control Register",  }, 
	{ "PLL_AUDIO0_PAT1_CTRL_REG", 0x017C, "PLL_AUDIO0 Pattern1 Control Register",  }, 
	{ "PLL_AUDIO1_PAT0_CTRL_REG", 0x0180, "PLL_AUDIO1 Pattern0 Control Register",  }, 
	{ "PLL_AUDIO1_PAT1_CTRL_REG", 0x0184, "PLL_AUDIO1 Pattern1 Control Register",  }, 
	{ "PLL_CPU_BIAS_REG", 0x0300, "PLL_CPU Bias Register",  }, 
	{ "PLL_DDR_BIAS_REG", 0x0310, "PLL_DDR Bias Register",  }, 
	{ "PLL_PERI_BIAS_REG", 0x0320, "PLL_PERI Bias Register",  }, 
	{ "PLL_VIDEO0_BIAS_REG", 0x0340, "PLL_VIDEO0 Bias Register",  }, 
	{ "PLL_VIDEO1_BIAS_REG", 0x0348, "PLL_VIDEO1 Bias Register",  }, 
	{ "PLL_VE_BIAS_REG", 0x0358, "PLL_VE Bias Register",  }, 
	{ "PLL_AUDIO0_BIAS_REG", 0x0378, "PLL_AUDIO0 Bias Register",  }, 
	{ "PLL_AUDIO1_BIAS_REG", 0x0380, "PLL_AUDIO1 Bias Register",  }, 
	{ "PLL_CPU_TUN_REG", 0x0400, "PLL_CPU Tuning Register",  }, 
	{ "CPU_AXI_CFG_REG", 0x0500, "CPU_AXI Configuration Register",  }, 
	{ "CPU_GATING_REG", 0x0504, "CPU_GATING Configuration Register",  }, 
	{ "PSI_CLK_REG", 0x0510, "PSI Clock Register",  }, 
	{ "APB0_CLK_REG", 0x0520, "APB0 Clock Register",  }, 
	{ "APB1_CLK_REG", 0x0524, "APB1 Clock Register",  }, 
	{ "MBUS_CLK_REG", 0x0540, "MBUS Clock Register",  }, 
	{ "DE_CLK_REG", 0x0600, "DE Clock Register",  }, 
	{ "DE_BGR_REG", 0x060C, "DE Bus Gating Reset Register",  }, 
	{ "DI_CLK_REG", 0x0620, "DI Clock Register",  }, 
	{ "DI_BGR_REG", 0x062C, "DI Bus Gating Reset Register",  }, 
	{ "G2D_CLK_REG", 0x0630, "G2D Clock Register",  }, 
	{ "G2D_BGR_REG", 0x063C, "G2D Bus Gating Reset Register",  }, 
	{ "CE_CLK_REG", 0x0680, "CE Clock Register",  }, 
	{ "CE_BGR_REG", 0x068C, "CE Bus Gating Reset Register",  }, 
	{ "VE_CLK_REG", 0x0690, "VE Clock Register",  }, 
	{ "VE_BGR_REG", 0x069C, "VE Bus Gating Reset Register",  }, 
	{ "DMA_BGR_REG", 0x070C, "DMA Bus Gating Reset Register",  }, 
	{ "MSGBOX_BGR_REG", 0x071C, "MSGBOX Bus Gating Reset Register",  }, 
	{ "SPINLOCK_BGR_REG", 0x072C, "SPINLOCK Bus Gating Reset Register",  }, 
	{ "HSTIMER_BGR_REG", 0x073C, "HSTIMER Bus Gating Reset Register",  }, 
	{ "AVS_CLK_REG", 0x0740,	"AVS Clock Register",  }, 
	{ "DBGSYS_BGR_REG", 0x078C, "DBGSYS Bus Gating Reset Register",  }, 
	{ "PWM_BGR_REG", 0x07AC, "PWM Bus Gating Reset Register",  }, 
	{ "IOMMU_BGR_REG", 0x07BC, "IOMMU Bus Gating Reset Register",  }, 
	{ "DRAM_CLK_REG", 0x0800, "DRAM Clock Register",  }, 
	{ "MBUS_MAT_CLK_GATING_REG", 0x0804,	"MBUS Master Clock Gating Register",  }, 
	{ "DRAM_BGR_REG", 0x080C, "DRAM Bus Gating Reset Register",  }, 
	{ "SMHC0_CLK_REG", 0x0830, "SMHC0 Clock Register",  }, 
	{ "SMHC1_CLK_REG", 0x0834, "SMHC1 Clock Register",  }, 
	{ "SMHC2_CLK_REG", 0x0838, "SMHC2 Clock Register",  }, 
	{ "SMHC_BGR_REG", 0x084C,"SMHC Bus Gating Reset Register",  }, 
	{ "UART_BGR_REG", 0x090C,	"UART Bus Gating Reset Register",  }, 
	{ "TWI_BGR_REG", 0x091C, "TWI Bus Gating Reset Register",  }, 
	{ "SPI0_CLK_REG", 0x0940, "SPI0 Clock Register",  }, 
	{ "SPI1_CLK_REG", 0x0944, "SPI1 Clock Register",  }, 
	{ "SPI_BGR_REG", 0x096C, "SPI Bus Gating Reset Register",  }, 
	{ "EMAC_25M_CLK_REG", 0x0970, "EMAC_25M Clock Register",  }, 
	{ "EMAC_BGR_REG", 0x097C, "EMAC Bus Gating Reset Register",  }, 
	{ "IRTX_CLK_REG", 0x09C0, "IRTX Clock Register",  }, 
	{ "IRTX_BGR_REG", 0x09CC, "IRTX Bus Gating Reset Register",  }, 
	{ "GPADC_BGR_REG", 0x09EC, "GPADC Bus Gating Reset Register",  }, 
	{ "THS_BGR_REG", 0x09FC, "THS Bus Gating Reset Register",  }, 
	{ "I2S1_CLK_REG", 0x0A14, "I2S1 Clock Register",  }, 
	{ "I2S2_CLK_REG", 0x0A18, "I2S2 Clock Register",  }, 
	{ "I2S2_ASRC_CLK_REG", 0x0A1C, "I2S2_ASRC Clock Register",  }, 
	{ "I2S_BGR_REG", 0x0A20, "I2S Bus Gating Reset Register",  }, 
	{ "OWA_TX_CLK_REG", 0x0A24, "OWA_TX Clock Register",  }, 
	{ "OWA_RX_CLK_REG", 0x0A28, "OWA_RX Clock Register",  }, 
	{ "OWA_BGR_REG", 0x0A2C, "OWA Bus Gating Reset Register",  }, 
	{ "DMIC_CLK_REG", 0x0A40, "DMIC Clock Register",  }, 
	{ "DMIC_BGR_REG", 0x0A4C, "DMIC Bus Gating Reset Register",  }, 
	{ "AUDIO_CODEC_DAC_CLK_REG", 0x0A50, "AUDIO_CODEC_DAC Clock Register",  }, 
	{ "AUDIO_CODEC_ADC_CLK_REG", 0x0A54, "AUDIO_CODEC_ADC Clock Register",  }, 
	{ "AUDIO_CODEC_BGR_REG", 0x0A5C, "AUDIO_CODEC Bus Gating Reset Register",  }, 
	{ "USB0_CLK_REG", 0x0A70, "USB0 Clock Register",  }, 
	{ "USB1_CLK_REG", 0x0A74, "USB1 Clock Register",  }, 
	{ "USB_BGR_REG", 0x0A8C, "USB Bus Gating Reset Register",  }, 
	{ "DPSS_TOP_BGR_REG", 0x0ABC, "DPSS_TOP Bus Gating Reset Register",  }, 
	{ "DSI_CLK_REG", 0x0B24, "DSI Clock Register",  }, 
	{ "DSI_BGR_REG", 0x0B4C, "DSI Bus Gating Reset Register",  }, 
	{ "TCONLCD_CLK_REG", 0x0B60, "TCONLCD Clock Register",  }, 
	{ "TCONLCD_BGR_REG", 0x0B7C, "TCONLCD Bus Gating Reset Register",  }, 
	{ "TCONTV_CLK_REG", 0x0B80, "TCONTV Clock Register",  }, 
	{ "TCONTV_BGR_REG", 0x0B9C, "TCONTV Bus Gating Reset Register",  }, 
	{ "LVDS_BGR_REG", 0x0BAC, "LVDS Bus Gating Reset Register",  }, 
	{ "TVE_CLK_REG", 0x0BB0, "TVE Clock Register",  }, 
	{ "TVE_BGR_REG", 0x0BBC, "TVE Bus Gating Reset Register",  }, 
	{ "TVD_CLK_REG", 0x0BC0, "TVD Clock Register",  }, 
	{ "TVD_BGR_REG", 0x0BDC, "TVD Bus Gating Reset Register",  }, 
	{ "LEDC_CLK_REG", 0x0BF0, "LEDC Clock Register",  }, 
	{ "LEDC_BGR_REG", 0x0BFC, "LEDC Bus Gating Reset Register",  }, 
	{ "CSI_CLK_REG", 0x0C04, "CSI Clock Register",  }, 
	{ "CSI_MASTER_CLK_REG", 0x0C08, "CSI Master Clock Register",  }, 
	{ "CSI_BGR_REG", 0x0C1C, "CSI Bus Gating Reset Register",  }, 
	{ "TPADC_CLK_REG", 0x0C50, "TPADC Clock Register",  }, 
	{ "TPADC_BGR_REG", 0x0C5C, "TPADC Bus Gating Reset Register",  }, 
	{ "DSP_CLK_REG", 0x0C70, "DSP Clock Register",  }, 
	{ "DSP_BGR_REG", 0x0C7C, "DSP Bus Gating Reset Register",  }, 
	{ "PLL_LOCK_DBG_CTRL_REG", 0x0F04, "PLL Lock Debug Control Register",  }, 
	{ "FRE_DET_CTRL_REG", 0x0F08, "Frequency Detect Control Register",  }, 
	{ "FRE_UP_LIM_REG", 0x0F0C, "Frequency Up Limit Register",  }, 
	{ "FRE_DOWN_LIM_REG", 0x0F10, "Frequency Down Limit Register",  }, 
	{ "CCU_FAN_GATE_REG", 0x0F30, "CCU FANOUT CLOCK GATE Register",  }, 
	{ "CLK27M_FAN_REG", 0x0F34, "CLK27M FANOUT Register",  }, 
	{ "PCLK_FAN_REG", 0x0F38, "PCLK FANOUT Register",  }, 
	{ "CCU_FAN_REG", 0x0F3C, "CCU FANOUT Register",  }, 
};

const struct ddd regsSYS_CFG [] =
{
	{ "DSP_BOOT_RAMMAP_REG", 0x0008, "DSP Boot SRAM Remap Control Register",  }, 
	{ "VER_REG", 0x0024, "Version Register",  }, 
	{ "EMAC_EPHY_CLK_REG0", 0x0030, "EMAC-EPHY Clock Register 0",  }, 
	{ "SYS_LDO_CTRL_REG", 0x0150, "System LDO Control Register",  }, 
	{ "RESCAL_CTRL_REG", 0x0160, "Resistor Calibration Control Register",  }, 
	{ "RES240_CTRL_REG", 0x0168, "240ohms Resistor Manual Control Register",  }, 
	{ "RESCAL_STATUS_REG", 0x016C, "Resistor Calibration Status Register",  }, 
};

static int processfile(const char * file, const char * bname)
{
    FILE * fp = fopen(file, "rt");
    if (fp == NULL)
        return 1;

    size_t maxrows = 1024;
    struct ddd * regs = (struct ddd *) calloc(sizeof (struct ddd), maxrows);
    if (regs == NULL)
        return 1;
    size_t nregs;
    for (nregs = 0; nregs < maxrows; ++ nregs)
    {
        char buff [1024];
        char * s0 = fgets(buff, sizeof buff / sizeof buff [0], fp);
        if (s0 == NULL)
            break;
         if (strchr(s0, '\n') != NULL)
            * strchr(s0, '\n') = '\0';
         if (strchr(s0, '/') != NULL)
            * strchr(s0, '/') = '_';
         if (strchr(s0, '/') != NULL)
            * strchr(s0, '/') = '_';
        regs [nregs].fldname = strdup(s0);

        char * s1 = fgets(buff, sizeof buff / sizeof buff [0], fp);
        if (s1 == NULL)
            break;

        int nargs = sscanf(buff, "%x %x", & regs [nregs].fldoffs, & regs [nregs].fldrept);
        switch (nargs)
        {
        case 1:
            regs [nregs].fldrept = 0;
            break;
        case 2:
            break;
        default:
            if (1 != sscanf(buff, "%u", & regs [nregs].fldoffs))
			    printf("WRONG offset format '%s'\n", regs [nregs].fldname);
            break;
        }

        char * s2 = fgets(buff, sizeof buff / sizeof buff [0], fp);
        if (s2 == NULL)
            break;
        if (strchr(s2, '\n') != NULL)
            * strchr(s2, '\n') = '\0';
       regs [nregs].comment = strdup(s2);

    }
	genstruct(regs, nregs, bname);

    unsigned i;
    for (i = 0; i < nregs; ++ i)
    {
        free(regs [i].fldname);
        free(regs [i].comment);
    }
    free(regs);
    return 0;
}

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	//genstruct(regsCCU, sizeof regsCCU / sizeof regsCCU [0], "CCU");
	//genstruct(regsSYS_CFG, sizeof regsSYS_CFG / sizeof regsSYS_CFG [0], "SYS_CFG");

    if (argc < 3)
        return 1;
    processfile(argv [1], argv [2]);
	return 0;
}


