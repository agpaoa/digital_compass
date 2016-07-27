/*
 * ecompass.h
 *
 *  Created on: May 7, 2015
 *      Author: Richie Agpaoa
 */
#ifndef ECOMPASS_H
#define ECOMPASS_H

#include "board.h"

// Structures
typedef struct _Accelerometer {
	int16_t x;
	int16_t y;
	int16_t z;
} Accelerometer;

typedef struct _Magnetometer {
	int16_t x;
	int16_t y;
	int16_t z;
} Magnetometer;

typedef struct _Compass {
	float heading;
	float pitch;
	float roll;
} Compass;

// Protoypes
void I2C_Init(I2C_ID_T id, int speed);
void I2C_Set_Mode(I2C_ID_T id, int polling);
void Compass_Init();

void writeReg(uint8_t regAddr, uint8_t regVal);
uint8_t readReg(uint8_t regAddr);

void enableCompass();
void disableCompass();
void readCompass(Compass *comp);
void accRead(Accelerometer *a);
void magRead(Magnetometer *m);
float calcHeading(float *from, Accelerometer *acc, Magnetometer *mag);
float getHeading();
float getPitch();
float getRoll();
float vector_dot(float *a, float *b);
void vector_cross(float *a, float *b, float *out);
void vector_normalize(float *a);

#endif /* ECOMPASS_H */
