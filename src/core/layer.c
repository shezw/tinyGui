//
// Created by 志伟佘 on 2024/3/9.
//
#include "../utils/cobj.h"
#include "layer.h"

TinyGUI_Layer * tinygui_layer_construct
( TinyGUI_ViewSet set, TinyGUI_ViewPos pos, TinyGUI_ViewCut cut )
{
    _CObject( layer, TinyGUI_Layer );
    _StCopy( layer->set, set );
    _StCopy( layer->pos, pos );
    _StCopy( layer->cut, cut );

    return layer;
}
