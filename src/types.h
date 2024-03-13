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

typedef int TinyGUI_Status;

#define TinyGUI_OK  0
#define TinyGUI_ERR -1

typedef enum TinyGUI_AccType_e
{
    TinyGUI_AccType_None,

    TinyGUI_AccType_Software,

    TinyGUI_AccType_SigmaStar_SSD202,
    TinyGUI_AccType_AllWinner_R818,
    TinyGUI_AccType_AllWinner_H616,

    TinyGUI_AccType_Max
} TinyGUI_AccType;

typedef enum TinyGUI_RotationType_e
{
    TinyGUI_Rotation_None = 0,
    TinyGUI_Rotation_90   = 90,
    TinyGUI_Rotation_180  = 180,
    TinyGUI_Rotation_270  = 270,
    TinyGUI_Rotation_MAX  = 360
} TinyGUI_RotationType;

typedef enum TinyGUI_FlipType_e
{
    TinyGUI_Flip_None     = 0,
    TinyGUI_Flip_Hor,
    TinyGUI_Flip_Ver,
    TinyGUI_Flip_Max
} TinyGUI_FlipType;

#endif //TINYGUI_TYPES_H
