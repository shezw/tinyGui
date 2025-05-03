/**
    -----------------------------------------------------------

 	Project
 	porting.c    2025/5/2   
 	
 	@link    : https://github.com/shezw/tinygui
 	@author	 : shezw
 	@email	 : hello@shezw.com

    -----------------------------------------------------------
*/

#include <SDL2/SDL.h>
#include "core/loop.h"
#include "loop.h"
#include "input.h"
#include "display.h"

static TinyGUI_LoopCall sdl_loopCall = NULL;

static bool  sdl_quit_qry = false;

void sdl_window_update(sdl_context * ctx);

static void sdl_clean_up(void)
{
    sdl_context * sdl_ctx = (sdl_context*) tinygui_get_porting_macos_sdl_display()->handler;

    if (sdl_ctx==NULL) return;

    SDL_DestroyTexture(sdl_ctx->texture);
    SDL_DestroyRenderer(sdl_ctx->renderer);
    SDL_DestroyWindow(sdl_ctx->window);

    SDL_Quit();
}



static void sdl_event_handler(TinyGUI_LoopUnit * t)
{
    (void)t;

    /*Refresh handling*/
    SDL_Event event;
//    printf("sdl_event_handler\n");
    while(SDL_PollEvent(&event)) {

        sdl_mouse_handler(&event);

//        mousewheel_handler(&event);
//        keyboard_handler(&event);

        if((&event)->type == SDL_QUIT) {
            sdl_quit_qry = true;
        }

        if((&event)->type == SDL_WINDOWEVENT) {
            switch((&event)->window.event) {
#if SDL_VERSION_ATLEAST(2, 0, 5)
                case SDL_WINDOWEVENT_TAKE_FOCUS:
#endif
                case SDL_WINDOWEVENT_EXPOSED:
                    sdl_window_update( (sdl_context*)(tinygui_get_porting_macos_sdl_display()->handler));
                    break;
                default:
                    break;
            }
        }
    }

    /*Run until quit event not arrives*/
    if(sdl_quit_qry) {
        sdl_clean_up();
        exit(0);
    }
}


void tinygui_porting_main_loop_init()
{
//    sdl_loopCall = call;
}


void tinygui_main_loop_porting( TinyGUI_TimeStamp now )
{
    sdl_event_handler(NULL); // Call the event handler

    sdl_window_update( (sdl_context*)(tinygui_get_porting_macos_sdl_display()->handler));

}
