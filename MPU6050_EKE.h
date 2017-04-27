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
#include <math.h>


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

float MPU6050_Callib_GYRO(void);
/* ****************************************************************************************************
 * Prototype    : float MPU6050_Callib_GYRO(void);
 *
 * return       : 4 byte :
 *
 * description  : callibrated value on X-axis
 *
 * notes        : returned val passed to kalman function as bias argument
 * *****************************************************************************************************/

float MPU6050_AngleX_ACC(double Accel_XYZ[3]);
/* ****************************************************************************************************
 * Prototype    : float MPU6050_AngleX_ACC(double Accel_XYZ[0],double Accel_XYZ[2] )
 *
 * return       : 4 byte :: angle
 *
 * description  : get  angle of accelerometer on X AXIS.
 *
 * notes        : pass 3  addresses of variables that pointer to U8_t point to them.
 * *****************************************************************************************************/


#endif /* MPU6050_EKE_H_ */
