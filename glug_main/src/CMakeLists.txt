include(${PROJECT_SOURCE_DIR}/cmake/compile.cmake)

set(MAIN_SRC_ROOT ${GLUG_MAIN_ROOT}/src)
set(MAIN_INC_ROOT ${MAIN_INCLUDE_ROOT}/glug)

set(MAIN_HEADERS
    ${MAIN_INC_ROOT}/main.h
)

set(MAIN_SOURCES
    ${MAIN_SRC_ROOT}/glug_main.c
)

set(WIN32_SOURCES
    ${MAIN_SRC_ROOT}/win_main.c
)

set_compilation_props("${WIN32_SOURCES}" GLUG_OS_WIN32)

if (${GLUG_OS_WIN32})
    set_compilation_props("${MAIN_SOURCES}" "")
else()
    set_compilation_props("${MAIN_SOURCES}" TRUE)
endif()

add_library(
    ${PROJECT_NAME}
    STATIC
    ${MAIN_HEADERS}
    ${MAIN_SOURCES}
    ${WIN32_SOURCES}
)
