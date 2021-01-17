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
	unsigned char tmp = 0x00;

    	while (1) {
		
		B = PINB & 0xFF;
		D = PIND & 0xFF;
		tmp = 0x00;

		if (B == 0x00) {	      
			if (D > 0x46) { 
				tmp = D;
			}	
			else { 
				tmp = (D << 1) | 0x01; 
			}
		}
		else  { 
			if (tmp > 0x46) { 
				tmp = D; 
			}
			else {
				tmp = (D << 1) | 0x01; 
			}
		}

		// if weight > 70 then PB1 is 1
		// if weight < 5 B1 and B2 should be set
		if (tmp >= 0x05) {
			if (tmp >= 0x46) {
				B1 = 0x02;
			}

			// if 5 < weight < 70 then PB2 is 1
			else {
				B1 = 0x04;
			}

		}
		else {
			B1 = 0x00;
		}

		PORTB = B1;
    	}
    	return 0;
}
