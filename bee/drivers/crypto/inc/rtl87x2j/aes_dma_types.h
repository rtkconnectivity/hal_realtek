/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: LicenseRef-Realtek-5-Clause
 */

#ifndef __AES_DMA_TYPES_H
#define __AES_DMA_TYPES_H

#include <stdint.h>

typedef void (*AES_DMA_CB)(void *);
typedef void (*AES_DMA_ISR)(void);

typedef struct AES_DMA_CFG
{
    uint8_t dma_ch_num;
    AES_DMA_ISR dma_isr;
    AES_DMA_CB cb;
    void *cb_param;
} AES_DMA_CFG;

#endif /* __AES_DMA_TYPES_H */
