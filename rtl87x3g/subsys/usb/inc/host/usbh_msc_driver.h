/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: LicenseRef-Realtek-5-Clause
 */
#ifndef __USBH_MSC_DRIVER_H__
#define __USBH_MSC_DRIVER_H__
#include <stdint.h>
#include <stdbool.h>

/**
 * \addtogroup USBH_Msc_Driver
 * \brief This module mainly provides components for implementing USB mass storage.
 * @{
 */

/** \defgroup USBH_Msc_Driver_Exported_Functions USB Host Mass Storage Exported Types
  * @{
  */

/**
 * \brief USB msc operation status
 * \param success success or not
 * \param skey status key
 * \param asc additional sense code
 */
typedef struct _usbh_msc_operation_status
{
    uint8_t success;
    uint8_t skey;
    uint8_t asc;
} T_USBH_MSC_OP_STATUS;

/**
 * \brief USB msc read/write parameter
 * \param buf data buffer
 * \param lba logical block address
 * \param blk_actual actual block count
 */
typedef struct _usbh_msc_wr_param
{
    uint8_t *buf;
    uint32_t lba;
    uint8_t blk_actual;
} T_USBH_MSC_RW_PARAM;

/**
 * \brief USB msc operation parameter
 */
typedef union _usbh_msc_operation_param
{
    T_USBH_MSC_RW_PARAM rw;
} T_USBH_MSC_OP_PARAM;

/**
 * \brief USB disk capacity
 * \param lba logical block address
 * \param blk_len block length
 */
typedef struct _usb_disk_capacity
{
    uint32_t lba;
    uint32_t blk_len;
} T_USB_DISK_CAPACITY;

/**
 * \brief USB msc user callback
 * \param param operation parameter
 * \param status operation status
 * \return 0:success, other:error
 * */
typedef int (*USBH_MSC_USER_CB)(T_USBH_MSC_OP_PARAM, T_USBH_MSC_OP_STATUS);

/**
 * \brief USB msc driver capacity get
 */
T_USB_DISK_CAPACITY usbh_msc_driver_capacity_get(uint8_t lun);

/**
 * \brief USB msc driver data read
 * \param lun logical unit number
 * \param buf data buffer
 * \param lba logical block address
 * \param blk_cnt block count
 * \param complete operation complete callback
 * \param timeout operation timeout
 * \return 0:success, other:error
 */
int usbh_msc_driver_data_read(uint8_t lun, uint8_t *buf, uint32_t lba, uint32_t blk_cnt,
                              USBH_MSC_USER_CB complete, uint32_t timeout);

/**
 * \brief USB msc driver data write
 * \param lun logical unit number
 * \param buf data buffer
 * \param lba logical block address
 * \param blk_cnt block count
 * \param complete operation complete callback
 * \param timeout operation timeout
 * \return 0:success, other:error
 */
int usbh_msc_driver_data_write(uint8_t lun, uint8_t *buf, uint32_t lba, uint32_t blk_cnt,
                               USBH_MSC_USER_CB complete, uint32_t timeout);

/**
* \brief USB msc driver is ready
* \param lun logical unit number
* \return true:ready, false:not ready
*/
bool usbh_msc_driver_is_ready(uint8_t lun);

/**
 * \brief USB msc driver init
 */
int32_t usbh_msc_driver_init(void);

/** @} */ /* End of group USBH_Msc_Driver_Exported_Functions */
/** @}*/
#endif // !__USBH_MSC_DRIVER_H__
