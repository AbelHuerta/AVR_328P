/*
 * PWM_avr.h
 *
 * Created: 13/06/2022 23:24:46
 *  Author: abelh
 */ 


#ifndef PWM_AVR_H_
#define PWM_AVR_H_

#define F_CPU	16000000UL
#include <avr/io.h>

#define DUTY(ARR,_duty)		(uint16_t)(((float)ARR/100)*_duty)

//CONFIGURACION FAST MODE
void Fast_Mode_10bits(void);

//CONFIGURACION %DUTY
void DUTY_CYCLE(void);

#endif /* PWM_AVR_H_ */