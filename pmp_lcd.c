/***********************************************************************************************
 *
 * LCD Driver for PIC24.
 *
 ***********************************************************************************************
 * FileName:        pmp_lcd.c
  *
 * A simple LCD driver for LCDs interface through the PMP
 * 
 * Author:			Date:				Description:									Version:
 * Serge Hould		16 Nov. 2017		Add comments. Make local functions static.		v2.0.0
 *
 * The original file is located in :
 * 247-501-VA_Advanced Programming in Microprocessors\A16\MPLAB-X_projects\common
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#include "config.h"
#include "pmp_lcd.h"
//#include <xc.h>


unsigned long _uLCDloops;
static void Wait(unsigned int B);
static void pmp_Init(void);

static void pmp_Init(void)
{
	unsigned int mode,control,port,addrs,interrupt;
	
    control = BIT_PMP_ON | BIT_RD_WR_ON | BIT_RD_WR_HI ;
	mode = BIT_MODE_MASTER_1 | BIT_WAITB_4_TCY  | BIT_WAITM_15_TCY | BIT_WAITE_4_TCY ;
	port = BIT_P0;
	addrs = 0x0000;
	interrupt = 0x0000;
	
	PMPClose();
	PMPOpen(control,mode,port,addrs,interrupt);
}		

/***************************************************************
Name:	void LCDInit(void)
Description: Initializes the LCD using pmp bus.

****************************************************************/
void LCDInit(void)
{	
    pmp_Init();

	_uLCDloops = LCD_STARTUP;
	Wait(_uLCDloops);

	_uLCDloops = LCD_F_INSTR;
	PMDIN1 = 0b00111000;			// Set the default function
	Wait(_uLCDloops);

	_uLCDloops = LCD_STARTUP;
	Wait(_uLCDloops);

	_uLCDloops = LCD_F_INSTR;
	PMDIN1 = 0b00001100;
	Wait(_uLCDloops);

	_uLCDloops = LCD_STARTUP;
	Wait(_uLCDloops);

	_uLCDloops = LCD_S_INSTR;
	PMDIN1 = 0b00000001;			// Clear the display
	Wait(_uLCDloops);

	_uLCDloops = LCD_STARTUP;
	Wait(_uLCDloops);

	_uLCDloops = LCD_S_INSTR;
	PMDIN1 = 0b00000110;			// Set the entry mode
     
	Wait(_uLCDloops);

	LCDClear();
	LCDHome();
}

/***************************************************************
Name:	void LCDHome(void)
Description: Sets the position home.

****************************************************************/
void LCDHome(void)
{
	_uLCDloops = LCD_S_INSTR;
//	PMADDR = 0x0000;
    PMPSetAddress(0x0000); 
	PMDIN1 = 0b00000010;
	while(_uLCDloops)
	_uLCDloops--;
}

/***************************************************************
Name:	void LCDL1Home(void)
Description: Sets the position home on line1

****************************************************************/
void LCDL1Home(void)
{
	_uLCDloops = LCD_S_INSTR;
//	PMADDR = 0x0000;
    PMPSetAddress(0x0000); 
	PMDIN1 = 0b10000000;
	while(_uLCDloops)
	_uLCDloops--;
}
/***************************************************************
Name:	void LCDL2Home(void)
Description: Sets the position home on line2.

****************************************************************/
void LCDL2Home(void)
{
	_uLCDloops = LCD_S_INSTR;
	//PMADDR = 0x0000;
	PMPSetAddress(0x0000); 
	PMDIN1 = 0b11000000;
	while(_uLCDloops)
	_uLCDloops--;
}

/***************************************************************
Name:	void LCDClear(void)
Description: Clears the whole LCD

****************************************************************/
void LCDClear(void)
{
	_uLCDloops = LCD_S_INSTR;
	//PMADDR = 0x0000;
	PMPSetAddress(0x0000); 
	PMDIN1 = 0b00000001;
	while(_uLCDloops)
	_uLCDloops--;
}
/***************************************************************
Name:	void LCDPut(char A)
Description: Put a character at the current position.

****************************************************************/
void LCDPut(char A)
{
	_uLCDloops = LCD_F_INSTR;
//	PMADDR = 0x0001;
    PMPSetAddress(0x0001); 
	PMDIN1 = A;
	while(_uLCDloops)
	_uLCDloops--;
	Nop();
	Nop();
	Nop();
	Nop();
   // __delay32(DELAY8MS);
}


/***************************************************************
Name:	void Wait(unsigned int B)
Description: Short delay

****************************************************************/
static void Wait(unsigned int B)
{
	while(B)
	B--;
}

/***************************************************************
Name:	void DisplayMSG( char *array)
Description: Dump a string to the current position. If it 
				reaches the end of line1, it will continue on
				line2.

****************************************************************/
void DisplayMSG( char *array)
{
  unsigned char i=0,line=1;	
	LCDL1Home();	
	 while (*array)           // Continue display characters from STRING untill NULL character appears.
	 {
	  LCDPut(*array++);  // Display selected character from the STRING.
	  if (i>19 && line==1)
	  {
	   LCDL2Home();
	   line++;
	  }
	   i++;	        
     }
}

/***************************************************************
Name:	void LCDPutString( char *array)
Description: Dump a string to the current position. Does not take 
				into account the end of the line.

****************************************************************/
void LCDPutString( char *array)
{
	 while (*array)           // Continue display characters from STRING untill NULL character appears.
	 {
	  LCDPut(*array++);  // Display selected character from the STRING.
     }
}


/***************************************************************
Name:	void LCDPos2(unsigned char row)
Description: Position the cursor to a specific position on line2.

****************************************************************/
void LCDPos2(unsigned char row)
{
    unsigned char temp;
	_uLCDloops = LCD_S_INSTR;
//	PMADDR = 0x0000;
    PMPSetAddress(0x0000); 
  //  PMDIN1 = 0b11001010 ;
    temp = 0b11000000 | row;
	PMDIN1 = temp;
	while(_uLCDloops)
	_uLCDloops--;
}

/***************************************************************
Name:	void LCDPos1(unsigned char row)
Description: Position the cursor to a specific position on line1.

****************************************************************/
void LCDPos1(unsigned char row)
{
    unsigned char temp;
	_uLCDloops = LCD_S_INSTR;
//	PMADDR = 0x0000;
    PMPSetAddress(0x0000); 
  //  PMDIN1 = 0b11001010 ;
    temp = 0b10000000 | row;
	PMDIN1 = temp;
	while(_uLCDloops)
	_uLCDloops--;
}
