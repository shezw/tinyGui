//
// Created by 志伟佘 on 2024/3/10.
//

#include "../../types.h"
#include "../../core/buffer.h"

#ifndef TINYGUI_SW_MEM_H
#define TINYGUI_SW_MEM_H

#ifdef __cplusplus
extern "C" {
#endif


TinyGUI_Buffer * sw_acc_new_buffer( TinyGUI_ViewSet * viewSet );
TinyGUI_Ptr sw_acc_malloc( U64 size );



#ifdef __cplusplus
}
#endif

#endif //TINYGUI_SW_MEM_H
