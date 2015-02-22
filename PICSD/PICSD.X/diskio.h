/***********************************************************************
* FILENAME :        diskio.h
*
* PURPOSE :
*       Header for SD Disk I/O
*
* FUNCTIONS :
*       BYTE disk_initialize (void);
*       DRESULT disk_readsector(DWORD sec);
*       DRESULT disk_readsectordata(void);
*       BYTE    SD_Init (void);
*       BYTE    SPI_send_cmd (BYTE cmd,DWORD arg);
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

#ifndef _DISKIO_DEFINED
#define _DISKIO_DEFINED

#define _XTAL_FREQ 8000000      //Internal Oscillator Frequency 8MHz

static char secdata[512];   //Sector data holder

//Function prototypes
BYTE disk_initialize (void);
BYTE disk_readsector(DWORD sec);
BYTE disk_readsectordata(void);
BYTE SD_Init (void);
BYTE SPI_send_cmd (BYTE cmd, DWORD arg);


#endif	/* _DISKIO_DEFINED */
