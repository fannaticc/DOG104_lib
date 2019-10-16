# 1 "dog104.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.00\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "dog104.c" 2







# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.00\\pic\\include\\c99\\stdint.h" 1 3



# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.00\\pic\\include\\c99\\musl_xc8.h" 1 3
# 4 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.00\\pic\\include\\c99\\stdint.h" 2 3
# 22 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.00\\pic\\include\\c99\\stdint.h" 3
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.00\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 135 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.00\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned long uintptr_t;
# 150 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.00\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long intptr_t;
# 166 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.00\\pic\\include\\c99\\bits/alltypes.h" 3
typedef signed char int8_t;




typedef short int16_t;




typedef long int32_t;
# 189 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.00\\pic\\include\\c99\\bits/alltypes.h" 3
typedef int32_t intmax_t;







typedef unsigned char uint8_t;




typedef unsigned short uint16_t;




typedef unsigned long uint32_t;
# 225 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.00\\pic\\include\\c99\\bits/alltypes.h" 3
typedef uint32_t uintmax_t;
# 22 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.00\\pic\\include\\c99\\stdint.h" 2 3


typedef int8_t int_fast8_t;




typedef int8_t int_least8_t;
typedef int16_t int_least16_t;
typedef int32_t int_least32_t;




typedef uint8_t uint_fast8_t;




typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;
typedef uint32_t uint_least32_t;
# 131 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.00\\pic\\include\\c99\\stdint.h" 3
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.00\\pic\\include\\c99\\bits/stdint.h" 1 3
typedef int32_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint32_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
# 131 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.00\\pic\\include\\c99\\stdint.h" 2 3
# 8 "dog104.c" 2

# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.00\\pic\\include\\c99\\stdbool.h" 1 3
# 9 "dog104.c" 2


# 1 "./dog104.h" 1
# 66 "./dog104.h"
void initDispl(void);
void WriteChar(int8_t character);
void WriteString(int8_t *stringi);
void SetPostion(int8_t pos);
void DisplayOnOff(int8_t data);
void DefineCharacter(uint8_t postion, uint8_t *data);
void ClrDisplay(void);
void SetContrast(uint8_t contr);
void SetView(uint8_t view);
void SetROM(uint8_t value);
void DisplLines(uint8_t lines);




void WriteIns(int8_t ins);
void WriteData(int8_t data);

uint8_t CheckBusy(void);
void IIC_put(uint8_t cb, uint8_t db);
static uint8_t IIC_get(void);
# 11 "dog104.c" 2

# 1 "./my_i2c.h" 1
# 19 "./my_i2c.h"
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
# 12 "dog104.c" 2




unsigned char dh_function_set = 0x38;




void Wait (uint8_t waitstates)
{
 uint8_t i = 0;
 for (i = 0; i < waitstates; i++)
 {
  __asm("NOP");
 }
}





void initDispl(void)
{
 uint8_t i;
# 45 "dog104.c"
 WriteIns(0x3A);
 WriteIns(0x09);

 WriteIns(0x06);




 WriteIns(0x1E);
 WriteIns(0x39);
 WriteIns(0x1B);
 WriteIns(0x6E);
 WriteIns(0x56);
 WriteIns(0x7A);
 WriteIns(dh_function_set);

 ClrDisplay();
 DisplayOnOff(0x04 | 0x02 | 0x01);
}





void WriteChar(int8_t character)
{
 WriteData(character);
}





void WriteString(int8_t *stringi)
{
 do
 {
  WriteData(*stringi++);
 }
 while(*stringi);
}





void DisplLines(uint8_t lines)
{
 if(lines == 0x38)
 {
  WriteIns(lines);
  dh_function_set = 0x38;
 }
 else
 {
  WriteIns(0x3C);
  WriteIns(0x3A);
  WriteIns(lines);
  WriteIns(0x3C);
  dh_function_set = 0x3C;
 }
}





void SetPostion(int8_t pos)
{
 WriteIns(0x80 + pos);
}





void DisplayOnOff(int8_t data)
{
 WriteIns(0x08 + data);
}





void DefineCharacter(uint8_t postion, uint8_t *data)
{
 uint8_t i = 0;
 WriteIns(0x40 + 8 * postion);

 for (i = 0; i < 8; i++)
 {
  WriteData(data[i]);
 }
 SetPostion(0);
}





void ClrDisplay(void)
{
 WriteIns(0x01);
 SetPostion(0);
}





void SetContrast(uint8_t contr)
{
 WriteIns(0x39);
 WriteIns(0x54 | (contr >> 4));
 WriteIns(0x70 | (contr & 0x0F));
 WriteIns(dh_function_set);
}





void SetView(uint8_t view)
{
 WriteIns(0x3A);
 WriteIns(view);
 WriteIns(dh_function_set);
}





void SetROM(uint8_t value)
{
 WriteIns(0x2A);
 WriteIns(0x72);
 WriteData(value);
 WriteIns(0x28);
}





void WriteIns(int8_t ins)
{
 while(CheckBusy() == 1);
 IIC_put(0x80, ins);
}





void WriteData(int8_t data)
{
 while(CheckBusy() == 1);
 IIC_put(0x40, data);
}





uint8_t CheckBusy(void)
{
    return (IIC_get() & 0x80);
}






void IIC_put(uint8_t cb, uint8_t db)
{
    I2C_Start();
 I2C_WriteByte(0x78);
 I2C_WriteByte(cb);
 I2C_WriteByte(db);
 I2C_Stop();
}





static uint8_t IIC_get(void)
{
 uint8_t ret;

    I2C_Start();
    I2C_WriteByte(0x78);
    I2C_WriteByte(0x80);
    I2C_RepeatedStart();
    I2C_WriteByte(0x78 + 1);
    ret = I2C_ReadByte(0);
    I2C_Stop();

 return ret;
}
