/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: LicenseRef-Realtek-5-Clause
 */


#ifndef _RTL876X_RCC_H_
#define _RTL876X_RCC_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "rtl876x.h"

/** @addtogroup 87x3g_RCC RCC
  * @brief RCC driver module.
  * @{
  */

/** @defgroup 87x3g_RCC_Exported_Constants RCC Exported Constants
  * @{
  */

/*============================================================================*
 *                              Macros  IO_module_20241008_v0.xlsx
 *============================================================================*/

/** @defgroup 87x3g_RCC_Peripheral_Clock  RCC Peripheral Clock
  * @{
  */
/*start  offset address  28| --> bit28, (0x01 << 29) --> adress 0x230,(0x02 << 29) -->0x234, 0x00 << 10) -->0x00 sleep clock cfg?  yes*/
#define APBPeriph_SLEEP_CLOCK_EXIST       (0) //!< Peripheral sleep clock is exist.
#define APBPeriph_SLEEP_CLOCK_NOT_EXIST   (BIT10) //!< Peripheral sleep clock is not exist.

/* 0x220 */
#define APBPeriph_I2S2_CLOCK              ((uint32_t)(1 << 12)) //!< I2S2 clock.
#define APBPeriph_I2S1_CLOCK              ((uint32_t)((1 << 6) | (1 << 8))) //!< I2S1 clock.
#define APBPeriph_I2S0_CLOCK              ((uint32_t)((1 << 5) | (1 << 8))) //!< I2S0 clock.
#define APBPeriph_CODEC_CLOCK             ((uint32_t)(1 << 4)) //!< CODEC clock.

/* 0x230 */
#define APBPeriph_SD_HOST1_CLOCK            ((uint32_t)( 28 | (0x01UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< SD HOST1 clock.
#define APBPeriph_SD_HOST_CLOCK             ((uint32_t)( 26 | (0x01UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< SD host clock.
#define APBPeriph_GPIOA_CLOCK               ((uint32_t)( 24 | (0x01UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< GPIOA clock.
#define APBPeriph_GPIO_CLOCK                APBPeriph_GPIOA_CLOCK //!< GPIO clock.
#define APBPeriph_GPIOB_CLOCK               ((uint32_t)( 22 | (0x01UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< GPIOB clock.
#define APBPeriph_FLASH2_CLOCK              ((uint32_t)( 20 | (0x01UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< FLASH2 clock.
#define APBPeriph_FLASH1_CLOCK              ((uint32_t)( 18 | (0x01UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< FLASH1 clock.
#define APBPeriph_GDMA_CLOCK                ((uint32_t)( 16 | (0x01UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< GDMA clock.
#define APBPeriph_TIMER_CLOCK               ((uint32_t)( 14 | (0x01UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< Timer clock.
#define APBPeriph_TIMERA_CLOCK              APBPeriph_TIMER_CLOCK //!< Timer clock.
#define APBPeriph_FLASH3_CLOCK              ((uint32_t)( 12 | (0x01UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< FLASH3 clock.
#define APBPeriph_AHBC_CLOCK                ((uint32_t)( 10 | (0x01UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< AHBC clock.
#define APBPeriph_FLASH_CLOCK               ((uint32_t)(  8 | (0x01UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< FLASH clock.
#define APBPeriph_VENDOR_REG_CLOCK          ((uint32_t)(  6 | (0x01UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< VENDOR REG clock.
#define APBPeriph_CKE_BTV_CLOCK             ((uint32_t)(  5 | (0x01UL << 29) | APBPeriph_SLEEP_CLOCK_NOT_EXIST)) //!< CKE BTV clock.
#define APBPeriph_BUS_RAM_SLP_CLOCK         ((uint32_t)(  4 | (0x01UL << 29) | APBPeriph_SLEEP_CLOCK_NOT_EXIST)) //!< BUS RAM SLP clock.
#define APBPeriph_CKE_CTRLAP_CLOCK          ((uint32_t)(  3 | (0x01UL << 29) | APBPeriph_SLEEP_CLOCK_NOT_EXIST)) //!< CKE CTRLAP clock.
#define APBPeriph_CKE_PLFM_CLOCK            ((uint32_t)(  2 | (0x01UL << 29) | APBPeriph_SLEEP_CLOCK_NOT_EXIST)) //!< CKE PLFM clock.
#define APBPeriph_GPIO1_DEB_CLOCK           ((uint32_t)(  1 | (0x01UL << 29) | APBPeriph_SLEEP_CLOCK_NOT_EXIST)) //!< GPIO1 DEB clock.
#define APBPeriph_GPIO0_DEB_CLOCK           ((uint32_t)(  0 | (0x01UL << 29) | APBPeriph_SLEEP_CLOCK_NOT_EXIST)) //!< GPIO0 DEB clock.

/* 0x234 */
#define APBPeriph_IDU_CLOCK                 ((uint32_t)( 30 | (0x02UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< IDU clock.
#define APBPeriph_PKE_CLOCK                 ((uint32_t)( 28 | (0x02UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< PKE clock.
#define APBPeriph_PPE_CLOCK                 ((uint32_t)( 26 | (0x02UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< PPE clock.
#define APBPeriph_CAN0_CLOCK                ((uint32_t)( 24 | (0x02UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< CAN0 clock.
#define APBPeriph_SPI2_CLOCK                ((uint32_t)( 22 | (0x02UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< SPI2 clock.
#define APBPeriph_IR_CLOCK                  ((uint32_t)( 20 | (0x02UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< IR clock.
#define APBPeriph_SPI1_CLOCK                ((uint32_t)( 18 | (0x02UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< SPI1 clock.
#define APBPeriph_SPI0_CLOCK                ((uint32_t)( 16 | (0x02UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< SPI0 clock.
#define APBPeriph_TIMER1_CLOCK              ((uint32_t)( 14 | (0x02UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< TIMER1 clock.
#define APBPeriph_GMAC_CLOCK                ((uint32_t)( 13 | (0x02UL << 29) | APBPeriph_SLEEP_CLOCK_NOT_EXIST)) //!< GMAC clock.
#define APBPeriph_CKE_SM3_CLOCK             ((uint32_t)( 12 | (0x02UL << 29) | APBPeriph_SLEEP_CLOCK_NOT_EXIST)) //!< CKE SM3 clock.
#define APBPeriph_CKE_SHA256_CLOCK          ((uint32_t)( 11 | (0x02UL << 29) | APBPeriph_SLEEP_CLOCK_NOT_EXIST)) //!< CKE SHA256 clock.
#define APBPeriph_CKE_AAC_XTAL_CLOCK        ((uint32_t)( 10 | (0x02UL << 29) | APBPeriph_SLEEP_CLOCK_NOT_EXIST)) //!< CKE AAC XTAL clock.
#define APBPeriph_CKE_PDCK_CLOCK            ((uint32_t)(  9 | (0x02UL << 29) | APBPeriph_SLEEP_CLOCK_NOT_EXIST)) //!< CKE PDCK clock.
#define APBPeriph_RNG_CLOCK                 ((uint32_t)(  8 | (0x02UL << 29) | APBPeriph_SLEEP_CLOCK_NOT_EXIST)) //!< RNG clock.
#define APBPeriph_SWR_SS_CLOCK              ((uint32_t)(  6 | (0x02UL << 29) | APBPeriph_SLEEP_CLOCK_NOT_EXIST)) //!< SWR SS clock.
#define APBPeriph_CAL_32K_CLOCK             ((uint32_t)(  5 | (0x02UL << 29) | APBPeriph_SLEEP_CLOCK_NOT_EXIST)) //!< CAL 32K clock.
#define APBPeriph_CKE_MODEM_CLOCK           ((uint32_t)(  4 | (0x02UL << 29) | APBPeriph_SLEEP_CLOCK_NOT_EXIST)) //!< CKE MODEM clock.
#define APBPeriph_SPI0_SLAVE_CLOCK          ((uint32_t)(  2 | (0x02UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< SPI0 SLAVE clock.
#define APBPeriph_2P4G_CLOCK                ((uint32_t)(  0 | (0x02UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< 2P4G clock.

/* 0x238 */
#define APBPeriph_EFUSE_CLOCK             ((uint32_t)( 31 | (0x03UL << 29) | APBPeriph_SLEEP_CLOCK_NOT_EXIST)) //!< EFUSE clock.
#define APBPeriph_CKE_DSP_WDT_CLOCK       ((uint32_t)( 30 | (0x03UL << 29) | APBPeriph_SLEEP_CLOCK_NOT_EXIST)) //!< CKE DSP WDT clock.
#define APBPeriph_CKE_DSP_CLOCK           ((uint32_t)( 28 | (0x03UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< CKE DSP clock.
#define APBPeriph_CKE_H2D_D2H             ((uint32_t)( 26 | (0x03UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< CKE H2D D2H clock.
#define APBPeriph_ADC_CLOCK               ((uint32_t)( 24 | (0x03UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< ADC clock.
#define APBPeriph_DSP_MEM_CLOCK           ((uint32_t)( 22 | (0x03UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< DSP MEM clock.
#define APBPeriph_ASRC_CLOCK              ((uint32_t)( 20 | (0x03UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< ASRC clock.
#define APBPeriph_DISP_CLOCK              ((uint32_t)( 18 | (0x03UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< DISP clock.
#define APBPeriph_DATA_MEM1_CLOCK         ((uint32_t)( 16 | (0x03UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< DATA MEM1 clock.
#define APBPeriph_DATA_MEM0_CLOCK         ((uint32_t)( 14 | (0x03UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< DATA MEM0 clock.
#define APBPeriph_I2C2_CLOCK              ((uint32_t)( 12 | (0x03UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< I2C2 clock.
#define APBPeriph_SIMC_CLOCK              ((uint32_t)( 10 | (0x03UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< SIMC clock.
#define APBPeriph_ISO7816_CLOCK           APBPeriph_SIMC_CLOCK //!< ISO7816 clock.
#define APBPeriph_AES_CLOCK               ((uint32_t)(  8 | (0x03UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< AES clock.
#define APBPeriph_KEYSCAN_CLOCK           ((uint32_t)(  6 | (0x03UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< KEYSCAN clock.
#define APBPeriph_QDEC_CLOCK              ((uint32_t)(  4 | (0x03UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< QDEC clock.
#define APBPeriph_I2C1_CLOCK              ((uint32_t)(  2 | (0x03UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< I2C1 clock.
#define APBPeriph_I2C0_CLOCK              ((uint32_t)(  0 | (0x03UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< I2C0 clock.

/* 0x23C */
#define APBPeriph_CAN1_CLOCK              ((uint32_t)( 30 | (0x04UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< CAN1 clock.
#define APBPeriph_UART5_CLOCK             ((uint32_t)( 28 | (0x04UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< UART5 clock.
#define APBPeriph_UART4_CLOCK             ((uint32_t)( 26 | (0x04UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< UART4 clock.
#define APBPeriph_UART3_CLOCK             ((uint32_t)( 24 | (0x04UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< UART3 clock.
#define APBPeriph_UART2_CLOCK             ((uint32_t)( 22 | (0x04UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< UART2 clock.
#define APBPeriph_UART1_CLOCK             ((uint32_t)( 20 | (0x04UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< UART1 clock.
#define APBPeriph_UART0_CLOCK             ((uint32_t)( 18 | (0x04UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< UART0 clock.
#define APBPeriph_JPEG_CLOCK              ((uint32_t)( 16 | (0x04UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< JPEG clock.
#define APBPeriph_ZIGBEE_CLOCK            ((uint32_t)( 14 | (0x04UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< ZIGBEE clock.
#define APBPeriph_CAN2_CLOCK              ((uint32_t)( 12 | (0x04UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< CAN2 clock.

/* 0x244 */
#define APBPeriph_BTBUS_CLOCK             ((uint32_t)( 0 | (0x06UL << 29) | APBPeriph_SLEEP_CLOCK_EXIST)) //!< BTBUS clock.

#define IS_APB_PERIPH_CLOCK(CLOCK)  (((CLOCK) == APBPeriph_I2S2_CLOCK) || ((CLOCK) == APBPeriph_I2S1_CLOCK)\
                                     || ((CLOCK) == APBPeriph_I2S0_CLOCK)|| ((CLOCK) == APBPeriph_CODEC_CLOCK) \
                                     || ((CLOCK) == APBPeriph_SD_HOST_CLOCK)|| ((CLOCK) == APBPeriph_GPIOA_CLOCK)\
                                     || ((CLOCK) == APBPeriph_GPIOB_CLOCK) || ((CLOCK) == APBPeriph_FLASH2_CLOCK)\
                                     || ((CLOCK) == APBPeriph_FLASH1_CLOCK) || ((CLOCK) == APBPeriph_GDMA_CLOCK)\
                                     || ((CLOCK) == APBPeriph_TIMER_CLOCK) || ((CLOCK) == APBPeriph_FLASH_CLOCK)\
                                     || ((CLOCK) == APBPeriph_VENDOR_REG_CLOCK) || ((CLOCK) == APBPeriph_CKE_BTV_CLOCK)\
                                     || ((CLOCK) == APBPeriph_BUS_RAM_SLP_CLOCK) || ((CLOCK) == APBPeriph_CKE_CTRLAP_CLOCK)\
                                     || ((CLOCK) == APBPeriph_CKE_PLFM_CLOCK)|| ((CLOCK) == APBPeriph_GPIO1_DEB_CLOCK)\
                                     || ((CLOCK) == APBPeriph_GPIO0_DEB_CLOCK) || ((CLOCK) == APBPeriph_IDU_CLOCK)\
                                     || ((CLOCK) == APBPeriph_PKE_CLOCK)|| ((CLOCK) == APBPeriph_PPE_CLOCK)\
                                     || ((CLOCK) == APBPeriph_CAN0_CLOCK)||(CLOCK) == (APBPeriph_SPI2_CLOCK)\
                                     || ((CLOCK) ==APBPeriph_IR_CLOCK ) || (CLOCK) == (APBPeriph_SPI1_CLOCK)\
                                     || ((CLOCK) == APBPeriph_SPI0_CLOCK)||((CLOCK) == APBPeriph_TIMER1_CLOCK)\
                                     || ((CLOCK) == APBPeriph_CKE_SM3_CLOCK)|| ((CLOCK) == APBPeriph_CKE_SHA256_CLOCK)\
                                     || ((CLOCK) == APBPeriph_CKE_AAC_XTAL_CLOCK) || ((CLOCK) == APBPeriph_CKE_PDCK_CLOCK)\
                                     || ((CLOCK) == APBPeriph_RNG_CLOCK)||((CLOCK) == APBPeriph_SWR_SS_CLOCK)\
                                     || ((CLOCK) == APBPeriph_CAL_32K_CLOCK) || ((CLOCK) == APBPeriph_CKE_MODEM_CLOCK)\
                                     || ((CLOCK) == APBPeriph_SPI0_SLAVE_CLOCK) || ((CLOCK) == APBPeriph_EFUSE_CLOCK)\
                                     || ((CLOCK) == APBPeriph_DSP_MEM_CLOCK) || ((CLOCK) == APBPeriph_ASRC_CLOCK)\
                                     || ((CLOCK) == APBPeriph_DISP_CLOCK) || ((CLOCK) == APBPeriph_DATA_MEM1_CLOCK)\
                                     || ((CLOCK) == APBPeriph_DATA_MEM0_CLOCK) || ((CLOCK) == APBPeriph_CAN2_CLOCK)\
                                     || ((CLOCK) == APBPeriph_I2C2_CLOCK) || ((CLOCK) == APBPeriph_SIMC_CLOCK)\
                                     || ((CLOCK) == APBPeriph_AES_CLOCK)||((CLOCK) == APBPeriph_KEYSCAN_CLOCK)\
                                     || ((CLOCK) == APBPeriph_QDEC_CLOCK)||((CLOCK) == APBPeriph_I2C1_CLOCK )\
                                     || ((CLOCK) == APBPeriph_I2C0_CLOCK) || ((CLOCK) == APBPeriph_CAN1_CLOCK )\
                                     || ((CLOCK) == APBPeriph_UART5_CLOCK) || ((CLOCK) == APBPeriph_UART4_CLOCK )\
                                     || ((CLOCK) == APBPeriph_UART3_CLOCK) || ((CLOCK) == APBPeriph_UART2_CLOCK )\
                                     || ((CLOCK) == APBPeriph_UART1_CLOCK )|| ((CLOCK) == APBPeriph_UART0_CLOCK )\
                                     || ((CLOCK) == APBPeriph_JPEG_CLOCK )|| ((CLOCK) == APBPeriph_ZIGBEE_CLOCK )\
                                     || ((CLOCK) == APBPeriph_BTBUS_CLOCK) || ((CLOCK) == APBPeriph_GMAC_CLOCK)\
                                     || ((CLOCK) == APBPeriph_SD_HOST1_CLOCK) || ((CLOCK) == APBPeriph_FLASH3_CLOCK)\
                                     || ((CLOCK) == APBPeriph_AHBC_CLOCK) || ((CLOCK) == APBPeriph_2P4G_CLOCK)\
                                    ) //!< Check if the input parameter is valid.

/** End of group 87x3g_RCC_Peripheral_Clock
  * @}
  */

/** @defgroup 87x3g_APB_Peripheral_Define APB Peripheral Define
  * @{
  */
/* 0x210 */
#define APBPeriph_TIMER1_DEB            ((uint32_t)( 31 | (0x00UL << 26))) //!< TIMER1 DEB peripheral.
#define APBPeriph_ZIGBEE                ((uint32_t)( 30 | (0x00UL << 26))) //!< ZIGBEE peripheral.
#define APBPeriph_GMAC                  ((uint32_t)( 29 | (0x00UL << 26))) //!< GMAC peripheral.
#define APBPeriph_JPEG                  ((uint32_t)( 28 | (0x00UL << 26))) //!< JPEG peripheral.
#define APBPeriph_CAN1                  ((uint32_t)( 27 | (0x00UL << 26))) //!< CAN1 peripheral.
#define APBPeriph_IDU                   ((uint32_t)( 26 | (0x00UL << 26))) //!< IDU peripheral.
#define APBPeriph_PKE                   ((uint32_t)( 25 | (0x00UL << 26))) //!< PKE peripheral.
#define APBPeriph_PPE                   ((uint32_t)( 24 | (0x00UL << 26))) //!< PPE peripheral.
#define APBPeriph_CAN0                  ((uint32_t)( 23 | (0x00UL << 26))) //!< CAN0 peripheral.
#define APBPeriph_TIMER1                ((uint32_t)( 22 | (0x00UL << 26))) //!< TIMER1 peripheral.
#define APBPeriph_AAC_XTAL              ((uint32_t)( 20 | (0x00UL << 26))) //!< AAC XTAL peripheral.
#define APBPeriph_PDCK                  ((uint32_t)( 19 | (0x00UL << 26))) //!< PDCK peripheral.
#define APBPeriph_SWR_SS                ((uint32_t)( 18 | (0x00UL << 26))) //!< SWR SS peripheral.
#define APBPeriph_CAN2                  ((uint32_t)( 17 | (0x00UL << 26))) //!< CAN2 peripheral.
#define APBPeriph_TIMER                 ((uint32_t)( 16 | (0x00UL << 26))) //!< TIMER peripheral.
#define APBPeriph_TIMERA                APBPeriph_TIMER //!< TIMERA peripheral.
#define APBPeriph_USB                   ((uint32_t)( 15 | (0x00UL << 26))) //!< USB peripheral.
#define APBPeriph_SD_HOST               ((uint32_t)( 14 | (0x00UL << 26))) //!< SD host peripheral.
#define APBPeriph_GDMA                  ((uint32_t)( 13 | (0x00UL << 26))) //!< GDMA peripheral.
#define APBPeriph_UART5                 ((uint32_t)( 12 | (0x00UL << 26))) //!< UART5 peripheral.
#define APBPeriph_UART4                 ((uint32_t)( 11 | (0x00UL << 26))) //!< UART4 peripheral.
#define APBPeriph_UART3                 ((uint32_t)( 10 | (0x00UL << 26))) //!< UART3 peripheral.
#define APBPeriph_UART2                 ((uint32_t)( 9  | (0x00UL << 26))) //!< UART2 peripheral.
#define APBPeriph_UART1                 ((uint32_t)( 8  | (0x00UL << 26))) //!< UART1 peripheral.
#define APBPeriph_UART0                 ((uint32_t)( 7  | (0x00UL << 26))) //!< UART0 peripheral.
#define APBPeriph_FLASH2                ((uint32_t)( 6  | (0x00UL << 26))) //!< FLASH2 peripheral.
#define APBPeriph_FLASH1                ((uint32_t)( 5  | (0x00UL << 26))) //!< FLASH1 peripheral.
#define APBPeriph_FLASH                 ((uint32_t)( 4  | (0x00UL << 26))) //!< FLASH peripheral.
#define APBPeriph_FLASH3                ((uint32_t)( 3  | (0x00UL << 26))) //!< FLASH3 peripheral.
#define APBPeriph_BTBUS                 ((uint32_t)( 2  | (0x00UL << 26))) //!< BTBUS peripheral.
#define APBPeriph_SD_HOST1              ((uint32_t)( 1  | (0x00UL << 26))) //!< SD HOST1 peripheral.
#define APBPeriph_2P4G                  ((uint32_t)( 0  | (0x00UL << 26))) //!< 2P4G peripheral.

/* 0x218 */
#define APBPeriph_DATA_MEM              ((uint32_t)( 31 | (0x02UL << 26))) //!< DATA MEM peripheral.
#define APBPeriph_EFUSE                 ((uint32_t)( 30 | (0x02UL << 26))) //!< EFUSE peripheral.
#define APBPeriph_DSP_WDT               ((uint32_t)( 29 | (0x02UL << 26))) //!< DSP WDT peripheral.
#define APBPeriph_ASRC                  ((uint32_t)( 28 | (0x02UL << 26))) //!< ASRC peripheral.
#define APBPeriph_DSP_MEM               ((uint32_t)( 27 | (0x02UL << 26))) //!< DSP MEM peripheral.
#define APBPeriph_DSP_H2D_D2H           ((uint32_t)( 26 | (0x02UL << 26))) //!< DSP H2D D2H peripheral.
#define APBPeriph_DSP_CORE              ((uint32_t)( 25 | (0x02UL << 26))) //!< DSP CORE peripheral.
#define APBPeriph_SPI0_SLAVE            ((uint32_t)( 24 | (0x02UL << 26))) //!< SPI0 SLAVE peripheral.
#define APBPeriph_PSRAM3                ((uint32_t)( 23 | (0x02UL << 26))) //!< PSRAM3 peripheral.
#define APBPeriph_PSRAM                 ((uint32_t)( 22 | (0x02UL << 26))) //!< PSRAM peripheral.
#define APBPeriph_I2C2                  ((uint32_t)( 20 | (0x02UL << 26))) //!< I2C2 peripheral.
#define APBPeriph_KEYSCAN               ((uint32_t)( 19 | (0x02UL << 26))) //!< KEYSCAN peripheral.
#define APBPeriph_QDEC                  ((uint32_t)( 18 | (0x02UL << 26))) //!< QDEC peripheral.
#define APBPeriph_I2C1                  ((uint32_t)( 17 | (0x02UL << 26))) //!< I2C1 peripheral.
#define APBPeriph_I2C0                  ((uint32_t)( 16 | (0x02UL << 26))) //!< I2C0 peripheral.
#define APBPeriph_SPI2                  ((uint32_t)( 11 | (0x02UL << 26))) //!< SPI2 peripheral.
#define APBPeriph_IR                    ((uint32_t)( 10 | (0x02UL << 26))) //!< IR peripheral.
#define APBPeriph_SPI1                  ((uint32_t)( 9  | (0x02UL << 26))) //!< SPI1 peripheral.
#define APBPeriph_SPI0                  ((uint32_t)( 8  | (0x02UL << 26))) //!< SPI0 peripheral.
#define APBPeriph_SM3                   ((uint32_t)( 7  | (0x02UL << 26))) //!< SM3 peripheral.
#define APBPeriph_SHA256                ((uint32_t)( 6  | (0x02UL << 26))) //!< SHA256 peripheral.
#define APBPeriph_DISP                  ((uint32_t)( 5  | (0x02UL << 26))) //!< DISP peripheral.
#define APBPeriph_SIMC                  ((uint32_t)( 4  | (0x02UL << 26))) //!< SIMC peripheral.
#define APBPeriph_ISO7816               APBPeriph_SIMC //!< ISO7816 peripheral.
#define APBPeriph_RNG                   ((uint32_t)( 3  | (0x02UL << 26))) //!< RNG peripheral.
#define APBPeriph_AES                   ((uint32_t)( 2  | (0x02UL << 26))) //!< AES peripheral.

/* 0x21C */
#define APBPeriph_TIMER1_9_PWM          ((uint32_t)( 13  | (0x03UL << 26))) //!< TIMER1_9_PWM peripheral.
#define APBPeriph_TIMER1_8_PWM          ((uint32_t)( 12  | (0x03UL << 26))) //!< TIMER1_8_PWM peripheral.
#define APBPeriph_TIMER1_7_PWM          ((uint32_t)( 11  | (0x03UL << 26))) //!< TIMER1_7_PWM peripheral.
#define APBPeriph_TIMER1_6_PWM          ((uint32_t)( 10  | (0x03UL << 26))) //!< TIMER1_6_PWM peripheral.
#define APBPeriph_GPIOB                 ((uint32_t)( 9  | (0x03UL << 26))) //!< GPIOB peripheral.
#define APBPeriph_GPIOA                 ((uint32_t)( 8  | (0x03UL << 26))) //!< GPIOA peripheral.
#define APBPeriph_GPIO                  APBPeriph_GPIOA //!< GPIO peripheral.
#define APBPeriph_ADC                   ((uint32_t)(0  | (0x03UL << 26))) //!< ADC peripheral.

/* 0x220 */
#define APBPeriph_I2S2                  ((uint32_t)((1 << 10) | (0x04UL << 26))) //!< I2S2 peripheral.
#define APBPeriph_I2S1                  ((uint32_t)((1 << 2)  | (0x04UL << 26))) //!< I2S1 peripheral.
#define APBPeriph_I2S0                  ((uint32_t)((1 << 1)  | (0x04UL << 26))) //!< I2S0 peripheral.
#define APBPeriph_CODEC                 ((uint32_t)((1 << 0)  | (0x04UL << 26))) //!< CODEC peripheral.

/* No periph function bit */
#define APBPeriph_NO_FUNCTION_BIT       (0xff) //!< No function bit.
#define APBPeriph_CKE_MODEM             (APBPeriph_NO_FUNCTION_BIT) //!< CKE MODEM peripheral.
#define APBPeriph_VENDOR_REG            (APBPeriph_NO_FUNCTION_BIT) //!< VENDOR REG peripheral.
#define APBPeriph_CKE_BTV               (APBPeriph_NO_FUNCTION_BIT) //!< CKE BTV peripheral.
#define APBPeriph_BUS_RAM_SLP           (APBPeriph_NO_FUNCTION_BIT) //!< BUS RAM SLP peripheral.
#define APBPeriph_CKE_CTRLAP            (APBPeriph_NO_FUNCTION_BIT) //!< CKE CTRLAP peripheral.
#define APBPeriph_CKE_PLFM              (APBPeriph_NO_FUNCTION_BIT) //!< CKE PLFM peripheral.
#define APBPeriph_GPIO1_DEB             (APBPeriph_NO_FUNCTION_BIT) //!< GPIO1 DEB peripheral.
#define APBPeriph_GPIO0_DEB             (APBPeriph_NO_FUNCTION_BIT) //!< GPIO0 DEB peripheral.
#define APBPeriph_AHBC                  (APBPeriph_NO_FUNCTION_BIT) //!< AHBC peripheral.

#define IS_APB_PERIPH(PERIPH) (((PERIPH) == APBPeriph_TIMER1_DEB) || ((PERIPH) == APBPeriph_ZIGBEE)\
                               || ((PERIPH) == APBPeriph_GMAC)\
                               || ((PERIPH) == APBPeriph_JPEG) || ((PERIPH) == APBPeriph_CAN1)\
                               || ((PERIPH) == APBPeriph_IDU) || ((PERIPH) == APBPeriph_PKE)\
                               || ((PERIPH) == APBPeriph_PPE) || ((PERIPH) == APBPeriph_CAN0)\
                               || ((PERIPH) == APBPeriph_TIMER1)\
                               || ((PERIPH) == APBPeriph_AAC_XTAL)|| ((PERIPH) == APBPeriph_PDCK)\
                               || ((PERIPH) == APBPeriph_SWR_SS) || ((PERIPH) == APBPeriph_TIMER)\
                               || ((PERIPH) == APBPeriph_USB) || ((PERIPH) == APBPeriph_SD_HOST)\
                               || ((PERIPH) == APBPeriph_GDMA) || ((PERIPH) == APBPeriph_UART5)\
                               || ((PERIPH) == APBPeriph_UART4) || ((PERIPH) == APBPeriph_UART3)\
                               || ((PERIPH) == APBPeriph_UART2) || ((PERIPH) == APBPeriph_UART1)\
                               || ((PERIPH) == APBPeriph_UART0) || ((PERIPH) == APBPeriph_FLASH2)\
                               || ((PERIPH) == APBPeriph_FLASH1) || ((PERIPH) == APBPeriph_FLASH)\
                               || ((PERIPH) == APBPeriph_BTBUS)|| ((PERIPH) == APBPeriph_DATA_MEM)\
                               || ((PERIPH) == APBPeriph_EFUSE) || ((PERIPH) == APBPeriph_DSP_WDT)\
                               || ((PERIPH) == APBPeriph_ASRC) || ((PERIPH) == APBPeriph_DSP_MEM)\
                               || ((PERIPH) == APBPeriph_DSP_H2D_D2H)\
                               || ((PERIPH) == APBPeriph_DSP_CORE) || ((PERIPH) == APBPeriph_SPI0_SLAVE)\
                               |  ((PERIPH) == APBPeriph_PSRAM) || ((PERIPH) == APBPeriph_I2C2)\
                               || ((PERIPH) == APBPeriph_KEYSCAN) || ((PERIPH) == APBPeriph_QDEC)\
                               || ((PERIPH) == APBPeriph_I2C1)|| ((PERIPH) == APBPeriph_I2C0)\
                               || ((PERIPH) == APBPeriph_SPI2) || ((PERIPH) == APBPeriph_IR)\
                               || (PERIPH == APBPeriph_SPI1) || (PERIPH == APBPeriph_SPI0)\
                               || (PERIPH == APBPeriph_SM3) || (PERIPH == APBPeriph_SHA256)\
                               || (PERIPH == APBPeriph_DISP) || (PERIPH == APBPeriph_SIMC)\
                               || (PERIPH == APBPeriph_RNG)|| (PERIPH == APBPeriph_AES) \
                               || (PERIPH == APBPeriph_GPIOB)|| (PERIPH == APBPeriph_GPIOA) \
                               || (PERIPH == APBPeriph_ADC)|| (PERIPH == APBPeriph_I2S2) \
                               || (PERIPH == APBPeriph_I2S1)|| (PERIPH == APBPeriph_I2S0) \
                               || (PERIPH == APBPeriph_CODEC)|| (PERIPH == APBPeriph_CKE_MODEM) \
                               || (PERIPH == APBPeriph_VENDOR_REG)|| (PERIPH == APBPeriph_CKE_BTV) \
                               || (PERIPH == APBPeriph_BUS_RAM_SLP)|| (PERIPH == APBPeriph_CKE_CTRLAP) \
                               || (PERIPH == APBPeriph_CKE_PLFM)|| (PERIPH == APBPeriph_GPIO1_DEB) \
                               || (PERIPH == APBPeriph_GPIO0_DEB) || (PERIPH == APBPeriph_CAN2) \
                               || (PERIPH == APBPeriph_FLASH3) || (PERIPH == APBPeriph_SD_HOST1)\
                               || (PERIPH == APBPeriph_2P4G) || (PERIPH == APBPeriph_PSRAM3)\
                               || (PERIPH == APBPeriph_TIMER1_6_PWM) || (PERIPH == APBPeriph_TIMER1_7_PWM)\
                               || (PERIPH == APBPeriph_TIMER1_8_PWM) || (PERIPH == APBPeriph_TIMER1_9_PWM)\
                               || (PERIPH == APBPeriph_AHBC)) //!< Check if the input parameter is valid.

/** End of group 87x3g_APB_Peripheral_Define
  * @}
  */

/** @defgroup 87x3g_Display_Clock_Source Display Clock Source
  * @{
  */

#define DISPLAY_CLOCK_SOURCE_PLL1                               ((uint16_t) 0x0) //!< Select PLL1 as the clock source for display.
#define DISPLAY_CLOCK_SOURCE_PLL2                               ((uint16_t) 0x1) //!< Select PLL2 as the clock source for display.
#define DISPLAY_CLOCK_SOURCE_PLL3                               ((uint16_t) 0x3) //!< Select PLL3 as the clock source for display.
#define DISPLAY_CLOCK_SOURCE_40MHZ                              ((uint16_t) 0x4) //!< Select 40MHz as the clock source for display.
#define IS_DISPLAY_CLOCK_SOURCE(CLOCK)                          (((CLOCK) == DISPLAY_CLOCK_SOURCE_PLL1) || \
                                                                 ((CLOCK) == DISPLAY_CLOCK_SOURCE_PLL2) || \
                                                                 ((CLOCK) == DISPLAY_CLOCK_SOURCE_PLL3) || \
                                                                 ((CLOCK) == DISPLAY_CLOCK_SOURCE_40MHZ)) //!< Check if the input parameter is valid.

/** End of group 87x3g_Display_Clock_Source
  * @}
  */

/** @defgroup 87x3g_Display_Clock_Divider Display Clock Divider
  * @{
  */

#define DISPLAY_CLOCK_DIV_1                     ((uint16_t)0x0) //!< Display clock divider is set to 1.
#define DISPLAY_CLOCK_DIV_2                     ((uint16_t)0x1) //!< Display clock divider is set to 2.
#define DISPLAY_CLOCK_DIV_4                     ((uint16_t)0x2) //!< Display clock divider is set to 4.
#define DISPLAY_CLOCK_DIV_8                     ((uint16_t)0x3) //!< Display clock divider is set to 8.
#define DISPLAY_CLOCK_DIV_16                    ((uint16_t)0x4) //!< Display clock divider is set to 16.
#define DISPLAY_CLOCK_DIV_32                    ((uint16_t)0x5) //!< Display clock divider is set to 32.
#define DISPLAY_CLOCK_DIV_40                    ((uint16_t)0x6) //!< Display clock divider is set to 40.
#define DISPLAY_CLOCK_DIV_64                    ((uint16_t)0x7) //!< Display clock divider is set to 64.
#define IS_DISPLAY_DIV(DIV)                     (((DIV) == DISPLAY_CLOCK_DIV_1) || \
                                                 ((DIV) == DISPLAY_CLOCK_DIV_2) || \
                                                 ((DIV) == DISPLAY_CLOCK_DIV_4) || \
                                                 ((DIV) == DISPLAY_CLOCK_DIV_8) || \
                                                 ((DIV) == DISPLAY_CLOCK_DIV_16) || \
                                                 ((DIV) == DISPLAY_CLOCK_DIV_32) || \
                                                 ((DIV) == DISPLAY_CLOCK_DIV_40) || \
                                                 ((DIV) == DISPLAY_CLOCK_DIV_64)) //!< Check if the input parameter is valid.

/** End of group 87x3g_Display_Clock_Divider
  * @}
  */

/** End of group 87x3g_RCC_Exported_Constants
  * @}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/

/** @defgroup 87x3g_RCC_Exported_Functions RCC Exported Functions
  * @{
  */

/**
 *
 * \brief  Enable or disable the APB peripheral clock.
 *
 * \param[in] APBPeriph: Specifies the APB peripheral to gates its clock. This parameter can refer to \ref x3g_APB_Peripheral_Define.
 *            This parameter can be one of the following values:
 *            - APBPeriph_TIMERx: The APB peripheral of TIMER, where x can be A or 1.
 *            - APBPeriph_GDMA: The APB peripheral of GDMA.
 *            - APBPeriph_KEYSCAN: The APB peripheral of KEYSCAN.
 *            - APBPeriph_QDEC: The APB peripheral of QDEC.
 *            - APBPeriph_I2Cx: The APB peripheral of I2C, where x can be 0 to 2.
 *            - APBPeriph_IR: The APB peripheral of IR.
 *            - APBPeriph_SPIx: The APB peripheral of SPI, where x can be 0 to 2.
 *            - APBPeriph_GPIOx: The APB peripheral of GPIO, where x can be A or B.
 *            - APBPeriph_UARTx: The APB peripheral of UART, where x can be 0 to 5.
 *            - APBPeriph_ADC: The APB peripheral of ADC.
 *            - APBPeriph_CODEC: The APB peripheral of CODEC.
 * \param[in] APBPeriph_Clock: Specifies the APB peripheral clock config. This parameter can refer to \ref x3g_RCC_Peripheral_Clock.
 *            This parameter can be one of the following values(must be the same with APBPeriph):
 *            - APBPeriph_TIMERx_CLOCK: The APB peripheral clock of TIMER, where x can be A or 1.
 *            - APBPeriph_GDMA_CLOCK: The APB peripheral clock of GDMA.
 *            - APBPeriph_KEYSCAN_CLOCK: The APB peripheral clock of KEYSCAN.
 *            - APBPeriph_QDEC_CLOCK: The APB peripheral clock of QDEC.
 *            - APBPeriph_I2Cx_CLOCK: The APB peripheral clock of I2C, where x can be 0 to 2.
 *            - APBPeriph_IR_CLOCK: The APB peripheral clock of IR.
 *            - APBPeriph_SPIx_CLOCK: The APB peripheral clock of SPI, where x can be 0 to 2.
 *            - APBPeriph_GPIOx_CLOCK: The APB peripheral clock of GPIO, where x can be A or B.
 *            - APBPeriph_UARTx_CLOCK: The APB peripheral clock of UART, where x can be 0 to 5.
 *            - APBPeriph_ADC_CLOCK: The APB peripheral clock of ADC.
 *            - APBPeriph_CODEC_CLOCK: The APB peripheral clock of CODEC.
 * \param[in] NewState: New state of the specified peripheral clock.
 *            This parameter can be one of the following values:
 *            - ENABLE: Enable the specified peripheral clock.
 *            - DISABLE: Disable the specified peripheral clock.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_spi_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_SPI0, APBPeriph_SPI0_CLOCK, ENABLE);
 * }
 * \endcode
 */
void RCC_PeriphClockCmd(uint32_t APBPeriph, uint32_t APBPeriph_Clock, FunctionalState NewState);

/**
 *
 * \brief  Enable or disable the specified APB peripheral clock.
 *
 * \param[in] APBPeriph_Clock: Specifies the APB peripheral clock config. This parameter can refer to \ref x3g_RCC_Peripheral_Clock.
 *            This parameter can be one of the following values(must be the same with APBPeriph):
 *            - APBPeriph_TIMERx_CLOCK: The APB peripheral clock of TIMER, where x can be A or 1.
 *            - APBPeriph_GDMA_CLOCK: The APB peripheral clock of GDMA.
 *            - APBPeriph_KEYSCAN_CLOCK: The APB peripheral clock of KEYSCAN.
 *            - APBPeriph_QDEC_CLOCK: The APB peripheral clock of QDEC.
 *            - APBPeriph_I2Cx_CLOCK: The APB peripheral clock of I2C, where x can be 0 to 2.
 *            - APBPeriph_IR_CLOCK: The APB peripheral clock of IR.
 *            - APBPeriph_SPIx_CLOCK: The APB peripheral clock of SPI, where x can be 0 to 2.
 *            - APBPeriph_GPIOx_CLOCK: The APB peripheral clock of GPIO, where x can be A or B.
 *            - APBPeriph_UARTx_CLOCK: The APB peripheral clock of UART, where x can be 0 to 5.
 *            - APBPeriph_ADC_CLOCK: The APB peripheral clock of ADC.
 *            - APBPeriph_CODEC_CLOCK: The APB peripheral clock of CODEC.
 * \param[in] NewState: New state of the specified APB peripheral clock.
 *            This parameter can be one of the following values:
 *            - ENABLE: Enable the specified APB peripheral clock.
 *            - DISABLE: Disable the specified APB peripheral clock.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_spi_init(void)
 * {
 *     RCC_PeriClockConfig(APBPeriph_SPI0_CLOCK, ENABLE);
 * }
 * \endcode
 */
void RCC_PeriClockConfig(uint32_t APBPeriph_Clock, FunctionalState NewState);

/**
 *
 * \brief  Enable or disable the APB peripheral function.
 *
 * \param[in] APBPeriph: Specifies the APB peripheral to gates its clock. This parameter can refer to \ref x3g_APB_Peripheral_Define.
 *            This parameter can be one of the following values:
 *            - APBPeriph_TIMERx: The APB peripheral of TIMER, where x can be A or 1.
 *            - APBPeriph_GDMA: The APB peripheral of GDMA.
 *            - APBPeriph_KEYSCAN: The APB peripheral of KEYSCAN.
 *            - APBPeriph_QDEC: The APB peripheral of QDEC.
 *            - APBPeriph_I2Cx: The APB peripheral of I2C, where x can be 0 to 2.
 *            - APBPeriph_IR: The APB peripheral of IR.
 *            - APBPeriph_SPIx: The APB peripheral of SPI, where x can be 0 to 2.
 *            - APBPeriph_GPIOx: The APB peripheral of GPIO, where x can be A or B.
 *            - APBPeriph_UARTx: The APB peripheral of UART, where x can be 0 to 5.
 *            - APBPeriph_ADC: The APB peripheral of ADC.
 *            - APBPeriph_CODEC: The APB peripheral of CODEC
 * \param[in] NewState: New state of the specified peripheral.
 *            This parameter can be one of the following values:
 *            - ENABLE: Enable the specified peripheral function.
 *            - DISABLE: Disable the specified peripheral function.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_spi_init(void)
 * {
 *     RCC_PeriFunctionConfig(APBPeriph_SPI0, ENABLE);
 * }
 * \endcode
 */
void RCC_PeriFunctionConfig(uint32_t APBPeriph, FunctionalState NewState);

/**
 *
 * \brief     Select the display clock source and divider.
 *
 * \param[in] ClockSource: Display clock source \ref x3g_Display_Clock_Source.
 *            This parameter can be one of the following values:
 *            - DISPLAY_CLOCK_SOURCE_PLL1: Select PLL1 as the clock source for display.
 *            - DISPLAY_CLOCK_SOURCE_PLL2: Select PLL2 as the clock source for display.
 *            - DISPLAY_CLOCK_SOURCE_PLL3: Select PLL3 as the clock source for display.
 *            - DISPLAY_CLOCK_SOURCE_40MHZ: Select 40MHz as the clock source for display.
 * \param[in] ClockDiv: Display clock divider \ref x3g_Display_Clock_Divider.
 *            This parameter can be one of the following values:
 *            - DISPLAY_CLOCK_DIV_x: Where x can be 1, 2, 4, 8, 16, 32, 40, 64 to select the specified clock divider.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_xx_init(void)
 * {
 *     RCC_DisplayClockConfig(DISPLAY_CLOCK_SOURCE_40MHZ, DISPLAY_CLOCK_DIV_1);
 * }
 * \endcode
 */
extern void RCC_DisplayClockConfig(uint16_t ClockSource, uint16_t ClockDiv);
#ifdef __cplusplus
}
#endif

#endif /* _RTL876X_RCC_H_ */

/**End of group 87x3g_RCC_Exported_Functions
  * @}
  */

/**End of group 87x3g_RCC
  * @}
  */

