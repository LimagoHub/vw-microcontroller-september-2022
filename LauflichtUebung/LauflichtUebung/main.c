/*
 * LauflichtUebung.c
 *
 * Created: 09.09.2022 12:30:43
 * Author : JoachimWagner
 */ 

#include <avr/io.h>
#include "lauflicht.h"

int main(void)
{
    lauflicht_init();
    while (1) 
    {
		lauflicht_animiere(3);
    }
}

