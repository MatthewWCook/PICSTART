/***********************************************************************
* FILENAME :        spi_mc.h
*
* PURPOSE :
*       Header for SPI module
*       Initialization of SPI master mode
*
* FUNCTIONS :
*       void SPI_MC_Initialize(void);
*       void SPI_MC_Close(void);
*       BYTE SPI_MC_Write(BYTE data_out);
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

#ifndef SPI_MC_H
#define	SPI_MC_H

// Initialization of SPI master mode
// RB0 SDI    Pin 33
// RB1 SCK    Pin 34
// RB2 CS/SS  Pin 35
// RB3 SDO    Pin 36
#define SPI_MC_SDI_TRIS            TRISBbits.TRISB0
#define SPI_MC_SCK_TRIS            TRISBbits.TRISB1
#define SPI_MC_SCK                 LATBbits.LATB1
#define SPI_MC_SDO_TRIS            TRISBbits.TRISB3
#define SPI_MC_SDO                 LATBbits.LATB3
#define SPI_MC_SLAVE_SELECT_TRIS   TRISBbits.TRISB2
#define SPI_MC_SLAVE_SELECT        LATBbits.LATB2

//Function prototypes
void SPI_MC_Initialize(void);
void SPI_MC_Close(void);
BYTE SPI_MC_Write(BYTE data_out);

#endif	/* SPI_MC_H */

