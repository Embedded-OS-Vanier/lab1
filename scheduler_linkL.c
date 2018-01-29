#include "task1.h"
#include "scheduler.h"
#include <stdlib.h>

static tTaskRecord *head = NULL;

tTaskRecord testTaskRecord ;
void TaskCreate(void (*pFunc)(void),char _id, char _prior){

    tTaskRecord *pNewTask;
    static tTaskRecord *pActiveTask = NULL;

    /* Create a new task record */
    pNewTask =(tTaskRecord*) malloc(sizeof(tTaskRecord));
    if(pNewTask != NULL)
    {
        /* Assign the event handler function to the task */
        pNewTask->pFunc = pFunc;
        pNewTask->id = _id;
        pNewTask->prior_cnt=_prior;
        pNewTask->prior_period=_prior;
        pNewTask->pNext = NULL;

        if(head == NULL)
        {
            /* Store the address of the first task in the task list */
            head = pNewTask;
        }
        else
        {
            /* Move to the last task in the list */
            pActiveTask = head;
            while(pActiveTask->pNext != NULL)
            {
                pActiveTask = pActiveTask->pNext;
            }

            /* Add the new task to the end of the list */
            pActiveTask->pNext = pNewTask;
        }
    }
}


void TaskManager(void)
{
    tTaskRecord *pActiveTask;
    pFunc       highPFunc = NULL;     // High priority task pointer
    // Find out High Priority task (priority 1)
    // There cannot be more than one High priority
     while(pActiveTask != NULL) // while the last node is not reached
            {
                if(pActiveTask->pFunc != NULL)  
                {
                    /* If prior_period is 1, make it the highest priority task */
                    if(pActiveTask->prior_period ==1){
                        highPFunc = pActiveTask->pFunc;
                    }
                } 
				/* Move to the next node */
                pActiveTask = pActiveTask->pNext;
            }
    /* No return */
    while(1){
     
            /* Process all priority tasks  */
            pActiveTask = head; // Reset to the first linked list node
            while(pActiveTask != NULL) // while the last node is not reached
            {
                if(pActiveTask->pFunc != NULL)  
                {
                    // Always calls priority 0 first (those with period 0)
                    if (highPFunc != NULL) (highPFunc)();
                    /* Call the task's event handler function if period expires but not high priority 0 */
                    if(pActiveTask->prior_cnt ==0 && pActiveTask->prior_period !=1 ){
                        (pActiveTask->pFunc)();
                        pActiveTask->prior_cnt = pActiveTask->prior_period;
                    }
                    else --(pActiveTask->prior_cnt);
                } 
				/* Move to the next node */
                pActiveTask = pActiveTask->pNext;
            }
        
    }
}
