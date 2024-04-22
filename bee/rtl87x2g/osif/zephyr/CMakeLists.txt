# SPDX-License-Identifier: Apache-2.0

zephyr_library()
zephyr_library_sources(osif_zephyr.c)
zephyr_code_relocate(FILES osif_zephyr.c LOCATION ITCM)
zephyr_include_directories(${ZEPHYR_BASE}/arch/arm/include)
zephyr_include_directories(${ZEPHYR_BASE}/kernel/include)
