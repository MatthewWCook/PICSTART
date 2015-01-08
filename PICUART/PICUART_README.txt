-------------------------------------------------------------------------------
Project Name : PICUART
-------------------------------------------------------------------------------
Version : 1.0
Release date : 01/08/2015
-------------------------------------------------------------------------------
Project state : stable
-------------------------------------------------------------------------------
Credits : Matthew Cook
-------------------------------------------------------------------------------
Project description

	Add PICUART program which repeatedly sends message "Hello World!"
	via the UART in one second intervals.

-------------------------------------------------------------------------------
Documentation

	To use this program you will need MPLABX with the XC8 compiler.
	You will also need the PICKit3 Programmer to program the PIC18F45K50.
	I used PuTTy on Windows to receive data via a USB -> TTL UART dongle.
        The dongle has power output for 3.3V and 5V at a low current limit. (USB)
        I do not use these power options and instead use and external supply.
        Even though these power rails are not used you still need to connect 
        the GND connection on the dongle to the ground connection of your circuit.
	The Schematic can be found in the Schematic Folder.
	The Schematic shows minimum connections for PIC18F45K50, 
	USB->UART Dongle, and PICKit3.
	The PIC18F45K50 can be powered by a range of voltages. 
	The Schematic assumes VCC = 5 Volts.

-------------------------------------------------------------------------------
Additional Notes

	PIC18F45K50 USART pins 25 (TX) and 26 (RX).  
	MPLABX XC8 Compiler
	PICKit3 Programmer
	MPLAB_XC8_Peripheral_Libraries.pdf (Microchip Website)
-------------------------------------------------------------------------------