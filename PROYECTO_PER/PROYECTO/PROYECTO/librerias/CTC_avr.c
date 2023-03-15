/*
 * CTC_avr.c
 *
 * Created: 17/06/2022 17:43:21
 *  Author: abelh
 */ 

#include "CTC_avr.h"


void Init_CTC_Mode(void){
	//VALOR INICIAL
	TCNT0 = 0;
	
	//CTC (TOP = OCR0A)
	TCCR0B &= ~(1<<WGM02) ;
	TCCR0A |= (1<<WGM01);
	TCCR0A &= ~(1<<WGM00);
	
	//PREESCALER 1:64
	TCCR0B |= (1<<CS02) | (1<<CS00);
	TCCR0B &= ~(1<<CS01) | (1<<CS00);
	
	
}

void TIMER_0_CTC(void){
	
	Init_CTC_Mode();
	
	//OCR0A = (FCLK/FOSC*2*N)-1
	//OCR0A = (16M/100*2*1024)-1	//FOSC = 100 -> TOSC = 10mS;
	//OCR0A = //OCR0A <= 256
	OCR0A = 77;
	//CONFIGURAR INTERRUPCION
	TIMSK0 |= 1<<OCIE0A;	//GENERA INTERRUPCION CUANDO OCR0A == TCNT
	//
	TIFR0 |= 1<<OCF0A;
}