cmake_minimum_required(VERSION 3.0)
cmake_policy(SET CMP0054 NEW)
project(glug_main_suite)

set(GLUG_LIB_TARGET glug_main)
option(BUILD_XMPLS "Build the examples?")

# disable find_package in any subproject for finding this lib
macro(find_package)
    if (NOT "${ARGV0}" STREQUAL ${GLUG_LIB_TARGET})
        _find_package(${ARGV})
    endif()
endmacro()

# add the library subproject
add_subdirectory(${GLUG_LIB_TARGET})

# build and install examples
if (${BUILD_XMPLS} STREQUAL "ON")
    add_subdirectory(example)
endif()
