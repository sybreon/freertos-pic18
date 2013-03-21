/* 
 * File:   newmain.c
 * Author: sybreon
 *
 * Created on March 21, 2013, 8:11 PM
 */

/* Scheduler include files. */
#include "FreeRTOS.h"
#include "task.h"


/*
 * 
 */
void main(void) {


    /* Start the scheduler.  Will never return here. */
    vTaskStartScheduler();
    return 0;
}

