/*
 * adc_driver.c
 *
 * Created: 6/25/2024 1:13:49 AM
 *  Author: Mai El-Shahed
 */ 
#include <avr/io.h>

#include "Std_macros.h"

void ADC_vinit(void)
{
	SET_BIT(ADMUX,REFS0); //configure VREF AVCC 5v
	SET_BIT(ADMUX,REFS1); //configure VREF AVCC 2.65v  steb 2.5   
	SET_BIT(ADCSRA,ADEN); // enable ADC
	/* adjust ADC clock 8mhz clock cpu / 64 = 125khz clock adc*/
	SET_BIT(ADCSRA,ADPS2);
	SET_BIT(ADCSRA,ADPS1);
}

unsigned short ADC_Read(void)
{
	unsigned short read_val;

	SET_BIT(ADCSRA,ADSC);//start conv
	while(READ_BIT(ADCSRA,ADSC)==1);
	/*while(IS_BIT_CLR(ADCSRA,ADIF));//stay in your position till ADIF become 1
	   SET_BIT(ADCSRA,ADIF); // clear ADIF*/
	//while(!(READ_BIT(ADCSRA,ADIF)==1));//stay in your position till ADIF become 1
	/*while((READ_BIT(ADCSRA,ADIF)==0));//stay in your position till ADIF become 1
	   SET_BIT(ADCSRA,ADIF); // clear ADIF*/
	
	read_val=(ADCL);
	read_val|=(ADCH<<8);
	return read_val ;
}


