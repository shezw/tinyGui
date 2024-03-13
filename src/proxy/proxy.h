//
// Created by 志伟佘 on 2024/3/10.
//
#include "../types.h"
#include "memory.h"
#include "fill.h"
#include "blend.h"

#ifndef TINYGUI_PROXY_H
#define TINYGUI_PROXY_H

typedef struct TinyGUI_Acc_t
{
    AccNewBufferFunc    new_buffer;
    AccMallocFunc       malloc;
} TinyGUI_Acc;

typedef struct TinyGUI_Proxy_t
{

    TinyGUI_RotationType rotation;
    TinyGUI_FlipType     flip;

    bool                 useAcc;
    TinyGUI_AccType      accType;
    TinyGUI_Acc        * acc;

} TinyGUI_Proxy;

void tinygui_proxy_init( TinyGUI_Proxy * proxyImp );

#endif //TINYGUI_PROXY_H
