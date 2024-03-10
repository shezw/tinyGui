
#============================================================================
# libtinygui
#============================================================================
set(LIBTINYGUI_PUBLIC_CORE_HDRS

        src/core/buffer.h
        src/core/event.h
        src/core/layer.h
        src/core/loop.h
        src/core/screen.h

        )

set(LIBTINYGUI_PUBLIC_UI_HDRS

        src/gui/button.h

        )

set(LIBTINYGUI_PUBLIC_PROXY_HDRS

        src/proxy/fill.h
        src/proxy/blend.h
        src/proxy/memory.h

        )

set(LIBTINYGUI_PUBLIC_HDRS
        ${CMAKE_CURRENT_BINARY_DIR}/tinyguiconf.h

        src/types.h
        src/tinygui.h

        )

set(LIBTINYGUI_PRIVATE_HDRS

        )

set(LIBTINYGUI_SRCS
        src/core/buffer.c
        src/core/event.c
        src/core/layer.c
        src/core/loop.c
        src/core/screen.c
        src/core/tinygui.c

        src/gui/

        src/proxy/fill.c
        src/proxy/blend.c
        src/proxy/memory.c
        )

add_library(tinygui SHARED ${LIBTINYGUI_SRCS} ${LIBTINYGUI_PUBLIC_HDRS} ${LIBTINYGUI_PRIVATE_HDRS})
add_library(tinygui-static STATIC ${LIBTINYGUI_SRCS} ${LIBTINYGUI_PUBLIC_HDRS} ${LIBTINYGUI_PRIVATE_HDRS})
set_target_properties(tinygui PROPERTIES SOVERSION 1)
set_target_properties(tinygui PROPERTIES VERSION ${VERSION})

if(UNIX)
    set_target_properties(tinygui tinygui-static PROPERTIES OUTPUT_NAME tinygui)
endif()

if(NOT SKIP_INSTALL_LIBRARIES AND NOT SKIP_INSTALL_ALL )
    install(TARGETS tinygui tinygui-static
            RUNTIME DESTINATION "${INSTALL_BIN_DIR}"
            ARCHIVE DESTINATION "${INSTALL_LIB_DIR}"
            LIBRARY DESTINATION "${INSTALL_LIB_DIR}" )
endif()
if(NOT SKIP_INSTALL_HEADERS AND NOT SKIP_INSTALL_ALL )
    install(FILES ${LIBTINYGUI_PUBLIC_CORE_HDRS} DESTINATION "${INSTALL_INC_DIR}/tinygui/core")
    install(FILES ${LIBTINYGUI_PUBLIC_UI_HDRS} DESTINATION "${INSTALL_INC_DIR}/tinygui/ui")
    install(FILES ${LIBTINYGUI_PUBLIC_PROXY_HDRS} DESTINATION "${INSTALL_INC_DIR}/tinygui/proxy")
    install(FILES ${LIBTINYGUI_PUBLIC_HDRS} DESTINATION "${INSTALL_INC_DIR}/tinygui")
endif()
if(NOT SKIP_INSTALL_FILES AND NOT SKIP_INSTALL_ALL )
    install(FILES ${LIBTINYGUI_PC} DESTINATION "${INSTALL_PKGCONFIG_DIR}")
endif()
