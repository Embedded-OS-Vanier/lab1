/* 
 * File:   scheduler.h
 * Author: sh
 *
 * Created on December 5, 2017, 4:31 PM
 */

#ifndef SCHEDULER_H
#define	SCHEDULER_H

//#define NULL 0

/* Application event handler function pointer */
typedef void (*pFunc)(void);

/* Link-list definition */
typedef struct TaskRecord
{
    pFunc pFunc;
    char id;
    char prior_cnt;
    char prior_period;
    struct TaskRecord *pNext;
}tTaskRecord;

void TaskManager(void);
void TaskCreate(void (*EventHandlerFunc)(void),char , char);

#endif	/* SCHEDULER_H */

