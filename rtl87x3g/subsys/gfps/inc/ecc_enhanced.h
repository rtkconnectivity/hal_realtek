/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: LicenseRef-Realtek-5-Clause
 */

#ifndef _ECC_ENHANCED_
#define _ECC_ENHANCED_

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    ECC_CAUSE_SUCCESS           = 0x00,//ecdh_shared_secret_enhanced() run completed
    ECC_CAUSE_PENDING           = 0x01,//ecdh_shared_secret_enhanced() is running
    ECC_CAUSE_FAIL              = 0x02,//ecdh_shared_secret_enhanced() run fail
} T_ECC_CAUSE;

/**
 *@brief Compute a shared secret use ecdh.
 * Note: Because ECDH is time consuming, the function is piecewise executed.
 * After one phase is completed, an MSG(@ref IO_MSG_TYPE_ECC) will be sent to the app task.
 * After app task receive the msg(@ref IO_MSG_TYPE_ECC), it will execute the next phase.
 *@Input:
 *  public_key  - The public key of the remote party.
 *  private_Key - Your private key.
 *
 *@Output:
 *  secret - Will be filled in with the shared secret value.
 *
 * @Return ECC_CAUSE_SUCCESS if the shared secret was generated successfully, Both input and output parameters are with the
 * LSB first.
 */
T_ECC_CAUSE ecdh_shared_secret_enhanced(const uint8_t public_key[64],
                                        const uint8_t private_key[32],
                                        uint8_t secret[32]);

/**
 * @brief execute ecc sub procedure when needed.
 *
 * @return T_ECC_CAUSE
 */
T_ECC_CAUSE ecc_sub_proc(void);

/**
 * @brief enter ecdh test mode
 *
 */
void ecdh_enter_test_mode(void);

/**
 * @brief exit ecdh test mode
 *
 */
void ecdh_exit_test_mode(void);

void gfps_ecc_init_msg_queue(void *evt_queue, void *io_queue);
#ifdef __cplusplus
}
#endif

#endif /* _ECC_ENHANCED_ */
