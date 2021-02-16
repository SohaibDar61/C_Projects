/*
 * Timer.c
 *
 * Created: 9/23/2019 6:10:57 AM
 *  Author: SOHAIB
 */ 



#include "Timer.h"

#include "Mem_MAPPED.h"
/******************************************************************************************************/
/*********************************************Timer 0**************************************************/
/******************************************************************************************************/

void Timer0_INIT(Timer0MODE_TYPE mode ,Timer0SCALER_TYPE scaler,Timer0COMPARE_TYPE ModeOC0)
{
	switch(mode)
	{
		case TIMER0_NORMAL_MODE:
		CLEAR_BIT(TCCR0,WGM00);
		CLEAR_BIT(TCCR0,WGM01);
		break;
		case TIMER0_CTC_MODE:
		CLEAR_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		break;
		case TIMER0_PHASECORRECT_MODE:
		SET_BIT(TCCR0,WGM00);
		CLEAR_BIT(TCCR0,WGM01);
		break;
		case TIMER0_FASTPWM_MODE:
		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		break;
	}
	
	switch(ModeOC0)
	{
		case DISCONNECTED_OC0_MODE:
		CLEAR_BIT(TCCR0,COM00);
		CLEAR_BIT(TCCR0,COM01);
		break;
		
		case TOGGLE_OC0_MODE:
		SET_BIT(TCCR0,COM00);
		CLEAR_BIT(TCCR0,COM01);
		break;
		
		case NONINVERTING_MODE:
		CLEAR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
		break;
		
		case INVERTING_MODE:
		CLEAR_BIT(TCCR0,COM00);
		CLEAR_BIT(TCCR0,COM01);
		break;
	}
	
	TCCR0 &= 0XF8;
	TCCR0 |=scaler;
}


void TIMER0_OVEINT_Enable(void)
{
	SET_BIT(TIMSK,TOIE0);
}
void TIMER0_OVEINT_Disable(void)
{
	CLEAR_BIT(TIMSK,TOIE0);
}


void TIMER0_OC0_Enable(void)
{
	SET_BIT(TIMSK,OCIE0);
}
void TIMER0_OC0_Disable(void)
{
	CLEAR_BIT(TIMSK,OCIE0);
}





/******************************************************************************************************/
/*********************************************Timer 1**************************************************/
/******************************************************************************************************/



void Timer1_INIT(Timer1_MODE_TYPE MODE_WG ,Timer1_SCALER_TYPE CLK_SLC ,Timer1_OCRA_COMPARE_TYPE MODE_OCRA,Timer1_OCRB_COMPARE_TYPE MODE_OCRB)
{
	switch(MODE_WG)
	{
		case TIMER1_NORMAL_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		CLEAR_BIT(TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;
		
		
		case TIMER1_FASTPWM_ICR1_TOP_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
		
		
		case TIMER1_FASTPWM_OCR1A_TOP_MODE:
		SET_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
	}
	TCCR1B &=0XF8;
	TCCR1B |=CLK_SLC;
	
	
	switch(MODE_OCRA)
	{
		case DISCONNECTED_OCRA_MODE:
		CLEAR_BIT(TCCR1A ,COM1A0);
		CLEAR_BIT(TCCR1A ,COM1A1);
		break;
		
		case TOGGLE_OCRA_MODE:
		SET_BIT(TCCR1A,COM1A0);
		CLEAR_BIT(TCCR1A,COM1A1);
		
		case NONINVERTING_OCRA_MODE:
		CLEAR_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);

		case INVERTING_OCRA_MODE:
		SET_BIT(TCCR1A ,COM1A0);
		SET_BIT(TCCR1A ,COM1A1);
	}
	
	DDRD |= (1<<PIND5);
	DDRD |= (1<<PIND4);
	
	switch(MODE_OCRB)
	{
		case DISCONNECTED_OCRB_MODE:
		CLEAR_BIT(TCCR1A ,COM1B0);
		CLEAR_BIT(TCCR1A ,COM1B1);
		break;
		
		case TOGGLE_OCRB_MODE:
		SET_BIT(TCCR1A ,COM1B0);
		CLEAR_BIT(TCCR1A ,COM1B1);
		
		case NONINVERTING_OCRB_MODE:
		CLEAR_BIT(TCCR1A ,COM1B0);
		SET_BIT(TCCR1A ,COM1B1);

		case INVERTING_OCRB_MODE:
		SET_BIT(TCCR1A ,COM1B0);
		SET_BIT(TCCR1A ,COM1B1);
	}
}



void Timer1_OVF_INT_ENABLE(void)
{
	SET_BIT(TIMSK,TOIE1);
}

void Timer1_OVF_INT_DISABLE(void)
{
	CLEAR_BIT(TIMSK,TOIE1);
}



void Timer1_OCA_INT_ENABLE(void)
{
	SET_BIT(TIMSK,OCIE1A);
}

void Timer1_OCA_INT_DISABLE(void)
{
	CLEAR_BIT(TIMSK,OCIE1A);
}





void Timer1_OCB_INT_ENABLE(void)
{
	SET_BIT(TIMSK,OCIE1B);
}

void Timer1_OCB_INT_DISABLE(void)
{
	CLEAR_BIT(TIMSK,OCIE1B);
}



void Timer1_ICU_INT_ENABLE(void)
{
	SET_BIT(TIMSK,TICIE1);
}

void Timer1_ICU_INT_DISABLE(void)
{
	CLEAR_BIT(TIMSK,TICIE1);
}




void Timer1_ICU_Edge(Timer1_Trigger_Edge edge)
{
	if(edge == TIMER1_ICU_FALLING_EDGE)
	{
		SET_BIT(TCCR1B,ICES1);
	}
	else if(edge == TIMER1_ICU_RAISING_EDGE)
	{
		CLEAR_BIT(TCCR1B,ICES1);
	}
}




/****************************Timer 1 Call Back Functions***************************************/

static void (*Timer1_OVF_Fptr)(void)= NULLPTR;
static void (*Timer1_OCA_Fptr)(void)= NULLPTR;
static void (*Timer1_OCB_Fptr)(void)= NULLPTR;
static void (*Timer1_ICU_Fptr)(void)= NULLPTR;



void Timer1_SETCALLBACK(TIMER1_INT_SOURCE_TYPE Interrupt ,void (*local_Fptr)(void))
{
	switch(Interrupt)
	{
		case Timer1_OVF:
		Timer1_OVF_Fptr = local_Fptr;
		break;
		case Timer1_OCA:
		Timer1_OCA_Fptr = local_Fptr;
		break;
		case  Timer1_OCB:
		Timer1_OCB_Fptr = local_Fptr;
		break;
		case  Timer1_ICU:
		Timer1_ICU_Fptr = local_Fptr;
		break;
	}
}


//=================================================================================================//
//================================ISR TIMERS=======================================================//
//=================================================================================================//
 
 ISR(TIMER1_ICU_vect)
{
	 if(Timer1_ICU_Fptr!=NULLPTR)
	 {
		 Timer1_ICU_Fptr();
	 }
}

  
 ISR(TIMER1_OCA_vect)
{
	 if(Timer1_OCA_Fptr != NULLPTR)
	 {
		 Timer1_OCA_Fptr();
	 }
}


ISR(TIMER1_OCB_vect)
{
	if(Timer1_OCB_Fptr != NULLPTR)
	{
		Timer1_OCB_Fptr();
	}
}


ISR(TIMER1_OVF_vect)
{
	if(Timer1_OVF_Fptr != NULLPTR)
	{
		Timer1_OVF_Fptr();
	}
}




/****************************Timer 0 Call Back Functions***************************************/


static void (*Timer0_OC0_Fptr)(void)= NULLPTR;
static void (*TIMER0_OVF_Fptr)(void)= NULLPTR;


void Timer0_SETCALLBACK(TIMER0_INT_SOURCE_TYPE Interrupt ,void (*local_Fptr)(void))
{
	switch(Interrupt)
	{
		case Timer0_OVF:
		TIMER0_OVF_Fptr = local_Fptr;
		break;
		case Timer0_OC0:
		Timer0_OC0_Fptr = local_Fptr;
		break;
	}

}

//=================================================================================================//
//================================ISR TIMERS=======================================================//
//=================================================================================================//

ISR(TIMER0_OVF_vect)
{
	if(TIMER0_OVF_Fptr != NULLPTR)
	{
		TIMER0_OVF_Fptr();
	}
}


ISR(TIMER0_OC0_vect)
{
	if(Timer0_OC0_Fptr != NULLPTR)
	{
		Timer0_OC0_Fptr();
	}
}



