/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
*********************************************************************************************************
* \file     rtl_rcc.h
* \brief    The header file of the clock control and reset driver.
* \details  This file provides all peripheral clock control firmware functions.
* @author   Echo
* @date     2023-10-17
* @version  v1.0
* *********************************************************************************************************
*/

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef RTL_RCC_H
#define RTL_RCC_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl876x.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2G)
#include "rcc/src/rtl87x2g/rtl_rcc_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3E)
#include "rcc/src/rtl87x3e/rtl_rcc_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3D)
#include "rcc/src/rtl8763d/rtl_rcc_def.h"
#endif
#include "spi/inc/rtl_spi.h"
#include "uart/inc/rtl_uart.h"
#include "i2c/inc/rtl_i2c.h"
#include "tim/inc/rtl_tim.h"
#if RCC_SUPPORT_ENH_TIMER_SOURCE_API
#include "tim/inc/rtl_enh_tim.h"
#endif

/** \defgroup 87X2G_RCC         RCC
  * \brief
  * \{
  */

/*============================================================================*
 *                         Constants
 *============================================================================*/
/** \defgroup RCC_Exported_Constants RCC Exported Constants
  * \brief
  * \{
  */

/**
 * \brief       Clock Divider
 *
 * \ingroup     RCC_Exported_Constants
 */
typedef enum
{
    CLOCK_DIV_1,
    CLOCK_DIV_2,
    CLOCK_DIV_4,
    CLOCK_DIV_8,
    CLOCK_DIV_16,
    CLOCK_DIV_32,
    CLOCK_DIV_40,
    CLOCK_DIV_64,
} RCCClockDiv_Typedef;

#define IS_DIV(DIV)       ((DIV) == CLOCK_DIV_1) || \
    ((DIV) == CLOCK_DIV_2) || \
    ((DIV) == CLOCK_DIV_4) || \
    ((DIV) == CLOCK_DIV_8) || \
    ((DIV) == CLOCK_DIV_16) || \
    ((DIV) == CLOCK_DIV_32) || \
    ((DIV) == CLOCK_DIV_40) || \
    ((DIV) == CLOCK_DIV_64))

/** End of RCC_Exported_Constants
  * \}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/
/** \defgroup RCC_Exported_Functions RCC Exported Functions
  * \brief
  * \{
  */

/**
 * \brief  Enable or disable the APB peripheral clock.
 *
 * \param[in] APBPeriph: Specifies the APB peripheral to gates its clock.
 *            This parameter can refer APB Peripheral.
 * \param[in] APBPeriph_Clock: Specifies the APB peripheral clock config.
 *            This parameter can refer to APB Peripheral Clock (must be the same with APBPeriph).
 * \param[in] NewState: New state of the specified peripheral clock.
 *            This parameter can be one of the following values:
 *            \arg ENABLE: Enable the specified peripheral clock.
 *            \arg DISABLE: Disable the specified peripheral clock.
 *
 * \return  None.
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
 * \brief  Enable or disable the APB peripheral.
 *
 * \param[in] APBPeriph: Specifies the APB peripheral.
 *            This parameter can refer APB Peripheral.
 * #if RCC_SUPPORT_PERIPHCLOCKCONFIG_API_MORE_PARAMS
 * \param[in] APBPeriph_Clock: specifies the APB peripheral clock config.
 *            This parameter can refer to APB Peripheral Clock (must be the same with APBPeriph).
 * #endif
 * \param[in] NewState: New state of the specified peripheral.
 *            This parameter can be one of the following values:
 *            \arg ENABLE: Enable the specified peripheral.
 *            \arg DISABLE: Disable the specified peripheral.
 *
 * \return  None.
 */
#if RCC_SUPPORT_PERIPHCLOCKCONFIG_API_MORE_PARAMS
void RCC_PeriFunctionConfig(uint32_t APBPeriph, uint32_t APBPeriph_Clock, FunctionalState NewState);
#else
void RCC_PeriFunctionConfig(uint32_t APBPeriph, FunctionalState NewState);
#endif

/**
 * \brief  Enable or disable the specified APB peripheral clock.
 *
 * \param[in] APBPeriph: specifies the APB peripheral to gates its clock.
 *            This parameter can refer APB Peripheral.
 * #if RCC_SUPPORT_PERIPHCLOCKCONFIG_API_MORE_PARAMS
 * \param[in] APBPeriph_Clock: Specifies the APB peripheral clock config.
 *            This parameter can refer to APB Peripheral Clock (must be the same with APBPeriph).
 * #endif
 * \param[in] NewState: New state of the specified APB peripheral clock.
 *            This parameter can be one of the following values:
 *            \arg ENABLE: Enable the specified APB peripheral clock.
 *            \arg DISABLE: Disable the specified APB peripheral clock.
 *
 * \return None
 */
#if RCC_SUPPORT_PERIPHCLOCKCONFIG_API_MORE_PARAMS
void RCC_PeriClockConfig(uint32_t APBPeriph, uint32_t APBPeriph_Clock, FunctionalState NewState);
#else
void RCC_PeriClockConfig(uint32_t APBPeriph_Clock, FunctionalState NewState);
#endif

/**
 * \brief  I2C clock divider config.
 *
 * \param[in] I2Cx: Select the I2C peripheral. \ref I2C_Declaration
 * \param[in] ClockDiv: Specifies the I2C clock divider.
 *            This parameter can be one of the following values:
 *            \arg CLOCK_DIV_x: where x can refer to CLock Divider to select the specified clock divider
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_i2c_init(void)
 * {
 *     RCC_I2CClkDivConfig(I2C0, CLOCK_DIV_1);
 * }
 * \endcode
 */
void RCC_I2CClkDivConfig(I2C_TypeDef *I2Cx, uint16_t ClockDiv);

/**
 * \brief     SPI clock divider config.
 *
 * \param[in] SPIx: Select the SPI peripheral. \ref SPI_Declaration
 * \param[in] ClockDiv: Specifies the SPI clock divider.
 *            This parameter can be one of the following values:
 *            \arg CLOCK_DIV_x: where x can refer to CLock Divider to select the specified clock divider
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_spi_init(void)
 * {
 *     RCC_SPIClkDivConfig(SPI0, CLOCK_DIV_1);
 * }
 * \endcode
 */
void RCC_SPIClkDivConfig(SPI_TypeDef *SPIx, uint16_t ClockDiv);

/**
 * \brief  UART clock divider config.
 *
 * \param[in] UARTx: Select the UART peripheral. \ref UART_Declaration
 * \param[in] ClockDiv: Specifies the UART clock divider.
 *            This parameter can be one of the following values:
 *            \arg CLOCK_DIV_x: where x can refer to CLock Divider to select the specified clock divider
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_i2c_init(void)
 * {
 *     RCC_UARTClkDivConfig(UART0, CLOCK_DIV_1);
 * }
 * \endcode
 */
void RCC_UARTClkDivConfig(UART_TypeDef *UARTx, uint16_t ClockDiv);

/**
 * \brief  TIM clock config.
 *
 * \param[in] TIMx: Select the TIM peripheral. \ref TIMER_Declaration
 * \param[in] ClockSrc: specifies the PLL clock source.
 * \param[in] ClockDiv: specifies the APB peripheral to gates its clock.
 *
 * \return None
 */
void RCC_TIMClkConfig(TIM_TypeDef *TIMx, uint16_t ClockSrc, uint16_t ClockDiv);

#if RCC_SUPPORT_ENH_TIMER_SOURCE_API
/**
 * \brief  ENHTIM clock config.
 *
 * \param[in]  ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
 * \param[in]  ClockSrc: specifies the PLL clock source.
 * \param[in]  ClockDiv: specifies the APB peripheral to gates its clock.
 *
 * \return None
 */
void RCC_ENHTIMClkConfig(ENHTIM_TypeDef *ENHTIMx, uint16_t ClockSrc, uint16_t ClockDiv);
#endif

#if RCC_SUPPORT_CLOCKGATECMD_API
/**
 * rtl876x_rcc.h
 *
 * \brief  Enable or disable the specified RCC Clock Source Gating.
 *
 * \param[in] ClockGate: Specifies the clock source to gate.
 *            This parameter can be one of the following values:
 *            \arg CLOCK_GATE_5M: 5M clock source for adc and keyscan.
 *            \arg CLOCK_GATE_10M: 10M clock source for bluewiz.
 *            \arg CLOCK_GATE_20M: 20M clock source for 2wssi and qdec.
 * \param[in] NewState: New state of the specified RCC Clock Source.
 *            This parameter can be one of the following values:
 *            \arg ENABLE: Enable the specified RCC Clock Source.
 *            \arg DISABLE: Disable the specified RCC Clock Source.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_xx_init(void)
 * {
 *     RCC_ClockGateCmd(CLOCK_GATE_5M, ENABLE);
 * }
 * \endcode
 */
extern void RCC_ClockGateCmd(uint32_t ClockGate, FunctionalState NewState);
#endif

#if RCC_SUPPORT_SPICCLKSOURCESWITCH_API
/**
 * rtl876x_rcc.h
 *
 * \brief  SPI clock source switch.
 *
 * \param[in] SPIx: Select the SPI peripheral. \ref SPI_Declaration
 * \param[in] ClockSource: SPI clock source to switch.
 *            This parameter can be one of the following values:
 *            \arg SPI_CLOCK_SOURCE_40M: Select SPI clock source of 40MHz.
 *            \arg SPI_CLOCK_SOURCE_PLL: Select SPI clock source of PLL.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_spi_init(void)
 * {
 *     RCC_SPIClkSourceSwitch(SPI0, SPI_CLOCK_SOURCE_40M);
 * }
 * \endcode
 */
extern void RCC_SPIClkSourceSwitch(SPI_TypeDef *SPIx, uint16_t ClockSource);
#endif

#if RCC_SUPPORT_SPDIFCLKSOURCECONFIG_API
/**
 * rtl876x_rcc.h
 *
 * \brief  SPDIF clock source config.
 *
 * \param[in] ClockSource: Specifies the SPDIF clock sorce.
 *            This parameter can be one of the following values:
 *            \arg SPDIF_CLOCK_SOURCE_40M: Select SPDIF clock source of 40MHz.
 *            \arg SPDIF_CLOCK_SOURCE_PLL: Select SPDIF clock source of PLL.
 *            \arg SPDIF_CLOCK_SOURCE_PLL2: Select SPDIF clock source of PLL2.
 *            \arg SPDIF_CLOCK_SOURCE_PLL3: Select SPDIF clock source of PLL3.
 *            \arg SPDIF_CLOCK_SOURCE_MCLK: Select SPDIF clock source of MCLK.
 * \param[in] first_div: Specifies the SPDIF clock source first div, actual effective division value = first_div + 1.
 * \param[in] sec_div: Specifies the SPDIF clock source second div.
 *            This parameter can be one of the following values:
 *            \arg SPDIF_CLOCK_SEC_DIV_DISABLE: Disable the SPDIF clock source second divider.
 *            \arg SPDIF_CLOCK_SEC_DIV_2: The SPDIF clock source second divider is 2.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_spdif_init(void)
 * {
 *     RCC_SPDIFClkSourceConfig(SPDIF_CLOCK_SOURCE_40M, 1, SPDIF_CLOCK_SEC_DIV_2);
 * }
 * \endcode
 */
extern void RCC_SPDIFClkSourceConfig(uint16_t ClockSource, uint8_t first_div, uint8_t sec_div);
#endif

#if RCC_SUPPORT_TIMSOURCECONFIG_API
/**
 * rtl876x_rcc.h
 *
 * \brief     Select the specified timer clock divider and source.
 *
 * \param[in] clocklevel: Timer clock divider.
 *            This parameter can be one of the following values:
 *            \arg TIM2TO7_CLOCK_DIV_x: TIM2TO7 clock divider, where x can be 1 ~ 4, 6, 8, 16.
 * \param[in] clocksource: Timer clock Source.
 *            This parameter can be one of the following values:
 *            \arg TIM_CLOCK_SOURCE_SYSTEM_CLOCK: Select timer clock source of system clock.
 *            \arg TIM_CLOCK_SOURCE_40MHZ: Select timer clock source of 40MHz.
 *            \arg TIM_CLOCK_SOURCE_PLL: Select timer clock source of PLL.
 * \param[in] NewState: New state of the specified RCC Clock Source.
 *            This parameter can be one of the following values:
 *            \arg ENABLE: Enable the specified RCC Clock Source.
 *            \arg DISABLE: Disable the specified RCC Clock Source.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_xx_init(void)
 * {
 *     RCC_TimSourceConfig(TIM2TO7_CLOCK_DIV_1, TIM_CLOCK_SOURCE_40MHZ, ENABLE);
 * }
 * \endcode
 */
void RCC_TimSourceConfig(uint16_t clocklevel, uint16_t clocksource, FunctionalState NewState);
#endif
/** End of RCC_Exported_Functions
  * \}
  */

/** End of RCC
  * \}
  */

#ifdef __cplusplus
}
#endif

#endif /* RTL_RCC_H */


/******************* (C) COPYRIGHT 2023 Realtek Semiconductor *****END OF FILE****/



