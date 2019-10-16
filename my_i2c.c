/* 
 * File:   my_i2c.c
 * Author: Raphael
 *
 * Created on 17 de Novembro de 2017, 09:56
 */

#include <xc.h>
#include "my_i2c.h"
#include "mcc_generated_files/pin_manager.h"

void I2C_Init(unsigned char clock_output)
{
#ifdef p16f18323
    SSP1STAT &= 0x3F; // Power on state
    SSPCON1 = 0x00; // Power on state
    SSPCON2 = 0x00; // Power on state
    SSPCON1 |= 0b00001000; // Select serial mode
    SSP1STAT |= 0b10000000; // Slew rate on/off
    
    I2C1_SCL = 1; // Set SCL1 (PORTC,3) pin to input
    I2C1_SDA = 1; // Set SDA1 (PORTC,4) pin to input
    
    SSPCON1 |= 0b00100000; // Enable synchronous serial port

    SSP1ADD = clock_output; // Clock = FOSC/(4 * (SSP1ADD + 1))
#endif

    SSP1STAT &= 0x3F; // Power on state
    SSP1CON1 = 0x00; // Power on state
    SSP1CON2 = 0x00; // Power on state
    SSP1CON1 |= 0b00001000; // Select serial mode
    SSP1STAT |= 0b10000000; // Slew rate on/off
    
    SSP1CON1 |= 0b00100000; // Enable synchronous serial port*
    
    //SSP1ADD = clock_output; // Clock = FOSC/(4 * (SSP1ADD + 1))
   
}

void I2C_Start(void)
{
    I2C_Idle();
    
    SSP1CON2bits.SEN = 1;
    
    while(SSP1CON2bits.SEN);
}

void I2C_RepeatedStart(void)
{
    I2C_Idle();
    
    SSP1CON2bits.RSEN = 1;
    
    while(SSP1CON2bits.RSEN);
}

void I2C_Stop(void)
{
    I2C_Idle();
    SSP1CON2bits.PEN = 1;
    
    i2ctimeout = 0;
    
    while(SSP1CON2bits.PEN)
    {
#ifdef i2c_timeout_enable
        i2ctimeout++;
        if(i2ctimeout == i2c_trys)
        {
            i2c_error = 1;
            I2C_falsepulses();
            break;
        }
#endif
    }
}

void I2C_Idle(void)
{
    i2ctimeout = 0;
    
    while((SSP1CON2 & 0x1F) | (SSP1STATbits.R_nW))
    {
#ifdef i2c_timeout_enable
        i2ctimeout++;
        if(i2ctimeout == i2c_trys)
        {
            i2c_error = 1;
            I2C_falsepulses();
            break;
        }
#endif
    }
}

void I2C_Close(void)
{
    SSP1CON1 &= 0xDF;
}

unsigned char I2C_ReadByte(unsigned char acknowledge)
{
    unsigned char buffer_I2C = 0;
    
    I2C_Idle();
    
    if(((SSP1CON1 & 0x0F) == 0x08) || ((SSP1CON1 & 0x0F) == 0x0B)) //Master mode only
    {
        SSP1CON2bits.RCEN = 1; // Enable master for 1 byte reception
    }
    
    i2ctimeout = 0;
    
    while(!SSP1STATbits.BF) // Wait until byte received
    {
#ifdef i2c_timeout_enable
        i2ctimeout++;
        if(i2ctimeout == i2c_trys)
        {
            i2c_error = 1;
            I2C_falsepulses();
            break;
        }
#endif
    }
    i2ctimeout = 0;
    
    buffer_I2C = SSP1BUF; // Read byte

    I2C_Idle();
    
    if(acknowledge == 1)
    {
        SSP1CON2bits.ACKDT = 0;
        SSP1CON2bits.ACKEN = 1;
        
        i2ctimeout = 0;
        
        while(SSP1CON2bits.ACKEN)
        {
#ifdef i2c_timeout_enable
            i2ctimeout++;
            if(i2ctimeout == i2c_trys)
            {
                i2c_error = 1;
                I2C_falsepulses();
                break;
            }
#endif
        }
    }
    else
    {
        SSP1CON2bits.ACKDT = 1;
        SSP1CON2bits.ACKEN = 1;
        
        i2ctimeout = 0;
        
        while(SSP1CON2bits.ACKEN)
        {
#ifdef i2c_timeout_enable
            i2ctimeout++;
            if (i2ctimeout == i2c_trys)
            {
                i2c_error = 1;
                I2C_falsepulses();
                break;
            }
#endif
        }
    }
    
    return (buffer_I2C); // Return with read byte
}

unsigned char I2C_WriteByte(unsigned char data_out)
{
    I2C_Idle();
    
    SSP1BUF = data_out; // Write single byte to SSP1BUF
    
    if(SSP1CON1bits.WCOL) // Test if write collision occurred
    {
        return (1); // If WCOL bit is set return negative #
    }
    else
    {
        if(((SSP1CON1 & 0x0F) == 0x08) || ((SSP1CON1 & 0x0F) == 0x0B)) //master mode only
        {
            i2ctimeout = 0;
            
            while (SSP1STATbits.BF) // Wait until write cycle is complete
            {
#ifdef i2c_timeout_enable
                i2ctimeout++;
                if (i2ctimeout == 2000)
                {
                    i2c_error = 1;
                    I2C_falsepulses();
                    break;
                }
#endif
            }
            
            I2C_Idle(); // Ensure module is idle
            
            if(SSP1CON2bits.ACKSTAT) // Test for ACK condition received
            {
                return (2); // Return NACK
            }
            else
            {
                return (0); // Return ACK
            }
        }
    }
    
    return (0);
}

void I2C_falsepulses()
{
    for(uint8_t i = 0; i < 9; i++)
    {
        SCL1_TRIS = 0;
        NOP();
        SCL1_TRIS = 1;
        NOP();
    }
}