//
// Created by 志伟佘 on 2024/3/9.
//
#include "../types.h"
#include "object.h"

#ifndef TINYGUI_SCREEN_H
#define TINYGUI_SCREEN_H

typedef struct TinyGUI_Screen_t
{
    TinyGUI_ViewSet  set;
    TinyGUI_Object * imp;
} TinyGUI_Screen;

TinyGUI_Screen * tinyGUiConstruct();

#endif //TINYGUI_SCREEN_H
