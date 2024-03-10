//
// Created by 志伟佘 on 2024/3/10.
//
#include <stdlib.h>
#include "proxy.h"

static TypeGUI_Proxy * singletonProxy;

void tinygui_proxy_init( TinyGUI_Proxy * proxyImp )
{
    singletonProxy = malloc( sizeof TinyGUI_Proxy);

    singletonProxy->acc_new_buffer = proxyImp->acc_new_buffer;
    singletonProxy->acc_malloc = proxyImp->acc_malloc;

}
