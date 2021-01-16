/*	Author: Jessie Lu
 *  Partner(s) Name: 
 *	Lab Section: 23
 *	Assignment: Lab #3  Exercise #5
 *	Exercise Description: Airbag enabler depends on weight sensor. 
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	DDRD = 0x00; PORTD = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;

	unsigned char D = 0x00;
	unsigned char B = 0x00;
	unsigned char B1 = 0x00;
	unsigned char B2 = 0x00;
	unsigned char tmp = 0x00;

    	while (1) {
		
		B = PINB & 0xFF;
		D = PIND & 0xFF;

		if (B == 0x00) {
			tmp = D;
		}
		else {
			tmp = (D << 1) | B;
		}
		
		// if weight > 70 then PB1 is 1
		// if weight < 5 B1 and B2 should be set
		if (tmp >= 0x05) {
		//if (D >= 0x05 || ((D << 1) | B) >= 5) {
			if (tmp >= 0x46) {
			//if (D >= 0x46 || ((D << 1) | B) >= 0x46) {
				B1 = 0x02;
			}

			// if 5 < weight < 70 then PB2 is 1
			else if (tmp > 0x05 && tmp < 0x46) {
			//else if ((D > 0x05 && D < 0x46) || (((D << 1) | B > 0x05) &&((D << 1) | B) < 0x46)) {
				B2 = 0x04;
			}

			else {
				B2 = 0x00;
			}
		}
		else {
			B1 = 0x00;
			B2 = 0x00;
		}
		

		PORTB = B2 | B1;
    	}
    	return 0;
}
