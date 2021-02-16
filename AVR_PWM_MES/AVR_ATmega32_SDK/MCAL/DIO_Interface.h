/*
 * gpio.h
 *
 * Created: 9/23/2019 4:18:39 AM
 *  Author: SOHAIB
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "Data_Types.h"
#include "Mem_MAPPED.h"
#include "DIO_confg.h"
#include "Utilies.h"

typedef enum
{
	PA=0,
	PB,
	PC,
	PD,
}Port_type;

typedef enum
{
	LOW=0,
	HIGH=1,
}VoltageLevel_type;

extern void DIO_Init(void);
extern void DIO_WritePort(Port_type Port, u8 Value);
extern void DIO_WriteBitsInPort(Port_type Port,u8 Value,u8 Mask);
extern u8 DIO_ReadPort(Port_type Port);
extern void DIO_WritePin(PinNum_type Pin,VoltageLevel_type Value);
extern void DIO_TogglePin(PinNum_type Pin);
extern VoltageLevel_type DIO_ReadPin(PinNum_type Pin);



#endif /* DIO_INTERFACE_H_ */