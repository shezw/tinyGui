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

#define cObject( ptr, Type ) \
Type * ptr = (Type *) malloc( sizeof(Type) ); \
memset( ptr, 0, sizeof(Type) );

#define cSubObject( ptr, Type ) \
ptr = (Type *)malloc(sizeof(Type));   \
memset( ptr, 0, sizeof(Type) );

#define stCopy( structTar, structFrom ) \
memcpy( &structTar, &structFrom, sizeof(structTar) );

#define ptrCopy( ptrTar, ptrFrom, Type ) \
memcpy( ptrTar, ptrFrom, sizeof(Type) );

#ifdef __cplusplus
}
#endif

#endif //TINYGUI_COBJ_H
