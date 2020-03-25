set(TESTED_LIB glug_main)
find_package(${TESTED_LIB} REQUIRED)

set(TEST_TARGET_NAME ${TESTED_LIB}_test)

if (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    add_executable(
        ${TEST_TARGET_NAME}
        WIN32
        winmain.c
    )

    # workaround for MinGW not including WinMain from a static library (.a archive file)
    if ("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
        target_link_libraries(
            ${TEST_TARGET_NAME}
            -Wl,--whole-archive ${TESTED_LIB} -Wl,--no-whole-archive
        )
    endif()

else()

    add_executable(
        ${TEST_TARGET_NAME}
        main.c
    )

endif()

target_link_libraries(
    ${TEST_TARGET_NAME}
    ${TESTED_LIB}
)

add_test(${TEST_TARGET_NAME} ${TEST_TARGET_NAME} "HELLO" "hallo" "hola" "こんにちは")

# create a custom target which builds tests and their dependencies
add_custom_target(
    check
    ALL
    DEPENDS
        ${TEST_TARGET_NAME}
)
