/*
 * LedProgramm.c
 *
 * Created: 22.08.2022 13:54:44
 * Author : JoachimWagner
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DDRB |= (1 << DDB0) | (1 << DDB1) | (1 << DDB2);
	PORTB |= (1 << PB1);
	
    while (1) 
    {
		
		// Gelb
		PORTB |= (1 << PB1);
		_delay_ms(500);
		
		// Alle aus
		PORTB &= 11111000;
		
		// Rot
		PORTB |= (1 << PB2);
		_delay_ms(1000);
		
		
		// ROT Gelb
		PORTB |= (1 << PB1);
		_delay_ms(500);
		
		
		// Alle aus
		PORTB &= 11111000;
		
		PORTB &= ~(1 << PB0);
		_delay_ms(1000);
		
		// Alle aus
		PORTB &= 11111000;		
    }
}

