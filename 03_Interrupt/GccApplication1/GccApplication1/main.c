

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>



#include <avr/interrupt.h>

ISR (TIMER0_COMP_vect)  // timer0 overflow interrupt
{
	PORTB = ~PORTB;
	
}


int main(void)
{

	DDRB = 0xFF;
	PORTB = 0;

	// Set the Timer Mode to CTC
	TCCR0 |= (1 << WGM01) ;

	// Set the value that you want to count to
	OCR0 = 141; // Kammerton A
	//OCR0A = 117; // ...und C

	TIMSK |= (1 << OCIE0);    //Set the ISR COMPA vect

	TCCR0 |= (1 << CS01) | (1 << CS00) ;
	sei();         //enable interrupts


	


	while (1)
	{
		//main loop
	}
}
