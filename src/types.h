//
// Created by 志伟佘 on 2024/3/10.
//

#include "tinyguiconf.h"

#ifndef TINYGUI_TYPES_H
#define TINYGUI_TYPES_H

typedef unsigned long int TguiID;       // number ID
typedef unsigned char *   TguiSID;      // string ID

typedef unsigned char *   TguiPtr;      // normal pointer
typedef TguiPtr *         TguiPofPtr;   // pointer of pointer

#ifdef TINYGUI_SYS_32

typedef unsigned long TguiU32;      // U32
typedef unsigned long long TguiU64; // U64

#else

typedef unsigned int TguiU32;       // U32
typedef unsigned long TguiU64;      // U64
#endif

#endif //TINYGUI_TYPES_H
