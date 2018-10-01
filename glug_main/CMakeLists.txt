include(${PROJECT_SOURCE_DIR}/cmake/macros/add_gluglib.cmake)

set(SRC_ROOT src)
set(INC_ROOT include/glug)

list(
    APPEND
    COMMON_SOURCE
    ${INC_ROOT}/main.h
)

list(
    APPEND
    WIN32_SOURCE
    ${COMMON_SOURCE}
    ${SRC_ROOT}/win_main.c
)

list(
    APPEND
    MACOS_SOURCE
    ${COMMON_SOURCE}
    ${SRC_ROOT}/glug_main.c
)

list(
    APPEND
    LINUX_SOURCE
    ${COMMON_SOURCE}
    ${SRC_ROOT}/glug_main.c
)

set(GLUG_TARGET_NAME ${CMAKE_PROJECT_NAME})

add_gluglib(
    STATIC
    TARGET_NAME ${GLUG_TARGET_NAME}
    WIN32_SOURCE ${WIN32_SOURCE}
    MACOS_SOURCE ${MACOS_SOURCE}
    LINUX_SOURCE ${LINUX_SOURCE}
)

install(
    TARGETS ${GLUG_TARGET_NAME}
    DESTINATION ${GLUG_DIST_LIBR_DIR}
)
