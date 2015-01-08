/* 
 * File:   PICUART.c
 * Author: MCook
 *
 * Created on January 8, 2015, 2:02 PM
 *
 * Purpose: Repeatedly sends message "Hello World!" via the UART in one second intervals.
 */

#include <xc.h>
#include <plib/usart.h>
#include "PICUART.h"

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

void main(void)
{
    configOscillator(); // Config OSCCON Register for Internal Osc at 8MHz
    configUSART(); // Config USART module for 8-bit Asynchronous @ 9600 baud

    while(1)
    {
        putrs1USART("Hello World!\n");
        for(int delay = 0; delay < 20; delay++) __delay_ms(50); // 1 sec delay
    }
}
