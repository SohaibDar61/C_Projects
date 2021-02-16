/*
 * ADC.c
 *
 * Created: 9/23/2019 5:15:57 AM
 *  Author: SOHAIB
 */ 


#include "ADC.h"


void ADC_Init(REF_type REF ,PreScaler_type PreScale)
{

	//v ref set
	if(REF==AREF)
	{
		CLEAR_BIT(ADMUX,REFS0);
		CLEAR_BIT(ADMUX,REFS1);
	}
	else if(REF==AVCC)
	{
		SET_BIT(ADMUX,REFS0);
		CLEAR_BIT(ADMUX,REFS1);
	}
	else if (REF==REF256V)
	{
		SET_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);
	}

	//ADC right Adjust Result
	CLEAR_BIT(ADMUX,ADLAR);
	
	//ADC left Adjust Result
	//SIT_BIT(ADMUX,ADLAR);

	//ADC enable
	SET_BIT(ADCSRA,ADEN);

	//Prescaler 128
	ADCSRA&=0XF8;
	ADCSRA|=PreScale;

}

void ADC_StartConversion(Channel_type CH)
{   ADMUX &=0xe0;
	ADMUX |= CH;
	//Start conv.
	SET_BIT(ADCSRA,ADSC);
}

u16 ADC_GetRead(void)
{
	u16 result;
	while(CHECK_BIT(ADCSRA,ADSC));
	result=  *((u16*)& ADCL);
	return result;
}


u16 ADC_GetRead_NoPolling(void)
{
	u16 result;
	result=  *((u16*)& ADCL);
	return result;

}


void ADC_Interrupt_Enable(void)
{
	SET_BIT(ADCSRA,ADIE);
}
void ADC_Interrupt_Disable(void)
{
	CLEAR_BIT(ADCSRA,ADIE);
}

























/*
#define ADC_BUSY (IS_BIT_CLEAR(ADCSRA,ADIF))
#define ADC ADCL



static void (*Call_Back_Fun)(u16);

ISR(ADC_vect)
{
	Call_Back_Fun(ADC);	
}


u16 ADC_read(Channel_SelectType channel)
{
	switch(channel)
	{
		//ASSIGN_REG(ADMUX,0x1F);
		ADMUX = 0x1F;
		case CHANNEL0:
		ASSIGN_REG(ADMUX,0x00);
		break;
		
		case CHANNEL1:
		//ASSIGN_REG(ADMUX,0x01);
		ADMUX = 0x01;
		break;
		
		case CHANNEL2:
		//ASSIGN_REG(ADMUX,0x02);
		ADMUX = 0x02;
		break;
		
		case CHANNEL3:
		//ASSIGN_REG(ADMUX,0x03);
        ADMUX = 0x03;
		break;
		
		case CHANNEL4:
        //ASSIGN_REG(ADMUX,0x04);
		ADMUX = 0x04;
        break;
		
        case CHANNEL5:
        //ASSIGN_REG(ADMUX,0x05);
		ADMUX = 0x05;
        break;
		
		case CHANNEL6:
		//ASSIGN_REG(ADMUX,0x06);
		ADMUX = 0x06;
		break;
		
		
		case CHANNEL7:
		//ASSIGN_REG(ADMUX,0x07);
		ADMUX = 0x07;
		break;
	}
	/*
	ACCESS_REG_8BIT(ADCMUX) &= ~0x1f;              // clear channels value
	ACCESS_REG_8BIT(ADCMUX) |= channel;				// set channel
	SET_BIT((ADCSRA,6);					// start conversion for one shoot
	while(ADC_BUSY);
	*/
	/*
	SET_BIT(ADCSRA,ADSC);
	while(ADC_BUSY);
	return ADC ;
}


void ADC_init(Vref_SelectType vref,Mode_SelectType mode,SCALAR_SelectType clk)
{
	
	switch(vref)
	{
		case AREF:
		CLEAR_BIT(ADMUX,REFS0);
		CLEAR_BIT(ADMUX,REFS1);
		break;
		
		case AVCC:
		SET_BIT(ADMUX,REFS0);
		CLEAR_BIT(ADMUX,REFS1);
		break;
		
		case INTERNAL_VREF:
		SET_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);
		break;
	}
	
	
	switch(mode)
	{
		case FREE_RUNNING_MODE:
		CLEAR_BIT(SFIOR,ADTS0);
		CLEAR_BIT(SFIOR,ADTS1);
		CLEAR_BIT(SFIOR,ADTS2);
		break;
		
		case ANALOG_COMPARTOR:
		SET_BIT(SFIOR,ADTS0);
		CLEAR_BIT(SFIOR,ADTS1);
		CLEAR_BIT(SFIOR,ADTS2);
		break;
		
		case EXTERNAL_INITERRUPT0:
		CLEAR_BIT(SFIOR,ADTS0);
		SET_BIT(SFIOR,ADTS1);
		CLEAR_BIT(SFIOR,ADTS2);
		break;
		
		case COMPARE_MATCH_TIMER0:
		SET_BIT(SFIOR,ADTS0);
		SET_BIT(SFIOR,ADTS1);
		CLEAR_BIT(SFIOR,ADTS2);
		break;
		
		case OVERFLOW_TIMER0:
		CLEAR_BIT(SFIOR,ADTS0);
		CLEAR_BIT(SFIOR,ADTS1);
		SET_BIT(SFIOR,ADTS2);
		break;
		
		
		case COMPARE_MATCH_TIMER1:
		SET_BIT(SFIOR,ADTS0);
		CLEAR_BIT(SFIOR,ADTS1);
		SET_BIT(SFIOR,ADTS2);
		break;
		
		
		case OVERFLOW_TIMER1:
		CLEAR_BIT(SFIOR,ADTS0);
		SET_BIT(SFIOR,ADTS1);
		SET_BIT(SFIOR,ADTS2);
		break;
		
		case Capture_TIMER1:
		SET_BIT(SFIOR,ADTS0);
		SET_BIT(SFIOR,ADTS1);
		SET_BIT(SFIOR,ADTS2);
		break;
	}
	
	if (mode != FREE_RUNNING_MODE)
	{
		SET_BIT(ADCSRA,ADATE);
	}
	// enable adc
	SET_BIT(ADCSRA ,ADEN);
	
	// set clock + set type of trigger
	ADCSRA |= (clk <<0);
}


void ADC_IntEnable(void (*F_callBack)(u16 val),Channel_SelectType channel)
{
	Call_Back_Fun = F_callBack;
	SET_BIT(ADCSRA,ADIE);
	ADMUX |= (channel);               // set channel
	SET_BIT(ADCSRA,ADSC);             // start conversion for one shoot
}





void ADC_StartConversion()
{
	
	SET_BIT( ADCSRA , ADSC);
	
}



/*
static void (*ptr_callBackFun)(u16);


void adc_init(ADC_cnfg* ptrADC, void(*ptr_func)(u16 val))
{
	ADCSRA = 0XFF;                                      //clear ADCSRA REG
	ADMUX   = 0XFF;                                     //clear ADCMUX REG
    ADMUX   |= ((ptrADC->vref)    << REFS0);            //V REFERENCE (REFS0,REFS1) (bit6,bit7) in ADMUX REG
	ADCSRA  |= ((ptrADC->clk)     << ADPS0);             //clock conversion (ADPS0,ADPS1,ADPS2) in ADCSRA REG
	SET_BIT((ADCBASE + CSRA_OFFSET),ADEN);                                   //SET EN BIT IN ACSRA REG
	SFIOR |= ((ptrADC->mode)    << ADTS0);               //mode (ADTS0,ADTS1,ADTS2)(bit 5,6,7) in SFIOR   REG
	if((ptrADC->mode) != FREE_RUNNING_MODE)
	{
		SET_BIT(ADCSRA,ADATE);                              //set trigger mode (ADATE BIT5)in ADCSRA REG
	}
	ptr_callBackFun = ptr_func;
}


u16 adc_read(channel_selectType channel)
{
	(ADMUX)   |= ((channel) << MUX0);
	SET_BIT(ADCSRA,ADSC);                              //start conversion (ADSC BIT 6) at ACSRA REG
	while((ADC_BUSY));
	(*ptr_callBackFun)(ADC);                           // check (ADC Interrupt Flag BIT 4) in ACSRA REG
	return ADC;
}



void adc_int(INT_cnfg adcint, channel_selectType channel, void (*ptr_func)(u16 val))
{
	(ADCSRA)  |= ((adcint)  << ADIE);
	(ADMUX)   |= ((channel) << MUX0);
	SET_BIT(ADCSRA,ADSC);                          // start conversion for one shoot
	ptr_callBackFun = ptr_func;
}

ISR(ADC_vect)
{
	sei();
	(*ptr_callBackFun)(ADC);
}



*/

