/*
 * ATmega16_Master_I2C.c
 * http://www.electronicwings.com
 */ 


#define F_CPU 8000000UL						/* Define CPU clock Frequency e.g. here its 8MHz */
#include <avr/io.h>							/* Include AVR std. library file */
#include <util/delay.h>						/* Include inbuilt defined Delay header file */
#include <string.h>							/* Include string header file */
#include "I2C_Master_H_file.h"				/* Include I2C header file */
#include "usart.h"
#include <stdlib.h>
				/* Include LCD header file */

#define Slave_Write_Address		0x20
#define Slave_Read_Address		0x21
#define	count				10
int main()
{
	char buffer[10];
	
	usart_Init();			/* Initialize LCD */
	I2C_Init();			/* Initialize I2C */
	
	usart_sendStringNewLine( "Master Device");
	
	while (1)
	{
		usart_sendStringNewLine(  "Sending :       ");
		I2C_Start_Wait(Slave_Write_Address);/* Start I2C with SLA+W */
		_delay_ms(5);
		for (uint8_t i = 0; i < count ; i++)
		{
			//sprintf(buffer, "%d    ",i);
			itoa(i,buffer,10);
			usart_sendStringNewLine( buffer);
			I2C_Write(i);	/* Send Incrementing count */
			_delay_ms(500);
		}
		usart_sendStringNewLine(  "Receiving :       ");
		I2C_Repeated_Start(Slave_Read_Address);/* Repeated Start with SLA+R */
		_delay_ms(5);
		for (uint8_t i = 0; i < count; i++)
		{
			if(i < count - 1)
				itoa(I2C_Read_Ack(),buffer,10);
			
			else
				itoa(I2C_Read_Nack(),buffer,10);
			usart_sendStringNewLine(  buffer);
			_delay_ms(500);
		}
		I2C_Stop();		/* Stop I2C */
	}
}