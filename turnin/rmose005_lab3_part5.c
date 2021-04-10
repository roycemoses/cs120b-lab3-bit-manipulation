/*	Author: rmose005
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #3  Exercise #5
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
	DDRB = 0xFE; PORTB = 0x01; // Configure port B's last pin as an input, initalize to 1. Configure the rest of port B's pins to outputs PB7..PB1, initialize to 0.
	DDRD = 0x00; PORTD = 0xFF; // Configure port D's 8 pins as inputs, initialize to 1s.

	unsigned short weight = 0x00;   	
	unsigned char tmpB = 0x00;
    /* Insert your solution below */
    while (1) {
	weight = 0;
	tmpB = 0;
	// 1) Read input
	weight = (PIND << 1) | (PINB & 0x01); // Shift D left --> merge with B's last bit.

	// 2) Perform computation
	if (weight >= 70)
		tmpB = tmpB | 0x02; // set PB1 to 1	
	else if (weight > 5 && weight < 70)
		tmpB = tmpB | 0x04; // set PB2 to 1 	

	// 3) Write output
 	PORTB = tmpB;
   }
    return 1;
}
