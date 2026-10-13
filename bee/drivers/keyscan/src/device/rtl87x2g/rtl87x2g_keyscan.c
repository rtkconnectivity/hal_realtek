/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl_keyscan.h"
#include "rtl_rcc.h"
#include "app_section.h"

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  Store KEYSCAN register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the KEYSCAN peripheral.
  * \param  StoreBuf: Store buffer to store KEYSCAN register data.
  * \return None.
  */
RAM_FUNCTION
void KEYSCAN_DLPSEnter(void *PeriReg, void *StoreBuf)
{
    KEYSCANStoreReg_TypeDef *store_buf = (KEYSCANStoreReg_TypeDef *)StoreBuf;

    RCC_PeriphClockCmd(APBPeriph_KEYSCAN, APBPeriph_KEYSCAN_CLOCK, ENABLE);

    store_buf->keyscan_reg[KEYSCAN_DLPS_CLK_DIV] = KEYSCAN->KEYSCAN_CLK_DIV;         /* 0x00 */
    store_buf->keyscan_reg[KEYSCAN_DLPS_CONFIG1] = KEYSCAN->KEYSCAN_CONFIG1;         /* 0x04 */
    store_buf->keyscan_reg[KEYSCAN_DLPS_CONFIG2] = KEYSCAN->KEYSCAN_CONFIG2;         /* 0x08 */
    store_buf->keyscan_reg[KEYSCAN_DLPS_COLUMN_CONFIG] = KEYSCAN->KEYSCAN_COLUMN_CONFIG;   /* 0x0C */
    store_buf->keyscan_reg[KEYSCAN_DLPS_ROW_CONFIG] = KEYSCAN->KEYSCAN_ROW_CONFIG;      /* 0x10 */
    store_buf->keyscan_reg[KEYSCAN_DLPS_INT_MASK] = KEYSCAN->KEYSCAN_INT_MASK;        /* 0x18 */

    return;
}

/**
  * \brief  Restore KEYSCAN register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the KEYSCAN peripheral.
  * \param  StoreBuf: Restore buffer to restore KEYSCAN register data.
  * \return None
  */
RAM_FUNCTION
void KEYSCAN_DLPSExit(void *PeriReg, void *StoreBuf)
{
    KEYSCANStoreReg_TypeDef *store_buf = (KEYSCANStoreReg_TypeDef *)StoreBuf;

    RCC_PeriphClockCmd(APBPeriph_KEYSCAN, APBPeriph_KEYSCAN_CLOCK, ENABLE);

    /* Set FSM to idle state */
    KEYSCAN->KEYSCAN_CONFIG2 &= ~BIT31;
    KEYSCAN->KEYSCAN_CLK_DIV = store_buf->keyscan_reg[KEYSCAN_DLPS_CLK_DIV];
    KEYSCAN->KEYSCAN_CONFIG2 = (store_buf->keyscan_reg[KEYSCAN_DLPS_CONFIG2] & (~(BIT31)));
    KEYSCAN->KEYSCAN_CONFIG1 = store_buf->keyscan_reg[KEYSCAN_DLPS_CONFIG1];
    KEYSCAN->KEYSCAN_COLUMN_CONFIG = store_buf->keyscan_reg[KEYSCAN_DLPS_COLUMN_CONFIG];
    KEYSCAN->KEYSCAN_ROW_CONFIG = store_buf->keyscan_reg[KEYSCAN_DLPS_ROW_CONFIG];
    KEYSCAN->KEYSCAN_INT_MASK = store_buf->keyscan_reg[KEYSCAN_DLPS_INT_MASK];
    KEYSCAN->KEYSCAN_CONFIG2 |= (store_buf->keyscan_reg[KEYSCAN_DLPS_CONFIG2] & ((BIT31)));

    return;
}

