//
// Created by 志伟佘 on 2024/3/10.
//

#ifndef TINYGUI_LOOP_H
#define TINYGUI_LOOP_H

#include "event.h"
#include "../types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct TinyGUI_LoopUnit_s TinyGUI_LoopUnit;

typedef void (*TinyGUI_LoopCall) ( TinyGUI_LoopUnit * unit );

typedef struct TinyGUI_LoopUnit_s
{
    I32                 repeat;
    bool                paused;
    TinyGUI_TimeStamp   lastTime;
    TinyGUI_TimeStamp   period;
    TinyGUI_LoopCall    call;
} TinyGUI_LoopUnit;

void tinygui_main_loop_construct();
void tinygui_main_loop_init();
void tinygui_main_loop_deinit();

void tinygui_side_loop_construct();
void tinygui_side_loop_init();
void tinygui_side_loop_deinit();

TinyGUI_LoopUnit * tinygui_main_loop_add( TinyGUI_LoopCall call, TinyGUI_TimeStamp period, I32 repeats );
void tinygui_main_loop_del( TinyGUI_LoopUnit unit );

void tinygui_loop_send_event( TinyGUI_Event * event );
void tinygui_loop_dispatch_event( TinyGUI_Event * event );

#ifdef __cplusplus
}
#endif

#endif //TINYGUI_LOOP_H
