/**
*********************************************************************************************************
*               Copyright(c) 2016, Realtek Semiconductor Corporation. All rights reserved.
*********************************************************************************************************
* \file      rtl_wdt.h
* \brief     header file of watch dog timer driver.
* \details
* \author    renee
* \date      2023-11-16
* \version   v1.0
* *********************************************************************************************************
*/

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef RTL_WDT_H
#define RTL_WDT_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                               Header Files
*============================================================================*/
#include <stdbool.h>
#if defined (CONFIG_SOC_SERIES_RTL87X2G)
#include "wdt/src/rtl87x2g/rtl_wdt_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3E)
#include "wdt/src/rtl87x3e/rtl_wdt_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3D)
#include "wdt/src/rtl8763d/rtl_wdt_def.h"
#endif

/** \defgroup 87X2G_WDT         WDT
  * \brief
  * \{
  */

/*============================================================================*
 *                         Types
 *============================================================================*/
/** \defgroup WDT_Exported_Types WDT Exported Types
  * \brief
  * \{
  */

/**
  * \brief       WDT Mode structure definition.
  *
  * \ingroup     WDT_Exported_Types
  */
typedef enum
{
#if (WDT_SUPPORT_RESET_CORE_DOMAIN == 1)
    INTERRUPT_CPU = 0,            /**< Interrupt CPU. */
    RESET_CORE_DOMAIN = 1,        /**< Reset core domain. */
    RESET_ALL_EXCEPT_AON = 2,    /**< Reset all except RTC and some AON register. */
    RESET_ALL = 3                /**< Reset all. */
#else
    RESET_ALL = 0,               /**< Reset all. */
    RESET_ALL_EXCEPT_AON = 1,    /**< Reset all except RTC and some AON register. */
    INTERRUPT_CPU = 2,           /**< Interrupt CPU. */
#endif
} WDTMode_TypeDef;

/** End of group WDT_Exported_Types
  * \}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/
/** \defgroup WDT_Exported_Functions WDT Exported Functions
  * \{
  */

/**
  * \brief  Start WDT. This function will enable WDT clock, set and start WDT.
  * \param  TimeMs.
  * \param  Mode \ref WDTMode_TypeDef.
  * \return true or false.
  */
bool WDT_Start(uint32_t TimeMs, WDTMode_TypeDef Mode);

/**
  * \brief  Disable WDT.
  * \return None.
  */
void WDT_Disable(void);

/**
  * \brief  Kick WDT to restart WDT.
  * \return None.
  */
void WDT_Kick(void);

/**
  * \brief  Is WDT enable.
  * \return Is WDT enable or not
  */
bool WDT_IsEnable(void);

/**
  * \brief  Get WDT timeout.
  * \return WDT timeout
  */
uint32_t WDT_GetTimeoutMs(void);

/**
  * \brief  Get WDT mode.
  * \return WDT mode
  */
WDTMode_TypeDef WDT_GetMode(void);

/** End of WDT_Exported_Functions
  * \}
  */

/** End of WDT
  * \}
  */

#ifdef __cplusplus
}
#endif

#endif /* RTL_WDT_H */
