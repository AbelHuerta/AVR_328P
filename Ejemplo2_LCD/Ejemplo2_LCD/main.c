/*
 * Ejemplo2_LCD.c
 *
 * Created: 1/05/2022 17:01:15
 * Author : abelh
 */ 

#define  F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "LCD_avr.h"

int main(void)
{
	LCD_AVR_INIT();
	//LCD_AVR_Set_Cursor(0,Fila1);
	//LCD_AVR_Print_Char('H');
	//
	//LCD_AVR_Set_Cursor(0,Fila2);
	//LCD_AVR_Print_Char('O');
	//
	//LCD_AVR_Set_Cursor(0,Fila3);
	//LCD_AVR_Print_Char('L');
	//
	//LCD_AVR_Set_Cursor(0,Fila4);
	//LCD_AVR_Print_Char('A');   
	
	LCD_AVR_Set_Cursor(0,Fila1);
	LCD_AVR_Print_String("Bienvenidos");
	
	LCD_AVR_Set_Cursor(0,Fila2);
	LCD_AVR_Print_String("a todos");
	
	LCD_AVR_Set_Cursor(0,Fila3);
	LCD_AVR_Print_String("as");
	
	LCD_AVR_Set_Cursor(0,Fila4);
	LCD_AVR_Print_String("ds");
	
    while (1) 
    {
    }
}

