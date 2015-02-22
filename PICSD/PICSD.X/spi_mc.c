/***********************************************************************
* FILENAME :        spi_mc.c
*
* PURPOSE :
*       C functions for SPI module
*       Initialization of SPI master mode
*
* FUNCTIONS :
*       void SPI_MC_Initialize(void);
*       void SPI_MC_Close(void);
*       signed char SPI_MC_Write(unsigned char data_out);
*
* NOTES :
*       BYTE SPI_MC_Write(BYTE data_out)
*           - content copied directly from XC8 SPI p-lib
* LICENCE:
*	The MIT Licence
*
* AUTHOR :  MCook
*
* CREATE DATE :  16 Feb 15
*
************************************************************************/

#include <xc.h>
#include "spi_mc.h"

/***********************************************************************
* FUNCTION NAME:  void SPI_MC_Initialize(void)
*
* PURPOSE :
*       Initialize SPI Master Mode sequence
*
* PARAMETERS:
*	N/A
*
* RETURN :
*	N/A
*
************************************************************************/
void SPI_MC_Initialize(void)
{
    SPI_MC_SLAVE_SELECT = 1;
    SPI_MC_SLAVE_SELECT_TRIS = 0;

    // Set up "idle" value for SCK. Set SDO to some specific value
    // for debugging purposes, actually can be anything.
    SPI_MC_SCK = 0;
    SPI_MC_SDO = 1;
    SPI_MC_SCK_TRIS = 0;
    SPI_MC_SDO_TRIS = 0;

    // Set SPI Master Mode clock frequency
    // Master: Fosc/64
    SSP1CON1bits.SSPM = 0b0010;

    // SPI MODE_00
    SSP1STATbits.CKE = 0 ;
    SSP1CON1bits.CKP = 0 ;

    // Finally: Enable the MSSP module
    SSP1CON1bits.SSPEN = 1;
}

/***********************************************************************
* FUNCTION NAME:  void SPI_MC_Close(void)
*
* PURPOSE :
*       Close SPI module
*
* PARAMETERS:
*	N/A
*
* RETURN :
*	N/A
*
************************************************************************/
void SPI_MC_Close(void)
{
  SSP1CON1 &= 0xDF;               // disable synchronous serial port
}

/***********************************************************************
* FUNCTION NAME:  BYTE SPI_MC_Write(BYTE data_out)
*
* PURPOSE :
*       Write a byte to the SPI module and read a response back
*
* PARAMETERS:
*	BYTE data_out - the data to write to the SPI module
*
* RETURN :
*	BYTE - SSP1BUF holds the reponse to the data_out
*
************************************************************************/
BYTE SPI_MC_Write(BYTE data_out)
{
  unsigned char TempVar;
  TempVar = SSP1BUF;           // Clears BF
  PIR1bits.SSP1IF = 0;         // Clear interrupt flag
  SSP1CON1bits.WCOL = 0;			//Clear any previous write collision
  SSP1BUF = data_out;          // write byte to SSP1BUF register
  if ( SSP1CON1 & 0x80 )       // test if write collision occurred
   return ( -1 );              // if WCOL bit is set return negative #
  else
   //while( !SSP1STATbits.BF ); // wait until bus cycle complete
   while(!PIR1bits.SSP1IF); // wait until bus cycle complete
   return ( SSP1BUF );      // return with byte read
}
