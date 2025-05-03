/**
    -----------------------------------------------------------

 	Project
 	input.c    2025/3/9   
 	
 	@link    : https://github.com/shezw/tinygui
 	@author	 : shezw
 	@email	 : hello@shezw.com

    -----------------------------------------------------------
*/
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include "display.h"
#include "input.h"

static TinyGUI_InputMgr * inputMgr = NULL;

static bool left_button_down = false;
static int16_t last_x = 0;
static int16_t last_y = 0;

void sdl_mouse_handler(SDL_Event * event)
{
    int screen_width = tinygui_get_porting_macos_sdl_display()->viewSet->width;
    int screen_height = tinygui_get_porting_macos_sdl_display()->viewSet->height;

    switch(event->type) {
        case SDL_MOUSEBUTTONUP:
            if(event->button.button == SDL_BUTTON_LEFT)
                left_button_down = false;
            break;
        case SDL_MOUSEBUTTONDOWN:
            if(event->button.button == SDL_BUTTON_LEFT) {
                left_button_down = true;
                last_x = event->motion.x;
                last_y = event->motion.y;
            }
            break;
        case SDL_MOUSEMOTION:
            last_x = event->motion.x;
            last_y = event->motion.y;
            break;

        case SDL_FINGERUP:
            left_button_down = false;
            last_x = screen_width * event->tfinger.x;
            last_y = screen_height * event->tfinger.y;
            break;
        case SDL_FINGERDOWN:
            left_button_down = true;
            last_x = screen_width * event->tfinger.x;
            last_y = screen_height * event->tfinger.y;
            break;
        case SDL_FINGERMOTION:
            last_x = screen_width * event->tfinger.x;
            last_y = screen_height * event->tfinger.y;
            break;
    }

    printf("Mouse event: %d, %d\n", last_x, last_y);
}

static void sdl_input_loop_run()
{
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        sdl_mouse_handler(&event);
    }
}

void tinygui_porting_input_loop_run()
{
    sdl_input_loop_run();
}

const TinyGUI_InputMgr * tinygui_get_porting_macos_sdl_input()
{
    if(inputMgr == NULL)
    {
        fprintf(stderr, "Input manager is not initialized.\n");
        return NULL;
    }
    return inputMgr;
}

void tinygui_porting_macos_sdl_input_init()
{

}

void tinygui_porting_macos_sdl_input_deinit()
{
    if(inputMgr)
    {
        free(inputMgr);
        inputMgr = NULL;
    }
}

TinyGUI_InputMgr * tinygui_porting_input_construct( TinyGUI_ViewSet * viewSet )
{
    inputMgr = (TinyGUI_InputMgr *) malloc(sizeof(TinyGUI_InputMgr));
    inputMgr->viewSet = viewSet;
    inputMgr->init = tinygui_porting_macos_sdl_input_init;
    inputMgr->deinit = tinygui_porting_macos_sdl_input_deinit;
    return inputMgr;
}

void tinygui_porting_input_destruct( TinyGUI_InputMgr * inputMgr )
{
    tinygui_porting_macos_sdl_input_deinit();
}