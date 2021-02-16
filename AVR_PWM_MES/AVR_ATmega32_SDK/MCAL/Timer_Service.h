/*
 * Timer_Service.h
 *
 * Created: 9/23/2019 6:30:57 AM
 *  Author: SOHAIB
 */ 


#ifndef TIMER_SERVICE_H_
#define TIMER_SERVICE_H_

#include "Timer.h"
#include "Utilies.h"
#include "Mem_MAPPED.h"

extern void PWM_INIT(void);
extern void PWM_Freq_KHZ(u16 freq);
extern void PWM_Freq_HZ(u16 freq);
extern void PWM_Duty(u16 duty);

extern void Timer1_SET_INTERRUPT_Time_ms(u16 Time ,void(*Local_Fptr)(void));
extern void Timer1_SET_INTERRUPT_Time_us(u16 Time ,void(*Local_Fptr)(void));
static void FUNC_ICU(void);


#endif /* TIMER_SERVICE_H_ */