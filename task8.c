#include "config.h"
#include "task8.h"
#include "process.h"

extern int task8_f;

void task8(void) {
			if(task8_f == 1){
				task8_f =0;
                process8();    // slow process

			}
}


