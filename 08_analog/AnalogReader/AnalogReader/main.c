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
#include "pwm.h"


void setup() {
	 usart_Init();
	 ADC_Init();
	 pwm_init(PRESCALE_1024);
}

void mainloop() {
	int8_t luefter_stufe = (int8_t) (ADC_Read(0) * 0.0058f); // Sensor 1 lesen
	uint16_t aussentemperatur = ADC_Read(1);	// Sensor 2 lesen
	
	if( aussentemperatur < 200)
	luefter_stufe --;
	
	if( aussentemperatur > 900)
	luefter_stufe ++;
	
	// Stufe ggf. korrigieren
	if(luefter_stufe < 0)
	luefter_stufe = 0;
	
	if(luefter_stufe > 5)
	luefter_stufe = 5;
	
	
	pwm_set_duty(luefter_stufe * 51);
}

int main(void)
{
   
   setup();
	
	
    while (1) 
    {
		mainloop();
		
		
	
		
    }
}

