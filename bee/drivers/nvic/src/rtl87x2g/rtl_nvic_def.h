/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RTL_NVIC_DEF_H
#define RTL_NVIC_DEF_H

#include "utils/rtl_utils.h"
#include "address_map.h"
#include "platform_reg.h"
#include "vector_table.h"
#include "armv81mml_setting.h"

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */

/*============================================================================*
 *                         NVIC Defines
 *============================================================================*/
/** \defgroup NVIC_Exported_Constants NVIC Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup NVIC_Defines NVIC Defines
 * \{
 * \ingroup  NVIC_Exported_Constants
 */

/** End of NVIC_Defines
  * \}
  */

/** End of NVIC_Exported_Constants
  * \}
  */

/*============================================================================*
 *                         NVIC Private Defines
 *============================================================================*/
#define FIRST_LEVEL_First_IRQn   System_IRQn
#define FIRST_LEVEL_Last_IRQn    PF_RTC_IRQn

#define Peripheral_First_IRQn    SPIC0_IRQn
#define Peripheral_Last_IRQn     RSVD7_IRQn

#define BTMAC_First_IRQn         Timer_A0_A1_IRQn
#define BTMAC_Last_IRQn          RSVD6_IRQn

/*============================================================================*
 *                         NVIC Constants
 *============================================================================*/

/** \defgroup NVIC_Exported_Constants NVIC Exported Constants
  * \brief
  * \{
  */

/** End of NVIC_Exported_Constants
  * \}
  */

#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* RTL_NVIC_DEF_H */
