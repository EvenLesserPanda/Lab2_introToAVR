/*	Author: gyama009
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
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
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs
	unsigned char full = 0x00; // Temporary variable to hold if full
	unsigned char cntavail = 0x00; // Temporary variable to hold # of taken spots
	while(1){
		cntavail = ((PINA & 0x08) >> 3) + ((PINA & 0x04) >> 2) + ((PINA & 0x02) >> 1) + (PINA & 0x01);
		full = ((PINA & 0x08) >> 3) & ((PINA & 0x04) >> 2) & ((PINA & 0x02) >> 1) & (PINA & 0x01);
		PORTC = (full << 7) + 4 - cntavail;
	}
	return 0;
}
