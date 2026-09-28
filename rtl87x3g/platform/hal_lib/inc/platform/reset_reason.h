/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/** @defgroup  WDG_RESET_REASON    WDG Reset Reason
    * @brief This file introduces the watch dog reset reason.
    * @{
    */

/*============================================================================*
 *               Constants
 *============================================================================*/
#ifndef __WDG_RESET_REASON_
#define __WDG_RESET_REASON_

#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup WDG_RESET_REASON_Exported_Constants WDG Reset Reason Exported Constants
  * @{
  */

#define RESET_REASON_HW             0x0               //!< Indicates hardware reset.
#define RESET_REASON_MAX            0x3F              //!< Reset reason max index.

/** End of group WDG_RESET_REASON_Exported_Constants
  * @}
  */

#ifdef __cplusplus
}
#endif
/** @} */ /* End of group WDG_RESET_REASON */
#endif
