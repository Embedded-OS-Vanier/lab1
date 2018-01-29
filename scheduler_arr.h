/* 
 * File:   scheduler.h
 * Author: sh
 *
 * Created on December 5, 2017, 4:31 PM
 */

#ifndef SCHEDULER_ARR_H
#define	SCHEDULER_ARR_H

#define NBTASKS 15

//#define NULL 0

/* Application event handler function pointer */
typedef void (*pFunc)(void);

/* Link-list definition */
typedef struct TaskRecord
{
    pFunc pFunc;
    char occupied;
    int prior_cnt;
    int prior_period;
 //   struct TaskRecord *pNext;
}tTaskRecord;


void TaskManager(void);
void TaskCreate(void (*EventHandlerFunc)(void), int);

#endif	/* SCHEDULER_ARR_H */

