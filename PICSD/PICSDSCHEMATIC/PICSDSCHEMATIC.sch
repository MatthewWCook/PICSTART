EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:MCPARTS
LIBS:PICSDSCHEMATIC-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date "26 feb 2015"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L PIC18F45K50 U?
U 1 1 54B02B66
P 6300 4350
F 0 "U?" H 5250 5350 60  0000 C CNN
F 1 "PIC18F45K50" H 7050 3150 60  0000 C CNN
F 2 "~" H 6300 4350 60  0000 C CNN
F 3 "~" H 6300 4350 60  0000 C CNN
	1    6300 4350
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR?
U 1 1 54B02B7F
P 7950 4350
F 0 "#PWR?" H 7950 4450 30  0001 C CNN
F 1 "VCC" H 7950 4450 30  0000 C CNN
F 2 "" H 7950 4350 60  0000 C CNN
F 3 "" H 7950 4350 60  0000 C CNN
	1    7950 4350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 54B02B98
P 7850 4450
F 0 "#PWR?" H 7850 4450 30  0001 C CNN
F 1 "GND" H 7850 4380 30  0001 C CNN
F 2 "" H 7850 4450 60  0000 C CNN
F 3 "" H 7850 4450 60  0000 C CNN
	1    7850 4450
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR?
U 1 1 54B0312A
P 4800 4500
F 0 "#PWR?" H 4800 4600 30  0001 C CNN
F 1 "VCC" H 4800 4600 30  0000 C CNN
F 2 "" H 4800 4500 60  0000 C CNN
F 3 "" H 4800 4500 60  0000 C CNN
	1    4800 4500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 54B03130
P 4800 4650
F 0 "#PWR?" H 4800 4650 30  0001 C CNN
F 1 "GND" H 4800 4580 30  0001 C CNN
F 2 "" H 4800 4650 60  0000 C CNN
F 3 "" H 4800 4650 60  0000 C CNN
	1    4800 4650
	1    0    0    -1  
$EndComp
$Comp
L CONN_6 P?
U 1 1 54B03261
P 6350 2450
F 0 "P?" V 6300 2450 60  0000 C CNN
F 1 "PICKIT3 HDR" V 6400 2450 60  0000 C CNN
F 2 "" H 6350 2450 60  0000 C CNN
F 3 "" H 6350 2450 60  0000 C CNN
	1    6350 2450
	0    -1   -1   0   
$EndComp
$Comp
L VCC #PWR?
U 1 1 54B032C8
P 4600 2850
F 0 "#PWR?" H 4600 2950 30  0001 C CNN
F 1 "VCC" H 4600 2950 30  0000 C CNN
F 2 "" H 4600 2850 60  0000 C CNN
F 3 "" H 4600 2850 60  0000 C CNN
	1    4600 2850
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 54B032D0
P 4600 3250
F 0 "R?" V 4680 3250 40  0000 C CNN
F 1 "10K" V 4607 3251 40  0000 C CNN
F 2 "~" V 4530 3250 30  0000 C CNN
F 3 "~" H 4600 3250 30  0000 C CNN
	1    4600 3250
	-1   0    0    1   
$EndComp
NoConn ~ 6600 2800
NoConn ~ 6200 2800
$Comp
L GND #PWR?
U 1 1 54B0334E
P 6300 2950
F 0 "#PWR?" H 6300 2950 30  0001 C CNN
F 1 "GND" H 6300 2880 30  0001 C CNN
F 2 "" H 6300 2950 60  0000 C CNN
F 3 "" H 6300 2950 60  0000 C CNN
	1    6300 2950
	1    0    0    -1  
$EndComp
$Comp
L CONN_5 P?
U 1 1 54B45716
P 8400 5000
F 0 "P?" V 8350 5000 50  0000 C CNN
F 1 "UART_MODULE" V 8450 5000 43  0000 C CNN
F 2 "" H 8400 5000 60  0000 C CNN
F 3 "" H 8400 5000 60  0000 C CNN
	1    8400 5000
	1    0    0    -1  
$EndComp
NoConn ~ 8000 4800
NoConn ~ 8000 5200
$Comp
L GND #PWR?
U 1 1 54B45778
P 7900 5200
F 0 "#PWR?" H 7900 5200 30  0001 C CNN
F 1 "GND" H 7900 5130 30  0001 C CNN
F 2 "" H 7900 5200 60  0000 C CNN
F 3 "" H 7900 5200 60  0000 C CNN
	1    7900 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	7650 4400 7850 4400
Wire Wire Line
	7850 4400 7850 4450
Wire Wire Line
	7650 4300 7850 4300
Wire Wire Line
	4800 4500 4900 4500
Wire Wire Line
	4900 4600 4800 4600
Wire Wire Line
	4800 4600 4800 4650
Wire Wire Line
	4600 3000 4600 2850
Wire Wire Line
	4600 3500 4750 3500
Wire Wire Line
	4750 3500 4900 3500
Wire Wire Line
	4750 3500 4750 3000
Wire Wire Line
	4750 3000 6100 3000
Wire Wire Line
	6100 3000 6100 2800
Connection ~ 4750 3500
Wire Wire Line
	7650 3500 7650 3150
Wire Wire Line
	7650 3150 6400 3150
Wire Wire Line
	6400 3150 6400 2800
Wire Wire Line
	7750 3600 7650 3600
Wire Wire Line
	7750 3050 7750 3600
Wire Wire Line
	7750 3050 6500 3050
Wire Wire Line
	6500 3050 6500 2800
Wire Wire Line
	6300 2800 6300 2950
Wire Wire Line
	8000 5100 7900 5100
Wire Wire Line
	7900 5100 7900 5200
Wire Wire Line
	7650 5000 8000 5000
Wire Wire Line
	7650 4900 8000 4900
Text Notes 8550 4800 0    39   ~ 0
3V3
Text Notes 8550 4900 0    39   ~ 0
TXD
Text Notes 8550 5000 0    39   ~ 0
RXD
Text Notes 8550 5100 0    39   ~ 0
GND
Text Notes 8550 5200 0    39   ~ 0
+5V
$Comp
L CONN_8 P?
U 1 1 54EF49DA
P 8400 3950
F 0 "P?" V 8350 3950 60  0000 C CNN
F 1 "SD_MODULE" V 8450 3950 60  0000 C CNN
F 2 "" H 8400 3950 60  0000 C CNN
F 3 "" H 8400 3950 60  0000 C CNN
	1    8400 3950
	1    0    0    -1  
$EndComp
Text Notes 8550 4800 0    39   ~ 0
3V3
Text Notes 8550 3700 0    39   ~ 0
3V3
Text Notes 8550 3600 0    39   ~ 0
GND
Text Notes 8550 3900 0    39   ~ 0
CS
Text Notes 8550 3800 0    39   ~ 0
+5V
Text Notes 8550 4000 0    39   ~ 0
MOSI
Text Notes 8550 4100 0    39   ~ 0
SCK
Text Notes 8550 4200 0    39   ~ 0
MISO
Text Notes 8550 4300 0    39   ~ 0
GND
Wire Wire Line
	7650 4100 8050 4100
Wire Wire Line
	8050 4200 7650 4200
$Comp
L GND #PWR?
U 1 1 54EF4AE5
P 8050 4400
F 0 "#PWR?" H 8050 4400 30  0001 C CNN
F 1 "GND" H 8050 4330 30  0001 C CNN
F 2 "" H 8050 4400 60  0000 C CNN
F 3 "" H 8050 4400 60  0000 C CNN
	1    8050 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	8050 4300 8050 4400
Wire Wire Line
	8050 3900 7800 3900
Wire Wire Line
	7800 3900 7800 4000
Wire Wire Line
	7800 4000 7650 4000
Wire Wire Line
	8050 4000 7850 4000
Wire Wire Line
	7850 4000 7850 3950
Wire Wire Line
	7850 3950 7750 3950
Wire Wire Line
	7750 3950 7750 3900
Wire Wire Line
	7750 3900 7650 3900
$Comp
L VCC #PWR?
U 1 1 54EF4B45
P 7900 3750
F 0 "#PWR?" H 7900 3850 30  0001 C CNN
F 1 "VCC" H 7900 3850 30  0000 C CNN
F 2 "" H 7900 3750 60  0000 C CNN
F 3 "" H 7900 3750 60  0000 C CNN
	1    7900 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	8050 3800 7900 3800
Wire Wire Line
	7900 3800 7900 3750
NoConn ~ 8050 3700
$Comp
L GND #PWR?
U 1 1 54EF4B6F
P 7900 3550
F 0 "#PWR?" H 7900 3550 30  0001 C CNN
F 1 "GND" H 7900 3480 30  0001 C CNN
F 2 "" H 7900 3550 60  0000 C CNN
F 3 "" H 7900 3550 60  0000 C CNN
	1    7900 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	8050 3600 8050 3450
Wire Wire Line
	8050 3450 7900 3450
Wire Wire Line
	7900 3450 7900 3550
Wire Wire Line
	7950 4350 7850 4350
Wire Wire Line
	7850 4350 7850 4300
$EndSCHEMATC