# Copyright (c) 2024 Realtek Semiconductor Corp.
# SPDX-License-Identifier: Apache-2.0

# Using Newlibc: 1. implement the osif version of _malloc_r,_calloc_r,_realloc_r and _free_r.
#                2. -u,strncmp: make sure strncmp is not trimmed. 
# Using other libc: implement the osif version of malloc,calloc,realloc and free.
# Common: implement the __wrap_memset_s and __wrap_memcpy_s in hal lib.
if(CONFIG_NEWLIB_LIBC)
zephyr_ld_options(-Wl,-wrap=_malloc_r,-wrap=_calloc_r,-wrap=_realloc_r,-wrap=_free_r,-wrap=memset_s,-wrap=memcpy_s,-u,strncmp)
else()
zephyr_ld_options(-Wl,-wrap=malloc,-wrap=calloc,-wrap=realloc,-wrap=free,-wrap=memset_s,-wrap=memcpy_s)
endif()

add_subdirectory(src)
if(CONFIG_REALTEK_LIBS_NANDBOOT)
# The prebuilt nandboot lib references newlib memset/memcpy/... which live in
# flash. The NAND/flash boot path runs at moments where XIP flash / PSRAM cannot
# execute code, so those calls would fault. Rewrite the references in the
# archive to our RAM-resident rtk_ram_* implementations (see src/rtk_ram_libc.c)
# WITHOUT touching the rest of the firmware's (faster) newlib memcpy/memset.
set(_nb_src ${CMAKE_CURRENT_SOURCE_DIR}/libhal_utils_nandboot.a)
set(_nb_out ${CMAKE_CURRENT_BINARY_DIR}/libhal_utils_nandboot_ramfn.a)
# Re-run configure (and thus this objcopy) whenever the prebuilt blob changes.
set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS ${_nb_src})
execute_process(
  COMMAND ${CMAKE_OBJCOPY}
          --redefine-sym memset=rtk_ram_memset
          ${_nb_src} ${_nb_out}
  RESULT_VARIABLE _nb_rc)
if(NOT _nb_rc EQUAL 0)
  message(FATAL_ERROR "objcopy --redefine-sym on nandboot lib failed (${_nb_rc})")
endif()
zephyr_link_libraries(${_nb_out})
else()
zephyr_link_libraries(${CMAKE_CURRENT_SOURCE_DIR}/libhal_utils.a)
endif()
zephyr_include_directories(inc/platform)
zephyr_include_directories(inc/power)
zephyr_include_directories(inc/io)
zephyr_include_directories(inc/rtl87x3g)
zephyr_include_directories(inc/rtl87x3g/stack)

