/***********************************************************************
* FILENAME :        PICSD.c
*
* PURPOSE :
*       Main test program dumps 512 bytes from the SD Card (one sector) to the UART
*       then increases the sector and repeats
*
* FUNCTIONS :
*       void configOscillator(void)
*       void configUSART(void)
*       void putch(char data)
*       void main(void)
*
* NOTES :
*       N/A
*
* LICENCE:
*	The MIT Licence
*
* AUTHOR :  MCook
*
* CREATE DATE :  16 Feb 15
*
************************************************************************/

#include <xc.h>
#include <stdio.h>
#include "PICSD.h"
#include "diskio.h"

/***********************************************************************
* FUNCTION NAME:  void configOscillator(void)
*
* PURPOSE :
*       Configures PIC18F45K50 internal oscillator to 8Mhz
*
* PARAMETERS:
*	N/A
*
* RETURN :
*	N/A
*
************************************************************************/
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

/***********************************************************************
* FUNCTION NAME:  void configUSART(void)
*
* PURPOSE :
*       Configures PIC18F45K50 internal UART Module
*
* PARAMETERS:
*	N/A
*
* RETURN :
*	N/A
*
************************************************************************/
void configUSART(void)
{
    /*
        Open1SPI defined in XC8 peripheral libraries.
        MPLAB XC8 Peripheral Libraries outlines other functions USART can use.
        USART1 uses pins 25 (TX) and 26 (RX).
    */
    unsigned char config = USART_TX_INT_ON & USART_RX_INT_ON & USART_ASYNCH_MODE & USART_EIGHT_BIT & USART_BRGH_HIGH;
    unsigned char spbrg = 51; // Formula High Speed spbrg = FOSC / ( 16 * baud ) - 1 eg. spbrg = 8000000/(16 * 9600) - 1 = 51
    Open1USART(config, spbrg);
}

/***********************************************************************
* FUNCTION NAME:  void putch(char data)
*
* PURPOSE :
*       putch specifies how printf will function (printf's output device)
*
* PARAMETERS:
*	char data - character data sent to the UART module
*
* RETURN :
*	N/A
*
************************************************************************/
void putch(char data)
{
    putc1USART(data);
    while(Busy1USART());
}

/***********************************************************************
* FUNCTION NAME:  void main(void)
*
* PURPOSE :
*       Main test program
*
* PARAMETERS:
*	N/A
*
* RETURN :
*	N/A
*
************************************************************************/
void main(void)
{
    DWORD sec = 0;
    configOscillator(); // Config OSCCON Register for Internal Osc at 8MHz
    configUSART(); // Config USART module for 8-bit Asynchronous @ 9600 baud
    printf("USART Module Initialized...\r\n");
    disk_initialize();
    while(1)
        disk_readsector(sec++);
}

