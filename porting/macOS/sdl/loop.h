/**
    -----------------------------------------------------------

 	Project
 	porting.h    2025/5/2   
 	
 	@link    : https://github.com/shezw/tinygui
 	@author	 : shezw
 	@email	 : hello@shezw.com

    -----------------------------------------------------------
*/

#ifndef TINYGUI_PORTING_MACOS_SDL_LOOP_H
#define TINYGUI_PORTING_MACOS_SDL_LOOP_H

#include "proxy.h"

#ifdef __cplusplus
extern "C" {
#endif

void tinygui_main_loop_porting( TinyGUI_TimeStamp now );

#ifdef __cplusplus
}
#endif


#endif //TINYGUI_PORTING_MACOS_SDL_LOOP_H
