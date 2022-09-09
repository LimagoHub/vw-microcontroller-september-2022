/*
 * usart.h
 *
 * Created: 17.12.2021 09:55:36
 *  Author: JoachimWagner
 */ 


#ifndef USART_H_
#define USART_H_
#include <avr/io.h>
#include <stdint.h>                     // needed for uint8_t
//#include <stdlib.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL                       // Clock Speed
#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD -1



void usart_sendChar(char value);
void usart_sendString(char *message);
void usart_sendStringNewLine(char *message);
void usart_Init() ;



#endif /* USART_H_ */