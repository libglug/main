project(glug_main)
cmake_minimum_required(VERSION 2.8)

include(cmake/os.cmake)

set(GLUG_MAIN_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/glug_main)
set(MAIN_INCLUDE_ROOT ${GLUG_MAIN_ROOT}/include)
include_directories(${MAIN_INCLUDE_ROOT})

add_subdirectory(glug_main/src)
add_subdirectory(example)
