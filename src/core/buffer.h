//
// Created by 志伟佘 on 2024/3/9.
//
#include "../types.h"

#ifndef TINYGUI_BUFFER_H
#define TINYGUI_BUFFER_H

typedef struct TinyGUI_Buffer_t
{
    U32     width;
    U32     height;
    U32     x;
    U32     y;
    U8      bpp;

    TguiPhyAddr    pAddr;
    TguiPtr        vAddr;

} TinyGUI_Buffer;

#endif //TINYGUI_BUFFER_H
