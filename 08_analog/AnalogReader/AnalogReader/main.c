/*
 * AnalogReader.c
 *
 * Created: 14.09.2022 07:15:52
 * Author : JoachimWagner
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#include "usart.h"
#include "adc.h"

int main(void)
{
    usart_Init();
	ADC_Init();
	char buffer[10];
	
    while (1) 
    {
		uint16_t messwert = ADC_Read(0);
		itoa(messwert,buffer,10);
		usart_sendString("Channel 0: ");
		usart_sendStringNewLine(buffer);
		
		messwert = ADC_Read(1);
		itoa(messwert,buffer,10);
		usart_sendString("Channel 1: ");
		usart_sendStringNewLine(buffer);
		
    }
}

