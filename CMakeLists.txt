#
# Copyright (c) 2018 Nordic Semiconductor
#
# SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
#
cmake_minimum_required(VERSION 3.13.1)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(NONE)

# NORDIC SDK APP START
target_sources (app PRIVATE src/main.c)
target_sources (app PRIVATE src/seggerDebug.c)
target_sources (app PRIVATE src/parseHelper.c)
# NORDIC SDK APP END

zephyr_library_include_directories(${CMAKE_CURRENT_SOURCE_DIR})
