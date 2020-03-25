cmake_minimum_required(VERSION 3.0)

set(VER_MAJOR 1)
set(VER_MINOR 0)
set(VER_PATCH 0)
project(glug_main VERSION ${VER_MAJOR}.${VER_MINOR}.${VER_PATCH})

set(COM_ROOT common_headers/include/glug)
set(SRC_ROOT src)
set(INC_ROOT include/glug)

list(
    APPEND
    SOURCE
    ${COM_ROOT}/bool.h
    ${COM_ROOT}/extern.h
    ${COM_ROOT}/import.h
    ${COM_ROOT}/namespace.h
    ${COM_ROOT}/os.h
    ${INC_ROOT}/main.h
    ${SRC_ROOT}/win_main.c
    ${SRC_ROOT}/glug_main.c
)

if ("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")
    set(UNSUPPORTED_SOURCE ${SRC_ROOT}/glug_main.c)
else()
    set(UNSUPPORTED_SOURCE ${SRC_ROOT}/win_main.c)
endif()

set_source_files_properties(${UNSUPPORTED_SOURCE} PROPERTIES HEADER_FILE_ONLY TRUE)

add_library(
    ${PROJECT_NAME}
    STATIC
    ${SOURCE}
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/common_headers/include>
    INTERFACE
        $<INSTALL_INTERFACE:include>
)

# install the library
install(
    TARGETS
        ${PROJECT_NAME}
    EXPORT
        Find${PROJECT_NAME}
    DESTINATION
        lib
)

#install the lib's headers
install(
    DIRECTORY
        include/
    DESTINATION
        include
)

# install the common_headers
install(
    DIRECTORY
        common_headers/include/
    DESTINATION
        include
    FILES_MATCHING PATTERN
        "*.h"
)

# export the package to be included in other projects
export(PACKAGE ${PROJECT_NAME})
export(
    TARGETS
        ${PROJECT_NAME}
    FILE
        ${PROJECT_NAME}-config.cmake
)

# install export file
install(
    EXPORT
        Find${PROJECT_NAME}
    DESTINATION
        cmake
)
