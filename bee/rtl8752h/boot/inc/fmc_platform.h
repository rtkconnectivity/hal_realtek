/**
 *****************************************************************************************
 *     Copyright(c) 2018, Realtek Semiconductor Corporation. All rights reserved.
 *****************************************************************************************
 * @file    fmc_platform.h
 * @brief   Flexible memory controller (SPIC & PSRAMC) platform dependent implementation header file
 * @author  Yao-Yu
 * @date    2020-10-20
 * @version v0.1
 * ***************************************************************************************
 */

#ifndef _FMC_PLATFORM_H
#define _FMC_PLATFORM_H

#include "stdint.h"

#define _PACKED_                __attribute__((packed))

/****************************************************************************************
 * Flexible Memory Controller Address Map
 ****************************************************************************************/
#define FMC_MAIN0_ADDR                                      (SPIC0_ADDR)
#define FMC_MAIN0_SIZE                                      (SPIC0_SIZE)
#define FMC_MAIN0_UNCACHEABLE_ADDR                          (FLASH_OFFSET_TO_NO_CACHE)
#define FMC_MAIN0_NON_CACHE_ADDR(cache_addr)                ((cache_addr) & ~(FMC_MAIN0_ADDR) | (FMC_MAIN0_UNCACHEABLE_ADDR))

/********************************FLASH_OFFSET_TO_NO_CACHE********************************************************
 * Flexible Memory Controller Address Map Checking
 ****************************************************************************************/
#define FMC_IS_SPIC0_CACHEABLE_ADDR(addr)                   ((addr >= FMC_MAIN0_ADDR) && (addr < FMC_MAIN0_ADDR + FMC_MAIN0_SIZE))
#define FMC_IS_SPIC0_UNCACHEABLE_ADDR(addr)                 ((addr >= FMC_MAIN0_UNCACHEABLE_ADDR) && (addr < FMC_MAIN0_UNCACHEABLE_ADDR + FMC_MAIN0_SIZE))
#define FMC_IS_SPIC0_ADDR(addr)                             (FMC_IS_SPIC0_CACHEABLE_ADDR(addr) || FMC_IS_SPIC0_UNCACHEABLE_ADDR(addr))


#endif
