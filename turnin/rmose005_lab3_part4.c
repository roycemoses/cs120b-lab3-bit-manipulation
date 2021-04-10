/*	Author: rmose005
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #3  Exercise #4
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
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initalize to 0s.
	DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs, initalize to 0s.
   	
    /* Insert your solution below */
    while (1) {
	// 1) Read input
	// 2) Perform computation	
	// 3) Write output
	PORTB = (PINA & 0xF0) >> 4; // Take upper nibble of A and map it to the lower nibble of B
	PORTC = (PINA & 0x0F) << 4; // Take lower nibble of A and map it to the upper nibble of C
    }
    return 1;
}
