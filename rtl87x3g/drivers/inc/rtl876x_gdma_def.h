/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: LicenseRef-Realtek-5-Clause
 */

#ifndef RTL_GDMA_DEF_H
#define RTL_GDMA_DEF_H

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include <stdint.h>
#include <stdbool.h>
#include "rtl876x.h"

/*============================================================================*
 *                          Private Macros
 *============================================================================*/
#define CHIP_GDMA_CHANNEL_NUM                        (16)

#define GDMA_SUPPORT_GATHER_SCATTER_FUNCTION         (1)
#define GDMA_SUPPORT_INT_HAIF_BLOCK                  (1)
#define GDMA_SUPPORT_INT_HAIF_BLOCK_ALL              (1)
#define GDMA_SUPPORT_TIMER_DMA_EN                    (1)

/*============================================================================*
 *                         GDMA Registers Memory Map
 *============================================================================*/
typedef struct
{
    __IO uint32_t GDMA_SARx;                /*!< 0x00 */
    __I  uint32_t GDMA_CURR_SARx;           /*!< 0x04 */
    __IO uint32_t GDMA_DARx;                /*!< 0x08 */
    __I  uint32_t GDMA_CURR_DARx;           /*!< 0x0C */
    __IO uint32_t GDMA_LLPx;                /*!< 0x10 */
    __IO uint32_t GDMA_RSVD;                /*!< 0x14 */
    __IO uint32_t GDMA_CTL_LOWx;            /*!< 0x18 */
    __IO uint32_t GDMA_CTL_HIGHx;           /*!< 0x1C */
    __IO uint32_t GDMA_RSVD1[8];            /*!< 0x20 ~ 0x3C */
    __IO uint32_t GDMA_CFG_LOWx;            /*!< 0x40 */
    __IO uint32_t GDMA_CFG_HIGHx;           /*!< 0x44 */
    __IO uint32_t GDMA_SGR_LOW;             /*!< 0x48 */
    __IO uint32_t GDMA_SGR_HIGH;            /*!< 0x4C */
    __IO uint32_t GDMA_DSR_LOW;             /*!< 0x50 */
    __IO uint32_t GDMA_DSR_HIGH;            /*!< 0x54 */
} GDMA_ChannelTypeDef;

typedef struct
{
    uint32_t GDMA_RSVD[10];                 /*!< 0x2C0 - 0x2E4 */

    __I uint32_t GDMA_StatusTfr;            /*!< 0x2E8 */
    uint32_t GDMA_RSVD1;
    __I uint32_t GDMA_StatusBlock;          /*!< 0x2F0 */
    __I uint32_t GDMA_StatusHalfBlock;      /*!< 0x2F4 */
    __I uint32_t GDMA_StatusSrcTran;        /*!< 0x2F8 */
    uint32_t GDMA_RSVD3;
    __I uint32_t GDMA_StatusDstTran;        /*!< 0x300 */
    uint32_t GDMA_RSVD4;
    __I uint32_t GDMA_StatuErr;             /*!< 0x308 */
    __I uint32_t GDMA_StatuErrNonSecure;

    __IO uint32_t GDMA_MaskTfr;             /*!< 0x310 */
    uint32_t GDMA_RSVD6;
    __IO uint32_t GDMA_MaskBlock;           /*!< 0x318 */
    __IO uint32_t GDMA_MaskHalfBlock;       /*!< 0x31C */
    __IO uint32_t GDMA_MaskSrcTran;         /*!< 0x320 */
    uint32_t GDMA_RSVD8;
    __IO uint32_t GDMA_MaskDstTran;         /*!< 0x328 */
    uint32_t GDMA_RSVD9;
    __IO uint32_t GDMA_MaskErr;             /*!< 0x330 */
    __IO uint32_t GDMA_MaskErrNonSecure;

    __O uint32_t GDMA_ClearTfr;             /*!< 0x338 */
    uint32_t GDMA_RSVD11;
    __O uint32_t GDMA_ClearBlock;           /*!< 0x340 */
    __O uint32_t GDMA_ClearHalfBlock;       /*!< 0x344 */
    __O uint32_t GDMA_ClearSrcTran;         /*!< 0x348 */
    uint32_t GDMA_RSVD13;
    __O uint32_t GDMA_ClearDstTran;         /*!< 0x350 */
    uint32_t GDMA_RSVD14;
    __O uint32_t GDMA_ClearErr;             /*!< 0x358 */
    __O uint32_t GDMA_ClearErrNonSecure;

    uint32_t GDMA_RSVD16[14];               /*!< 0x360 ~ 0x394 */

    __IO uint32_t GDMA_DmaCfgReg;           /*!< 0x398 */
    uint32_t GDMA_RSVD17;
    __IO uint32_t GDMA_ChEnReg;             /*!< 0x3A0 */
    uint32_t GDMA_RSVD18;

    uint32_t GDMA_RSVD19[4];                /*!< 0x3A8 ~ 0x3B4 */
    __IO uint32_t GDMA_DmaOsNum;            /*!< 0x3B8 */
    uint32_t GDMA_RSVD20;
} GDMA_TypeDef;

/** @addtogroup 87x3g_GDMA GDMA
  * @brief GDMA driver module
  * @{
  */
/* ================================================================================ */
/* ================                GDMA Declaration                ================ */
/* ================================================================================ */

/** @defgroup 87x3g_GDMA_Declaration GDMA Declaration
  * @{
  */

#define GDMA_REG_BASE                   (RXI350_DMA_CFG_BASE + 0x02c0)      //!< The GDMA0 base address.
#define GDMA_Channel0_BASE              (RXI350_DMA_CFG_BASE + 0x0000)      //!< The GDMA0 channel0 base address.
#define GDMA_Channel1_BASE              (RXI350_DMA_CFG_BASE + 0x0058)      //!< The GDMA0 channel1 base address.
#define GDMA_Channel2_BASE              (RXI350_DMA_CFG_BASE + 0x00b0)      //!< The GDMA0 channel2 base address.
#define GDMA_Channel3_BASE              (RXI350_DMA_CFG_BASE + 0x0108)      //!< The GDMA0 channel3 base address.
#define GDMA_Channel4_BASE              (RXI350_DMA_CFG_BASE + 0x0160)      //!< The GDMA0 channel4 base address.
#define GDMA_Channel5_BASE              (RXI350_DMA_CFG_BASE + 0x01b8)      //!< The GDMA0 channel5 base address.
#define GDMA_Channel6_BASE              (RXI350_DMA_CFG_BASE + 0x0210)      //!< The GDMA0 channel6 base address.
#define GDMA_Channel7_BASE              (RXI350_DMA_CFG_BASE + 0x0268)      //!< The GDMA0 channel7 base address.
#define GDMA_Channel8_BASE              (RXI350_DMA_CFG_BASE + 0x0400)      //!< The GDMA0 channel8 base address.
#define GDMA_Channel9_BASE              (RXI350_DMA_CFG_BASE + 0x0458)      //!< The GDMA0 channel9 base address.
#define GDMA_Channel10_BASE             (RXI350_DMA_CFG_BASE + 0x04b0)      //!< The GDMA0 channel10 base address.
#define GDMA_Channel11_BASE             (RXI350_DMA_CFG_BASE + 0x0508)      //!< The GDMA0 channel11 base address.
#define GDMA_Channel12_BASE             (RXI350_DMA_CFG_BASE + 0x0560)      //!< The GDMA0 channel12 base address.
#define GDMA_Channel13_BASE             (RXI350_DMA_CFG_BASE + 0x05B8)      //!< The GDMA0 channel13 base address.
#define GDMA_Channel14_BASE             (RXI350_DMA_CFG_BASE + 0x0610)      //!< The GDMA0 channel14 base address.
#define GDMA_Channel15_BASE             (RXI350_DMA_CFG_BASE + 0x0668)      //!< The GDMA0 channel15 base address.


#define GDMA0                           ((GDMA_TypeDef             *) GDMA_REG_BASE)        //!< The GDMA0 base.
#define GDMA_BASE                       ((GDMA_TypeDef             *) GDMA_REG_BASE)        //!< The GDMA0 base.

#define GDMA_Channel0                   ((GDMA_ChannelTypeDef      *) GDMA_Channel0_BASE)   //!< The GDMA channel 0 base.
#define GDMA_Channel1                   ((GDMA_ChannelTypeDef      *) GDMA_Channel1_BASE)   //!< The GDMA channel 1 base.
#define GDMA_Channel2                   ((GDMA_ChannelTypeDef      *) GDMA_Channel2_BASE)   //!< The GDMA channel 2 base.
#define GDMA_Channel3                   ((GDMA_ChannelTypeDef      *) GDMA_Channel3_BASE)   //!< The GDMA channel 3 base.
#define GDMA_Channel4                   ((GDMA_ChannelTypeDef      *) GDMA_Channel4_BASE)   //!< The GDMA channel 4 base.
#define GDMA_Channel5                   ((GDMA_ChannelTypeDef      *) GDMA_Channel5_BASE)   //!< The GDMA channel 5 base.
#define GDMA_Channel6                   ((GDMA_ChannelTypeDef      *) GDMA_Channel6_BASE)   //!< The GDMA channel 6 base.
#define GDMA_Channel7                   ((GDMA_ChannelTypeDef      *) GDMA_Channel7_BASE)   //!< The GDMA channel 7 base.
#define GDMA_Channel8                   ((GDMA_ChannelTypeDef      *) GDMA_Channel8_BASE)   //!< The GDMA channel 8 base.
#define GDMA_Channel9                   ((GDMA_ChannelTypeDef      *) GDMA_Channel9_BASE)   //!< The GDMA channel 9 base.
#define GDMA_Channel10                  ((GDMA_ChannelTypeDef      *) GDMA_Channel10_BASE)  //!< The GDMA channel 10 base.
#define GDMA_Channel11                  ((GDMA_ChannelTypeDef      *) GDMA_Channel11_BASE)  //!< The GDMA channel 11 base.
#define GDMA_Channel12                  ((GDMA_ChannelTypeDef      *) GDMA_Channel12_BASE)  //!< The GDMA channel 12 base.
#define GDMA_Channel13                  ((GDMA_ChannelTypeDef      *) GDMA_Channel13_BASE)  //!< The GDMA channel 13 base.
#define GDMA_Channel14                  ((GDMA_ChannelTypeDef      *) GDMA_Channel14_BASE)  //!< The GDMA channel 14 base.
#define GDMA_Channel15                  ((GDMA_ChannelTypeDef      *) GDMA_Channel15_BASE)  //!< The GDMA channel 15 base.

#define IS_GDMA_PERIPH(PERIPH)     (((PERIPH) == GDMA_Channel0) || \
                                    ((PERIPH) == GDMA_Channel1) || \
                                    ((PERIPH) == GDMA_Channel2) || \
                                    ((PERIPH) == GDMA_Channel3) || \
                                    ((PERIPH) == GDMA_Channel4) || \
                                    ((PERIPH) == GDMA_Channel5) || \
                                    ((PERIPH) == GDMA_Channel6) || \
                                    ((PERIPH) == GDMA_Channel7) || \
                                    ((PERIPH) == GDMA_Channel8) || \
                                    ((PERIPH) == GDMA_Channel9) || \
                                    ((PERIPH) == GDMA_Channel10) || \
                                    ((PERIPH) == GDMA_Channel11) || \
                                    ((PERIPH) == GDMA_Channel12) || \
                                    ((PERIPH) == GDMA_Channel13) || \
                                    ((PERIPH) == GDMA_Channel14) || \
                                    ((PERIPH) == GDMA_Channel15))       //!< Check whether is GDMA channel.

#define IS_GDMA_ALL_PERIPH(PERIPH) (IS_GDMA_PERIPH(PERIPH))     //!< Check whether is GDMA channel.
/** End of group 87x3g_GDMA_Declaration
  * @}
  */
/** @} */ /* End of group 87x3g_GDMA */

/*============================================================================*
 *                         GDMA Registers and Field Descriptions
 *============================================================================*/
/* 0x00
   31:0    R/W    SAR                 undefined
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        uint32_t SAR: 32;
    } b;
} GDMA_SARx_TypeDef;



/* 0x04
   31:0    R      CURR_SAR            0x0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        const uint32_t CURR_SAR: 32;
        } b;
    } GDMA_CURR_SARx_TypeDef;



    /* 0x08
    31:0    R/W    DAR                 undefined
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t DAR: 32;
            } b;
        } GDMA_DARx_TypeDef;



    /* 0x0C
    31:0    R      CURR_DAR            0x0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t CURR_DAR: 32;
            } b;
        } GDMA_CURR_DARx_TypeDef;



    /* 0x10
    1:0     R/W    reserved13          0x0
    31:2    R/W    LOC                 0x0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t reserved_0: 2;
                uint32_t LOC: 30;
            } b;
        } GDMA_LLPx_TypeDef;


    /* 0x18
    0       R/W    INT_EN              0x1
    3:1     R/W    DST_TR_WIDTH        0x0
    6:4     R/W    SRC_TR_WIDTH        0x0
    8:7     R/W    DINC                0x0
    10:9    R/W    SINC                0x0
    13:11   R/W    DEST_MSIZE          0x1
    16:14   R/W    SRC_MSIZE           0x1
    17      R/W    SRC_SCATTER_EN      0x0
    18      R/W    DST_SCATTER_EN      0x0
    19      R/W    reserved20          0x0
    22:20   R/W    TT_FC               0x0
    26:23   R      reserved18          0x0
    27      R/W    LLP_DST_EN          0x0
    28      R/W    LLP_SRC_EN          0x0
    31:29   R      reserved15          0x0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t INT_EN: 1;
                uint32_t DST_TR_WIDTH: 3;
                uint32_t SRC_TR_WIDTH: 3;
                uint32_t DINC: 2;
                uint32_t SINC: 2;
                uint32_t DEST_MSIZE: 3;
                uint32_t SRC_MSIZE: 3;
                uint32_t SRC_GATHER_EN: 1;
                uint32_t DST_SCATTER_EN: 1;
                uint32_t reserved_2: 1;
                uint32_t TT_FC: 3;
                const uint32_t reserved_1: 4;
                uint32_t LLP_DST_EN: 1;
                uint32_t LLP_SRC_EN: 1;
                const uint32_t reserved_0: 3;
            } b;
        } GDMA_CTL_LOWx_TypeDef;



    /* 0x1C
    31:0    R      TRANS_DATA_CNT      0x0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t TRANS_DATA_CNT: 32;
            } b;
        } GDMA_CTL_HIGHx_R_TypeDef;



    /* 0x1C
    19:0    W      BLOCK_TS            0x2
    31:20   W      reserved31          0x0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t BLOCK_TS: 20;
                uint32_t reserved_0: 12;
            } b;
        } GDMA_CTL_HIGHx_W_TypeDef;


    /* 0x40
    0       R      INACTIVE            0x1
    1       R      SRC_PCTL_OVER       0x1
    2       R      DST_PCTL_OVER       0x1
    3       R      reserved45          0x0
    7:4     R/W    CH_PRIOR            0x0
    8       R/W    CH_SUSP             0x0
    9       R      FIFO_EMPTY          0x1
    10      R/W    HS_SEL_DST          0x1
    11      R/W    HS_SEL_SRC          0x1
    17:12   R      reserved39          0x0
    18      R/W    DST_HS_POL          0x0
    19      R/W    SRC_HS_POL          0x0
    29:20   R/W    reserved36          0x0
    30      R/W    RELOAD_SRC          0x0
    31      R/W    RELOAD_DST          0x0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t INACTIVE: 1;
                const uint32_t SRC_PCTL_OVER: 1;
                const uint32_t DST_PCTL_OVER: 1;
                const uint32_t reserved_2: 1;
                uint32_t CH_PRIOR: 4;
                uint32_t CH_SUSP: 1;
                const uint32_t FIFO_EMPTY: 1;
                uint32_t HS_SEL_DST: 1;
                uint32_t HS_SEL_SRC: 1;
                const uint32_t reserved_1: 6;
                uint32_t DST_HS_POL: 1;
                uint32_t SRC_HS_POL: 1;
                uint32_t reserved_0: 10;
                uint32_t RELOAD_SRC: 1;
                uint32_t RELOAD_DST: 1;
            } b;
        } GDMA_CFG_LOWx_TypeDef;



    /* 0x44
    0       R/W    reserved63          0x0
    1       R/W    reserved62          0x0
    2       R      reserved61          0x0
    3       R/W    PROTCTL             0x1
    6:4     R      reserved59          0x0
    10:7    R/W    SRC_PER             0x0
    14:11   R/W    DEST_PER            0x0
    15      R/W    ExtendedSRC_PER1    0x0
    16      R/W    ExtendedDEST_PER1   0x0
    17      R/W    ExtendedSRC_PER2    0x0
    18      R/W    ExtendedDEST_PER2   0x0
    19      R      ExtendedSRC_PER3    0x0
    20      R      ExtendedDEST_PER3   0x0
    31:21   R      reserved50          0x0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t reserved_5: 1;
                uint32_t reserved_4: 1;
                const uint32_t reserved_3: 1;
                uint32_t reserved_2: 1;
                const uint32_t reserved_1: 3;
                uint32_t SRC_PER: 4;
                uint32_t DEST_PER: 4;
                uint32_t ExtendedSRC_PER1: 1;
                uint32_t ExtendedDEST_PER1: 1;
                uint32_t ExtendedSRC_PER2: 1;
                uint32_t ExtendedDEST_PER2: 1;
                uint32_t ExtendedSRC_PER3: 1;
                uint32_t ExtendedDEST_PER3: 1;
                const uint32_t reserved_0: 11;
            } b;
        } GDMA_CFG_HIGHx_TypeDef;

    /* 0x48
    19:0    R/W    SGI                 0x0
    31:20   R/W    SGC                 0x0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t SGI: 20;
                uint32_t SGC: 12;
            } b;
        } GDMA_SGR_LOW_TypeDef;

    /* 0x4C
    15:0    R/W    SGSN                0x0
    31:16   R      reserved68          0x2
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t SGSN: 16;
                const uint32_t reserved_0: 16;
            } b;
        } GDMA_SGR_HIGH_TypeDef;

    /* 0x50
    19:0    R/W    DSI                 0x0
    31:20   R      DSC                 0x0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t DSI: 20;
                uint32_t DSC: 12;
            } b;
        } GDMA_DSR_LOW_TypeDef;

    /* 0x54
    15:0    R/W    DSSN                0x0
    31:16   R      reserved74          0x0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t DSSN: 16;
                const uint32_t reserved_0: 16;
            } b;
        } GDMA_DSR_HIGH_TypeDef;



    /* 0x2E8
    31:0    R      STATUS              0x0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t STATUS: 32;
            } b;
        } GDMA_StatusTfr_TypeDef;



    /* 0x2F0
    31:0    R      STATUS              0x0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t STATUS: 32;
            } b;
        } GDMA_StatusBlock_TypeDef;



    /* 0x2F8
    31:0    R      STATUS              0x0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t STATUS: 32;
            } b;
        } GDMA_StatusSrcTran_TypeDef;



    /* 0x300
    31:0    R      STATUS              0x0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t STATUS: 32;
            } b;
        } GDMA_StatusDstTran_TypeDef;



    /* 0x308
    31:0    R      STATUS              0x0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t STATUS: 32;
            } b;
        } GDMA_StatusErr_TypeDef;



    /* 0x310
    7:0     R/W    INT_MASK_L          0x0
    15:8    W      INT_MASK_WE_L       0x0
    23:16   R/W    INT_MASK_H          0x0
    31:24   W      INT_MASK_WE_H       0x0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t INT_MASK_L: 8;
                uint32_t INT_MASK_WE_L: 8;
                uint32_t INT_MASK_H: 8;
                uint32_t INT_MASK_WE_H: 8;
            } b;
        } GDMA_MaskTfr_TypeDef;



    /* 0x318
    7:0     R/W    INT_MASK_L          0x0
    15:8    W      INT_MASK_WE_L       0x0
    23:16   R/W    INT_MASK_H          0x0
    31:24   W      INT_MASK_WE_H       0x0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t INT_MASK_L: 8;
                uint32_t INT_MASK_WE_L: 8;
                uint32_t INT_MASK_H: 8;
                uint32_t INT_MASK_WE_H: 8;
            } b;
        } GDMA_MaskBlock_TypeDef;



    /* 0x320
    7:0     R/W    INT_MASK_L          0x0
    15:8    W      INT_MASK_WE_L       0x0
    23:16   R/W    INT_MASK_H          0x0
    31:24   W      INT_MASK_WE_H       0x0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t INT_MASK_L: 8;
                uint32_t INT_MASK_WE_L: 8;
                uint32_t INT_MASK_H: 8;
                uint32_t INT_MASK_WE_H: 8;
            } b;
        } GDMA_MaskSrcTran_TypeDef;



    /* 0x328
    7:0     R/W    INT_MASK_L          0x0
    15:8    W      INT_MASK_WE_L       0x0
    23:16   R/W    INT_MASK_H          0x0
    31:24   W      INT_MASK_WE_H       0x0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t INT_MASK_L: 8;
                uint32_t INT_MASK_WE_L: 8;
                uint32_t INT_MASK_H: 8;
                uint32_t INT_MASK_WE_H: 8;
            } b;
        } GDMA_MaskDstTran_TypeDef;



    /* 0x330
    7:0     R/W    INT_MASK_L          0x0
    15:8    W      INT_MASK_WE_L       0x0
    23:16   R/W    INT_MASK_H          0x0
    31:24   W      INT_MASK_WE_H       0x0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t INT_MASK_L: 8;
                uint32_t INT_MASK_WE_L: 8;
                uint32_t INT_MASK_H: 8;
                uint32_t INT_MASK_WE_H: 8;
            } b;
        } GDMA_MaskErr_TypeDef;



    /* 0x338
    31:0    W      CLEAR               0x0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t CLEAR: 32;
            } b;
        } GDMA_ClearTfr_TypeDef;



    /* 0x340
    31:0    W      CLEAR               0x0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t CLEAR: 32;
            } b;
        } GDMA_ClearBlock_TypeDef;



    /* 0x348
    31:0    W      CLEAR               0x0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t CLEAR: 32;
            } b;
        } GDMA_ClearSrcTran_TypeDef;



    /* 0x350
    31:0    W      CLEAR               0x0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t CLEAR: 32;
            } b;
        } GDMA_ClearDstTran_TypeDef;



    /* 0x358
    31:0    W      CLEAR               0x0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t CLEAR: 32;
            } b;
        } GDMA_ClearErr_TypeDef;



    /* 0x398
    0       R/W    DMAC_EN             0x0
    31:1    R      reserved130         0x0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t DMAC_EN: 1;
                __I uint32_t reserved_0: 31;
            } b;
        } GDMA_DmaCfgReg_TypeDef;



    /* 0x3A0
    7:0     R/W    CH_EN_L             0x0
    15:8    W      CH_EN_WE_L          0x0
    23:16   R/W    CH_EN_H             0x0
    31:24   W      CH_EN_WE_H          0x0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t CH_EN_L: 8;
                uint32_t CH_EN_WE_L: 8;
                uint32_t CH_EN_H: 8;
                uint32_t CH_EN_WE_H: 8;
            } b;
        } GDMA_ChEnReg_TypeDef;



    /* 0x3B8
    4:0     R    OSR                 0xC
    7:5     R    reserved_0          0x0
    10:8    R    OSW                 0x4
    31:11   R    reserved_1          0x0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t OSR: 5;
                const uint32_t reserved_0: 3;
                const uint32_t OSW: 3;
                const uint32_t reserved_1: 21;
            } b;
        } GDMA_DmaOsNum_TypeDef;


    /** @addtogroup 87x3g_GDMA GDMA
      * @brief GDMA driver module
      * @{
      */

    /* ================================================================================ */
    /* ================                   GDMA  Constants              ================ */
    /* ================================================================================ */

    /** @defgroup 87x3g_GDMA_Exported_Constants GDMA Exported Constants
      * @{
      */

    /**
     * \defgroup    87x3g_GDMA_IRQ GDMA IRQ
      * @{
     */

#define GDMA_Channel0_IRQn              GDMA0_Channel0_IRQn     //!< The IRQ of GDMA channel0.
#define GDMA_Channel1_IRQn              GDMA0_Channel1_IRQn     //!< The IRQ of GDMA channel1.
#define GDMA_Channel2_IRQn              GDMA0_Channel2_IRQn     //!< The IRQ of GDMA channel2.
#define GDMA_Channel3_IRQn              GDMA0_Channel3_IRQn     //!< The IRQ of GDMA channel3.
#define GDMA_Channel4_IRQn              GDMA0_Channel4_IRQn     //!< The IRQ of GDMA channel4.
#define GDMA_Channel5_IRQn              GDMA0_Channel5_IRQn     //!< The IRQ of GDMA channel5.
#define GDMA_Channel6_IRQn              GDMA0_Channel6_IRQn     //!< The IRQ of GDMA channel6.
#define GDMA_Channel7_IRQn              GDMA0_Channel7_IRQn     //!< The IRQ of GDMA channel7.
#define GDMA_Channel8_IRQn              GDMA0_Channel8_IRQn     //!< The IRQ of GDMA channel8.
#define GDMA_Channel9_IRQn              GDMA0_Channel9_IRQn     //!< The IRQ of GDMA channel9.
#define GDMA_Channel10_IRQn             GDMA0_Channel10_IRQn    //!< The IRQ of GDMA channel10.
#define GDMA_Channel11_IRQn             GDMA0_Channel11_IRQn    //!< The IRQ of GDMA channel11.
#define GDMA_Channel12_IRQn             GDMA0_Channel12_IRQn    //!< The IRQ of GDMA channel12.
#define GDMA_Channel13_IRQn             GDMA0_Channel13_IRQn    //!< The IRQ of GDMA channel13.
#define GDMA_Channel14_IRQn             GDMA0_Channel14_IRQn    //!< The IRQ of GDMA channel14.
#define GDMA_Channel15_IRQn             GDMA0_Channel15_IRQn    //!< The IRQ of GDMA channel15.

#define GDMA_Channel0_Handler           GDMA0_Channel0_Handler  //!< The handler of GDMA channel0.
#define GDMA_Channel1_Handler           GDMA0_Channel1_Handler  //!< The handler of GDMA channel1.
#define GDMA_Channel2_Handler           GDMA0_Channel2_Handler  //!< The handler of GDMA channel2.
#define GDMA_Channel3_Handler           GDMA0_Channel3_Handler  //!< The handler of GDMA channel3.
#define GDMA_Channel4_Handler           GDMA0_Channel4_Handler  //!< The handler of GDMA channel4.
#define GDMA_Channel5_Handler           GDMA0_Channel5_Handler  //!< The handler of GDMA channel5.
#define GDMA_Channel6_Handler           GDMA0_Channel6_Handler  //!< The handler of GDMA channel6.
#define GDMA_Channel7_Handler           GDMA0_Channel7_Handler  //!< The handler of GDMA channel7.
#define GDMA_Channel8_Handler           GDMA0_Channel8_Handler  //!< The handler of GDMA channel8.
#define GDMA_Channel9_Handler           GDMA0_Channel9_Handler  //!< The handler of GDMA channel9.
#define GDMA_Channel10_Handler          GDMA0_Channel10_Handler //!< The handler of GDMA channel10.
#define GDMA_Channel11_Handler          GDMA0_Channel11_Handler //!< The handler of GDMA channel11.
#define GDMA_Channel12_Handler          GDMA0_Channel12_Handler //!< The handler of GDMA channel12.
#define GDMA_Channel13_Handler          GDMA0_Channel13_Handler //!< The handler of GDMA channel13.
#define GDMA_Channel14_Handler          GDMA0_Channel14_Handler //!< The handler of GDMA channel14.
#define GDMA_Channel15_Handler          GDMA0_Channel15_Handler //!< The handler of GDMA channel15.

    /** End of 87x3g_GDMA_IRQ
      * @}
      */

    /** @defgroup 87x3g_GDMA_Handshake_Type GDMA Handshake Type
      * @{
      */
#define GDMA_Handshake_UART0_TX                                     (0)     //!< The handshake for UART0 TX.
#define GDMA_Handshake_UART0_RX                                     (1)     //!< The handshake for UART0 RX.
#define GDMA_Handshake_UART2_TX                                     (2)     //!< The handshake for UART2 TX.
#define GDMA_Handshake_UART2_RX                                     (3)     //!< The handshake for UART2 RX.
#define GDMA_Handshake_SPI0_TX                                      (4)     //!< The handshake for SPI0 TX.
#define GDMA_Handshake_SPI0_RX                                      (5)     //!< The handshake for SPI0 RX.
#define GDMA_Handshake_SPI1_TX                                      (6)     //!< The handshake for SPI1 TX.
#define GDMA_Handshake_SPI1_RX                                      (7)     //!< The handshake for SPI1 RX.
#define GDMA_Handshake_I2C0_TX                                      (8)     //!< The handshake for I2C0 TX.
#define GDMA_Handshake_I2C0_RX                                      (9)     //!< The handshake for I2C0 RX.
#define GDMA_Handshake_I2C1_TX                                      (10)    //!< The handshake for I2C1 TX.
#define GDMA_Handshake_I2C1_RX                                      (11)    //!< The handshake for I2C1 RX.
#define GDMA_Handshake_ADC_RX                                       (12)    //!< The handshake for ADC.
#define GDMA_Handshake_AES_TX                                       (13)    //!< The handshake for AES TX.
#define GDMA_Handshake_AES_RX                                       (14)    //!< The handshake for AES RX.
#define GDMA_Handshake_UART1_TX                                     (15)    //!< The handshake for UART1 TX.
#define GDMA_Handshake_TDM_0_TX                                     (16)    //!< The handshake for TDM0 TX.
#define GDMA_Handshake_TDM_0_RX                                     (17)    //!< The handshake for TDM0 RX.
#define GDMA_Handshake_TDM_1_TX                                     (18)    //!< The handshake for TDM1 TX.
#define GDMA_Handshake_TDM_1_RX                                     (19)    //!< The handshake for TDM1 RX.
#define GDMA_Handshake_UART1_RX                                     (20)    //!< The handshake for UART1 RX.
#define GDMA_Handshake_SPIC0_TX                                     (21)    //!< The handshake for SPIC0 TX.
#define GDMA_Handshake_SPIC0_RX                                     (22)    //!< The handshake for SPIC0 RX.
#define GDMA_Handshake_CANBUS0_RX                                   (23)    //!< The handshake for CANBUS0 RX.
#define GDMA_Handshake_CANBUS2_RX                                   (24)    //!< The handshake for CANBUS2 RX.
#define GDMA_Handshake_TIM1_CH6_TRX                                 (25)    //!< The handshake for TIM1_CH6 TRX.
#define GDMA_Handshake_TIM1_CH4                                     (26)    //!< The handshake for TIM1_CH4.
#define GDMA_Handshake_TIM1_CH5                                     (27)    //!< The handshake for TIM1_CH5.
#define GDMA_Handshake_TIM1_CH6                                     (28)    //!< The handshake for TIM1_CH6.
#define GDMA_Handshake_TIM1_CH7                                     (29)    //!< The handshake for TIM1_CH7.
#define GDMA_Handshake_TIM1_CH8                                     (30)    //!< The handshake for TIM1_CH8.
#define GDMA_Handshake_TIM1_CH9                                     (31)    //!< The handshake for TIM1_CH9.
#define GDMA_Handshake_SPIC1_TX                                     (32)    //!< The handshake for SPIC1 TX.
#define GDMA_Handshake_SPIC1_RX                                     (33)    //!< The handshake for SPIC1 RX.
#define GDMA_Handshake_SPIC2_TX                                     (34)    //!< The handshake for SPIC2 TX.
#define GDMA_Handshake_SPIC2_RX                                     (35)    //!< The handshake for SPIC2 RX.
#define GDMA_Handshake_I2C2_TX                                      (36)    //!< The handshake for I2C2 TX.
#define GDMA_Handshake_I2C2_RX                                      (37)    //!< The handshake for I2C2 RX.
#define GDMA_Handshake_SPI2_TX                                      (38)    //!< The handshake for SPI2 TX.
#define GDMA_Handshake_SPI2_RX                                      (39)    //!< The handshake for SPI2 RX.
#define GDMA_Handshake_AUDIO_RX                                     (40)    //!< The handshake for AUDIO RX.
#define GDMA_Handshake_TDM_2_RX                                     (42)    //!< The handshake for TDM2 RX.
#define GDMA_Handshake_IDU_RX                                       (43)    //!< The handshake for IDU RX.
#define GDMA_Handshake_IDU_TX                                       (44)    //!< The handshake for IDU TX.
#define GDMA_Handshake_SM3                                          (46)    //!< The handshake for SM3.
#define GDMA_Handshake_UART3_TX                                     (48)    //!< The handshake for UART3 TX.
#define GDMA_Handshake_UART3_RX                                     (49)    //!< The handshake for UART3 RX.
#define GDMA_Handshake_UART4_TX                                     (50)    //!< The handshake for UART4 TX.
#define GDMA_Handshake_UART4_RX                                     (51)    //!< The handshake for UART4 RX.
#define GDMA_Handshake_UART5_TX                                     (52)    //!< The handshake for UART5 TX.
#define GDMA_Handshake_UART5_RX                                     (53)    //!< The handshake for UART5 RX.
#define GDMA_Handshake_TIM1_CH7_TRX                                 (54)    //!< The handshake for TIM1_CH7 TRX.
#define GDMA_Handshake_SPI_SLAVE_TX                                 (55)    //!< The handshake for SPI SLAVE TX.
#define GDMA_Handshake_SPI_SLAVE_RX                                 (56)    //!< The handshake for SPI SLAVE RX.
#define GDMA_Handshake_CANBUS1_RX                                   (57)    //!< The handshake for CANBUS1 RX.
#define GDMA_Handshake_TIM1_CH9_TRX                                 (58)    //!< The handshake for TIM1_CH9 TRX.
#define GDMA_Handshake_TIM1_CH8_TRX                                 (59)    //!< The handshake for TIM1_CH8 TRX.
#define GDMA_Handshake_SPIC3_TX                                     (60)    //!< The handshake for SPIC3 TX.
#define GDMA_Handshake_SPIC3_RX                                     (61)    //!< The handshake for SPIC3 RX.
#define GDMA_Handshake_IR_TX                                        (62)    //!< The handshake for IR TX.
#define GDMA_Handshake_IR_RX                                        (63)    //!< The handshake for IR RX.

#define GDMA_Handshake_UART_TX           GDMA_Handshake_UART0_TX    //!< The handshake for UART0 TX.
#define GDMA_Handshake_UART_RX           GDMA_Handshake_UART0_RX    //!< The handshake for UART0 RX.
#define GDMA_Handshake_LOG_UART1_TX      GDMA_Handshake_UART2_TX    //!< The handshake for UART2 TX.
#define GDMA_Handshake_LOG_UART1_RX      GDMA_Handshake_UART2_RX    //!< The handshake for UART2 RX.
#define GDMA_Handshake_LOG_UART_TX       GDMA_Handshake_UART1_TX    //!< The handshake for UART1 TX.
#define GDMA_Handshake_LOG_UART_RX       GDMA_Handshake_UART1_RX    //!< The handshake for UART1 RX.

#define IS_GDMA_TransferType(Type) (((Type) == GDMA_Handshake_UART0_TX) || \
                                    ((Type) == GDMA_Handshake_UART0_RX) || \
                                    ((Type) == GDMA_Handshake_UART2_TX) || \
                                    ((Type) == GDMA_Handshake_UART2_RX) || \
                                    ((Type) == GDMA_Handshake_SPI0_TX) || \
                                    ((Type) == GDMA_Handshake_SPI0_RX) || \
                                    ((Type) == GDMA_Handshake_SPI1_TX) || \
                                    ((Type) == GDMA_Handshake_SPI1_RX) || \
                                    ((Type) == GDMA_Handshake_I2C0_TX) || \
                                    ((Type) == GDMA_Handshake_I2C0_RX) || \
                                    ((Type) == GDMA_Handshake_I2C1_TX) || \
                                    ((Type) == GDMA_Handshake_I2C1_RX) || \
                                    ((Type) == GDMA_Handshake_ADC_RX) || \
                                    ((Type) == GDMA_Handshake_AES_TX) || \
                                    ((Type) == GDMA_Handshake_AES_RX) || \
                                    ((Type) == GDMA_Handshake_UART1_TX) || \
                                    ((Type) == GDMA_Handshake_TDM_0_TX) || \
                                    ((Type) == GDMA_Handshake_TDM_0_RX) || \
                                    ((Type) == GDMA_Handshake_TDM_1_TX) || \
                                    ((Type) == GDMA_Handshake_TDM_1_RX) || \
                                    ((Type) == GDMA_Handshake_UART1_RX) || \
                                    ((Type) == GDMA_Handshake_SPIC0_TX) ||\
                                    ((Type) == GDMA_Handshake_SPIC0_RX) ||\
                                    ((Type) == GDMA_Handshake_CANBUS0_RX) ||\
                                    ((Type) == GDMA_Handshake_TIM1_CH4)||\
                                    ((Type) == GDMA_Handshake_TIM1_CH5)||\
                                    ((Type) == GDMA_Handshake_TIM1_CH6)||\
                                    ((Type) == GDMA_Handshake_TIM1_CH7)||\
                                    ((Type) == GDMA_Handshake_TIM1_CH8)||\
                                    ((Type) == GDMA_Handshake_TIM1_CH9)||\
                                    ((Type) == GDMA_Handshake_SPIC1_TX)||\
                                    ((Type) == GDMA_Handshake_SPIC1_RX)||\
                                    ((Type) == GDMA_Handshake_SPIC2_TX)||\
                                    ((Type) == GDMA_Handshake_SPIC2_RX)||\
                                    ((Type) == GDMA_Handshake_I2C2_TX)||\
                                    ((Type) == GDMA_Handshake_I2C2_RX)||\
                                    ((Type) == GDMA_Handshake_SPI2_TX)||\
                                    ((Type) == GDMA_Handshake_SPI2_RX)||\
                                    ((Type) == GDMA_Handshake_AUDIO_RX)||\
                                    ((Type) == GDMA_Handshake_TDM_2_RX)||\
                                    ((Type) == GDMA_Handshake_IDU_RX)||\
                                    ((Type) == GDMA_Handshake_IDU_TX)||\
                                    ((Type) == GDMA_Handshake_SM3)||\
                                    ((Type) == GDMA_Handshake_UART3_TX)||\
                                    ((Type) == GDMA_Handshake_UART3_RX)||\
                                    ((Type) == GDMA_Handshake_UART4_TX)||\
                                    ((Type) == GDMA_Handshake_UART4_RX)||\
                                    ((Type) == GDMA_Handshake_UART5_TX)||\
                                    ((Type) == GDMA_Handshake_UART5_RX)||\
                                    ((Type) == GDMA_Handshake_SPI_SLAVE_TX)||\
                                    ((Type) == GDMA_Handshake_SPI_SLAVE_RX)||\
                                    ((Type) == GDMA_Handshake_CANBUS1_RX)||\
                                    ((Type) == GDMA_Handshake_TIM1_CH6_TRX)||\
                                    ((Type) == GDMA_Handshake_IR_TX)||\
                                    ((Type) == GDMA_Handshake_IR_RX)||\
                                    ((Type) == GDMA_Handshake_CANBUS2_RX)||\
                                    ((Type) == GDMA_Handshake_SPIC3_TX)||\
                                    ((Type) == GDMA_Handshake_SPIC3_RX)||\
                                    ((Type) == GDMA_Handshake_TIM1_CH7_TRX)||\
                                    ((Type) == GDMA_Handshake_TIM1_CH8_TRX)||\
                                    ((Type) == GDMA_Handshake_TIM1_CH9_TRX)||\
                                   )    //!< Check whether is the GDMA handshake.


    /** End of Group 87x3g_GDMA_Handshake_Type
      * @}
      */
    /** End of Group 87x3g_GDMA_Exported_Constants
      * @}
      */
    /** @} */ /* End of group 87x3g_GDMA */

    /**
     * \brief    GDMA Macro Wrapper
     *
     * \ingroup  GDMA_Exported_Constants
     */
#define GDMA_Source_Cir_Gather_Num  GDMA_GatherCircularStreamingNum
#define GDMA_Dest_Cir_Sca_Num       GDMA_ScatterCircularStreamingNum

#ifdef  __cplusplus
}
#endif /* __cplusplus */
#endif /* RTL_GDMA_DEF_H */

