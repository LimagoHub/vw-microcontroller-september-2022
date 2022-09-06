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

 

int main(void)
{
	
	
	usart_Init();
	
    while (1) 
    {
		for(char c = 'A'; c <= 'Z'; c++){
			usart_sendChar(c);
			
		}
		
	for(char x = 0; x <= 10; x++){
		usart_sendChar(x + '0');
		
	}
		
		usart_sendStringNewLine("");
		_delay_ms(500);
		
		
    }
}

