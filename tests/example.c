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

    tinygui_screen_construct( config );

    _CSubObject( config.proxy, TinyGUI_Proxy);

    tinygui_sw_acc_construct( config.proxy->acc );

    tinygui_init( &config );

    tinygui_run( 5 );

    return 0;
}

