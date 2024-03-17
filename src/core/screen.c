//
// Created by 志伟佘 on 2024/3/9.
//
#include "../utils/cobj.h"
#include "screen.h"

TinyGUI_Screen * tinyGUiConstruct( TinyGUI_ViewSet conf )
{
    _CObject(screen,TinyGUI_Screen);
    _CSubObject( screen->imp, TinyGUI_Reaction);
    _StCopy(screen->set, conf);

//    TinyGUI_Screen * screen = (TinyGUI_Screen *) PROXY_ACC->malloc( conf.width * conf.height * conf.bpp );
//    screen->imp = PROXY_ACC->new_buffer( &conf );

    return screen;
}
