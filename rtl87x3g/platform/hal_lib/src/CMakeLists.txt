# Copyright (c) 2024 Realtek Semiconductor Corp.
# SPDX-License-Identifier: Apache-2.0
zephyr_library_sources(hw_tim.c)
zephyr_library_sources(hal_gpio.c)
zephyr_library_sources(hal_gpio_int.c)
zephyr_library_sources(hal_dma_internal.c)
zephyr_library_sources(hal_i2c.c)
zephyr_library_sources(hal_pinmux.c)
zephyr_library_sources(pwm.c)

# RAM-resident libc used by the objcopy-patched libhal_utils_nandboot.a.
# -fno-tree-loop-distribute-patterns / -fno-builtin stop GCC from turning the
# hand-written loops back into calls to memset/memcpy (which would recurse or
# jump back into flash-resident newlib). See ../CMakeLists.txt.
zephyr_library_sources(rtk_ram_libc.c)
set_source_files_properties(rtk_ram_libc.c
  PROPERTIES COMPILE_OPTIONS "-fno-tree-loop-distribute-patterns;-fno-builtin")