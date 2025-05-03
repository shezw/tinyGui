/**
    -----------------------------------------------------------

 	Project
 	input.c    2025/3/9   
 	
 	@link    : https://github.com/shezw/tinygui
 	@author	 : shezw
 	@email	 : hello@shezw.com

    -----------------------------------------------------------
*/
#include <stdlib.h>
#include <stdio.h>
#include "display.h"
#include "input.h"

static TinyGUI_InputMgr * inputMgr = NULL;

static bool left_button_down = false;
static int16_t last_x = 0;
static int16_t last_y = 0;

void input_mouse_handler(SDL_Event * event)
{
    int screen_width = tinygui_get_porting_linux_fbdev_display()->viewSet->width;
    int screen_height = tinygui_get_porting_linux_fbdev_display()->viewSet->height;
    // todo
    printf("Mouse event: %d, %d\n", last_x, last_y);
}

static void linux_input_loop_run()
{
    // todo
}

void tinygui_porting_input_loop_run()
{
    linux_input_loop_run();
}

const TinyGUI_InputMgr * tinygui_get_porting_linux_fbdev_input()
{
    if(inputMgr == NULL)
    {
        fprintf(stderr, "Input manager is not initialized.\n");
        return NULL;
    }
    return inputMgr;
}

void tinygui_porting_linux_fbdev_input_init()
{

}

void tinygui_porting_linux_fbdev_input_deinit()
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
    inputMgr->init = tinygui_porting_linux_fbdev_input_init;
    inputMgr->deinit = tinygui_porting_linux_fbdev_input_deinit;
    return inputMgr;
}

void tinygui_porting_input_destruct( TinyGUI_InputMgr * inputMgr )
{
    tinygui_porting_linux_fbdev_input_deinit();
}