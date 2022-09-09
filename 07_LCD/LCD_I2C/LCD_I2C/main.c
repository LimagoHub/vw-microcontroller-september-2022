/*
 * LCD_I2C.c
 *
 * Created: 06.09.2022 09:22:35
 * Author : JoachimWagner
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
#include "wire.h"

int main(void)
{
    wire_begin();
	wire_beginTransmission(0x20);
	wire_write( 0);
	wire_write( 0);
	wire_endTransmission();
    while (1)
    {
		
			
			
		wire_beginTransmission(0x20);
		wire_write( 0x12);
		wire_write( 255);
		wire_endTransmission();
    }
}

