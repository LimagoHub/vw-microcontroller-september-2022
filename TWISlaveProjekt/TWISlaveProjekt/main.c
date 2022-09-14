/*
 * TWISlaveProjekt.c
 *
 * Created: 02.01.2019 10:54:18
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

void requestEvent() {
	wire_write('H');
	wire_write('a');
	wire_write('l');
	wire_write('l');
	wire_write('o');
	wire_write(' ');
}

 static inline void setup(){
	 serial_init(BAUD_9600);
	 serial_puts("Start Slave\r\n");
	 wire_beginSlaveMode(8);
	 wire_onRequest(requestEvent);
 }

 static inline void mainloop(){
	 

	 _delay_ms(100);
 }


 int main(void)
 {
	 setup();
	 while (1)
	 {
		 mainloop();
	 }
 }

