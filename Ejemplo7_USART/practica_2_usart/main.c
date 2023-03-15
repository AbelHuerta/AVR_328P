/*
 * practica_2_usart.c
 *
 * Created: 15/05/2022 18:41:05
 * Author : abelh
 */ 

#define  F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <stdio.h>
#include "USART_avr.h"

int main(void)
{
    UART0_Avr_Init(9600);
	
    while (1) 
    {
		UART0_Avr_Print_Char('S');
		_delay_ms(500);
    }
}

