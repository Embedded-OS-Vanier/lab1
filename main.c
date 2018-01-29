/**
 * Multi-rate round robin cooperative task scheduler for Lab1.
 * 
 * Author:			Date:				Description:						
 *                
 * 
 */

#include "GenericTypeDefs.h"
#include "mcc_generated_files/mcc.h"
#include "initBoard.h"
#include "config.h"
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"
#include "task5.h"
#include "task6.h"
#include "task7.h"
#include "task8.h"
#include "task9.h"

#include "scheduler_arr.h"

/*
    Main application
 */
int main(void) {
    // initialize the device
    OSCILLATOR_Initialize();
    initIO();
    TickInit();
    initTimer2();
    //    initTimer3(7812);   // 8 Hz
    // initTimer3(31250);   // 2 Hz   
    LCDInit();
     
    /* Register the event handler */
  
    TaskCreate(task2,7);

    /* Finally start the task manager. */
    TaskManager();
    return -1;
}
/**
 End of File
 */
