/*
 * lauflicht.c
 *
 * Created: 09.09.2022 12:36:52
 *  Author: JoachimWagner
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>
#include "lauflicht.h"


static void bitshift_operation(uint8_t muster, uint8_t richtung) {
	for(uint8_t i = 0; i < 8 ; i ++) {
		uint8_t weite = richtung != 0?8-i:i;
		PORTB = (muster << weite);
		_delay_ms(64);
	}
}

void lauflicht_init() {
	DDRB = 255;
	PORTB = 0;
}

void lauflicht_animiere(uint8_t muster) {
	
	bitshift_operation(muster, 1);
	bitshift_operation(muster, 0);
	
}
