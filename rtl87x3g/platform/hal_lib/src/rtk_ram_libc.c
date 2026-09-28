/* Copyright (c) 2026 Realtek Semiconductor Corp.
 * SPDX-License-Identifier: Apache-2.0
 *
 * RAM-resident (ITCM/.ram_text) replacement for memset, used ONLY by
 * libhal_utils_nandboot.a.  That archive's memset reference is rewritten to
 * rtk_ram_memset at build time via objcopy --redefine-sym (see ../CMakeLists.txt);
 * every other memset in the firmware still uses newlib.  The point is that the
 * NAND/flash boot path runs at moments where XIP flash / PSRAM cannot execute
 * code, so newlib's memset (which lives in flash) would fault.
 *
 * NOTE: this file MUST be built with -fno-tree-loop-distribute-patterns and
 * -fno-builtin, otherwise GCC recognises the loop below and replaces it with a
 * call to memset again (self-recursion / back into flash). See the
 * set_source_files_properties() in ../src/CMakeLists.txt.
 */

#include <stddef.h>
#include "section.h"

RAM_TEXT_SECTION
void *rtk_ram_memset(void *dst, int c, size_t n)
{
    unsigned char *d = (unsigned char *)dst;

    while (n--)
    {
        *d++ = (unsigned char)c;
    }
    return dst;
}
