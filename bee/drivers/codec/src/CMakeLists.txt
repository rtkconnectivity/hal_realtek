# Copyright (c) 2024 Realtek Semiconductor Corp.
# SPDX-License-Identifier: Apache-2.0

if(DEFINED CONFIG_SOC_SERIES_RTL8752H)
	zephyr_include_directories(rtl8752h)
elseif(DEFINED CONFIG_SOC_SERIES_RTL87X2G)
	zephyr_include_directories(rtl87x2g)
endif()

add_subdirectory_ifdef(CONFIG_SOC_SERIES_RTL8752H rtl8752h)
add_subdirectory_ifdef(CONFIG_SOC_SERIES_RTL87X2G rtl87x2g)
