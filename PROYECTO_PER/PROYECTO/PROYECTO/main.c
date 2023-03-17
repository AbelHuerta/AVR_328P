/*
 * PROYECTO.c
 *
 * Created: 13/06/2022 13:05:04
 * Author : abelh
 */ 


#define  F_CPU 16000000UL
#include <avr/io.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <avr/interrupt.h>

#include "GPIO_avr.h"
#include "LCD_avr.h"

#include "ADC_avr.h"
float POT0 = 0.0;
char  Str_POT0[20];

#include "CTC_avr.h"
int cont=0;

#include "PWM_avr.h"
#include "USART_avr.h"
char	txt[20];
uint8_t	bufferRx[20];
uint16_t RxCount;
uint8_t byte;
extern  uint8_t duty;

/***********************/

volatile unsigned char tiempo = 0;

int main(void)
{
	PIN_OUTPUT(D,6);//DDRD |= (1<<6); //CTC
	
	GPIO_Init();
	LCD_AVR_Init();
	
	ADC_Init();
	ADC_Enable();
	//UBICAMOS LOS INDICADORES
	LCD_AVR_Set_Cursor(0,Fila4);
	LCD_AVR_Print_String("VOLT:");
	
	TIMER_0_CTC();
	
	PIN_OUTPUT(B,1);//DDRB |= (1<<1); //SALIDA DUTY
	
	DUTY_CYCLE(); //PWM : 60%
	
	LCD_AVR_Init();
	LCD_AVR_Set_Cursor(0,Fila1);
	LCD_AVR_Print_String("--------------------");
	LCD_AVR_Set_Cursor(0,Fila2);
	LCD_AVR_Print_String("-----ABEL HUERTA----");
	//UBICACION DEL DUTY
	LCD_AVR_Set_Cursor(0,Fila3);
	LCD_AVR_Print_String("DUTY:");
	
	UART_Config(DOUBLE_SPEED,9600);
	
	
	
	
	sei();
    for (;;) 
    {
		//INICIA LA CONVERSION 0-5V
		POT0 = (((float)ADC_Muestreo(ADC3))*((float)(Vref/Resolucion)));
		//CONVERTIMOS UINT A STRING
		sprintf((char*)Str_POT0,"%.2f",POT0);
		//ESCRIBIMOS LA LCD
		LCD_AVR_Set_Cursor(5,Fila4);
		LCD_AVR_Print_String(Str_POT0);
		
		//CLEAR(0-100) DUTY
		LCD_AVR_Set_Cursor(7,Fila3);
		LCD_AVR_Print_String(" ");
		
		//DE UINT_8 A CADENA
		sprintf((char*)txt,"%d",duty);
		//VALOR DE DUTY - LCD
		LCD_AVR_Set_Cursor(5,Fila3);
		LCD_AVR_Print_String(txt);
		
		
    }
}

ISR(TIMER0_COMPA_vect){
	TIFR0 |= 1<<OCF0A;
	cont ++;
	if (cont==100)
	{
		cont=0;
		PIN_TOGGLE(D,6);//PIND |= (1<<6);
		
	}
	
	

}




ISR(USART_RX_vect){
	byte = UDR0;
	if(byte == 'X'){
		bufferRx[RxCount] = '\n';			//SE AÑADE EL CARACTER FINAL
		duty = atoi((char*)bufferRx); //CONVIERTE EL NUMERO A ENTERO
		memset(bufferRx,0,RxCount); //LIMPIA EL BUFFER
		RxCount = 0;
		OCR1A = DUTY(1024,duty);		//CAMBIA EL PORCENTAJE
		}else{
		bufferRx[RxCount] = byte;
		RxCount++;
	}
	
	return;
}
