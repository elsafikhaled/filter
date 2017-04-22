/*
 * KalmanFilter.c
 *
 *  Created on: ٢٢‏/٠٤‏/٢٠١٧
 *      Author: El-safi
 */
#include "KalmanFilter.h"




float KalmanFilter_CurrentAngle(signed char GyroRate,signed char AccelAngle){

       float term=0.0f;
	  /* calculate the ESTIMATE angle by GyroRate  */
	  GyroDiff=GyroRate - Bias;
	  EstAngleGyro_P = EstAngleGyro_Pr + dt*GyroDiff;

	  /*   Process covarience Matrix struct Matrix Cova={1,0,0,1};             */
	  term=Cova[0][1] ;
	  Cova[0][0]=Cova[0][0] + dt * ((dt * Cova[1][1] )- Cova[1][0] - term+ Q_angle);
	  Cova[0][1]=Cova[0][1]-(dt*Cova[1][1]);
	  Cova[1][0]=Cova[1][0]-(dt*Cova[1][1]);
	  Cova[1][1]=Cova[1][1]+(Q_gyroBias*dt);

	  /* Calculate Kalman Gain */
	  KG_Angle=Cova[0][0]/(Cova[0][0]+R_measure);
	  KG_Bias= Cova[1][0] /(Cova[0][0]+R_measure);

	  /* Get the current state or Angle and Bias */
	  CurrentAngle=EstAngleGyro_P+KG_Angle*(AccelAngle-EstAngleGyro_P);
	  // updata angle and Bias
	  EstAngleGyro_Pr=CurrentAngle;
	  Bias=Bias+KG_Bias*(AccelAngle-EstAngleGyro_P);

	  /* equation :: update covariance process
                            P=[P00  P01] - [K0*P00  K0*P01]
                              [P10  P11]   [K1*P10  K1*P11]
      */
	  Cova[0][0]=Cova[0][0]-KG_Angle*Cova[0][0];
	  Cova[0][1]=Cova[0][1]-KG_Angle*Cova[0][1];
	  Cova[1][0]=Cova[1][0]-KG_Bias* Cova[1][0];
	  Cova[1][1]=Cova[1][1]-KG_Bias* Cova[1][1];

     /* return final accurate angle */

      return CurrentAngle;

}





