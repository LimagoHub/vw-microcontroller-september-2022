/*
 * Polling.c
 *
 * Created: 30.07.2022 17:26:38
 * Author : JoachimWagner
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>



#define SET_BIT(BYTE,BIT) BYTE|=(1<<BIT)

int main(void)
{
	DDRD = 0b00000000;
	DDRB = 0b00000001;
	PORTD = 0b00001100; // Pull-up Widerstand schalten
	PORTB &= ~(1 << PB0);
	
	while (1)
	{
		
		if(! (PIND & (1 << PIND2))) {
			PORTB |= (1 << PB0);
			
		}
		if(! (PIND & (1 << PIND3))) {
			PORTB &= ~(1 << PB0);
		}
		
	}
}

