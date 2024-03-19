//
// Created by 志伟佘 on 2024/3/13.
//

#include "reaction.h"
#include "../utils/cobj.h"

TinyGUI_Status tinygui_reaction_add_event_listener
        ( TinyGUI_Reaction * reaction, TinyGUI_EventType eventType, TinyGUI_ReactionEventCall callback )
{
    _CObject(caller,TinyGUI_ReactionLinkedCall);
    caller->event = eventType;
    caller->call  = callback;

    if (!reaction->callCount)
        reaction->callbacks = caller;
    else
        reaction->callbacks->next = caller;

    reaction->callCount ++;

    return TinyGUI_OK;
}


TinyGUI_Status tinygui_reaction_remove_event_listener
        ( TinyGUI_Reaction * reaction, TinyGUI_EventType eventType, TinyGUI_ReactionEventCall callback )
{
    TinyGUI_ReactionLinkedCall * caller = reaction->callbacks;
    TinyGUI_ReactionLinkedCall * last   = NULL;

    while (caller)
    {
        if (caller->event==eventType && caller->call==callback)
        {
            if (last)
                last->next = caller->next;
            else
                reaction->callbacks = caller->next;

            reaction->callCount--;
            if (reaction->callCount==0)
                reaction->callbacks = NULL;

            free(caller);
            break;
        }
        last = caller;
        caller = caller->next;
    }
    return TinyGUI_OK;
}
