/*
 * AVR_ATmega32_SDK.c
 *
 * Created: 9/23/2019 2:57:09 AM
 * Author : SOHAIB
 */ 

// Measure PWM
#include "Utilies.h"
#include "Data_Types.h"
#include "DIO_interface.h"
#include "LCD.h"
#include "EX_INT.h"
#include "ADC.h"
#include "Timer.h"
#include "Timer_Service.h"
#include "Mem_MAPPED.h"


int main(void)
{
	DIO_Init();
	LCD_Init();
	Timer1_INIT(TIMER1_NORMAL_MODE,TIMER1_SCALER_8,DISCONNECTED_OCRA_MODE,DISCONNECTED_OCRA_MODE);
	u8 x = 0,d,d2,duty;
	u16 adc;
	u32 freq; 
	LCD_WriteSentence("Freq: ");
	LCD_GoTo(1,0);
	LCD_WriteSentence("Duty: ");
	while(1)
	{
		PWM_MEASURE(&freq,&duty);
		LCD_GoTo(0,6);
		LCD_WriteNumber4(freq);
		LCD_GoTo(1,6);
		LCD_WriteNumber4(duty);	
	}
	return 0;
}

