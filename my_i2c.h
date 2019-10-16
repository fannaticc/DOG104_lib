/* 
 * File:   my_i2c.h
 * Author: Raphael
 *
 * Created on 17 de Novembro de 2017, 09:56
 */

#ifndef MY_I2C_H
#define	MY_I2C_H

#include <stdint.h>

#define I2C1_SCL	TRISAbits.TRISA5
#define I2C1_SDA	TRISAbits.TRISA4

#define i2c_trys 20
//#define i2c_timeout_enable

uint16_t i2ctimeout = 0;
uint8_t i2c_error = 0;

unsigned char I2C_ReadByte(unsigned char acknowledge);
unsigned char I2C_WriteByte(unsigned char data_out);

void I2C_Init(unsigned char clock_output);
void I2C_Start(void);
void I2C_RepeatedStart(void);
void I2C_Stop(void);
void I2C_Idle(void);
void I2C_Close(void);
void I2C_falsepulses();

#endif	/* MY_I2C_H */

