/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef         _MFB_API_
#define         _MFB_API_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

/** @addtogroup MFB MFB
  * @brief MFB function module.
  * @{
  */

/*============================================================================*
 *                         Types
 *============================================================================*/


/** @defgroup MFB_Exported_Types MFB Exported Types
  * @{
  */

/**
  * @brief  MFB callback definition.
  */
typedef void (*P_MFB_LEVEL_CHANGE_CBACK)(void);

/** End of group MFB_Exported_Types
  * @}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/

/** @defgroup MFB_Exported_Functions MFB Exported Functions
  * @{
  */

/**
    * @brief  MFB get level.
    * @return True means level high, false means level low.
    */
bool mfb_get_level(void);

/**
    * @brief  Enable MFB interrupt.
    */
void mfb_irq_enable(void);

/**
    * @brief  Disable MFB interrupt.
    */
void mfb_irq_disable(void);

/**
    * @brief  Initialize the MFB for power on key.
    * @param  cback: Callback function which called in MFB interrupt handler.
    */
void mfb_init(P_MFB_LEVEL_CHANGE_CBACK cback);

/** @} */ /* End of group MFB_Exported_Functions */
/** @} */ /* End of group MFB */

#ifdef __cplusplus
}
#endif

#endif /*_MFB_API_*/
