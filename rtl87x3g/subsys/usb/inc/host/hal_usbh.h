/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: LicenseRef-Realtek-5-Clause
 */

#ifndef __HAL_USBH_H__
#define __HAL_USBH_H__
#include <stdint.h>
#include "usb_spec20.h"

/**
 * \addtogroup USBH_HAL
 * \brief This section introduces definitions and usage of the USB Host HAL APIs.
 *
 * |Terms         |Details                                               |
 * |--------------|------------------------------------------------------|
 * |\b HAL        |Hardware Abstraction Layer                            |
 * |\b urb        |USB request block                                     |
 * |\b chnl       |USB channel                                           |
 * |\b usbh       |USB host                                              |
 *
 * @{
 */
/**
 * \defgroup HAL_USBH_Usage_Chapter How to Use USB Host HAL
 * @{
 *
 * \section HAL_HW_SETUP Hardware Setup
 *  - step1: Call #hal_usbh_init() to initialize hal software resource. \n
 *  - step2: Call #hal_usbh_phy_power_on() to power on USB PHY
 *  - step3: Call #hal_usbh_mac_init() to initialize USB mac
 * \par Example
 * \code
 *      void usbh_hw_init(void)
 *      {
 *          hal_usbh_init();
 *          hal_usbh_phy_power_on();
 *          hal_usbh_mac_init();
 *      }
 * \endcode
 *
 * \section HAL_Enable_ISR Enable ISR
 *  - step1: Call #hal_usbh_isr_update() to initialize USB isr hooks. \n
 *  - step2: Set USB related NVIC. \n
 *  - step3: Call #hal_usbh_global_isr_enable() to enable USB global isr. \n
 * \par Example
 * \code
 *      void usbh_sys_isr_enter(void)
 *      {
 *          //add process code if needed
 *      }
 *
 *      void usbh_sys_isr_exit(void)
 *      {
 *          //add process code if needed
 *      }
 *
 *      void usbh_sys_isr_handler(T_HAL_USBH_IRQ irq, T_HAL_USBH_ISR_PARAM *param)
 *      {
 *         //process usb isr
 *      }
 *
 *     T_HAL_USBH_ISR_HOOKS usbh_sys_isr_hooks =
 *     {
 *         .enter = usbh_sys_isr_enter,
 *         .handler = usbh_sys_isr_handler,
 *         .exit = usbh_sys_isr_exit,
 *     };
 *
 *      void usbh_chnl_isr_enter(void)
 *      {
 *          //add process code if needed
 *      }
 *
 *      void usbh_chnl_isr_exit(void)
 *      {
 *          //add process code if needed
 *      }
 *
 *      void usbh_chnl_isr_handler(T_HAL_USBH_IRQ irq, T_HAL_USBH_ISR_PARAM *param)
 *      {
 *         //process usb isr
 *      }
 *
 *     T_HAL_USBH_ISR_HOOKS usbh_chnl_isr_hooks =
 *     {
 *         .enter = usbh_chnl_isr_enter,
 *         .handler = usbh_chnl_isr_handler,
 *         .exit = usbh_chnl_isr_exit,
 *     };
 *
 *     hal_usbh_isr_update(HAL_USBH_IRQ_GROUP_SYS, &usbh_sys_isr_hooks);
 *     hal_usbh_isr_update(HAL_USBH_IRQ_GROUP_CHANNELS, &usbh_chnl_isr_hooks);
 *
 *     NVIC_SetPriority(USB_IRQn, 4);
 *     NVIC_EnableIRQ(USB_IRQn);
 *
 *     hal_usbh_global_isr_enable();
 *
 * \endcode
 *
 * \section HAL_PREPARE_TO_ENUM Prepare to enum device. \n
 * - step1: Setup hardware and enable isr as above. \n
 * - step2: Create task to handle interrupts. \n
 * - step3: Wait for USB device connection. \n
 * - step4: Allocate USB channel, and bind USB channel to USB device control endpoint. \n
 * \par Example
 * \code
 *
 *     T_USBH_CHANNEL_HANDLE *chnl_out0 = hal_usbh_channel_alloc();
 *     T_USBH_CHANNEL_HANDLE *chnl_in0 = hal_usbh_channel_alloc();
 *
 *      void usbh_sys_isr_handler(T_HAL_USBH_IRQ irq, T_HAL_USBH_ISR_PARAM *param)
 *      {
 *            if (irq == HAL_USBH_SYS_IRQ_PORT_STS_CHANGE)
 *           {
 *              if (param->port_status_change.status == HAL_USBH_STATUS_CONNECTED)
 *              {
 *                  //USB device connected
 *                 T_USB_ENDPOINT_DESC ep0_desc =
 *                 {
 *                     .bDescriptorType = USB_EP_TYPE_CONTROL,
 *                     .wMaxPacketSize = 64,
 *                     .bEndpointAddress = 0x00,
 *                 };
 *                 hal_usbh_channel_init(chnl_out0, dev addr, &ep0_desc);
 *                 ep0_desc.bEndpointAddress = 0x80;
 *                 hal_usbh_channel_init(chnl_in0, dev addr, &ep0_desc);
 *                 //start enumeration
 *              }
 *          }
 *      }
 *
 *      void usbh_chnl_isr_handler(T_HAL_USBH_IRQ irq, T_HAL_USBH_ISR_PARAM *param)
 *      {
 *           //process usb channel isr
 *      }
 *
 *      void usbh_task(void)
 *      {
 *         while(1)
 *        {
 *            if receive msg from usb sys/channel isr
 *            {
 *                //process msg
 *            }
 *        }
 *      }
 *
 *     void usbh_start(void)
 *     {
 *         usbh_hw_init();//Setup hardware
 *         hal_usbh_isr_update(HAL_USBH_IRQ_GROUP_SYS, &usbh_sys_isr_hooks);
 *         hal_usbh_isr_update(HAL_USBH_IRQ_GROUP_CHANNELS, &usbh_chnl_isr_hooks);
 *         //Enable isr
 *
 *         //os scheduler start
 *     }
 * \endcode
 * /
 *
 * \section HAL_DATA_TRANSFER Data Transfer
 *  Data transfer entity is defined in \ref T_HAL_USBH_REQUEST_BLOCK for control/bulk transfers. \n
 *  To setup data transfer:
 *  - step1: setup channel
 *  - step2: alloc urb
 *  - step2: start transfer
 *
 * \par Example
 * \code
 *     // \b Control \b transfer
 *
 *     //enable channel
 *     void *chnl_out0 = hal_usbh_channel_alloc();
 *     T_USB_ENDPOINT_DESC ep0_desc =
 *     {
 *         .bDescriptorType = USB_EP_TYPE_CONTROL,
 *         .wMaxPacketSize = 64,
 *         .bEndpointAddress = 0x00,
 *      };
 *     void *chnl_in0 = hal_usbh_channel_alloc();
 *     hal_usbh_channel_init(chnl_out0, dev addr, &ep0_desc);
 *     ep0_desc.bEndpointAddress = 0x80;
 *     hal_usbh_channel_init(chnl_in0, dev addr, &ep0_desc);
 *
 *     //alloc urb
 *     T_HAL_USBH_REQUEST_BLOCK *ctrl_urb = hal_usbh_urb_alloc(1024);
 *
 *     //setup stage
 *     ctrl_urb->token = HAL_USBH_TOKEN_SETUP;
 *     ctrl_urb->length = sizeof(T_USB_DEVICE_REQUEST);
 *     ctrl_urb->complete = ctrl_request_complete;
 *     ctrl_urb->chnl_handle = chnl_out0;
 *     //contruct setup packet and copy to ctrl_urb->buf
 *     hal_usbh_channel_tx(chnl_out0, ctrl_urb);
 *
 *     //out data/status stage
 *     ctrl_urb->token = HAL_USBH_TOKEN_DATA;
 *     ctrl_urb->length = len to send;
 *     //data copy to ctrl_urb->buf
 *     ctrl_urb->chnl_handle = chnl_out0;
 *     hal_usbh_channel_tx(chnl_out0, ctrl_urb);
 *
 *     //in data/status stage
 *     ctrl_urb->token = HAL_USBH_TOKEN_DATA;
 *     ctrl_urb->length = len to recv;
 *     //data copy to ctrl_urb->buf
 *     ctrl_urb->chnl_handle = chnl_in0;
 *     hal_usbh_channel_tx(chnl_in0, ctrl_urb);
 *
 *     // \b bulk \b transfer
 *
 *     //enable channel
 *    void *chnl_outx = hal_usbh_channel_alloc();
 *    hal_usbh_channel_init(chnl_outx, dev addr, &bulk_epx_desc);
 *    void *chnl_inx = hal_usbh_channel_alloc();
 *    hal_usbh_channel_init(chnl_inx, dev addr, &bulk_epx_desc);
 *
 *    //alloc urb
 *    T_HAL_USBH_REQUEST_BLOCK *bulk_urb = hal_usbh_urb_alloc(len);
 *
 *    //send
 *    bulk_urb->token = HAL_USBH_TOKEN_DATA;
 *    bulk_urb->length = length of data to send;
 *    //data copy to bulk_urb->buf
 *    bulk_urb->complete = bulk_request_complete;
 *    bulk_urb->chnl_handle = chnl_outx;
 *    hal_usbh_channel_tx(chnl_outx, bulk_urb);
 *
 *   //recv
 *   bulk_urb->token = HAL_USBH_TOKEN_DATA;
 *   bulk_urb->length = length of data to recv;
 *   bulk_urb->complete = bulk_request_complete;
 *   bulk_urb->chnl_handle = chnl_inx;
 *   hal_usbh_channel_rx(chnl_inx, bulk_urb);
 *
 * \endcode
 */
/** @}*/

/** \defgroup HAL_USBH_Exported_Functions USB Host HAL Exported Types
  * @{
  */

/**
 * \brief USB channel handle
 */
typedef void       *T_USBH_CHANNEL_HANDLE;

/**
 * \brief USB device speed
 */
#define HAL_USB_SPEED_FULL      0
#define HAL_USB_SPEED_HIGH      1

/**
 * \brief USB host channel number
 */
typedef enum
{
    HAL_USBH_CHNL_0,
    HAL_USBH_CHNL_1,
    HAL_USBH_CHNL_2,
    HAL_USBH_CHNL_3,

    HAL_USBH_CHNL_MAX
} T_HAL_USBH_CHNL;

/**
 * \brief USB host packet token
 */
typedef enum
{
    HAL_USBH_TOKEN_SETUP,
    HAL_USBH_TOKEN_DATA
} T_HAL_USBH_TOKEN;

/**
 * \brief USB host test mode
 */
typedef enum
{
    USBH_TEST_MODE_DISABLE,
    USBH_TEST_MODE_J,
    USBH_TEST_MODE_K,
    USBH_TEST_MODE_SE0_NAK,
    USBH_TEST_MODE_PACKET,
    USBH_TEST_MODE_FORCE_ENABLE,
} T_USBH_TEST_MODE;

/**
 * \brief USB host request block
 * \param token packet token, refer to \ref T_HAL_USBH_TOKEN
 * \param length packet length
 * \param actual packet actual length
 * \param buf packet buffer
 * \param complete_in_isr 1: \ref complete callback will be called in ISR. \n
 *                    0: \ref complete callback will not be called in ISR, and the urb will be passed through in \ref HAL_USBH_COMMON_ISR_XFER_DONE.
 * \param status if data has been transferred successfully
 * \param chnl_handle handle of channel that will transfer data
 * \param complete this callback will be called when data that has been sent or received. \n
 *                 For sending data, this callback is mainly used to indicate the result of data sending. \n
 *                 For receiving data, this callback is used to get the data already received and related information.
 * \param priv private data
 */
typedef struct _hal_usbh_request_block
{
    uint8_t token;
    int length;
    int actual;
    uint8_t *buf;

    uint8_t complete_in_isr: 1;
    uint8_t rsv: 7;

    int status;
    void *chnl_handle;
    int (*complete)(struct _hal_usbh_request_block *urb);

    void *priv;
} T_HAL_USBH_REQUEST_BLOCK;

typedef struct _hal_usbh_iso_pkt_info
{
    uint32_t offset;
    uint32_t length;
    uint32_t actual;
    int status;
} T_HAL_USBH_ISO_PKT_INFO;

typedef struct _hal_usbh_iso_request_block
{
    uint8_t *buf0;
    uint8_t *buf1;

    uint32_t data_per_frame;
    uint32_t buf_proc_intrvl;

    uint8_t pkt_cnt;
    T_HAL_USBH_ISO_PKT_INFO *iso_pkt0;
    T_HAL_USBH_ISO_PKT_INFO *iso_pkt1;

    void *chnl_handle;

    int (*complete)(struct _hal_usbh_iso_request_block *urb, uint8_t proc_buf_num);

    void *priv;
} T_HAL_USBH_ISO_REQUEST_BLOCK;


/**
 * \brief USB host speed
 */
typedef enum {HAL_USBH_SPEED_FULL, HAL_USBH_SPEED_HIGH, HAL_USBH_SPEED_UNSUPPORTED} T_HAL_USBH_SPEED;

/**
 * \brief USB host port status
 */
typedef enum
{
    HAL_USBH_STATUS_IDLE,
    HAL_USBH_STATUS_CONNECTED,
    HAL_USBH_STATUS_DISCONNECTED,
    HAL_USBH_STATUS_SUSPENDED,
    HAL_USBH_STATUS_RESET_DONE,
    HAL_USBH_STATUS_RESUMED,
} T_HAL_USBH_PORT_STATUS;

/**
 * \brief parameter of isr handler in \ref T_HAL_USBH_ISR_HOOKS
 * \param port_status_change: used in \ref HAL_USBH_SYS_IRQ_PORT_STS_CHANGE
 * \param xfer_done: used in \ref HAL_USBH_CHANNEL_IRQ_XFER_DONE
 * \param stalled: used in \ref HAL_USBH_CHANNEL_IRQ_STALLED
 */
typedef union _hal_usbh_isr_param
{
    struct
    {
        uint8_t status;
        uint8_t spd;
    } port_status_change;

    struct
    {

        T_HAL_USBH_REQUEST_BLOCK *urb;

    } xfer_done;


    struct
    {

        T_USBH_CHANNEL_HANDLE *channel;

    } stalled;

} T_HAL_USBH_ISR_PARAM;

/**
 * \brief USB host interrupt definition
 */
#define HAL_USBH_IRQ_GROUP_OFFSET        (16)

#define HAL_USBH_IRQ_GROUP_NONE          (0 << HAL_USBH_IRQ_GROUP_OFFSET)
#define HAL_USBH_IRQ_GROUP_SYS           (1 << HAL_USBH_IRQ_GROUP_OFFSET)
#define HAL_USBH_IRQ_GROUP_CHANNELS      (2 << HAL_USBH_IRQ_GROUP_OFFSET)
#define HAL_USBH_IRQ_GROUP_SUSPENDN      (3 << HAL_USBH_IRQ_GROUP_OFFSET)

#define HAL_USBH_SYS_IRQ_NONE            (0 | HAL_USBH_IRQ_GROUP_SYS)
#define HAL_USBH_SYS_IRQ_PORT_STS_CHANGE (1 | HAL_USBH_IRQ_GROUP_SYS)

#define HAL_USBH_CHANNEL_IRQ_NONE        (0 | HAL_USBH_IRQ_GROUP_CHANNELS)
#define HAL_USBH_CHANNEL_IRQ_XFER_DONE   (1 | HAL_USBH_IRQ_GROUP_CHANNELS)
#define HAL_USBH_CHANNEL_IRQ_STALLED     (2 | HAL_USBH_IRQ_GROUP_CHANNELS)
#define HAL_USBH_CHANNEL_IRQ_XFER_ERROR  (3 | HAL_USBH_IRQ_GROUP_CHANNELS)

#define HAL_USBH_SUSPENDN_IRQ            (1 | HAL_USBH_IRQ_GROUP_SUSPENDN)

typedef uint32_t T_HAL_USBH_IRQ;


typedef int32_t (*HAL_USBH_ISR_ENTER)(void);
typedef int32_t (*HAL_USBH_ISR_HANDLER)(T_HAL_USBH_IRQ irq, T_HAL_USBH_ISR_PARAM *param);
typedef int32_t (*HAL_USBH_ISR_EXIT)(void);

/**
 * \brief USB host interrupt hooks
 * \param enter: enter ISR \n
 * \param handler: process USB interrupt \n
 * \param exit: exit ISR \n
 */
typedef struct _hal_usbh_isr_hooks
{
    HAL_USBH_ISR_ENTER enter;
    HAL_USBH_ISR_HANDLER handler;
    HAL_USBH_ISR_EXIT exit;
} T_HAL_USBH_ISR_HOOKS;

/**
 * \brief allocate USB host urb
 * \param size buffer size
 * \return urb, NULL means alloc failed
 * \par Example
 * Please refer to \ref HAL_DATA_TRANSFER
 */
T_HAL_USBH_REQUEST_BLOCK *hal_usbh_urb_alloc(uint32_t size);

/**
 * \brief allocate USB host isochronous urb
 * \param size buffer size
 * \return urb, NULL means alloc failed
 * \par Example
 * Please refer to \ref HAL_DATA_TRANSFER
 */
T_HAL_USBH_ISO_REQUEST_BLOCK *hal_usbh_iso_urb_alloc(uint32_t size);

/**
 * \brief free USB host isochronous urb
 * \param iso_urb urb returned by \ref hal_usbh_iso_urb_alloc
 * \return int result, refer to "errno.h"
 * \par Example
 * Please refer to \ref HAL_DATA_TRANSFER
 */
int hal_usbh_iso_urb_free(T_HAL_USBH_ISO_REQUEST_BLOCK *iso_urb);

/**
 * \brief free USB host urb
 * \param urb urb returned by \ref hal_usbh_urb_alloc
 * \return int result, refer to "errno.h"
 * \par Example
 * Please refer to \ref HAL_DATA_TRANSFE
 */
int hal_usbh_urb_free(T_HAL_USBH_REQUEST_BLOCK *urb);

/**
 * \brief allocate USB host channel handle
 * \return channel handle, NULL means alloc failed
 * \par Example
 * Please refer to \ref HAL_DATA_TRANSFE
 */
T_USBH_CHANNEL_HANDLE hal_usbh_channel_alloc(void);

/**
 * \brief init USB host channel
 * \param chnl channel handle returned by \ref hal_usbh_channel_alloc
 * \param dev_addr USB device address
 * \param desc endpoint descriptor
 * \return int result, refer to "errno.h"
 * \par Example
 * Please refer to \ref HAL_DATA_TRANSFE
 */
int hal_usbh_channel_init(T_USBH_CHANNEL_HANDLE chnl, uint8_t dev_addr, T_USB_ENDPOINT_DESC *desc);

/**
 * \brief free USB host channel
 * \param chnl channel handle returned by \ref hal_usbh_channel_alloc
 * \return int result, refer to "errno.h"
 * \par Example
 * Please refer to \ref HAL_DATA_TRANSFE
 */
int hal_usbh_channel_free(T_USBH_CHANNEL_HANDLE chnl);

/**
 * \brief halt USB host channel
 * \param chnl channel handle returned by \ref hal_usbh_channel_alloc
 * \return int result, refer to "errno.h"
 * \par Example
 * Please refer to \ref HAL_DATA_TRANSFE
 */
int hal_usbh_channel_halt(T_USBH_CHANNEL_HANDLE chnl);

/**
 * \brief reset USB host channel
 * \param chnl channel handle returned by \ref hal_usbh_channel_alloc
 * \return int result, refer to "errno.h"
 * \par Example
 * Please refer to \ref HAL_DATA_TRANSFE
 */
int hal_usbh_channel_tx(T_USBH_CHANNEL_HANDLE chnl, T_HAL_USBH_REQUEST_BLOCK *urb);

/**
 * \brief reset USB host channel
 * \param chnl channel handle returned by \ref hal_usbh_channel_alloc
 * \return int result, refer to "errno.h"
 * \par Example
 * Please refer to \ref HAL_DATA_TRANSFER
 */
int hal_usbh_channel_rx(T_USBH_CHANNEL_HANDLE chnl, T_HAL_USBH_REQUEST_BLOCK *urb);

/**
 * \brief Start ISO transfer on channel
 *
 * \param chnl Channel handle
 * \param urb ISO URB
 * \return 0 on success, negative error code on failure
 * \par Example
 * Please refer to \ref HAL_DATA_TRANSFER
 */
int hal_usbh_iso_channel_start(T_USBH_CHANNEL_HANDLE chnl, T_HAL_USBH_ISO_REQUEST_BLOCK *urb);

/**
 * \brief Stop ISO transfer on channel
 *
 * \param chnl Channel handle
 * \param urb ISO URB
 * \return 0 on success, negative error code on failure
 * \par Example
 * Please refer to \ref HAL_DATA_TRANSFER
 */
int hal_usbh_iso_channel_stop(T_USBH_CHANNEL_HANDLE chnl, T_HAL_USBH_ISO_REQUEST_BLOCK *urb);
/**
 * \brief hal USB host software init
 * \return int result, refer to "errno.h"
 * \par Example
 * Please refer to \ref HAL_HW_SETUP
 */
int hal_usbh_init(void);

/**
 * \brief hal USB host software deinit
 * \return int result, refer to "errno.h"
 */
int hal_usbh_deinit(void);

/**
 * \brief hal USB host mac init
 * \return int result, refer to "errno.h"
 * \par Example
 * Please refer to \ref HAL_HW_SETUP
 */
int hal_usbh_mac_init(void);

/**
 * \brief hal USB host mac deinit
 * \return int result, refer to "errno.h"
 */
int hal_usbh_mac_deinit(void);

/**
 * \brief hal USB host phy power on
 * \return int result, refer to "errno.h"
 * \par Example
 * Please refer to \ref HAL_HW_SETUP
 */
int hal_usbh_phy_power_on(void);

/**
 * \brief hal USB host phy power down
 * \return int result, refer to "errno.h"
 */
int hal_usbh_phy_power_down(void);

/**
 * \brief hal USB host global interrupt enable
 * \return int result, refer to "errno.h"
 */
int hal_usbh_global_intr_enable(void);

/**
 * \brief hal USB host global interrupt disable
 * \return int result, refer to "errno.h"
 */
int hal_usbh_global_intr_disable(void);

/**
 * \brief hal USB host interrupt update
 * \param irq_group interrupt group
 * \param hooks interrupt hooks
 * \return int result, refer to "errno.h"
 * \par Example
 * Please refer to in \ref HAL_Enable_ISR
 */
int hal_usbh_isr_update(uint32_t irq_group, T_HAL_USBH_ISR_HOOKS *hooks);

/**
 * \brief hal USB host port reset
 * \return int result, refer to "errno.h"
 */
int hal_usbh_port_reset(void);

/**
 * \brief hal USB host port suspend
 * \return int result, refer to "errno.h"
 */
int hal_usbh_port_suspend(void);

/**
 * \brief hal USB host port resume: APHY power on, and optionally drive bus
 *        resume signaling
 * \param drive_signaling true for host-initiated wake (generate resume
 *        signaling); false for remote wake (device already signaled, PHY only)
 * \return int result, refer to "errno.h"
 */
int hal_usbh_port_resume(bool drive_signaling);

/**
 * \brief hal USB host port status get
 * \return int result, refer to "errno.h"
 */
int hal_usbh_port_status_get(void);

/**
 * \brief hal USB host port test control
 * \return int result, refer to "errno.h"
 */
int hal_usbh_port_test_control(T_USBH_TEST_MODE mode);

/**
 * \brief hal USB host wakeup status get
 * \return bool true: USB wakeup event occurred, false: no USB wakeup event occurred
 */
bool hal_usbh_wakeup_status_get(void);
/** @} */ /* End of group HAL_USBH_Exported_Functions */
/** @}*/

#endif
