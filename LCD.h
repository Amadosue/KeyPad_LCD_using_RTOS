/*
 * LCD.h
 *
 * Created: 12/16/2017 11:10:57 AM
 *  Author: NewUsername
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "stdMacros.h"

//#define INIT_PORT_LCD DDRA|= 15<<4; DDRB|=7<<1;

#define RW(x)	(x==1)?SETBIT(PORTB,2):CLRBIT(PORTB,2)
#define RS(x)	(x==1)?SETBIT(PORTB,1):CLRBIT(PORTB,1)
#define EN(x)	(x==1)?SETBIT(PORTB,3):CLRBIT(PORTB,3)

#define D4(x)	(x==1)?SETBIT(PORTA,4):CLRBIT(PORTA,4)
#define D5(x)	(x==1)?SETBIT(PORTA,5):CLRBIT(PORTA,5)
#define D6(x)	(x==1)?SETBIT(PORTA,6):CLRBIT(PORTA,6)
#define D7(x)	(x==1)?SETBIT(PORTA,7):CLRBIT(PORTA,7)

void lcd_init();
void lcd_write_cmd_char(uint8_t,uint8_t);
void lcd_write_txt(uint8_t *);
void lcd_write_number(uint16_t );





#endif /* LCD_H_ */