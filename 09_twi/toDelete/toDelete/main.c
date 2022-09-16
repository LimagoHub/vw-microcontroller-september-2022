/*
 * toDelete.c
 *
 * Created: 16.09.2022 10:35:09
 * Author : JoachimWagner
 */ 

#include <avr/io.h>
#include "i2c.h"
#include <util/delay.h>
int main(void)
{
	DDRA = 0xFF;
	i2c_init();
	i2c_start();
	i2c_write(0x4E);
	while (1)
	{
		i2c_write(0x55);
		_delay_ms(1000);
		i2c_write(0xAA);
		_delay_ms(1000);
	}
}


