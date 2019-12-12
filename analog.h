/*
 * analog.h
 *
 *  Created on: Nov 29, 2019
 *      Author: Aji sasongko
 */

#ifndef ANALOG_H_
#define ANALOG_H_


#include<avr/io.h>
unsigned int ADCIN (unsigned char channel);
void ADCInit(void);
uint16_t ReadADC(uint8_t channel,uint8_t tipe);
uint16_t dataADC;


#endif /* ANALOG_H_ */
