#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>
#include <unistd.h>

#include "core/renderer.h"
#include "core/loop.h"
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
    assert( conf->proxy->acc && conf->proxy->acc->init);
    assert( conf->proxy->display && conf->proxy->display->init);
    assert( conf->proxy->input && conf->proxy->input->init);

    tinygui_main_loop_construct();

    if (conf->proxy->acc)
        conf->proxy->acc->init();

    if (conf->proxy->display)
        conf->proxy->display->init();

    if (conf->proxy->input)
        conf->proxy->input->init();

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

static bool run_input_thread = true;
static void *input_thread()
{
    while( run_input_thread )
    {
        // todo input handler
        usleep( currentInputPeriodUS );
    }
    return 0;
}

static bool run_main_thread = true;
void tinygui_main()
{
    tinygui_main_mutex_init();

    pthread_create(&p_input, NULL, input_thread, NULL);

    while( run_main_thread ) {

        tinygui_main_lock();

        tinygui_main_loop_run();

        tinygui_pre_rend();
        tinygui_rend();

//        printf("main loop \n");

        // Todo in mainloop [ Gui Handler ]
        tinygui_main_unlock();

        usleep( currentPeriodUS );
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