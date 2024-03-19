//
// Created by 志伟佘 on 2024/3/10.
//

#include "tinyguiconf.h"
#include "types.h"
#include "proxy/proxy.h"

#ifndef TINYGUI_TINYGUI_H
#define TINYGUI_TINYGUI_H

#ifdef __cplusplus
extern "C" {
#endif



typedef struct TinyGUI_Config_t
{
    TinyGUI_ViewSet viewSet;
    TinyGUI_Proxy * proxy;

} TinyGUI_Config;

typedef struct TinyGUI_t {

    TinyGUI_Config * conf;

} TinyGUI;

void tinygui_version();

const TinyGUI * tinygui();

TinyGUI_Status tinygui_init( TinyGUI_Config * conf );
TinyGUI_Status tinygui_deinit();

TinyGUI_Status tinygui_run( U32 ms );

#define PROXY_ACC  tinygui()->conf->proxy->acc
#define PROXY      tinygui()->conf->proxy

#ifdef __cplusplus
}
#endif

#endif //TINYGUI_TINYGUI_H
