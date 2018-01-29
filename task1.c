#include "Tick.h"
#include "config.h"
#include "task1.h"
#include "process.h"

void task1(void) {
	static DWORD lastTick;
    char textBuff1[17];
    int i=0;
    static enum {SM_IDLE,SM_INC,SM_CRASH} state=0;
    switch (state) {
      	case SM_IDLE:
			if(TickGet_ms() - lastTick >=1000){
				state=SM_INC;   	// memorize the current time
				lastTick= TickGet_ms();
			}
            if(!S4) state = SM_CRASH;
         break;
        case SM_INC:
			process1();
			state=SM_IDLE;
         break;
      	case SM_CRASH:
            i=0;
            sprintf(textBuff1,"Task1 CRASHED   ");
            LCDPos1(0);
            while(textBuff1[i]){
                    LCDPut(textBuff1[i]);   
                    i++;
            }
            while(1); // blocked and crashes the system
            break;
       } // end case
}
