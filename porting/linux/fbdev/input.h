/**
    -----------------------------------------------------------

 	Project
 	input.h    2025/3/9   
 	
 	@link    : https://github.com/shezw/tinygui
 	@author	 : shezw
 	@email	 : hello@shezw.com

    -----------------------------------------------------------
*/

#ifndef TINYGUI_PORTING_MACOS_SDL_INPUT_H
#define TINYGUI_PORTING_MACOS_SDL_INPUT_H

#include "proxy.h"
#include "loop.h"

#ifdef __cplusplus
extern "C" {
#endif

void tinygui_porting_linux_input_init();
void tinygui_porting_linux_input_deinit();

//void sdl_mouse_handler(SDL_Event * event);

#ifdef __cplusplus
}
#endif

#endif //TINYGUI_PORTING_MACOS_SDL_INPUT_H
