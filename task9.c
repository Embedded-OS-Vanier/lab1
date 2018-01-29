#include "config.h"
#include "task9.h"
#include "process.h"

extern int task9_f;

void task9(void) {
    if(task9_f == 1){
        task9_f = 0;
        process9();     

    }    
}
