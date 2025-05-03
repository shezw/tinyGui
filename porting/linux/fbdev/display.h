/**
    -----------------------------------------------------------

 	Project
 	sdl.h    2025/3/5   
 	
 	@link    : https://github.com/shezw/tinygui
 	@author	 : shezw
 	@email	 : hello@shezw.com

    -----------------------------------------------------------
*/

#ifndef TINYGUI_PORTING_LINUX_FBDEV_DISPLAY_H
#define TINYGUI_PORTING_LINUX_FBDEV_DISPLAY_H

#ifdef __cplusplus
extern "C" {
#endif

const TinyGUI_DisplayMgr * tinygui_get_porting_linux_fbdev_display();

void tinygui_porting_linux_fbdev_display_init();

//void sdl_window_update(sdl_context * ctx);


#ifdef __cplusplus
}
#endif


#endif //TINYGUI_PORTING_LINUX_FBDEV_DISPLAY_H
