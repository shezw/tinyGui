# find SDL2 in /opt/homebrew not in the default path

if (APPLE)

    set(CMAKE_PREFIX_PATH /opt/homebrew)
    set(CMAKE_INCLUDE_PATH /opt/homebrew/include)
    set(CMAKE_LIBRARY_PATH /opt/homebrew/lib)

    find_path(LIB_SDL2_INCLUDE_DIR
        NAMES SDL2/SDL.h
        PATHS ${CMAKE_INCLUDE_PATH}
        NO_CACHE
        NO_DEFAULT_PATH
    )
    find_path(LIB_SDL2_LIBRARY_DIR
        NAMES libSDL2.dylib
        PATHS ${CMAKE_LIBRARY_PATH}
        NO_CACHE
        NO_DEFAULT_PATH
    )
    find_library(LIB_SDL2_LIBRARY
        NAMES SDL2
        PATHS ${CMAKE_LIBRARY_PATH}
        NO_CACHE
        NO_DEFAULT_PATH
    )
else()

    find_package(SDL2 REQUIRED)

    if(SDL2_INCLUDE_DIRS)
        set(LIB_SDL2_INCLUDE_DIR ${SDL2_INCLUDE_DIRS})
    else()
        set(LIB_SDL2_INCLUDE_DIR ${SDL2_INCLUDE_DIR})
    endif()

endif(APPLE)

# set the lib dir of sdl2


SET(CMAKE_INCLUDE_DIRECTORIES_BEFORE ON) #
message(STATUS "LIB_SDL2_INCLUDE_DIR: ${LIB_SDL2_INCLUDE_DIR}")
message(STATUS "LIB_SDL2_LIBRARY: ${LIB_SDL2_LIBRARY}")

if(LIB_SDL2_INCLUDE_DIR AND LIB_SDL2_LIBRARY)
    message(STATUS "Found SDL2: ${LIB_SDL2_INCLUDE_DIR} ${LIB_SDL2_LIBRARY}")
else()
    message(FATAL_ERROR "SDL2 not found")
endif()