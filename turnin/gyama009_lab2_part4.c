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
	unsigned char holdchar = 0x00;
	unsigned char tempweight = 0x00; // Holding the temp weight
	unsigned char tempA = 0x00; // Holding A
	unsigned char tempB = 0x00; // Holding B
	unsigned char tempC = 0x00; // Holding C
	while(1){
		tempA = PINA & 0xFF;
		tempB = PINB & 0xFF;
		tempC = PINC & 0xFF;
		tempweight = 0x00;
		if((tempA + tempB + tempC) == 0){
			tempweight += 0x00;
		}
		if(((tempA + tempB + tempC) & 0x01) == 0x01){
			tempweight += 0x01;
		}
		if(((tempA + tempB + tempC) & 0x02) == 0x02){
                        tempweight += 0x02;
                }
		if(((tempA + tempB + tempC) & 0x04) == 0x04){
                        tempweight += 0x04;
                }
		if(((tempA + tempB + tempC) & 0x08) == 0x08){
                        tempweight += 0x08;
                }
		if(((tempA + tempB + tempC) & 0x10) == 0x10){
                        tempweight += 0x10;
                }
		if(((tempA + tempB + tempC) & 0x20) == 0x20){
                        tempweight += 0x20;
                }
		if(((tempA + tempB + tempC) & 0x40) == 0x40){
                        tempweight += 0x40;
                }
		if(((tempA + tempB + tempC) & 0x80) == 0x80){
                        tempweight += 0x80;
                }
		if((tempA + tempB + tempC) > 140){
			PORTD += 0x01;
		}	
		if(abs(tempA - tempC) > 80){
			PORTD += 0x02;
		}
		PORTD += (tempweight & 0xFC);
	}
	return 0;
}
