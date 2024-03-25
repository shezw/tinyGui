#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>
#include <unistd.h>
#include "tinygui.h"

static pthread_mutex_t mutex;

static TinyGUI * singletonTinyGUI;
static bool      singletonInited;

static TinyGUI_TimeStamp currentFPS             = 100;
static TinyGUI_TimeStamp currentInputFPS        = 200;

static TinyGUI_TimeStamp currentPeriodMS        = 10;
static TinyGUI_TimeStamp currentInputPeriodMS   = 5;

static TinyGUI_TimeStamp currentPeriodUS        = 10 * 1000;
static TinyGUI_TimeStamp currentInputPeriodUS   = 5 * 1000;

static pthread_t p_input;

const TinyGUI * tinygui()
{
    return singletonInited ? singletonTinyGUI : NULL;
}

void tinygui_version()
{
    printf( TINYGUI_VERSION );
}

TinyGUI_Status tinygui_init( TinyGUI_Config * conf )
{
    singletonTinyGUI = malloc( sizeof(TinyGUI) );
    singletonInited = true;
    singletonTinyGUI->conf = conf;

    assert( conf->proxy && conf->proxy->acc );

    return TinyGUI_OK;
}

TinyGUI_Status tinygui_deinit()
{
    free(singletonTinyGUI);
    return TinyGUI_OK;
}

void tinygui_main_mutex_init()
{
    pthread_mutex_init(&mutex, NULL);
}

void tinygui_main_lock()
{
    pthread_mutex_lock(&mutex);
}

void tinygui_main_unlock()
{
    pthread_mutex_unlock(&mutex);
}

void tinygui_main_mutex_destroy()
{
    pthread_mutex_destroy(&mutex);
}

static void *input_thread()
{
    while(true)
    {
        // todo input handler
        usleep( currentInputPeriodUS );
        printf("main input loop \n");
    }
    return 0;
}

void tinygui_main()
{
    tinygui_main_mutex_init();

    pthread_create(&p_input, NULL, input_thread, NULL);

    while(true) {

        tinygui_main_lock();

        // Todo in mainloop [ Gui Handler ]
        usleep( currentPeriodUS );

        printf("main loop \n");
        tinygui_main_unlock();
    }

    tinygui_main_mutex_destroy();

}

void tinygui_set_fps( TinyGUI_TimeStamp fps )
{
    if (fps>TINYGUI_MAX_FPS) return;
    currentFPS = fps;
    currentPeriodMS = 1000 / currentFPS;
    currentPeriodUS = 1000 * currentPeriodMS;
}

void tinygui_set_input_fps( TinyGUI_TimeStamp fps )
{
    if (fps>TINYGUI_MAX_INPUT_FPS) return;
    currentInputFPS = fps;
    currentInputPeriodMS = 1000 / currentInputFPS;
    currentInputPeriodUS = 1000 * currentInputPeriodMS;
}

TinyGUI_TimeStamp tinygui_get_fps()
{
    return currentFPS;
}

TinyGUI_TimeStamp tinygui_get_input_fps()
{
    return currentInputFPS;
}

TinyGUI_TimeStamp tinygui_get_period()
{
    return currentPeriodMS;
}

TinyGUI_TimeStamp tinygui_get_input_period()
{
    return currentInputPeriodMS;
}

TinyGUI_Status tinygui_run( U32 ms )
{


    return TinyGUI_OK;
}