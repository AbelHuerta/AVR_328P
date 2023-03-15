/*
 * interrupciones_AVR.c
 *
 * Created: 28/05/2022 14:51:03
 *  Author: abelh
 */ 

#include "interrupciones_AVR.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>
extern volatile bool Flag_PCINT;

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

void PCINTX_Init(void){
	//HABILITAMOS ESE VECTOR
	PCICR |= (1<<PCIE0);
	//HABILITAMOS EL PIN PB7
	PCMSK0 |= (1<<PCINT7);
}

ISR(PCINT0_vect){
	Flag_PCINT = true;
	//PORTB ^= (1<<5);
	//LIMPIAR LA BANDERA
	PCIFR |= (1<<PCIF0);
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