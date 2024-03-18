//
// Created by 志伟佘 on 2024/3/13.
//
#include "buffer.h"

#ifndef TINYGUI_REACTION_H
#define TINYGUI_REACTION_H

#include "event.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void   (*TinyGUI_ReactionEventCall) ( TinyGUI_Reaction * reaction, TinyGUI_Event * event );

typedef struct TinyGUI_ReactionLinkedCall_s TinyGUI_ReactionLinkedCall;
typedef struct TinyGUI_ReactionLinkedCall_s
{
    TinyGUI_EventType           event;
    TinyGUI_ReactionEventCall    call;
    TinyGUI_ReactionLinkedCall * next;
} TinyGUI_ReactionLinkedCall;

typedef struct TinyGUI_Reaction_t
{
    TinyGUI_Buffer * buffer;
    TinyGUI_ReactionLinkedCall * callbacks;
    U32 callCount;
} TinyGUI_Reaction;

TinyGUI_Status tinygui_reaction_add_event_listener
( TinyGUI_Reaction * reaction, TinyGUI_EventType eventType, TinyGUI_ReactionEventCall callback );

TinyGUI_Status tinygui_reaction_remove_event_listener
( TinyGUI_Reaction * reaction, TinyGUI_EventType eventType, TinyGUI_ReactionEventCall callback );

#ifdef __cplusplus
}
#endif


#endif //TINYGUI_REACTION_H
