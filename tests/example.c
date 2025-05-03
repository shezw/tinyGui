//
// Created by mac on 2023/9/18.
//
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "../src/acc/sw/sw_acc.h"
#include "../src/utils/cobj.h"
#include "../src/tinygui.h"
#include "../src/core/screen.h"

#include "proxy/proxy.h"
#include "porting/display.h"
#include "porting/input.h"
#include "utils/cobj.h"

static pthread_t p_paint;

static U32 example_width = 800;
static U32 example_height = 400;
static TinyGUI_RotationType example_rotation = TinyGUI_Rotation_None;
static TinyGUI_FlipType example_flip = TinyGUI_Flip_None;
static U8 example_bpp = 4;

static TinyGUI_Config * config = NULL;

static unsigned char test_pixel[4] = {0x00, 0x00, 0x00, 0x00};

void * test_paint_screen(void * arg)
{
    TinyGUI_Screen * screen = config->proxy->display->screen;
    TinyGUI_Layer * gui_layer = screen->layers;

    U8* buffer = gui_layer->imp->buffer->vAddr;

    while (1)
    {
        test_pixel[0] += 2;
        test_pixel[1] += 4;
        test_pixel[2] += 8;
        test_pixel[3] += 16;

        usleep(1000 * 1000 / 10);

        for (int i = 0; i < screen->set->height; ++i) {
            for (int j = 0; j < screen->set->width; ++j) {
                buffer[i * screen->set->width * screen->set->bpp + j * screen->set->bpp] = test_pixel[0];
                buffer[i * screen->set->width * screen->set->bpp + j * screen->set->bpp + 1] = test_pixel[1];
                buffer[i * screen->set->width * screen->set->bpp + j * screen->set->bpp + 2] = test_pixel[2];
                buffer[i * screen->set->width * screen->set->bpp + j * screen->set->bpp + 3] = test_pixel[3];
            }
        }

//        tinygui_screen_paint(config->proxy->display->screen);
    }
}

void tinygui_test_mouse_move( TinyGUI_Reaction * reaction, TinyGUI_Event * event)
{
    TinyGUI_Screen * screen = config->proxy->display->screen;
    TinyGUI_Layer * gui_layer = screen->layers;

    if (event->eventType == TinyGUI_EventMouse_Move)
    {
        printf("Mouse move: int test call");
    }
}

void test_gui_init()
{
    if (config->viewSet == NULL)
        return;

    TinyGUI_Screen * screen = config->proxy->display->screen;

    tinygui_screen_add_layer(
            config->proxy->display->screen,
            config->viewSet,
            NULL,
            NULL);

    TinyGUI_Layer * gui_layer = screen->layers;

    tinygui_screen_add_event_listener(screen,TinyGUI_EventMouse_Move, tinygui_test_mouse_move);

    pthread_create(&p_paint, NULL, test_paint_screen, NULL);
}


int main()
{
    tinygui_version();

    _CSubObject( config, TinyGUI_Config);
    _CSubObject( config->viewSet, TinyGUI_ViewSet);
    config->viewSet->width = example_width;
    config->viewSet->height = example_height;
    config->viewSet->rotation = example_rotation;
    config->viewSet->flip = example_flip;
    config->viewSet->bpp = example_bpp;

    _CSubObject( config->proxy, TinyGUI_Proxy);

    config->proxy->accType = TinyGUI_AccType_None;
    config->proxy->useAcc = false;
    config->proxy->acc = tinygui_sw_acc_construct();
    config->proxy->display = tinygui_porting_display_construct( config->viewSet);
    config->proxy->input = tinygui_porting_input_construct( config->viewSet);

//    tinygui_screen_construct( config->proxy->display, false );

    tinygui_init( config );

//    tinygui_set_fps(10);
//    tinygui_set_input_fps(5);

    test_gui_init();

    tinygui_main();

    return 0;
}

