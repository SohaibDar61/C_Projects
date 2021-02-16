/*
 * Utilies.h
 *
 * Created: 9/23/2019 4:18:39 AM
 *  Author: SOHAIB
 */ 


#ifndef UTILIES_H_
#define UTILIES_H_


#define ACCESS_REG_8BIT(REG)         (*(volatile u8*)REG)

#define ACCESS_REG_16BIT(REG)        (*(volatile u16*)REG)

#define SET_REG(Reg) Reg=0xFF

#define CLEAR_REG(Reg) Reg=0x00

#define TOOGLE_REG(Reg) Reg^=0xFF

#define ASSIGN_REG(Reg,Value) Reg=Value

#define SET_BITS_REG(Reg,Mask) Reg|=(Mask)

#define CLEAR_BITS_REG(Reg,Mask) Reg=(Reg&(~Mask))

#define SET_BIT(Reg,bit) Reg|=(1<<bit)

#define CLEAR_BIT(Reg,bit) Reg=(Reg&(~(1<<bit)))

#define TOOGLE_BIT(Reg,bit) Reg^=(1<<bit)

#define CHECK_BIT(Reg,bit) ((Reg>>bit)&1)

#define IS_BIT_SET(REG,BIT_NUM)      ((ACCESS_REG_8BIT(REG) & (1 << BIT_NUM)))

#define IS_BIT_CLEAR(REG,BIT_NUM)    (!(IS_BIT_SET(REG,BIT_NUM)))





#endif /* UTILIES_H_ */