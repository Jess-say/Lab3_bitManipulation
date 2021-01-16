/*	Author: Jessie Lu
 *  Partner(s) Name: 
 *	Lab Section: 23
 *	Assignment: Lab #3  Exercise #1
 *	Exercise Description: Outputs how many numbers of 1 on ports A and B.
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned char GetBit(unsigned char x, unsigned char y) {
	if ((x & (0x01 << y)) != 0)
		return 1;
	else 
		return 0;
	//return ((x & (0x01 << y)) != 0);
}

int main(void) {
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char cnt = 0x00;
	unsigned char A = 0x00;
	unsigned char B = 0x00;
	unsigned char i;
    	while (1) {
		cnt = 0;
		A = PINA & 0xFF; B = PINB & 0xFF; 
		for (i = 0; i < 8; i++) {
			// if i-th bit at A is 1
			if (GetBit(A, i) == 1) {
				cnt = cnt + 1;
			}

			// if i-th bit at B is 1
			if (GetBit(B, i) == 1) {
				cnt = cnt + 1;
			}
		}
		PORTC = cnt;
    	}
    	return 0;
}
