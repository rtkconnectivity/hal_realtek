/**
*********************************************************************************************************
*               Copyright(c) 2015, Realtek Semiconductor Corporation. All rights reserved.
**********************************************************************************************************
* @file     ota_service.h
* @brief
* @details
* @author   hunter_shuai
* @date     14-July-2015
* @version  v1.0.0
******************************************************************************
* @attention
* <h2><center>&copy; COPYRIGHT 2015 Realtek Semiconductor Corporation</center></h2>
******************************************************************************
*/

#ifndef _OTA_SERVICE_H_
#define _OTA_SERVICE_H_


#ifdef __cplusplus
extern "C"  {
#endif      /* __cplusplus */

#include "dfu_api.h"
/** @brief  Demo Profile service related UUIDs. */

#define GATT_UUID_CHAR_OTA                          0xFFD1  //1
#define GATT_UUID_CHAR_MAC                          0xFFD2  //2
#define GATT_UUID_CHAR_PATCH                        0xFFD3  //3
#define GATT_UUID_CHAR_APP_VERSION                  0xFFD4  //4
#define GATT_UUID_CHAR_PATCH_EXTENSION              0xFFD5  //5
#define GATT_UUID_CHAR_TEST_MODE                    0xFFD8  //6

#define GATT_UUID_CHAR_DEVICE_INFO                  0xFFF1  //7
#define GATT_UUID_CHAR_IMAGE_COUNT_TO_UPDATE        0xFFF2  //8
#define GATT_UUID_CHAR_IMAGE_VERSION0               0xFFE0  //mandatory when OTA version >= 1
#define GATT_UUID_CHAR_IMAGE_VERSION1               0xFFE1
#define GATT_UUID_CHAR_IMAGE_VERSION2               0xFFE2
#define GATT_UUID_CHAR_PROTOCOL_TYPE                0xFFF3

/** @brief  Index of each characteristic in Demo Profile service database. */
#define BLE_SERVICE_CHAR_OTA_INDEX                  0x02 /**< attr write */
#define BLE_SERVICE_CHAR_MAC_ADDRESS_INDEX          0x04 /**< attr read */
#define BLE_SERVICE_CHAR_PATCH_INDEX                0x06 /**< attr read */
#define BLE_SERVICE_CHAR_APP_VERSION_INDEX          0x08 /**< attr read */
#define BLE_SERVICE_CHAR_PATCH_EXTENSION_INDEX      0x0a /**< attr read */
#define BLE_SERVICE_CHAR_TEST_MODE_INDEX            0x0c /**< attr write */
#define BLE_SERVICE_CHAR_DEVICE_INFO_INDEX          0x0e /**< attr read */
#define BLE_SERVICE_CHAR_IMAGE_COUNT_INDEX          0x10 /**< attr write */
#define BLE_SERVICE_CHAR_IMAGE_VERSION_INDEX        0x12 /**< attr read */
#define BLE_SERVICE_CHAR_IMAGE_VERSION0_INDEX       0x12 /**< attr read */
#define BLE_SERVICE_CHAR_IMAGE_VERSION1_INDEX       0x14 /**< attr read */
#define BLE_SERVICE_CHAR_IMAGE_VERSION2_INDEX       0x16 /**< attr read */
#define BLE_SERVICE_CHAR_PROTOCOL_TYPE_INDEX        0x18 /**< attr read */

/** @brief OTA Read callback data type definition.*/
#define OTA_READ_CHAR_MAC_ADDRESS_INDEX             0x01
#define OTA_READ_CHAR_PATCH_INDEX                   0x02
#define OTA_READ_CHAR_APP_VERSION_INDEX             0x03
#define OTA_READ_CHAR_PATCH_EXTENSION_INDEX         0x04
#define OTA_READ_CHAR_DEVICE_INFO_INDEX             0x05
#define OTA_READ_CHAR_IMAGE_VERSION_INDEX           0x06
#define OTA_READ_CHAR_PROTOCOL_TYPE_INDEX           0x07


/** @brief OTA Write callback data type definition.*/
#define OTA_WRITE_CHAR_VAL                          0x01 /**< switch ota mode write opcode */
#define OTA_VALUE_ENTER                             0x01 /**< switch ota mode write value */

/** @brief OTA Write callback data type definition.*/
#define OTA_WRITE_TEST_MODE_CHAR_VAL                0x02 /**< test mode write opcode */

/** @brief OTA Write callback data type definition.*/
#define OTA_WRITE_IMAGE_COUNT_VAL                   0x02 /**< image count write opcode */
#define OTA_VALUE_IMAGE_COUNT_APP_ONLY              0x01
#define OTA_VALUE_IMAGE_COUNT_PATCH_ONLY            0x02
#define OTA_VALUE_IMAGE_COUNT_APP_AND_PATCH         0x03

#define OTA_CHAR_IMAGE_COUNT_LEN                    5

#define CHAR2SHORT(p) (((*(p)) & 0xff) + ((*((p)+1)) << 8))

typedef struct _T_DFU_DEVICE_INFO
{
    uint8_t ic_type;
    uint8_t spec_version;
    uint8_t secure_version;
    T_OTA_MODE ota_mode;

    uint16_t max_buffer_size;
    uint8_t temp_bank_size; //Unit:4K, 0x00:No Limitation of OTA Temp Buffer Size,Only available when Updating Multi Image at a time  is supported.
    uint8_t rsvd;
    uint32_t img_indicator;
    uint16_t image_crtl_header_offset;
    uint16_t compressed_image_crtl_header_offset;

} T_DFU_DEVICE_INFO, *P_DFU_DEVICE_INFO;

typedef struct _T_OTA_UPDATE_IMAGE_INFO
{
    uint8_t image_count;
    uint16_t update_patch_version;
    uint16_t update_app_version;
} T_OTA_UPDATE_IMAGE_INFO;

typedef struct _T_OTA_WRITE_MSG
{
    uint8_t opcode;
    union
    {
        uint8_t value;
        T_OTA_UPDATE_IMAGE_INFO update_image_info;
    } u;
} T_OTA_WRITE_MSG;

typedef union _T_OTA_UPSTREAM_MSG_DATA
{
    uint8_t notification_indification_index;
    uint8_t read_value_index;
    T_OTA_WRITE_MSG write;
} T_OTA_UPSTREAM_MSG_DATA;


#ifdef __cplusplus
}
#endif

#endif
