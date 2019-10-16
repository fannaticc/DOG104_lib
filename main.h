/* 
 * File:   main.h
 * Author: raphael.pereira
 *
 * Created on 14 de Fevereiro de 2019, 10:18
 */

#ifndef MAIN_H
#define	MAIN_H

#include <stdint.h>

#include "adxl355.h"

#define TEMP_COEF1 0
#define TEMP_COEF2 1

union float_modbus{
    float float_32;
    uint16_t unsigned_16[2];
};

union floatto16bits{
    float value_32;
    uint16_t value_16[2];
};

struct axis_value acc_value;
struct g_value acc_g;
union floatto16bits value;
struct fixedpoint returnfixedvalue;

void Get_New_Reads();
int16_t fixfloat(float value, float multiplier);

#endif	/* MAIN_H */

