//
// Created by 志伟佘 on 2024/3/10.
//
#include <stdlib.h>
#include "../../utils/cobj.h"
#include "sw_acc.h"

static TinyGUI_Acc * sw_accImpl;

void  tinygui_sw_acc_construct( TinyGUI_Acc * accImpl )
{
    _CPtrObject( sw_accImpl, TinyGUI_Acc );

    sw_accImpl->init        = tinygui_sw_acc_init;
    sw_accImpl->deinit      = tinygui_sw_acc_deinit;
    sw_accImpl->malloc      = tinygui_sw_acc_malloc;
    sw_accImpl->new_buffer  = tinygui_sw_acc_new_buffer;

    accImpl = sw_accImpl;
}

void tinygui_sw_acc_init()
{

}

void tinygui_sw_acc_deinit()
{
    free(sw_accImpl);
}
