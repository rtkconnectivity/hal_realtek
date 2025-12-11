# Copyright (c) 2025 Realtek Semiconductor Corp.
# SPDX-License-Identifier: Apache-2.0

zephyr_library()

zephyr_library_sources(rtl876x_qdec.c)

if (CONFIG_PM_DEVICE)
zephyr_library_sources(rtl8752h_qdec.c)
if (CONFIG_REALTEK_DRIVER_DLPS_CALLBACK_ON_RAM)
zephyr_code_relocate(FILES rtl8752h_qdec.c LOCATION RAM)
endif()
endif()
