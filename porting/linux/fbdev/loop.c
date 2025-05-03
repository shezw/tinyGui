/**
    -----------------------------------------------------------

 	Project
 	porting.c    2025/5/2   
 	
 	@link    : https://github.com/shezw/tinygui
 	@author	 : shezw
 	@email	 : hello@shezw.com

    -----------------------------------------------------------
*/

#include "core/loop.h"
#include "loop.h"
#include "input.h"
#include "display.h"

static TinyGUI_LoopCall fbdev_loopCall = NULL;

static bool  fbdev_quit_qry = false;

void fbdev_window_update(fbdev_context * ctx);

static void fbdev_clean_up(void)
{
    fbdev_context * fbdev_ctx = (fbdev_context*) tinygui_get_porting_linux_fbdev_display()->handler;

}



static void fbdev_event_handler(TinyGUI_LoopUnit * t)
{
    (void)t;

}


void tinygui_porting_main_loop_init()
{
//    fbdev_loopCall = call;
}


void tinygui_main_loop_porting( TinyGUI_TimeStamp now )
{
    fbdev_event_handler(NULL); // Call the event handler

    fbdev_window_update( (fbdev_context*)(tinygui_get_porting_linux_fbdev_display()->handler));

}
