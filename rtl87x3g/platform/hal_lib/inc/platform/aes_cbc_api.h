/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */
/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef __AES_CBC_API_H_
#define __AES_CBC_API_H_

/*============================================================================*
 *                               Header Files
*============================================================================*/
#include <stdbool.h>
#include <stdint.h>

/** @defgroup  HAL_AES_CBC    AES CBC
    * @brief AES CBC.
    * @{
    */
/*============================================================================*
 *                              Variables
*============================================================================*/


/*============================================================================*
 *                              Functions
*============================================================================*/
/** @defgroup HAL_AES_CBC_EXPORTED_FUNCTIONS AES CBC Exported Functions
    * @brief
    * @{
    */
#ifdef __cplusplus
extern "C" {
#endif
/**
    * @brief  Encrypt the speicified plaintext by AES CBC mode with a 128-bit key.
    * @param  plaintext    Specify the plaintext to be encypted.
    * @param  key          Specify the 128-bit key to encrypt the plaintext.
    * @param  encrypted    Specify the output buffer to store the encrypted data.
    * @param  p_iv         Specify the initialization vector (IV) for AES CBC mode with 16 bytes.
    *                      If p_iv is NULL, IV will be initialized as 16 bytes of 0.
    * @param  data_word_len  Specify the word length of the data. The data length must be a multiple of 4.
    * @return Encryption result.
    * @retval true      Success.
    * @retval false     Fail.
    * @note   The least significant octet of encrypted data corresponds to encypted[0].
    *
    * <b>Example usage</b>
    * @code{.c}
    * void aes128_cbc_enc_test(void)
    * {
    *    uint32_t enc_byte_cnt; // Number of bytes to encrypt. It should be aligned by 16 bytes.
    *    uint8_t *p_plain_buf;  // Pointer to the buffer to store the plaintext.
    *    uint8_t *p_out_buf;    // Pointer to the buffer to store the encrypted data.
    *    uint8_t key[16];       // AES 128-bit key, 16 bytes.
    *    uint32_t *p_iv;        // Pointer to Initialization vector, it can be set as NULL, or pointer to 16 bytes iv value.
    *
    *    //Initialize enc_byte_cnt, p_plain_buf, p_out_buf, key, and p_iv here.
    *    // The size of encrypted data and the size of decrypted data are the same, and should be aligned by 16 bytes.
    *
    *     bool result = aes128_cbc_encrypt(p_plain_buf, key, p_out_buf, p_iv, enc_byte_cnt / 4);
    *     if (result) {
    *         // Handle successful encryption
    *     } else {
    *         // Handle encryption failure
    *     }
    *
    * }
    * @endcode
    */
bool aes128_cbc_encrypt(uint8_t *plaintext, const uint8_t key[16], uint8_t *encrypted,
                        uint32_t *p_iv, uint32_t data_word_len);
/**
    * @brief  Decrypt the speicified data by AES CBC mode with a 128-bit key.
    * @param  input    Specify the encypted data to be decypted.
    * @param  key      Specify the 128-bit key to decrypt the data.
    * @param  output   Specify the output buffer to store the plain data.
    * @param  p_iv     Specify the initialization vector (IV) for AES CBC mode with 16 bytes.
    *                  If p_iv is NULL, IV will be initialized as 16 bytes of 0.
    * @param  data_word_len  Specify the word length of the data. The data length must be a multiple of 4.
    * @return Decryption result.
    * @retval true      Success.
    * @retval false     Fail.
    * @note   The least significant octet of decrypted data corresponds to output[0].
    *
    * <b>Example usage</b>
    * @code{.c}
    * void aes128_cbc_dec_test(void)
    * {
    *    uint32_t dec_byte_cnt; // Number of bytes to decrypt. It should be aligned by 16 bytes.
    *    uint8_t *p_enc_buf;    // Pointer to the buffer with the encrypted data.
    *    uint8_t *p_out_buf;    // Pointer to the buffer to store the decrypted data.
    *    uint8_t key[16];       // AES 128-bit key, 16 bytes.
    *    uint32_t *p_iv;        // Pointer to Initialization vector, can be NULL or point to a 16-byte IV value.
    *
    *    // Initialize dec_byte_cnt, p_enc_buf, p_out_buf, key, and p_iv here.
    *    // The size of encrypted data and the size of decrypted data are the same, and should be aligned by 16 bytes.
    *
    *    bool result = aes128_cbc_decrypt(p_enc_buf, key, p_out_buf, p_iv, dec_byte_cnt / 4);
    *    if (result) {
    *        // Handle successful decryption
    *    } else {
    *        // Handle decryption failure
    *    }
    * }
    * @endcode
    */
bool aes128_cbc_decrypt(uint8_t *input, const uint8_t key[16], uint8_t *output, uint32_t *p_iv,
                        uint32_t data_word_len);
/**
    * @brief  Encrypt the speicified plaintext (MSB) by AES CBC mode with a 128-bit key.
    * @param  plaintext    Specify the plaintext (MSB) to be encypted.
    * @param  key          Specify the 128-bit key to encrypt the plaintext.
    * @param  encrypted    Specify the output buffer to store the encrypted data.
    * @param  p_iv         Specify the initialization vector (IV) for AES CBC mode with 16 bytes.
    *                      If p_iv is NULL, IV will be initialized as 16 bytes of 0.
    * @param  data_word_len  Specify the word length of the data. The data length must be a multiple of 4.
    * @return Encryption result.
    * @retval true      Success
    * @retval false     Fail.
    * @note   The most significant octet of encrypted data corresponds to encypted[0].
    *
    *
    * <b>Example usage</b>
    * @code{.c}
    * void aes128_cbc_enc_msb_test(void)
    * {
    *    uint32_t enc_byte_cnt;    // Number of bytes to encrypt. It should be aligned by 16 bytes.
    *    uint8_t *p_plain_msb_buf; // Pointer to the buffer storing the plaintext (MSB first).
    *    uint8_t *p_out_buf;       // Pointer to the buffer to store the encrypted data.
    *    uint8_t key[16];          // AES 128-bit key, 16 bytes.
    *    uint32_t *p_iv;           // Pointer to Initialization vector, can be NULL or point to a 16-byte IV value.
    *
    *    // Initialize enc_byte_cnt, p_plain_msb_buf, p_out_buf, key, and p_iv here.
    *    // The size of encrypted data and the size of decrypted data are the same, and should be aligned by 16 bytes.
    *
    *    bool result = aes128_cbc_encrypt_msb2lsb(p_plain_msb_buf, key, p_out_buf, p_iv, enc_byte_cnt / 4);
    *    if (result) {
    *        // Handle successful encryption
    *    } else {
    *        // Handle encryption failure
    *    }
    * }
    * @endcode
    */
bool aes128_cbc_encrypt_msb2lsb(uint8_t plaintext[16], const uint8_t key[16], uint8_t *encrypted,
                                uint32_t *p_iv, uint32_t data_word_len);

/**
    * @brief  Decrypt the speicified data (MSB) by AES CBC mode with a 128-bit key.
    * @param  input    Specify the encypted data (MSB) to be decypted.
    * @param  key      Specify the 128-bit key to decrypt the data.
    * @param  output   Specify the output buffer to store the plain data.
    * @param  p_iv     Specify the initialization vector (IV) for AES CBC mode with 16 bytes.
    *                  If p_iv is NULL, IV will be initialized as 16 bytes of 0.
    * @param  data_word_len  Specify the word length of the data. The data length must be a multiple of 4.
    * @return Decryption result.
    * @retval true      Success.
    * @retval false     Fail.
    * @note   The most significant octet of encrypted data corresponds to output[0].
    *
    * <b>Example usage</b>
    * @code{.c}
    * void aes128_cbc_dec_msb_test(void)
    * {
    *    uint32_t dec_byte_cnt;  // Number of bytes to decrypt. It should be aligned by 16 bytes.
    *    uint8_t *p_enc_msb_buf;  // Pointer to the buffer with the encrypted data (MSB first).
    *    uint8_t *p_out_buf;      // Pointer to the buffer to store the decrypted data.
    *    uint8_t key[16];         // AES 128-bit key, 16 bytes.
    *    uint32_t *p_iv;          // Pointer to Initialization vector, can be NULL or point to a 16-byte IV value.
    *
    *    // Initialize dec_byte_cnt, p_enc_msb_buf, p_out_buf, key, and p_iv here.
    *    // The size of encrypted data and the size of decrypted data are the same, and should be aligned by 16 bytes.
    *
    *    bool result = aes128_cbc_decrypt_msb2lsb(p_enc_msb_buf, key, p_out_buf, p_iv, dec_byte_cnt / 4);
    *    if (result) {
    *        // Handle successful decryption
    *    } else {
    *        // Handle decryption failure
    *    }
    * }
    * @endcode
    */
bool aes128_cbc_decrypt_msb2lsb(uint8_t *input, const uint8_t key[16], uint8_t *output,
                                uint32_t *p_iv, uint32_t data_word_len);

/**
    * @brief  Encrypt the speicified plaintext by AES CBC mode with a 256-bit key.
    * @param  plaintext    Specify the plaintext to be encypted.
    * @param  key          Specify the 256-bit key to encrypt the plaintext.
    * @param  encrypted    Specify the output buffer to store the encrypted data.
    * @param  p_iv         Specify the initialization vector (IV) for AES CBC mode with 16 bytes.
    * @param  data_word_len  Specify the word length of the data. The data length must be a multiple of 4.
    * @return Encryption result.
    * @retval true      Success.
    * @retval false     Fail.
    * @note   The least significant octet of encrypted data corresponds to encypted[0].
    *
    * <b>Example usage</b>
    * @code{.c}
    * void aes256_cbc_enc_test(void)
    * {
    *    uint32_t enc_byte_cnt;  // Number of bytes to encrypt. It should be aligned by 16 bytes.
    *    uint8_t *p_plain_buf;   // Pointer to the buffer to store the plaintext.
    *    uint8_t *p_out_buf;     // Pointer to the buffer to store the encrypted data.
    *    uint8_t key[32];        // AES 256-bit key, 32 bytes.
    *    uint32_t *p_iv;         // Pointer to Initialization vector, can be NULL or point to a 16-byte IV value.
    *
    *    // Initialize enc_byte_cnt, p_plain_buf, p_out_buf, key, and p_iv here.
    *    // The size of encrypted data and the size of decrypted data are the same, and should be aligned by 16 bytes.
    *
    *    bool result = aes256_cbc_encrypt(p_plain_buf, key, p_out_buf, p_iv, enc_byte_cnt / 4);
    *    if (result) {
    *        // Handle successful encryption
    *    } else {
    *        // Handle encryption failure
    *    }
    * }
    * @endcode
    */
bool aes256_cbc_encrypt(uint8_t *plaintext, const uint8_t key[32], uint8_t *encrypted,
                        uint32_t *p_iv, uint32_t data_word_len);

/**
    * @brief  Decrypt the speicified data by AES CBC mode with a 256-bit key.
    * @param  input    Specify the encypted data to be decypted.
    * @param  key      Specify the 256-bit key to decrypt the data.
    * @param  output   Specify the output buffer to store the plain data.
    * @param  p_iv     Specify the initialization vector (IV) for AES CBC mode with 16 bytes.
    * @param  data_word_len  Specify the word length of the data. The data length must be a multiple of 4.
    * @return Decryption result.
    * @retval true      Success.
    * @retval false     Fail.
    * @note   The least significant octet of decrypted data corresponds to output[0].
    *
    * <b>Example usage</b>
    * @code{.c}
    * void aes256_cbc_dec_test(void)
    * {
    *    uint32_t dec_byte_cnt;  // Number of bytes to decrypt. It should be aligned by 16 bytes.
    *    uint8_t *p_enc_buf;     // Pointer to the buffer with the encrypted data.
    *    uint8_t *p_out_buf;     // Pointer to the buffer to store the decrypted data.
    *    uint8_t key[32];        // AES 256-bit key, 32 bytes.
    *    uint32_t *p_iv;         // Pointer to Initialization vector, can be NULL or point to a 16-byte IV value.
    *
    *    // Initialize dec_byte_cnt, p_enc_buf, p_out_buf, key, and p_iv here.
    *    // The size of encrypted data and the size of decrypted data are the same, and should be aligned by 16 bytes.
    *
    *    bool result = aes256_cbc_decrypt(p_enc_buf, key, p_out_buf, p_iv, dec_byte_cnt / 4);
    *    if (result) {
    *        // Handle successful decryption
    *    } else {
    *        // Handle decryption failure
    *    }
    * }
    * @endcode
    */
bool aes256_cbc_decrypt(uint8_t *input, const uint8_t key[32], uint8_t *output, uint32_t *p_iv,
                        uint32_t data_word_len);
/**
    * @brief  It's called when the decryption for AES CBC mode by DMA with 128-bit key has finished.
    * \xrefitem Experimental_Added_API_2_14_0_0 "Experimental Added Since 2.14.0.0" "Added API"
    * @param  parameter Specify the HW AES callback parameter.
    * @note RX DMA channel and TX DMA channel are released in this function.
    *
    * <b>Example usage</b>
    * @code{.c}
    * //aes128_cbc_dma_done_cb is used as the cback parameter for aes128_cbc_decrypt_by_dma function.
    * void aes128_cbc_dma_done_cb(void *parameter)
    * {
    *     aes128_cbc_dma_done((uint32_t)parameter);
    *     // do other things when aes dma done
    * }
    * @endcode
    */
void aes128_cbc_dma_done(uint32_t parameter);
/**
    * @brief  Decrypt data by AES CBC DMA mode with 128-bit key.
    * \xrefitem Experimental_Added_API_2_14_0_0 "Experimental Added Since 2.14.0.0" "Added API"
    * @param  input     Specify the source address of the data to be decypted.
    * @param  output    Specify the output buffer to store the plain data.
    * @param  data_word_len  Specify the word length of the data. The data length must be a multiple of 4.
    * @param  key       Specify the 128-bit key to decrypt the data.
    * @param  p_iv      Specify the initialization vector (IV) for AES CBC mode.
    * @param  cback     Register the callback function when the total AES DMA operation has been finished.
    * @return The AES CBC decryption result by DMA mode.
    * @retval true      Success.
    * @retval false     Fail.
    * @note   The RX DMA channel and TX DMA channel are requested and used by HW AES DMA operation.
    *         The RX DMA channel and TX DMA channel should be released in the HW AES DMA done callback.
    *
    * <b>Example usage</b>
    * @code{.c}
    * void aes128_cbc_dma_done_cb(void *parameter)
    * {
    *     aes128_cbc_dma_done((uint32_t)parameter);
    *     // do other things when aes dma done
    * }
    * bool test_aes128_cbc_decrypt_by_dma(void)
    * {
    *     uint32_t input_decrypt_addr; //Specify the data address to decrypt. It can be nor flash address or ram address.
    *     uint32_t dec_data_size;  //Number of bytes to decrypt. It should be aligned by 16 bytes.
    *     uint8_t key[16];         // AES 128-bit key, 16 bytes.
    *     uint32_t *p_iv;          // Pointer to Initialization vector, can be NULL or point to a 16-byte IV value.
    *     uint32_t *p_out_buf;     // Pointer to the buffer to store the decrypted data.
    *
    *     // Initialize input_decrypt_addr, dec_data_size, p_out_buf, key, and p_iv here.
    *
    *     bool ret = aes128_cbc_decrypt_by_dma((uint32_t *)input_decrypt_addr,
    *                                          (uint32_t *)p_out_buf,
    *                                          (dec_data_size >> 2),
    *                                          (uint8_t *)key, p_iv,
    *                                          aes128_cbc_dma_done_cb);
    *     if (ret) {
    *        // Handle successful decryption
    *     } else {
    *        // Handle decryption failure
    *     }
    * }
    * @endcode
    */
bool aes128_cbc_decrypt_by_dma(uint32_t *input, uint32_t *output, uint32_t data_word_len,
                               const uint8_t key[16], uint32_t *p_iv,
                               void (*cback)(void *));

#ifdef __cplusplus
}
#endif  // __cplusplus
/** @} */ /* End of group HAL_AES_CBC_EXPORTED_FUNCTIONS */
/** @} */ /* End of group HAL_AES_CBC */
#endif //__AES_CBC_API_H_
