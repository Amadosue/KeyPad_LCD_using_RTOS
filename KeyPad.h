/*
 * KeyPad.h
 *
 * Created: 12/22/2017 5:50:37 PM
 *  Author: NewUsername
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "stdMacros.h"

#define KEYPAD_INIT_PORT DDRD= 0xf0;PORTD= 0x0f
#define INPUT_PORT PIND
#define OUTPUT_PORT PORTD

void KeyPad_init(void);
uint8_t KeyPad_read(void);




#endif /* KEYPAD_H_ */