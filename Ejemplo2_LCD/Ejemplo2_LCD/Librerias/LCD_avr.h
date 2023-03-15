/*
 * LCD_avr.h
 *
 * Created: 1/05/2022 17:02:23
 *  Author: abelh
 */ 


#ifndef LCD_AVR_H_
#define LCD_AVR_H_

#define  F_CPU 8000000UL
#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

#define E_ON	PORTB |= (1<<0);
#define E_OFF	PORTB &= ~(1<<0);

#define RS_ON	PORTB |= (1<<1);
#define RS_OFF	PORTB &= ~(1<<1);

#define D4_ON	PORTB |= (1<<2);
#define D4_OFF	PORTB &= ~(1<<2);

#define D5_ON	PORTB |= (1<<3);
#define D5_OFF	PORTB &= ~(1<<3);

#define D6_ON	PORTB |= (1<<4);
#define D6_OFF	PORTB &= ~(1<<4);

#define D7_ON	PORTB |= (1<<5);
#define D7_OFF	PORTB &= ~(1<<5);
	
typedef enum{
	Fila1 = 0,
	Fila2,
	Fila3,
	Fila4,
}Ubicacion;

//ENVIO DE COMANDO
void LCD_AVR_Cmd(uint8_t a);

//ENVIO DE DATA
void LCD_AVR_Data_bus(uint8_t a);

//PARA INICIALIZAR
void LCD_AVR_INIT(void);

//PARA UBICAR EL CURSOR
void LCD_AVR_Set_Cursor(uint8_t x,Ubicacion y);

//PARA ESCRIBIR UN CARACTER
void LCD_AVR_Print_Char(char c);

//PARA ESCRIBIR UNA CADENA
void LCD_AVR_Print_String(char *c);



#endif /* LCD_AVR_H_ */