//
// Created by 志伟佘 on 2024/3/10.
//

#include "tinyguiconf.h"
#include "types.h"
#include "proxy/proxy.h"

#ifndef TINYGUI_TINYGUI_H
#define TINYGUI_TINYGUI_H

typedef struct TinyGUI_Config_t
{
    TguiU32         screen_w;
    TguiU32         screen_h;

    TinyGUI_Proxy * proxy;

} TinyGUI_Config;

typedef struct TinyGUI_t {

    TinyGUI_Config * conf;

} TinyGUI;

void tinygui_version();

TGUIStatus tinygui_init( TinyGUI_Config * conf );
TGUIStatus tinygui_deinit();

#endif //TINYGUI_TINYGUI_H
