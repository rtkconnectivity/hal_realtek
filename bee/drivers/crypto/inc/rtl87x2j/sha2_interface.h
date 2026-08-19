/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: LicenseRef-Realtek-5-Clause
 */

#ifndef __SHA2_INTERFACE_H
#define __SHA2_INTERFACE_H
// *INDENT-OFF*
#ifdef __cplusplus
extern "C" {
#endif
/* Includes ------------------------------------------------------------------*/
#include <stdbool.h>
#include <stdint.h>

#define SHA2_SUPPORT_DMA_MODE       1
#define SHA2_DMA_CH_NUM             2U

typedef enum
{
    SHA2_DMA_MODE = 0,
    SHA2_CPU_MODE = 1,
} SHA2_ACCESS_MODE;

typedef enum
{
    SHA2_224,
    SHA2_256,
    SHA2_ALGO_MAX,
} SHA2_ALGO;

typedef struct
{
    uint32_t total[2];
    uint32_t state[8];
    uint8_t buffer[64];
    SHA2_ALGO algo;
} SHA2_CTX;

typedef struct
{
    uint8_t *input;
    uint32_t byte_len;
    SHA2_ALGO algo;
    SHA2_ACCESS_MODE access_mode;
    uint8_t dma_ch_num;
} SHA2_CFG;

void sha2_init(void);
void sha2_start(SHA2_CTX *ctx, SHA2_ALGO algo);
bool sha2_cpu_update(SHA2_CTX *ctx, const uint8_t *input, uint32_t byte_len);
bool sha2_cpu_finish(SHA2_CTX *ctx, uint32_t *output);
uint32_t sha2_get_digest_len(SHA2_ALGO algo);
void sha2_iv_init(SHA2_ALGO algo, uint32_t *iv);
void sha2_get_digest(SHA2_ALGO algo, uint32_t *output);

#if SHA2_SUPPORT_DMA_MODE == 1
void sha2_dma_channel_init(uint8_t dma_rx_ch_num);
bool sha2_dma_update(SHA2_CTX *ctx, const uint8_t *input, uint32_t byte_len);
bool sha2_dma_finish(SHA2_CTX *ctx, uint32_t *output);
#endif

bool sha2(SHA2_CFG *sha2_config, uint32_t *result);

#ifdef __cplusplus
}
#endif
#endif /*__SHA2_INTERFACE_H*/
