/*
 * EX_INT.h
 *
 * Created: 9/23/2019 5:25:57 AM
 *  Author: SOHAIB
 */ 


#ifndef EX_INT_H_
#define EX_INT_H_


#include "Data_Types.h"
#include "Utilies.h"
#include "Mem_MAPPED.h"

typedef enum{
	LOW_LEVEL=0,
	ANY_LOGIC_CHANGE,
	FALLING_EDGE,
	RISING_EDGE,
}TriggerEdge_type;

typedef enum{
	EX_INT0=0,
	EX_INT1,
	EX_INT2
}ExInterruptSource_type;

void EXI_Enable(ExInterruptSource_type Interrupt);
void EXI_Disable(ExInterruptSource_type Interrupt);
void EXI_TriggerEdge(ExInterruptSource_type Interrupt,TriggerEdge_type Edge);
void EXI_SetCallBack(ExInterruptSource_type Interrupt,void(*LocalPtr)(void));





#endif /* EX_INT_H_ */