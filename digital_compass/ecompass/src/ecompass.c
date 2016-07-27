/*
 * @brief I2C example
 * This example show how to use the I2C interface
 *
 * @note
 * Copyright(C) NXP Semiconductors, 2012
 * All rights reserved.
 *
 * @par
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * LPC products.  This software is supplied "AS IS" without any warranties of
 * any kind, and NXP Semiconductors and its licensor disclaim any and
 * all warranties, express or implied, including all implied warranties of
 * merchantability, fitness for a particular purpose and non-infringement of
 * intellectual property rights.  NXP Semiconductors assumes no responsibility
 * or liability for the use of the software, conveys no license or rights under any
 * patent, copyright, mask work right, or any other intellectual property rights in
 * or to any products. NXP Semiconductors reserves the right to make changes
 * in the software without notification. NXP Semiconductors also makes no
 * representation or warranty that such application will be suitable for the
 * specified use without further testing or modification.
 *
 * @par
 * Permission to use, copy, modify, and distribute this software and its
 * documentation is hereby granted, under NXP Semiconductors' and its
 * licensor's relevant copyrights in the software, without fee, provided that it
 * is used in conjunction with NXP Semiconductors microcontrollers.  This
 * copyright, permission, and disclaimer notice must appear in all copies of
 * this code.
 */

#include <math.h>
#include "board.h"
#include "ecompass.h"
#include "LSM303D.h"

// Defines
#define I2C_ECOMP_BUS		I2C1
#define SPEED_100KHZ		100000

// Globals
static I2C_ID_T i2cDev = I2C1;
static int mode_poll;          /* Poll/Interrupt mode flag */
Accelerometer acc;
Magnetometer mag;

// Initialize the I2C bus
void I2C_Init(I2C_ID_T id, int speed)
{
	Board_I2C_Init(id);					// Initialize board I2C
	Chip_I2C_Init(id);					// Initialize I2C1
	Chip_I2C_SetClockRate(id, speed);   // Set clock speed
	I2C_Set_Mode(id, 0);				// Set default mode interrupt
}

// Set I2C mode to polling/interrupt
void I2C_Set_Mode(I2C_ID_T id, int polling)
{
	if(!polling)
	{
		mode_poll &= ~(1 << id);
		Chip_I2C_SetMasterEventHandler(id, Chip_I2C_EventHandler);
		NVIC_EnableIRQ(id == I2C0 ? I2C0_IRQn : I2C1_IRQn);
	}
	else
	{
		mode_poll |= 1 << id;
		NVIC_DisableIRQ(id == I2C0 ? I2C0_IRQn : I2C1_IRQn);
		Chip_I2C_SetMasterEventHandler(id, Chip_I2C_EventHandlerPolling);
	}
}

// I2C state handler
static void i2c_state_handling(I2C_ID_T id)
{
	if (Chip_I2C_IsMasterActive(id))
		Chip_I2C_MasterStateHandler(id);
	else
		Chip_I2C_SlaveStateHandler(id);
}

// IRQ handler for I2C1
void I2C1_IRQHandler(void)
{
	i2c_state_handling(I2C1);
}

// Function called when timer expires
void SysTick_Handler(void)
{
	int currentHeading = 0;
	currentHeading = getHeading();
	printf("Heading: %d\n", currentHeading);
}

// Initialize the compass
void Compass_Init()
{
	I2C_ID_T id = I2C_ECOMP_BUS;
	static I2C_XFER_T ecomp_xfer;
	I2C_Init(I2C1, SPEED_100KHZ);
	ecomp_xfer.slaveAddr = (LSM303D_ADDR << 1);
	Chip_I2C_SlaveSetup(id, I2C_SLAVE_2, &ecomp_xfer, NULL, 0);

	writeReg(CTRL1, ACC_ON_50HZ);			// Enable accelerometer +/- 2 at 50 Hz
	writeReg(CTRL5, MAG_HIGH_RES_6_25HZ);	// Magnetometer Hi-Res at 6.25 Hz
	writeReg(CTRL6, MAG_FS_4);				// Magnetometer +/- 4
	writeReg(CTRL7, MAG_ON);				// Enable magnetometer
}


// Set the value of a register
void writeReg(uint8_t regAddr, uint8_t regVal)
{
	uint8_t txBuff[2];
	txBuff[0] = regAddr;
	txBuff[1] = regVal;
	Chip_I2C_MasterSend(i2cDev, LSM303D_ADDR, txBuff, 2);
}

// Read value from register
uint8_t readReg(uint8_t regAddr)
{
	uint8_t txBuff[1];
	uint8_t rxBuff[1];
	txBuff[0] = regAddr;
	Chip_I2C_MasterSend(i2cDev, LSM303D_ADDR, txBuff, 1);
	Chip_I2C_MasterRead(i2cDev, LSM303D_ADDR, rxBuff, 1);
	return rxBuff[0];
}

// Enables compass
void enableCompass()
{
	writeReg(CTRL1, ACC_ON_50HZ); 	// Enable accelerometer
	writeReg(CTRL7, MAG_ON);		// Enable magnetometer
}

// Disables compass
void disableCompass()
{
	writeReg(CTRL1, ACC_OFF);		// Disable accelerometer
	writeReg(CTRL7, MAG_OFF); 		// Disable magnetometer
}

// Store ecompass readings in acc and mag
void readCompass(Compass *comp)
{
	comp->heading = getHeading();
	comp->pitch = getPitch();
	comp->roll = getRoll();
}

// Calculate pitch
float getPitch()
{
	return (atan2(acc.x,sqrt(acc.y*acc.y+acc.z*acc.z))*180/M_PI);
}

// Calculate roll
float getRoll()
{
	return (atan2(acc.y,sqrt(acc.x*acc.x+acc.z*acc.z))*180/M_PI);
}

// Get accelerometer values
void accRead(Accelerometer *a)
{
	a->x = (int16_t)(readReg(OUT_X_H_A) << 8 | readReg(OUT_X_L_A))*A_CONV_FACTOR;
	a->y = (int16_t)(readReg(OUT_Y_H_A) << 8 | readReg(OUT_Y_L_A))*A_CONV_FACTOR;
	a->z = (int16_t)(readReg(OUT_Z_H_A) << 8 | readReg(OUT_Z_L_A))*A_CONV_FACTOR;
}

// Get magnetometer values
void magRead(Magnetometer *m)
{
	m->x = (int16_t)(readReg(OUT_X_H_M) << 8 | readReg(OUT_X_L_M))*M_CONV_FACTOR;
	m->y = (int16_t)(readReg(OUT_Y_H_M) << 8 | readReg(OUT_Y_L_M))*M_CONV_FACTOR;
	m->z = (int16_t)(readReg(OUT_Z_H_M) << 8 | readReg(OUT_Z_L_M))*M_CONV_FACTOR;
}

// Returns the angular difference in the horizontal plane between
// a default vector an north in degrees.
float getHeading()
{
	// Default vector of x axis
	float from[3] = { 1, 0, 0 };

	// Get latest compass readings for calculations
	accRead(&acc);
	magRead(&mag);

	return calcHeading(from, &acc, &mag);
}

// Calculate the heading
float calcHeading(float *from, const Accelerometer *acc, const Magnetometer *mag)
{
    // Change values with values from calibration tests...
	int16_t min[] = { 32767, 32767, 32767 };
	int16_t max[] = { -32767, -32767, -32767 };

	float temp_m[] = { mag->x, mag->y, mag->z };
	float temp_a[] = { acc->x, acc->y, acc->z };

	// Initialize east and north vector
	float east[] = {0, 0, 0};
    float north[] = {0, 0, 0};

    int i;
	for(i = 0; i < 3; i ++)
		temp_m[i] -= (min[i]+max[i])/2;

	// Calculate North and East vectors
	vector_cross(temp_m, temp_a, east);
	vector_normalize(east);
	vector_cross(temp_a, east, north);
	vector_normalize(north);

	// Calculate angular difference
	float heading = atan2(vector_dot(east, from), vector_dot(north,from))*180/M_PI;

	if (heading < 0)
		heading += 360;

	return heading;
}

// Get dot product
float vector_dot(float *a, float *b)
{
	return (a[0]*b[0])+ (a[1]*b[1]) + (a[2]*b[2]);
}

// Get cross product of vector
void vector_cross(float *a, float *b, float *out)
{
	out[0] = (a[1]*b[2]) - (a[2]*b[1]);
	out[1] = (a[2]*b[0]) - (a[0]*b[2]);
	out[2] = (a[0]*b[1]) - (a[1]*b[0]);
}

// Normalize vector
void vector_normalize(float *a)
{
	float m = sqrt(vector_dot(a,a));
	int i;

	for(i = 0; i < 3; i++)
		a[i] = a[i]/m;
}

Accelerometer getAcc()
{
	return acc;
}
Magnetometer getMag()
{
	return mag;
}
