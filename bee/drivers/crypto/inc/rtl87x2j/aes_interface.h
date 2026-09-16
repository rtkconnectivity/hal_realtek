/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: LicenseRef-Realtek-5-Clause
 */

#ifndef __AES_INTERFACE_H
#define __AES_INTERFACE_H
// *INDENT-OFF*
#ifdef __cplusplus
extern "C" {
#endif
/* Includes ------------------------------------------------------------------*/
#include <stdbool.h>
#include <stdint.h>
#include "aes_dma_types.h"

#define AES_SUPPORT_DMA_MODE    1
#define AES_SUPPORT_CMAC        1

typedef enum
{
    AES_NONE,
    AES_CBC = 0x1,
    AES_ECB = 0x2,
    AES_CFB = 0x3,
    AES_OFB = 0x4,
    AES_CTR_IV_64BITS_MSB = 0x5,
    AES_CTR_IV_96BITS_MSB = 0x15,
    AES_CTR_IV_64BITS_LSB = 0x25,
    AES_CTR_IV_96BITS_LSB = 0x35,
    AES_CIPHER_MAC = 0x6,
} AES_WORK_MODE;

typedef enum
{
    AES_KEY_IRK = 0,
    AES_KEY2 = 1,
    AES_KEY3 = 2,
    AES_KEY4 = 3,
    AES_KEY5 = 4,
    AES_HIDDEN_KEY,
    AES_KEY_MAX,
} AES_KEY_SEL;

typedef enum
{
    AES_KEY_BITS_128 = 128,
    AES_KEY_BITS_256 = 256,
} AES_KEY_BITS_SEL;

typedef struct
{
    uint32_t *key;
    AES_KEY_BITS_SEL key_bits;
    AES_KEY_SEL key_sel;
} AES_KEY_CFG;

typedef enum
{
    AES_CPU_MODE = 0,
    AES_DMA_MODE = 1,
} AES_ACCESS_MODE;

typedef struct
{
    uint32_t *input;
    uint32_t *iv;
    uint32_t byte_len;
    AES_WORK_MODE aes_mode;
    AES_ACCESS_MODE access_mode;
#if AES_SUPPORT_DMA_MODE == 1
    AES_DMA_CFG *dma_rx_cfg;
    AES_DMA_CFG *dma_tx_cfg;
#endif
} AES_CFG;

void aes_init(AES_WORK_MODE aes_mode, const uint32_t *iv, AES_KEY_CFG *key_cfg);
bool aes_cpu_operate(const uint32_t *in, uint32_t *out, uint32_t word_len, bool isEncrypt);
bool aes_encrypt(AES_CFG *aes_config, AES_KEY_CFG *key_cfg, uint32_t *ciphertext);
bool aes_decrypt(AES_CFG *aes_config, AES_KEY_CFG *key_cfg, uint32_t *plaintext);

#if AES_SUPPORT_DMA_MODE == 1
void aes_dma_channel_init(AES_DMA_CFG *rx_cfg, AES_DMA_CFG *tx_cfg);
bool aes_dma_operate(const uint32_t *in, uint32_t *out, uint32_t word_len, bool isEncrypt);
bool aes_dma_done(void);
#endif

#if AES_SUPPORT_CMAC == 1
typedef struct
{
    uint8_t *input;
    uint32_t byte_len;
    AES_ACCESS_MODE access_mode;
    AES_DMA_CFG *dma_rx_cfg;
} AES_CMAC_CFG;

bool aes_cmac(AES_CMAC_CFG *cmac_config, AES_KEY_CFG *key_cfg, uint32_t *cmac);
#endif

#ifdef __cplusplus
}
#endif
#endif /*__AES_INTERFACE_H*/
