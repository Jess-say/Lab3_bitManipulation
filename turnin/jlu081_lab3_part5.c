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

	unsigned char B1 = 0x00;
	unsigned char tmp = 0x00;

    	while (1) {
		
		tmp = 0x00;
		B1 = 0x00;

		// B0 is 0
		if (PINB == 0x00) {
	  		// if PIND > 70 then just set B1 to 1		
			if (PIND >= 0x46) { 
				tmp = PIND;
				B1 = 0x02;
			}	
			else { 
				// shift PIND 1 to the right and add in B0
				tmp = (PIND << 1) | 0x00;
				// if 5 < tmp < 70
			       	if (tmp > 0x05 && tmp < 0x46) {
					B1 = 0x04;
				}
				// if tmp > 70
				else if (tmp >= 0x46) {
					B1 = 0x02;
				}
				// if neither
				else { 
					B1 = 0x00;
				}	
			}
		}
		// if B0 is 1
		else  { 
			if (PIND >= 0x46) { 
				tmp = PIND; 
				B1 = 0x02;
			}
			else {
				tmp = (PIND << 1) | 0x01; 
				if (tmp > 0x05 && tmp < 0x46) {
					B1 = 0x04;
				}
				else if (tmp >= 0x46) {
					B1 = 0x02;
				}
				else {
					B1 = 0x00;
				}
			}
		}

		PORTB = B1;
    	}
    	return 0;
}
