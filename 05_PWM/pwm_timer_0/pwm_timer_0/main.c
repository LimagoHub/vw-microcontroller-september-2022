/*
 * pwm_timer_0.c
 *
 * Created: 02.08.2022 08:11:01
 * Author : JoachimWagner
 */ 

#define F_CPU 8000000UL
#include "avr/io.h"
#include <util/delay.h>
#include "pwm.h"




int main ()
{
	uint8_t duty;
	
	pwm_init(NO_PRESCALING);
	
	while (1)
	{
		
		
		for(duty=0; duty<255; duty++)
		{
			pwm_set_duty(duty);
			_delay_ms(8);
		}
		for(duty=255; duty>1; duty--)
		{
			pwm_set_duty(duty) ;/*decrease the LED light intensity*/
			_delay_ms(8);
		}
	}
}
