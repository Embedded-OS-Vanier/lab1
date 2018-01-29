/* 
 * File:   config.h
 * Author: sh
 *
 * Created on December 8, 2017, 10:35 AM
 */

#ifndef CONFIG_H
#define	CONFIG_H
#include <xc.h>

#define LED7 _LATA7
#define LED6 _LATA7
#define S4  _RD13
#define	LINE0   _LATA7=0;     _LATA6=0;  _LATA5=0;     _LATA4=0
#define	LINE1   _LATA7=1;     _LATA6=0;  _LATA5=0;     _LATA4=0
#define	LINE2   _LATA7=1;     _LATA6=1;  _LATA5=0;     _LATA4=0
#define	LINE3   _LATA7=1;     _LATA6=1;  _LATA5=1;     _LATA4=0
#define 	_ISR_NO_PSV 	__attribute__((__interrupt__, no_auto_psv))
#define DELAY1MS    16000
#define DELAY8MS    128000
#define DELAY10MS   160000
#define DELAY20MS   320000
#define DELAY30MS   480000
#define DELAY50MS   800000
#define DELAY170MS  2720000
#define DELAY100MS  1600000
#define DELAY400MS  6400000


#endif	/* CONFIG_H */

