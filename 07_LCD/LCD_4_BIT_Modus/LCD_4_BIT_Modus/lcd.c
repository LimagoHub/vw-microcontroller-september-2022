/*
 * lcd.c
 *
 * Created: 06.09.2022 08:13:34
 *  Author: JoachimWagner
 */ 
#include "lcd.h"

void lcd_enable(void)
{

	LCD_PORT |= (1<< E);
	_delay_ms(1);
	LCD_PORT &= ~(1<< E);
}

void lcd_puts ( char * s ) {

	
	while (*s)
	lcd_putc(*s++);

}


static void lcd_send_c(uint8_t c , uint8_t rs) {

	uint8_t high_nibble = c & 0xf0;
	uint8_t low_nibble = (c << 4) & 0xf0;
	
	LCD_PORT = high_nibble | (rs == 0 ? 0 : (1 << RS));
	lcd_enable();
	LCD_PORT = low_nibble |  (rs == 0 ? 0 : (1 << RS));
	lcd_enable();
	_delay_ms(2);

}

void lcd_putc ( uint8_t c ) {

	lcd_send_c( c, 1);

}



void lcd_command ( uint8_t cmd ) {

	lcd_send_c( cmd, 0);

}

void lcd_clear () {

	lcd_command(CLEAR);
	_delay_ms(5);

}



void lcd_init() {

	LCD_DDR =  (1 << RS) | (1 << E) | (1 << DB4) | (1 << DB5) | (1 << DB6) | (1 << DB7);
	_delay_ms(50);

	LCD_PORT = 0b00110000;
	
	lcd_enable();
	_delay_ms(15);

	lcd_enable();
	_delay_us(100);

	lcd_enable();
	
	LCD_PORT = FOURBIT_MODE;
	lcd_enable();
	_delay_ms(1);

	lcd_command( TWO_LINES);
	lcd_command( INSERT_MODE);
	lcd_command( OFF);
	lcd_command( CLEAR );
	_delay_ms(5);
	lcd_command( ON);


	
}



void lcd_home(void)
{
	lcd_command(CURSOR_HOME);
	_delay_ms(5);
}


void set_cursor(uint8_t x, uint8_t y)
{
	uint8_t tmp;

	if ( x > 0x0f || y > 1) return;

	if( y) {
		tmp=0x80+0x40+x ;
		} else {
		tmp=0x80+0x00+x;
	}



	lcd_command(tmp);
}
