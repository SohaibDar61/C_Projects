/*
 * ADC.h
 *
 * Created: 9/23/2019 5:20:57 AM
 *  Author: SOHAIB
 */ 


#ifndef ADC_H_
#define ADC_H_
#include "Data_Types.h"
#include "Mem_MAPPED.h"
#include "Utilies.h"

typedef enum
{
	CH_0=0x00,
	CH_1=0x01,
	CH_2=0x02,
	CH_3=0x03,
	CH_4=0x04,
	CH_5=0x05,
	CH_6=0x06,
	CH_7=0x07,
}Channel_type;

typedef enum
{
	AREF    =0x00,
	AVCC    =0x01,
	REF256V =0x03

}REF_type;

typedef enum
{
	scale_2   =0x00,
	scale_4   =0x02,
	scale_8   =0x03,
	scale_16  =0x04,
	scale_32  =0x05,
	scale_64  =0x06,
	scale_128 =0x07,
}PreScaler_type;

extern	void ADC_Init(REF_type REF ,PreScaler_type PreScale);
extern	void ADC_StartConversion(Channel_type CH);
extern	u16 ADC_GetRead(void);
extern	u16 ADC_GetRead_NoPolling(void);
extern	void ADC_Interrupt_Enable(void);
extern	void ADC_Interrupt_Disable(void);











/*
typedef enum
{
	CLK_2,
	CLK_4 = 2,
	CLK_8 = 3,
	CLK_16 = 4,
	CLK_32 = 5,
	CLK_64 = 6,
	CLK_128 = 7,
} SCALAR_SelectType;


typedef enum
{
	AREF = 0,
	AVCC = 1,
	INTERNAL_VREF = 3,
} Vref_SelectType;


typedef enum
{
	FREE_RUNNING_MODE = 0,
	ANALOG_COMPARTOR = 1,
	EXTERNAL_INITERRUPT0 = 2,
	COMPARE_MATCH_TIMER0 = 3,
	OVERFLOW_TIMER0 = 4,
	COMPARE_MATCH_TIMER1=5,
	OVERFLOW_TIMER1=6,
	Capture_TIMER1=7
} Mode_SelectType;

typedef enum
{
	CHANNEL0,
	CHANNEL1,
	CHANNEL2,
	CHANNEL3,
	CHANNEL4,
	CHANNEL5,
	CHANNEL6,
	CHANNEL7,
} Channel_SelectType;



void ADC_init(Vref_SelectType vref,Mode_SelectType mode,SCALAR_SelectType clk);
u16 ADC_read(Channel_SelectType channel);
void ADC_IntEnable(void (*F_callBack)(u16 val),Channel_SelectType channel);
void ADC_StartConversion();



/*

typedef enum
{
	AREF_OFF      = 0,
	AVCC          = 1,
	INTERNAL_VREF = 3,
}vref_selectType;

typedef enum
{
	FREE_RUNNING_MODE    = 0,
	ANALOG_COMPARTOR     = 1,
	EXTERNAL_INITERRUPT0 = 2,
	COMPARE_MATCH_TIMER0 = 3,
	OVERFLOW_TIMER0      = 4,
	COMPARE_MATCH_TIMER1 = 5,
	OVERFLOW_TIMER1      = 6,
}mode_selectType;

typedef enum
{
	CLK_ADC_DIV_2   = 0,
	CLK_ADC_DIV_4   = 2,
	CLK_ADC_DIV_8   = 3,
	CLK_ADC_DIV_16  = 4,
	CLK_ADC_DIV_32  = 5,
	CLK_ADC_DIV_64  = 6,
	CLK_ADC_DIV_128 = 7,
}clk_selectType;

typedef enum
{
	CHANNEL0,
	CHANNEL1,
	CHANNEL2,
	CHANNEL3,
	CHANNEL4,
	CHANNEL5,
	CHANNEL6,
	CHANNEL7,
}channel_selectType;

typedef enum            //ADC Interrupt Enable
{
	ADC_DISABLE,
	ADC_ENABLE
}INT_cnfg;


typedef struct
{
	vref_selectType    vref;
	clk_selectType     clk;
	mode_selectType    mode;
}ADC_cnfg;


void  adc_init(ADC_cnfg* ptrADC,void (*ptr_func)(u16 val));

u16 adc_read(channel_selectType channel);

void  adc_int(INT_cnfg adcint, channel_selectType channel, void (*ptr_func)(u16 val));

*/





#endif /* ADC_H_ */