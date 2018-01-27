/*
 * LCD.c
 *
 * Created: 12/16/2017 11:10:43 AM
 *  Author: NewUsername
 */ 

#include "LCD.h"

void lcd_init()
{
	SETBIT(DDRA,DDA4); //D4
	SETBIT(DDRA,DDA5); //D5
	SETBIT(DDRA,DDA6); //D6
	SETBIT(DDRA,DDA7); //D7
	
	SETBIT(DDRB,DDB1); //Set RS as output to select cmd or data
	SETBIT(DDRB,DDB2); //RW to read or write to LCD 
	SETBIT(DDRB,DDB3); //enable to push data to LCD
	
	RW(0);
	
	lcd_write_cmd_char(0x2,0);
	lcd_write_cmd_char(0x28,0);
	lcd_write_cmd_char(0x01,0);
	lcd_write_cmd_char(0x0c,0);
	lcd_write_cmd_char(0x06,0);
	lcd_write_cmd_char(0x80,0);
	
}

void lcd_write_cmd_char(uint8_t data,uint8_t select)
{
	RS(select);
	
	D7(READBIT(data,7));
	D6(READBIT(data,6));
	D5(READBIT(data,5));
	D4(READBIT(data,4));
	EN(1);
	_delay_ms(1);
	EN(0);
	_delay_ms(0);
	
	D7(READBIT(data,3));
	D6(READBIT(data,2));
	D5(READBIT(data,1));
	D4(READBIT(data,0));
	EN(1);
	_delay_ms(1);
	EN(0);
	_delay_ms(0);
	
}

void lcd_write_txt(uint8_t *text)
{
	uint8_t i;
	
	for(i=0;text[i]!='\0';i++)
	{
		lcd_write_cmd_char(text[i],1);
	}
}

void lcd_write_number(uint16_t num)
{
 /*  if(num<10){
	  lcd_write_cmd_char(num,1);	
	}
   if(num<100){
	   uint16_t bit1=num/10;
	   lcd_write_cmd_char(bit1+48,1);
	   uint16_t bit2=num%10;
	   lcd_write_cmd_char(bit2+48,1);
    }
	if(num<1000){
		uint16_t bit1=num/100;
		lcd_write_cmd_char(bit1+48,1);
		uint16_t bit2=(num%100)/10;
		lcd_write_cmd_char(bit2+48,1);
		uint16_t bit3=(num%100)%10;
		lcd_write_cmd_char(bit3+48,1);
	  }
	 if(num<10000){
		 uint16_t bit1=num/1000;
		 lcd_write_cmd_char(bit1+48,1);
		 uint16_t bit2=(num%1000)/100;
		 lcd_write_cmd_char(bit2+48,1);
		 uint16_t bit3=((num%1000)%100)/10;
		 lcd_write_cmd_char(bit3+48,1);
		 uint16_t bit4=((num%1000)%100)%10;
		 lcd_write_cmd_char(bit3+48,1);
	 } */
	 int8_t i=0;
	 uint8_t txt[10];
	 
	 while(num !=0)
	 {
		 txt[i++]= (num%10)+48;
		 num/=10;
	 } 
	 i--;
	 while(i>=0)
	 {
		 lcd_write_cmd_char(txt[i--],1);
	 }

}