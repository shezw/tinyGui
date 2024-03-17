//
// Created by 志伟佘 on 2024/3/9.
//
#include "../types.h"

#ifndef TINYGUI_BUFFER_H
#define TINYGUI_BUFFER_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct TinyGUI_Buffer_t
{
    TinyGUI_ViewSet * viewSet;

    TinyGUI_PhyAddr    pAddr;
    TinyGUI_Ptr        vAddr;

} TinyGUI_Buffer;

#ifdef __cplusplus
}
#endif

#endif //TINYGUI_BUFFER_H
