/*
 * GPIO_avr.c
 *
 * Created: 13/06/2022 13:08:34
 *  Author: abelh
 */ 


#include "GPIO_avr.h"

void GPIO_Init(void){
	PIN_INPUT(D,7);
	PIN_OUTPUT(B,1);
}

