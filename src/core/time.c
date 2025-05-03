/**
    -----------------------------------------------------------

 	Project
 	time.c    2025/3/9   
 	
 	@link    : https://github.com/shezw/tinygui
 	@author	 : shezw
 	@email	 : hello@shezw.com

    -----------------------------------------------------------
*/
#include "types.h"
#include <sys/time.h>
#include "time.h"

TinyGUI_TimeStamp tinygui_get_time_ms()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (TinyGUI_TimeStamp)tv.tv_sec * 1000 + tv.tv_usec / 1000;

}
