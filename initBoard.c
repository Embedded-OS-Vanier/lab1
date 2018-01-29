#include "initBoard.h"
#include "config.h"

void initIO(void) 
{
    _TRISD13 = 1;    // Used for push button
    TRISA=0;    //LEDs

}
//8Hz


void initTimer3( int _pr)
{
// Initialize and enable Timer2
	T3CONbits.TON = 0; // Disable Timer
	T3CONbits.TCS = 0; // Select internal instruction cycle clock
	T3CONbits.TGATE = 0; // Disable Gated Timer mode
	T3CONbits.TCKPS = 0b11; // Select 256:1 Prescaler
	TMR3 = 0x00; // Clear timer register
	//PR2=28250;  // fine tuned
   	PR3=_pr;  // for test
    _T3IP = 0x01; // Set Timer 2 Interrupt Priority Level
	_T3IF = 0; // Clear Timer 2 Interrupt Flag
	_T3IE = 1; // Enable Timer 2 interrupt
	T3CONbits.TON = 1; // Start Timer             

} // init

void initTimer2( void)
{
// Initialize and enable Timer2
	T2CONbits.TON = 0; // Disable Timer
	T2CONbits.TCS = 0; // Select internal instruction cycle clock
	T2CONbits.TGATE = 0; // Disable Gated Timer mode
	T2CONbits.TCKPS = 0b10; // Select 64:1 Prescaler
	TMR2 = 0x00; // Clear timer register
	//PR2=28250;  // fine tuned
   	PR2=31250;  // for test
    _T2IP = 0x01; // Set Timer 2 Interrupt Priority Level
	_T2IF = 0; // Clear Timer 2 Interrupt Flag
	IEC0bits.T2IE = 1; // Enable Timer 2 interrupt
	T2CONbits.TON = 1; // Start Timer             

} // init


