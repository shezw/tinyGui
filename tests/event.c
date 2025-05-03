//
// Created by 志伟佘 on 2024/3/26.
//

#include <stdlib.h>
#include "../src/acc/sw/sw_acc.h"
#include "../src/utils/cobj.h"
#include "../src/tinygui.h"
#include "../src/core/screen.h"

static U32 example_width = 800;
static U32 example_height = 400;
static TinyGUI_RotationType example_rotation = TinyGUI_Rotation_None;
static TinyGUI_FlipType example_flip = TinyGUI_Flip_None;
static U8 example_bpp = 8;
static TinyGUI_Proxy * example_proxy = NULL;

static TinyGUI_ViewSet * example_viewSet = NULL;

static TinyGUI_Config * config = NULL;

int main()
{
    tinygui_version();

    _CObject( config, TinyGUI_Config);
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
//    config->proxy->display = tinygui_porting_display_construct( config->viewSet);
//    config->proxy->input = tinygui_porting_input_construct( config->viewSet);

    tinygui_init( config );

//    tinygui_screen_construct( config->viewSet, false );

    tinygui_set_fps(1);
    tinygui_set_input_fps(5);

    tinygui_main();

    return 0;
}
