/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _FLASH_NAND_ADV_DRIVER_H
#define _FLASH_NAND_ADV_DRIVER_H

#include <stdint.h>
#include <stdbool.h>
#include "flash_nand_basic.h"

typedef void (*FLASH_NAND_ASYNC_CB)(void);

bool flash_nand_auto_dma_read(uint32_t src_addr, uint32_t dest_addr, uint32_t len,
                              FLASH_NAND_ASYNC_CB cb);


FLASH_NAND_RET_TYPE flash_nand_page_read(uint32_t addr, uint8_t *data, uint32_t length);
FLASH_NAND_RET_TYPE flash_nand_page_write(uint32_t addr, uint8_t *data, uint32_t length);
bool flash_nand_remapping(uint32_t dest_flash_addr, uint32_t src_flash_addr, uint32_t remap_size);
#endif
