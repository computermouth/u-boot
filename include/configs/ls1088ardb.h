/*
 * Copyright 2017 NXP
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __LS1088A_RDB_H
#define __LS1088A_RDB_H

#include "ls1088a_common.h"

#define CONFIG_DISPLAY_BOARDINFO_LATE

#if defined(CONFIG_QSPI_BOOT)
#define CONFIG_ENV_IS_IN_SPI_FLASH
#define CONFIG_ENV_SIZE			0x2000          /* 8KB */
#define CONFIG_ENV_OFFSET		0x300000        /* 3MB */
#define CONFIG_ENV_SECT_SIZE		0x40000
#else
#define CONFIG_ENV_IS_IN_FLASH
#define CONFIG_ENV_ADDR			(CONFIG_SYS_FLASH_BASE + 0x300000)
#define CONFIG_ENV_SECT_SIZE		0x20000
#define CONFIG_ENV_SIZE			0x20000
#endif

#if defined(CONFIG_QSPI_BOOT)
#define CONFIG_QIXIS_I2C_ACCESS
#define SYS_NO_FLASH
#endif

#define CONFIG_SYS_CLK_FREQ		100000000
#define CONFIG_DDR_CLK_FREQ		100000000
#define COUNTER_FREQUENCY_REAL		25000000	/* 25MHz */
#define COUNTER_FREQUENCY		25000000	/* 25MHz */

#define CONFIG_DDR_SPD
#ifdef CONFIG_EMU
#define CONFIG_SYS_FSL_DDR_EMU
#define CONFIG_SYS_MXC_I2C1_SPEED	40000000
#define CONFIG_SYS_MXC_I2C2_SPEED	40000000
#else
#define CONFIG_DDR_ECC
#define CONFIG_ECC_INIT_VIA_DDRCONTROLLER
#define CONFIG_MEM_INIT_VALUE		0xdeadbeef
#endif
#define SPD_EEPROM_ADDRESS	0x51
#define CONFIG_SYS_SPD_BUS_NUM	0	/* SPD on I2C bus 0 */
#define CONFIG_DIMM_SLOTS_PER_CTLR	1


#if !defined(CONFIG_QSPI_BOOT) && !defined(CONFIG_SD_BOOT_QSPI)
#define CONFIG_SYS_NOR0_CSPR_EXT	(0x0)
#define CONFIG_SYS_NOR_AMASK		IFC_AMASK(128 * 1024 * 1024)
#define CONFIG_SYS_NOR_AMASK_EARLY	IFC_AMASK(64 * 1024 * 1024)

#define CONFIG_SYS_NOR0_CSPR					\
	(CSPR_PHYS_ADDR(CONFIG_SYS_FLASH_BASE_PHYS)		| \
	CSPR_PORT_SIZE_16					| \
	CSPR_MSEL_NOR						| \
	CSPR_V)
#define CONFIG_SYS_NOR0_CSPR_EARLY				\
	(CSPR_PHYS_ADDR(CONFIG_SYS_FLASH_BASE_PHYS_EARLY)	| \
	CSPR_PORT_SIZE_16					| \
	CSPR_MSEL_NOR						| \
	CSPR_V)
#define CONFIG_SYS_NOR_CSOR	CSOR_NOR_ADM_SHIFT(6)
#define CONFIG_SYS_NOR_FTIM0	(FTIM0_NOR_TACSE(0x1) | \
				FTIM0_NOR_TEADC(0x1) | \
				FTIM0_NOR_TEAHC(0x1))
#define CONFIG_SYS_NOR_FTIM1	(FTIM1_NOR_TACO(0x1) | \
				FTIM1_NOR_TRAD_NOR(0x1))
#define CONFIG_SYS_NOR_FTIM2	(FTIM2_NOR_TCS(0x0) | \
				FTIM2_NOR_TCH(0x0) | \
				FTIM2_NOR_TWP(0x1))
#define CONFIG_SYS_NOR_FTIM3	0x04000000
#define CONFIG_SYS_IFC_CCR	0x01000000

#ifndef SYS_NO_FLASH
#define CONFIG_FLASH_CFI_DRIVER
#define CONFIG_SYS_FLASH_CFI
#define CONFIG_SYS_FLASH_USE_BUFFER_WRITE
#define CONFIG_SYS_FLASH_QUIET_TEST
#define CONFIG_FLASH_SHOW_PROGRESS	45 /* count down from 45/5: 9..1 */

#define CONFIG_SYS_MAX_FLASH_BANKS	1	/* number of banks */
#define CONFIG_SYS_MAX_FLASH_SECT	1024	/* sectors per device */
#define CONFIG_SYS_FLASH_ERASE_TOUT	60000	/* Flash Erase Timeout (ms) */
#define CONFIG_SYS_FLASH_WRITE_TOUT	500	/* Flash Write Timeout (ms) */

#define CONFIG_SYS_FLASH_EMPTY_INFO
#define CONFIG_SYS_FLASH_BANKS_LIST	{ CONFIG_SYS_FLASH_BASE }
#endif
#endif
#define CONFIG_SYS_NAND_MAX_ECCPOS	256
#define CONFIG_SYS_NAND_MAX_OOBFREE	2

#define CONFIG_SYS_NAND_CSPR_EXT	(0x0)
#define CONFIG_SYS_NAND_CSPR	(CSPR_PHYS_ADDR(CONFIG_SYS_NAND_BASE_PHYS) \
				| CSPR_PORT_SIZE_8 /* Port Size = 8 bit */ \
				| CSPR_MSEL_NAND	/* MSEL = NAND */ \
				| CSPR_V)
#define CONFIG_SYS_NAND_AMASK	IFC_AMASK(64 * 1024)

#define CONFIG_SYS_NAND_CSOR    (CSOR_NAND_ECC_ENC_EN   /* ECC on encode */ \
				| CSOR_NAND_ECC_DEC_EN  /* ECC on decode */ \
				| CSOR_NAND_ECC_MODE_4  /* 4-bit ECC */ \
				| CSOR_NAND_RAL_3	/* RAL = 3Byes */ \
				| CSOR_NAND_PGS_2K	/* Page Size = 2K */ \
				| CSOR_NAND_SPRZ_64/* Spare size = 64 */ \
				| CSOR_NAND_PB(64))	/*Pages Per Block = 64*/

#define CONFIG_SYS_NAND_ONFI_DETECTION

/* ONFI NAND Flash mode0 Timing Params */
#define CONFIG_SYS_NAND_FTIM0		(FTIM0_NAND_TCCST(0x07) | \
					FTIM0_NAND_TWP(0x18)   | \
					FTIM0_NAND_TWCHT(0x07) | \
					FTIM0_NAND_TWH(0x0a))
#define CONFIG_SYS_NAND_FTIM1		(FTIM1_NAND_TADLE(0x32) | \
					FTIM1_NAND_TWBE(0x39)  | \
					FTIM1_NAND_TRR(0x0e)   | \
					FTIM1_NAND_TRP(0x18))
#define CONFIG_SYS_NAND_FTIM2		(FTIM2_NAND_TRAD(0x0f) | \
					FTIM2_NAND_TREH(0x0a) | \
					FTIM2_NAND_TWHRE(0x1e))
#define CONFIG_SYS_NAND_FTIM3		0x0

#define CONFIG_SYS_NAND_BASE_LIST	{ CONFIG_SYS_NAND_BASE }
#define CONFIG_SYS_MAX_NAND_DEVICE	1
#define CONFIG_MTD_NAND_VERIFY_WRITE

#define CONFIG_SYS_NAND_BLOCK_SIZE	(128 * 1024)

#define CONFIG_FSL_QIXIS
#define CONFIG_SYS_I2C_FPGA_ADDR	0x66
#define QIXIS_LBMAP_SWITCH		2
#define QIXIS_QMAP_MASK			0xe0
#define QIXIS_QMAP_SHIFT		5
#define QIXIS_LBMAP_MASK		0x1f
#define QIXIS_LBMAP_SHIFT		5
#define QIXIS_LBMAP_DFLTBANK		0x00
#define QIXIS_LBMAP_ALTBANK		0x20
#define QIXIS_LBMAP_SD			0x00
#define QIXIS_LBMAP_SD_QSPI		0x00
#define QIXIS_LBMAP_QSPI		0x00
#define QIXIS_RCW_SRC_SD		0x40
#define QIXIS_RCW_SRC_QSPI		0x62
#define QIXIS_RST_CTL_RESET		0x31
#define QIXIS_RCFG_CTL_RECONFIG_IDLE	0x20
#define QIXIS_RCFG_CTL_RECONFIG_START	0x21
#define QIXIS_RCFG_CTL_WATCHDOG_ENBLE	0x08
#define	QIXIS_RST_FORCE_MEM		0x01

#define CONFIG_SYS_FPGA_CSPR_EXT	(0x0)
#define CONFIG_SYS_FPGA_CSPR		(CSPR_PHYS_ADDR(QIXIS_BASE_PHYS_EARLY) \
					| CSPR_PORT_SIZE_8 \
					| CSPR_MSEL_GPCM \
					| CSPR_V)
#define SYS_FPGA_CSPR_FINAL	(CSPR_PHYS_ADDR(QIXIS_BASE_PHYS) \
					| CSPR_PORT_SIZE_8 \
					| CSPR_MSEL_GPCM \
					| CSPR_V)

#define CONFIG_SYS_FPGA_AMASK		IFC_AMASK(64*1024)
#define CONFIG_SYS_FPGA_CSOR		CSOR_GPCM_ADM_SHIFT(0)
/* QIXIS Timing parameters*/
#define SYS_FPGA_CS_FTIM0	(FTIM0_GPCM_TACSE(0x0e) | \
					FTIM0_GPCM_TEADC(0x0e) | \
					FTIM0_GPCM_TEAHC(0x0e))
#define SYS_FPGA_CS_FTIM1	(FTIM1_GPCM_TACO(0xff) | \
					FTIM1_GPCM_TRAD(0x3f))
#define SYS_FPGA_CS_FTIM2	(FTIM2_GPCM_TCS(0xf) | \
					FTIM2_GPCM_TCH(0xf) | \
					FTIM2_GPCM_TWP(0x3E))
#define SYS_FPGA_CS_FTIM3	0x0

#if defined(CONFIG_QSPI_BOOT) || defined(CONFIG_SD_BOOT_QSPI)
#define CONFIG_SYS_CSPR0_EXT		CONFIG_SYS_NAND_CSPR_EXT
#define CONFIG_SYS_CSPR0		CONFIG_SYS_NAND_CSPR
#define CONFIG_SYS_AMASK0		CONFIG_SYS_NAND_AMASK
#define CONFIG_SYS_CSOR0		CONFIG_SYS_NAND_CSOR
#define CONFIG_SYS_CS0_FTIM0		CONFIG_SYS_NAND_FTIM0
#define CONFIG_SYS_CS0_FTIM1		CONFIG_SYS_NAND_FTIM1
#define CONFIG_SYS_CS0_FTIM2		CONFIG_SYS_NAND_FTIM2
#define CONFIG_SYS_CS0_FTIM3		CONFIG_SYS_NAND_FTIM3
#define CONFIG_SYS_CSPR2_EXT		CONFIG_SYS_FPGA_CSPR_EXT
#define CONFIG_SYS_CSPR2		CONFIG_SYS_FPGA_CSPR
#define CONFIG_SYS_CSPR2_FINAL		SYS_FPGA_CSPR_FINAL
#define CONFIG_SYS_AMASK2		CONFIG_SYS_FPGA_AMASK
#define CONFIG_SYS_CSOR2		CONFIG_SYS_FPGA_CSOR
#define CONFIG_SYS_CS2_FTIM0		SYS_FPGA_CS_FTIM0
#define CONFIG_SYS_CS2_FTIM1		SYS_FPGA_CS_FTIM1
#define CONFIG_SYS_CS2_FTIM2		SYS_FPGA_CS_FTIM2
#define CONFIG_SYS_CS2_FTIM3		SYS_FPGA_CS_FTIM3
#else
#define CONFIG_SYS_CSPR0_EXT		CONFIG_SYS_NOR0_CSPR_EXT
#define CONFIG_SYS_CSPR0		CONFIG_SYS_NOR0_CSPR_EARLY
#define CONFIG_SYS_CSPR0_FINAL		CONFIG_SYS_NOR0_CSPR
#define CONFIG_SYS_AMASK0		CONFIG_SYS_NOR_AMASK
#define CONFIG_SYS_CSOR0		CONFIG_SYS_NOR_CSOR
#define CONFIG_SYS_CS0_FTIM0		CONFIG_SYS_NOR_FTIM0
#define CONFIG_SYS_CS0_FTIM1		CONFIG_SYS_NOR_FTIM1
#define CONFIG_SYS_CS0_FTIM2		CONFIG_SYS_NOR_FTIM2
#define CONFIG_SYS_CS0_FTIM3		CONFIG_SYS_NOR_FTIM3
#endif


#define CONFIG_SYS_LS_MC_BOOT_TIMEOUT_MS 5000

/*
 * I2C bus multiplexer
 */
#define I2C_MUX_PCA_ADDR_PRI		0x77
#define I2C_MUX_PCA_ADDR_SEC		0x76 /* Secondary multiplexer */
#define I2C_RETIMER_ADDR		0x18
#define I2C_MUX_CH_DEFAULT		0x8
#define I2C_MUX_CH5			0xD
/*
* RTC configuration
*/
#define RTC
#define CONFIG_RTC_PCF8563 1
#define CONFIG_SYS_I2C_RTC_ADDR         0x51  /* Channel 3*/
#define CONFIG_CMD_DATE

/* EEPROM */
#define CONFIG_ID_EEPROM
#define CONFIG_SYS_I2C_EEPROM_NXID
#define CONFIG_SYS_EEPROM_BUS_NUM		0
#define CONFIG_SYS_I2C_EEPROM_ADDR		0x57
#define CONFIG_SYS_I2C_EEPROM_ADDR_LEN		1
#define CONFIG_SYS_EEPROM_PAGE_WRITE_BITS	3
#define CONFIG_SYS_EEPROM_PAGE_WRITE_DELAY_MS	5

/* QSPI device */
#if defined(CONFIG_QSPI_BOOT)
#define CONFIG_FSL_QSPI
#define CONFIG_SPI_FLASH_SPANSION
#define FSL_QSPI_FLASH_SIZE		(1 << 26)
#define FSL_QSPI_FLASH_NUM		2
#endif

#define CONFIG_CMD_MEMINFO
#define CONFIG_CMD_MEMTEST
#define CONFIG_SYS_MEMTEST_START	0x80000000
#define CONFIG_SYS_MEMTEST_END		0x9fffffff

#define CONFIG_SYS_MONITOR_BASE CONFIG_SYS_TEXT_BASE

#define CONFIG_FSL_MEMAC

/* Initial environment variables */
#if defined(CONFIG_QSPI_BOOT)
#undef CONFIG_EXTRA_ENV_SETTINGS
#define CONFIG_EXTRA_ENV_SETTINGS		\
	"hwconfig=fsl_ddr:bank_intlv=auto\0"	\
	"loadaddr=0x90100000\0"			\
	"kernel_addr=0x100000\0"		\
	"ramdisk_addr=0x800000\0"		\
	"ramdisk_size=0x2000000\0"		\
	"fdt_high=0xa0000000\0"			\
	"initrd_high=0xffffffffffffffff\0"	\
	"kernel_start=0x1000000\0"		\
	"kernel_load=0xa0000000\0"		\
	"kernel_size=0x2800000\0"		\
	"mcinitcmd=sf probe 0:0;sf read 0x80000000 0xA00000 0x100000;"	\
	"sf read 0x80100000 0xE00000 0x100000;" \
	"fsl_mc start mc 0x80000000 0x80100000\0"	\
	"mcmemsize=0x70000000 \0"

#endif

/* MAC/PHY configuration */
#ifdef CONFIG_FSL_MC_ENET
#define CONFIG_PHYLIB_10G
#define CONFIG_PHY_GIGE
#define CONFIG_PHYLIB

#define CONFIG_PHY_VITESSE
#define CONFIG_PHY_AQUANTIA
#define AQ_PHY_ADDR1			0x00
#define AQR105_IRQ_MASK			0x00000004

#define QSGMII1_PORT1_PHY_ADDR		0x0c
#define QSGMII1_PORT2_PHY_ADDR		0x0d
#define QSGMII1_PORT3_PHY_ADDR		0x0e
#define QSGMII1_PORT4_PHY_ADDR		0x0f
#define QSGMII2_PORT1_PHY_ADDR		0x1c
#define QSGMII2_PORT2_PHY_ADDR		0x1d
#define QSGMII2_PORT3_PHY_ADDR		0x1e
#define QSGMII2_PORT4_PHY_ADDR		0x1f

#define CONFIG_MII
#define CONFIG_ETHPRIME		"DPMAC1@xgmii"
#define CONFIG_PHY_GIGE
#endif

/*  MMC  */
#ifdef CONFIG_MMC
#define CONFIG_FSL_ESDHC
#define CONFIG_SYS_FSL_MMC_HAS_CAPBLT_VS33
#endif

#undef CONFIG_CMDLINE_EDITING
#include <config_distro_defaults.h>

#define BOOT_TARGET_DEVICES(func) \
	func(USB, usb, 0) \
	func(MMC, mmc, 0) \
	func(SCSI, scsi, 0) \
	func(DHCP, dhcp, na)
#include <config_distro_bootcmd.h>

#include <asm/fsl_secure_boot.h>

#endif /* __LS1088A_RDB_H */
