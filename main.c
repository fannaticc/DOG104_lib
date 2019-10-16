/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC16F18426
        Driver Version    :  2.00
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
#include <stdint.h>

#include "mcc_generated_files/mcc.h"
#include "dog104.h"
#include "my_delays.h"
#include "my_i2c.h"

/*
                         Main application
 */
void main(void)
{
    uint8_t arrowd[] = {0x04, 0x04, 0x04, 0x04, 0x15, 0x0E, 0x04, 0x00};
	uint8_t arrowu[8];
	uint8_t i = 0, j = 0;
	uint8_t charset1[] = {0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0};
	uint8_t charset2[] = {0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0xF9, 0};
    
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    //__delay_ms(10000);

    while(1) 
    {
        //Define own chars (arrow up and down)

        for(i = 0; i < 7; i++)
        {
            arrowu[i] = arrowd[6 - i];
        }
        
        initDispl(); //init display
        
        //define own characters
        DefineCharacter(0, arrowd);
        DefineCharacter(2, arrowu);

        DisplayOnOff(DISPLAY_ON); //Disable cursor
        i = CONTRSTART;
        
        while(1)
        {
            LED_LAT ^= 1;
            
            switch(j++)
            {
            case 0:
                DisplLines(DOUBLEHEIGHT_OFF);
                ClrDisplay();
                SetPostion(LINE1);
                WriteString("Ola mundo");
                SetPostion(LINE2);
                WriteString("olha o");
                SetPostion(LINE3);
                WriteString("display");
                SetPostion(LINE4);
                WriteString("funcionando");
                break;
            case 1:
                ClrDisplay();
                SetROM(ROMA);
                SetPostion(LINE1);
                WriteString("3char sets");
                SetPostion(LINE2);
                WriteString("ROMA-Euro1");
                SetPostion(LINE3);
                WriteString(charset1);
                SetPostion(LINE4);
                WriteString(charset2);
                break;
            case 2:
                ClrDisplay();
                SetROM(ROMB);
                SetPostion(LINE1);
                WriteString("3char sets");
                SetPostion(LINE2);
                WriteString("ROMB-Euro2");
                SetPostion(LINE3);
                WriteString(charset1);
                SetPostion(LINE4);
                WriteString(charset2);
                break;
            case 3:
                ClrDisplay();
                SetROM(ROMC);
                SetPostion(LINE1);
                WriteString("3char sets");
                SetPostion(LINE2);
                WriteString("ROMB-Japan");
                SetPostion(LINE3);
                WriteString(charset1);
                SetPostion(LINE4);
                WriteString(charset2);
                break;
            case 4:
                ClrDisplay();
                DisplLines(DOUBLEHEIGHT_TOP);
                SetPostion(LINE1);
                WriteString("5.2mm char");
                SetPostion(LINE2);
                WriteString("2.6mm char");
                SetPostion(LINE3);
                WriteString("----------");
                break;
            case 5:
                ClrDisplay();
                DisplLines(DOUBLEHEIGHT_MID);
                SetPostion(LINE1);
                WriteString("2.6mm char");
                SetPostion(LINE2);
                WriteString("5.2mm char");
                SetPostion(LINE3);
                WriteString("----------");
                break;
            case 6:
                ClrDisplay();
                DisplLines(DOUBLEHEIGHT_BOT);
                SetPostion(LINE1);
                WriteString("2.6mm char");
                SetPostion(LINE2);
                WriteString("----------");
                SetPostion(LINE3);
                WriteString("5.2mm char");
                break;
            case 7:
                ClrDisplay();
                DisplLines(DOUBLEHEIGHT_DOUBLE);
                SetPostion(LINE1);
                WriteString("5.2mm char");
                SetPostion(LINE2);
                WriteString("Big Letter");
                j = 0;
                break;
            default:
                j = 0;
                break;
            }

            if (i > (CONTRSTART + CONTRSPAN))
                i = CONTRSTART;

            SetContrast(i++); //show different contrast levels, using i as increment



            Delay_ms(TIME);
        }
    }
}
/**
 End of File
*/