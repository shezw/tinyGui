/**
    -----------------------------------------------------------

 	Project
 	sdl.c    2025/3/5   
 	
 	@link    : https://github.com/shezw/tinygui
 	@author	 : shezw
 	@email	 : hello@shezw.com

    -----------------------------------------------------------
*/
#include <stdlib.h>
#include <string.h>

#include "screen.h"

#include "tinygui.h"
#include "display.h"
#include "loop.h"

#include "sw/sw_mem.h"
#include "proxy/memory.h"
#include "utils/cobj.h"

/**
 * ~/dev/tinyGui/build $ cmake .. -D PORTING=MacOS -D CMAKE_BUILD_TYPE=Debug -D SDL2_INCLUDE_DIR=/opt/homebrew/Cellar/sdl2/2.32.2/include -D SDL2_LIBRARY=/opt/homebrew/Cellar/sdl2/2.32.2/lib
 */

static TinyGUI_DisplayMgr * displayMgr = NULL;
static TinyGUI_Screen * screen = NULL;

static void sdl_refr(void * t);
static void sdl_clean_up(void);

static void sdl_refr(void * t)
{
    (void)t;
    sdl_context * sdl_ctx = (sdl_context*)displayMgr->handler;
    /*Refresh handling*/
    if(sdl_ctx->sdl_refr_qry != false) {
        sdl_ctx->sdl_refr_qry = false;
        sdl_window_update(sdl_ctx);
    }

}

void tinygui_porting_macos_sdl_display_init()
{
    sdl_context * sdl_ctx = (sdl_context *)malloc(sizeof(sdl_context));
    memset(sdl_ctx, 0, sizeof(sdl_context));

    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        fprintf(stderr, "SDL_Init failed: %s\n", SDL_GetError());
        exit(1);
    }

    SDL_Window * window = SDL_CreateWindow("TinyGUI", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, displayMgr->viewSet->width, displayMgr->viewSet->height, SDL_WINDOW_SHOWN);

    if(window == NULL)
    {
        fprintf(stderr, "SDL_CreateWindow failed: %s\n", SDL_GetError());
        exit(1);
    }
    sdl_ctx->window = window;

    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if(renderer == NULL)
    {
        fprintf(stderr, "SDL_CreateRenderer failed: %s\n", SDL_GetError());
        exit(1);
    }
    sdl_ctx->renderer = renderer;

    SDL_Texture * texture = SDL_CreateTexture(sdl_ctx->renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, displayMgr->viewSet->width, displayMgr->viewSet->height);

    if (texture == NULL)
    {

    }
    sdl_ctx->texture = texture;

    SDL_SetTextureBlendMode(sdl_ctx->texture, SDL_BLENDMODE_BLEND);

    /*Initialize the frame buffer to gray (77 is an empirical value) */

    /*Create a screen buffer*/
    screen = tinygui_screen_construct( displayMgr, true);

    sdl_ctx->screen_fb = (uint32_t *) screen->imp->buffer->vAddr;
    memset(sdl_ctx->screen_fb, 0x00, displayMgr->viewSet->width * displayMgr->viewSet->height * sizeof(uint32_t));

    sdl_ctx->sdl_refr_qry = true;

    displayMgr->handler = sdl_ctx;

//    tinygui_main_loop_porting_init_add(sdl_event_handler);
}

void sdl_window_update(sdl_context * ctx)
{
    TinyGUI_ViewSet * viewSet = displayMgr->viewSet;

    SDL_UpdateTexture(ctx->texture, NULL, ctx->screen_fb, displayMgr->viewSet->width * sizeof(uint32_t));
    SDL_RenderClear(ctx->renderer);
//    lv_disp_t * d = _lv_refr_get_disp_refreshing();
//    if(d->driver->screen_transp) {
//        SDL_SetRenderDrawColor(ctx->renderer, test_pixel[0], test_pixel[1], test_pixel[2], test_pixel[3]);
//        SDL_Rect r;
//        r.x = 0; r.y = 0; r.w = viewSet->width; r.h = viewSet->height;
//        SDL_RenderDrawRect(ctx->renderer, &r);
//    }

    /*Update the renderer with the texture containing the rendered image*/
    SDL_RenderCopy(ctx->renderer, ctx->texture, NULL, NULL);
    SDL_RenderPresent(ctx->renderer);
}

static void tinygui_porting_macos_sdl_display_deinit()
{
    if(displayMgr)
    {
        free(displayMgr);
        displayMgr = NULL;
    }
}

const TinyGUI_DisplayMgr * tinygui_get_porting_macos_sdl_display()
{
    if(displayMgr == NULL)
    {
        fprintf(stderr, "Display manager is not initialized.\n");
        return NULL;
    }
    return displayMgr;

}

static TinyGUI_DisplayMgr *  tinygui_porting_macos_sdl_display_construct( TinyGUI_ViewSet * viewSet)
{
    displayMgr = (TinyGUI_DisplayMgr *)malloc(sizeof(TinyGUI_DisplayMgr));
    displayMgr->viewSet = viewSet;

    displayMgr->buffer = tinygui_sw_acc_new_buffer( viewSet );

    displayMgr->init = tinygui_porting_macos_sdl_display_init;
    displayMgr->deinit = tinygui_porting_macos_sdl_display_deinit;

    return displayMgr;
}

static void tinygui_porting_macos_sdl_display_destruct( TinyGUI_DisplayMgr * displayMgr )
{
    free(displayMgr);
}

TinyGUI_DisplayMgr * tinygui_porting_display_construct( TinyGUI_ViewSet * viewSet)
{
    return tinygui_porting_macos_sdl_display_construct(viewSet);
}

void tinygui_porting_display_destruct( TinyGUI_DisplayMgr * displayMgr )
{
    tinygui_porting_macos_sdl_display_destruct(displayMgr);
}