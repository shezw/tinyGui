#include <stdio.h>
#include <stdlib.h>
#include "tinygui.h"

static TinyGUI * singletonTinyGUI;
static bool      singletonInited;

const TinyGUI * tinygui()
{
    return singletonInited ? singletonTinyGUI : NULL;
}

void tinygui_version()
{
    printf( TINYGUI_VERSION );
}

TinyGUI_Status tinygui_init( TinyGUI_Config * conf )
{
    singletonTinyGUI = malloc( sizeof(TinyGUI) );
    singletonTinyGUI->conf = conf;

    return TinyGUI_OK;
}

TinyGUI_Status tinygui_deinit()
{
    free(singletonTinyGUI);
    return TinyGUI_OK;
}

TinyGUI_Status tinygui_run( U32 ms )
{


    return TinyGUI_OK;
}