#
# Valid Porting
# Linux(fbdev) MacOS(sdl)
#
#

if (NOT PORTING)
    message(FATAL_ERROR "You must set PORTING in MacOS, Linux")
endif()

# set porting to upper case
string(TOUPPER ${PORTING} PORTING)
set(PORTING_DIR ${PROJ_DIR}/porting)
set(LIBTINYGUI_PORTING_SRCS "")
set(LIBTINYGUI_PORTING_INCS "")
set(LIBTINYGUI_PORTING_LIBS "")
set(LIBTINYGUI_PORTING_LIBS_DIRS "")

if (PORTING STREQUAL "MACOS")
    message(WARNING "Porting to MacOS")
    include(${PORTING_DIR}/macOS/porting.cmake)
elseif(PORTING STREQUAL "LINUX")
    message(WARNING "Porting to Linux")
    include(${PORTING_DIR}/linux/porting.cmake)
endif()

include_directories(${LIBTINYGUI_PORTING_INCS})