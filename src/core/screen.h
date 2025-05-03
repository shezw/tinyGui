//
// Created by 志伟佘 on 2024/3/9.
//
#include "../types.h"
#include "../tinygui.h"
#include "reaction.h"
#include "layer.h"

#ifndef TINYGUI_SCREEN_H
#define TINYGUI_SCREEN_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct TinyGUI_DisplayMgr_t TinyGUI_DisplayMgr;

typedef struct TinyGUI_Screen_t
{
    TinyGUI_DisplayMgr * display;
    TinyGUI_ViewSet  *  set;
    TinyGUI_Reaction *  imp;
    bool                sleep;
    bool                directMode;
    TinyGUI_Layer   *   layers;
    TinyGUI_Layer   *   lastLayer;

} TinyGUI_Screen;

TinyGUI_Screen * tinygui_screen_construct( TinyGUI_DisplayMgr * display, bool directMode );

TinyGUI_Status   tinygui_screen_add_layer
( TinyGUI_Screen * screen, TinyGUI_ViewSet* set, TinyGUI_ViewPos* pos, TinyGUI_ViewCut* cut );

TinyGUI_Status tinygui_screen_add_event_listener
        ( TinyGUI_Screen * screen, TinyGUI_EventType eventType, TinyGUI_ReactionEventCall callback );

TinyGUI_Status tinygui_screen_remove_event_listener
        ( TinyGUI_Screen * screen, TinyGUI_EventType eventType, TinyGUI_ReactionEventCall callback );

#ifdef __cplusplus
}
#endif

#endif //TINYGUI_SCREEN_H
