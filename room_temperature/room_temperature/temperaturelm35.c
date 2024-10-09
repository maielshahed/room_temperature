/*
 * temperaturelm35.c
 *
 * Created: 6/29/2024 4:29:43 PM
 *  Author: RS3
 */ 


#include <avr/io.h>


#include "adc_driver.h"
#include "LCD.h"
#define F_CPU 8000000UL
#include <util/delay.h>

char read_val;
unsigned short temperature;

int main(void)
{
	ADC_vinit();
	LCD_vinit();
	
	 LCD_vsend_string("temperature=");
 
	
    while(1)
    {
        //TODO:: Please write your application code 
		temperature=((ADC_Read())*0.25);
		    
				if(temperature<10)
				{
					LCD_movecursor(1,13);
					//LCD_vsend_char(0x30);
					LCD_vsend_char((temperature%10)+48);
					LCD_vsend_char(0xDF);
					LCD_vsend_char(0x43);
					LCD_vsend_char(0x20);//clear bit 
				}
				else if( temperature<100)
				{
					LCD_movecursor(1,13);
					LCD_vsend_char((temperature/10)+48);
					LCD_vsend_char((temperature%10)+48);
					LCD_vsend_char(0xDF);
					LCD_vsend_char(0x43);
				}
				else
				{

				}


    }
}