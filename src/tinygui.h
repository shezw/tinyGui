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

#define TINYGUI_MAX_FPS         200
#define TINYGUI_MAX_INPUT_FPS   500

typedef struct TinyGUI_Config_t
{
    TinyGUI_ViewSet viewSet;
    TinyGUI_Proxy * proxy;

} TinyGUI_Config;

typedef struct TinyGUI_t {

    TinyGUI_Config * conf;

} TinyGUI;

void tinygui_version();

void tinygui_main();

const TinyGUI * tinygui();

TinyGUI_Status tinygui_init( TinyGUI_Config * conf );
TinyGUI_Status tinygui_deinit();

TinyGUI_Status tinygui_run( U32 ms );

void tinygui_set_fps( TinyGUI_TimeStamp fps );
void tinygui_set_input_fps( TinyGUI_TimeStamp fps );

TinyGUI_TimeStamp tinygui_get_fps();
TinyGUI_TimeStamp tinygui_get_input_fps();

TinyGUI_TimeStamp tinygui_get_period();
TinyGUI_TimeStamp tinygui_get_input_period();

void tinygui_main_mutex_init();
void tinygui_main_lock();
void tinygui_main_unlock();
void tinygui_main_mutex_destroy();

#define PROXY_ACC  tinygui()->conf->proxy->acc
#define PROXY      tinygui()->conf->proxy

#ifdef __cplusplus
}
#endif

#endif //TINYGUI_TINYGUI_H
