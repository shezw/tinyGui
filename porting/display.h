/**
    -----------------------------------------------------------

 	Project
 	display.h    2025/3/9   
 	
 	@link    : https://github.com/shezw/tinygui
 	@author	 : shezw
 	@email	 : hello@shezw.com

    -----------------------------------------------------------
*/

#ifndef TINYGUI_PORTING_DISPLAY_H
#define TINYGUI_PORTING_DISPLAY_H

#include "proxy.h"

#ifdef __cplusplus
extern "C" {
#endif

extern TinyGUI_DisplayMgr * tinygui_porting_display_construct( TinyGUI_ViewSet * viewSet);
extern void tinygui_porting_display_destruct( TinyGUI_DisplayMgr * displayMgr );

#ifdef __cplusplus
}
#endif

#if PORTING_MACOS
#include "macOS/sdl/display.h"
#endif


#endif //TINYGUI_PORTING_DISPLAY_H
