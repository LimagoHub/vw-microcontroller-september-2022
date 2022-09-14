/*
 * TWIMasterProjekt.c
 *
 * Created: 30.12.2018 11:08:37
 * Author : jowag
 */ 

 #ifndef F_CPU
 #define F_CPU 16000000UL
 #endif


#include <avr/io.h>
#include <util/delay.h>
#include "wire.h"
#include "serial.h"




static inline void setup();
static inline void mainloop();


static inline void setup(){
	serial_init(BAUD_9600);
	serial_puts("Start\r\n");
	wire_begin();
	
}

static inline void mainloop(){
	wire_requestFrom(8, 6);    // request 6 bytes from slave device #8
	
	while (wire_available()) { // slave may send less than requested
		char c = wire_read(); // receive a byte as character
		serial_putc(c);         // print the character
	}

	_delay_ms(500);
}


int main(void)
{
	setup();
    while (1) 
    {
		mainloop();
    }
}

