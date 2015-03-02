-------------------------------------------------------------------------------
Project Name : PICSD
-------------------------------------------------------------------------------
Version : 1.0
Release date : 02/21/2015
-------------------------------------------------------------------------------
Project state : stable
-------------------------------------------------------------------------------
Credits : Matthew Cook
-------------------------------------------------------------------------------
Project description

	Add PICSD program which dumps 512 bytes from the SD Card (one sector) 
	to the UART then increases the sector and repeats.
-------------------------------------------------------------------------------
Documentation

	To use this program you will need MPLABX with the XC8 compiler.
	You will also need the PICKit3 Programmer to program the PIC18F45K50.
	I used PuTTy on Windows to receive data via a USB -> TTL UART dongle.
        The dongle has power output for 3.3V and 5V at a low current limit. (USB)
        I do not use these power options and instead use and external supply.
        Even though these power rails are not used you still need to connect 
        the GND connection on the dongle to the ground connection of your circuit.
	Schematic in PICSDSCHEMATIC folder under PICSD. (KICAD, PNG, PDF)
	The Schematic shows minimum connections for PIC18F45K50, 
	USB->UART Dongle, SDCARD Module, and PICKit3.
	The PIC18F45K50 can be powered by a range of voltages. 
	The Schematic assumes VCC = 5 Volts.
  
-------------------------------------------------------------------------------
Additional Notes

	PIC18F45K50 USART PINS 25 (TX) and 26 (RX)
	HARDWARE SPI PINS: MOSI PIN 36, CHIP SELECT PIN 35, SCK PIN 34, MISO PIN 33 (MSSP)
	MPLABX XC8 Compiler
	PICKit3 Programmer
	MPLAB_XC8_Peripheral_Libraries.pdf (Microchip Website)
	
-------------------------------------------------------------------------------