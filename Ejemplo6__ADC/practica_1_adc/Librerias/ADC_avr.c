/*
 * ADC_avr.c
 *
 * Created: 15/05/2022 15:48:36
 *  Author: abelh
 */ 

#include "ADC_avr.h"

void ADC_AVR_Init(void){
	
//AVCC CON CAPACITOR EXTERNO AL PIN AREF	
	ADMUX |= (1<<REFS0); 
	ADMUX &= ~(1<<REFS1);

//JUSTIFICACION A LA DERECHA	
	ADMUX &= ~(1<<ADLAR);
	
//SELECCION DEL CLOCK DEL ADC
//FOSC/PRE = 16MHz/128 = 125KHz
	ADCSRA |= (1<<ADPS2) | (1<<ADPS1)| (1<<ADPS0); 

//HABILITAR CANALES ANALOGICOS
	DIDR0 = 0xFF;	
}


void ADC_Avr_Enable(void){
//HABILITA EL ADC
	ADCSRA |= (1<<ADEN);	
}


void ADC_Avr_Disable(void){
//DESABILITA EL ADC
	ADCSRA &= ~(1<<ADEN);	
}

void ADC_Avr_SelectANX(uint8_t ANX){
	
}


uint16_t AnalogRead(Channel ANx){
	
//SELECCION DEL CANAL	
	ADMUX = ((ADMUX & 0xF0 )| (ANx & 0x0F)); //MANTIENE LOS BITS 7-4

//HABILITA EL ADC
	ADC_Avr_Enable();

//INICIA CONVERSION
	ADCSRA |= (1<<ADSC);
	
//ESPERAR QUE LA CONVERSION TERMINE
	while((ADCSRA & (1<<ADSC)) == true);

//DESABILITAMOS EL ADC
	ADC_Avr_Disable();
	
return ADC;
	
}