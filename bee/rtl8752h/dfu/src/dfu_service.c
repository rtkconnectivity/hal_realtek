/*
 * Copyright (c) 2025 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/hci.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/uuid.h>
#include <zephyr/bluetooth/gatt.h>

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(DFU, CONFIG_DFU_LOG_LEVEL);
#include "log_adapter.h"

#include "patch_header_check.h"
#include "rtl876x_wdg.h"
#include "flash_nor_device.h"
#include "dfu_flash.h"
#include "dfu_api.h"
#include "dfu_service.h"
#include "otp.h"
#include "board.h"
#include "gap.h"
#include "dfu_application.h"
#include "silent_ota_application.h"
/*============================================================================*
 *                               Variables
 *============================================================================*/
T_DFU_PARA g_dfu_para;
uint8_t *p_ota_temp_buffer_head;
uint16_t g_ota_tmp_buf_used_size;
uint8_t temp_image_num = 0;
T_TEMP_IMAGE_INFO temp_image_info[IMAGE_MAX - SecureBoot];

uint8_t  __ALIGNED(4) ota_temp_buffer_head[DFU_TEMP_BUFFER_SIZE];
static bool buffer_check_en = false;
bool is_ota_procedure = false;
static uint32_t dfu_resend_offset = 0;
static uint8_t dfu_service_id;
typedef T_APP_RESULT(*P_FUN_SERVER_GENERAL_CB)(uint8_t service_id, void *p_para);
P_FUN_SERVER_GENERAL_CB pfn_dfu_service_cb = app_profile_callback;

/*============================================================================*
 *                        Extern Declarations
 *============================================================================*/

void dfu_service_handle_control_point_req(struct bt_conn *conn, uint16_t length, uint8_t *p_value);

uint8_t dfu_add_service(void *pFunc)
{
    p_ota_temp_buffer_head = ota_temp_buffer_head;
    return 0;
}

/**
 * @brief dfu_service_handle_packet_req
 *
 * @param length     data reviewed length.
 * @param p_value    data receive point address.
 * @return None
 */
void dfu_service_handle_packet_req(struct bt_conn *conn, uint16_t length, uint8_t *p_value)
{
    T_APP_RESULT w_cause = APP_RESULT_SUCCESS;
    T_DFU_CALLBACK_DATA callback_data;
    callback_data.conn = conn;
    callback_data.msg_type = SERVICE_CALLBACK_TYPE_WRITE_CHAR_VALUE;
    callback_data.msg_data.write.write_attrib_index = INDEX_DFU_PACKET_VALUE;
    callback_data.msg_data.write.length = length;
    callback_data.msg_data.write.p_value = p_value;

    DFU_PRINT_INFO4("dfu_service_handle_packet_req: length=%d, cur_offset=%d, "
                    "g_ota_tmp_buf_used_size=%d, image_total_length=%d",
                    length, g_dfu_para.cur_offset, g_ota_tmp_buf_used_size,
                    g_dfu_para.image_total_length);

    /*if haven't started dfu, send data directly, do nothing*/
    if (!is_ota_procedure)
    {
        return;
    }

    if (buffer_check_en == true)
    {
        /*to avoid memory overflow*/
        if (g_ota_tmp_buf_used_size + length > DFU_TEMP_BUFFER_SIZE)
        {
            DFU_PRINT_ERROR3("<==dfu_service_handle_packet_req: Buf overflow! "
                             "ota_tmp_buf_used_size=%d,length=%d, max_buffer_size=%d",
                             g_ota_tmp_buf_used_size, length, DFU_TEMP_BUFFER_SIZE);

            T_DFU_FAIL_REASON dfu_fail_reason = DFU_FAIL_EXCEED_MAX_BUFFER_SIZE;
            callback_data.msg_data.write.length = sizeof(T_DFU_FAIL_REASON);
            callback_data.msg_data.write.p_value = (uint8_t *)&dfu_fail_reason;
            callback_data.msg_data.write.opcode = DFU_WRITE_FAIL;
            if (pfn_dfu_service_cb)
            {
                w_cause =
                    pfn_dfu_service_cb(dfu_service_id, (void *)&callback_data);
                if (w_cause != APP_RESULT_SUCCESS)
                {
                    return;
                }
            }

            dfu_fw_reboot(false);
        }
        else
        {
            memcpy(p_ota_temp_buffer_head + g_ota_tmp_buf_used_size, p_value, length);
            g_ota_tmp_buf_used_size += length;
        }
    }
    else
    {
        /*when disable buffer check, Default client send 20bytes per packet*/
        uint32_t max_buffer_size = DFU_TEMP_BUFFER_SIZE - (DFU_TEMP_BUFFER_SIZE % 20);
        /*0.check memcpy buffer boundary*/
        if (g_ota_tmp_buf_used_size + length > max_buffer_size)
        {
            DFU_PRINT_ERROR3("<==dfu_service_handle_packet_req: Buf overflow! "
                             "ota_tmp_buf_used_size=%d,length=%d, max_buffer_size=%d",
                             g_ota_tmp_buf_used_size, length, max_buffer_size);

            T_DFU_FAIL_REASON dfu_fail_reason = DFU_FAIL_EXCEED_MAX_BUFFER_SIZE;
            callback_data.msg_data.write.opcode = DFU_WRITE_FAIL;
            callback_data.msg_data.write.length = sizeof(T_DFU_FAIL_REASON);
            callback_data.msg_data.write.p_value = (uint8_t *)&dfu_fail_reason;
            if (pfn_dfu_service_cb)
            {
                w_cause =
                    pfn_dfu_service_cb(dfu_service_id, (void *)&callback_data);
                if (w_cause != APP_RESULT_SUCCESS)
                {
                    return;
                }
            }

            dfu_fw_reboot(false);
        }

        /*0.check total length*/
        if (g_dfu_para.cur_offset + g_ota_tmp_buf_used_size + length >
            g_dfu_para.image_total_length)
        {
            DFU_PRINT_ERROR1("<==dfu_service_handle_packet_req: received data total "
                             "length beyond image_total_length(%d bytes)",
                             g_dfu_para.image_total_length);

            T_DFU_FAIL_REASON dfu_fail_reason = DFU_FAIL_EXCEED_IMG_TOTAL_LEN;
            callback_data.msg_data.write.opcode = DFU_WRITE_FAIL;
            callback_data.msg_data.write.length = sizeof(T_DFU_FAIL_REASON);
            callback_data.msg_data.write.p_value = (uint8_t *)&dfu_fail_reason;
            if (pfn_dfu_service_cb)
            {
                w_cause =
                    pfn_dfu_service_cb(dfu_service_id, (void *)&callback_data);
                if (w_cause != APP_RESULT_SUCCESS)
                {
                    return;
                }
            }

            dfu_fw_reboot(false);
        }

        /*start handle received data*/
        /* 1. deceypt data */
        if (dfu_get_enc_setting())
        {
            dfu_hw_aes_decrypt_image(p_value, p_value, length);
        }

        /* 2. copy received data to buffer */
        memcpy(p_ota_temp_buffer_head + g_ota_tmp_buf_used_size, p_value, length);
        g_ota_tmp_buf_used_size += length;

        /* 3. write to flash */
        if (g_ota_tmp_buf_used_size == max_buffer_size ||
            g_dfu_para.cur_offset + g_ota_tmp_buf_used_size ==
            g_dfu_para.image_total_length)
        {
            uint32_t result = dfu_update(
                                  g_dfu_para.ctrl_header.image_id, g_dfu_para.cur_offset,
                                  temp_image_info[temp_image_num].image_offset,
                                  g_ota_tmp_buf_used_size, (uint32_t *)p_ota_temp_buffer_head);
            if (result)
            {
                DFU_PRINT_ERROR1("Buffer check disable: dfu_update fail=%d",
                                 result);

                /*eflash write fail, we should restart ota procedure.*/
                T_DFU_FAIL_REASON dfu_fail_reason = DFU_FAIL_UPDATE_FLASH;
                callback_data.msg_data.write.opcode = DFU_WRITE_FAIL;
                callback_data.msg_data.write.length = sizeof(T_DFU_FAIL_REASON);
                callback_data.msg_data.write.p_value = (uint8_t *)&dfu_fail_reason;
                if (pfn_dfu_service_cb)
                {
                    w_cause = pfn_dfu_service_cb(dfu_service_id,
                                                 (void *)&callback_data);
                    if (w_cause != APP_RESULT_SUCCESS)
                    {
                        return;
                    }
                }

                dfu_fw_reboot(false);
            }
            else
            {
                uint32_t updated_success_len = g_ota_tmp_buf_used_size;
                callback_data.msg_data.write.opcode = DFU_WRITE_DOING;
                callback_data.msg_data.write.length = 4;
                callback_data.msg_data.write.p_value =
                    (uint8_t *)&updated_success_len;
                if (pfn_dfu_service_cb)
                {
                    w_cause = pfn_dfu_service_cb(dfu_service_id,
                                                 (void *)&callback_data);
                    if (w_cause != APP_RESULT_SUCCESS)
                    {
                        return;
                    }
                }

                /*update varibals value*/
                g_dfu_para.cur_offset += g_ota_tmp_buf_used_size;
                g_ota_tmp_buf_used_size = 0;
            }
        }
    }
}

static ssize_t dfu_srv_write_cb(struct bt_conn *conn, const struct bt_gatt_attr *attr,
                                const void *buf, uint16_t len, uint16_t offset, uint8_t flags)
{
    T_APP_RESULT w_cause = APP_RESULT_SUCCESS;
    T_DFU_CALLBACK_DATA callback_data;
    const struct bt_uuid_128 *uuid_128 = BT_UUID_128(attr->uuid);

    callback_data.conn = conn;
    callback_data.msg_type = SERVICE_CALLBACK_TYPE_WRITE_CHAR_VALUE;

    if (uuid_128->val[13] == 0x63)
    {
        callback_data.msg_data.write.write_attrib_index = INDEX_DFU_PACKET_VALUE;
    }
    else if (uuid_128->val[13] == 0x64)
    {
        callback_data.msg_data.write.write_attrib_index =
            INDEX_DFU_CONTROL_POINT_CHAR_VALUE;
    }

    callback_data.msg_data.write.length = len;
    callback_data.msg_data.write.p_value = (uint8_t *)buf;

    /* Notify Application. */
    callback_data.msg_data.write.opcode = DFU_WRITE_ATTR_ENTER;
    if (pfn_dfu_service_cb)
    {
        w_cause = pfn_dfu_service_cb(dfu_service_id, (void *)&callback_data);
        if (w_cause != APP_RESULT_SUCCESS)
        {
            return w_cause;
        }
    }

    if (callback_data.msg_data.write.write_attrib_index == INDEX_DFU_CONTROL_POINT_CHAR_VALUE)
    {
        dfu_service_handle_control_point_req(conn, len, (uint8_t *)buf);
    }
    else if (callback_data.msg_data.write.write_attrib_index == INDEX_DFU_PACKET_VALUE)
    {
        dfu_service_handle_packet_req(conn, len, (uint8_t *)buf);
    }
    else
    {
        DFU_PRINT_INFO1("dfu_attr_write_cb fail! attrib_index=%d",
                        callback_data.msg_data.write.write_attrib_index);
        w_cause = APP_RESULT_ATTR_NOT_FOUND;
    }

    /* Notify Application. */
    callback_data.msg_data.write.opcode = DFU_WRITE_ATTR_EXIT;
    if (pfn_dfu_service_cb)
    {
        w_cause = pfn_dfu_service_cb(dfu_service_id, (void *)&callback_data);
        if (w_cause != APP_RESULT_SUCCESS)
        {
            return w_cause;
        }
    }

    return len;
}

static void dfu_service_cccd_update_cb(const struct bt_gatt_attr *attr, uint16_t value)
{
    T_SERVER_ID service_id = 0xff; /* unused in zephyr */

    bool notif_enabled = (value & BT_GATT_CCC_NOTIFY);
    LOG_INF("dfu_cccd_update_cb Notifications %s\n", notif_enabled ? "enabled" : "disabled");

    T_DFU_CALLBACK_DATA callback_data;
    callback_data.msg_type = SERVICE_CALLBACK_TYPE_INDIFICATION_NOTIFICATION;
    if (notif_enabled)
    {
        /* Enable Notification */
        callback_data.msg_type = SERVICE_CALLBACK_TYPE_INDIFICATION_NOTIFICATION;
        callback_data.msg_data.notification_indification_index = DFU_NOTIFY_ENABLE;
    }
    else
    {
        callback_data.msg_type = SERVICE_CALLBACK_TYPE_INDIFICATION_NOTIFICATION;
        callback_data.msg_data.notification_indification_index = DFU_NOTIFY_DISABLE;
    }

    /* Notify Application. */
    if (pfn_dfu_service_cb)
    {
        T_APP_RESULT update_cause = pfn_dfu_service_cb(service_id, (void *)&callback_data);
        if (update_cause != APP_RESULT_SUCCESS)
        {
            return;
        }
    }

    return;
}

#define BT_UUID_RTK_DFU_SERVICE_VAL                                                                \
    BT_UUID_128_ENCODE(0x00006287, 0x3c17, 0xd293, 0x8e48, 0x14fe2e4da212)

static struct bt_uuid_128 rtk_dfu_srv_uuid = BT_UUID_INIT_128(BT_UUID_RTK_DFU_SERVICE_VAL);

BT_GATT_SERVICE_DEFINE(rtk_dfu_service, BT_GATT_PRIMARY_SERVICE(&rtk_dfu_srv_uuid),
                       BT_GATT_CHARACTERISTIC(BT_UUID_DECLARE_128(GATT_UUID128_DFU_DATA),
                                              BT_GATT_CHRC_WRITE_WITHOUT_RESP, BT_GATT_PERM_WRITE,
                                              NULL, dfu_srv_write_cb, NULL),
                       BT_GATT_CHARACTERISTIC(BT_UUID_DECLARE_128(GATT_UUID128_DFU_CONTROL_POINT),
                                              BT_GATT_CHRC_WRITE | BT_GATT_CHRC_NOTIFY,
                                              BT_GATT_PERM_WRITE, NULL, dfu_srv_write_cb, NULL),
                       BT_GATT_CCC(dfu_service_cccd_update_cb,
                                   BT_GATT_PERM_READ | BT_GATT_PERM_WRITE));

/*APP can define differtnt check rules of different images*/
bool dfu_soc_check_img_version(uint16_t image_id, uint32_t version)
{
    T_IMAGE_VERSION active_image_version;
    get_active_bank_image_version((T_IMG_ID)image_id, &active_image_version);

    APP_PRINT_INFO3("dfu_soc_check_img_version: img 0x%04x, dfu ver 0x%08x, active ver 0x%08x",
                    image_id, version, active_image_version.ver_info.version);

#if (OTA_ONLY_SUPPORT_UPGRADE == 1)
    if (image_id == OTA)
    {
        if (OTA_IMG_VER_TO_LE_VALUE(version) <
            OTA_IMG_VER_TO_LE_VALUE(active_image_version.ver_info.version))
        {
            return false;
        }
    }
    else
    {
        if (IMG_VER_TO_LE_VALUE(version) <
            IMG_VER_TO_LE_VALUE(active_image_version.ver_info.version))
        {
            return false;
        }
    }
#endif

    return true;
}

void dfu_buffer_check_process(struct bt_conn *conn, uint16_t buffer_check_size, uint16_t buffer_crc)
{
    uint8_t notif_data[DFU_NOTIFY_LENGTH_REPORT_BUFFER_CRC] = {0};
    notif_data[0] = DFU_OPCODE_NOTIFICATION;
    notif_data[1] = DFU_OPCODE_REPORT_BUFFER_CRC;

    T_DFU_CALLBACK_DATA callback_data;
    /* callback_data.conn_id = conn_id; */
    callback_data.conn = conn;
    callback_data.msg_type = SERVICE_CALLBACK_TYPE_WRITE_CHAR_VALUE;
    callback_data.msg_data.write.write_attrib_index = INDEX_DFU_CONTROL_POINT_CHAR_VALUE;

    if (buffer_check_size > DFU_TEMP_BUFFER_SIZE)
    {
        /* invalid para */
        DFU_PRINT_ERROR3("<==dfu_buffer_check_process: invalid buffer_check_size=%d(>%d), "
                         "cur_offset=%d",
                         buffer_check_size, DFU_TEMP_BUFFER_SIZE, g_dfu_para.cur_offset);
        g_ota_tmp_buf_used_size = 0;
        notif_data[2] = DFU_ARV_FAIL_INVALID_PARAMETER;
        LE_UINT32_TO_ARRAY(&notif_data[3], g_dfu_para.cur_offset);
        bt_gatt_notify_uuid(conn, BT_UUID_DECLARE_128(GATT_UUID128_DFU_CONTROL_POINT),
                            rtk_dfu_service.attrs, notif_data,
                            DFU_NOTIFY_LENGTH_REPORT_BUFFER_CRC);
        return;
    }

    if (g_ota_tmp_buf_used_size == buffer_check_size ||
        g_dfu_para.cur_offset + g_ota_tmp_buf_used_size == g_dfu_para.image_total_length)
    {
        if (dfu_check_buf_crc(p_ota_temp_buffer_head, g_ota_tmp_buf_used_size,
                              buffer_crc))
        {
            /* crc error */
            DFU_PRINT_ERROR1(
                "<==Buf CRC Error! cur_offset=%d",
                g_dfu_para.cur_offset);
            g_ota_tmp_buf_used_size = 0;
            notif_data[2] = DFU_ARV_FAIL_CRC_ERROR;
            LE_UINT32_TO_ARRAY(&notif_data[3], g_dfu_para.cur_offset);
            bt_gatt_notify_uuid(conn,
                                BT_UUID_DECLARE_128(GATT_UUID128_DFU_CONTROL_POINT),
                                rtk_dfu_service.attrs, notif_data,
                                DFU_NOTIFY_LENGTH_REPORT_BUFFER_CRC);
            return;
        }

        else   /* crc ok */
        {
            /* 1. decrypt data */
            if (dfu_get_enc_setting())
            {
                dfu_hw_aes_decrypt_image(p_ota_temp_buffer_head,
                                         p_ota_temp_buffer_head,
                                         g_ota_tmp_buf_used_size);
            }
            /* 2. write flash */
            uint32_t result = dfu_update(
                                  g_dfu_para.ctrl_header.image_id, g_dfu_para.cur_offset,
                                  temp_image_info[temp_image_num].image_offset,
                                  g_ota_tmp_buf_used_size, (uint32_t *)p_ota_temp_buffer_head);

            if (result == 0)
            {
                uint32_t updated_success_len = g_ota_tmp_buf_used_size;
                callback_data.msg_data.write.opcode = DFU_WRITE_DOING;
                callback_data.msg_data.write.length = 4;
                callback_data.msg_data.write.p_value =
                    (uint8_t *)&updated_success_len;
                if (pfn_dfu_service_cb)
                {
                    T_APP_RESULT w_cause = pfn_dfu_service_cb(
                                               dfu_service_id, (void *)&callback_data);
                    if (w_cause != APP_RESULT_SUCCESS)
                    {
                        return;
                    }
                }

                g_dfu_para.cur_offset += g_ota_tmp_buf_used_size;

                if ((g_dfu_para.cur_offset - dfu_resend_offset) >=
                    FLASH_NOR_SECTOR_SIZE)
                {
                    dfu_resend_offset += FLASH_NOR_SECTOR_SIZE;
                }
                g_ota_tmp_buf_used_size = 0;
                DFU_PRINT_INFO2("<== dfu_update Success! "
                                "cur_offset=%d, dfu_resend_offset=%d",
                                g_dfu_para.cur_offset, dfu_resend_offset);
                notif_data[2] = DFU_ARV_SUCCESS; /* valid */
                LE_UINT32_TO_ARRAY(&notif_data[3], g_dfu_para.cur_offset);
                bt_gatt_notify_uuid(
                    conn, BT_UUID_DECLARE_128(GATT_UUID128_DFU_CONTROL_POINT),
                    rtk_dfu_service.attrs, notif_data,
                    DFU_NOTIFY_LENGTH_REPORT_BUFFER_CRC);
                return;
            }
            else
            {
                DFU_PRINT_ERROR1(
                    "<==dfu_update Fail result=%d",
                    result);

                result = dfu_flash_erase_sector_with_retry(
                             g_dfu_para.ctrl_header.image_id, dfu_resend_offset);
                if (result)
                {
                    /* erase fail */
                    g_ota_tmp_buf_used_size = 0;
                    g_dfu_para.cur_offset = dfu_resend_offset;
                    DFU_PRINT_ERROR1("<==erase flash "
                                     "fail 3 times! cur_offset=%d",
                                     g_dfu_para.cur_offset);

                    notif_data[2] = DFU_ARV_FAIL_ERASE_ERROR;
                    LE_UINT32_TO_ARRAY(&notif_data[3], g_dfu_para.cur_offset);
                    bt_gatt_notify_uuid(
                        conn,
                        BT_UUID_DECLARE_128(GATT_UUID128_DFU_CONTROL_POINT),
                        rtk_dfu_service.attrs, notif_data,
                        DFU_NOTIFY_LENGTH_REPORT_BUFFER_CRC);
                    return;
                }

                if ((g_dfu_para.cur_offset - dfu_resend_offset) >
                    FLASH_NOR_SECTOR_SIZE)
                {
                    /* need erase two sector */
                    DFU_PRINT_INFO0("<==dfu_buffer_check_process:Need erase "
                                    "two sectors");
                    result = dfu_flash_erase_sector_with_retry(
                                 g_dfu_para.ctrl_header.image_id,
                                 dfu_resend_offset + FLASH_NOR_SECTOR_SIZE);
                    if (result)
                    {
                        /* erase fail */
                        g_ota_tmp_buf_used_size = 0;
                        g_dfu_para.cur_offset = dfu_resend_offset;
                        DFU_PRINT_ERROR1(
                            "<==dfu_buffer_check_process: erase flash "
                            "fail 3 times! cur_offset=%d",
                            g_dfu_para.cur_offset);

                        notif_data[2] = DFU_ARV_FAIL_ERASE_ERROR;
                        LE_UINT32_TO_ARRAY(&notif_data[3],
                                           g_dfu_para.cur_offset);
                        bt_gatt_notify_uuid(
                            conn,
                            BT_UUID_DECLARE_128(
                                GATT_UUID128_DFU_CONTROL_POINT),
                            rtk_dfu_service.attrs, notif_data,
                            DFU_NOTIFY_LENGTH_REPORT_BUFFER_CRC);
                        return;
                    }
                }
                /* erase ok */
                g_ota_tmp_buf_used_size = 0;
                g_dfu_para.cur_offset = dfu_resend_offset;
                DFU_PRINT_INFO1(
                    "<==dfu_buffer_check_process: erase ok! cur_offset=%d",
                    g_dfu_para.cur_offset);
                notif_data[2] = DFU_ARV_FAIL_PROG_ERROR;
                LE_UINT32_TO_ARRAY(&notif_data[3], g_dfu_para.cur_offset);
                bt_gatt_notify_uuid(
                    conn, BT_UUID_DECLARE_128(GATT_UUID128_DFU_CONTROL_POINT),
                    rtk_dfu_service.attrs, notif_data,
                    DFU_NOTIFY_LENGTH_REPORT_BUFFER_CRC);
                return;
            }
        }
    }
    else
    {
        DFU_PRINT_ERROR4(
            "<==dfu_buffer_check_process: Error "
            "buffer_check_size=%d,buf_used_size=%d,cur_offset=%d,image_total_length=%d",
            buffer_check_size, g_ota_tmp_buf_used_size, g_dfu_para.cur_offset,
            g_dfu_para.image_total_length);
        /* flush buffer. */
        g_ota_tmp_buf_used_size = 0;
        notif_data[2] = DFU_ARV_FAIL_LENGTH_ERROR;
        LE_UINT32_TO_ARRAY(&notif_data[3], g_dfu_para.cur_offset);
        bt_gatt_notify_uuid(conn, BT_UUID_DECLARE_128(GATT_UUID128_DFU_CONTROL_POINT),
                            rtk_dfu_service.attrs, notif_data,
                            DFU_NOTIFY_LENGTH_REPORT_BUFFER_CRC);
        return;
    }
}

void dfu_notify_conn_para_update_req(struct bt_conn *conn, T_DFU_ARV_ERROR_CODE error_code)
{
    if (g_dfu_para.dfu_conn_para_update_in_progress == true)
    {
        g_dfu_para.dfu_conn_para_update_in_progress = false;
        uint8_t notif_data[3] = {0};
        notif_data[0] = DFU_OPCODE_NOTIFICATION;
        notif_data[1] = DFU_OPCODE_CONN_PARA_TO_UPDATE_REQ;
        notif_data[2] = error_code;

        DFU_PRINT_INFO1("<==dfu_notify_conn_para_update_req error_code=0x%x", error_code);
        /* Connection Param Update rejected, we should notify the fail result to remote
         * device. */
        bt_gatt_notify_uuid(conn, BT_UUID_DECLARE_128(GATT_UUID128_DFU_CONTROL_POINT),
                            rtk_dfu_service.attrs, notif_data,
                            DFU_NOTIFY_LENGTH_CONN_PARA_UPDATE_REQ);
    }
}

void dfu_service_handle_valid_fw(struct bt_conn *conn)
{
    uint8_t notif_data[DFU_NOTIFY_LENGTH_VALID_FW] = {0};
    bool check_result = false;
    bool is_enable_bank_switch = is_ota_support_bank_switch();

    if (is_enable_bank_switch || g_dfu_para.ctrl_header.image_id == IMAGE_USER_DATA ||
        g_dfu_para.ctrl_header.image_id == IMAGE_USER_DATA2)
    {
        check_result = dfu_check_checksum(g_dfu_para.ctrl_header.image_id, 0);
    }
    else
    {
        check_result = dfu_check_checksum(temp_image_info[temp_image_num].image_id,
                                          temp_image_info[temp_image_num].image_offset);
    }
    DFU_PRINT_INFO1("check_result=%d (1: Success, 0: Fail)",
                    check_result);

    if (check_result)
    {
        if (!is_enable_bank_switch && g_dfu_para.ctrl_header.image_id != IMAGE_USER_DATA &&
            g_dfu_para.ctrl_header.image_id != IMAGE_USER_DATA2)
        {
            temp_image_num++;
            DFU_PRINT_INFO1("temp_image_num=%d ", temp_image_num);
        }

        notif_data[2] = DFU_ARV_SUCCESS;
    }
    else
    {
        notif_data[2] = DFU_ARV_FAIL_CRC_ERROR;
    }
    notif_data[0] = DFU_OPCODE_NOTIFICATION;
    notif_data[1] = DFU_OPCODE_VALID_FW;
    bt_gatt_notify_uuid(conn, BT_UUID_DECLARE_128(GATT_UUID128_DFU_CONTROL_POINT),
                        rtk_dfu_service.attrs, notif_data, DFU_NOTIFY_LENGTH_VALID_FW);
}

void dfu_service_handle_active_image(void)
{
    uint32_t base_addr = 0;
    T_IMG_HEADER_FORMAT *p_header = NULL;

    /* check OTA temp or running bank to see if received image is OK.*/
    base_addr = dfu_get_temp_ota_bank_addr_by_img_id((T_IMG_ID)g_dfu_para.ctrl_header.image_id);

    if (!is_ota_support_bank_switch())
    {
        for (uint8_t i = 0; i < temp_image_num; i++)
        {
            p_header = (T_IMG_HEADER_FORMAT *)(base_addr +
                                               temp_image_info[i].image_offset);
            dfu_set_image_ready(p_header, temp_image_info[i].dfu_compressed_mode);
        }
    }

    /*set user data image ready*/
    if (g_dfu_para.ctrl_header.image_id == IMAGE_USER_DATA ||
        g_dfu_para.ctrl_header.image_id == IMAGE_USER_DATA2)
    {
        uint32_t img_id = IMAGE_USER_DATA2;

        for (; img_id < IMAGE_USER_DATA; img_id++)
        {
            {
                T_IMG_HEADER_FORMAT *p_header =
                    (T_IMG_HEADER_FORMAT *)dfu_get_temp_ota_bank_addr_by_img_id(
                        (T_IMG_ID)img_id);
                if (p_header)
                {
                    dfu_set_image_ready(p_header, false);
                }
            }
        }
    }
}
/* implement le_update_conn_param in zephyr*/
int le_update_connection_parameters(struct bt_conn *conn, uint16_t conn_interval_min,
                                    uint16_t conn_interval_max, uint16_t conn_latency,
                                    uint16_t superv_tout)
{
    struct bt_le_conn_param param = {.interval_min = conn_interval_min,
               .interval_max = conn_interval_max,
                .latency = conn_latency,
                 .timeout = superv_tout
    };

    int err = bt_conn_le_param_update(conn, &param);

    if (err)
    {
        LOG_INF("Failed to update connection parameters (err %d)\n", err);
        return err;
    }

    return 0;
}

/**
 * @brief dfu_service_handle_control_point_req
 *
 * @param length     control point cmd length.
 * @param p_value    control point cmd address..
 * @return None
 */
void dfu_service_handle_control_point_req(struct bt_conn *conn, uint16_t length, uint8_t *p_value)
{
    T_APP_RESULT w_cause = APP_RESULT_SUCCESS;
    T_DFU_CTRL_POINT dfu_control_point;
    uint8_t *p = p_value + 1;
    uint8_t notif_data[DFU_NOTIFY_LENGTH_MAX] = {0};

    T_DFU_CALLBACK_DATA callback_data;
    /* callback_data.conn_id = conn_id; */
    callback_data.conn = conn;
    callback_data.msg_type = SERVICE_CALLBACK_TYPE_WRITE_CHAR_VALUE;
    callback_data.msg_data.write.write_attrib_index = INDEX_DFU_CONTROL_POINT_CHAR_VALUE;

    dfu_control_point.opcode = *p_value;
    DFU_PRINT_TRACE2("==>opcode=0x%x, length=%d",
                     dfu_control_point.opcode, length);

    if (dfu_control_point.opcode >= DFU_OPCODE_MAX ||
        dfu_control_point.opcode <= DFU_OPCODE_MIN)
    {
        notif_data[0] = DFU_OPCODE_NOTIFICATION;
        notif_data[1] = dfu_control_point.opcode;
        notif_data[2] = 0xff;
        bt_gatt_notify_uuid(conn, BT_UUID_DECLARE_128(GATT_UUID128_DFU_CONTROL_POINT),
                            rtk_dfu_service.attrs, notif_data, DFU_NOTIFY_LENGTH_START_DFU);
        return;
    }

    switch (dfu_control_point.opcode)
    {
    case DFU_OPCODE_START_DFU: /* 0x01 */
        /*4 bytes is padding for encrypt*/
        if (length == DFU_LENGTH_START_DFU)
        {
            if (dfu_get_enc_setting())
            {
                /* DFU_PRINT_INFO1("ctrl header before decryped=%b", TRACE_BINARY(16, p)); */
                LOG_INF("ctrl header before decryped=%x", *p);
                LOG_HEXDUMP_DBG(p, 16, "ctrl header before decryped");
                dfu_hw_aes_decrypt_image(p, p, 16);
                LOG_HEXDUMP_DBG(p, 16, "ctrl header after decryped");
                /* DFU_PRINT_INFO1("ctrl header after decryped=%b", TRACE_BINARY(16, p)); */
            }
            LE_ARRAY_TO_UINT16(dfu_control_point.start_dfu.crc16, p);
            p += 2;
            dfu_control_point.start_dfu.ic_type = (*p);
            p += 1;
            dfu_control_point.start_dfu.secure_version = (*p);
            p += 1;
            LE_ARRAY_TO_UINT16(dfu_control_point.start_dfu.ctrl_flag.value, p);
            p += 2;
            LE_ARRAY_TO_UINT16(dfu_control_point.start_dfu.image_id, p);
            p += 2;
            LE_ARRAY_TO_UINT32(dfu_control_point.start_dfu.payload_len, p);
            p += 4;
            LE_ARRAY_TO_UINT8(g_dfu_para.start_dfu_mode, p);

            DFU_PRINT_INFO6(
                "DFU_OPCODE_START_DFU: ic_type=0x%x, secure_version=0x%x, "
                "ctrl_flag.value=0x%x, image_id=0x%x,crc16=0x%x, payload_len=%d",
                dfu_control_point.start_dfu.ic_type,
                dfu_control_point.start_dfu.secure_version,
                dfu_control_point.start_dfu.ctrl_flag.value,
                dfu_control_point.start_dfu.image_id,
                dfu_control_point.start_dfu.crc16,
                dfu_control_point.start_dfu.payload_len);
            g_dfu_para.ctrl_header.ic_type = dfu_control_point.start_dfu.ic_type;
            g_dfu_para.ctrl_header.ctrl_flag.value =
                dfu_control_point.start_dfu.ctrl_flag.value;
            g_dfu_para.ctrl_header.image_id = dfu_control_point.start_dfu.image_id;
            g_dfu_para.ctrl_header.crc16 = dfu_control_point.start_dfu.crc16;
            g_dfu_para.ctrl_header.payload_len =
                dfu_control_point.start_dfu.payload_len;
            g_dfu_para.image_total_length =
                g_dfu_para.ctrl_header.payload_len + IMG_HEADER_SIZE;

            dfu_compressed_mode =
                (g_dfu_para.start_dfu_mode == START_DFU_COMPRESSED_MODE_VALUE);
            DFU_PRINT_INFO3(
                "DFU_OPCODE_START_DFU: image_total_length=%d, "
                "start_dfu_mode=0x%x(%d: compressed mode, others: default mode)",
                g_dfu_para.image_total_length, g_dfu_para.start_dfu_mode,
                START_DFU_COMPRESSED_MODE_VALUE);

            /*check if start dfu fileds are vaild*/
            if (g_dfu_para.ctrl_header.ic_type == IMG_IC_TYPE)
            {
                if (((g_dfu_para.ctrl_header.image_id >= OTA) &&
                     (g_dfu_para.ctrl_header.image_id < IMAGE_MAX)) ||
                    (g_dfu_para.ctrl_header.image_id == IMAGE_USER_DATA) ||
                    (g_dfu_para.ctrl_header.image_id == IMAGE_USER_DATA2))
                {
                    is_ota_procedure = true;

                    /* user data image needn't record into temp info */
                    if (g_dfu_para.ctrl_header.image_id != IMAGE_USER_DATA &&
                        g_dfu_para.ctrl_header.image_id != IMAGE_USER_DATA2)
                    {
                        /*disable bank switch, need record temp image info*/
                        if (!is_ota_support_bank_switch())
                        {
                            temp_image_info[temp_image_num].image_id =
                                (T_IMG_ID)g_dfu_para.ctrl_header
                                .image_id;
                            /* temp_image_info[temp_image_num].image_size =
                             * UP_ALIGN(g_dfu_para.image_total_length,
                             * FMC_SEC_SECTION_LEN);
                             */
                            temp_image_info[temp_image_num].image_size =
                                g_dfu_para.image_total_length;
                            temp_image_info[temp_image_num]
                            .dfu_compressed_mode =
                                dfu_compressed_mode;
                            if (temp_image_num == 0)
                            {
                                temp_image_info[temp_image_num]
                                .image_offset = 0;
                            }
                            else
                            {
                                temp_image_info[temp_image_num]
                                .image_offset =
                                    temp_image_info
                                    [temp_image_num - 1]
                                    .image_offset +
                                    temp_image_info
                                    [temp_image_num - 1]
                                    .image_size;
                            }
                        }
                        DFU_PRINT_INFO5(
                            "DFU_OPCODE_START_DFU: image_num=%d, "
                            "image_id=0x%x, image_size=0x%x, "
                            "image_offset=0x%x, compressed_mode %d",
                            temp_image_num,
                            temp_image_info[temp_image_num].image_id,
                            temp_image_info[temp_image_num].image_size,
                            temp_image_info[temp_image_num]
                            .image_offset,
                            temp_image_info[temp_image_num]
                            .dfu_compressed_mode);
                    }

                    callback_data.msg_data.write.opcode = DFU_WRITE_START;
                    callback_data.msg_data.write.length = DFU_HEADER_SIZE;
                    callback_data.msg_data.write.p_value =
                        (uint8_t *)&g_dfu_para.ctrl_header;
                    if (pfn_dfu_service_cb)
                    {
                        w_cause = pfn_dfu_service_cb(
                                      dfu_service_id, (void *)&callback_data);
                        if (w_cause != APP_RESULT_SUCCESS)
                        {
                            return;
                        }
                    }

                    g_dfu_para.cur_offset += 0;
                    DFU_PRINT_INFO0("DFU_OPCODE_START_DFU: start success!");

                    notif_data[0] = DFU_OPCODE_NOTIFICATION;
                    notif_data[1] = DFU_OPCODE_START_DFU;
                    notif_data[2] = DFU_ARV_SUCCESS;
                    bt_gatt_notify_uuid(
                        conn,
                        BT_UUID_DECLARE_128(GATT_UUID128_DFU_CONTROL_POINT),
                        rtk_dfu_service.attrs, notif_data,
                        DFU_NOTIFY_LENGTH_START_DFU);

                }
                else
                {
                    DFU_PRINT_ERROR1(
                        "DFU_OPCODE_START_DFU: image id=0x%x Error!",
                        g_dfu_para.ctrl_header.image_id);
                    notif_data[0] = DFU_OPCODE_NOTIFICATION;
                    notif_data[1] = DFU_OPCODE_START_DFU;
                    notif_data[2] = DFU_ARV_FAIL_INVALID_PARAMETER;
                    bt_gatt_notify_uuid(
                        conn,
                        BT_UUID_DECLARE_128(GATT_UUID128_DFU_CONTROL_POINT),
                        rtk_dfu_service.attrs, notif_data,
                        DFU_NOTIFY_LENGTH_START_DFU);
                    return;
                }
            }
            else
            {
                DFU_PRINT_ERROR1("DFU_OPCODE_START_DFU: ic type=0x%x Error!",
                                 g_dfu_para.ctrl_header.ic_type);
                notif_data[0] = DFU_OPCODE_NOTIFICATION;
                notif_data[1] = DFU_OPCODE_START_DFU;
                notif_data[2] = DFU_ARV_FAIL_INVALID_PARAMETER;
                bt_gatt_notify_uuid(
                    conn, BT_UUID_DECLARE_128(GATT_UUID128_DFU_CONTROL_POINT),
                    rtk_dfu_service.attrs, notif_data,
                    DFU_NOTIFY_LENGTH_START_DFU);
                return;
            }
        }
        break;

    case DFU_OPCODE_RECEIVE_FW_IMAGE_INFO: /* 0x02 */
        if (length == DFU_LENGTH_RECEIVE_FW_IMAGE_INFO)
        {
            LE_ARRAY_TO_UINT16(g_dfu_para.ctrl_header.image_id, p);
            p += 2;
            LE_ARRAY_TO_UINT32(g_dfu_para.cur_offset, p);
            if ((g_dfu_para.cur_offset == 0) ||
                (g_dfu_para.cur_offset == DFU_HEADER_SIZE))
            {
                g_ota_tmp_buf_used_size = 0;
                dfu_resend_offset = 0;
            }
            DFU_PRINT_INFO3("DFU_OPCODE_RECEIVE_FW_IMAGE_INFO: image_id=0x%x, "
                            "cur_offset=%d, g_ota_tmp_buf_used_size=%d",
                            g_dfu_para.ctrl_header.image_id, g_dfu_para.cur_offset,
                            g_ota_tmp_buf_used_size);
        }
        else
        {
            DFU_PRINT_ERROR1("DFU_OPCODE_RECEIVE_FW_IMAGE_INFO: length=%d Error!",
                             length);
        }
        break;

    case DFU_OPCODE_VALID_FW: /* 0x03 */

        if (length == DFU_LENGTH_VALID_FW)
        {
            LE_ARRAY_TO_UINT16(g_dfu_para.ctrl_header.image_id, p);
            DFU_PRINT_TRACE1("DFU_OPCODE_VALID_FW: image_id=0x%x",
                             g_dfu_para.ctrl_header.image_id);

            /* if ota large img, need modify wdg timeout period */
            if (OTP->wdgEnableInRom && g_dfu_para.image_total_length > 0x100000)
            {
                /* 1M and less---4s, 2M and less---8s,..., 8M and less---32s */
                uint32_t img_align_len =
                    ((g_dfu_para.image_total_length + (0x100000 - 1)) &
                     (~(0x100000 - 1)));
                uint8_t wdg_period_4s = (img_align_len / 0x100000);
                uint16_t div_factor = (32 * wdg_period_4s - 1);

                DFU_PRINT_TRACE2("DFU_OPCODE_VALID_FW: Change WDG Period to %ds, "
                                 "div_factor=%d",
                                 wdg_period_4s << 2, div_factor);
                WDG_Config(div_factor, 15, RESET_ALL); /* 31 - 4s, 63 - 8s */
            }
            /* It is not recommended to do things that take a long time in upperstack
             * task cb. So dfu service cb need send msg to app task to handle checksum
             * image if support silent ota. While app task must handle
             * IO_MSG_TYPE_DFU_VALID_FW by calling dfu_service_handle_valid_fw.
             */
        }
        else
        {
            DFU_PRINT_ERROR1("DFU_OPCODE_VALID_FW: length=%d Error!", length);
        }
        break;

    case DFU_OPCODE_ACTIVE_IMAGE_RESET: /* 0x04 */
        {
            /*when disable bank switch, need set image ready*/
            dfu_service_handle_active_image();

            /*notify bootloader to reset and use new image*/
            DFU_PRINT_INFO0("DFU_OPCODE_ACTIVE_IMAGE_RESET");
            callback_data.msg_data.write.opcode = DFU_WRITE_END;
            callback_data.msg_data.write.length = DFU_HEADER_SIZE;
            callback_data.msg_data.write.p_value = (uint8_t *)&g_dfu_para.ctrl_header;
            if (pfn_dfu_service_cb)
            {
                w_cause = pfn_dfu_service_cb(dfu_service_id, (void *)&callback_data);
                if (w_cause != APP_RESULT_SUCCESS)
                {
                    return;
                }
            }

            if (!is_ota_support_bank_switch())
            {
                /* note: must unlock flash bp for ota copy before reset when not
                 * support bank switch
                 */
                unlock_flash_bp_all();
            }
        } break;

    case DFU_OPCODE_SYSTEM_RESET: /* 0x05 */
        {
            /* whatever cause ota fail, clinet will send this cmd to reset device */
            DFU_PRINT_INFO0("DFU_OPCODE_SYSTEM_RESET");

            /* if select not active image by Phone even if image transport successful.
             * Not for single bank user data
             */
            if (g_dfu_para.ctrl_header.image_id >= OTA &&
                g_dfu_para.ctrl_header.image_id < IMAGE_MAX)
            {

                uint32_t temp_addr = get_temp_ota_bank_addr_by_img_id(
                                         (T_IMG_ID)g_dfu_para.ctrl_header.image_id);

                T_IMG_HEADER_FORMAT *p_temp_header = (T_IMG_HEADER_FORMAT *)temp_addr;

                if (p_temp_header &&
                    !p_temp_header->ctrl_header.ctrl_flag.flag_value.not_ready)
                {

                    dfu_flash_erase_sector(temp_addr);
                }
            }

            T_DFU_FAIL_REASON dfu_fail_reason = DFU_FAIL_SYSTEM_RESET_CMD;

            callback_data.msg_data.write.length = sizeof(T_DFU_FAIL_REASON);
            callback_data.msg_data.write.p_value = (uint8_t *)&dfu_fail_reason;
            callback_data.msg_data.write.opcode = DFU_WRITE_FAIL;
            if (pfn_dfu_service_cb)
            {
                w_cause = pfn_dfu_service_cb(dfu_service_id, (void *)&callback_data);
                if (w_cause != APP_RESULT_SUCCESS)
                {
                    return;
                }
            }

            dfu_fw_reboot(false);
        } break;

    case DFU_OPCODE_REPORT_TARGET_INFO: /* 0x06 */
        if (length == DFU_LENGTH_REPORT_TARGET_INFO)
        {
            LE_ARRAY_TO_UINT16(g_dfu_para.ctrl_header.image_id, p);
            dfu_report_target_fw_info(g_dfu_para.ctrl_header.image_id,
                                      &g_dfu_para.origin_image_version,
                                      (uint32_t *)&g_dfu_para.cur_offset);
            g_dfu_para.cur_offset = 0;
            DFU_PRINT_INFO3("DFU_OPCODE_REPORT_TARGET_INFO: "
                            "image_id=0x%x,origin_image_ver=0x%x, cur_offset=%d",
                            g_dfu_para.ctrl_header.image_id,
                            g_dfu_para.origin_image_version, g_dfu_para.cur_offset);

            notif_data[0] = DFU_OPCODE_NOTIFICATION;
            notif_data[1] = DFU_OPCODE_REPORT_TARGET_INFO;
            notif_data[2] = DFU_ARV_SUCCESS;

            LE_UINT32_TO_ARRAY(&notif_data[3], g_dfu_para.origin_image_version);
            LE_UINT32_TO_ARRAY(&notif_data[7], g_dfu_para.cur_offset);
            /* server_send_data(conn_id, dfu_service_id,
             * INDEX_DFU_CONTROL_POINT_CHAR_VALUE, notif_data,
             * DFU_NOTIFY_LENGTH_REPORT_TARGET_INFO, GATT_PDU_TYPE_NOTIFICATION);
             */
            bt_gatt_notify_uuid(conn,
                                BT_UUID_DECLARE_128(GATT_UUID128_DFU_CONTROL_POINT),
                                rtk_dfu_service.attrs, notif_data,
                                DFU_NOTIFY_LENGTH_REPORT_TARGET_INFO);
        }
        else
        {
            DFU_PRINT_ERROR1("DFU_OPCODE_REPORT_TARGET_INFO: length=%d Error!", length);
        }
        break;

    case DFU_OPCODE_CONN_PARA_TO_UPDATE_REQ: /* 0x07 */
        {
            notif_data[0] = DFU_OPCODE_NOTIFICATION;
            notif_data[1] = DFU_OPCODE_CONN_PARA_TO_UPDATE_REQ;

            if (length == DFU_LENGTH_CONN_PARA_TO_UPDATE_REQ)
            {
                if (g_dfu_para.dfu_conn_para_update_in_progress)
                {
                    DFU_PRINT_ERROR0("DFU_OPCODE_CONN_PARA_TO_UPDATE_REQ: OTA "
                                     "ConnParaUpdInProgress!");
                    notif_data[2] = DFU_ARV_FAIL_OPERATION;
                    /* server_send_data(conn_id, dfu_service_id,
                     * INDEX_DFU_CONTROL_POINT_CHAR_VALUE, notif_data,
                     * DFU_NOTIFY_LENGTH_ARV, GATT_PDU_TYPE_NOTIFICATION);
                     */
                    bt_gatt_notify_uuid(
                        conn, BT_UUID_DECLARE_128(GATT_UUID128_DFU_CONTROL_POINT),
                        rtk_dfu_service.attrs, notif_data, DFU_NOTIFY_LENGTH_ARV);
                }
                else
                {
                    uint16_t conn_interval_min;
                    uint16_t conn_interval_max;
                    uint16_t conn_latency;
                    uint16_t superv_tout;

                    LE_ARRAY_TO_UINT16(conn_interval_min, p_value + 1);
                    LE_ARRAY_TO_UINT16(conn_interval_max, p_value + 3);
                    LE_ARRAY_TO_UINT16(conn_latency, p_value + 5);
                    LE_ARRAY_TO_UINT16(superv_tout, p_value + 7);

                    if (le_update_connection_parameters(
                            conn, conn_interval_min, conn_interval_max,
                            conn_latency, superv_tout) == GAP_CAUSE_SUCCESS)
                    {
                        /* Connection Parameter Update Request sent successfully,
                         * means this procedure is in progress.
                         */
                        g_dfu_para.dfu_conn_para_update_in_progress = true;
                        DFU_PRINT_INFO4("DFU_OPCODE_CONN_PARA_TO_UPDATE_REQ: "
                                        "conn_min=0x%x, conn_max=0x%x, latcy=0x%x, "
                                        "timeout=0x%x",
                                        conn_interval_min, conn_interval_max,
                                        conn_latency, superv_tout);
                    }
                    else
                    {
                        notif_data[2] = DFU_ARV_FAIL_OPERATION;
                        /* server_send_data(conn_id, dfu_service_id,
                         * INDEX_DFU_CONTROL_POINT_CHAR_VALUE,
                         * notif_data, DFU_NOTIFY_LENGTH_ARV,
                         * GATT_PDU_TYPE_NOTIFICATION);
                         */
                        bt_gatt_notify_uuid(
                            conn,
                            BT_UUID_DECLARE_128(GATT_UUID128_DFU_CONTROL_POINT),
                            rtk_dfu_service.attrs, notif_data,
                            DFU_NOTIFY_LENGTH_ARV);
                    }
                }
            }
            else
            {
                /*TODO: to be masked.*/
                DFU_PRINT_ERROR1("DFU_OPCODE_CONN_PARA_TO_UPDATE_REQ: length=%d Error!",
                                 length);
                notif_data[2] = DFU_ARV_FAIL_INVALID_PARAMETER;
                /* server_send_data(conn_id, dfu_service_id,
                 * INDEX_DFU_CONTROL_POINT_CHAR_VALUE,
                 * notif_data, DFU_NOTIFY_LENGTH_ARV, GATT_PDU_TYPE_NOTIFICATION);
                 */
                bt_gatt_notify_uuid(
                    conn, BT_UUID_DECLARE_128(GATT_UUID128_DFU_CONTROL_POINT),
                    rtk_dfu_service.attrs, notif_data, DFU_NOTIFY_LENGTH_ARV);
            }
        } break;

    case DFU_OPCODE_BUFFER_CHECK_EN: /* 0x09 */
        {
            /* le_get_conn_param(GAP_PARAM_CONN_MTU_SIZE, &g_dfu_para.mtu_size, conn_id); */
            g_dfu_para.mtu_size = bt_gatt_get_mtu(conn);
            LOG_INF("DFU_OPCODE_BUFFER_CHECK_EN: mtu_size=%d, max_bufffer_size=%d",
                    g_dfu_para.mtu_size, DFU_TEMP_BUFFER_SIZE);

            notif_data[0] = DFU_OPCODE_NOTIFICATION;
            notif_data[1] = DFU_OPCODE_BUFFER_CHECK_EN;
#if (DFU_BUFFER_CHECK_ENABLE == 1)
            buffer_check_en = true;
            notif_data[2] = DFU_ARV_SUCCESS;
#else
            buffer_check_en = false;
            notif_data[2] = DFU_ARV_FAIL_OPERATION;
#endif
            LE_UINT16_TO_ARRAY(&notif_data[3], DFU_TEMP_BUFFER_SIZE);
            LE_UINT16_TO_ARRAY(&notif_data[5], g_dfu_para.mtu_size);
            /* server_send_data(conn_id, dfu_service_id, INDEX_DFU_CONTROL_POINT_CHAR_VALUE,
             * notif_data, DFU_NOTIFY_LENGTH_BUFFER_CHECK_EN, GATT_PDU_TYPE_NOTIFICATION);
             */
            bt_gatt_notify_uuid(conn, BT_UUID_DECLARE_128(GATT_UUID128_DFU_CONTROL_POINT),
                                rtk_dfu_service.attrs, notif_data,
                                DFU_NOTIFY_LENGTH_BUFFER_CHECK_EN);
        } break;

    case DFU_OPCODE_REPORT_BUFFER_CRC: /* 0x0a */
        {
            uint16_t mBufSize;
            uint16_t mCrcVal;

            LE_ARRAY_TO_UINT16(mBufSize, p);
            p += 2;
            LE_ARRAY_TO_UINT16(mCrcVal, p);
            DFU_PRINT_INFO2("DFU_OPCODE_REPORT_BUFFER_CRC: mBufSize=0x%x, mCrcVal=0x%x",
                            mBufSize, mCrcVal);
            dfu_buffer_check_process(conn, mBufSize, mCrcVal);
        } break;

    case DFU_OPCODE_RECEIVE_IC_TYPE: /* 0x0b */
        {
            uint8_t ic_type = 0; /* 0 means invalid ic type */

            notif_data[0] = DFU_OPCODE_NOTIFICATION;
            notif_data[1] = DFU_OPCODE_RECEIVE_IC_TYPE;

            if (dfu_report_target_ic_type(OTA, &ic_type))
            {
                notif_data[2] = DFU_ARV_FAIL_INVALID_PARAMETER;
                notif_data[3] = ic_type;
            }
            else
            {
                notif_data[2] = DFU_ARV_SUCCESS;
                notif_data[3] = ic_type;
            }
            DFU_PRINT_INFO1("DFU_OPCODE_RECEIVE_IC_TYPE: ic_type=0x%x", ic_type);
            /* server_send_data(conn_id, dfu_service_id, INDEX_DFU_CONTROL_POINT_CHAR_VALUE,
             * notif_data, DFU_NOTIFY_LENGTH_RECEIVE_IC_TYPE, GATT_PDU_TYPE_NOTIFICATION);
             */
            bt_gatt_notify_uuid(conn, BT_UUID_DECLARE_128(GATT_UUID128_DFU_CONTROL_POINT),
                                rtk_dfu_service.attrs, notif_data,
                                DFU_NOTIFY_LENGTH_RECEIVE_IC_TYPE);
        } break;

#if (ENABLE_BANK_SWITCH_COPY_APP_DATA == 1)
    case DFU_OPCODE_COPY_IMG: /* 0x0c */
        {
            uint32_t dlAddress, dlSize;

            LE_ARRAY_TO_UINT16(g_dfu_para.ctrl_header.image_id, p);
            p += 2;
            LE_ARRAY_TO_UINT32(dlAddress, p);
            p += 4;
            LE_ARRAY_TO_UINT32(dlSize, p);
            DFU_PRINT_TRACE2("DFU_OPCODE_COPY_IMG: dlAddress=0x%x,dlSize=0x%x", dlAddress,
                             dlSize);

            notif_data[0] = DFU_OPCODE_NOTIFICATION;
            notif_data[1] = DFU_OPCODE_COPY_IMG;

            if (dfu_copy_img(g_dfu_para.ctrl_header.image_id, dlAddress, dlSize))
            {
                notif_data[2] = DFU_ARV_SUCCESS;
            }
            else
            {
                notif_data[2] = DFU_ARV_FAIL_INVALID_PARAMETER;
            }
            /* server_send_data(conn_id, dfu_service_id, INDEX_DFU_CONTROL_POINT_CHAR_VALUE,
             * notif_data, DFU_NOTIFY_LENGTH_ARV, GATT_PDU_TYPE_NOTIFICATION);
             */
            bt_gatt_notify_uuid(conn, BT_UUID_DECLARE_128(GATT_UUID128_DFU_CONTROL_POINT),
                                rtk_dfu_service.attrs, notif_data, DFU_NOTIFY_LENGTH_ARV);
        } break;
#endif  /* end ENABLE_BANK_SWITCH_COPY_APP_DATA */
    case DFU_OPCODE_CHECK_IMAGE_VER: /* 0x0d */
        {
            if (length == DFU_LENGTH_IMAGE_VERSION)
            {
                uint16_t image_id;
                uint32_t version;

                LE_ARRAY_TO_UINT16(image_id, p);
                LE_ARRAY_TO_UINT32(version, p + 2);
                DFU_PRINT_INFO2("DFU_OPCODE_CHECK_IMAGE_VER: img_id 0x%x, version %x",
                                image_id, version);

                if (dfu_soc_check_img_version(image_id, version))
                {
                    DFU_PRINT_INFO0("DFU_OPCODE_CHECK_IMAGE_VER length version check "
                                    "success!!");
                    notif_data[2] = DFU_ARV_SUCCESS;
                    g_dfu_para.is_need_dfu = true;
                }
                else
                {
                    DFU_PRINT_INFO0("DFU_OPCODE_CHECK_IMAGE_VER Image check failed!!");
                    notif_data[2] = DFU_ARV_FAIL_INVALID_PARAMETER;
                    g_dfu_para.is_need_dfu = false;
                }
            }
            else
            {
                DFU_PRINT_INFO0("DFU_OPCODE_CHECK_IMAGE_VER length error!!");
                notif_data[2] = DFU_ARV_FAIL_INVALID_PARAMETER;
            }

            notif_data[0] = DFU_OPCODE_NOTIFICATION;
            notif_data[1] = DFU_OPCODE_CHECK_IMAGE_VER;
            /**
             * server_send_data(conn_id, dfu_service_id, INDEX_DFU_CONTROL_POINT_CHAR_VALUE,
             * notif_data, DFU_NOTIFY_LENGTH_ARV, GATT_PDU_TYPE_NOTIFICATION);
             */
            bt_gatt_notify_uuid(conn, BT_UUID_DECLARE_128(GATT_UUID128_DFU_CONTROL_POINT),
                                rtk_dfu_service.attrs, notif_data, DFU_NOTIFY_LENGTH_ARV);
        } break;
    case DFU_OPCODE_HANDSHAKE: /* 0x0e */
        {
            if (length == DFU_LENGTH_HANDSHAKE)
            {
                DFU_PRINT_INFO0("DFU_OPCODE_HANDSHAKE");

                uint8_t handshake_data[16];

                memcpy(handshake_data, p_value + 1, 16);

                /* decrypt data */
                if (dfu_get_enc_setting())
                {
                    dfu_hw_aes_decrypt_image(handshake_data, handshake_data, 16);
                }

                /* increase data value */
                for (uint8_t index = 0; index < 16; index++)
                {
                    handshake_data[index] += 1;
                }

                /* encrypt data */
                if (dfu_get_enc_setting())
                {
                    dfu_encrypt_handshake_data(handshake_data);
                }

                notif_data[0] = DFU_OPCODE_NOTIFICATION;
                notif_data[1] = DFU_OPCODE_HANDSHAKE;
                notif_data[2] = DFU_ARV_SUCCESS;
                memcpy(&notif_data[3], handshake_data, 16);
                /**
                 * server_send_data(conn_id, dfu_service_id,
                 *      INDEX_DFU_CONTROL_POINT_CHAR_VALUE, notif_data,
                 *      DFU_NOTIFY_LENGTH_HANDSHAKE, GATT_PDU_TYPE_NOTIFICATION);
                 */
                bt_gatt_notify_uuid(
                    conn, BT_UUID_DECLARE_128(GATT_UUID128_DFU_CONTROL_POINT),
                    rtk_dfu_service.attrs, notif_data, DFU_NOTIFY_LENGTH_HANDSHAKE);
            }
            else
            {
                DFU_PRINT_ERROR1("DFU_OPCODE_HANDSHAKE: length=%d Error!", length);
                notif_data[0] = DFU_OPCODE_NOTIFICATION;
                notif_data[1] = DFU_OPCODE_HANDSHAKE;
                notif_data[2] = DFU_ARV_FAIL_INVALID_PARAMETER;
                memset(&notif_data[3], 0, 16);
                /**
                 * server_send_data(conn_id, dfu_service_id,
                 *      INDEX_DFU_CONTROL_POINT_CHAR_VALUE, notif_data,
                 *      DFU_NOTIFY_LENGTH_HANDSHAKE, GATT_PDU_TYPE_NOTIFICATION);
                 */
                bt_gatt_notify_uuid(
                    conn, BT_UUID_DECLARE_128(GATT_UUID128_DFU_CONTROL_POINT),
                    rtk_dfu_service.attrs, notif_data, DFU_NOTIFY_LENGTH_HANDSHAKE);
            }
        } break;

    default:
        {
            DFU_PRINT_TRACE1("Unknown Opcode=0x%x",
                             dfu_control_point.opcode);
        } break;
    }
}
