/*	Author: Jessie Lu
 *  Partner(s) Name: 
 *	Lab Section: 23
 *	Assignment: Lab #3  Exercise #3
 *	Exercise Description: Continues from exercise 2. Add extra inputs for key is in ignition, driver is seated, driver's seatbelt is fastened. PC7 should light if key is in ignition, driver is seated but belt isn't fastened.
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
		A = PINA & 0xF0; 
	 	C = 0x00;

		// if key is in ignition. driver seated but belt not fastened
		if (A == 0x30) {
			C = 0x80;
		}

		A = PINA & 0x0F;

		// PA3-PA0 holds values from 0-15
		// if fuel level is 1 or 2 PC5 lights
		if (A == 0x01 || A == 0x02) {
			C =  C | 0x20 | 0x40;
		}
		// if fuel level is 3 or 4 
		else if (A == 0x03 || A == 0x04) {
			C = C | 0x30 | 0x40; // 0011 0000 and PC6 lights
		}
		// if fuel is 5 or 6 
		else if (A == 0x05 || A == 0x06) {
			C = C | 0x38; // 0011 1000
		}
		// if fuel is 7-9
		else if (A >= 0x07 && A <= 0x09) {
			C = C | 0x3C; // 0011 1100
		}
		// if fuel is 10-12
		else if (A >= 0x0A && A <= 0x0C) {
		       C = C | 0x3E; // 0011 1110
		}
		else if (A >= 0x0D && A <= 0x0F) {
			C = C | 0x3F; // 0011 1111
		}
		else {
			C = 0x40; // if fuel level is 0
		}

		PORTC = C;
    	}
    	return 0;
}
