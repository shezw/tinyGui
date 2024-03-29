//
// Created by 志伟佘 on 2024/3/10.
//
#include <stdlib.h>
#include <string.h>
#include "../../utils/cobj.h"
#include "sw_mem.h"

//typedef TinyGUI_Buffer * buffer (*AccNewBufferFunc)( TinyGUI_ViewSet * viewSet );
//typedef TinyGUI_Ptr * address (*AccMallocFunc)( U32 size );

TinyGUI_Buffer * tinygui_sw_acc_new_buffer( TinyGUI_ViewSet * viewSet )
{
    _CObject( buffer, TinyGUI_Buffer );
    _CSubObject( buffer->viewSet, TinyGUI_ViewSet );
    _PtrCopy( buffer->viewSet, viewSet, TinyGUI_ViewSet );

    buffer->vAddr = malloc( viewSet->width * viewSet->height * viewSet->bpp );
    buffer->pAddr = 0;

    return buffer;
}

TinyGUI_Ptr tinygui_sw_acc_malloc( U64 size )
{
    return malloc( size );
}
