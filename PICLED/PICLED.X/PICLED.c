/* 
 * File:   PICLED.c
 * Author: MCook
 *
 * Created on January 8, 2015, 11:14 AM
 *
 * Purpose: Toggle LED on PORT B RB0 (PIC18F45K50 PIN 33)
 */

#include <xc.h>
#include "PICLED.h"

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

void main(void)
{
    TRISBbits.RB0 = 0; //RB0 - Bit 0 of PORT B is an OUTPUT (PIC18F45K50 PIN 33)

    configOscillator(); //Configure OSCCON Register for Internal Osc at 8MHz

    while(1)
    {
        LATBbits.LATB0 = ~LATBbits.LATB0; // TURN LED ON / OFF via latch on port
        for(int delay = 0; delay < 20; delay++) __delay_ms(50); // 1 sec delay
    }      
}

