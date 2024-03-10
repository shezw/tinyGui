#include <stdio.h>
#include <stdlib.h>
#include "tinygui.h"

static TinyGUI * singletonTinyGUI;

void tinygui_version()
{
    printf( TINYGUI_VERSION );
}

TGUIStatus tinygui_init( TinyGUI_Config * conf )
{
    singletonTinyGUI = malloc( sizeof(TinyGUI) );
    singletonTinyGUI->conf = conf;

    return TGUI_OK;
}

TGUIStatus tinygui_deinit()
{
    free(singletonTinyGUI);
    return TGUI_OK;
}
