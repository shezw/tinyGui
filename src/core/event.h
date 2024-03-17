//
// Created by 志伟佘 on 2024/3/9.
//

#include "../types.h"
#include "reaction.h"

#ifndef TINYGUI_EVENT_H
#define TINYGUI_EVENT_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum TinyGUI_EventType_e
{

    TinyGUI_EventNone = 0,

    /** Input Event **/
    TinyGUI_EventTouch_Begin,
    TinyGUI_EventTouch_Move,
    TinyGUI_EventTouch_End,
    TinyGUI_EventTouch_Tap,
    TinyGUI_EventTouch_DoubleTap,
    TinyGUI_EventTouch_LongPress,

    TinyGUI_EventMouse_Down,
    TinyGUI_EventMouse_Move,
    TinyGUI_EventMouse_Up,
    TinyGUI_EventMouse_Click,
    TinyGUI_EventMouse_DoubleClick,
    TinyGUI_EventMouse_LongPress,

    TinyGUI_EventScroll_Begin,
    TinyGUI_EventScrolling,
    TinyGUI_EventScroll_End,

    TinyGUI_EventKey,

    /** Input & Gesture **/
    TinyGUI_EventSwipe_Left,
    TinyGUI_EventSwipe_Right,
    TinyGUI_EventSwipe_Top,
    TinyGUI_EventSwipe_Bottom,

    /** Input & layout **/
    TinyGUI_Event_Enter,
    TinyGUI_Event_Leave,

    TinyGUI_Event_SizeChanged,
    TinyGUI_Event_StyleChanged,
    TinyGUI_Event_LayoutChanged,

    /** Animation **/
    TinyGUI_EventAnimation_BeforeStart,
    TinyGUI_EventAnimation_Start,
    TinyGUI_EventAnimation_Keeping,
    TinyGUI_EventAnimation_End,

    /** Gui life **/
    TinyGUI_EventInit,
    TinyGUI_EventLoop,
    TinyGUI_EventExit,

    TinyGUI_EventWake,
    TinyGUI_EventLazy,
    TinyGUI_EventBusy,
    TinyGUI_EventSleep,

    TinyGUI_EventMax

} TinyGUI_EventType;

typedef struct TinyGUI_Event_t
{
    TinyGUI_Reaction * fromTarget;
    TinyGUI_Reaction * target;
    TinyGUI_EventType eventType;

} TinyGUI_Event;



#ifdef __cplusplus
}
#endif

#endif //TINYGUI_EVENT_H
