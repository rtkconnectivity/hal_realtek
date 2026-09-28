/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: LicenseRef-Realtek-5-Clause
 */
#ifndef __USBH_MGR_H__
#define __USBH_MGR_H__
#include <stdint.h>
#include "usbh_msc_driver.h"
#include "usbh_audio_driver.h"

/**
 * \addtogroup USBH_Mgr
 * \brief This module mainly provides components for implementing USB host manager.
 * @{
 */

/** \defgroup USBH_Mgr_Exported_Functions USB Host Manager Exported Types
  * @{
  */

typedef enum
{
    USBH_MGR_PORT_STATE_PDN,
    USBH_MGR_PORT_STATE_POWERED,
    USBH_MGR_PORT_STATE_DEV_ATTACHED,
    USBH_MGR_PORT_STATE_DEV_DETTACHED,
    USBH_MGR_PORT_STATE_DEV_RESET_DONE,
    USBH_MGR_PORT_STATE_DEV_ADDRESSED,
    USBH_MGR_PORT_STATE_DEV_CONFIGURED,
    USBH_MGR_PORT_STATE_SUSPENDED,
    USBH_MGR_PORT_STATE_RESUMED,
} T_USBH_MGR_PORT_STATE;

/**
 * \brief usb host manager event
 */
typedef enum
{
    USBH_MGR_EVT_PORT_STATE_CHANGED,
    USBH_MGR_EVT_DEV_INFO_INFORM,
} T_USBH_MGR_EVT;

#define USBH_AUDIO_DIR_CAP_OUT   (1 << USBH_AUDIO_DIR_OUT)
#define USBH_AUDIO_DIR_CAP_IN    (1 << USBH_AUDIO_DIR_IN)
#define USBH_AUDIO_DIR_CAP_BOTH  (USBH_AUDIO_DIR_CAP_OUT | USBH_AUDIO_DIR_CAP_IN)

/**
 * \brief usb host manager event mask
 */
typedef union
{
    uint32_t d32;

    struct
    {
        uint32_t port_sts_changed: 1;
        uint32_t dev_info_inform: 1;
        uint32_t rsv: 30;
    } b;

} T_USBH_MGR_EVT_MSK;

typedef struct _usbh_mgr_param_port_state
{
    T_USBH_MGR_PORT_STATE state;
    union
    {
        uint8_t speed;
    } info;
} T_USBH_MGR_PARAM_PORT_STATE;

typedef struct
{
    uint8_t             lun;
    T_USB_DISK_CAPACITY capacity;
} T_USBH_MGR_DEV_INFO_MSC;

typedef struct
{
    uint8_t             dir_cap;   /* bit0=OUT, bit1=IN; both=bidirectional */
    uint8_t             nr_formats_out;
    uint8_t             nr_formats_in;
    T_USBH_AUDIO_FORMAT formats_out[USBH_AUDIO_MAX_FORMATS];
    T_USBH_AUDIO_FORMAT formats_in[USBH_AUDIO_MAX_FORMATS];
} T_USBH_MGR_DEV_INFO_AUDIO;

/**
 * \brief usb host manager event parameter-device information
 * \param msc   pointer to MSC info (valid when class == USB_CLASS_MSC)
 * \param audio pointer to audio info (valid when class == AUDIO/AUDIOCONTROL)
 */
typedef struct _usbh_mgr_param_dev_info
{
    uint8_t class;
    uint8_t subclass;
    union
    {
        T_USBH_MGR_DEV_INFO_MSC   *msc;
        T_USBH_MGR_DEV_INFO_AUDIO *audio;
    };

} T_USBH_MGR_PARAM_DEV_INFO;

/**
 * \brief usb host manager event parameter
 * \param dev_info device information
 */
typedef union _usbh_mgr_evt_param
{
    T_USBH_MGR_PARAM_PORT_STATE port_state;
    T_USBH_MGR_PARAM_DEV_INFO dev_info;

} T_USBH_MGR_EVT_PARAM;

/**
 * \brief usb host manager callback
 * \param evt usb host manager event
 * \param param usb host manager event parameter
 * \return 0 success
 */
typedef int (*USBH_MGR_CB)(T_USBH_MGR_EVT, T_USBH_MGR_EVT_PARAM *);

/**
 * \brief usb host manager init
 */
int usbh_mgr_init(void);

/**
 * \brief usb host manager deinit
 */
int usbh_mgr_deinit(void);

/**
 * \brief usb host manager start
 */
int usbh_mgr_start(void);

/**
 * \brief usb host manager stop
 */
int usbh_mgr_stop(void);

/**
 * \brief usb host manager suspend port
 */
int usbh_mgr_suspend(void);

/**
 * \brief usb host manager resume port
 */
int usbh_mgr_resume(void);

/**
 * \brief usb host manager event callback register
 * \param evt usb host manager event
 * \param param usb host manager event parameter
 * \return 0 success
 */
int usbh_mgr_cb_register(T_USBH_MGR_EVT_MSK evt_msk, USBH_MGR_CB cb);

/**
 * \brief usb host manager event callback unregister
 * \param cb usb host manager event callback
 */
int usbh_mgr_cb_unregister(USBH_MGR_CB cb);

/** @} */ /* End of group USBH_Mgr_Exported_Functions */
/** @}*/
#endif
