/*
 * Timer_Service.c
 *
 * Created: 9/23/2019 6:30:57 AM
 *  Author: SOHAIB
 */ 


#include "Timer_Service.h"
/**************************PWM***********************************************/
volatile u16 flag ,t1,t2,t3;

void PWM_INIT(void)
{
	Timer1_INIT(TIMER1_FASTPWM_ICR1_TOP_MODE,TIMER1_SCALER_8,NONINVERTING_OCRA_MODE,DISCONNECTED_OCRB_MODE);
}

void PWM_Freq_KHZ(u16 freq)
{
	if(freq == 0);
	else
	{
		u16 T_total=1000/freq;
		if(T_total >= 1)
		{
			ICR1 = T_total -1;
		}
		else
		ICR1 = 0;
	}
}

void PWM_Freq_HZ(u16 freq)
{
	if(freq == 0);
	else
	{
		u16 T_total=(u32)1000000/freq;
		if(T_total >= 1)
		{
			ICR1 = T_total -1;
		}
		else
		ICR1 = 0;
	}
	
}

void PWM_Duty(u16 duty)
{
	if(duty <= 100)
	{
		u16 T_ON =((u32)duty * (ICR1 + 1))/100;
		if(T_ON > 1)
		{
			OCR1A = T_ON - 1;
		}
		else OCR1A = 0;
	}
}


void Timer1_SET_INTERRUPT_Time_ms(u16 Time ,void(*Local_Fptr)(void))
{
		Timer1_INIT(TIMER1_FASTPWM_ICR1_TOP_MODE,TIMER1_SCALER_8,NONINVERTING_OCRA_MODE,DISCONNECTED_OCRB_MODE);
		OCR1A = (1000 *Time) - 1;
		Timer1_SETCALLBACK(Timer1_OCA,Local_Fptr);
		Timer1_OCA_INT_ENABLE(); 
}


void Timer1_SET_INTERRUPT_Time_us(u16 Time ,void(*Local_Fptr)(void))
{
	Timer1_INIT(TIMER1_FASTPWM_ICR1_TOP_MODE,TIMER1_SCALER_8,NONINVERTING_OCRA_MODE,DISCONNECTED_OCRB_MODE);
	OCR1A = ( Time )- 1;
	Timer1_SETCALLBACK(Timer1_OCA,Local_Fptr);
	Timer1_OCA_INT_ENABLE();
}

void PWM_MEASURE(u32* PFreq ,u32* PDuty)
{
	u16 T_ON, T_OFF;
	TCNT0=0;
	Timer1_SETCALLBACK(Timer1_ICU,FUNC_ICU);
	Timer1_ICU_Edge(TIMER1_ICU_RAISING_EDGE);
	Timer1_ICU_INT_ENABLE();
	flag = 0;
	while(flag < 3);
	T_ON = t2 - t1;
	T_OFF = t3 - t2;
	*PFreq = ((u32)1000000) / ((u32)T_ON + T_OFF);
	*PDuty = ((u32) T_ON * 100) / ((u32)T_ON + T_OFF);
}



static void FUNC_ICU(void)
{
	if(flag == 0)
	{
		t1 = ICR1;
		Timer1_Trigger_Edge(FALLING_EDGE);
		flag = 1;
	}
	else if(flag == 1)
	{
		t2 = ICR1;
		Timer1_Trigger_Edge(RISING_EDGE);
		flag = 2;
	}
	else if(flag == 2)
	{
		t3 = ICR1;
		Timer1_ICU_INT_DISABLE();
		flag = 3;
	}
}