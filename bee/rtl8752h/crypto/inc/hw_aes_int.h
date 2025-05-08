/**
*****************************************************************************************
*     Copyright(c) 2017, Realtek Semiconductor Corporation. All rights reserved.
*****************************************************************************************
   * @file      hw_aes_int.h
   * @brief     hw aes header file for internal project
   * @details
   * @author
   * @date
   * @version
   **************************************************************************************
   * @attention
   * <h2><center>&copy; COPYRIGHT 2017 Realtek Semiconductor Corporation</center></h2>
   * *************************************************************************************
  */

/*============================================================================*
  *                   Define to prevent recursive inclusion
  *============================================================================*/
#ifndef _HW_AES_INT_H
#define _HW_AES_INT_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
  *                               Header Files
  *============================================================================*/
#include "hw_aes.h"
// #include "efuse_table.h"
#include "rtl876x_hw_aes.h"

#define SHARE_CACHE_RAM_0_BLOCK          0x82F70000
#define SHARE_CACHE_RAM_1_BLOCK          0x2F2D0002
#define SHARE_CACHE_RAM_2_BLOCKS         0xA2AA0003
/*============================================================================*
  *                                   Types
  *============================================================================*/
typedef union
{
    uint32_t cfg;
    struct
    {
        uint32_t work_mode:         8;
        uint32_t is_aes256:         1;
        uint32_t is_encrypt:        1;
        uint32_t use_dma:           1;
        uint32_t rsvd:              5;
        uint32_t dma_channel_in:    8;
        uint32_t dma_channel_out:   8;
    } cfg_bits;
} THw_AesConfig;
/*============================================================================*
  *                                Functions
  *============================================================================*/
bool hw_aes_encrypt128(uint32_t *p_in, uint32_t *p_out, uint16_t data_word_len, uint32_t *p_key,
                       uint32_t *p_iv,
                       T_HW_AES_MODE mode);
bool hw_aes_decrypt128(uint32_t *p_in, uint32_t *p_out, uint16_t data_word_len, uint32_t *p_key,
                       uint32_t *p_iv,
                       T_HW_AES_MODE mode);
bool hw_aes_encrypt256(uint32_t *p_in, uint32_t *p_out, uint16_t data_word_len, uint32_t *p_key,
                       uint32_t *p_iv,
                       T_HW_AES_MODE mode);
bool hw_aes_decrypt256(uint32_t *p_in, uint32_t *p_out, uint16_t data_word_len, uint32_t *p_key,
                       uint32_t *p_iv,
                       T_HW_AES_MODE mode);

bool hw_aes_create_mutex(void);
bool hw_aes_decrypt_code_init_slim(const uint32_t *aes_key, bool is_aes256);
#if (CALCULATE_HASH_TEST != 0)
uint32_t get_secure_reg_cfg_val(uint32_t in_val);
#endif

#ifdef __cplusplus
}
#endif

#endif
