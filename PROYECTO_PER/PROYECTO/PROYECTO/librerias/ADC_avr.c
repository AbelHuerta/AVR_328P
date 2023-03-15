/*
 * ADC_avr.c
 *
 * Created: 4/06/2022 00:23:36
 *  Author: abelh
 */ 

#include "ADC_avr.h"

void ADC_Init(void){
//AVcc CON CAPACITOR EXTERNO AL PIN AREF
	ADMUX |= (1<<REFS0);
	ADMUX &= ~(1<<REFS1);

//PREESCALADOR PARA QUE LA FRECUENCIA ESTE ENTRE 50kHz - 200kHz
// 16MHz/128 = 125kHz
	ADCSRA |= (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);

//JUSTIFICADO A LA DERECHA
	ADCSRA &= ~(1<<ADLAR);

//REDUCIR EL CONSUMO DE ENERGIA EN EL BUFER DE ENTRADA
	DIDR0 = 0xFF; 
}

void ADC_Enable(void){
//HABILITA EL ADC
	ADCSRA |= (1<<ADEN);
}

void ADC_channel(uint8_t CHx){
//SELECCION DEL CANAL
	ADMUX = (ADMUX & 0xF0) | (CHx & 0x0F);
}

void Inicia_Conversion(void)
{
//INICIA LA CONVERSION
	ADCSRA |= (1<<ADSC);
}

bool Conversion_Lista(void)
{
//ADCS = 0 (CONVERSION FINALIZADA) ;  ADCS = 1 (CONVERSION EN CURSO)
	return (ADCSRA & (1<<ADSC));
}


uint16_t ADC_Valor(void)
{
	return ADC;
}

uint16_t ADC_Muestreo(uint16_t CHx)
{
	ADC_channel(CHx);
	Inicia_Conversion();
	while(Conversion_Lista() != 0 );
	
	return ADC_Valor();
	
}
