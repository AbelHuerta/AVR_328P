/*
 * practica_1_adc.c
 *
 * Created: 15/05/2022 15:47:10
 * Author : abelh
 */ 

#define  F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <stdio.h>
#include "ADC_avr.h"
#include "LCD_avr.h"

uint16_t pot0=0,pot1=0,pot2=0,pot3=0,pot4=0,pot5=0,pot6=0,pot7=0;
char Str_pot0[20],Str_pot1[20],Str_pot2[20],Str_pot3[20],
	 Str_pot4[20],Str_pot5[20],Str_pot6[20],Str_pot7[20];

int main(void)
{
	ADC_AVR_Init();
    LCD_AVR_Init();
	
//UBICAMOS LOS INDICADORES
	LCD_AVR_Set_Cursor(0,Fila1);
	LCD_AVR_Print_String("POT1:");
	LCD_AVR_Set_Cursor(0,Fila2);
	LCD_AVR_Print_String("POT2:");
	LCD_AVR_Set_Cursor(0,Fila3);
	LCD_AVR_Print_String("POT3:");
	LCD_AVR_Set_Cursor(0,Fila4);
	LCD_AVR_Print_String("POT4:");
	LCD_AVR_Set_Cursor(11,Fila1);
	LCD_AVR_Print_String("POT5:");
	LCD_AVR_Set_Cursor(11,Fila2);
	LCD_AVR_Print_String("POT6:");
	
    for(;;) 
    {
		//INICIAMOS LA CONVERSION
		pot0 = AnalogRead(AN0);
		pot1 = AnalogRead(AN1);
		pot2 = AnalogRead(AN2);
		pot3 = AnalogRead(AN3);
		pot4 = AnalogRead(AN4);
		pot5 = AnalogRead(AN5);
	
		
		//CONVERTIMOS UINT A STRING
		
		sprintf((char*)Str_pot0,"%04u",pot0);
		sprintf((char*)Str_pot1,"%04u",pot1);
		sprintf((char*)Str_pot2,"%04u",pot2);
		sprintf((char*)Str_pot3,"%04u",pot3);
		sprintf((char*)Str_pot4,"%04u",pot4);
		sprintf((char*)Str_pot5,"%04u",pot5);
    
		//ESCRIBIMOS LA LCD
		LCD_AVR_Set_Cursor(5,Fila1);
		LCD_AVR_Print_String(Str_pot0);
		LCD_AVR_Set_Cursor(5,Fila2);
		LCD_AVR_Print_String(Str_pot1);
		LCD_AVR_Set_Cursor(5,Fila3);
		LCD_AVR_Print_String(Str_pot2);
		LCD_AVR_Set_Cursor(5,Fila4);
		LCD_AVR_Print_String(Str_pot3);
		LCD_AVR_Set_Cursor(16,Fila1);
		LCD_AVR_Print_String(Str_pot3);
		LCD_AVR_Set_Cursor(16,Fila2);
		LCD_AVR_Print_String(Str_pot3);
		
	}
}

