/*
 * aplicacion_interrup.c
 *
 * Created: 28/05/2022 22:33:44
 * Author : abelh
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
#include <stdint.h>
#include "Interrupciones_AVR.h"
#include "LCD_avr.h"
#include <avr/interrupt.h>

volatile uint16_t algodon=0,cemento=0;
volatile bool algodon_f = false, cemento_f = false;
//PARA PASAR DE ENTERO A CADENA
char str_algodon[20],str_cemento[20];

int main(void)
{
	cli();
	LCD_AVR_Init();
	
	//conversion
	sprintf(str_algodon,"Algodon: %04u",algodon);
	sprintf(str_cemento,"Algodon: %04u",cemento);
	
	LCD_AVR_Set_Cursor(0,Fila1);
	LCD_AVR_Print_String(str_algodon);
	
	LCD_AVR_Set_Cursor(0,Fila2);
	LCD_AVR_Print_String(str_cemento);
	
	INTX_Init();
	sei();
	for (;;)
	{
		if (algodon_f || cemento_f)
		{
			sprintf(str_algodon,"Algodon: %04u",algodon);
			sprintf(str_cemento,"Algodon: %04u",cemento);
			
			LCD_AVR_Set_Cursor(0,Fila1);
			LCD_AVR_Print_String(str_algodon);
			
			LCD_AVR_Set_Cursor(0,Fila2);
			LCD_AVR_Print_String(str_cemento);
			
			//BORRAMOS LAS BANDERAS
			algodon_f = false;
			cemento_f = false;	
		}
		
	}
}


