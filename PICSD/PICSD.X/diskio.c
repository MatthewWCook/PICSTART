/***********************************************************************
* FILENAME :        diskio.c
*
* PURPOSE :
*       C functions for SD Disk I/O
*
* FUNCTIONS :
*       BYTE disk_initialize (void);
*       BYTE disk_readsector(DWORD sec);
*       BYTE disk_readsectordata(void);
*       BYTE SD_Init (void);
*       BYTE SPI_send_cmd (BYTE cmd,DWORD arg);
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
#include "diskio.h"
#include "spi_mc.h"

// Definitions for MMC/SDC command
#define CMD0	(0x40+0)	// GO_IDLE_STATE
#define CMD1	(0x40+1)	// SD_INIT_COM
#define CMD16	(0x40+16)	// SET_BLOCKLEN
#define CMD17	(0x40+17)	// READ_SINGLE_BLOCK

/***********************************************************************
* FUNCTION NAME:  BYTE disk_initialize (void)
*
* PURPOSE :
*       Initialize Disk Drive
*
* PARAMETERS:
*	N/A
*
* RETURN :
*	0 - Success
*	1 - Fail
*
************************************************************************/
BYTE disk_initialize (void)
{
        if( SD_Init() == 0 )
        {
            printf("Disk Initialized\r\n");
            return 0;
        }
        else
            return 1;
}

/***********************************************************************
* FUNCTION NAME:  BYTE SD_Init( void )
*
* PURPOSE :
*       Initialize SD Card Sequence
*
* PARAMETERS:
*	N/A
*
* RETURN :
*	0 - Success
*	1 - Fail
*
************************************************************************/
BYTE SD_Init( void )
{
    int Count = 0;

    SPI_MC_SLAVE_SELECT = 0; //Chip Select OUTPUT

    SPI_MC_Close();

    SPI_MC_Initialize(); //SPI SLOW CLOCK 125KHz  8MHz/64 = 125KHz MODE_00

    SPI_MC_SLAVE_SELECT = 1; //CS DISABLE

    printf("Sending Dummy Clocks..\r\n");
    //Send > 74 Dummy Clocks for SPI MODE
    for(Count=0;Count<10;Count++)
    {
        SPI_MC_Write( 0xff );
    }

    Count = 0;
    printf("Sending CMD0..\r\n");
    //Send SD IDLE Command (CMD0) RES 0x01 = IDLE STATE
    while( SPI_send_cmd(CMD0,0) != 0x01 )
    {
        Count++;
        if(Count==10)
        {
            printf("Sending Command 0 Failed...\r\n");
            return 1;
        }
    }
    printf("Command 0 Success..\r\n");

    Count = 0;
    printf("Sending CMD1..\r\n");
    while( SPI_send_cmd(CMD1,0) != 0x00 )
    {
        Count++;
        if(Count==10)
        {
            printf("Sending Command 1 Failed...\r\n");
            return 1;
        }
    }
    printf("Command 1 Success..\r\n");

    Count = 0;
    printf("Sending CMD16..\r\n");
    while( SPI_send_cmd(CMD16,0x0200) != 0x00 )
    {
        Count++;
        if(Count==10)
        {
            printf("Sending Command 16 Failed...\r\n");
            return 1;
        }
    }
    printf("Command 16 Success..\r\n");

    return 0;
}

/***********************************************************************
* FUNCTION NAME:  BYTE SPI_send_cmd (BYTE cmd, DWORD arg)
*
* PURPOSE :
*       Send a command packet to the SDC/MMC
*
* PARAMETERS:
*       BYTE  cmd - SD Command
*	DWORD arg - Argument (32 bits)
*
* RETURN :
*	0 - Success
*	1 - Fail
*
************************************************************************/
BYTE SPI_send_cmd (BYTE cmd, DWORD arg)
{
	BYTE n, res;
        BYTE retry = 0;

	/* Select the card */
        SPI_MC_SLAVE_SELECT = 0; //CS ENABLE

        SPI_MC_Write(0xff); // flush the buffer

	/* Send a command packet */
	SPI_MC_Write(cmd);			/* Start + Command index */
        SPI_MC_Write((BYTE)(arg >> 24));	/* Argument[31..24] */
        SPI_MC_Write((BYTE)(arg >> 16));	/* Argument[23..16] */
        SPI_MC_Write((BYTE)(arg >> 8));	        /* Argument[15..8] */
        SPI_MC_Write((BYTE)arg);		/* Argument[7..0] */
	SPI_MC_Write(0x95);                     /* CRC */

        switch( cmd )
        {
            case CMD1:
                /* Receive a command response */
                while( (res = SPI_MC_Write(0xff)) != 0x00 )//wait response
                {
                    __delay_ms(10);
                    if(retry++ > 10)
                    {
                        printf("Timeout Error...\r\n");
                        break; //time out error
                    }
                }
                break;
            default :
                while( (res = SPI_MC_Write(0xff)) == 0xff )//wait response
                {
                    if(retry++ > 10)
                    {
                        printf("Timeout Error...\r\n");
                        break; //time out error
                    }
                }
                break;
        }

        /* Deselect the card */
        SPI_MC_SLAVE_SELECT = 1; //CS DISABLE

        printf("R1 = 0x%02x\r\n",res);
	return res;			/* Return with the response value */
}

/***********************************************************************
* FUNCTION NAME:  BYTE disk_readsector(DWORD sec)
*
* PURPOSE :
*       Routine to read a SD Card sector
*
* PARAMETERS:
*	DWORD sec - sector number to read
*
* RETURN :
*	0 - Success
*	1 - Fail
*
************************************************************************/
BYTE disk_readsector(DWORD sec){

    BYTE res;

    printf("Reading sector %u\r\n",sec);

    printf("Sending CMD17..\r\n");

    res = SPI_send_cmd (CMD17,sec<<9);

     if(res != 0x00)
         return 1;

     res = disk_readsectordata();
     
     if(res != 0x00)
         return 1;

     return 0;
}

/***********************************************************************
* FUNCTION NAME:  BYTE disk_readsectordata(void)
*
* PURPOSE :
*       Read a full 512 Bytes SD Card sector data
*
* PARAMETERS:
*	N/A
*
* RETURN :
*	0 - Success
*	1 - Fail
*
************************************************************************/
BYTE disk_readsectordata(void)
{
    BYTE res;

    /* Select the card */
    SPI_MC_SLAVE_SELECT = 0; //CS ENABLE

     while((res = SPI_MC_Write(0xff)) != 0xfe);

     for(int x = 0; x < 512; x++)
     {
         secdata[x] = SPI_MC_Write(0xff);
     }

     //Data Packet CRC
     SPI_MC_Write(0xff);
     SPI_MC_Write(0xff);

     /* Deselect the card */
     SPI_MC_SLAVE_SELECT = 1; //CS DISABLE

     for(int x = 0; x < 512; x++)
     {
         printf("0x%02x ",secdata[x]);
     }

     printf("\r\n");

     return 0;
}
