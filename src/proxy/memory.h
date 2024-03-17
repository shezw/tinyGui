//
// Created by 志伟佘 on 2024/3/10.
//

#include "../types.h"
#include "../core/buffer.h"

#ifndef TINYGUI_MEMORY_H
#define TINYGUI_MEMORY_H

#ifdef __cplusplus
extern "C" {
#endif

/**

 make sure use acc_$(methods) only in Graphic ACC or DMA scenes.

**/

typedef TinyGUI_Buffer * (*AccNewBufferFunc)( TinyGUI_ViewSet * viewSet );
typedef TinyGUI_Ptr (*AccMallocFunc)( U64 size );


#ifdef __cplusplus
}
#endif

#endif //TINYGUI_MEMORY_H
