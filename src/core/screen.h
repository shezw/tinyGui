//
// Created by 志伟佘 on 2024/3/9.
//
#include "../types.h"
#include "../tinygui.h"
#include "reaction.h"

#ifndef TINYGUI_SCREEN_H
#define TINYGUI_SCREEN_H

#ifdef __cplusplus
extern "C" {
#endif



typedef struct TinyGUI_Screen_t
{
    TinyGUI_ViewSet  set;
    TinyGUI_Reaction * imp;
} TinyGUI_Screen;

TinyGUI_Screen * tinyGUiConstruct( TinyGUI_ViewSet conf );



#ifdef __cplusplus
}
#endif

#endif //TINYGUI_SCREEN_H
