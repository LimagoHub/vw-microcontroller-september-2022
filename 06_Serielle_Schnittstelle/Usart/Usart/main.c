/*
 * Usart.c
 *
 * Created: 29.07.2022 21:11:00
 * Author : JoachimWagner
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL 
//#include "usart.h"
#include <util/delay.h>
#include "usart.h"
#include <avr/interrupt.h>
 #include <stdlib.h>

int main(void)
{
	
	
	usart_Init();
	sei();
	//uint8_t messwert = 10;
	//
	char buffer[7];
	//itoa(messwert,buffer,10);
	//
	//usart_sendStringNewLine(buffer);
	
	
    while (1) 
    {
		for(int i = 0 ; i <= 10000; i+=1000) {
			itoa(i, buffer, 10);
			usart_sendStringNewLine(buffer);
		}
		_delay_ms(500);
		
    }
}

