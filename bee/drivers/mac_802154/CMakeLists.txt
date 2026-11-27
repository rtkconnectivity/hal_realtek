# Copyright (c) 2024 Realtek Semiconductor Corp.
# SPDX-License-Identifier: Apache-2.0

if(NOT DEFINED MAC_802154_DEV_BUILD)
    set(MAC_802154_DEV_BUILD "OFF")
endif()

# The SoC series selects both the porting headers and the prebuilt archive.
# Anything other than a series with a directory under portable/ is unsupported.
string(TOLOWER "${CONFIG_SOC_SERIES}" MAC_SOC)

if(${MAC_802154_DEV_BUILD} STREQUAL "ON")
zephyr_library()
zephyr_library_sources(mac_driver/mac_802154_frame_parser.c)
zephyr_library_sources(mac_driver/mac_stats.c)
zephyr_library_sources(mac_driver/private/mac_driver_ext.c)
zephyr_library_sources(mac_driver/private/${MAC_SOC}/patch.c)
zephyr_library_compile_options(
    -DDEV_BUILD
)
zephyr_include_directories(inc)
zephyr_include_directories(inc/${MAC_SOC})
zephyr_include_directories(mac_driver)
zephyr_include_directories(mac_driver/portable/${MAC_SOC})
zephyr_include_directories(mac_driver/private)
zephyr_include_directories(mac_driver/private/${MAC_SOC})
zephyr_code_relocate(FILES mac_driver/mac_802154_frame_parser.c LOCATION ITCM_TEXT)
zephyr_code_relocate(FILES mac_driver/mac_stats.c LOCATION ITCM_TEXT)
zephyr_code_relocate(FILES mac_driver/private/mac_driver_ext.c LOCATION ITCM_TEXT)
zephyr_code_relocate(FILES mac_driver/private/${MAC_SOC}/patch.c LOCATION ITCM_TEXT)
else()
set(MAC_LIB "${CMAKE_CURRENT_SOURCE_DIR}/lib/${MAC_SOC}/librtl87x2g-mac_802154.a")
if(NOT EXISTS "${MAC_LIB}")
    message(FATAL_ERROR
        "mac_802154: no prebuilt archive for ${MAC_SOC} at ${MAC_LIB}. "
        "Build with -DMAC_802154_DEV_BUILD=ON, or add the archive.")
endif()

zephyr_library_import(lib_mac_802154 "${MAC_LIB}")
zephyr_include_directories(inc)
zephyr_include_directories(inc/${MAC_SOC})
# Consumers reach a few headers that are not part of the public surface.
# Exposing the source tree is acceptable here because the archive is what
# actually provides the implementation; nothing links against these sources.
zephyr_include_directories(mac_driver)
zephyr_include_directories(mac_driver/portable/${MAC_SOC})

# ITCM placement cannot be driven through zephyr_code_relocate() for an
# imported archive: it resolves the target's SOURCES property, an imported
# target has none, and gen_relocate_app.py silently drops the empty file list.
#
# A plain `-T` fragment does not work either. Zephyr's linker.ld is passed last
# and its own .text wildcards claim the archive sections first, so anything
# named in an earlier fragment matches nothing. zephyr_linker_sources() splices
# the fragment into linker.ld at the ITCM insertion point instead, after the
# generic text rules.
set(MAC_ITCM "${CMAKE_CURRENT_SOURCE_DIR}/ld/${MAC_SOC}/mac_802154_itcm.ld")
if(EXISTS "${MAC_ITCM}")
    zephyr_linker_sources(ITCM_SECTION "${MAC_ITCM}")
else()
    message(WARNING
        "mac_802154: no ITCM fragment for ${MAC_SOC}; the archive stays in "
        "flash and the hot 802.15.4 path will be slower.")
endif()
endif()
