/*
 * MPU6050CONFIG.h
 *
 *  Created on: ٢٤‏/٠٢‏/٢٠١٧
 *      Author: El-safi
 */

#ifndef MPU6050CONFIG_H_
#define MPU6050CONFIG_H_
/*
 * GET READINGS EVERY 4 MILI SECONDE =250HZ
 */
enum I2C_MODE{
	READ=0X01,
	WRITE=0X00,
	X=0,
	Y=1,
	Z=2
};
#define MPU6050_ID             0b11010000   // Address with end write bit ID=0X68
#define MPU6050_WAKE_UP        0x6B
#define WAKE_UP_val            0x00
#define ACCELEROMETER_SETUP    0x1C         //Configure register for accelerometer
#define ACC_SETUP_VAL          0x00         // Configure the accelerometer (+/-2g)
#define GYRO_SETUP             0x1B         //Configure register for gyro
#define GYRO_SETUP_VAL         0x00         //Configure the gyro (250dps full scale)

/* Skilled data from data sheet */
//MPU-6050 registers
#define MPU_address  (0b11010000) //device address of MPU-6050; see datasheet
#define WHO_AM_I     (0x75) //Register 117, holds upper 6 bits of MPU6050's 7-bit I2C address = 0x68
#define PWR_MGMT_1   (0x6B) //Register 107, used to wake the MPU from sleep mode
#define INT_ENABLE   (0x38) //Register 56 , used to enable interrupts on the MPU
#define INT_STATUS   (0x3A) //Register 58 , the location of the MPU's interrupt flags
#define DATA_RDY_EN  (0x01) //Bit 0  of register 58(INT_STATUS)

#define GYRO_CONFIG	 (0x1B) //Register 27, used to trigger gyroscope     self-test & configure gyroscopes'   full scale range
#define ACCEL_CONFIG (0x1C) //Register 28, used to trigger accelerometer self_test & configure accelerometer full scale rang
#define FS_SEL_0	 (0x00) //FS_SEL[1:0] - 0 = 250 o/s  for gero, or +/- 2g  for accelerometer
#define FS_SEL_1	 (0x08) //FS_SEL[1:0] - 1 = 500 o/s  for gero, or +/- 4g  for accelerometer
#define FS_SEL_2	 (0x10) //FS_SEL[1:0] - 2 = 1000 o/s for gero, or +/- 8g  for accelerometer
#define FS_SEL_3	 (0x18) //FS_SEL[1:0] - 3 = 2000 o/s for gero, or +/- 16g for accelerometer

#define TEMPERATURE_H (0x41) //Register 65,
#define TEMPERATURE_L (0x42) //Register 66,

#define GYRO_XOUT_H   (0x43) //Register 67, contains [15:8] of 16 bit 2's complement value of most recent x axis gyroscope measurement
#define GYRO_XOUT_L   (0x44) //Register 68, contains [7:0]  of 16 bit 2's complement value of most recent x axis gyroscope measurement
#define GYRO_YOUT_H   (0x45) //Register 69, contains [15:8] of 16 bit 2's complement value of most recent y axis gyroscope measurement
#define GYRO_YOUT_L   (0x46) //Register 70, contains [7:0]  of 16 bit 2's complement value of most recent y axis gyroscope measurement
#define GYRO_ZOUT_H   (0x47) //Register 71, contains [15:8] of 16 bit 2's complement value of most recent z axis gyroscope measurement
#define GYRO_ZOUT_L   (0x48) //Register 72, contains [7:0]  of 16 bit 2's complement value of most recent z axis gyroscope measurement

#define ACCEL_XOUT_H  (0x3B) //Register 59, contains [15:8] of 16 bit 2's complement value of most recent x axis accelometer measurement
#define ACCEL_XOUT_L  (0x3C) //Register 60, contains [7:0]  of 16 bit 2's complement value of most recent x axis gyroscope measurement
#define ACCEL_YOUT_H  (0x3D) //Register 61, contains [15:8] of 16 bit 2's complement value of most recent x axis gyroscope measurement
#define ACCEL_YOUT_L  (0x3E) //Register 62, contains [7:0]  of 16 bit 2's complement value of most recent x axis gyroscope measurement
#define ACCEL_ZOUT_H  (0x3F) //Register 63, contains [15:8] of 16 bit 2's complement value of most recent x axis gyroscope measurement
#define ACCEL_ZOUT_L  (0x40) //Register 64, contains [7:0]  of 16 bit 2's complement value of most recent x axis gyroscope measurement



#endif /* MPU6050CONFIG_H_ */
