/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC16F18426
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.05 and above
        MPLAB 	          :  MPLAB X 5.20	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set SDA1 aliases
#define SDA1_TRIS                 TRISAbits.TRISA4
#define SDA1_LAT                  LATAbits.LATA4
#define SDA1_PORT                 PORTAbits.RA4
#define SDA1_WPU                  WPUAbits.WPUA4
#define SDA1_OD                   ODCONAbits.ODCA4
#define SDA1_ANS                  ANSELAbits.ANSA4
#define SDA1_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define SDA1_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define SDA1_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define SDA1_GetValue()           PORTAbits.RA4
#define SDA1_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define SDA1_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define SDA1_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define SDA1_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define SDA1_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define SDA1_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define SDA1_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define SDA1_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set SCL1 aliases
#define SCL1_TRIS                 TRISAbits.TRISA5
#define SCL1_LAT                  LATAbits.LATA5
#define SCL1_PORT                 PORTAbits.RA5
#define SCL1_WPU                  WPUAbits.WPUA5
#define SCL1_OD                   ODCONAbits.ODCA5
#define SCL1_ANS                  ANSELAbits.ANSA5
#define SCL1_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define SCL1_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define SCL1_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define SCL1_GetValue()           PORTAbits.RA5
#define SCL1_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define SCL1_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define SCL1_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define SCL1_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define SCL1_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define SCL1_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define SCL1_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define SCL1_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set LED aliases
#define LED_TRIS                 TRISCbits.TRISC1
#define LED_LAT                  LATCbits.LATC1
#define LED_PORT                 PORTCbits.RC1
#define LED_WPU                  WPUCbits.WPUC1
#define LED_OD                   ODCONCbits.ODCC1
#define LED_ANS                  ANSELCbits.ANSC1
#define LED_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define LED_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define LED_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define LED_GetValue()           PORTCbits.RC1
#define LED_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define LED_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define LED_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define LED_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define LED_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define LED_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define LED_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set EN_ACC aliases
#define EN_ACC_TRIS                 TRISCbits.TRISC2
#define EN_ACC_LAT                  LATCbits.LATC2
#define EN_ACC_PORT                 PORTCbits.RC2
#define EN_ACC_WPU                  WPUCbits.WPUC2
#define EN_ACC_OD                   ODCONCbits.ODCC2
#define EN_ACC_ANS                  ANSELCbits.ANSC2
#define EN_ACC_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define EN_ACC_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define EN_ACC_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define EN_ACC_GetValue()           PORTCbits.RC2
#define EN_ACC_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define EN_ACC_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define EN_ACC_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define EN_ACC_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define EN_ACC_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define EN_ACC_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define EN_ACC_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define EN_ACC_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/