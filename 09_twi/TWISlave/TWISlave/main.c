/*
 * ATmega32_Slave.c
 * http://www.electronicwings.com
 *
 */ 


#define F_CPU 8000000UL							/* Define CPU clock Frequency e.g. here its 8MHz */
#include <avr/io.h>								/* Include AVR std. library file */
#include <util/delay.h>							/* Include inbuilt defined Delay header file */
#include <stdio.h>								/* Include standard I/O header file */
#include <string.h>								/* Include string header file */
#include "usart.h"					/* Include LCD header file */
#include "I2C_Slave_H_File.h"					/* Include I2C slave header file */
#include "stdlib.h"
#define Slave_Address			0x20

int main(void)
{
	char buffer[10];
	int8_t count = 0;
	
	usart_Init();
	I2C_Slave_Init(Slave_Address);
	
	usart_sendStringNewLine( "Slave Device");
	
	while (1)
	{
		switch(I2C_Slave_Listen())				/* Check for any SLA+W or SLA+R */
		{
			case 0:
			{
				usart_sendStringNewLine( "Receiving :       ");
				do
				{
					itoa( count,buffer,10);
					usart_sendStringNewLine( buffer);
					count = I2C_Slave_Receive();/* Receive data byte*/
				} while (count != -1);			/* Receive until STOP/REPEATED START received */
				count = 0;
				break;
			}
			case 1:
			{
				int8_t Ack_status;
				usart_sendStringNewLine( "Sending :       ");
				do
				{
					Ack_status = I2C_Slave_Transmit(count);	/* Send data byte */
					itoa( count,buffer,10);
					usart_sendStringNewLine(buffer);
					count++;
				} while (Ack_status == 0);		/* Send until Acknowledgment is received */
				break;
			}
			default:
				break;
		}
	}
}

