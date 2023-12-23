/*
 * main.c
 *
 *  Created on: Dec 21, 2023
 *      Author: ahmed
 */
#define PORTA *(unsigned volatile char*)0x3B
#define DDRA *(unsigned volatile char*)0x3A
#define PINA *(unsigned volatile char*)0x39

#define PORTB *(unsigned volatile char*)0x38
#define DDRB *(unsigned volatile char*)0x37
#define PINB *(unsigned volatile char*)0x36

#define PORTC *(unsigned volatile char*)0x35
#define DDRC *(unsigned volatile char*)0x34
#define PINC *(unsigned volatile char*)0x33

#define PORTD *(unsigned volatile char*)0x32
#define DDRD *(unsigned volatile char*)0x31
#define PIND *(unsigned volatile char*)0x30

#define SET(REG,n) (REG|=1<<n)
#define RESET(REG,n) (REG&=~(1<<n))
#define GET(REG,n) ((REG>>n)&1)

#include <util/delay.h>

void SetPinDirection(char port,char pin, char direction){
	switch(direction){
	case 1:
		switch (port) {
			case 'A':
				SET(DDRA,pin);
				break;
			case 'B':
				SET(DDRB,pin);
				break;
			case 'C':
				SET(DDRC,pin);
				break;
			case 'D':
				SET(DDRD,pin);
				break;
				}
		break;
	case 0:
		switch (port) {
			case 'A':
				RESET(DDRA,pin);
				break;
			case 'B':
				RESET(DDRB,pin);
				break;
			case 'C':
				RESET(DDRC,pin);
				break;
			case 'D':
				RESET(DDRD,pin);
				break;
		}
		break;
	}
}

void SetPinValue(char port,char pin, char direction){
	switch(direction){
	case 1:
		switch (port) {
			case 'A':
				SET(PORTA,pin);
				break;
			case 'B':
				SET(PORTB,pin);
				break;
			case 'C':
				SET(PORTC,pin);
				break;
			case 'D':
				SET(PORTD,pin);
				break;
				}
		break;
	case 0:
		switch (port) {
			case 'A':
				RESET(PORTA,pin);
				break;
			case 'B':
				RESET(PORTB,pin);
				break;
			case 'C':
				RESET(PORTC,pin);
				break;
			case 'D':
				RESET(PORTD,pin);
				break;
		}
		break;
	}
}

unsigned char GetPinValue(char port,char pin){
	unsigned char x = 0;
	switch (port) {
		case 'A':
			x=  GET(PORTA,pin);
			break;
		case 'B':
			x=  GET(PORTB,pin);
			break;
		case 'C':
			x=  GET(PORTC,pin);
			break;
		case 'D':
			x=  GET(PORTD,pin);
			break;
			}
	return x;

}
int main (void)
{	//massive led test
	SetPinDirection('A',5,1);
	SetPinValue('A',5,1);

	SetPinDirection('B',5,1);
	SetPinValue('B',5,1);

	SetPinDirection('D',5,1);
	SetPinValue('D',5,1);

	// end massive led test

	//Working
	SetPinDirection('C',0,0);
	SetPinValue('C',0,1);


	SetPinDirection('C',5,1);
	while(1){
//		unsigned char inp = GetPinValue('C',0);
//		SetPinValue('C',5,inp);

			SetPinValue('A',5,1);
			_delay_ms(1000);
			SetPinValue('A',5,0);
			_delay_ms(1000);

	}



}
