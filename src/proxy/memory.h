//
// Created by 志伟佘 on 2024/3/10.
//

#include "../types.h"

#ifndef TINYGUI_MEMORY_H
#define TINYGUI_MEMORY_H

/**

 make sure use acc_$(methods) only in Graphic ACC or DMA scenes.

**/

typedef TguiID (*AccNewBufferFunc)( TguiPtr * userAddress, TguiU32 size );
typedef TguiID (*AccMallocFunc)( TguiPtr * address, TguiU32 size );

#endif //TINYGUI_MEMORY_H
