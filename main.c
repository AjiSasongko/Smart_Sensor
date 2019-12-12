/*
 * main.c
 *
 *  Created on: Nov 29, 2019
 *      Author: Aji sasongko
 */


#include <avr/io.h>
#include <util/delay.h>
#include "analog.h"
//#include "spi.h"
#include <stdio.h>
//#define DDR_SPI DDRB
//#define DD_SS DDB0
//#define DD_SCK DDB1
//#define DD_MOSI DDB2
//#define DD_MISO DDB3

int data;
uint16_t nilaiSensor0, nilaiSensor1, nilaiSensor2;
uint16_t light [2]= {1023,1023,1023};
uint16_t dark [2]= {0,0,0};
uint16_t treshold[2]= {};
void calibrateall (void)
{
	nilaiSensor0=ReadADC(0,'low')+ReadADC(0,'high');
	nilaiSensor1=ReadADC(1,'low')+ReadADC(1,'high');
	nilaiSensor2=ReadADC(2,'low')+ReadADC(2,'high');


	if (nilaiSensor0<light[0])
	{
		light[0]=nilaiSensor0;
		treshold[0] = (dark[0]+light[0])/2;
	}
	if (nilaiSensor1<light[1])
	{
		light[1]=nilaiSensor1;
		treshold[1] = (dark[1]+light[1])/2;
	}
	if (nilaiSensor2<light[2])
	{
		light[2]=nilaiSensor2;
		treshold[2] = (dark[2]+light[2])/2;
	}
	if (nilaiSensor0>dark[0])
	{
		dark[0]=nilaiSensor0;
		treshold[0] = (dark[0]+light[0])/2;
	}
	if (nilaiSensor1>dark[1])
	{
		dark[1]=nilaiSensor1;
		treshold[1] = (dark[1]+light[1])/2;
	}
	if (nilaiSensor2>dark[2])
	{
		dark[2]=nilaiSensor2;
		treshold[2] = (dark[2]+light[2])/2;
	}
}
void calibratesS2(void)
{
	if (nilaiSensor2<light[2])
	{
		light[2]=nilaiSensor2;
		treshold[2] = (dark[2]+light[2])/2;
	}
	if (nilaiSensor2>dark[2])
	{
		dark[2]=nilaiSensor2;
		treshold[2] = (dark[2]+light[2])/2;
	}
}

int main( void) {
	ADCInit();
	DDRA=0xFF; //port A as output
	PORTA=0xFF; //reset all port A
	//SPI_SlaveInit();

	while (1) {
		//sprintf(str, "adc_read = %d \r",dataADC);
		//PORTA=~SPI_SlaveReceive(0x0F);
	}
}
