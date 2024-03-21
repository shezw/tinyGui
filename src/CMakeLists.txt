
#============================================================================
# libtinygui
#============================================================================
set(LIBTINYGUI_PUBLIC_UTIL_HDRS

        src/utils/cobj.h

        )

set(LIBTINYGUI_PUBLIC_CORE_HDRS

        src/core/buffer.h
        src/core/event.h
        src/core/reaction.h
        src/core/layer.h
        src/core/loop.h
        src/core/screen.h

        )

set(LIBTINYGUI_PUBLIC_ACC_SW_HDRS

        src/acc/sw/sw_mem.h
        src/acc/sw/sw_fill.h
        src/acc/sw/sw_map.h
        src/acc/sw/sw_blend.h
        src/acc/sw/sw_flush.h

        src/acc/sw/sw_acc.h

        )

set(LIBTINYGUI_PUBLIC_UI_HDRS

        src/gui/button.h

        )

set(LIBTINYGUI_PUBLIC_PROXY_HDRS

        src/proxy/fill.h
        src/proxy/blend.h
        src/proxy/memory.h
        src/proxy/proxy.h

        )

set(LIBTINYGUI_PUBLIC_HDRS
        ${CMAKE_CURRENT_BINARY_DIR}/tinyguiconf.h

        src/types.h

        ${LIBTINYGUI_PUBLIC_UTILS_HDRS}
        ${LIBTINYGUI_PUBLIC_CORE_HDRS}
        ${LIBTINYGUI_PUBLIC_ACC_SW_HDRS}
        ${LIBTINYGUI_PUBLIC_UI_HDRS}
        ${LIBTINYGUI_PUBLIC_PROXY_HDRS}

        src/tinygui.h

        )

set(LIBTINYGUI_PRIVATE_HDRS

        )

set(LIBTINYGUI_SRCS
        src/core/buffer.c
        src/core/event.c
        src/core/reaction.c
        src/core/layer.c
        src/core/loop.c
        src/core/screen.c

        src/acc/sw/sw_blend.c
        src/acc/sw/sw_mem.c
        src/acc/sw/sw_fill.c
        src/acc/sw/sw_map.c
        src/acc/sw/sw_flush.c
        src/acc/sw/sw_acc.c

        src/gui/
        src/gui/button.c

        src/proxy/fill.c
        src/proxy/blend.c
        src/proxy/memory.c

        src/tinygui.c
        )

add_library(tinygui SHARED ${LIBTINYGUI_SRCS} ${LIBTINYGUI_THIRD_SRCS} ${LIBTINYGUI_PUBLIC_HDRS} ${LIBTINYGUI_PRIVATE_HDRS})
add_library(tinygui-static STATIC ${LIBTINYGUI_SRCS} ${LIBTINYGUI_THIRD_SRCS} ${LIBTINYGUI_PUBLIC_HDRS} ${LIBTINYGUI_PRIVATE_HDRS})
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
    install(FILES ${LIBTINYGUI_PUBLIC_ACC_SW_HDRS} DESTINATION "${INSTALL_INC_DIR}/tinygui/acc/sw")
    install(FILES ${LIBTINYGUI_PUBLIC_PROXY_HDRS} DESTINATION "${INSTALL_INC_DIR}/tinygui/proxy")
    install(FILES ${LIBTINYGUI_PUBLIC_HDRS} DESTINATION "${INSTALL_INC_DIR}/tinygui")
endif()
if(NOT SKIP_INSTALL_FILES AND NOT SKIP_INSTALL_ALL )
    install(FILES ${LIBTINYGUI_PC} DESTINATION "${INSTALL_PKGCONFIG_DIR}")
endif()
