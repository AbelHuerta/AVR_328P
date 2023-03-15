/*
 * ADC_avr.h
 *
 * Created: 4/06/2022 00:23:48
 *  Author: abelh
 */ 


#ifndef ADC_AVR_H_
#define ADC_AVR_H_

#define Resolucion 1023.0
#define Vref	5.0
#define ADC0	0
#define ADC1	1
#define ADC2	2
#define ADC3	3
#define ADC4	4
#define ADC5	5

#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "ADC_avr.h"
#include "LCD_avr.h"

//INICIALIZA ADC
void ADC_Init(void);

//HABILITA EL ADC
void ADC_Enable(void);

//SELECCION DEL CANAL
void ADC_channel(uint8_t CHx);

//INICIA LA CONVERCION
void Inicia_Conversion(void);

//CONVERSION LISTA
bool Conversion_Lista(void);

//VALOR DEL ADC
uint16_t ADC_Valor(void);

//MUESTREO DEL ADC
uint16_t ADC_Muestreo(uint16_t CHx);

#endif /* ADC_AVR_H_ */