project(example)
include(cmake/add_example.cmake)

set(LIB glug_main)
find_package(${LIB} REQUIRED)
set(GLUG_TARGET_NAME ${LIB}_test)

set(INSTALL_PATH example)

add_example(
    USE_WINMAIN
    TARGET_NAME
        ${GLUG_TARGET_NAME}
    SRCS
        main.c
    LINK_LIB
        ${LIB}
    INSTALL_PATH
        ${INSTALL_PATH}
)

add_example(
    USE_WINMAIN
    TARGET_NAME
        ${GLUG_TARGET_NAME}++
    SRCS
        main.cpp
    LINK_LIB
        ${LIB}
    INSTALL_PATH
        ${INSTALL_PATH}
)
