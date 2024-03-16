//
// Created by mac on 2023/9/18.
//
#include <stdlib.h>
#include "../src/acc/sw/sw_acc.h"
#include "../src/tinygui.h"

static TinyGUI_Config config = {
    800,
    400,
    NULL
};

int main()
{
    tinygui_version();

    TinyGUI_Proxy * proxy = malloc( sizeof(TinyGUI_Proxy) );

    sw_acc_init( proxy->acc );

    config.proxy = proxy;

    tinygui_init( &config );

    tinygui_run( 5 );

    return 0;
}

