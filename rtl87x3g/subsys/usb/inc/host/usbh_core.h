/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: LicenseRef-Realtek-5-Clause
 */
#ifndef __USBH_CORE_H__
#define __USBH_CORE_H__
#include <stdint.h>

#include "usb_spec20.h"
#include "hal_usbh.h"

/**
 * \addtogroup USBH_Core
 * \brief This module mainly provides components for implementing USB host class driver.
 * @{
 */
/** \defgroup USBH_Core_Usage How to Implement a USB Host Class Driver
 * @{
 *
 * \brief This section provides a comprehensive guide on implementing a USB host class driver,
 *        complete with sample code for your reference.
 * \section USBH_CLASS_DRIVER_IMPLEMENT Implement a Class Driver
 * Implement a class driver as follows:
 *   - Implement the class driver structure \ref T_USB_HOST_CLASS_DRIVER.
 *   - Register the class driver using \ref usbh_class_driver_register.
 *
 * \par Example
 * \code
 *
 *    int demo_ep_desc_proc(T_USB_HOST_CLASS_DRIVER *driver, void *param)
 *    {
 *        //process endpoint descriptors of the interface.
 *        T_USB_ENDPOINT_DESC *ep_desc = (T_USB_ENDPOINT_DESC *)param;
 *        T_USB_HOST_PIPE pipe = usbh_pipe_alloc(dir, ep_desc->bEndpointAddress).
 *        usbh_pipe_open(pipe, ep_desc);
 *
 *        return 0;
 *    }
 *
 *    int demo_mount(T_USB_HOST_CLASS_DRIVER *driver, void *param)
 *    {
 *        T_USB_INTERFACE_DESC *if_desc = (T_USB_INTERFACE_DESC *)param;
 *        //use \ref usbh_dev_ep_desc_traverse to traverse all endpoint descriptors of the interface.
 *        usbh_dev_ep_desc_traverse(driver, if_desc, demo_ep_desc_proc);
 *        //start process class-related operations.
 *        return 0;
 *    }
 *
 *   int demo_unmount(T_USB_HOST_CLASS_DRIVER *driver, void *param)
 *   {
 *       //stop class-related operations.
 *       return 0;
 *   }
 *
 *   T_USB_HOST_CLASS_DRIVER demo_driver = {
 *       .class = USB_CLASS_MSC,
 *       .subclass = USBH_MSC_SUBCLASS_SCSI,
 *       .mount = demo_mount,
 *       .unmount = demo_unmount,
 *       .priv = NULL,
 *   };
 *
 *   usbh_class_driver_register(&demo_driver);
 * \endcode
 *
 */
/** @}*/

/** \defgroup USBH_Core_Exported_Functions USB Host Core Exported Types
  * @{
  */

/**
 * \brief USB Request Undefined Type
 */
#define USB_REQUEST_TYPE_UNDEF      (0xff)

struct _usb_host_class_driver;
typedef struct _usb_host_class_driver T_USB_HOST_CLASS_DRIVER;

typedef int32_t (*USB_HOST_CLASS_DRIVER_CB)(T_USB_HOST_CLASS_DRIVER *, void *param);

/**
 * \brief USB Host Class Driver
 * \param class USB device class code
 * \param subclass USB device subclass code
 * \param mount mount callback, refer to \ref USB_HOST_CLASS_DRIVER_CB. \n
 *              The callback will be called when a device with matching class/subclass is configured. \n
 *              The param is start address of the interface descriptors of the device.
 * \param unmount unmount callback, refer to \ref USB_HOST_CLASS_DRIVER_CB. \n
 *             The callback will be called when the device is disconnected. \n
 *             The param is NULL.
 * \param priv private data
 */
struct _usb_host_class_driver
{
    uint8_t class;
    uint8_t subclass;

    USB_HOST_CLASS_DRIVER_CB mount;
    USB_HOST_CLASS_DRIVER_CB unmount;

    USB_HOST_CLASS_DRIVER_CB suspend;
    USB_HOST_CLASS_DRIVER_CB resume;

    void *priv;
};

/**
 * \brief USB Host Transfer Status
 */
typedef enum
{
    USB_HOST_XFER_STATUS_OK,
    USB_HOST_XFER_STATUS_STALL,
    USB_HOST_XFER_STATUS_ERROR,
    USB_HOST_XFER_STATUS_NO_DEV     /**< device removed (transfer nuked with -ESHUTDOWN) */
} T_USB_HOST_XFER_STATUS;

/**
 * \brief USB Host Transfer Type
 */
typedef enum
{
    T_USB_HOST_XFER_TYPE_CTRL,
    T_USB_HOST_XFER_TYPE_BULK,
} T_USB_HOST_XFER_TYPE;

/**
 * \brief USB Pipe Direction
 */
typedef enum
{
    USB_PIPE_DIR_OUT,
    USB_PIPE_DIR_IN
} T_USB_PIPE_DIR;

struct _usb_host_xfer;
typedef struct _usb_host_xfer T_USB_HOST_XFER;
typedef int32_t (*USB_HOST_XFER_CB)(T_USB_HOST_XFER *);
typedef void   *T_USB_HOST_PIPE;

/**
 * \brief USB Host Transfer
 * \param type USB transfer type, refer to \ref T_USB_HOST_XFER_TYPE
 * \param status USB transfer status, refer to \ref T_USB_HOST_XFER_STATUS
 * \param pipe USB pipe
 * \param setup USB setup packet
 * \param complete_in_isr 1: \ref complete callback will be called in ISR. \n
 *                    0: \ref complete callback will not be called in ISR, and the urb will be passed through in \ref HAL_USBH_COMMON_ISR_XFER_DONE.
 * \param data data buffer
 * \param len data length
 * \param actual actual data length
 * \param pre_xfer pre transfer callback
 * \param complete transfer complete callback
 * \param trace debug trace
 * \param priv private data
 */
struct _usb_host_xfer
{
    T_USB_HOST_XFER_TYPE type;
    T_USB_HOST_XFER_STATUS status;
    T_USB_HOST_PIPE *pipe;
    T_USB_DEVICE_REQUEST setup;

    uint32_t complete_in_isr: 1;
    uint32_t rsv: 31;
    uint8_t *data;
    int32_t len;
    int32_t actual;

    USB_HOST_XFER_CB pre_xfer;
    USB_HOST_XFER_CB complete;

    char *trace;

    void  *priv;

};

//#define USB_HOST_XFER_DEBUG_TRACE_PRINT(xfer)
#define USB_HOST_XFER_DEBUG_TRACE_PRINT(xfer)    {if((xfer)->trace) USB_PRINT_INFO3("%s:0x%x, (%s)", TRACE_STRING(__FUNCTION__), (xfer), TRACE_STRING((xfer)->trace));}

/**
 * \brief submit a control transfer
 * \param xfer control transfer
 * \param timeout timeout in ms
 *
 */
int usbh_pipe_ctrl_xfer_submit(T_USB_HOST_XFER *xfer, uint32_t timeout);

/**
 * \brief allocate a pipe
 * \param dir USB pipe direction, refer to \ref T_USB_PIPE_DIR
 * \param mtu maximum transfer unit; for ISO pipes this is the per-buffer size
 * \param is_iso 1 for isochronous pipe (allocates ISO URB internally), 0 otherwise
 */
T_USB_HOST_PIPE usbh_pipe_alloc(uint8_t dir, uint32_t mtu, uint8_t is_iso);

/**
 * \brief free a pipe
 * \param pipe USB pipe
 */
int32_t usbh_pipe_free(T_USB_HOST_PIPE pipe);

/**
 * \brief open a pipe
 * \param pipe USB pipe
 * \param ep_desc device endpoint descriptor
 *
 */
int32_t usbh_pipe_open(T_USB_HOST_PIPE pipe, T_USB_ENDPOINT_DESC *ep_desc);

/**
 * \brief get device endpoint descriptor of a pipe
 * \param pipe USB pipe
 *
 */
T_USB_ENDPOINT_DESC *usbh_pipe_ep_desc_get(T_USB_HOST_PIPE pipe);

/**
 * \brief submit a transfer
 * \param pipe USB pipe
 * \param xfer transfer
 * \param timeout timeout in ms
 */
int usbh_pipe_xfer_submit(T_USB_HOST_PIPE pipe, T_USB_HOST_XFER *xfer, uint32_t timeout);

/**
 * \brief close a pipe
 * \param pipe USB pipe
 */
int usbh_pipe_close(T_USB_HOST_PIPE pipe);

/**
 * \brief register a class driver
 * \param driver class driver
 */
int usbh_class_driver_register(T_USB_HOST_CLASS_DRIVER *driver);

/**
 * \brief unregister a class driver
 * \param driver class driver
 */
int usbh_class_driver_unregister(T_USB_HOST_CLASS_DRIVER *driver);

/**
 * \brief traverse device endpoint descriptor
 * \param driver class driver
 * \param if_descs interface descriptor
 * \param cb callback
 */
int32_t usbh_dev_ep_desc_traverse(T_USB_HOST_CLASS_DRIVER *driver,
                                  T_USB_INTERFACE_DESC *if_descs, USB_HOST_CLASS_DRIVER_CB cb);

/**
 * \brief enter USB host suspend state
 */
int32_t usbh_suspend(void);

/**
 * \brief exit USB host suspend state
 */
int32_t usbh_resume(void);

/**
 * \brief Get the ISO URB allocated inside the pipe (valid only for ISO pipes).
 * \param pipe USB pipe allocated with is_iso=1
 * \return ISO URB pointer, NULL if pipe is NULL or not an ISO pipe
 */
T_HAL_USBH_ISO_REQUEST_BLOCK *usbh_pipe_iso_urb_get(T_USB_HOST_PIPE pipe);

/**
 * \brief Start ISO streaming on a pipe.
 * Sets iso_urb->chnl_handle from the pipe and calls
 * hal_usbh_iso_channel_start().
 */
int usbh_pipe_iso_start(T_USB_HOST_PIPE pipe,
                        T_HAL_USBH_ISO_REQUEST_BLOCK *iso_urb);

/**
 * \brief Stop ISO streaming on a pipe.
 */
int usbh_pipe_iso_stop(T_USB_HOST_PIPE pipe,
                       T_HAL_USBH_ISO_REQUEST_BLOCK *iso_urb);

/**
 *\brief initialize USB host
 */
int usbh_init(void);

/**
 *\brief de-initialize USB host and free all resources allocated by usbh_init().
 *
 * The controller must already be quiesced (usbh_isr_disable /
 * hal_usbh_mac_deinit run) before calling this.
 */
int usbh_deinit(void);

/**
 * \brief Get current device speed
 * \return HAL_USBH_SPEED_FULL (0) or HAL_USBH_SPEED_HIGH (1)
 */
uint8_t usbh_dev_speed_get(void);


/** @} */ /* End of group USBH_Core_Exported_Functions */
/** @}*/
#endif
