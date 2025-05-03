/**
    -----------------------------------------------------------

 	Project
 	display.h    2025/3/9   
 	
 	@link    : https://github.com/shezw/tinygui
 	@author	 : shezw
 	@email	 : hello@shezw.com

    -----------------------------------------------------------
*/

#ifndef TINYGUI_PROXY_DISPLAY_H
#define TINYGUI_PROXY_DISPLAY_H

#include "types.h"
#include "buffer.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct TinyGUI_Screen_t TinyGUI_Screen;

typedef struct TinyGUI_DisplayMgr_t
{
    TinyGUI_ViewSet * viewSet;
    TinyGUI_Buffer * buffer;
    TinyGUI_Screen * screen;
    void (*init)(void);
    void (*deinit)(void);

    void * handler;
} TinyGUI_DisplayMgr;

#ifdef __cplusplus
}
#endif

#endif //TINYGUI_PROXY_DISPLAY_H
