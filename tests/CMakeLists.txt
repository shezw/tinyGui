
#============================================================================
# Example binaries
#============================================================================

include_directories(
        ${CMAKE_CURRENT_BINARY_DIR}
        src
        src/acc
        src/core
        src/gui
        src/platform
        src/proxy
)
add_executable(tg_example tests/example.c)
target_link_libraries(tg_example tinygui)

add_executable(tg_event_test tests/event.c)
target_link_libraries(tg_event_test tinygui)

set(ALL_TESTS
    tg_example
    tg_event_test
)

if (NOT SKIP_INSTALL_BIN AND NOT SKIP_INSTALL_ALL )
    install(TARGETS ${ALL_TESTS} DESTINATION ${INSTALL_BIN_DIR})
endif ()