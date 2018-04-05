set(SRC
    "main.cpp"
)

set(SRC_C
    "main.c"
)

set(PLATFORM "")
if (${GLUG_OS_WIN32})
    set(PLATFORM WIN32)
endif()

add_executable(main_test ${PLATFORM} ${SRC})
add_executable(main_test_c ${PLATFORM} ${SRC_C})

set(MAIN_LIB -Wl,--whole-archive glug_main -Wl,--no-whole-archive)

target_link_libraries(main_test ${MAIN_LIB})
target_link_libraries(main_test_c ${MAIN_LIB})
