/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: LicenseRef-Realtek-5-Clause
 */

#ifndef RTL_CAN_DEF_H
#define RTL_CAN_DEF_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "rtl876x.h"

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */

/*============================================================================*
 *                          CAN Features
 *============================================================================*/
#define CAN_SUPPORT_EXT_LOOPBACK                         (1)
#define CAN_SUPPORT_INT_MSK_STS                          (1)
#define CAN_SUPPORT_SLEEP_MODE                           (1)

#define CAN_DFS_BIT_FIELD_FD_SSP_AUTO   can_reg_0x00.b.can_fd_ssp_auto
#define CAN_DFS_BIT_FIELD_FD_SSP_DCO_2  can_reg_0x14.b.can_fd_ssp_dco_2
#define CAN_FD_BIT_TIMING               CAN_RSVD_0X10
#define CAN_FD_SSP_CAL                  CAN_RSVD_0X14

/** @addtogroup 87x3g_CAN CAN
  * @brief Can driver module
  * @{
  */

/*============================================================================*
 *                         Types
 *============================================================================*/
/** \defgroup 87x3g_CAN_Exported_Types
  * \brief
  * \{
  */

/**
* \brief       CAN clock div definition.
*/
typedef enum _X3G_CANClkDIV_TypeDef
{
    CAN_CLK_DIV_1 = 0,      //!< DVI = 1(40M / 1).
    CAN_CLK_DIV_2 = 1,      //!< DVI = 2(40M / 2).
} CANClkDIV_TypeDef;

#define IS_CAN_CLK_DIV(DIV)              (((DIV) == CAN_CLK_DIV_1) || \
                                          ((DIV) == CAN_CLK_DIV_2)) //!< Check whether is the CAN DIV.

/**
* \brief       CAN frame IDE mask value when in rx mode.
*/
typedef enum _X3G_CANFrameIDEMask_TypeDef
{
    CAN_RX_FRAME_MASK_IDE = 0,    //!< Mask the IDE of CAN RX frame.
    CAN_RX_FRAME_UNMASK_IDE = 1,  //!< Unmask the IDE of CAN RX frame.
} CANFrameIDEMask_TypeDef;

/**
* \brief       CAN frame RTR mask value when in rx mode.
*/
typedef enum _X3G_CANFrameRTRMask_TypeDef
{
    CAN_RX_FRAME_MASK_RTR = 0,    //!< Mask the RTR of CAN RX frame.
    CAN_RX_FRAME_UNMASK_RTR = 1,  //!< Unmask the RTR of CAN RX frame.
} CANFrameRTRMask_TypeDef;

/**
* \brief       CAN frame ID mask value when in rx mode.
*/
typedef enum _X3G_CANFrameIDMask_TypeDef
{
    CAN_RX_FRAME_MASK_ID = 0,   //!< Mask the ID of CAN RX frame.
} CANFrameIDMask_TypeDef;

#if (CAN_SUPPORT_SLEEP_MODE == 1)
/**
* \brief       CAN low power clock div definition.
*/
typedef enum _X3G_CANLowPowerClkDIV_TypeDef
{
    CAN_LOW_CLK_DISABLE = 0,        //!< Disable low power clock.
    CAN_LOW_CLK_DIV_5 = 1,          //!< DVI = 5(40M / 5).
    CAN_LOW_CLK_DIV_10 = 2,         //!< DVI = 10(40M / 10).
    CAN_LOW_CLK_DIV_20 = 3,         //!< DVI = 20(40M / 20).
} CANLowPowerClkDIV_TypeDef;

#define IS_CAN_LOWER_CLK_DIV(DIV)              (((DIV) == CAN_LOW_CLK_DISABLE) || \
                                                ((DIV) == CAN_LOW_CLK_DIV_5) || \
                                                ((DIV) == CAN_LOW_CLK_DIV_10) || \
                                                ((DIV) == CAN_LOW_CLK_DIV_20))  /*!< Check whether is the CAN lower power clock DIV. */
#endif

/** End of 87x3g_CAN_Exported_Types
  * \}
  */

/*============================================================================*
 *                          CAN Declaration
 *============================================================================*/

/** @defgroup 87x3g_CAN_Declaration CAN Declaration
  * @{
  */
#define CAN0                       ((CAN_TypeDef *) CAN0_BASE)
#define CAN1                       ((CAN_TypeDef *) CAN1_BASE)
#define CAN2                       ((CAN_TypeDef *) CAN2_BASE)
/** End of group 87x3g_CAN_Declaration
  * @}
  */

/** @} */ /* End of group 87x3g_CAN */

/*============================================================================*
 *                          CAN Registers Memory Map
 *============================================================================*/
typedef struct            /*!< CAN Structure */
{
    __IO uint32_t  CAN_CTL;              //!<0X00
    __IO uint32_t  CAN_STS;              //!<0X04
    __IO uint32_t  CAN_FIFO_STS;         //!<0X08
    __IO uint32_t  CAN_BIT_TIMING;       //!<0X0C
    __IO uint32_t  CAN_RSVD_0X10;        //!<0X10
    __IO uint32_t  CAN_RSVD_0X14;        //!<0X14
    __IO uint32_t  CAN_INT_EN;           //!<0X18
    __IO uint32_t  CAN_MB_RXINT_EN;      //!<0X1C
    __IO uint32_t  CAN_MB_TXINT_EN;      //!<0X20
    __IO uint32_t  CAN_INT_FLAG;         //!<0X24
    __IO uint32_t  CAN_ERR_STATUS;       //!<0X28
    __IO uint32_t  CAN_ERR_CNT_CTL;      //!<0X2C
    __IO uint32_t  CAN_ERR_CNT_STS;      //!<0X30
    __IO uint32_t  CAN_TX_ERROR_FLAG;    //!<0X34
    __IO uint32_t  CAN_TX_DONE;          //!<0X38
    __IO uint32_t  CAN_RX_DONE;          //!<0X3C
    __IO uint32_t  CAN_TIME_STAMP;       //!<0X40
    __IO uint32_t  CAN_MB_TRIGGER;       //!<0X44
    __IO uint32_t  CAN_RXDMA_MSIZE;      //!<0X48
    __IO uint32_t  CAN_RX_DMA_DATA;      //!<0X4C
    __IO uint32_t  CAN_SLEEP_MODE;       //!<0X50
    __IO uint32_t  CAN_TEST;             //!<0X54
    uint32_t  CAN_RSVD[42];         //!<0X58:0xFC
    __IO uint32_t  CAN_MB0_15_STS[16];   //!<0X100:0x13C
    uint32_t  CAN_RSVD1[48];        //!<0X140:0x1FC
    __IO uint32_t  CAN_MB0_15_CTRL[16];  //!<0X200:0x23C
    uint32_t  CAN_RSVD2[44];        //!<0X240:0x2EC
    __IO uint32_t  CAN_MB_BA_END;        //!<0X2F0
    uint32_t  CAN_RSVD3[3];         //!<0X2F4:0x2FC
    uint32_t  CAN_RSVD4[14];             //!<0X300:0x334
    __IO uint32_t  CAN_RAM_DATA[2];      //!<0X338:0x33C
    __IO uint32_t  CAN_RAM_ARB;          //!<0X340
    __IO uint32_t  CAN_RAM_MASK;         //!<0X344
    __IO uint32_t  CAN_RAM_CS;           //!<0X348
    __IO uint32_t  CAN_RAM_CMD;          //!<0X34C
} CAN_TypeDef;

#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* RTL_CAN_DEF_H */

