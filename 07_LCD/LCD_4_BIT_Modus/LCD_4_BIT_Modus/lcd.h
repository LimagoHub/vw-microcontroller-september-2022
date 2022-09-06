/*
 * lcd.h
 *
 * Created: 06.09.2022 08:12:08
 *  Author: JoachimWagner
 */ 


#ifndef LCD_H_
#define LCD_H_

	#ifndef F_CPU
	#define F_CPU 8000000UL
	#endif


	#include <avr/io.h>
	#include <util/delay.h>


	#define LCD_DDR DDRD
	#define LCD_PORT PORTD
	#define RS  2
	#define E   3
	#define DB4 4
	#define DB5 5
	#define DB6 6
	#define DB7 7

	#define FOURBIT_MODE 0b00100000

	#define TWO_LINES 0b00101000
	#define INSERT_MODE 0b00000110
	#define OFF 0b00001000
	#define CLEAR 0b00000001
	#define ON 0b00001110
	#define CURSOR_HOME 0x02

	void lcd_enable(void);
	void lcd_putc ( volatile uint8_t c );
	void lcd_puts ( char * s );
	void lcd_command ( uint8_t cmd );
	void lcd_init(void);
	void lcd_clear(void);
	void lcd_home(void);
	void set_cursor(uint8_t x, uint8_t y);

	




#endif /* LCD_H_ */