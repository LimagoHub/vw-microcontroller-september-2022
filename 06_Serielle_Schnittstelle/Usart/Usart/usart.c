/*
 * usart.c
 *
 * Created: 17.12.2021 09:57:41
 *  Author: JoachimWagner
 */ 
#include "usart.h"



void usart_Init() { // 1000 wird übergeben
	
	
	/*Set baud rate */
	UBRRH = (MYUBRR >> 8);
	UBRRL = MYUBRR;
	
	UCSRB |= (1 << RXEN) | (1 << TXEN);      // Enable receiver and transmitter
	UCSRB |= (1 << RXCIE);                    // Enable reciever interrupt
	UCSRC |= (1 << UCSZ1) | (1 << UCSZ0) | (1 << URSEL);    // Set frame: 8data, 1 stp

	
}

void usart_sendChar(char value) {
	
	while(! (UCSRA & (1 << UDRE)));// warten bis Sendepuffer leer ist 
	UDR = value; // sendet das Byte
}

void usart_sendString(char *message) {
	while(*message)
	usart_sendChar(*message ++);
}

void usart_sendStringNewLine(char *message) {
	usart_sendString(message);
	usart_sendString("\r\n");
}


