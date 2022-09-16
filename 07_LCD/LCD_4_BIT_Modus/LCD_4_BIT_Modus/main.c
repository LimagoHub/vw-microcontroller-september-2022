/*
 * LCD_4_BIT_Modus.c
 *
 * Created: 06.09.2022 08:08:52
 * Author : JoachimWagner
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include "lcd.h"

int main(void)
{
    lcd_init();
	lcd_puts("Hallo");
    while (1) 
    {
		lcd_puts("Welt");
		_delay_ms(1000);
		lcd_command(CLEAR);
		lcd_puts("Hallo");
		_delay_ms(1000);
		lcd_command(CLEAR);
    }
}

