/**
    -----------------------------------------------------------

 	Project
 	input.h    2025/3/9   
 	
 	@link    : https://github.com/shezw/tinygui
 	@author	 : shezw
 	@email	 : hello@shezw.com

    -----------------------------------------------------------
*/

#ifndef TINYGUI_PORTING_INPUT_H
#define TINYGUI_PORTING_INPUT_H

#include "proxy.h"

#ifdef __cplusplus
extern "C" {
#endif

extern TinyGUI_InputMgr * tinygui_porting_input_construct( TinyGUI_ViewSet * viewSet );
extern void tinygui_porting_input_destruct( TinyGUI_InputMgr * inputMgr );

#ifdef __cplusplus
}
#endif

#if PORTING_MACOS
#include "macOS/sdl/input.h"
#endif

#endif //TINYGUI_PORTING_INPUT_H
