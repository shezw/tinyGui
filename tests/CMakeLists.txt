
#============================================================================
# Example binaries
#============================================================================

include_directories(
        ${CMAKE_CURRENT_BINARY_DIR}/tinyguiconf.h
        src
        src/acc
        src/core
        src/gui
        src/platform
        src/proxy
)
add_executable(example tests/example.c)
target_link_libraries(example tinygui)

add_executable(event_test tests/event.c)
target_link_libraries(event_test tinygui)
