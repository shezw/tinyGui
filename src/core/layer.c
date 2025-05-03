//
// Created by 志伟佘 on 2024/3/9.
//
#include "../utils/cobj.h"
#include "screen.h"
#include "layer.h"

TinyGUI_Layer * tinygui_layer_construct
( TinyGUI_Screen * screen, TinyGUI_ViewSet * set, TinyGUI_ViewPos * pos, TinyGUI_ViewCut * cut )
{
    _CObject( layer, TinyGUI_Layer );
    _CSubObject( layer->imp, TinyGUI_Reaction );
    _CSubObject( layer->set, TinyGUI_ViewSet );
    _CSubObject( layer->pos, TinyGUI_ViewPos );
    _CSubObject( layer->cut, TinyGUI_ViewCut );

    _PtrCopy( layer->set, set, TinyGUI_ViewSet );

    if(pos)
    _PtrCopy( layer->pos, pos, TinyGUI_ViewPos );

    if(cut)
    _PtrCopy( layer->cut, cut, TinyGUI_ViewCut );

    layer->imp->buffer = screen->imp->buffer;
    return layer;
}

TinyGUI_Status tinygui_layer_add_event_listener
        ( TinyGUI_Layer * layer, TinyGUI_EventType eventType, TinyGUI_ReactionEventCall callback )
{
    return tinygui_reaction_add_event_listener(layer->imp,eventType,callback);
}

TinyGUI_Status tinygui_layer_remove_event_listener
        ( TinyGUI_Layer * layer, TinyGUI_EventType eventType, TinyGUI_ReactionEventCall callback )
{
    return tinygui_reaction_remove_event_listener(layer->imp,eventType,callback);
}
