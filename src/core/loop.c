//
// Created by 志伟佘 on 2024/3/10.
//
#include "../3rd.h"

#include "../utils/cobj.h"
#include "time.h"
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
      tinygui_porting_main_loop_init();
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

TinyGUI_LoopUnit * tinygui_main_loop_add( TinyGUI_LoopCall call )
{
    _CObject( loop, TinyGUI_LoopUnit );
    loop->call = call;
    loop->period = TINYGUI_LOOP_ZERO_PERIOD;
    loop->repeat = TINYGUI_LOOP_INFINITY;

    clist_rpush( mainLoopRoot, clist_node_new(loop) );

    return loop;
}

void tinygui_main_loop_run()
{
    clist_node_t * node = mainLoopRoot->head;
    TinyGUI_TimeStamp now = tinygui_get_time_ms();

    while( node )
    {
        TinyGUI_LoopUnit * unit = (TinyGUI_LoopUnit *)node->val;
        if( unit->paused )
        {
            node = node->next;
            continue;
        }

        if( unit->repeat == 0 )
        {
            clist_node_t * next = node->next;
            clist_remove( mainLoopRoot, node );
            node = next;
            continue;
        }

        if( unit->period == 0 )
        {
            unit->call( unit );
            node = node->next;
            continue;
        }

        if( now - unit->lastTime >= unit->period )
        {
            unit->call( unit );
            unit->lastTime = now;
            if( unit->repeat > 0 )
            {
                unit->repeat--;
            }
        }

        node = node->next;
    }

    tinygui_main_loop_porting( now );
}

void tinygui_main_loop_del( TinyGUI_LoopUnit unit )
{

}

TinyGUI_LoopUnit * tinygui_side_loop_add( TinyGUI_LoopCall call, TinyGUI_TimeStamp period, I32 repeats )
{

}

void tinygui_side_loop_del( TinyGUI_LoopUnit unit )
{

}


void tinygui_loop_send_event( TinyGUI_Event * event )
{

}

void tinygui_loop_dispatch_event( TinyGUI_Event * event )
{

}

