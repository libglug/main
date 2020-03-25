set(TESTED_LIB glug_main)
find_package(${TESTED_LIB} REQUIRED)

set(TEST_TARGET_NAME ${TESTED_LIB}_test)

add_executable(
    ${TEST_TARGET_NAME}
    WIN32
    main.c
)

# workaround for MinGW not including WinMain from a static library (.a archive file)
if (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    if ("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
        target_link_libraries(
            ${TEST_TARGET_NAME}
            mingw32
        )
    endif()
endif()
target_link_libraries(
    ${TEST_TARGET_NAME}
    ${TESTED_LIB}
)

add_test(${TEST_TARGET_NAME} ${TEST_TARGET_NAME} "HELLO" "glug")

# create a custom target which builds tests and their dependencies
add_custom_target(
    check
    ALL
    DEPENDS
        ${TEST_TARGET_NAME}
)
