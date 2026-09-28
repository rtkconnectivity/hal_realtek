/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: LicenseRef-Realtek-5-Clause
 */
#ifndef __HAL_USB__
#define __HAL_USB__
#include <stdint.h>

/**
 * \addtogroup USB_HAL
 * \brief This section introduces the definition and the usage of the USB HAL APIs.
 *
 * |Terms         |Details                                               |
 * |--------------|------------------------------------------------------|
 * |\b HAL        |Hardware Abstraction Layer                            |
 * |\b URB        |USB Request Block                                     |
 *
 * @{
 */
/**
 * \defgroup HAL_Usage_Chapter How to Use USB HAL
 * @{
 *
 * \brief This section provides a detailed explanation on utilizing USB HAL,
 *        accompanied by sample code for better understanding.
 *
 * \section HAL_HW_SETUP Hardware Setup
 *  - Call #hal_usb_speed_set() to set USB target speed
 *  - Call #hal_usb_init() to initialize hal software resource.
 *  - Call #hal_usb_phy_power_on() to power on USB PHY.
 *  - Call #hal_usb_mac_init() to initialize USB MAC.
 * \par Example
 * \code
 *      void usb_hw_init(void)
 *      {
 *          hal_usb_speed_set(HAL_USB_SPEED_HIGH);
 *          hal_usb_init();
 *          hal_usb_phy_power_on();
 *          hal_usb_mac_init();
 *      }
 * \endcode
 *
 * \section HAL_Enable_ISR Enable ISR
 *  - Call #hal_usb_isr_update() to initialize USB isr hooks. \n
 *  - Set USB related NVIC. \n
 *  - Call #hal_usb_global_isr_enable() to enable USB global isr. \n
 * \par Example
 * \code
 *      void usb_common_isr_enter(void)
 *      {
 *          NVIC_DisableIRQ(USB_IP_IRQn);
 *      }
 *
 *      void usb_common_isr_exit(void)
 *      {
 *          NVIC_EnableIRQ(USB_IP_IRQn);
 *      }
 *
 *      void usb_common_isr_handler(T_HAL_USB_IRQ irq, T_HAL_USB_ISR_PARAM *param)
 *      {
 *        //process usb isr
 *      }
 *
 *      T_HAL_USB_ISR_HOOKS usb_sys_isr_hooks =
 *      {
 *          .enter = usb_common_isr_enter,
 *          .handler = usb_common_isr_handler,
 *          .exit = usb_common_isr_exit,
 *      };
 *      void usb_eps_isr_enter(void)
 *      {
 *          //disable USB ep interrupt
 *      }
 *
 *      void usb_eps_isr_exit(void)
 *      {
 *          //enable USB ep interrupt
 *      }
 *
 *      void usb_eps_isr_handler(T_HAL_USB_IRQ irq, T_HAL_USB_ISR_PARAM *param)
 *      {
 *        //process usb ep isr
 *      }
 *
 *      T_HAL_USB_ISR_HOOKS usb_eps_isr_hooks =
 *      {
 *          .enter = usb_eps_isr_enter,
 *          .handler = usb_eps_isr_handler,
 *          .exit = usb_eps_isr_exit,
 *      };
 *
 *
 *      hal_usb_isr_update(HAL_USB_IRQ_GROUP_SYS, (T_HAL_USB_ISR_HOOKS *)&usb_sys_isr_hooks);
 *      hal_usb_isr_update(HAL_USB_IRQ_GROUP_IEP0, (T_HAL_USB_ISR_HOOKS *)&usb_eps_isr_hooks);
 *      hal_usb_isr_update(HAL_USB_IRQ_GROUP_IEPn, (T_HAL_USB_ISR_HOOKS *)&usb_eps_isr_hooks);
 *      hal_usb_isr_update(HAL_USB_IRQ_GROUP_OEP0, (T_HAL_USB_ISR_HOOKS *)&usb_eps_isr_hooks);
 *      hal_usb_isr_update(HAL_USB_IRQ_GROUP_OEPn, (T_HAL_USB_ISR_HOOKS *)&usb_eps_isr_hooks);
 *
 *      NVIC_SetPriority(USB_IP_IRQn, 4);
 *      NVIC_EnableIRQ(USB_IP_IRQn);
 *      hal_usb_global_isr_enable();
 * \endcode
 *
 * \section HAL_PREPARE_TO_ENUM Prepare to Enumerate
 *  - Set up the hardware as required above.
 *  - Implement the HAL USB composite driver.
 *  - Create task to handle interrupts.
 *  - Initialize the interrupts.
 *  - USB soft connect.
 *
 * \par Example
 * \code
 *
 *      uint8_t isr_pending = 0;
 *      void usb_ep0_isr_handler(T_HAL_USB_IRQ isr, T_HAL_USB_ISR_PARAM *param)
 *      {
 *          if process in task
 *          {
 *              isr_pending++;
 *              //send msg to usb irq task
 *          }
 *      }
 *
 *      void usb_ep0_isr_enter(void)
 *      {
 *          //disable USB ep0 interrupt
 *      }
 *
 *      void usb_ep0_isr_exit(void)
 *      {
 *          if(isr_pending == 0)
 *          {
 *              //enable USB ep0 interrupt
 *          }
 *      }
 *
 *      T_HAL_USB_ISR_HOOKS ep0_isr_hooks =
 *      {
 *          .enter = usb_ep0_isr_enter,
 *          .handler = usb_ep0_isr_handler,
 *          .exit = usb_ep0_isr_exit,
 *      }
 *      void usb_isr_proc_task(void *)
 *      {
 *          while(1)
 *          {
 *              if receive msg from usb ep0 isr
 *              {
 *                  process ep0 isr
 *              }
 *              isr_pending--;
 *              if(isr_pending == 0)
 *              {
 *                  //enable USB ep0 interrupt
 *              }
 *          }
 *      }
 *
 *      void usb_isr_proc_task_create(void)
 *      {
 *          //create task usb_isr_proc_task
 *      }
 *
 *
 *      void usb_start(void)
 *      {
 *          usb_hw_init();//Setup hardware
 *          usb_isr_proc_task_create();//Create task to handle interrupts
 *          usb_isr_init();//Initialize interrupts
 *          hal_usb_soft_attach();//USB soft connect
 *
 *          os scheduler start
 *      }
 * \endcode
 *
 * \section HAL_EP_SETUP Endpoint Setup
 *   The endpoint should be enabled when receiving `set_alt` request and the alternate setting contains the endpoint.
 *   Please refer to `Prepare to Enumerate` to know how to receive setup packets.
 *
 * \par Example
 * \code
 *      int setup_cb(uint8_t *data)
 *      {
 *         if setup request is SET_ALT
 *         {
 *              void *ep_handle = hal_usb_ep_handle_get(ep addr);
 *              if alt value is m and alt setting m contains the endpoint epN
 *              {
 *                  hal_usb_ep_enable(ep_handle , ep desc);
 *
 *                  // \b bulk \b & \b interrupt \b endpoints
 *                  if endpoint direction is OUT
 *                  //alloc URB
 *                  T_HAL_USB_REQUEST_BLOCK *ep_urb = hal_usb_urb_alloc(len);
 *                  ...init URB...(refer to "Data transfer" in \ref HAL_Usage_Chapter)
 *                  //prepare to receive data
 *                  hal_usb_ep_rx(ep_handle, ep_urb);
 *
 *                  // \b isochronous \b endpoints
 *                  //alloc URB
 *                  T_HAL_USB_ISO_REQUEST_BLOCK *ep_urb = hal_usb_iso_urb_alloc(len);
 *                  ...init URB...(refer to "Data transfer" in \ref HAL_Usage_ChapterK)
 *                  //start transfer--For both send & receive
 *                  hal_usb_iso_ep_start(ep_handle, ep_urb);
 *              }
 *              else
 *              {
 *                  // \b isochronous \b endpoints
 *                  hal_usb_iso_ep_stop(ep_handle, ep_urb);
 *
 *                  // \b all \b endpoints
 *                  hal_usb_ep_disable(ep_handle);
 *              }
 *         }
 *      }
 * \endcode
 *
 * \section HAL_DATA_TRANSFER Data Transfer
 *  Data transfer entity is defined in \ref T_HAL_USB_REQUEST_BLOCK for control/interrupt/bulk transfers
 *  and \ref T_HAL_USB_ISO_REQUEST_BLOCK for isochronous transfer.
 *
 *  To setup data transfer:
 *  - Setup endpoint, refer to `Endpoint Setup` in \ref HAL_Usage_Chapter.
 *  - Allocate URB.
 *  - Start transfer.
 * \par Example
 * \code
 *      // \b Control \b transfer
 *
 *      //enable ep0
 *      void *ep0_handle = hal_usb_ep_handle_get(0);
 *      hal_usb_ep_enable(ep0_handle , NULL);
 *
 *      int ep0_request_complete(T_HAL_USB_REQUEST_BLOCK *urb)
 *      {
 *          //for OUT data stage
 *          process data in urb->buf
 *      }
 *
 *      //alloc URB
 *      T_HAL_USB_REQUEST_BLOCK *ep0_urb = hal_usb_urb_alloc(len);
 *      ep0_urb->length = length of data to transfer
 *      memcpy(ep0_urb->buf, data, ep0_urb->length)
 *      ep0_urb->complete = ep0_request_complete;
 *      ep0_urb->ep_handle = ep0_handle;
 *
 *      //start transfer--For both send & receive
 *      //hal_usb_ep0_trx MUST be called in setup callback in \ref T_HAL_USB_DRIVER
 *      //for tx, if ep0_urb->length is 0, it means send ACK to host
 *      hal_usb_ep0_trx(ep0_handle, ep0_urb);
 *
 *     // \b bulk \b & \b interrupt \b transfer
 *
 *     //enable ep
 *     void *ep_handle = hal_usb_ep_handle_get(ep addr);
 *     hal_usb_ep_enable(ep_handle , ep desc);
 *
 *     int ep_request_complete(T_HAL_USB_REQUEST_BLOCK *urb)
 *     {
 *          //for OUT data stage
 *          process data in urb->buf
 *          ...reinit URB if needed...
 *          hal_usb_ep_rx(ep_handle, ep_urb);
 *
 *     }
 *
 *     //alloc URB
 *     T_HAL_USB_REQUEST_BLOCK *ep_urb = hal_usb_urb_alloc(len);
 *     ep_urb->complete = ep_request_complete;
 *     ep_urb->ep_handle = ep_handle;
 *     ep_urb->buf_proc_intrvl = process interval;
 *     ep_urb->data_per_frame = data length per host polling;
 *
 *     //start transfer
 *     //send
 *     if support zero length packet
 *     {
 *          ep_urb->zlp = (ep max packet size ==  ep_urb->length);
 *     }
 *     else
 *     {
 *          ep_urb->zlp = 0;
 *     }
 *     hal_usb_ep_tx(ep_handle, ep_urb);
 *     //Receive
 *     hal_usb_ep_rx(ep_handle, ep_urb);
 *
 *     // \b isochronous \b transfer
 *
 *     int iso_ep_request_complete(T_HAL_USB_ISO_REQUEST_BLOCK *urb, uint8_t proc_buf_num)
 *     {
 *          T_HAL_USB_ISO_PKT_INFO *iso_pkt = urb->iso_pkt;
 *          uint8_t *buf = NULL;
 *          uint8_t pkt_cnt = 0;
 *
 *          if(proc_buf_num == 0)
 *          {
 *              buf = urb->buf0;
 *          }
 *          else
 *          {
 *              buf = urb->buf1;
 *          }
 *          pkt_cnt = iso_pkt->pkt_cnt;
 *          for(uint8_t i = 0; i < pkt_cnt; i++)
 *          {
 *              if(iso_pkt[i].status == 0)
 *              {
 *              //process data store in buf + iso_pkt[i].offset,
 *                and data length is  iso_pkt[i].actual
 *              }
 *          }
 *          return 0;
 *     }
 *
 *     //enable ep
 *     void *ep_handle = hal_usb_ep_handle_get(ep addr);
 *     hal_usb_ep_enable(ep_handle , ep desc);
 *
 *     //alloc URB
 *     T_HAL_USB_ISO_REQUEST_BLOCK *iso_ep_urb = hal_usb_iso_urb_alloc(len);
 *     iso_ep_urb->length = length of data to transfer
 *     memcpy(iso_ep_urb->buf, data, iso_ep_urb->length)
 *     iso_ep_urb->complete = iso_ep_request_complete;
 *     iso_ep_urb->ep_handle = ep_handle;
 *
 *     //start transfer--For both send & receive
 *     hal_usb_iso_ep_start(ep_handle, iso_ep_urb);
 * \endcode
 *
 * \section HAL_POWER_MANAGER Power Manager
 *  To limit power consumption, the USB PHY will partially power down when the device suspends by calling
 *  \ref hal_usb_suspend_enter in \ref HAL_USB_COMMON_ISR_SUSPEND. If you quit the suspend state, a suspendn
 *  interrupt will be triggered, and \ref hal_usb_suspend_exit \b should be called in the suspendn interrupt,
 *  followed by \ref HAL_USB_COMMON_ISR_RESUME.
 *
 * \par Example
 * \code
 *
 *      void usb_suspendn_isr_handler(T_HAL_USB_IRQ isr, T_HAL_USB_ISR_PARAM *param)
 *      {
 *        usb_dm_suspend_exit();
 *      }
 *
 *      static T_HAL_USB_ISR_HOOKS usb_suspendn_isr_hooks =
 *      {
 *          .enter = NULL,
 *          .handler = usb_suspendn_isr_handler,
 *          .exit = NULL,
 *      };
 *      enable suspendn interrupt
 *      hal_usb_isr_update(HAL_USB_IRQ_GROUP_SUSPENDN, (T_HAL_USB_ISR_HOOKS *)&usb_suspendn_isr_hooks);
 * \endcode
 */
/** @}*/

/** @defgroup USB_HAL_Exported_Constants USB HAL Exported Constants
  * @{
  */

/**
 * @brief USB interrupt group offset.
 */
#define HAL_USB_IRQ_GROUP_OFFSET        (16)

/**
 * @brief USB interrupt group offset.
 */
#define HAL_USB_IRQ_GROUP_NONE          (0 << HAL_USB_IRQ_GROUP_OFFSET)
/**
 * @brief USB interrupt group offset.
 */
#define HAL_USB_IRQ_GROUP_SYS           (1 << HAL_USB_IRQ_GROUP_OFFSET)
/**
 * @brief USB interrupt group offset.
 */
#define HAL_USB_IRQ_GROUP_IEP0          (2 << HAL_USB_IRQ_GROUP_OFFSET)
/**
 * @brief USB interrupt group offset.
 */
#define HAL_USB_IRQ_GROUP_IEPn          (3 << HAL_USB_IRQ_GROUP_OFFSET)
/**
 * @brief USB interrupt group offset.
 */
#define HAL_USB_IRQ_GROUP_OEP0          (4 << HAL_USB_IRQ_GROUP_OFFSET)
/**
 * @brief USB interrupt group offset.
 */
#define HAL_USB_IRQ_GROUP_OEPn          (5 << HAL_USB_IRQ_GROUP_OFFSET)
/**
 * @brief USB interrupt group offset.
 */
#define HAL_USB_IRQ_GROUP_SUSPENDN      (6 << HAL_USB_IRQ_GROUP_OFFSET)

/**
 * @brief USB interrupt group offset.
 */
#define HAL_USB_SYS_IRQ_NONE            (0 | HAL_USB_IRQ_GROUP_SYS)
/**
 * @brief USB interrupt group offset.
 */
#define HAL_USB_SYS_IRQ_RESET           (1 | HAL_USB_IRQ_GROUP_SYS)
/**
 * @brief USB interrupt group offset.
 */
#define HAL_USB_SYS_IRQ_ENUM_DONE       (2 | HAL_USB_IRQ_GROUP_SYS)
/**
 * @brief USB interrupt group offset.
 */
#define HAL_USB_SYS_IRQ_SUSPEND         (3 | HAL_USB_IRQ_GROUP_SYS)
/**
 * @brief USB interrupt group offset.
 */
#define HAL_USB_SYS_IRQ_RESUME          (4 | HAL_USB_IRQ_GROUP_SYS)

/**
 * @brief USB interrupt group offset.
 */
#define HAL_USB_IEP0_IRQ_NONE           (0 | HAL_USB_IRQ_GROUP_IEP0)
/**
 * @brief USB interrupt group offset.
 */
#define HAL_USB_IEP0_IRQ_XFER_DONE      (1 | HAL_USB_IRQ_GROUP_IEP0)

/**
 * @brief USB interrupt group offset.
 */
#define HAL_USB_IEPn_IRQ_NONE           (0 | HAL_USB_IRQ_GROUP_IEPn)
/**
 * @brief USB interrupt group offset.
 */
#define HAL_USB_IEPn_IRQ_XFER_DONE      (1 | HAL_USB_IRQ_GROUP_IEPn)
/**
 * @brief USB interrupt group offset.
 */
#define HAL_USB_IEPn_IRQ_NAK            (2 | HAL_USB_IRQ_GROUP_IEPn)

/**
 * @brief USB interrupt group offset.
 */
#define HAL_USB_OEP0_IRQ_NONE           (0 | HAL_USB_IRQ_GROUP_OEP0)
/**
 * @brief USB interrupt group offset.
 */
#define HAL_USB_OEP0_IRQ_XFER_DONE      (1 | HAL_USB_IRQ_GROUP_OEP0)
/**
 * @brief USB interrupt group offset.
 */
#define HAL_USB_OEP0_IRQ_SETUP          (2 | HAL_USB_IRQ_GROUP_OEP0)

/**
 * @brief USB interrupt group offset.
 */
#define HAL_USB_OEPn_IRQ_NONE           (0 | HAL_USB_IRQ_GROUP_OEPn)
/**
 * @brief USB interrupt group offset.
 */
#define HAL_USB_OEPn_IRQ_XFER_DONE      (1 | HAL_USB_IRQ_GROUP_OEPn)

/**
 * @brief USB interrupt group offset.
 */
#define HAL_USB_SUSPENDN_IRQ            (1 | HAL_USB_IRQ_GROUP_SUSPENDN)

/**
 * @brief USB speed type.
 *
 */
typedef enum {HAL_USB_SPEED_FULL, HAL_USB_SPEED_HIGH, HAL_USB_SPEED_UNSUPPORTED} T_HAL_USB_SPEED;

/** End of group USB_HAL_Exported_Constants
  * @}
  */

/** @defgroup USB_HAL_Exported_Types USB HAL Exported Types
  * @{
  */

/**
 * \brief USB request block, USB data transfer entity.
 *
 * \param length The length of data that will be sent or received.
 * \param actual The actual length of data that has been sent or received.
 * \param buf The buffer that stores data will be sent or has been received.
 * \param zlp Send a zero-length packet when the length is equal to the maximum packet size of the endpoint.
 * \param complete_in_isr 1: \ref The complete callback will be called in ISR. \n
 *                        0: \ref The complete callback will not be called in ISR, and the URB will be transferred
 *                           through \ref HAL_USB_IEPn_IRQ_XFER_DONE.
 * \param status The status of the data transfer.
 * \param ep_handle The handle of endpoint that will transfer data.
 * \param complete The callback will be called when data that has been sent or received. \n
 *                 For sending data, this callback is mainly used to indicate the result of data sending. \n
 *                 For receiving data, this callback is used to get the data already received and related information.
 * \param priv The private data.
 *
 */
typedef struct _hal_usb_request_block
{
    int length;
    int actual;
    uint8_t *buf;

    uint8_t zlp: 1;
    uint8_t complete_in_isr: 1;
    uint8_t rsv: 6;

    int status;
    void *ep_handle;
    int (*complete)(struct _hal_usb_request_block *urb);

    void *priv;

} T_HAL_USB_REQUEST_BLOCK;

/**
 * \brief USB isochronous packet information.
 * \details For isochronous transfer, multiple packets can be sent at once. For example, if USB speed is high and
 *          bInterval of isochronous endpoint is 3, the host will send a \b token packet every 0.5ms, but the upper
 *          application may prepare data every 2 ms. In this case, the upper application can process 4 packets
 *          at a time.
 *
 * \param offset The offset of the current packet in \ref buf of \ref T_HAL_USB_ISO_REQUEST_BLOCK.
 * \param actual The actual length of the current packet.
 * \param status The status of the current packet transferred.
 *
 */
typedef struct _hal_usb_iso_pkt_info
{
    uint32_t offset;
    uint32_t actual;
    int status;
} T_HAL_USB_ISO_PKT_INFO;

/**
 * \brief USB isochronous request block.
 * \details For isochronous transfer, ping-pong buffers are used to manage data transfer. For example, if the current
 *          data transfer uses buf0, the next data transfer will use buf1, and this alternation continues between the
 *          two buffers. The interval at which data is processed is determined by both the bInterval field in the
 *          endpoint descriptor and buf_proc_intrvl. The formula to calculate the data processing interval is:
 *          `2^(bInterval - 1) * buf_proc_intrvl * 125us`.
 *
 * \param buf0 The buffer 0 of ping-pong buffers.
 * \param buf1 The buffer 1 of ping-pong buffers.
 * \param data_per_frame The data length per host polling.
 * \param buf_proc_intrvl The number of the host polling per data process.
 * \param pkt_cnt The packet number per data process.
 * \param iso_pkt0 The packets information stored in \ref buf0, refer to \ref T_HAL_USB_ISO_PKT_INFO.
 * \param iso_pkt1 The packets information stored in \ref buf1, refer to \ref T_HAL_USB_ISO_PKT_INFO.
 * \param ep_handle The handle of endpoint that will transfer data.
 * \param complete The callback will be called when data has been sent or received. \n
 *                 For sending data, the upper application SHOULD prepare data in the buffer indexed by \ref proc_buf_num. \n
 *                 For receiving data, the upper application SHOULD process data stored in the buffer indexed by \ref proc_buf_num. \n
 * \param priv The private data.
 *
 */
typedef struct _hal_usb_iso_request_block
{
    uint8_t *buf0;
    uint8_t *buf1;

    uint32_t data_per_frame;
    uint32_t buf_proc_intrvl;

    uint8_t pkt_cnt;
    T_HAL_USB_ISO_PKT_INFO *iso_pkt0;
    T_HAL_USB_ISO_PKT_INFO *iso_pkt1;
    void *ep_handle;
    int (*complete)(struct _hal_usb_iso_request_block *urb, uint8_t proc_buf_num);

    void *priv;
} T_HAL_USB_ISO_REQUEST_BLOCK;

/**
 * \brief The parameter of the ISR handler in \ref T_HAL_USB_ISR_HOOKS.
 * \param enum_done: Used in \ref HAL_USB_SYS_IRQ_ENUM_DONE.
 * \param setup: Used in \ref HAL_USB_OEP0_IRQ_SETUP.
 * \param xfer_done: Used in \ref HAL_USB_IEPn_IRQ_XFER_DONE.
 *
 */
typedef union _hal_usb_isr_param
{
    struct
    {
        T_HAL_USB_SPEED speed;
    } enum_done;

    struct
    {
        uint8_t *setup_pkt;
    } setup;

    struct
    {
        uint8_t is_iso;
        union
        {
            T_HAL_USB_REQUEST_BLOCK *urb;
            T_HAL_USB_ISO_REQUEST_BLOCK *iso_urb;
        };
    } xfer_done;

    struct
    {
        uint8_t ep_addr;
    } nak;

} T_HAL_USB_ISR_PARAM;

/**
 * @brief USB interrupt type.
 */
typedef uint32_t T_HAL_USB_IRQ;


typedef void (*HAL_USB_ISR_ENTER)(void);
typedef void (*HAL_USB_ISR_HANDLER)(T_HAL_USB_IRQ irq, T_HAL_USB_ISR_PARAM *param);
typedef void (*HAL_USB_ISR_EXIT)(void);

/**
 * \brief USB ISR Hooks.
 * \param enter: Called at the beginning of the common ISR.
 * \param handler: The handler of the ISR defined in \ref HAL_USB_ISR_HANDLER.
 * \param exit: Called at the end of the common ISR.
 *
 */
typedef struct _hal_usb_isr_hooks
{
    HAL_USB_ISR_ENTER enter;
    HAL_USB_ISR_HANDLER handler;
    HAL_USB_ISR_EXIT exit;
} T_HAL_USB_ISR_HOOKS;

/** End of group USB_HAL_Exported_Types
  * @}
  */

/** @defgroup USB_HAL_Exported_Functions USB HAL Exported Functions
  * @{
  */

/**
 * @brief Update USB ISR hooks.
 * @param irq_group: USB interrupt group.
 * @param hooks: USB interrupt hooks refer to \ref T_HAL_USB_ISR_HOOKS.
 * @return Refer to `errno.h`.
 *
 * @par Example
 * Please refer to  \ref HAL_Usage_Chapter.
 */
int hal_usb_isr_update(uint32_t irq_group, T_HAL_USB_ISR_HOOKS *hooks);

/**
 * @brief Set USB device address, the function \b should be called to process SET_ADDRESS request.
 *
 * @param addr Device address.
 * @return Refer to `errno.h`.
 *
 * @par Example
 * @code
 *      #include "usb_spec20.h"
 *      int setup_cb(uint8_t *data)
 *      {
 *          T_USB_DEVICE_REQUEST *ctrl_request = (T_USB_DEVICE_REQUEST *)data;
 *          ret = 0;
 *          if(ctrl_request->bmRequestType & USB_TYPE_MASK == USB_TYPE_STANDARD)
 *          {
 *              if(ctrl_request->bRequest == USB_REQ_CODE_SET_ADDRESS)
 *              {
 *                  ret = hal_usb_set_address(UGETW(ctrl_request->wValue));
 *              }
 *          }
 *          return ret;
 *      }
 * @endcode
 *
 */
int hal_usb_set_address(uint8_t addr);

/**
 * @brief Allocate URB for data transferring.
 *
 * @param buf_len Length of buffer to store data.
 * @return T_HAL_USB_REQUEST_BLOCK* NULL: fail, other: success.
 * @par Example
 * Please refer to "Data transfer" in \ref HAL_Usage_Chapter.
 *
 */
T_HAL_USB_REQUEST_BLOCK *hal_usb_urb_alloc(uint32_t buf_len);

/**
 * @brief Free URB allocated by \ref hal_usb_urb_alloc.
 *
 * @param urb Allocated by \ref hal_usb_urb_alloc.
 * @return Refer to `errno.h`.
 *
 */
int hal_usb_urb_free(T_HAL_USB_REQUEST_BLOCK *urb);

/**
 * @brief Allocate isochronous URB for data transferring.
 *
 * @param buf_len Length of buffer to store data.
 * @return T_HAL_USB_ISO_REQUEST_BLOCK* NULL: fail, other: success.
 * @par Example
 * Please refer to "Data transfer" in \ref HAL_Usage_Chapter.
 *
 */
T_HAL_USB_ISO_REQUEST_BLOCK *hal_usb_iso_urb_alloc(uint32_t buf_len);

/**
 * \brief Free isochronous URB allocated by \ref hal_usb_iso_urb_alloc.
 *
 * \param urb Allocated by \ref hal_usb_iso_urb_alloc
 * \return Refer to `errno.h`.
 */
int hal_usb_iso_urb_free(T_HAL_USB_ISO_REQUEST_BLOCK *urb);

/**
 * \brief Get endpoint handle, the return value is necessary for all endpoint related functions,
 *        including `hal_usb_ep_xxx` and `hal_usb_iso_ep_xxx`.
 *
 * \param addr The endpoint address.
 * \return The endpoint handle.
 *
 * \par Example
 * Please refer to `Endpoint Setup` in \ref HAL_Usage_Chapter.
 */
void *hal_usb_ep_handle_get(uint8_t addr);

/**
 * \brief Enable the endpoint, the function should be called when receiving a `set_alt` request.
 *
 * \param ep_handle Returned by \ref hal_usb_ep_handle_get.
 * \param desc The endpoint descriptor.
 * \return Refer to `errno.h`.
 *
 * \par Example
 * Please refer to `Endpoint Setup` in \ref HAL_Usage_Chapter.
 */
int hal_usb_ep_enable(void *ep_handle, void *desc);

/**
 * \brief Disable endpoint, the function should be called when receiving a `set_alt` request.
 *
 * \param ep_handle Returned by \ref hal_usb_ep_handle_get.
 * \return Refer to `errno.h`.
 *
 * \par Example
 * Please refer to `Data Transfer` in \ref HAL_Usage_Chapter.
 */
int hal_usb_ep_disable(void *ep_handle);

/**
 * \brief The endpoint 0 sends data to the host or receives data from the host.
 *
 * \param ep_handle The handle of endpoint 0.
 * \param urb The URB returned by \ref hal_usb_urb_alloc.
 * \return Refer to `errno.h`.
 *
 * \par Example
 * Please refer to `Data transfer` in \ref HAL_Usage_Chapter.
 */
int hal_usb_ep0_trx(void *ep_handle, T_HAL_USB_REQUEST_BLOCK *urb);

/**
 * \brief Non zero endpoint sends data to the host except isochronous endpoints.
 *
 * \param ep_handle The handle of the endpoint, returned by \ref hal_usb_ep_handle_get.
 * \param urb The URB returned by \ref hal_usb_urb_alloc.
 * \return Refer to `errno.h`.
 *
 * \par Example
 * Please refer to `Data Transfer` in \ref HAL_Usage_Chapter.
 */
int hal_usb_ep_tx(void *ep_handle, T_HAL_USB_REQUEST_BLOCK *urb);

/**
 * \brief Non zero endpoint receives data from the host except isochronous endpoints.
 *
 * \param ep_handle The handle of the endpoint.
 * \param urb The URB returned by \ref hal_usb_urb_alloc.
 * \return Refer to `errno.h`.
 *
 * \par Example
 * Please refer to `Data Transfer` in \ref HAL_Usage_Chapter.
 */
int hal_usb_ep_rx(void *ep_handle, T_HAL_USB_REQUEST_BLOCK *urb);

/**
 * \brief Halt the interrupt/bulk endpoints or return \b stall in the \b in status stage of the control transfer. \n
 *        For endpoint 0, the API is used when the request is not supported or other errors occur,
 *        the device will return \b stall in the \b in status stage of the control transfer. \n
 *        For non zero endpoint, the API is used when processing the `SetFeature(ENDPOINT_HALT)` request.
 *
 * \param ep_handle The endpoint handle, returned by \ref hal_usb_ep_handle_get.
 * \param err Error that causes a stall.
 * \return Refer to `errno.h`.
 *
 * \par Example
 * \code
 *      //endpoint0
 *       int setup_cb(uint8_t *data)
 *      {
 *          if request is not supported
 *          {
 *              hal_usb_ep_stall_set(ep0_handle, -ENOTSUPP);
 *          }
 *          return -ENOTSUPP;
 *      }
 *
 *      //interrupt/bulk endpoints
 *  *   int setup_cb(uint8_t *data)
 *      {
 *          if request is SetFeature(ENDPOINT_HALT)
 *          {
 *               uint8_t addr = UGETW(wIndex);
 *               void *ep_handle = hal_usb_ep_handle_get(addr);
 *              hal_usb_ep_stall_set(ep_handle, 0);
 *          }
 *          return 0;
 *      }
 *
 * \endcode
 */
int hal_usb_ep_stall_set(void *ep_handle, int err);

/**
 * \brief Clear endpoint halt when processing the `ClearFeature(ENDPOINT_HALT)` request.
 *
 * \param ep_handle The endpoint handle, returned by \ref hal_usb_ep_handle_get.
 * \return Refer to `errno.h`.
 *
 * \par Example
 * \code
 *
 *      //interrupt/bulk endpoints
 *  *   int setup_cb(uint8_t *data)
 *      {
 *          if request is ClearFeature(ENDPOINT_HALT)
 *          {
 *               uint8_t addr = UGETW(wIndex);
 *               void *ep_handle = hal_usb_ep_handle_get(addr);
 *              hal_usb_ep_stall_clear(ep_handle);
 *          }
 *          return 0;
 *      }
 *
 * \endcode
 */
int hal_usb_ep_stall_clear(void *ep_handle);

/**
 * \brief Get endpoint stall status when processing the `GetStatus(ENDPOINT)` request.
 *
 * \param ep_handle The endpoint handle.
 * \return The status.
 *
 * \par Example
 * \code
 *
 *      int setup_cb(uint8_t *data)
 *      {
 *          ...
 *          if request is  GetStatus(ENDPOINT)
 *          {
 *               uint8_t addr = UGETW(wIndex);
 *               void *ep_handle = hal_usb_ep_handle_get(addr);
 *               uint16_t status = hal_usb_ep_stall_status_get(ep_handle);
 *               memcpy(ctrl_urb->buf, &status, 2);
 *               ....
 *          }
 *          return 0;
 *      }
 *
 * \endcode
 */
uint16_t hal_usb_ep_stall_status_get(void *ep_handle);

/**
 * \brief Start the isochronous transfer.
 *
 * \param ep_handle The isochronous endpoint, returned by \ref hal_usb_ep_handle_get.
 * \param iso_urb The isochronous URB, returned by \ref hal_usb_iso_urb_alloc.
 * \return Refer to `errno.h`.
 * \par Example
 * Please refer to `Data Transfer` in \ref HAL_Usage_Chapter.
 */
int hal_usb_iso_ep_start(void *ep_handle, T_HAL_USB_ISO_REQUEST_BLOCK *iso_urb);

/**
 * \brief  Stop the isochronous transfer.
 *
 * \param ep_handle The isochronous endpoint, returned by \ref hal_usb_ep_handle_get.
 * \param iso_urb The isochronous URB, returned by \ref hal_usb_iso_urb_alloc.
 * \return Refer to `errno.h`.
 * \par Example
 * Please refer to `Data Transfer` in \ref HAL_Usage_Chapter.
 */
int hal_usb_iso_ep_stop(void *ep_handle, T_HAL_USB_ISO_REQUEST_BLOCK *iso_urb);

/**
 * \brief Initialize HAL software resources.
 *
 * \return Refer to `errno.h`.
 *
 * \par Example
 * Please refer to `Hardware Setup` in \ref HAL_Usage_Chapter.
 */
int hal_usb_init(void);

/**
 * \brief Deinit HAL software resources.
 *
 * \return Refer to `errno.h`.
 */
int hal_usb_deinit(void);

/**
 * \brief Set USB default speed, which is used to initialize hardware.
 *
 * \param speed Refer to \ref T_HAL_USB_SPEED.
 * \return Refer to `errno.h`.
 *
 * \par Example
 * Please refer to `Hardware Setup` in \ref HAL_Usage_Chapter.
 */
int hal_usb_speed_set(T_HAL_USB_SPEED speed);

/**
 * \brief Remote wakeup the host, if the `bmAttributes` in the configure descriptor support remote wakeup.
 *
 * \return Refer to `errno.h`.
 */
int hal_usb_remote_wakeup(void);

/**
 * \brief Initialize USB MAC.
 *
 * \return Refer to `errno.h`.
 * \par Example
 * Please refer to `Hardware Setup` in \ref HAL_Usage_Chapter.
 */
int hal_usb_mac_init(void);

/**
 * \brief Deinit USB MAC.
 *
 * \return Refer to `errno.h`.
 */
int hal_usb_mac_deinit(void);

/**
 * \brief Power on USB PHY.
 *
 * \return Refer to `errno.h`.
 * \par Example
 * Please refer to `Hardware Setup` in \ref HAL_Usage_Chapter.
 */
int hal_usb_phy_power_on(void);

/**
 * \brief Power down USB PHY.
 *
 * \return Refer to `errno.h`.
 */
int hal_usb_phy_power_down(void);

/**
 * \brief Generate a connect signal to the host.
 *
 * \return Refer to `errno.h`.
 * \par Example
 * Please refer to `Hardware Setup` in \ref HAL_Usage_Chapter.
 */
int hal_usb_soft_attach(void);

/**
 * \brief Generate a disconnect signal to the host.
 *
 * \return Refer to `errno.h`.
 */
int hal_usb_soft_detach(void);

/**
 * \brief Enable dedicated isochronous interrupt.
 */
void hal_usb_isoc_interrupt_enable(void);

/**
 * @brief Disable dedicated isochronous interrupt.
 *
 */
void hal_usb_isoc_interrupt_disable(void);

/**
 * @brief Disable the global interrupt to the application.
 *
 */
void hal_usb_global_isr_disable(void);

/**
 * @brief Enable the global interrupt to the application.
 *
 */
void hal_usb_global_isr_enable(void);

/**
 * @brief Enable endpoint 0 interrupt.
 */
void hal_usb_ep0_isr_enable(void);

/**
 * @brief Disable endpoint 0 interrupt.
 */
void hal_usb_ep0_isr_disable(void);

/**
 * @brief Enable in endpoint interrupt.
 *
 * @param endpoint Number.
 */
void hal_usb_in_ep_isr_enable(uint8_t num);

/**
 * @brief Disable in endpoint interrupt.
 *
 * @param endpoint Number.
 */
void hal_usb_in_ep_isr_disable(uint8_t num);

/**
 * @brief Enable out endpoint interrupt.
 *
 * @param endpoint Number.
 */
void hal_usb_out_ep_isr_enable(uint8_t num);

/**
 * @brief Disable out endpoint interrupt.
 *
 * @param endpoint Number.
 */
void hal_usb_out_ep_isr_disable(uint8_t num);
/**
 * @brief USB phy enter suspend mode.
 *
 * @return Refer to `errno.h`.
 */
int hal_usb_suspend_enter(void);

/**
 * @brief USB PHY exits suspend mode.
 *
 * @return  Refer to `errno.h`.
 */
int hal_usb_suspend_exit(void);

/**
 * @brief USB PHY sets status.
 *
 * @return Refer to `errno.h`.
 */
int hal_usb_wakeup_status_clear(void);

/**
 * \brief USB PHY gets status.
 *
 * \return If the status is set to 1, USB wakes up.
 */
int hal_usb_wakeup_status_get(void);

/**
 * \brief USB processes test mode requests.
 *
 * \param sel Test mode selector.
 * \return Refer to `errno.h`.
 *
 */
int hal_usb_do_test_mode(uint8_t sel);
/** @} */ /* End of group USB_HAL_Exported_Functions */
/** @}*/

#endif
