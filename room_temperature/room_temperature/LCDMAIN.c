/*
 * LCD.c
 *
 * Created: 6/10/2024 5:41:23 PM
 *  Author: RS3
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "LCD.h"
int main(void)
{LCD_vinit();
	LCD_vsend_char('M');
	_delay_ms(1000);
	LCD_vsend_char('a');
	_delay_ms(1000);
	LCD_vsend_char('i');
	_delay_ms(1000);
	LCD_vsend_char(32);//space
	//cgram story-->data
	LCD_vsend_cmd(64);//adress 1 loction
	//story HART
	LCD_vsend_char(0b00011011);
	LCD_vsend_char(0b00010101);
	LCD_vsend_char(0b00010001);
	LCD_vsend_char(0b00010001);
	LCD_vsend_char(0b00010001);
	LCD_vsend_char(0b00001010);
	LCD_vsend_char(0b00000100);
	LCD_vsend_char(0b00000000);
	
	LCD_movecursor(1,5);//cursor  row 2 coul   1
	
	LCD_vsend_char(0);//It takes data from the first place in  cgram
	LCD_vsend_char(32);//space
	
	LCD_vsend_char('S');
	_delay_ms(1000);
	LCD_vsend_char('a');
	_delay_ms(1000);
	LCD_vsend_char('l');
	_delay_ms(1000);
	LCD_vsend_char('l');
	_delay_ms(1000);
	LCD_vsend_char('y');
	
	
	
	
	
    while(1)
    {
        //TODO:: Please write your application code 
    }
}