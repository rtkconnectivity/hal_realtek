# Copyright (c) 2024 Realtek Semiconductor Corp.
# SPDX-License-Identifier: Apache-2.0

zephyr_library()

if(CONFIG_REALTEK_TIM)
zephyr_library_sources(rtl876x_tim.c)
endif()

if(CONFIG_REALTEK_ENHTIM)
zephyr_library_sources(rtl876x_enh_tim.c)
endif()

if (CONFIG_PM_DEVICE)
if(CONFIG_REALTEK_TIM)
zephyr_library_sources(rtl8752h_tim.c)
if (CONFIG_REALTEK_DRIVER_DLPS_CALLBACK_ON_RAM)
zephyr_code_relocate(FILES rtl8752h_tim.c LOCATION RAM)
endif()
endif()

if(CONFIG_REALTEK_ENHTIM)
zephyr_library_sources(rtl8752h_enh_tim.c)
if (CONFIG_REALTEK_DRIVER_DLPS_CALLBACK_ON_RAM)
zephyr_code_relocate(FILES rtl8752h_enh_tim.c LOCATION RAM)
endif()
endif()
endif()
