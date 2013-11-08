cmake_minimum_required(VERSION 2.6)

add_definitions(-D_GNU_SOURCE -D_BSD_SOURCE)
set(CMAKE_C_FLAGS "-std=c99 -Wall -pedantic -g -Wextra -Wno-unused-parameter -Wformat -Wparentheses -Wl,--no-undefined ${CMAKE_C_FLAGS}")

# Set LIB_SUFFIX to 64 on 64bit architectures
if(CMAKE_SIZEOF_VOID_P EQUAL 4)
    set(LIB_SUFFIX "")
else(CMAKE_SIZEOF_VOID_P EQUAL 4)
    SET(LIB_SUFFIX 64)
endif(CMAKE_SIZEOF_VOID_P EQUAL 4)

include(OpenLMIMacros RESULT_VARIABLE LMIMACROS)

if (${LMIMACROS} STREQUAL "NOTFOUND")
    message(FATAL_ERROR "OpenLMIMacros.cmake not found, check if openlmi-providers(-devel) is installed")
endif (${LMIMACROS} STREQUAL "NOTFOUND")

# Find required packages
find_package(CMPI REQUIRED)
find_package(KonkretCMPI REQUIRED)

add_subdirectory(src)
add_subdirectory(mof)
