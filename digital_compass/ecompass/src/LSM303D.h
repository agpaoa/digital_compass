/*
 * LSM303D.h
 *
 *  Created on: May 7, 2015
 *      Author: Richie Agpaoa
 */
#ifndef LSM303D_H
#define LSM303D_H

// ***** LSM303D I2C ADDRESS *****
#define LSM303D_ADDR    	0x1D

// ***** LSM303D REGISTER MAPPING *****
#define TEMP_OUT_L 			0x05
#define TEMP_OUT_H			0x06

#define STATUS_M       	 	0x07

#define OUT_X_L_M        	0x08
#define OUT_X_H_M     		0x09
#define OUT_Y_L_M 			0x0A
#define OUT_Y_H_M        	0x0B
#define OUT_Z_L_M        	0x0C
#define OUT_Z_H_M        	0x0D

#define WHO_AM_I        	0x0F

#define INT_CTRL_M       	0x12
#define INT_SRC_M        	0x13
#define INT_TH8S_L_M       	0x14
#define INT_THS_H_M        	0x15

#define OFFSET_X_L_M       	0x16
#define OFFSET_X_H_M       	0x17
#define OFFSET_Y_L_M       	0x18
#define OFFSET_Y_H_M        0x19
#define OFFSET_Z_L_M      	0x1A
#define OFFSET_Z_H_M       	0x1B

#define REFERENCE_X        	0x1C
#define REFERENCE_Y        	0x1D
#define REFERENCE_Z        	0x1E

#define CTRL0        		0x2F
#define CTRL1        		0x20
#define CTRL2				0x21
#define CTRL3				0x22
#define CTRL4				0x23
#define CTRL5				0x24
#define CTRL6				0x25
#define CTRL7				0x26

#define STATUS_A 			0x27

#define OUT_X_L_A			0x28
#define OUT_X_H_A			0x29
#define OUT_Y_L_A			0x2A
#define OUT_Y_H_A			0x2B
#define OUT_Z_L_A			0x2C
#define OUT_Z_H_A			0x2D

#define FIFO_CTRL			0x2E
#define FIFO_SRC			0x2F

#define IG_CFG1				0x30
#define IG_SRC1				0x31
#define IG_THS1				0x32
#define IG_DUR1				0x33
#define IG_CFG2				0x34
#define IG_SRC2				0x35
#define IG_THS2				0x36
#define IG_DUR2				0x37

#define CLICK_CFG			0x38
#define CLICK_SRC			0x39
#define CLICK_THS			0x3A

#define TIME_LIMIT			0x3B
#define TIME_LATENCY		0x3C
#define TIME_WINDOW			0x3D

#define Act_THS				0x3E
#define Act_DUR				0x3F


// ***** ACC/MAG CONVERSION FACTORS *****
// Dev	Full Scale	Factor
// ----	----------	------
// ACC	+/- 2		0.061
// ACC	+/- 4		0.122
// ACC	+/- 6		0.183
// ACC	+/- 8		0.244
// ACC	+/- 16		0.732
// MAG	+/- 2		0.080
// MAG	+/- 4		0.160
// MAG	+/- 8		0.320
// MAG	+/- 12		0.479
#define A_CONV_FACTOR 0.061
#define M_CONV_FACTOR 0.160


// CONTROL REGISITER SETTINGS
// Only need to setup CTRL1, CTRL5, CTRL6, CTRL7
// Refer to LSM303D data sheet for more settings

// ***** CONTROL 0 REGISTER SETTINGS *****
// Initializes the LSM303D initialization settings
#define LSM303_INIT		0x00	// 0b0000 0000 (Default)

// ***** CONTROL 1 REGISTER SETTINGS *****
// Sets power mode and enable/disable axes
#define ACC_OFF				0x00	// 0b0000 0000 Power down
#define ACC_ON_3_125HZ		0x17	// 0b0001 0111 Low power
#define ACC_ON_50HZ			0x57	// 0b0101 0111 Regular power
#define ACC_ON_1600HZ		0xA7	// 0b1010 0111 High power

// ***** CONTROL 2 REGISTER SETTINGS *****
// Sets accelerometer full scale
#define ACC_FS_2		0x00	// 0b0000 0000 +/- 2 (Default)
#define ACC_FS_6		0x10	// 0b0001 0000 +/- 6
#define ACC_FS_16		0x20	// 0b0010 0000 +/- 16

// ***** CONTROL 3 REGISTER SETTINGS *****
// Interrupt 1 settings
#define ACC_DISBLE_INT1		0x00	// 0b0000 0000 Disable INT1 (Default)
#define ACC_ENABLE_INT1		0xFF	// 0b1111 1111

// ***** CONTROL 4 REGISTER SETTINGS *****
// Interrupt 2 settings
#define ACC_DISBLE_INT2		0x00	// 0b0000 0000 Disable INT2 (Default)
#define ACC_ENABLE_INT2		0xFF	// 0b1111 1111

// ***** CONTROL 5 REGISTER SETTINGS *****
// Magnetometer resolution and power settings
#define MAG_HIGH_RES_3_125HZ		0x60	// 0b0110 0000
#define MAG_HIGH_RES_6_25HZ			0x64	// 0b0110 0100
#define MAG_LOW_RES_3_125HZ			0x00	// 0b0000 0000
#define MAG_LOW_RES_6_25HZ			0x04	// 0b0000 0100

// ***** CONTROL 6 REGISTER SETTINGS *****
// Set Magnetometer full scale
#define MAG_FS_2	0x00	// 0b0000 0000 +/- 2
#define MAG_FS_4	0x20	// 0b0010 0000 +/- 4
#define MAG_FS_8	0x40	// 0b0100 0000 +/- 8
#define MAG_FS_12	0x60	// 0b0110 0000 +/- 12

// ***** CONTROL 7 REGISTER SETTINGS *****
// Magnetometer enable/disable
#define MAG_OFF		0x03	// 0b0000 0011 Magnetometer off
#define MAG_LOW 	0x04	// 0b0000 0100 Force low power mode (3.125Hz)
#define MAG_ON	 	0x00	// 0b0000 0000 Select CTRL5 power setting

#endif /* LSM303D_H */
