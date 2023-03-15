/*
 * interrupciones externas.c
 *
 * Created: 28/05/2022 14:49:58
 * Author : abelh
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "Interrupciones_AVR.h"
#include <avr/interrupt.h>

int main(void)
{
	INTX_Init();
	//SALIDAS
	DDRB |= (1<<0) | (1<<5);
	//INICIALMENTE APAGADO
	PORTB &= ~(1<<0) & ~(1<<5);
	//HABILITA INTERRUPCIONES GLOBALES
	sei();
	for (;;)
	{
		
	}
}

