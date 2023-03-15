/*
 * interrupciones_AVR.c
 *
 * Created: 28/05/2022 14:51:03
 *  Author: abelh
 */ 

#include "interrupciones_AVR.h"
#include <avr/io.h>
#include <avr/interrupt.h>

void INTX_Init(void){
	//FLANCO DE SUBIDA INT0
	EICRA |= (1<<ISC01) | (1<<ISC00);
	//HABLILITA LA INTERRUPCION INT0
	EIMSK |= (1<<INT0);
	
	//FLANCO DE BAJADA INT1
	EICRA |= (1<<ISC11);
	EICRA &= ~(1<<ISC10);
	//HABLILITA LA INTERRUPCION INT1
	EIMSK |= (1<<INT1);
}

ISR(INT0_vect){
	
	PORTB ^= (1<<0);
	//LIMPIA EL FLANCO COLOCANDOLO A 1; LIMPIAR LA BANDERA
	EIFR |= (1<<INTF0);
}

ISR(INT1_vect){
	
	PORTB ^= (1<<5);
	//LIMPIA EL FLANCO COLOCANDOLO A 1; LIMPIAR LA BANDERA
	EIFR |= (1<<INTF1);
}