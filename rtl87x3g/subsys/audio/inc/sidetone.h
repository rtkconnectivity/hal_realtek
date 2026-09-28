/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: LicenseRef-Realtek-5-Clause
 */

#ifndef _SIDETONE_H_
#define _SIDETONE_H_

#include <stdint.h>
#include <stdbool.h>

#include "audio_type.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * \defgroup AUDIO_SIDETONE Sidetone
 *
 * \brief   Control and customize the Sidetone engine in the Audio Subsystem.
 * \details Sidetone is the sound of the user voice captured by the microphone
 *          that is fed back into the earpiece. Sidetone gives indications to
 *          the user that the microphone is picking up the voice; the voice is
 *          loud enough or too low; and the voice connection is established or
 *          dropped.
 */

/**
 * \brief Define the supported Sidetone types.
 *
 * \ingroup AUDIO_SIDETONE
 */
typedef enum t_sidetone_type
{
    SIDETONE_TYPE_SW    = 0x00, /**< Software Sidetone engine type. */
    SIDETONE_TYPE_HW    = 0x01, /**< Hardware Sidetone engine type. */
} T_SIDETONE_TYPE;

/**
 * \brief   Create a Sidetone instance.
 *
 * \param[in] type       Sidetone type \ref T_SIDETONE_TYPE.
 * \param[in] gain       DAC digital gain value in (dB * 128) step unit.
 * \param[in] freq       Cutoff frequency.
 *
 * \return  The instance of the Sidetone engine. If returned instance is NULL, the
 *          Sidetone instance failed to create.
 *
 * \note    Only hardware sidetone allows to set the cutoff frequency manually, with supported values
 *          of 55Hz, 110Hz, 170Hz, 220Hz, 280Hz, 340Hz, 390Hz, and 450Hz. For software sidetone, the
 *          cutoff frequency is automatically determined by the internal Noise Reduction & Echo
 *          Canceling(NREC) module.
 *
 * \ingroup AUDIO_SIDETONE
 */
T_AUDIO_EFFECT_INSTANCE sidetone_create(T_SIDETONE_TYPE type,
                                        int16_t         gain,
                                        uint32_t        freq);

/**
 * \brief   Enable the specific Sidetone instance.
 *
 * \param[in] instance  The Sidetone engine session \ref AUDIO_SIDETONE.
 *
 * \return  The status of enabling the Sidetone instance.
 * \retval  true    The Sidetone instance was enabled successfully.
 * \retval  false   The Sidetone instance failed to enable.
 *
 * \ingroup AUDIO_SIDETONE
 */
bool sidetone_enable(T_AUDIO_EFFECT_INSTANCE instance);

/**
 * \brief   Disable the specific Sidetone instance.
 *
 * \param[in] instance  The Sidetone engine session \ref AUDIO_SIDETONE.
 *
 * \return  The status of disabling the Sidetone instance.
 * \retval  true    The Sidetone instance was disabled successfully.
 * \retval  false   The Sidetone instance failed to disable.
 *
 * \ingroup AUDIO_SIDETONE
 */
bool sidetone_disable(T_AUDIO_EFFECT_INSTANCE instance);

/**
 * \brief   Set the gain of the specific Sidetone instance.
 *
 *\param[in] instance  The Sidetone engine session \ref AUDIO_SIDETONE.
 *\param[in] gain      DAC digital gain value in dB unit.
 *
 * \return  The status of setting the gain.
 * \retval  true    The gain was set successfully.
 * \retval  false   The gain failed to set.
 *
 * \ingroup AUDIO_SIDETONE
 */
bool sidetone_gain_set(T_AUDIO_EFFECT_INSTANCE instance,
                       int16_t                 gain);

/**
 * \brief   Release the specific Sidetone instance.
 *
 * \param[in] instance  The Sidetone engine session \ref AUDIO_SIDETONE.
 *
 * \return  The status of releasing the Sidetone instance.
 * \retval  true    The Sidetone instance was released successfully.
 * \retval  false   The Sidetone instance failed to release.
 *
 * \ingroup AUDIO_SIDETONE
 */
bool sidetone_release(T_AUDIO_EFFECT_INSTANCE instance);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _SIDETONE_H_ */
