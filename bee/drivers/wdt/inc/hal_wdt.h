/**
*****************************************************************************************
*     Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
*****************************************************************************************
  * @file    hal_wdt.h
  * @brief   This file provides watch dog timer HAL layer api
  * @author  renee
  * @date    2023-11-16
  * @version v1.0
  * *************************************************************************************
   * @attention
   * <h2><center>&copy; COPYRIGHT 2023 Realtek Semiconductor Corporation</center></h2>
   * *************************************************************************************
 * @endcode
 */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef _HAL_WDT_H
#define _HAL_WDT_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                               Header Files
*============================================================================*/
#include <stdint.h>
#include <stdbool.h>

typedef enum _WDT_MODE
{
    INTERRUPT_CPU = 0,          /**< Interrupt CPU only */
    RESET_CORE_DOMAIN = 1,      /**< Reset core domain */
    RESET_ALL_EXCEPT_AON = 2,   /**< Reset all except RTC and some AON register */
    RESET_ALL = 3,              /**< Reset all */
    MODE_UNKNOWN = 4            /**< Mode unknown */
} T_WDT_MODE;

typedef enum
{
    CORE_WDT,                   /**< Core watch dog timer */
    AON_WDT,                    /**< AON watch dog timer */
    CORE_AON_BOTH_WDT,          /**< Core and AON watch dog both, AON wdt is back up for Core WDT */
    AON_WDT_FOR_CHARGER,        /**< AON watch dog for charger */
    WDT_ID_MAX,                 /**< Watch dog ID max index */
} T_WDT_ID;

/** @brief  This enum define the API return type.  */
typedef enum
{
    HAL_WDT_STATUS_INVALID_PARAMETER = -1,       /**<  A wrong parameter is given. */
    HAL_WDT_STATUS_OK = 0                        /**<  No error occurred during the function call. */
} T_WDT_STATUS;

#define IS_WDT_MODE(MODE) ((MODE) < MODE_UNKNOWN)
#define IS_WDT_ID(ID) ((ID) < WDT_ID_MAX)

typedef void (*P_WDT_RESET_CB)(T_WDG_MODE wdg_mode, T_SW_RESET_REASON reset_reason);

/** @defgroup HAL_WDT_API_Exported_Functions WDT Api
  * @{
  */

/**
    * @brief  set wdg timeout periods and mode
    * @param  none
    * @return true: enable
    * @return false: disable
    */
T_WDT_STATUS hal_wdt_start(T_WDT_ID wdt_id, T_WDT_MODE mode, uint32_t timeout_ms);

/**
    * @brief  disable wdt
    * @param  none
    * @return none
    */
T_WDT_STATUS hal_wdt_stop(T_WDT_ID wdt_id);

/**
    * @brief  check if wdt is enable
    * \xrefitem Added_API_2_13_0_0 "Added Since 2.13.0.0" "Added API"
    * @param  none
    * @return true: enable
        * @return false: disable
    */
bool hal_wdt_is_enable(T_WDT_ID wdt_id);

/**
    * @brief  wdt current mode get
        * \xrefitem Added_API_2_13_0_0 "Added Since 2.13.0.0" "Added API"
    * @param  none
    * @return wdt type @ref T_WDT_TYPE
    */
T_WDT_MODE hal_wdt_get_mode(T_WDT_ID wdt_id);

/**
    * @brief  wdt current timeout value get
    * \xrefitem Added_API_2_13_0_0 "Added Since 2.13.0.0" "Added API"
    * @param  none
    * @return current timeout
    */
uint32_t hal_wdt_get_timeout_ms(T_WDT_ID wdt_id);

/**
    * @brief  change wdt timeout period
    * \xrefitem Added_API_2_13_0_0 "Added Since 2.13.0.0" "Added API"
    * @param  timeout_ms: new timeout value
    * @return none
    */
T_WDT_STATUS hal_wdt_change_timeout_period(T_WDT_ID wdt_id, uint32_t timeout_ms);

/**
    * @brief  change wdt mode
    * \xrefitem Added_API_2_13_0_0 "Added Since 2.13.0.0" "Added API"
    * @param  wdt type @ref T_WDT_TYPE
    * @return none
    */
T_WDT_STATUS hal_wdt_change_mode(T_WDT_ID wdt_id, T_WDT_MODE mode);

/**
    * @brief  kick wdt
    * @param  none
    * @return none
    */
T_WDT_STATUS hal_wdt_kick(T_WDT_ID wdt_id);

/**
    * @brief  reset the mcu at specified mode
    * @param  mode: @ref T_WDT_TYPE
    * @return none
    */
void hal_wdt_reset(T_WDT_MODE wdt_mode, const char *function, uint32_t line);
#define chip_reset(mode)    hal_wdt_reset(mode,  __FUNCTION__, __LINE__)

void hal_wdt_regiser_reset_callback(P_WDT_RESET_CB reset_callback);

void hal_wdt_reset_with_reason(T_WDT_MODE wdt_mode, uint8_t reset_reason);

uint8_t hal_wdt_get_reset_reason();

#ifdef __cplusplus
}
#endif
/** @} */ /* End of group HAL_WDT_API_Exported_Functions */
/** @} */ /* End of group HAL_WDT_API */
#endif
