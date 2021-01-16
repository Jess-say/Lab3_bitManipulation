/*	Author: Jessie Lu
 *  Partner(s) Name: 
 *	Lab Section: 23
 *	Assignment: Lab #3  Exercise #2
 *	Exercise Description: Outputs Indicates low fuel level depending on values PA3-PA0.
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
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char A = 0x00;
	unsigned char C = 0x00;
    	while (1) {
		
		A = PINA & 0xFF; 
	 	C = 0x00;

		// PA3-PA0 holds values from 0-15
		// if fuel level is 1 or 2 PC5 lights
		if (A == 0x01 || A == 0x02) {
			C = 0x20 | 0x40; // 0110 0000 and PC6 lights
		}
		// if fuel level is 3 or 4 
		else if (A == 0x03 || A == 0x04) {
			C = 0x30 | 0x40; // 0011 0000 and PC6 lights
		}
		// if fuel is 5 or 6 
		else if (A == 0x05 || A == 0x06) {
			C = 0x38; // 0011 1000
		}
		// if fuel is 7-9
		else if (A >= 0x07 && A <= 0x09) {
			C = 0x3C; // 0011 1100
		}
		// if fuel is 10-12
		else if (A >= 0x0A && A <= 0x0C) {
		       C = 0x3E; // 0011 1110
		}
		else {
			C = 0x3F; // 0011 1111
		}

		PORTC = C;
    	}
    	return 0;
}
