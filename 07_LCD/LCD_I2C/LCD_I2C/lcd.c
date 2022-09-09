/*
 * lcd.c
 *
 * Created: 06.09.2022 08:13:34
 *  Author: JoachimWagner
 */ 
#include "lcd.h"
#include "wire.h"



void LiquidCrystal_I2C_send(uint8_t value, uint8_t mode);

void LiquidCrystal_I2C_write4bits(uint8_t value);

void LiquidCrystal_I2C_expanderWrite(uint8_t _data);

void LiquidCrystal_I2C_pulseEnable(uint8_t _data);





void lcd_puts ( char * s ) {

	
	while (*s)
	lcd_putc(*s++);

}


static void lcd_send_c(uint8_t c , uint8_t rs) {


	LiquidCrystal_I2C_send(c,rs);
	

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
	
	
	
	_delay_ms(50);
	
	// Now we pull both RS and R/W low to begin commands
	LiquidCrystal_I2C_expanderWrite(0b10000000);	// reset expanderand turn backlight off (Bit 8 =1)
	_delay_ms(1000);

	//put the LCD into 4 bit mode
	// this is according to the hitachi HD44780 datasheet
	// figure 24, pg 46
	
	// we start in 8bit mode, try to set 4 bit mode
	LiquidCrystal_I2C_write4bits(0x03 << 4);
	_delay_us(4500); // wait min 4.1ms
	
	// second try
	LiquidCrystal_I2C_write4bits(0x03 << 4);
	_delay_us(4500); // wait min 4.1ms
	
	// third go!
	LiquidCrystal_I2C_write4bits(0x03 << 4);
	_delay_us(150);
	
	// finally, set to 4-bit interface
	LiquidCrystal_I2C_write4bits(0x02 << 4);

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

void LiquidCrystal_I2C_send(uint8_t value, uint8_t mode) {
	uint8_t highnib=value&0xf0;
	uint8_t lownib=(value<<4)&0xf0;
	LiquidCrystal_I2C_write4bits((highnib)|mode);
	LiquidCrystal_I2C_write4bits((lownib)|mode);
}

void LiquidCrystal_I2C_write4bits(uint8_t value) {
	LiquidCrystal_I2C_expanderWrite(value);
	LiquidCrystal_I2C_pulseEnable(value);
}

void LiquidCrystal_I2C_expanderWrite(uint8_t _data){
	wire_beginTransmission(I2C_ADRESSE);
	wire_write(_data );
	wire_endTransmission();
}

void LiquidCrystal_I2C_pulseEnable(uint8_t _data){
	LiquidCrystal_I2C_expanderWrite(_data | E);	// En high
	_delay_us(1);		// enable pulse must be >450ns
	
	LiquidCrystal_I2C_expanderWrite(_data & ~E);	// En low
	_delay_us(50);		// commands need > 37us to settle
}
