/*
 * ADC_avr.h
 *
 * Created: 15/05/2022 15:48:43
 *  Author: abelh
 */ 


#ifndef ADC_AVR_H_
#define ADC_AVR_H_

#define  F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#define Resolucion_AVR	1023.0
#define Vref			5.0

//ENUMERACION PARA LOS CANALES
typedef enum{
	AN0 = 0,
	AN1,
	AN2,
	AN3,
	AN4,
	AN5,
	AN6,
	AN7,
}Channel;

void ADC_AVR_Init(void); //INICIALIZACION DEL PERIFERICO
void ADC_Avr_Enable(void); //HABILITA EL ADC
void ADC_Avr_Disable(void); //DESABILITA EL ADC
uint16_t AnalogRead(Channel ANx); //REALIZAMOS LA MUESTRA

#endif /* ADC_AVR_H_ */