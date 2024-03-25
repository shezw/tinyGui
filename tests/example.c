//
// Created by mac on 2023/9/18.
//
#include <stdlib.h>
#include "../src/acc/sw/sw_acc.h"
#include "../src/utils/cobj.h"
#include "../src/tinygui.h"
#include "../src/core/screen.h"

static TinyGUI_Config config = {
    800,
    400,
    TinyGUI_Rotation_None,
    TinyGUI_Flip_None,
    8,
    NULL
};

int main()
{
    tinygui_version();

    _CSubObject( config.proxy, TinyGUI_Proxy);

    config.proxy->accType = TinyGUI_AccType_None;
    config.proxy->useAcc = false;
    config.proxy->acc = tinygui_sw_acc_construct();

    tinygui_init( &config );

    tinygui_screen_construct( config.viewSet, false );

    tinygui_set_fps(1);
    tinygui_set_input_fps(5);

    tinygui_main();

    return 0;
}

