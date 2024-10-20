//
// Created by 志伟佘 on 2024/3/10.
//
#include "../3rd.h"

#include "../utils/cobj.h"
#include "loop.h"

clist_t * mainLoopRoot = NULL;
clist_t * sideLoopRoot = NULL;

void tinygui_main_loop_construct()
{
    mainLoopRoot = clist_new();
}

void tinygui_main_loop_init()
{
//    TinyGUI_LoopUnit * unit = NULL;
//    tinygui_linked_clist_init( loopRoot, sizeof(TinyGUI_LoopUnit) );
}

void tinygui_main_loop_deinit()
{
    clist_destroy( mainLoopRoot );
}

void tinygui_side_loop_construct()
{
    sideLoopRoot = clist_new();
}

void tinygui_side_loop_init()
{

}

void tinygui_side_loop_deinit()
{
    clist_destroy( sideLoopRoot );
}

TinyGUI_LoopUnit * tinygui_main_loop_add
( TinyGUI_LoopCall call, TinyGUI_TimeStamp period, I32 repeats )
{
    _CObject( loop, TinyGUI_LoopUnit );
    loop->call = call;
    loop->period = period;
    loop->repeat = repeats;

    clist_rpush( mainLoopRoot, clist_node_new(loop) );

    return loop;
}

void tinygui_main_loop_del( TinyGUI_LoopUnit unit )
{

}

void tinygui_loop_send_event( TinyGUI_Event * event )
{

}

void tinygui_loop_dispatch_event( TinyGUI_Event * event )
{

}

