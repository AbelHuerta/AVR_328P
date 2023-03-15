/*
 * GPIO.c
 *
 * Created: 15/05/2022 13:26:18
 *  Author: abelh
 */ 

#include "GPIO.h"

void GPIO_INIT(void){
	DDRB |=(1<<5);
}

void GPIO_TOGGLE(void){
	PORTB ^= (1<<5);
}
