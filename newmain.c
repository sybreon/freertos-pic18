/* 
 * File:   newmain.c
 * Author: sybreon
 *
 * Created on March 21, 2013, 8:11 PM
 */

/* Scheduler include files. */
#include "FreeRTOS.h"
#include "task.h"

#pragma config WDT = OFF
#pragma config OSC = HSPLL

static void vTask1(void *pvParameters) {
    while (1) {
        LATD ^= 0x1;
        vTaskDelay(111);
    }
}

static void vTask2(void *pvParameters) {
    while (1) {
        LATD ^= 0x2;
        vTaskDelay(222);
    }
}

static void vTask3(void *pvParameters) {
    while (1) {
        LATD ^= 0x4;
        vTaskDelay(333);
    }
}

static void vTask4(void *pvParameters) {
    while (1) {
        LATD ^= 0x8;
        vTaskDelay(444);
    }
}

static void vTask5(void *pvParameters) {
    while (1) {
        LATD ^= 0x10;
        vTaskDelay(555);
    }
}

static void vTask6(void *pvParameters) {
    while (1) {
        LATD ^= 0x20;
        vTaskDelay(666);
    }
}

static void vTask7(void *pvParameters) {
    while (1) {
        LATD ^= 0x40;
        vTaskDelay(777);
    }
}

static void vTask8(void *pvParameters) {
    while (1) {
        LATD ^= 0x80;
        vTaskDelay(888);
    }
}

/*
 * 
 */
void main(void) {
    /* Power up Configuration*/
    TRISD = 0;
    LATD = 0;
    /* Create tasks */
    xTaskCreate(vTask1, "T1", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(vTask2, "T2", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(vTask3, "T3", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(vTask4, "T4", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(vTask5, "T5", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(vTask6, "T6", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(vTask7, "T7", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(vTask8, "T8", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);

    /* Start the scheduler.  Will never return here. */
    vTaskStartScheduler();
    return 0;
}

