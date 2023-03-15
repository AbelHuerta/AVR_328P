/*
 * EJEMPLO_2_TIMER_CONTADOR.c
 *
 * Created: 14/05/2022 17:03:33
 * Author : abelh
 */ 

#define  F_CPU	16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "Timers_avr.h"
#include <avr/interrupt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include "LCD_avr.h"
#define  LedC0_Toggle()	(PORTC ^= (1<<PINC0))
volatile bool a= false;
uint8_t Productos;
char Str_Productos[20]="";

int main(void)
{
    LCD_AVR_Init();
	Timer1_ModoContador();
	LCD_AVR_Set_Cursor(0,Fila1);
	LCD_AVR_Print_String("clase");
    for (;;) 
    {
		Productos = TCNT1;
		 sprintf(Str_Productos,"Productos: %04u",Productos);
		 LCD_AVR_Set_Cursor(0,Fila2);
		 LCD_AVR_Print_String((char*)Str_Productos);
		
    }
}

