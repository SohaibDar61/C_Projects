/*
 * Timer.h
 *
 * Created: 9/23/2019 6:00:57 AM
 *  Author: SOHAIB
 */ 


#ifndef TIMER_H_
#define TIMER_H_


//#include <avr/interrupt.h>
#include "Mem_MAPPED.h"
#include "Utilies.h"
#include "DIO_confg.h"
#include "Data_Types.h"

//=================================================================================================//
//================================configuration for TIMER1=========================================//
//=================================================================================================//


typedef enum
{
	TIMER1_ICU_FALLING_EDGE = 0,
	TIMER1_ICU_RAISING_EDGE
}Timer1_Trigger_Edge;


typedef enum
{
	TIMER1_NORMAL_MODE = 0,
	TIMER1_FASTPWM_ICR1_TOP_MODE,
	TIMER1_FASTPWM_OCR1A_TOP_MODE
}Timer1_MODE_TYPE;


typedef enum
{
	TIMER1_STOP = 0,
	TIMER1_SCALER_1,
	TIMER1_SCALER_8,
	TIMER1_SCALER_64,
	TIMER1_SCALER_256,
	TIMER1_SCALER_1024,
	EXTERNAL1_FALLING,
	EXTERNAL1_RAISING
}Timer1_SCALER_TYPE;


typedef enum
{
	DISCONNECTED_OCRA_MODE = 0,
	TOGGLE_OCRA_MODE,
	NONINVERTING_OCRA_MODE,
	INVERTING_OCRA_MODE
}Timer1_OCRA_COMPARE_TYPE;


typedef enum
{
	DISCONNECTED_OCRB_MODE = 0,
	TOGGLE_OCRB_MODE,
	NONINVERTING_OCRB_MODE,
	INVERTING_OCRB_MODE
}Timer1_OCRB_COMPARE_TYPE;

typedef enum
{
	Timer1_OVF,
	Timer1_OCA,
	Timer1_OCB,
	Timer1_ICU
}TIMER1_INT_SOURCE_TYPE;


//=================================================================================================//
//================================configuration for TIMER0=========================================//
//=================================================================================================//

//Enum fro modes
typedef enum
{
	TIMER0_NORMAL_MODE = 0,
	TIMER0_PHASECORRECT_MODE,
	TIMER0_CTC_MODE,
	TIMER0_FASTPWM_MODE
}Timer0MODE_TYPE;


typedef enum
{
	TIMER0_STOP = 0,
	TIMER0_SCALER_1,
	TIMER0_SCALER_8,
	TIMER0_SCALER_64,
	TIMER0_SCALER_256,
	TIMER0_SCALER_1024,
	EXTERNAL0_FALLING,
	EXTERNAL0_RAISING
}Timer0SCALER_TYPE;

typedef enum
{
	DISCONNECTED_OC0_MODE = 0,
	TOGGLE_OC0_MODE,
	NONINVERTING_MODE,
	INVERTING_MODE
}Timer0COMPARE_TYPE;


typedef enum
{
	Timer0_OVF,
	Timer0_OC0
}TIMER0_INT_SOURCE_TYPE;










//================================TIMER0 PROTOTYPE===================================================================//

extern void Timer0_INIT(Timer0MODE_TYPE mode ,Timer0SCALER_TYPE scaler ,Timer0COMPARE_TYPE ModeOC0);
extern void TIMER0_OVEINT_Disable(void);
extern void TIMER0_OVEINT_Enable(void);
extern void TIMER0_OC0_Disable(void);
extern void TIMER0_OC0_Enable(void);
extern void Timer0_SETCALLBACK(TIMER0_INT_SOURCE_TYPE Interrupt ,void (*locaFptr0)(void));

//================================TIMER1 PROTOTYPE===================================================================//
extern void Timer1_INIT(Timer1_MODE_TYPE MODE_WG ,Timer1_SCALER_TYPE CLK_SLC ,Timer1_OCRA_COMPARE_TYPE MODE_OCRA,Timer1_OCRB_COMPARE_TYPE MODE_OCRB);
extern void Timer1_ICU_INT_DISABLE(void);
extern void Timer1_ICU_INT_ENABLE(void);
extern void Timer1_ICU_Edge(Timer1_Trigger_Edge edge);
extern void Timer1_OCB_INT_DISABLE(void);
extern void Timer1_OCB_INT_ENABLE(void);
extern void Timer1_OCA_INT_DISABLE(void);
extern void Timer1_OCA_INT_ENABLE(void);
extern void Timer1_OVF_INT_DISABLE(void);
extern void Timer1_OVF_INT_ENABLE(void);
extern void Timer1_SETCALLBACK(TIMER1_INT_SOURCE_TYPE Interrupt ,void (*locaFptr)(void));


#endif /* TIMER_H_ */