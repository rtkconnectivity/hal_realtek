/**************************************************************************//**
 * @file     mac_port_macro.h
 * @brief    Header file for MAC/PHY driver platform porting macros.
 *
 * @version  V1.00
 * @date     2022-09-14
 *
 * @note
 *
 ******************************************************************************
 *
 * Copyright(c) 2007 - 2022 Realtek Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ******************************************************************************/


#ifndef _MAC_DRIVER_PORT_H_
#define _MAC_DRIVER_PORT_H_

/* define macros for MAC driver porting on the specified platform here */
#if defined(__ZEPHYR__)
#if defined(DEV_BUILD)
#include "address_map.h"
#include "cpu_setting.h"
#endif
#else
#include "rtl876x.h"                           /*!< ARM Cortex-M4 processor and core peripherals                              */
#endif

#define PORT_CATEGORY_BT_SOC
#define PORT_PLATFORM_RTL87X2G
#define MAC_ROM_VER (0x20230720)

#define DEFAULT_RF_MODE     RF_TPM
#ifndef _IS_ASIC_   // FPGA, use external RF board
#undef DEFAULT_RF_MODE
#define DEFAULT_RF_MODE     RF_IQM
#endif

#endif  /* end of _MAC_DRIVER_PORT_H_ */
