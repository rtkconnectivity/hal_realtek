/**
*****************************************************************************************
*               Copyright(c) 2005, Colin Percival. All rights reserved.
*****************************************************************************************
   * @file      sha256.h
   * @brief     APIs for using SHA256
   **************************************************************************************
   * @attention
   * Redistribution and use in source and binary forms, with or without
   * modification, are permitted provided that the following conditions
   * are met:
   * 1. Redistributions of source code must retain the above copyright
   *    notice, this list of conditions and the following disclaimer.
   * 2. Redistributions in binary form must reproduce the above copyright
   *    notice, this list of conditions and the following disclaimer in the
   *    documentation and/or other materials provided with the distribution.
   *
   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
   * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
   * SUCH DAMAGE.
   *
   * $FreeBSD$
   **************************************************************************************
  */

/*============================================================================*
 *                      Define to prevent recursive inclusion
 *============================================================================*/
#ifndef _SHA256_H_
#define _SHA256_H_

#ifdef __cplusplus
extern "C" {
#endif
#include "stdbool.h"
/*============================================================================*
 *                              Header Files
 *============================================================================*/
#include <stdint.h>


/** @defgroup  SHA256_API Sha256
    * @brief APIs for using SHA256
    * @{
    */

/*============================================================================*
 *                              Macros
 *============================================================================*/
/** @defgroup SHA256_API_Exported_Macros SHA256 APIs Exported Macros
    * @{
    */

#define SHA256_BLOCK_LENGTH         64
#define SHA256_DIGEST_LENGTH        32
#define SHA256_DIGEST_STRING_LENGTH (SHA256_DIGEST_LENGTH * 2 + 1)

/** End of SHA256_API_Exported_Macros
    * @}
    */

/*============================================================================*
 *                              Types
 *============================================================================*/
/** @defgroup SHA256_API_Exported_Types SHA256 APIs Exported Types
    * @{
    */

/**  @brief Context structure to store SHA256 algorithm intermediate information */
typedef struct SHA256Context
{
    uint32_t state[8];
    uint64_t count;
    uint8_t buf[SHA256_BLOCK_LENGTH];
} SHA256_CTX;

/** End of SHA256_API_Exported_Types
    * @}
    */

/*============================================================================*
 *                              Functions
 *============================================================================*/
/** @defgroup SHA256_API_Exported_Functions SHA256 APIs Exported Functions
    * @brief
    * @{
    */

/**
    * @brief    SHA-256 initialization, begins a SHA-256 operation.
    * @param    ctx     A context pointer used to store algorithm information
    * @return   void
    *
    * <b>Example usage</b>
    * @code{.c}
    * void init_sha256(void)
    * {
    *     SHA256_CTX ctx = {0};
    *     SHA256_Init(&ctx);
    * }
    *
    * @endcode
    */
extern void SHA256_Init(SHA256_CTX *ctx);

/**
    * @brief    Add bytes into the hash.
    * @note     This is called to input the source data, and can be called several times to load
    *           a large amount of data sequentially.
    * @param    ctx     A context pointer used to store algorithm information
    * @param    in      A pointer which point to the array of the source data
    * @param    len     Length of input data, shouldn't be larger than the length of the 'in' array.
    * @return   void
    *
    * <b>Example usage</b>
    * @code{.c}
    * void update_sha256(const void *in, size_t len)
    * {
    *     SHA256_CTX ctx = {0};
    *     SHA256_Init(&ctx);
    *
    *     SHA256_Update(&ctx, in, len);
    * }
    *
    * @endcode
    */
extern void SHA256_Update(SHA256_CTX *ctx, const void *in, size_t len);

/**
    * @brief    SHA-256 finalization, called to retrieve the final calculating result.
                It pads the input data, exports the hash value, and clears the context state.
    * @note     The result is output to an array named 'digest', and the array length is
    *           fixed to 32, which replaces by an understandable macro SHA256_DIGEST_LENGTH.
    * @param    ctx     A context pointer used to store algorithm information
    * @param    digest  A pointer which point to the array storing calculating result data
    * @return   void
    *
    * <b>Example usage</b>
    * @code{.c}
    * void calc_sha256(void)
    * {
    *     void *in_buf_1;
    *     size_t len_1;
    *     void *in_buf_2;
    *     size_t len_2;
    *     uint8_t sha_output[32];
    *
    *     //Initialize in_buf_1,len_1,in_buf_2,len_2.
    *
    *     SHA256_CTX ctx = {0};
    *     SHA256_Init(&ctx);
    *
    *     SHA256_Update(&ctx, in_buf_1, len_1);
    *     SHA256_Update(&ctx, in_buf_2, len_2);
    *
    *     SHA256_Final(&ctx, sha_output);
    * }
    *
    * @endcode
    */
extern void SHA256_Final(SHA256_CTX *ctx, unsigned char digest[SHA256_DIGEST_LENGTH]);
/**
    * @brief    Alloc the memory for SHA-256 context.
    *           If the allocation success, init the SHA256 context.
    * @param    ctx     A context pointer used to store algorithm information.
    * @return   void
    */
extern bool SHA256_Alloc(SHA256_CTX **ctx);
/**
    * @brief    Free the memory for SHA-256 context.
    * @param    ctx     A context pointer used to store algorithm information.
    * @return   void
    */
extern void SHA256_Free(SHA256_CTX *ctx);
/**
    * @brief    Calculate SHA256 hash of the input data.
    * @param[in]     in      A pointer which points to the array of the source data.
    * @param[in]     len     The length of the input data.
    * @param[out]    result  A pointer which points to the SHA256 result buffer, and
    *                        the result is 32 bytes.
    * @return   void
    *
    * <b>Example usage</b>
    * @code{.c}
    * void calc_sha256(void)
    * {
    *     uint8_t sha_output[32];
    *     void *in;              // Pointer to the input buffer.
    *     size_t len;            // Specify the input buffer length.
    *     //Initialize in and len.
    *
    *     SHA256(in, len, sha_output);
    * }
    *
    * @endcode
    */
extern void SHA256(const void *in, size_t len, uint8_t *result);

/** End of SHA256_API_Exported_Functions
    * @}
    */


/** End of SHA256_API
    * @}
    */


#ifdef __cplusplus
}
#endif

#endif /* !_SHA256_H_ */
