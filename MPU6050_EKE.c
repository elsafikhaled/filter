/*
 * MPU6050_EKE.c
 *
 *  Created on: ١٧‏/٠٢‏/٢٠١٧
 *      Author: El-safi
 */
#include "MPU6050_EKE.h"

// MPU6050 initialization *******************************************************
void MPU6050_EKE_init(void){
//I2C Intialization
EKE_I2C_init(0x47,0,0x01);
//MPU6050 Configuration
EKE_I2C_start();
EKE_I2C_write(MPU6050_ID|WRITE);
EKE_I2C_write(MPU6050_WAKE_UP);
EKE_I2C_write(WAKE_UP_val);
// restart the master ... Accelerometer configure (+/-2g)
EKE_I2C_start();
EKE_I2C_write(MPU6050_ID|WRITE);
EKE_I2C_write(ACCELEROMETER_SETUP);
EKE_I2C_write(ACC_SETUP_VAL);
// restart the master ... Gyro configure (250dps full scale)
EKE_I2C_start();
EKE_I2C_write(MPU6050_ID|WRITE);
EKE_I2C_write(GYRO_SETUP);
EKE_I2C_write(GYRO_SETUP_VAL);
EKE_I2C_stop();
//END OF Rewrite Frame
}
//****************************************************************************************************

void MPU6050_Read_data(double ACC[3],double GYRO[3]){
U8_t temperature=0;
EKE_I2C_start();
EKE_I2C_write(MPU6050_ID|WRITE);
EKE_I2C_write(0x3B);
EKE_I2C_start();
EKE_I2C_write(MPU6050_ID|READ);
//the first 3 registers are ACCELEROMETER
ACC[X]=(EKE_I2C_read(1)<<8)|EKE_I2C_read(1);
ACC[Y]=(EKE_I2C_read(1)<<8)|EKE_I2C_read(1);
ACC[Z]=(EKE_I2C_read(1)<<8)|EKE_I2C_read(1);
//the temperature register
temperature=(EKE_I2C_read(1)<<8)|EKE_I2C_read(1);
//the last 3 register for GYRO
GYRO[X]=(EKE_I2C_read(1)<<8)|EKE_I2C_read(1);
GYRO[Y]=(EKE_I2C_read(1)<<8)|EKE_I2C_read(1);
GYRO[Z]=(EKE_I2C_read(1)<<8)|EKE_I2C_read(0);
//END OF FRAM OF READING 14 REGISTER
EKE_I2C_stop();
//get final reading from gyro degree/seconde, As 250 resolution then factor is 131 from datasheet.
GYRO[X]=GYRO[X]/(double)131.0;
GYRO[Y]=GYRO[Y]/(double)131.0;
GYRO[Z]=GYRO[Z]/(double)131.0;

//get final reading from Accelerometer (g), As 2g resolution then factor is 16384 from datasheet.
ACC[X]=ACC[X]/(double)16384.0;
ACC[Y]=ACC[Y]/(double)16384.0;
ACC[Z]=ACC[Z]/(double)16384.0;

}

//*******************************************************************************************************
void MPU6050_Angle_GYRO(double GYRO_XYZ[3],U8_t *GyAngX,U8_t *GyAngY,U8_t *GyAngZ){




}



