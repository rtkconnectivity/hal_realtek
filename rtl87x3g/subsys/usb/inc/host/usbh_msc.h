#ifndef __USBH_MSC_H__
#define __USBH_MSC_H__
#include <stdint.h>

typedef struct _usbh_msc_operation_status
{
    uint8_t success;
    uint8_t skey;
    uint8_t asc;
} T_USBH_MSC_OP_STATUS;

typedef struct _usbh_msc_wr_param
{
    uint8_t *buf;
    uint32_t lba;
    uint8_t blk_actual;
} T_USBH_MSC_RW_PARAM;

typedef union _usbh_msc_operation_param
{
    T_USBH_MSC_RW_PARAM rw;
} T_USBH_MSC_OP_PARAM;

typedef struct _usb_disk_capacity
{
    uint32_t lba;
    uint32_t blk_len;
} T_USB_DISK_CAPACITY;

typedef int (*USBH_MSC_USER_CB)(T_USBH_MSC_OP_PARAM, T_USBH_MSC_OP_STATUS);

T_USB_DISK_CAPACITY usbh_msc_capacity_get(uint8_t lun);

int usbh_msc_read(uint8_t lun, uint8_t *buf, uint32_t lba, uint32_t blk_cnt, bool sync,
                  USBH_MSC_USER_CB complete, uint32_t timeout);

int usbh_msc_write(uint8_t lun, uint8_t *buf, uint32_t lba, uint32_t blk_cnt,  bool sync,
                   USBH_MSC_USER_CB complete, uint32_t timeout);

bool usbh_msc_is_ready(uint8_t lun);

int32_t usbh_msc_init(void);
#endif // !__USBH_MSC_H__
