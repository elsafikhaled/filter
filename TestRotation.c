/*
 * TrackingTestRotation.c
 *
 *  Created on: ٢٤‏/٠٤‏/٢٠١٧
 *      Author: El-safi
 */
#include "KalmanFilter.h"
#include "MPU6050_EKE.h"
#include "TbUart.h"
#include <util/delay.h>


//callibration GYRO
double GYROCallibX=0;
//ACCelerometer angle
double AccAngle=0;
double ACC[3],GYRO[3];
//kalman final angle
double FinalAngle=0;



int main(void){

	TbUart_init();
	MPU6050_EKE_init();
	//GYROCallibX=MPU6050_Callib_GYRO();
	GYROCallibX=0.1;

	while(1){
	//read from Mpu 6050
	MPU6050_Read_data(ACC,GYRO);
	//get accelerometer angle (measured value in kalman algorithm)
    AccAngle=(double)MPU6050_AngleX_ACC(ACC);
    TbUart_Send_stri((signed char*)"ACCELRO_Angle on X_axis :");
    UART_SendDouble_void(AccAngle,3);
    TbUart_Send_char('\n');


    //filter data and get final angle by KALMAN
    FinalAngle=(double)KalmanFilter_CurrentAngle(GYRO[X],AccAngle,GYROCallibX);
    // send kalman angle to laptob
    TbUart_Send_stri((signed char*)"KALMAN_Angle on X_axis :");
    UART_SendDouble_void(FinalAngle,3);
    TbUart_Send_char('\n');


    _delay_ms(1000);// as dt = 1sec in kalman

	}
	return 0;
}

