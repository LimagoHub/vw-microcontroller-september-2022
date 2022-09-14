/*
 * GccApplication1.c
 *
 * Created: 12.09.2022 14:27:37
 * Author : JoachimWagner
 */ 

#include <avr/io.h>
#include "usart.h"
#include "pwm.h"

int main(void)
{
    usart_Init();
	pwm_init();
	
    while (1) 
    {
		char value = usart_receiveChar();
		if(value == 'A') {
			pwm_set_duty(64);
		}
		if(value == 'B') {
			pwm_set_duty(192);
		}
		
		
    }
}

