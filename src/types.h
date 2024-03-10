//
// Created by 志伟佘 on 2024/3/10.
//

#include "tinyguiconf.h"
#include <stdbool.h>

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

typedef int TGUIStatus;

#define TGUI_OK  0
#define TGUI_ERR -1

typedef enum {
    TGUI_ACC_TYPE_NONE,

    TGUI_ACC_TYPE_SW,

    TGUI_ACC_TYPE_ST_SSD202,
    TGUI_ACC_TYPE_AW_R818,
    TGUI_ACC_TYPE_AW_H616,

    TGUI_ACC_TYPE_MAX
} TGUI_ACC_TYPE;

typedef enum {
    TGUI_ROTATION_NONE = 0,
    TGUI_ROTATION_90   = 90,
    TGUI_ROTATION_180  = 180,
    TGUI_ROTATION_270  = 270,
    TGUI_ROTATION_MAX  = 360
} TGUI_ROTATION_TYPE;

typedef enum {
    TGUI_FLIP_NONE     = 0,
    TGUI_FLIP_HORIZON,
    TGUI_FLIP_VERTICAL,
    TGUI_FLIP_MAX
} TGUI_FLIP_TYPE;

#endif //TINYGUI_TYPES_H
