//
// Created by 志伟佘 on 2024/3/10.
//

#ifndef TINYGUI_BLEND_H
#define TINYGUI_BLEND_H

#include "memory.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef TinyGUI_Status (*AccBufferBlend)( TinyGUI_Buffer * src, TinyGUI_ViewRect src_rect, TinyGUI_Buffer * target, TinyGUI_ViewRect target_rect );




#ifdef __cplusplus
}
#endif

#endif //TINYGUI_BLEND_H
