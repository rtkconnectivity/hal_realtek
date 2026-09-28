/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _HAL_DEFINE_
#define _HAL_DEFINE_

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/** @defgroup HAL_87x3g_HAL_DEF HAL DEF
 * @brief HAL define.
 * @{
 */

/** @defgroup 87x3g_HAL_DEF_Exported_Constants HAL DEF Exported Constants
  * @{
  */
#define CHIP_DMA_CHANNEL_NUM                 (16)   //!< RTL87x3G has 16 GDMA channels.
#define CHIP_I2C_NUM                         (3)    //!< RTL87x3G has 3 I2C ports.

#ifndef CONFIG_SOC_SERIES_RTL87X3G
#define CONFIG_SOC_SERIES_RTL87X3G        //!< RTL87x3G Definition.
#endif

/** End of group 87x3g_HAL_DEF_Exported_Constants
  * @}
  */

/** End of group HAL_87x3g_HAL_DEF
  * @}
  */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _HAL_DEFINE_ */

