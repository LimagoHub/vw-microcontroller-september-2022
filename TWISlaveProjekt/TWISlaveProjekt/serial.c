/*
 * serial.c
 *
 * Created: 29.12.2018 17:54:03
 *  Author: jowag
 */ 
#include "serial.h"

static onreceiveHandler _onreceive;

void serial_init(uint32_t baudrate /*, uint8_t databits, uint8_t stopbits */){
	uint16_t myubrr = (uint16_t) (F_CPU/16/baudrate -1);
	UBRR0H = (myubrr >> 8);
	UBRR0L = myubrr;
	 
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0);      // Enable receiver and transmitter
	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);    // Set frame: 8data, 1 stp
	UCSR0B |= (1 << RXCIE0);                    // Enable receiver interrupt
	
	sei();
}
void serial_putc(volatile char c){
	while ( !(UCSR0A & (1 << UDRE0)) ) {}

	UDR0 = c;
}
void serial_puts(char *message) {
	while (*message) serial_putc(*message++);
}

volatile char serial_getc(){
	while ( !(UCSR0A & (1 << RXC0)) )  {} // Wait until data is received
	
	return UDR0;
}
char * serial_gets(char * buffer){
	return buffer;
}

void serial_onreceive(onreceiveHandler callback){
	_onreceive = callback;
} 

ISR (USART_RX_vect)
{
	_onreceive(UDR0);
	                       
}