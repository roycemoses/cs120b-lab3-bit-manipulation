/*	Author: rmose005
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #3  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs, initalize to 1s.
	DDRB = 0x00; PORTB = 0xFF; // ""B
	DDRC = 0xFF; PORTC = 0x00; // Configure port B's 8 pins as outputs, initalize to 0s.
   	
	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
	unsigned char count = 0x00;
	unsigned char i = 0x00;
    /* Insert your solution below */
    while (1) {
	// 1) Read input
	tmpA = PINA;
	tmpB = PINB;
	count = 0;
	
	// 2) Perform computation	
	for (i = 0; i < 8; ++i)
	{
		if ((tmpA & 0x01) == 1)
			++count;
		tmpA = tmpA >> 1;
	}

	for (i = 0; i < 8; ++i)
	{
		if ((tmpB & 0x01) == 1)
			++count;
		tmpB = tmpB >> 1;
	}
	
	// 3) Write output
	PORTC = count;
	
    }
    return 1;
}
