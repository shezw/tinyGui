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



TinyGUI_Status sw_acc_init( TinyGUI_Acc * ptr );
TinyGUI_Status sw_acc_deinit();



#ifdef __cplusplus
}
#endif

#endif //TINYGUI_SW_ACC_H
