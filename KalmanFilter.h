/*
 * KalmanFilter.h
 *
 *  Created on: ٢٠‏/٠٤‏/٢٠١٧
 *      Author: El-safi
 */

#ifndef KALMANFILTER_H_
#define KALMANFILTER_H_
/*  **************************************  Kalman Filter Algorithm   ********************************************************
 *
 *
 *  MATHS Representation ::
 *------------------------
 *
 *    1- sources :
 *        http://blog.tkjelectronics.dk/2012/09/a-practical-approach-to-kalman-filter-and-how-to-implement-it/comment-page-1/
 *____________________________________________________________________________________________________________________________
 *    2-Predected or Estimated value :-
 *
 *                   equation  ::    Xp= A * Xprevious + B * U + Qw
 *
 *                   parameters::           Xp -> predected value.
 *                                               Xp=[GyroAngle_p]
 *                                                  [Bias_p     ]
 *                                   Xprevious -> previous value.
 *                                           U -> control part and in my case is the bias that added by Gyro drift.
 *                                                U=Bias.
 *                                          Qw -> noise=0.
 *
 *                   Matrices  ::      A=[1 -dt]  , B=[dt]
 *                                       [0   1]  ,   [0 ]
 *                                     dt: time interval between two Reading
 *
 *              Implementation ::            Xp=[GyroAngle_p]=[GyroAngle_pr + dt * (GyroRate-Bias) ]
 *                                              [Bias_p     ] [              Bias                  ]
 *____________________________________________________________________________________________________________________________
 *    3-Process covarience Matrix :-
 *
 *                  equation   ::   P= A * Pprevious * A^t  + Qr
 *
 *                  parameters ::    Pprevious=[0  0]   , A^t=[1   0] , Qr=[dt*Qangle  0     ]  , P=[P00  P01]
 *                                             [0  0]   ,     [-dt 1] ,    [0          dt*Qbi]  ,   [P10  P11]
 *
 *
 *              Implementation ::
 *
 *                                 P=[P00  P01] = [P00 + dt * (dt*P11-P01-P10+Qangle)              P01-dt*P11]
 *                                   [P10  P11]   [P10-dt*P11                                      P11+Qbi*dt]
 *
 *____________________________________________________________________________________________________________________________
 *    4-Get measured value from ACCELEROMETER :-
 *                       equation :: Y= C * AccelAngle + Zr
 *                                     C=[1 0]  , Zr=0,
 *____________________________________________________________________________________________________________________________
 *    5-Calculate Kalman Gain :-
 *                    equation :: KG= (P*H^t) / (H*P*H^t+R)
 *
 *                  parameters :: H=[1  0], R=constant.
 *                                H^t=[1]
 *                                    [0]
 *
 *                                KG =   [P00]
 *                                       [P10]
 *                                         ÷
 *                                       [P00+R]
 *
 *                                KG_angle= P00 / [P00+R]
 *                                KG_bias=  P10 / [P00+R]
 *
 *_____________________________________________________________________________________________________________________________
 *   6-Calculate the current state:-
 *                    equation ::    Xs= Xp + KG_angle * ( Y - H * Xp )
 *                                     = GyroAngle_p + KG_angle * (Y_accelerometerAngle - GyroAngle_p)
 *                                 bias= bias + KG_bi * ( Y - H * Xp )
 *                  parameters ::     H=[1  0]
 *_____________________________________________________________________________________________________________________________
 *  7-Update covariance matrix :-
 *                    equation ::
 *                             P=[P00  P01] - [K0*P00  K0*P01]
 *                               [P10  P11]   [K1*P10  K1*P11]
 *______________________________________________________________________________________________________________________________
 *______________________________________________________________________________________________________________________________
 * ***************************************************************************************************************************/
  //Functions prototypes:-

      float KalmanFilter_CurrentAngle(double GyroRate,double AccelAngle,signed char Bias );

/*
 *
 *              Function   ::    void KalmanFilter_CurrentAngle(signed char GyroRate,signed char AccelAngle);
 *
 *              Parameters ::    signed char GyroRate,signed char AccelAngle ,Bias : callibration of gyro
 *
 *              Return     ::    ANGLE : float
 *
 *             Description ::    Calculate the accurate Angle of Rotation without noise and error
 *
 * *****************************************************************************************************************************/



#endif /* KALMANFILTER_H_ */
