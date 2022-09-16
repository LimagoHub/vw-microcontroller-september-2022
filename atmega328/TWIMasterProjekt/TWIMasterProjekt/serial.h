/*
 * serial.h
 *
 * Created: 29.12.2018 17:35:43
 *  Author: jowag
 */ 


#ifndef SERIAL_H_
#define SERIAL_H_
#include <stdint.h>
#include "avr/interrupt.h"

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#define BAUD_9600 9600
#define BAUD_19200 19200
#define BAUD_38400 38400
#define BAUD_57600 57600
#define BAUD_115200 115200

#define DATA_BITS_8 8
#define DATA_BITS_7 7

#define STOP_BITS_1 1
#define STOP_BITS_2 2


typedef void(*onreceiveHandler)(volatile char); 

void serial_init(uint32_t baudrate /*, uint8_t databits, uint8_t stopbits*/);
void serial_putc(char c);
void serial_puts(char *message);
volatile char  serial_getc();
char * serial_gets();
void serial_onreceive(onreceiveHandler);


#endif /* SERIAL_H_ */