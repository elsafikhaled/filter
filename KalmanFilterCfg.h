/*
 * KalmanFilterCfg.h
 *
 *  Created on: ٢٢‏/٠٤‏/٢٠١٧
 *      Author: El-safi
 */

#ifndef KALMANFILTERCFG_H_
#define KALMANFILTERCFG_H_

//global data types for the ESTIMATE angle by GyroRate
 // float Bias=0.0f;
  float dt=1.0f;   //acess by user
  float GyroDiff=0.0f;
  float EstAngleGyro_P=0.0f;
  float EstAngleGyro_Pr=0.0f;

//global data types for the Process covarience Matrix
  float Cova[2][2]={{1.0f,0.0f},{0.0f,1.0f}};
  float Q_angle = 0.001;    //constants from website try
  float Q_gyroBias = 0.003;

//global data types for Kalman Gain
  float R_measure = 0.03f;
  float KG_Angle=0.0f;
  float KG_Bias=0.0f;

 //Get the current state "Angle"
  float CurrentAngle=0.0f;



#endif /* KALMANFILTERCFG_H_ */
