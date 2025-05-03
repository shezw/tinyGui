include_directories(
        ${PORTING_DIR}/linux
        ${PORTING_DIR}/linux/fbdev
)
set(PORTING_LINUX ON)
set(PORTING_LINUX_FBDEV ON)

add_compile_definitions(PORTING_LINUX=1)

include_directories(${LIBTINYGUI_PORTING_INCLUDE_DIRS})

set(LIBTINYGUI_PORTING_SRCS ${LIBTINYGUI_PORTING_SRCS}
        ${PORTING_DIR}/linux/fbdev/loop.c
        ${PORTING_DIR}/linux/fbdev/input.c
        ${PORTING_DIR}/linux/fbdev/display.c
        )
