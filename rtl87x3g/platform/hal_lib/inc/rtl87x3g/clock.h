/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef __CLOCK_H_
#define __CLOCK_H_


/*============================================================================*
 *                               Header Files
*============================================================================*/
#include <stdint.h>
#include <stdbool.h>


#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup HAL_87x3g_CLOCK
  * @brief
  * @{
  */

/*============================================================================*
 *                              Variables
*============================================================================*/
/** @defgroup Clock_Exported_Variables Clock Exported Variables
  * @{
  */

typedef enum
{
    CLOCK_CPU            = 0,
    CLOCK_DSP            = 1,
    CLOCK_SPIC0          = 2,
    CLOCK_SPIC1          = 3,
    CLOCK_SPIC2          = 4,
    CLOCK_SPIC3          = 5,
    CLOCK_40M            = 6,
    CLOCK_SYS_MODULE_MAX = 7,
    CLOCK_SDIO0          = CLOCK_SYS_MODULE_MAX,
    CLOCK_SDIO1          = 8,
    CLOCK_SPI1_MASTER    = 9,
    CLOCK_DISPLAY        = 10,
    CLOCK_IR             = 11,
    CLOCK_TIMER_CH6_8    = 12,
    CLOCK_PPE            = 13,
    CLOCK_PKE            = 14,
    CLOCK_IDU            = 15,
    CLOCK_JPEG           = 16,
    CLOCK_USB            = 17,
    CLOCK_GMAC           = 18,
    CLOCK_MODULE_MAX     = 19,
} CLKRequestType;


typedef enum _ACTIVE_PLL_CLK_SRC
{
    CLK_PLL1 = 1,
    CLK_PLL2,
//    CLK_PLL3,
} ACTIVE_PLL_CLK_SRC_TYPE;

/** @} */ /* End of group DLPS_PLATFORM_Exported_Variables */

/*============================================================================*
 *                              Functions
*============================================================================*/
/** @defgroup DLPS_PLATFORM_Exported_Functions DLPS Platform Exported Functions
  * @{
  */
/**
 * @brief Pre-processing hook before clock resource allocation.
 *
 * This function is called before a clock resource is allocated or switched.
 * It can be used to perform validation checks, prepare resources,
 * log events, or implement any other custom pre-processing logic.
 *
 * @param clk_type      The type of clock to be configured. See CLKRequestType.
 * @param required_mhz  The target clock frequency in MHz to be set.
 *
 * @return int32_t
 *         - 0     : Success, continue with the clock allocation process.
 *         - < 0   : Failure or rejection, abort the following allocation process.
 */
int32_t clk_register_pre_hook(CLKRequestType clk_type, uint32_t required_mhz);


/**
 * @brief Post-processing hook after clock resource allocation.
 *
 * This function is called after a clock resource is successfully allocated or switched.
 * It can be used for resource synchronization, status updates, logging,
 * notifications, or any other required post-processing logic.
 *
 * @param clk_type      The type of clock that was configured. See CLKRequestType.
 * @param required_mhz  The frequency in MHz that the clock has been set to.
 *
 * @return int32_t
 *         - 0     : Success, continue with any further processing if needed.
 *         - < 0   : Failure in post-processing, proper handling should be considered.
 */
int32_t clk_register_post_hook(CLKRequestType clk_type, uint32_t required_mhz,
                               uint32_t *actual_mhz);

/**
 * @brief Enable a specified PLL clock source.
 *
 * This function enables the given Phase-Locked Loop (PLL) clock source
 * based on the specified active clock source type. It uses a clock
 * handle for additional configuration or context as required by the
 * underlying hardware or clock management subsystem.
 *
 * @param active_clk_src   The type of PLL clock source to activate.
 *                         (See ACTIVE_PLL_CLK_SRC_TYPE for possible values.)
 * @param clock_handle     Pointer to a clock handle or context object.
 *                         The usage depends on the implementation.
 *
 * @return int32_t         Returns 0 on success, or a negative error code
 *                         if enabling fails.
 */
int32_t clk_pll_request(ACTIVE_PLL_CLK_SRC_TYPE active_clk_src, void **clock_handle);

/** @} */ /* End of group DLPS_PLATFORM_Exported_Variables */
/** @} */ /* End of group DLPS_PLATFORM_Exported_Variables */

#ifdef __cplusplus
}
#endif

#endif
