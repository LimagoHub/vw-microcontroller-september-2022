/*
 * i2c.h
 *
 * Created: 16.09.2022 10:36:51
 *  Author: JoachimWagner
 */ 


#ifndef I2C_H_
#define I2C_H_


/* HEADER-Datei für den I2C-Bus
*	Autor
*	Datum
*/
#define F_CPU 8000000UL
#include <avr/io.h>
void i2c_init()
{
	TWSR = 0x00;
	TWBR = 0x08;
	TWCR = (1<<TWEN);
}
void i2c_start()
{
	TWCR	=(1<<TWINT) | (1<<TWEN) | (1<<TWSTA);
	while (!(TWCR & (1<<TWINT)));
}
void i2c_write(char x)
{
	TWDR = x;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
}
char i2c_read()
{
	TWCR = (1<<TWEN) | (1<<TWINT);
	while (!(TWCR & (1<<TWINT)));
	return TWDR;
}



#endif /* I2C_H_ */