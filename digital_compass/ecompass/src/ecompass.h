/*
 * ecompass.h
 *
 *  Created on: May 7, 2015
 *      Author: Richie Agpaoa
 */
#ifndef ECOMPASS_H
#define ECOMPASS_H

#include "board.h"

int closedHeading;
int currentHeading;

// Protoypes
void I2C_Init(I2C_ID_T id, int speed);
void I2C_Set_Mode(I2C_ID_T id, int polling);
void Compass_Init();

void writeReg(uint8_t regAddr, uint8_t regVal);
uint8_t readReg(uint8_t regAddr);

void enableCompass();
void disableCompass();
void readCompass();
void accRead(int16_t *acc);
void magRead(int16_t *mag);
float calcHeading(float *from);
float getHeading();
float vector_dot(float *a, float *b);
void vector_cross(float *a, float *b, float *out);
void vector_normalize(float *a);

#endif /* ECOMPASS_H */
