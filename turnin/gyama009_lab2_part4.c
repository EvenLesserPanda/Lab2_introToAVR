/*	Author: gyama009
 *  Partner(s) Name: 
 *	Lab Section:022
 *	Assignment: Lab #2  Exercise #4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#include <stdlib.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0x00; PORTB = 0xFF; // Configure port B's 8 pins as inputs
	DDRC = 0x00; PORTC = 0xFF; // Configure port C's 8 pins as inputs
	DDRD = 0xFF; PORTD = 0x00; // Configure port D's 8 pins as outputs
	unsigned char tempweight = 0x00; // Holding the temp weight
	while(1){
		tempweight = PINA + PINB + PINC;
		PORTD = tempweight;
		if(PINA + PINB + PINC > 140){
			tempweight = (tempweight & 0xFE) + 0x01;
		}
		if(abs(PINA - PINC) > 80){
			tempweight = (tempweight & 0xFD) + 0x02;
		}
		PORTD = tempweight;
	}
	return 0;
}
