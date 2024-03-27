# SPDX-License-Identifier: Apache-2.0

zephyr_library()
zephyr_library_sources(osif_zephyr.c)
zephyr_code_relocate(FILES osif_zephyr.c LOCATION ITCM_TEXT)
