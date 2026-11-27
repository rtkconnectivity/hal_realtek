/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 * SPDX-License-Identifier: Apache-2.0
 *
 * ITCM placement for the prebuilt mac_802154 archive, included by Zephyr's
 * linker.ld through zephyr_linker_sources(ITCM_SECTION ...).
 *
 * The source build uses zephyr_code_relocate(FILES ... LOCATION ITCM_TEXT),
 * which rewrites each object so its functions carry .rel.text.* names that the
 * generated linker_relocate.ld collects. That cannot target an imported
 * archive: the function resolves the target's SOURCES property, an imported
 * target has none, and gen_relocate_app.py drops the empty file list silently,
 * leaving `ITCM_TEXT:COPY:,` behind with no warning.
 *
 * Measured sizes for rtl87x2g (text + rodata):
 *
 *   patch.c                    6970 B
 *   mac_driver_ext.c           3904 B
 *   mac_802154_frame_parser.c  1186 B
 *   mac_stats.c                   0 B
 *                             ------
 *                             12060 B
 *
 * ITCM is 28672 B and the rest of the image claims 12956 B, leaving ~4.6 KB.
 *
 * KEEP() is required: the archive is linked --whole-archive, so every member is
 * present, but --gc-sections would then discard whatever nothing references,
 * which for mac_driver_ext.c is most of its 397 weak functions.
 */

KEEP(*mac_802154_frame_parser.c.obj(.text .text.*))
KEEP(*mac_driver_ext.c.obj(.text .text.*))
KEEP(*patch.c.obj(.text .text.*))

KEEP(*mac_802154_frame_parser.c.obj(.rodata .rodata.*))
KEEP(*mac_driver_ext.c.obj(.rodata .rodata.*))
KEEP(*patch.c.obj(.rodata .rodata.*))
