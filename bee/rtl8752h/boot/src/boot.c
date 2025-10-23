/*
 * Copyright (c) 2025 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>

#include "flash_nor_device.h"
#include "patch_header_check.h"
#include "mem_config.h"

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(boot, LOG_LEVEL_INF);

uint32_t get_temp_ota_bank_addr_by_img_id(T_IMG_ID image_id)
{
    uint32_t image_addr = 0;
    if (image_id < OTA || ((image_id >= IMAGE_MAX)))
    {
        return image_addr;
    }
    if (!is_ota_support_bank_switch())
    {
        if (image_id == OTA)
        {
            return 0;
        }
        image_addr = flash_nor_get_bank_addr(FLASH_OTA_TMP);
    }
    else
    {
        uint32_t ota_bank0_addr = flash_nor_get_bank_addr(FLASH_OTA_BANK_0);
        uint32_t temp_bank_addr;
        if (ota_bank0_addr == get_active_ota_bank_addr())
        {
            temp_bank_addr = flash_nor_get_bank_addr(FLASH_OTA_BANK_1);
        }
        else
        {
            temp_bank_addr = ota_bank0_addr;
        }
        if (image_id == OTA)
        {
            image_addr = temp_bank_addr;
        }
        else if (image_id >= SecureBoot && image_id < IMAGE_MAX)
        {
            if (IMG_CHECK_PASS != check_header_valid(temp_bank_addr, OTA))
            {
                return 0;
            }
            image_addr = *get_image_addr_in_bank(temp_bank_addr, image_id);
        }
    }
    if (image_addr == 0xffffffff)
    {
        return 0;
    }
    return image_addr;
}
/* ROM function get_temp_ota_bank_size_by_img_id has bugs,
so a new patch_get_temp_ota_bank_size_by_img_id is implemented here */
uint32_t patch_get_temp_ota_bank_size_by_img_id(T_IMG_ID image_id)
{
    uint32_t image_size = 0;

    if (image_id < OTA || ((image_id >= IMAGE_MAX)))
    {
        return image_size;
    }

    if (!is_ota_support_bank_switch())
    {
        if (image_id == OTA)
        {
            return 0;
        }
        /* Fix ROM implementation bugs at this line */
        image_size = flash_nor_get_bank_size(FLASH_OTA_TMP);
    }
    else
    {
        uint32_t ota_bank0_addr = flash_nor_get_bank_addr(FLASH_OTA_BANK_0);
        uint32_t temp_bank_addr;

        if (ota_bank0_addr == get_active_ota_bank_addr())
        {
            temp_bank_addr = flash_nor_get_bank_addr(FLASH_OTA_BANK_1);
        }
        else
        {
            temp_bank_addr = ota_bank0_addr;
        }

        if (image_id == OTA)
        {
            image_size = OTA_HEADER_SIZE;
        }
        else if (image_id >= SecureBoot && image_id < IMAGE_MAX)
        {
            if (IMG_CHECK_PASS != check_header_valid(temp_bank_addr, OTA))
            {
                return 0;
            }

            image_size = *get_image_size_in_bank(temp_bank_addr, image_id);
        }
    }

    return image_size;
}

void print_all_images_version(void)
{
    T_IMG_ID image_id;
    T_IMAGE_VERSION image_version;

    image_id = OTA;
    if (get_active_bank_image_version(image_id, &image_version))
    {
        LOG_INF("image:0x%x,version =0x%x, sub_version:%d.%d.%d.%d", image_id,
                image_version.ver_info.version,
                image_version.ver_info.header_sub_version._version_major,
                image_version.ver_info.header_sub_version._version_minor,
                image_version.ver_info.header_sub_version._version_revision,
                image_version.ver_info.header_sub_version._version_reserve);
    }
    else
    {
        LOG_INF("image:0x%x get_active_bank_image_version fail!!!", image_id);
    }
    for (image_id = SecureBoot; image_id < IMAGE_MAX && image_id != AppConfigFile; image_id++)
    {
        if (get_active_bank_image_version(image_id, &image_version))
        {
            LOG_INF("image:0x%x,version =0x%x, sub_version:%d.%d.%d.%d", image_id,
                    image_version.ver_info.version,
                    image_version.ver_info.img_sub_version._version_major,
                    image_version.ver_info.img_sub_version._version_minor,
                    image_version.ver_info.img_sub_version._version_revision,
                    image_version.ver_info.img_sub_version._version_reserve);
        }
        else
        {
            LOG_INF("image:0x%x get_active_bank_image_version fail!!!", image_id);
        }
    }

    image_id = AppConfigFile;
    if (get_active_bank_image_version(image_id, &image_version))
    {
        LOG_INF("image:0x%x,version =0x%x, sub_version:%d.%d.%d.%d", image_id,
                image_version.ver_info.version,
                image_version.ver_info.header_sub_version._version_major,
                image_version.ver_info.header_sub_version._version_minor,
                image_version.ver_info.header_sub_version._version_revision,
                image_version.ver_info.header_sub_version._version_reserve);
    }
    else
    {
        LOG_INF("image:0x%x get_active_bank_image_version fail!!!", image_id);
    }

    T_IMG_CTRL_HEADER_FORMAT user_ctrl_header;
    flash_nor_read_locked(flash_nor_get_bank_addr(FLASH_BKP_DATA1) + offsetof(T_IMG_HEADER_FORMAT,
                                                                              ctrl_header),
                          (uint8_t *)&user_ctrl_header,
                          sizeof(T_IMG_CTRL_HEADER_FORMAT));
    LOG_INF("image:0x%x, not_ready=%d",
            user_ctrl_header.image_id, user_ctrl_header.ctrl_flag.flag_value.not_ready);

    if (user_ctrl_header.image_id == IMAGE_USER_DATA &&
        !user_ctrl_header.ctrl_flag.flag_value.not_ready)
    {
        T_IMAGE_VERSION usr_data_version;
        flash_nor_read_locked(flash_nor_get_bank_addr(FLASH_BKP_DATA1) + offsetof(T_IMG_HEADER_FORMAT,
                                                                                  git_ver),
                              (uint8_t *)&usr_data_version,
                              sizeof(T_IMAGE_VERSION));

        LOG_INF("image:0x%x,version =0x%x, sub_version:%d.%d.%d.%d", user_ctrl_header.image_id,
                usr_data_version.ver_info.version,
                usr_data_version.ver_info.img_sub_version._version_major,
                usr_data_version.ver_info.img_sub_version._version_minor,
                usr_data_version.ver_info.img_sub_version._version_revision,
                usr_data_version.ver_info.img_sub_version._version_reserve);
    }
    else
    {
        LOG_INF("user data is not exist!!!");
    }

    flash_nor_read_locked(flash_nor_get_bank_addr(FLASH_BKP_DATA2) + offsetof(T_IMG_HEADER_FORMAT,
                                                                              ctrl_header),
                          (uint8_t *)&user_ctrl_header,
                          sizeof(T_IMG_CTRL_HEADER_FORMAT));
    LOG_INF("image:0x%x, not_ready=%d",
            user_ctrl_header.image_id, user_ctrl_header.ctrl_flag.flag_value.not_ready);
    if (user_ctrl_header.image_id == IMAGE_USER_DATA2 &&
        !user_ctrl_header.ctrl_flag.flag_value.not_ready)
    {
        T_IMAGE_VERSION usr_data_version;
        flash_nor_read_locked(flash_nor_get_bank_addr(FLASH_BKP_DATA2) + offsetof(T_IMG_HEADER_FORMAT,
                                                                                  git_ver),
                              (uint8_t *)&usr_data_version,
                              sizeof(T_IMAGE_VERSION));

        LOG_INF("image:0x%x,version =0x%x, sub_version:%d.%d.%d.%d", user_ctrl_header.image_id,
                usr_data_version.ver_info.version,
                usr_data_version.ver_info.img_sub_version._version_major,
                usr_data_version.ver_info.img_sub_version._version_minor,
                usr_data_version.ver_info.img_sub_version._version_revision,
                usr_data_version.ver_info.img_sub_version._version_reserve);
    }
    else
    {
        LOG_INF("user data2 is not exist!!!");
    }
}

void print_flash_layout(void)
{
    T_IMG_ID image_id;
    uint32_t img_addr = 0;
    uint32_t img_size = 0;

    bool is_enable_bank_switch = is_ota_support_bank_switch();
    LOG_INF("Flash Layout bank switch=%d(0: disable)", is_enable_bank_switch);

    for (image_id = OTA; image_id < IMAGE_MAX; image_id++)
    {
        img_addr = get_header_addr_by_img_id(image_id);
        img_size = get_active_bank_image_size_by_img_id(image_id);
        LOG_INF("Active Bank Image id 0x%x: Addr=0x%x, size=0x%x", image_id, img_addr, img_size);
    }

    if (is_enable_bank_switch)
    {
        for (image_id = OTA; image_id < IMAGE_MAX; image_id++)
        {
            img_addr = get_temp_ota_bank_addr_by_img_id(image_id);
            img_size = patch_get_temp_ota_bank_size_by_img_id(image_id);
            LOG_INF("Temp Bank Image id 0x%x: Addr=0x%x, size=0x%x", image_id, img_addr, img_size);
        }
    }

    LOG_INF("FTL: Addr=0x%x, size=0x%x", flash_nor_get_bank_addr(FLASH_FTL),
            flash_nor_get_bank_size(FLASH_FTL));
    LOG_INF("OTA TEMP: Addr=0x%x, size=0x%x", flash_nor_get_bank_addr(FLASH_OTA_TMP),
            flash_nor_get_bank_size(FLASH_OTA_TMP));
}
