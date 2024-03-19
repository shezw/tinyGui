//
// Created by 志伟佘 on 2024/3/9.
//
#include "../utils/cobj.h"
#include "screen.h"

TinyGUI_Screen * tinygui_screen_construct( TinyGUI_ViewSet conf )
{
    _CObject(screen,TinyGUI_Screen);
    _CSubObject( screen->imp, TinyGUI_Reaction);
    _StCopy(screen->set, conf);

//    screen->imp->eventCall = tinyGUIScreen_ReactionEventCall;

    return screen;
}

TinyGUI_Status   tinygui_screen_add_layer
( TinyGUI_Screen * screen, TinyGUI_ViewSet set, TinyGUI_ViewPos pos, TinyGUI_ViewCut cut )
{
    TinyGUI_Layer * layer = tinygui_layer_construct( set, pos, cut );
    if (!screen->layers)
        screen->layers = layer;
    else
        screen->layers->next = layer;

    screen->lastLayer = layer;
    return TinyGUI_OK;
}
