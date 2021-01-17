/*	Author: Jessie Lu
 *  Partner(s) Name: 
 *	Lab Section: 23
 *	Assignment: Lab #3  Exercise #4
 *	Exercise Description: Takes upper nibble of PINA and maps it to lower nibble of PORTB. Takes lower nibble of PINA and maps it to upper nibble of PORTC. 
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char B = 0x00;
	unsigned char C = 0x00;

    	while (1) {
		
		// get upper nibble of PINA to B 
		// get lower nibble of PINA to C
		B = PINA & 0xF0;
		C = PINA & 0x0F;

		// shift B to the right 4 so it's the lower nibble
		B = (B >> 4);
		// shift C to the left 4 so it's the upper nibble
		C = (C << 4);

		PORTB = B;
		PORTC = C;
    	}
    	return 0;
}
