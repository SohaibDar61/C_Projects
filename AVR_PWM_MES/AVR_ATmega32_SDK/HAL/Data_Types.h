/*
 * data_types.h
 *
 * Created: 9/23/2019 2:59:28 AM
 *  Author: SOHAIB
 *
 *	header file for data types portability 
 */ 


#ifndef DATA_TYPES_H_
#define DATA_TYPES_H_

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned long  u32;
typedef signed long   s32;
typedef unsigned long long   u64;
typedef signed long  long    s64;
typedef float f32;
typedef double f64;


#define No_error  1
#define error_happen 0
#define OVER_ERROR -1
#define TRUE (u8)0x01
#define FALSE (u8)0x00
#define NULLPTR   ((void*)0)




#endif /* DATA_TYPES_H_ */