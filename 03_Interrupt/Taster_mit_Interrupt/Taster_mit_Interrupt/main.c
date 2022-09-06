/*
 * Taster_mit_Interrupt.c
 *
 * Created: 31.07.2022 11:39:45
 * Author : JoachimWagner
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

/*Interrupt Service Routine for INT0*/
ISR(INT0_vect)
{
	PORTB=0xFF;	
	
}

ISR(INT1_vect)
{
	PORTB=0;

}


int main(void)
{
	
	DDRB=0xFF;		/* Make PORTB as output PORT*/
	PORTB=0;
	DDRD=0;			/* PORTD as input */
	PORTD=0xFF;		/* Make pull up high */
	
	GICR = (1<<INT0) | (1<<INT1);		/* Enable INT0 und int1*/
	MCUCR = (1<<ISC01)  | (1<<ISC11) ;  /* Trigger INT0 on rising edge */
	
	sei();			/* Enable Global Interrupt */
	// cli();
	
	while(1){}
}
