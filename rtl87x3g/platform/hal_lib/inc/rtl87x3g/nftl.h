/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef _NFTL_H_
#define _NFTL_H_

#include <stdint.h>
#include <stdbool.h>
#include "errno.h"

#ifdef  __cplusplus
extern  "C" {
#endif  // __cplusplus

bool nftl_init(uint32_t address, uint32_t size);

bool nftl_module_init(char *module_name, uint32_t logic_size);
uint32_t nftl_module_write(char *module_name, uint32_t offset, void *pdata, uint32_t size);
uint32_t nftl_module_read(char *module_name, uint32_t offset, void *pdata, uint32_t size);
uint32_t nftl_module_release(char *module_name, uint32_t offset, uint32_t size);

#ifdef  __cplusplus
}
#endif // __cplusplus

#endif // _FTL_H_
