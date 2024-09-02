# Copyright (c) 2024 Realtek Semiconductor Corp.
# SPDX-License-Identifier: Apache-2.0
zephyr_link_libraries_ifdef(CONFIG_REALTEK_USING_SDK_LIB ${CMAKE_CURRENT_SOURCE_DIR}/librtl87x2g_sdk.a)
