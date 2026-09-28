/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: LicenseRef-Realtek-5-Clause
 */
#ifndef __USBH_AUDIO_DRIVER_H__
#define __USBH_AUDIO_DRIVER_H__
#include <stdint.h>
#include <stdbool.h>
#include "usb_audio1_spec.h"

#define USBH_AUDIO_DIR_OUT   0   /* Host to Device (playback) */
#define USBH_AUDIO_DIR_IN    1   /* Device to Host (recording) */

#define USBH_AUDIO_MAX_FORMATS   32   /* max alt-settings per direction */

/**
 * \brief Per-packet descriptor for one ISO transfer packet.
 * Mirrors T_HAL_USBH_ISO_PKT_INFO; defined independently to avoid
 * exposing hal_usbh.h to application code.
 */
typedef struct
{
    uint32_t offset;
    uint32_t length;
    uint32_t actual;
    int      status;
} T_USBH_AUDIO_PKT_INFO;

/**
 * \brief Supported audio format (one per UAC1 alternate setting)
 */
typedef struct
{
    uint8_t  nr_channels;
    uint8_t  subframe_size;   /* bytes per sample: 1=8-bit, 2=16-bit, 3=24-bit */
    uint8_t  bit_resolution;
    uint32_t sample_freq;     /* Hz */
} T_USBH_AUDIO_FORMAT;

/**
 * \brief ISO stream data callback (called from ISR context)
 * \param dir       USBH_AUDIO_DIR_OUT or USBH_AUDIO_DIR_IN
 * \param buf       base address of the completed ping-pong buffer
 * \param pkt_info  per-packet descriptor array (pkt_cnt entries)
 * \param pkt_cnt   number of ISO packets in this buffer interval
 * \param priv      user private pointer
 * \return 0 on success
 */
typedef int (*USBH_AUDIO_STREAM_CB)(uint8_t dir,
                                    uint8_t *buf,
                                    T_USBH_AUDIO_PKT_INFO *pkt_info,
                                    uint8_t pkt_cnt,
                                    void *priv);

/**
 * \brief UAC-agnostic volume attribute (1/256 dB units).
 *        Compatible with both UAC1 and UAC2 volume controls.
 */
typedef struct
{
    int16_t cur;   /**< Current volume in 1/256 dB */
    int16_t min;   /**< Minimum volume */
    int16_t max;   /**< Maximum volume */
    int16_t res;   /**< Step resolution (0 = device does not report) */
} T_USBH_AUDIO_VOL_ATTR;

/**
 * \brief Mute state.
 */
typedef struct
{
    bool state;    /**< true = muted, false = unmuted */
} T_USBH_AUDIO_MUTE_ATTR;

/**
 * \brief Asynchronous completion event IDs for the unified event callback.
 */
typedef enum
{
    USBH_AUDIO_EVT_VOLUME_GET  = 0,   /**< volume_get completed */
    USBH_AUDIO_EVT_VOLUME_SET,        /**< volume_set completed */
    USBH_AUDIO_EVT_MUTE_GET,          /**< mute_get completed */
    USBH_AUDIO_EVT_MUTE_SET,          /**< mute_set completed */
    USBH_AUDIO_EVT_STREAM_START,      /**< stream_start async chain done */
    USBH_AUDIO_EVT_STREAM_STOP,       /**< stream_stop async chain done */
} T_USBH_AUDIO_EVT;

/**
 * \brief Event parameter carrying typed result data.
 *        Only the union field corresponding to evt is valid:
 *          VOLUME_GET  -> param.volume
 *          MUTE_GET    -> param.mute
 *          others      -> status only (union unused)
 */
typedef struct
{
    int      status;    /**< 0 on success, negative on error */
    uint8_t  dir;       /**< USBH_AUDIO_DIR_OUT or USBH_AUDIO_DIR_IN */
    uint8_t  ch;        /**< channel (0=master); for volume ops */
    union
    {
        T_USBH_AUDIO_VOL_ATTR  volume;  /**< [VOLUME_GET] volume attrs */
        T_USBH_AUDIO_MUTE_ATTR mute;    /**< [MUTE_GET] mute state */
    };
} T_USBH_AUDIO_EVT_PARAM;

/**
 * \brief Unified completion callback for all async operations.
 * Replaces USBH_AUDIO_CTRL_CB / VOL_GET_CB / MUTE_GET_CB.
 * \param evt    event type identifying the completed operation
 * \param param  event payload (status + typed data)
 * \param priv   user private pointer from register call
 */
typedef void (*USBH_AUDIO_EVT_CB)(T_USBH_AUDIO_EVT evt,
                                  const T_USBH_AUDIO_EVT_PARAM *param,
                                  void *priv);

/**
 * \brief Initialize the USB host audio class driver and register it.
 * Must be called before usbh_mgr_start().
 */
int usbh_audio_driver_init(void);

/**
 * \brief Get supported formats for a direction (valid after mount).
 * \param dir     USBH_AUDIO_DIR_OUT or USBH_AUDIO_DIR_IN
 * \param formats output array, caller provides USBH_AUDIO_MAX_FORMATS entries
 * \param count   output: number of formats filled
 */
int usbh_audio_driver_formats_get(uint8_t dir, T_USBH_AUDIO_FORMAT *formats,
                                  uint8_t *count);

/**
 * \brief Start ISO streaming on the given direction.
 * \param dir              USBH_AUDIO_DIR_OUT or USBH_AUDIO_DIR_IN
 * \param fmt              format to use (must come from usbh_audio_driver_formats_get)
 * \param buf_proc_intrvl  frames per ping-pong buffer (e.g. 10 = 10 ms)
 * \param cb               stream data callback (called in ISR)
 * \param priv             passed through to cb
 * \return 0 on success, -EBUSY if stream already active, -ENOENT if format
 *         not found, negative on other error
 */
int usbh_audio_driver_stream_start(uint8_t dir, T_USBH_AUDIO_FORMAT *fmt,
                                   uint32_t buf_proc_intrvl,
                                   USBH_AUDIO_STREAM_CB cb, void *priv);

/**
 * \brief Stop ISO streaming. Issues SET_INTERFACE back to alt 0.
 * \return 0 on success, -EBUSY if start chain still in flight,
 *         negative on other error
 */
int usbh_audio_driver_stream_stop(uint8_t dir);

/*
 * Async Feature Unit control API (volume / mute, get / set).
 *
 * All four calls share a single device control channel (EP0).  Each call
 * appends a logical operation to an internal FIFO and returns immediately;
 * the operations execute one at a time and results are reported through the
 * unified event callback registered via
 * usbh_audio_driver_evt_cb_register().
 *
 * A full queue returns -ENOSPC.  If the requested direction has no Feature
 * Unit, the event callback fires with -ENODEV.
 */

/**
 * \brief Register the unified async completion callback.
 * \param cb    event callback (NULL to deregister)
 * \param priv  passed through to every callback invocation
 */
void usbh_audio_driver_evt_cb_register(USBH_AUDIO_EVT_CB cb, void *priv);

/**
 * \brief Query Feature Unit volume range and current value (async).
 *        Result reported via USBH_AUDIO_EVT_VOLUME_GET.
 * \param dir   USBH_AUDIO_DIR_OUT or USBH_AUDIO_DIR_IN
 * \param ch    channel: 0=master, 1=left, 2=right
 * \return 0 if queued, -ENOSPC if the control queue is full, negative on
 *         other immediate error
 */
int usbh_audio_driver_volume_get(uint8_t dir, uint8_t ch);

/**
 * \brief Set Feature Unit volume (async).
 *        Result reported via USBH_AUDIO_EVT_VOLUME_SET.
 * \param dir       USBH_AUDIO_DIR_OUT or USBH_AUDIO_DIR_IN
 * \param ch        channel: 0=master, 1=left, 2=right
 * \param vol_db256 volume in 1/256 dB units (e.g. -1024 = -4.0 dB)
 * \return 0 if queued, -ENOSPC if the control queue is full, negative on
 *         other immediate error
 */
int usbh_audio_driver_volume_set(uint8_t dir, uint8_t ch, int16_t vol_db256);

/**
 * \brief Get mute state (async).
 *        Result reported via USBH_AUDIO_EVT_MUTE_GET.
 * \param dir  USBH_AUDIO_DIR_OUT or USBH_AUDIO_DIR_IN
 * \return 0 if queued, -ENOSPC if the control queue is full, negative on
 *         other immediate error
 */
int usbh_audio_driver_mute_get(uint8_t dir);

/**
 * \brief Set mute state (async).
 *        Result reported via USBH_AUDIO_EVT_MUTE_SET.
 * \param dir  USBH_AUDIO_DIR_OUT or USBH_AUDIO_DIR_IN
 * \param mute true = muted, false = unmuted
 * \return 0 if queued, -ENOSPC if the control queue is full, negative on
 *         other immediate error
 */
int usbh_audio_driver_mute_set(uint8_t dir, bool mute);

#endif /* __USBH_AUDIO_DRIVER_H__ */
