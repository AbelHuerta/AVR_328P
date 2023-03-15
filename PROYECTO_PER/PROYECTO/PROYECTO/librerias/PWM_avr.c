/*
 * PWM_avr.c
 *
 * Created: 13/06/2022 23:24:36
 *  Author: abelh
 */ 


#include "PWM_avr.h"
uint8_t duty=0;

void Fast_Mode_10bits(void){
	//NO INVERSOR
	TCCR1A |= (1<<COM1A1); 
	TCCR1A &= ~(1<<COM1A0); 
	
	//10 BITS (TOP = 0x03FF)
	TCCR1B &= ~(1<<WGM13);
	TCCR1B |= (1<<WGM12) ;
	TCCR1A |= (1<<WGM11) | (1<<WGM10);
	
	//PREESCALER 1:64
	TCCR1B &= ~(1<<CS12);
	TCCR1B |= (1<<CS11) | (1<<CS10);
	
}

void DUTY_CYCLE(void){
	
	Fast_Mode_10bits();
	//PERIODO DE LA ONDA PWM
	//FPWM = FCPU/(N*1024)
	//FPWM = 16M/(64*1024) -> FPWM = 244.14
	//TPWM = 4.096mS      -> 60%*4.096m = 2.4576mS (1) Y 1.6384mS(0)

	//PARA UN DUTY CYCLE 100%
	//DUTY CYCLE% = ((OCR1A+1)/1024)*100%
	//100% = ((OCR1A+1)/1024)*100%
	//1023 = OCR1A;
	OCR1B = 1023;
	//DUTY
	OCR1A = DUTY(1023,duty);
}

