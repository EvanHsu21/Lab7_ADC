/*	Author: Evan Hsu
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab 7  Exercise 2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	Video Link:
 *
 * 	Explanation of MAX value: The MAX ADC value displayed when the 
 * 	photoresistor is exposed to light is a rather finicky number. When the
 * 	light is at a certain angle, the ADC value can be 0xFFFF. Most of the 
 * 	time receiving light results in upwards of 0x8000 or 0xC000.
 *
 *	I acknowledge all content contained herein, excluding template or
 *	example code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE) ;
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
    /* Insert your solution below */
	ADC_init();
	unsigned short ADC_result;
	unsigned char bottomEight;
	unsigned char topTwo;
    while (1) {
	ADC_result = ADC;
	bottomEight = (char) (ADC_result & 0x00FF);
	topTwo = (char) ((ADC_result & 0x0300) >> 8);
	PORTB = bottomEight;
	PORTD = topTwo;
    }
    return 1;
}
