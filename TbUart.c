/*
 * TbUart.c
 *
 *  Created on: ٢٤‏/٠١‏/٢٠١٧
 *      Author: El-safi
 */
#include "TbUart.h"
/* ***************************************************************************************** */
extern void TbUart_init(void){

/*        UCSRB REGISTER      */
UBRRL=(U8_t) 51;             // baud rate 9600 from equation in datasheet
UCSRB|=(1<<TXEN)|(1<<RXEN);  // enable TX and RX modules in UART module
UCSRB&=~(1<<UCSZ2);          // to make frame 8 bits with 2 bits in UCSRC register

/*        UCSRC REGISTER      */
UCSRC|=(1<<URSEL)|(1<<USBS)|(1<<UCSZ0)|(1<<UCSZ1);    // to write this register as UCSRL ** as it may be UBBRH too
                                                      // 2 stop bits
                                                      // frame of data 8 bits

UCSRC &=~(1<<UMSEL);            // ASYNCHRONOUS mode
UCSRC &=~(1<<UPM1)|(1<<UPM0);   //no parity
UCSRC&=~(1<<UCPOL);             // no clock as ASYNCHRONOUS mode
}
/* ******************************************************************************************* */

extern U8_t TbUart_get_char(void){

while(!(UCSRA &(1<<RXC)));
	return UDR;
}
/* ******************************************************************************************** */
U8_t TB_getchar_notWait(void){
	U8_t val='0';
	if((UCSRA &(1<<RXC)))
	return UDR;
	else{
		return val;  // always equal zero
	}
}

/* ******************************/
extern void TbUart_Send_char(U8_t letter){

	while(!(UCSRA&(1<<UDRE)));
	UDR=letter;
}
/* ********************************************************************************************* */
extern void TbUart_Send_stri(signed char *phrase){

	while(*phrase!='\0'){
	     TbUart_Send_char(*phrase);
	     phrase++;
	}


}
/* ******************************************************************************************* */
extern U8_t* TbUart_get_stri(void){
     U8_t *strin=(U8_t*)"0";
	*strin=TbUart_get_char();

	while(*strin!='\0'){
	  strin++;
	  *strin=TbUart_get_char();
	}
	*strin='\0';
  return(U8_t*)strin; // return addresse inside pointer
}
/* ********************************************************************************************* */
U8_t string_compare_EKE(char array[],char *string_data){
/* FILL FUNCTION OF COMPARISON*/
unsigned char ret_value=3,index=0;

   while(array[index]!='\0'){


      if(array[index]==*string_data){
          ret_value=1;
        }
    else{
          ret_value=0;
        }
          index++;
          string_data++;

   }
return ret_value;
/* END OF FUNCTION */
}

/* ************************************************************************************************** */
void string_copy_EKE(char *st_data,char *string_copy){
/* Fill Function here */

while(*string_copy!='\0'){
   *st_data=*string_copy;
    st_data++;
    string_copy++;
}
*st_data='\0';
/* End of Code*/
}
/* **************************************************************************************************** */
U8_t string_length_EKE(char *s_data){
/* fill function here */
unsigned char ret=0,counter=0;

while(*s_data!='\0'){
    counter++;
    s_data++;
}
ret=counter;

return ret;
/* END OF CODE */
}
/* ****************************************** */
void TB_intNumASCII(signed char Number)
{
  char buffer[16]={0};
  itoa(Number,( char*)buffer,10);
  TbUart_Send_stri((signed char*)buffer);

}
/* ****************************************** */
U8_t TB_ASCII_INT(void){
	U8_t arr[4]={0},index=0;
	
	for(index=0;index<=4;index++){
		arr[index]=(U8_t)TbUart_get_char();
	}
	return(U8_t)((arr[0]-'0')*1000+(arr[1]-'0')*100+(arr[2]-'0')*10+(arr[3]-'0'));
	
}


void dcon(char *buffer, double d, int precision)
{

	int wholePart = (int) d;    //wholepart is integer value from d

	// Deposit the whole part of the number.

	itoa(wholePart,buffer,10);

	// Now work on the faction if we need one.

	if (precision > 0) {

		// We do, so locate the end of the string and insert
		// a decimal point.

		char *endOfString = buffer;
		while (*endOfString != '\0') endOfString++;
		*endOfString++ = '.';

		// Now work on the fraction, be sure to turn any negative
		// values positive.

		if (d < 0) {
			d *= -1;
			wholePart *= -1;
			if(wholePart==0){
				strcpy(buffer,"-0.");
				endOfString=buffer+3;
			}
		}

		double fraction = d - wholePart;
		while (precision > 0) {

			// Multipleby ten and pull out the digit.

			fraction *= 10;
			wholePart = (long) fraction;
			*endOfString++ = '0' + wholePart;

			// Update the fraction and move on to the
			// next digit.

			fraction -= wholePart;
			precision--;
		}

		// Terminate the string.

		*endOfString = '\0';
	}


}

void UART_SendDouble_void(double d,int precision){
	char buffer[12]={0};
	dcon(buffer,d,precision);
	TbUart_Send_stri(buffer);




}
