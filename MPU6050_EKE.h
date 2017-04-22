/*
 * MPU6050_EKE.h
 *
 *  Created on: ١٧‏/٠٢‏/٢٠١٧
 *      Author: El-safi
 */

#ifndef MPU6050_EKE_H_
#define MPU6050_EKE_H_
#include "EKE_I2C.h"
#include "MPU6050CONFIG.h"



void MPU6050_EKE_init(void);
/* ****************************************************************************************************
 * Prototype    : void MPU6050_EKE_init(void);
 *
 * return       : void
 *
 * description  : do setup for GYRO and accelerometer.
 *
 * notes        : let uC get reading every 250 mili_seconde "its urgent" and no delay in code except it
 * ****************************************************************************************************/

void MPU6050_Read_data(double ACC[3],double GYRO[3]); //Get readings from MPU6050
/* ****************************************************************************************************
 * Prototype    : void MPU6050_Read_data(double ACC[3],double GYRO[3]);
 *
 * return       : void
 *
 * description  : get 3 readings of GYRO and accelerometer on X,Y,Z AXIS.
 *
 * notes        : pass 2  arrays of 3 members for GYRO and accelerometer .
 * ****************************************************************************************************/

void MPU6050_Angle_GYRO(double GYRO_XYZ[3],U8_t *GyAngX,U8_t *GyAngY,U8_t *GyAngZ);
/* ****************************************************************************************************
 * Prototype    : void MPU6050_Angle_GYRO(double GYRO_XYZ[3],U8_t *GyAngX,U8_t *GyAngY,U8_t *GyAngZ);
 *
 * return       : void
 *
 * description  : get 3 angles of GYRO on X,Y,Z AXIS.
 *
 * notes        : pass 3  addresses of variables that pointer to U8_t point to them.
 * *****************************************************************************************************/

void MPU6050_Angle_ACC(double ACC_XYZ[3],U8_t *AccAngX,U8_t *AccAngY,U8_t *AccAngZ);
/* ****************************************************************************************************
 * Prototype    : void MPU6050_Angle_ACC(double ACC_XYZ[3],U8_t *AccAngX,U8_t *AccAngY,U8_t *AccAngZ);
 *
 * return       : void
 *
 * description  : get 3 angles of accelerometer on X,Y,Z AXIS.
 *
 * notes        : pass 3  addresses of variables that pointer to U8_t point to them.
 * *****************************************************************************************************/
void MPU6050_Pitch_Roll(U8_t *pitch,U8_t *Roll);
/* ****************************************************************************************************
 * Prototype    : void MPU6050_Pitch_Roll(U8_t *pitch,U8_t *Roll);
 *
 * return       : void
 *
 * description  : get pitch and roll angle  on X,Y AXIS and neglect yaw angle around Z axis.
 *                according this equation::
 *                " angle = angle_gyro * 0.9996 + angle__acc * 0.0004"
 *
 * notes        : pass 2  addresses of variables that pointer to U8_t point to them.
 * *****************************************************************************************************/

#endif /* MPU6050_EKE_H_ */
