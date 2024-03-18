//
// Created by 志伟佘 on 2024/3/10.
//

#include "../../proxy/proxy.h"

#include "sw_mem.h"
#include "sw_fill.h"
#include "sw_map.h"
#include "sw_blend.h"
#include "sw_flush.h"

#ifndef TINYGUI_SW_ACC_H
#define TINYGUI_SW_ACC_H

#ifdef __cplusplus
extern "C" {
#endif


void tinygui_sw_acc_construct( TinyGUI_Acc * accImpl );

void tinygui_sw_acc_init();
void tinygui_sw_acc_deinit();



#ifdef __cplusplus
}
#endif

#endif //TINYGUI_SW_ACC_H
