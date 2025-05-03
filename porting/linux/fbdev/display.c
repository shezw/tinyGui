/**
    -----------------------------------------------------------

 	Project
 	display.c    2025/5/5
 	
 	@link    : https://github.com/shezw/tinygui
 	@author	 : shezw
 	@email	 : hello@shezw.com

    -----------------------------------------------------------
*/
#include <stdlib.h>
#include <string.h>

#include "screen.h"

#include "tinygui.h"
#include "display.h"
#include "loop.h"

#include "sw/sw_mem.h"
#include "proxy/memory.h"
#include "utils/cobj.h"

static TinyGUI_DisplayMgr * displayMgr = NULL;
static TinyGUI_Screen * screen = NULL;

void tinygui_porting_linux_fbdev_display_init()
{

}

void fbdev_window_update()
{
    TinyGUI_ViewSet * viewSet = displayMgr->viewSet;

}

static void tinygui_porting_linux_fbdev_display_deinit()
{
    if(displayMgr)
    {
        free(displayMgr);
        displayMgr = NULL;
    }
}

const TinyGUI_DisplayMgr * tinygui_get_porting_linux_fbdev_display()
{
    if(displayMgr == NULL)
    {
        fprintf(stderr, "Display manager is not initialized.\n");
        return NULL;
    }
    return displayMgr;

}

static TinyGUI_DisplayMgr *  tinygui_porting_linux_fbdev_display_construct( TinyGUI_ViewSet * viewSet)
{
    displayMgr = (TinyGUI_DisplayMgr *)malloc(sizeof(TinyGUI_DisplayMgr));
    displayMgr->viewSet = viewSet;

    displayMgr->buffer = tinygui_sw_acc_new_buffer( viewSet );

    displayMgr->init = tinygui_porting_linux_fbdev_display_init;
    displayMgr->deinit = tinygui_porting_linux_fbdev_display_deinit;

    return displayMgr;
}

static void tinygui_porting_linux_fbdev_display_destruct( TinyGUI_DisplayMgr * displayMgr )
{
    free(displayMgr);
}

TinyGUI_DisplayMgr * tinygui_porting_display_construct( TinyGUI_ViewSet * viewSet)
{
    return tinygui_porting_linux_fbdev_display_construct(viewSet);
}

void tinygui_porting_display_destruct( TinyGUI_DisplayMgr * displayMgr )
{
    tinygui_porting_linux_fbdev_display_destruct(displayMgr);
}