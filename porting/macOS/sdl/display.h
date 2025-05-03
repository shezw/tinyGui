/**
    -----------------------------------------------------------

 	Project
 	sdl.h    2025/3/5   
 	
 	@link    : https://github.com/shezw/tinygui
 	@author	 : shezw
 	@email	 : hello@shezw.com

    -----------------------------------------------------------
*/

#ifndef TINYGUI_PORTING_MAC_SDL_DISPLAY_H
#define TINYGUI_PORTING_MAC_SDL_DISPLAY_H

#include <SDL2/SDL.h>
#include "proxy.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct sdl_context_t{
    SDL_Window * window;
    SDL_Renderer * renderer;
    SDL_Texture * texture;
    volatile bool sdl_refr_qry;
    uint32_t * screen_fb;
} sdl_context;

const TinyGUI_DisplayMgr * tinygui_get_porting_macos_sdl_display();

void tinygui_porting_macos_sdl_display_init();

void sdl_window_update(sdl_context * ctx);


#ifdef __cplusplus
}
#endif


#endif //TINYGUI_PORTING_MAC_SDL_DISPLAY_H
