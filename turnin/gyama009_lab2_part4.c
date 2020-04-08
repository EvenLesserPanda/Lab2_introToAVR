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
#include <stdlib.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0x00; PORTB = 0xFF; // Configure port B's 8 pins as inputs
	DDRC = 0x00; PORTC = 0xFF; // Configure port C's 8 pins as inputs
	DDRD = 0xFF; PORTD = 0x00; // Configure port D's 8 pins as outputs
	// unsigned char holdchar = 0x00; // Holding the exact weight
	unsigned short holdchar = 0x0000;
	unsigned short tempweight = 0x0000; // Holding the temp weight
	while(1){
		holdchar = PINA + PINB + PINC;
		//if((PINA + PINB + PINC) >= 512){
		if(holdchar >= 512){
			//holdchar = (PINA + PINB + PINC) - 512;
			holdchar -= 512;
			tempweight += 0x0200;
		}
		if(holdchar >= 256){
			holdchar -= 256;
			tempweight += 0x0100;
		}
		if(holdchar >= 128){
			holdchar -= 128;
			tempweight += 0x0080;
		}
		if(holdchar >= 64){
			holdchar -= 64;
			tempweight += 0x0040;
		}
		if(holdchar >= 32){
			holdchar -=32;
			tempweight += 0x0020;
		}
		if(holdchar >= 16){
			holdchar -= 16;
			tempweight += 0x0010;
		}
		if(holdchar >= 8){
			holdchar -= 8;
			tempweight += 0x0008;
		}
		if(holdchar >= 4){
			holdchar -= 4;
			tempweight += 0x0004;
		}
		if(holdchar >= 2){
			holdchar -= 2;
			tempweight += 0x0002;
		}
		if(holdchar >= 1){
			holdchar -= 1;
			tempweight += 0x0001;
		}
		if((PINA + PINB + PINC) > 140){
			PORTD += 0x01;
		}
		if(abs(PINA - PINC) > 80){
			PORTD += 0x02;
		}
		PORTD += ((tempweight >> 4) & 0x00FC);
	}
	return 0;
}
