/*
 * TbUart.h
 *
 *  Created on: ٢٤‏/٠١‏/٢٠١٧
 *      Author: El-safi
 */

#ifndef TBUART_H_
#define TBUART_H_
#include "std_data_types_EKE.h"
#include <avr/io.h>
#include <stdlib.h>
extern void TbUart_init(void);


extern void TbUart_Send_char(U8_t letter);

extern U8_t TbUart_get_char(void);

U8_t TB_getchar_notWait(void);

extern void TbUart_Send_stri(signed char *phrase);

extern U8_t* TbUart_get_stri(void);

U8_t string_compare_EKE(char array[],char *string_data);

void string_copy_EKE(char *st_data,char *string_copy);

U8_t string_length_EKE(char *s_data);
void TB_intNumASCII(signed char Number);
U8_t TB_ASCII_INT(void);

void UART_SendDouble_void(double d,int precision);
void dcon(char *buffer, double d, int precision);


#endif /* TBUART_H_ */
