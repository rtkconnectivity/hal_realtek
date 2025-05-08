/**
*********************************************************************************************************
*               Copyright(c) 2018, Realtek Semiconductor Corporation. All rights reserved.
*********************************************************************************************************
* @file      rtl876x_hw_sha256.h
* @brief
* @details
* @author    eason li
* @date      2018-09-04
* @version   v0.1
* *********************************************************************************************************
*/

#ifndef __RTL876X_HW_SHA256_H
#define __RTL876X_HW_SHA256_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdbool.h>
#include "rtl876x.h"

typedef enum
{
    HW_SHA256_CPU_MODE,
    HW_SHA256_DMA_MODE
} HW_SHA256_ACCESS_MODE;

typedef struct
{
    uint32_t total[2];          /*!< The number of Bytes processed.  */
    uint32_t state[8];          /*!< The intermediate digest state.  */
    uint8_t buffer[64];         /*!< The data block being processed. */
    int is224;                  /*!< unused, just align mbedtls structure */
} HW_SHA256_CTX;


extern bool (*hw_sha256_cpu_mode)(HW_SHA256_CTX *ctx, uint8_t *input, uint32_t byte_len,
                                  uint32_t *result);
extern bool (*hw_sha256_dma_update)(HW_SHA256_CTX *ctx, uint8_t *input, uint32_t byte_len,
                                    uint8_t dma_tx_ch_num);
extern bool (*hw_sha256_dma_mode)(HW_SHA256_CTX *ctx, uint8_t *input, uint32_t byte_len,
                                  uint32_t *result, uint8_t dma_rx_ch_num);

extern bool (*hw_sha256)(uint8_t *input, uint32_t byte_len, uint32_t *result, int mode);
extern void (*hw_sha256_start)(HW_SHA256_CTX *ctx, uint32_t *iv);
extern bool (*hw_sha256_cpu_update)(HW_SHA256_CTX *ctx, uint8_t *input, uint32_t byte_len);
extern bool (*hw_sha256_finish)(HW_SHA256_CTX *ctx, uint32_t *result);
void hw_sha256_init(void);
void hw_sha256_set_dma_move_src(uint32_t src);
void hw_sha256_set_dma_buf_size(uint32_t size);
bool hw_sha256_dma_done(void);

#ifdef __cplusplus
}
#endif
#endif /*__RTL876X_HW_SHA256_H*/
