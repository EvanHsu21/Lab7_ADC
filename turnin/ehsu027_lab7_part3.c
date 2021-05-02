/*	Author: Evan Hsu
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab 7  Exercise 3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	Video Link:
 *
 * 	Confusion regarding lab manual: In part 2, the lab manual states that
 * 	the MAX is reflective of when the photoresistor is exposed to light. 
 * 	I assumed this referred to the max ADC value that could be output 
 * 	when receiving light (e.g flashlight at optimal angle).
 *
 * 	Assuming I understand this correctly, part 3 requires that natural 
 * 	lighting be considered the max ADC value.
 *
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
	unsigned static short ADC_max = 0x00C0;
    while (1) {
	ADC_result = ADC;
	if (ADC_result >= (ADC_max / 2)) {
		PORTB = 0x0001;
	}
	else if (ADC_result < (ADC_max / 2)) {
		PORTB = 0x0000;
	}
    }
    return 1;
}
