//
// Created by 志伟佘 on 2024/3/27.
//

#ifndef TINYGUI_INPUT_H
#define TINYGUI_INPUT_H

#include "event.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum TinyGUI_InputType_e
{
    TinyGUI_InputType_None = 0,

    TinyGUI_InputType_Keyboard,
    TinyGUI_InputType_TouchScreen,
    TinyGUI_InputType_TouchPen,
    TinyGUI_InputType_Mouse,

    TinyGUI_InputType_Max
} TinyGUI_InputType;

typedef void (*TinyGUI_InputEventSet) ( TinyGUI_Event event );
//typedef

#ifdef __cplusplus
}
#endif

#endif //TINYGUI_INPUT_H
