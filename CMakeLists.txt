cmake_minimum_required(VERSION 2.4.4)
set(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS ON)

project(tinyGui C)

set(VERSION "0.0.1")

set(INSTALL_BIN_DIR "${CMAKE_INSTALL_PREFIX}/bin" CACHE PATH "Installation directory for executables")
set(INSTALL_LIB_DIR "${CMAKE_INSTALL_PREFIX}/lib" CACHE PATH "Installation directory for libraries")
set(INSTALL_INC_DIR "${CMAKE_INSTALL_PREFIX}/include" CACHE PATH "Installation directory for headers")
set(INSTALL_MAN_DIR "${CMAKE_INSTALL_PREFIX}/share/man" CACHE PATH "Installation directory for manual pages")
set(INSTALL_PKGCONFIG_DIR "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" CACHE PATH "Installation directory for pkgconfig (.pc) files")

if(NOT CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_CURRENT_BINARY_DIR)
    # If we're doing an out of source build and the user has a tinyguiconf.h
    # in their source tree...
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/tinyguiconf.h)
        message(STATUS "Renaming")
        message(STATUS "    ${CMAKE_CURRENT_SOURCE_DIR}/tinyguiconf.h")
        message(STATUS "to 'tinyguiconf.h.included' because this file is included with tinygui")
        message(STATUS "but CMake generates it automatically in the build directory.")
        file(RENAME ${CMAKE_CURRENT_SOURCE_DIR}/tinyguiconf.h ${CMAKE_CURRENT_SOURCE_DIR}/tinyguiconf.h.included)
  endif()
endif()

option(USE_64 "Build for 64 sys" ON)

if ( USE_64 )
    option(TINYGUI_SYS_64 "Build for 64 sys" ON)
else()
    option(TINYGUI_SYS_32 "Build for 32 sys" ON)
endif ()

if (CMAKE_CROSSCOMPILING)
    message("Cross Compiling!")
endif ()

set(LIBTINYGUI_PC ${CMAKE_CURRENT_BINARY_DIR}/tinygui.pc)
configure_file( ${CMAKE_CURRENT_SOURCE_DIR}/tinygui.pc.in
		${LIBTINYGUI_PC} @ONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/tinyguiconf.h.in
		${CMAKE_CURRENT_BINARY_DIR}/tinyguiconf.h @ONLY)
include_directories(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_SOURCE_DIR})

include(src/CMakeLists.txt)

include(tests/CMakeLists.txt)
