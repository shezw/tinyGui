//
// Created by 志伟佘 on 2024/3/10.
//
#include <stdlib.h>
#include "sw_mem.h"

TguiID tinygui_sw_malloc( TguiPtr * address, TguiU32 size )
{
    address = malloc( size );
    return 0;
}

TguiID tinygui_sw_new_buffer( TguiPtr * address, TguiU32 size )
{
    address = malloc( size );
    return 0;
}
