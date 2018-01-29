#include "scheduler_arr.h"
#include <stdlib.h>

static tTaskRecord PCB[NBTASKS ] ={0}; // array of pointers
static pFunc       highPFunc = NULL; 
	void TaskCreate(void (*_pFunc)(void),int _prior){
		int i=0;
		 while(PCB[i].occupied != 0)// end of the list?
		 {
			   i++;
		 }
		 PCB[i].pFunc=_pFunc;
		 PCB[i].occupied=1; //make it occupied
		 PCB[i].prior_period=_prior;
		 PCB[i].prior_cnt=_prior;
		 if(_prior == 1) highPFunc = _pFunc; // Only one task can be high priority
	}

//
void TaskManager(void)
{
    int i=0;
    /* No return */
    while(1){
        
     //   
     
            /* Process all priority tasks  */
            while(PCB[i].occupied != 0){  // end of the list
                if (highPFunc != NULL) (highPFunc)(); // Always processes priority 1
                if (--(PCB[i].prior_cnt) == 0) // decrement and check time
                { 
                    (PCB[i].pFunc)(); // TimeLeft is zero ? execute task
                    PCB[i].prior_cnt = PCB[i].prior_period; // re-init TimeLeft
                }
                i++;
            }
            i=0;// re-scan PCB
    }
}
