/*
 * hw_spi.h
 *
 * Created: 10/14/2017 10:15:34 AM
 *  Author: Ahmed
 */ 


#ifndef HW_SPI_H_
#define HW_SPI_H_

#define SPI_DATA_REG			0x2F
#define SPI_STATUS_REG			0x2E
#define SPI_CONTROL_REG			0x2D



#define SPI_FLAG_SPSR			0x07

#define SPI_ENABLE_SPCR			0x06
#define SPI_MASTER_MODE_SPCR	0x04 
#define SPI_FREQ0_SPCR			0x00
#define SPI_FREQ1_SPCR			0x01



#endif /* HW_SPI_H_ */