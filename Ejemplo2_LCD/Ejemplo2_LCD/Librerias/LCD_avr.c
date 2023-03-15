/*
 * LCD_avr.c
 *
 * Created: 1/05/2022 17:02:04
 *  Author: abelh
 */ 

#include "LCD_avr.h"

//ENVIO DE COMANDO
void LCD_AVR_Cmd(uint8_t a){
	E_OFF;
	E_ON;
	LCD_AVR_Data_bus(a);
	_delay_ms(2);  //PARA LEER EL COMANDO
	E_OFF;
}

//ENVIO DE DATA
void LCD_AVR_Data_bus(uint8_t a){
	// 0001
	if(a & 0x01){D4_ON;}
	else{D4_OFF;}
	// 0010
	if(a & 0x02){D5_ON;}
	else{D5_OFF;}
	// 0100
	if(a & 0x04){D6_ON;}
	else{D6_OFF;}
	// 1000
	if(a & 0x08){D7_ON;}
	else{D7_OFF;}
	
}

//PARA INICIALIZAR
void LCD_AVR_INIT(void){
	DDRB |= (1<<0) |(1<<1)|(1<<2)|(1<<3)|(1<<4)| (1<<5);
	
	LCD_AVR_Cmd(0x03);
	LCD_AVR_Cmd(0x03);
	LCD_AVR_Cmd(0x03);
	LCD_AVR_Cmd(0x02);
	LCD_AVR_Cmd(0x02);
	LCD_AVR_Cmd(0x08);
	LCD_AVR_Cmd(0x00);
	LCD_AVR_Cmd(0x08);
	LCD_AVR_Cmd(0x00);
	LCD_AVR_Cmd(0x01);
	LCD_AVR_Cmd(0x00);
	LCD_AVR_Cmd(0x0D); //DISTINTO AL DATASHEET
	
	
}

void LCD_AVR_Set_Cursor(uint8_t x,Ubicacion y){
	uint8_t m,n;
	RS_OFF
	switch(y)
	{
		case Fila1:
			m = 0x80+x;
			n = (0x80+x)>>4;
			LCD_AVR_Cmd(n);
			LCD_AVR_Cmd(m);
		break;
		case Fila2:
			m = 0xC0+x;
			n = (0xC0+x)>>4;
			LCD_AVR_Cmd(n);
			LCD_AVR_Cmd(m);
		break;
		case Fila3:
			m = 0x94+x;
			n = (0x94+x)>>4;
			LCD_AVR_Cmd(n);
			LCD_AVR_Cmd(m);
		break;
		case Fila4:
			m = 0xD4+x;
			n = (0xD4+x)>>4;
			LCD_AVR_Cmd(n);
			LCD_AVR_Cmd(m);
		break;
	}
	
}


void LCD_AVR_Print_Char(char c){
	uint8_t m,n;
	m = c>>4;
	n = c;
	RS_ON;
	LCD_AVR_Cmd(m);
	LCD_AVR_Cmd(n);
}

void LCD_AVR_Print_String(char *c){
	
	char *ptr;
	ptr = c;
	while(*ptr)
		LCD_AVR_Print_Char(*ptr++);
}