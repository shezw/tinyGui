//
// Created by 志伟佘 on 2024/3/10.
//
#include <stdlib.h>
#include <string.h>
#include "proxy.h"

static TinyGUI_Proxy * singletonProxy;

void tinygui_proxy_init( TinyGUI_Proxy * proxyImp )
{
    singletonProxy = malloc( sizeof( TinyGUI_Proxy));
    memset(singletonProxy,0,sizeof(TinyGUI_Proxy));

    singletonProxy->acc = proxyImp->acc;
    singletonProxy->accType = proxyImp->accType;
    singletonProxy->useAcc = true;

}
