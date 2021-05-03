/*	Author: Evan Hsu
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab 7  Exercise 4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	Video Link:
 *
 * 	Confusion regarding part 2, 3, & 4: Part 4 complies with my 
 * 	understanding in part 2, so I was planning on using the max
 * 	from part 2, but this would barely light the B7, so I decreased the max.
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
    /* Insert your solution below */
	ADC_init();
	unsigned static short ADC_max = 0x020F;
	unsigned char dividedADC = ADC_max / 8;
       	signed short tmpADC;
	unsigned char count = 0;
	unsigned char i;
    while (1) {
	PORTB = 0x00;
	count = 0;
        tmpADC = ADC;
	tmpADC -= dividedADC;

	while (tmpADC > 0) {
		tmpADC -= dividedADC;
		count++;
	}

	for (i = 0; i < count; ++i) {
		PORTB = PORTB << 1;
		PORTB++;
	}
    }
    return 1;
}
