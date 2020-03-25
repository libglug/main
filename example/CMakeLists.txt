project(example)

set(LIB glug_main)
find_package(${LIB} REQUIRED)

# create simple example with simple dependencies
function (add_example)
    set(OPTIONS)
    set(SINGLE_VALS TARGET_NAME LINK_LIB INSTALL_PATH)
    set(MULTI_VALS SRCS)
    cmake_parse_arguments(XMPL "${OPTIONS}" "${SINGLE_VALS}" "${MULTI_VALS}" ${ARGN})

    add_executable(${XMPL_TARGET_NAME} WIN32 ${XMPL_SRCS})

    # workaround for MinGW not including WinMain from a static library (.a archive file)
    if (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
        if ("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
            target_link_libraries(
                ${XMPL_TARGET_NAME}
                -Wl,--whole-archive ${LIB} -Wl,--no-whole-archive
            )
        endif()
    endif()

    target_link_libraries(${XMPL_TARGET_NAME} ${LIB} ${XMPL_LINK_LIB})

    set_target_properties(
        ${XMPL_TARGET_NAME}
        PROPERTIES
            INSTALL_RPATH "$ORIGIN;@loader_path"
            BUILD_WITH_INSTALL_RPATH TRUE
    )

    install(
        TARGETS
            ${XMPL_TARGET_NAME}
        DESTINATION
            ${XMPL_INSTALL_PATH}
    )

endfunction()

set(GLUG_TARGET_NAME ${LIB}_c)
set(GLUG_TARGET_NAME++ ${LIB}_c++)

set(INSTALL_PATH example)

add_example(
    TARGET_NAME
        ${GLUG_TARGET_NAME}
    SRCS
        main.c
    INSTALL_PATH
        ${INSTALL_PATH}
)

add_example(
    TARGET_NAME
        ${GLUG_TARGET_NAME++}
    SRCS
        main.cpp
    INSTALL_PATH
        ${INSTALL_PATH}
)
