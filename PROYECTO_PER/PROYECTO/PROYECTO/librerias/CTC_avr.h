/*
 * CTC_avr.h
 *
 * Created: 17/06/2022 17:43:29
 *  Author: abelh
 */ 


#ifndef CTC_AVR_H_
#define CTC_AVR_H_

#define F_CPU	16000000UL
#include <avr/io.h>

//CONFIGURACION CTC
void Init_CTC_Mode(void);

//PERIODO DEL CTC
void TIMER_0_CTC(void);


#endif /* CTC_AVR_H_ */