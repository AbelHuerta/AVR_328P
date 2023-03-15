/*
 * ejmplo_EEPROM.c
 *
 * Created: 5/06/2022 16:44:35
 * Author : abelh
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include "I2C_avr.h"

#define  EEPROM5 0b10100110
#define  EEPROM4 0b10100010
#define  EEPROM2 0b10100000

char Str_1[] = "hola epprom2";
char Str_2[] = "zxz";
char Str_3[] = "asd";

void Write_EEPROM_I2C(char *ptr_Str, uint16_t ADD_EEP);

int main(void)
{
    I2C_AVR_Init();
	
	I2C_AVR_START();
	I2C_AVR_ADDREES_SLAVE(EEPROM2,I2C_WRITE);
	Write_EEPROM_I2C(Str_1,0x0028);
	
	I2C_AVR_Stop();
	while (1) 
    {
		
    }
}


void Write_EEPROM_I2C(char *ptr_Str, uint16_t ADD_EEP){
	I2C_AVR_Write_Data((uint8_t)(ADD_EEP>>8));	//HIGH BIT
	I2C_AVR_Write_Data((uint8_t)(ADD_EEP));		//LOW BIT
	while(*ptr_Str)
		I2C_AVR_Write_Data(*ptr_Str++);
}
