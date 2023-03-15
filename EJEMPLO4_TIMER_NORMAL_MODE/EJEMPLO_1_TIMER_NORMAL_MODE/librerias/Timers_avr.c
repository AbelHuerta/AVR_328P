/*
 * Timers_avr.c
 *
 * Created: 14/05/2022 15:47:27
 *  Author: abelh
 */ 
#define  F_CPU	16000000UL
#include <avr/io.h>
#include "Timers_avr.h"
#include <avr/interrupt.h>
#include <stdbool.h>
extern	volatile bool a;	

void Timer1_init(void){
	//TIMER 1 NORMAL MODE	
	TCCR1A &= ~(1<<WGM11) & ~(1<<WGM10);  
	TCCR1B &= ~(1<<WGM13) & ~(1<<WGM12);
	
	//HABILITAR EL CLOCK(PREESCALER) 1:64
	TCCR1B |= (1<<CS11) | (1<<CS10);
	TCCR1B &= ~(1<<CS12);
	
	//TEMPORIZACION : 100mS
	/*
	t = 100mS
	FOSC = 16MHz

	VALOR TIMER = 65536 - ((T x FOSC)/PRE)
	VALOR TIMER = 65536 - ((100ms x 16MHz)/64)
	VALOR TIMER = 65536 - 25000
	VALOR TIMER = 40536
	*/	
	TCNT1 = Valor_100ms;	
	
	//CONFIGURAR INTERRUP POR DESBORDAMIENTO
	TIMSK1 |= (1<<TOIE1); //HABILITA LA INTERRUPCION
		
}

ISR(TIMER1_OVF_vect){
	a = true;
	TCNT1 =Valor_100ms; //RECARGA DEL VALOR
	TIFR1 |= (1<<TOV1); //LIMPIA LA BANDERA
}