//
// Created by 志伟佘 on 2024/3/10.
//
#include <stdlib.h>
#include "sw_acc.h"
#include "sw_blend.h"
#include "sw_mem.h"

static TinyGUI_Acc * sw_accImpl;

TGUIStatus sw_acc_init( TinyGUI_Acc * ptr )
{
    sw_accImpl = malloc( sizeof(TinyGUI_Acc) );

    sw_accImpl->malloc = tinygui_sw_malloc;
    sw_accImpl->new_buffer = tinygui_sw_new_buffer;


    return TGUI_OK;
}

TGUIStatus sw_acc_deinit()
{
    free(sw_accImpl);

    return TGUI_OK;
}
