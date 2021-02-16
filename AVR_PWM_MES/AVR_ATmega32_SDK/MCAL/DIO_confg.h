/*
 * DIO_confg.h
 *
 * Created: 9/23/2019 4:34:39 AM
 *  Author: SOAHIB
 */ 


#ifndef DIO_CONFG_H_
#define DIO_CONFG_H_

#include "Mem_MAPPED.h"

typedef enum
{
	OUTPUT=0,
	INPULLUP,
	INFREE,
}PinStatus_type;

typedef enum
{
	PINA0=0,
	PINA1=1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7,
	PINB0,
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7,
	PINC0,
	PINC1,
	PINC2,
	PINC3,
	PINC4,
	PINC5,
	PINC6,
	PINC7,
	PIND0,
	PIND1,
	PIND2,
	PIND3,
	PIND4,
	PIND5,
	PIND6,
	PIND7,
	TOTAL_PINS
}PinNum_type;

extern const PinStatus_type PinsStatus[TOTAL_PINS];

#endif /* DIO_CONFG_H_ */