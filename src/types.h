//
// Created by 志伟佘 on 2024/3/10.
//

#include "tinyguiconf.h"
#include <stdbool.h>
#include <stdint.h>

#ifndef TINYGUI_TYPES_H
#define TINYGUI_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef U32

typedef uint8_t     U8;
typedef uint16_t    U16;
typedef uint32_t    U32;
typedef uint64_t    U64;

#endif

#ifndef I32

typedef int8_t      I8;
typedef int16_t     I16;
typedef int32_t     I32;
typedef int64_t     I64;

#endif

typedef unsigned long int TinyGUI_ID;       // number ID
typedef unsigned char *   TinyGUI_SID;      // string ID

typedef unsigned char *   TinyGUI_Ptr;      // normal pointer
typedef void *            TinyGUI_AnyPtr;   // any pointer
typedef TinyGUI_Ptr *     TinyGUI_PofPtr;   // pointer of pointer

typedef uint64_t          TinyGUI_PhyAddr;
typedef char *            TinyGUI_String;
typedef U64               TinyGUI_TimeStamp;

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

typedef struct TinyGUI_ViewSet_t
{
    U32                  width;
    U32                  height;
    TinyGUI_RotationType rotation;
    TinyGUI_FlipType     flip;
    U8                   bpp;
} TinyGUI_ViewSet;

typedef struct TinyGUI_ViewPos_t
{
    U32 x;
    U32 y;
    TinyGUI_RotationType rotation;
    TinyGUI_FlipType     flip;
} TinyGUI_ViewPos;

typedef struct TinyGUI_ViewCut_t
{
    I32 offsetX;
    I32 offsetY;
    I32 clipX;
    I32 clipY;
} TinyGUI_ViewCut;

#ifdef __cplusplus
}
#endif

#endif //TINYGUI_TYPES_H
