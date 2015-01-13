/* 
 * File:   PICDS1307.c
 * Author: MCook
 *
 * Created on January 9, 2015, 10:28 AM
 *
 * Purpose: SET/GET Time from DS1307 and display via USART to PC.
*/

#include <xc.h>
#include <stdio.h>
#include <plib/usart.h>
#include <plib/i2c.h>
#include "PICDS1307.h"
#include "DS1307LIB/rtc-ds1307.h"

void configOscillator(void)
{
   /*
      OSCCONbits.IDLEN  = 0;   //1 - idle / 0 - sleep :on SLEEP instruction
      OSCCONbits.IRCF2  = 1;   //Internal Oscillator Speed Select 110 - 8MHz
      OSCCONbits.IRCF1  = 1;   //Datasheet will contain other speed values
      OSCCONbits.IRCF2  = 0;
      OSCCONbits.OSTS   = 0;   //1 - Defined by FOSC / 0 - Internal Oscillator
      OSCCONbits.HFIOFS = 1;   //1 - Frequency stable / 0 - Frequency not stable
      OSCCONbits.SCS1   = 1;   //1X - Internal Osc / 01 - SOSC / 00 - FOSC
      OSCCONbits.SCS0   = 1;
    */
    OSCCON = 0x66; //Configure OSCCON Register for Internal Oscillator at 8MHz
}

void configUSART(void)
{
    /*
        Open1USART defined in XC8 peripheral libraries.
        MPLAB XC8 Peripheral Libraries outlines other functions USART can use.
        USART1 uses pins 25 (TX) and 26 (RX).
    */
    unsigned char config = USART_TX_INT_OFF & USART_RX_INT_OFF & USART_ASYNCH_MODE & USART_EIGHT_BIT & USART_BRGH_HIGH;
    unsigned char spbrg = 51; // Formula High Speed spbrg = FOSC / ( 16 * baud ) - 1 eg. spbrg = 8000000/(16 * 9600) - 1 = 51
    Open1USART(config, spbrg);
}

void configDS1307(void)
{
    OpenI2C(MASTER, SLEW_OFF); //Init I2C Module
    SSP1ADD = 19; //100KHz Baud @ 8Mhz SSPADD = ((FOSC/BITRATE)/4)-1
}

void putch(char data)
{
    //putch function overrides the printf input so that we can define custom input. (USART1)
    putc1USART(data);
    while(Busy1USART());
}

void main(void)
{

    BYTE sec=0, min=0, hour=12, day=5, date=1, month=1, year=15;
    
    configOscillator(); // Config OSCCON Register for Internal Osc at 8MHz
    configUSART(); // Config USART module for 8-bit Asynchronous @ 9600 baud
    configDS1307(); //Config DS1307 for I2C Bus with PIC in Mater Mode.
    
    //rtc_set_time  (BYTE *seconds, BYTE *minutes, BYTE *hours, BYTE *day, BYTE *date, BYTE *month, BYTE *year)
    printf("The DS1307 programmed = %d\r\n",rtc_set_time(&sec,&min,&hour,&day,&date,&month,&year));

    while(1)
    {
        //rtc_get_time (BYTE *seconds, BYTE *minutes, BYTE *hours, BYTE *day, BYTE *date, BYTE *month, BYTE *year)
        rtc_get_time(&sec,&min,&hour,&day,&date,&month,&year);
        //printf can be used to circumvent limitations of putrs1USART by defining putch function
        printf("%.2d-%.2d-%d, %.2d:%.2d:%.2d\r", month, date, year, hour, min, sec);
        for(int delay = 0; delay < 20; delay++) __delay_ms(50); // 1 sec delay
    }
}