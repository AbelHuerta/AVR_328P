/*
 * EJEMPLO_1_TIMER_NORMAL_MODE.c
 *
 * Created: 14/05/2022 15:44:20
 * Author : abelh
 */ 

#define  F_CPU	16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "Timers_avr.h"
#include <avr/interrupt.h>
#include <stdbool.h>

#define  LedC0_Toggle()	(PORTC ^= (1<<PINC0))
volatile bool a= false;	


int main(void)
{
    Timer1_init();
	DDRC |= (1<<0);
	PORTC &= ~(1<<0); //INICIALMENTE APAGADO
	sei(); //HABILITA INTERRUPCIONES
    while (1) 
    {
		if(a){
			
			LedC0_Toggle();
			a=false;
		}
		
		
    }
}

