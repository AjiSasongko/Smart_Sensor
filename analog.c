/*
 * analog.c
 *
 *  Created on: Nov 29, 2019
 *      Author: Aji sasongko
 */


#include "analog.h"
#include <avr/io.h>
#include <util/delay.h>

uint8_t channel;
uint16_t dataADC;

void ADCInit(void)
{
	ADCSRA|=(1<<ADPS2)|(1<<ADPS1); //setting prescaller
	ADMUX &=~(1<<ADLAR); //configure 8 bit data from ADCH
	ADMUX |=(1<<REFS0)|channel; //get ref from VCC & activate channel 0
	ADCSRA|=(1<<ADEN);	//enable ADC
}
uint16_t ReadADC(uint8_t channel, uint8_t tipe)
{
	ADMUX &= ~(0x1F); //reset bit 0-4 ADMUX
	ADMUX |= channel; //mengakses data dari channel analog yang dipilih
	ADCSRA|= (1<<ADSC);
	while(!(ADCSRA&(1<<ADIF)));
	ADCSRA |= (1<<ADIF);
	uint8_t result;

	if (tipe=='low')
	{
		result = ADCL;
	}
	else if (tipe=='high')
	{
		result = ADCH;
	}
	return result;
}


