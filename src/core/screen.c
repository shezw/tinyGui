//
// Created by 志伟佘 on 2024/3/9.
//
#include "../utils/cobj.h"
#include "screen.h"

TinyGUI_Screen * tinyGUiConstruct( TinyGUI_ViewSet conf )
{
    cObject(screen,TinyGUI_Screen);
    cSubObject( screen->imp, TinyGUI_Reaction);
    stCopy(screen->set, conf);

//    TinyGUI_Screen * screen = (TinyGUI_Screen *) PROXY_ACC->malloc( conf.width * conf.height * conf.bpp );
//    screen->imp = PROXY_ACC->new_buffer( &conf );

    return screen;
}
