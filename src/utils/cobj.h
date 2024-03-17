//
// Created by 志伟佘 on 2024/3/17.
//
#include <stdlib.h>
#include <string.h>

#ifndef TINYGUI_COBJ_H
#define TINYGUI_COBJ_H


#ifdef __cplusplus
extern "C" {
#endif

#define _CObject( ptr, Type ) \
Type * ptr = (Type *) malloc( sizeof(Type) ); \
memset( ptr, 0, sizeof(Type) );

#define _CSubObject( ptr, Type ) \
ptr = (Type *)malloc(sizeof(Type));   \
memset( ptr, 0, sizeof(Type) );

#define _StCopy( structTar, structFrom ) \
memcpy( &structTar, &structFrom, sizeof(structTar) );

#define _PtrCopy( ptrTar, ptrFrom, Type ) \
memcpy( ptrTar, ptrFrom, sizeof(Type) );

#ifdef __cplusplus
}
#endif

#endif //TINYGUI_COBJ_H
