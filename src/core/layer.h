//
// Created by 志伟佘 on 2024/3/9.
//
#include "../types.h"
#include "reaction.h"

#ifndef TINYGUI_LAYER_H
#define TINYGUI_LAYER_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Layer is a linked list of all layers. the root is the screen obj.
 * the last is NULL.
 */

typedef struct TinyGUI_Screen_t TinyGUI_Screen;
typedef struct TinyGUI_Layer_t TinyGUI_Layer;

typedef struct TinyGUI_Layer_t
{
    TinyGUI_Reaction *  imp;
    TinyGUI_ViewSet  *  set;
    TinyGUI_ViewPos  *  pos;
    TinyGUI_ViewCut  *  cut;

    TinyGUI_Layer *    next;
} TinyGUI_Layer;

TinyGUI_Layer * tinygui_layer_construct( TinyGUI_Screen * screen, TinyGUI_ViewSet* set, TinyGUI_ViewPos* pos, TinyGUI_ViewCut* cut );

TinyGUI_Status tinygui_layer_add_event_listener
        ( TinyGUI_Layer * layer, TinyGUI_EventType eventType, TinyGUI_ReactionEventCall callback );

TinyGUI_Status tinygui_layer_remove_event_listener
        ( TinyGUI_Layer * layer, TinyGUI_EventType eventType, TinyGUI_ReactionEventCall callback );

#ifdef __cplusplus
}
#endif

#endif //TINYGUI_LAYER_H
