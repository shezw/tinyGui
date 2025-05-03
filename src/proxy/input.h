/**
    -----------------------------------------------------------

 	Project
 	input.h    2025/3/9   
 	
 	@link    : https://github.com/shezw/tinygui
 	@author	 : shezw
 	@email	 : hello@shezw.com

    -----------------------------------------------------------
*/

#ifndef TINYGUI_PROXY_INPUT_H
#define TINYGUI_PROXY_INPUT_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif



typedef struct TinyGUI_InputMgr_t {
    TinyGUI_ViewSet * viewSet;
    void (*init)(void);
    void (*deinit)(void);
    void (*update)(void);

    void (*onTouchDown)(int x, int y);
    void (*onTouchUp)(int x, int y);
    void (*onTouchMove)(int x, int y);
    void (*onTouchCancel)(void);

    void * handler;
} TinyGUI_InputMgr;

extern void tinygui_porting_input_loop_run();

#ifdef __cplusplus
}
#endif

#endif //TINYGUI_PROXY_INPUT_H
