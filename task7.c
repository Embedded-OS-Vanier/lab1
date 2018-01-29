#include "config.h"
#include "task7.h"
#include "Tick.h"
#include "process.h"

void task7(void) {
	static DWORD lastTick;
    static enum {SM_IDLE,SM_INC} state=0;
    switch (state) {
      	case SM_IDLE:
			if(TickGet_ms() - lastTick >=1000){
				state=SM_INC;   	// memorize the current time
				lastTick= TickGet_ms();
			}
         break;
        case SM_INC:
			process7();
			state=SM_IDLE;
         break;
    }
}