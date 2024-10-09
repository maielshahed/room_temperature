/*
 * adc_driver.h
 *
 * Created: 6/25/2024 1:14:10 AM
 *  Author: Mai El-Shahed
 */ 


#ifndef ADC_DRIVER_H_
#define ADC_DRIVER_H_

void ADC_vinit(void);
unsigned short ADC_Read(void);

void ADCintertupt_vinit();

unsigned short ADCinterrupt_read() ;

#endif /* ADC_DRIVER_H_ */