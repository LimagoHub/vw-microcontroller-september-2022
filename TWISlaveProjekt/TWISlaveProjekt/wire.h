/*
 * wire.h
 *
 * Created: 02.01.2019 09:50:48
 *  Author: jowag
 */ 


#ifndef WIRE_H_
#define WIRE_H_

#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "utility/twi.h"

#define BUFFER_LENGTH 32

// WIRE_HAS_END means Wire has end()
#define WIRE_HAS_END 1

    void wire_begin();
    void wire_beginSlaveMode(int);
    void wire_end();
    void wire_setClock(uint32_t);
    void wire_beginTransmission(int);
    uint8_t wire_endTransmission(void);
    uint8_t wire_endTransmissionWithStopMarker(uint8_t);
    uint8_t wire_requestFrom(int, int);
    uint8_t wire_requestFromWithStopMarker(int, int, int);
    size_t wire_write(uint8_t);
    size_t wire_writeArray(const uint8_t *, size_t);
    int wire_available(void);
    int wire_read(void);
    int wire_peek(void);
    void wire_flush(void);
    void wire_onReceive( void (*)(int) );
    void wire_onRequest( void (*)(void) );

	    




#endif /* WIRE_H_ */