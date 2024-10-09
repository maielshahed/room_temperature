/*
 * room_temperature.c
 *
 * Created: 10/4/2024 9:48:16 PM
 *  Author: Mai El-Shahed
 */ 


#include <avr/io.h>


#include "adc_driver.h"
#include "LCD.h"
#define F_CPU 8000000UL
#include <util/delay.h>

char read_val;
unsigned short temperature;
 volatile unsigned short sec=50,min=0,hour=12;
 char temp=0;
int main(void)
{
	ADC_vinit();
	LCD_vinit();
	
	LCD_vsend_string("temperature=");
DIO_vsetpindir('D',1,1);
	DIO_vsetpindir('D',0,1);//OUTPUT ==1   INPUT 0
	DIO_vsetpindir('D',2,1);//BUZZER
	while(1)
	{
		//TODO:: Please write your application code
		temperature=((ADC_Read())*0.25);
		
		if(temperature<10 )
		{
			LCD_movecursor(1,13);
			//LCD_vsend_char(0x30);
			LCD_vsend_char((temperature%10)+48);
			LCD_vsend_char(0xDF);
			LCD_vsend_char(0x43);
			LCD_vsend_char(0x20);//clear bit
			DIO_vwrite('D',1,1);
			DIO_vwrite('D',0,0); //RED
		}
		
		else if( temperature<100)
		{
			LCD_movecursor(1,13);
			LCD_vsend_char((temperature/10)+48);
			LCD_vsend_char((temperature%10)+48);
			LCD_vsend_char(0xDF);
			LCD_vsend_char(0x43);
			
			if (temperature>=50)
			{
				DIO_vwrite('D',1,0);
				DIO_vwrite('D',0,1); //RED
				DIO_vwrite('D',2,1); //BUZZER
			} 
			else
			{
				DIO_vwrite('D',1,1);
				DIO_vwrite('D',0,0); //RED
				DIO_vwrite('D',2,0); //BUZZER
			}
		}
		
		
	
	
	
		 if (sec < 10)
		{
			LCD_movecursor(2,1);
				LCD_vsend_char((hour/10)+48);
			LCD_vsend_char((hour%10)+48);
			LCD_movecursor(2,3);
			LCD_vsend_char(':');
			LCD_movecursor(2,4);
			LCD_vsend_char((min%10)+48);
			LCD_movecursor(2,5);
			LCD_vsend_char((sec%10)+48);
			if (temp==0)
			{
					LCD_movecursor(2,6);
					LCD_vsend_string("AM");
			}
			
			_delay_ms(1000);
			sec++;
			
		} else if(sec <= 59 || hour >= 12 ){
		
		LCD_movecursor(2,1);
		LCD_vsend_char((hour/10)+48);
		LCD_vsend_char((hour%10)+48);
	LCD_movecursor(2,3);
		LCD_vsend_char(':');
		LCD_movecursor(2,4);
		LCD_vsend_char((sec/10)+48);
		LCD_vsend_char((sec%10)+48);
		
			if (temp==0)
			{
				LCD_movecursor(2,6);
				LCD_vsend_string("AM");
			}
		
	
			_delay_ms(1000);
				
			if ((sec==59)&&(hour==12))
			{
				break;
			}
			  
			sec++;
			
		}
		else if(sec==60 || hour <= 9)
		{
			sec=0;
			hour++;
			LCD_movecursor(2,1);
			LCD_vsend_char((min%10)+48);
			LCD_movecursor(2,2);
			LCD_vsend_char((hour%10)+48);
			LCD_movecursor(2,3);
			LCD_vsend_char(':');
			LCD_movecursor(2,4);
			LCD_vsend_char((sec%10)+48);
					if (temp==0)
					{
						LCD_movecursor(2,6);
						LCD_vsend_string("AM");
					}
				
	}
	
	
	if ((sec==59)&&(hour==12))
	{
		sec=0;
		hour=1;
		temp=1;
			LCD_movecursor(2,6);
		LCD_vsend_string("PM");
	}
	
	
	}


		
		
	}


