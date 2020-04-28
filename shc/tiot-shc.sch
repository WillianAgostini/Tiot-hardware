EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr User 5906 5906
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ESP32-DEVKITC-32D:ESP32-DEVKITC-32D U1
U 1 1 5E87A32F
P 1800 2050
F 0 "U1" H 1800 3217 50  0000 C CNN
F 1 "ESP32-DEVKITC-32D" H 1800 3126 50  0000 C CNN
F 2 "ESP32-DEVKITC-32D:MODULE_ESP32-DEVKITC-32D" H 1800 2050 50  0001 L BNN
F 3 "4" H 1800 2050 50  0001 L BNN
F 4 "Espressif Systems" H 1800 2050 50  0001 L BNN "Campo4"
	1    1800 2050
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5E87C1AE
P 3200 2200
F 0 "R1" H 3270 2246 50  0000 L CNN
F 1 "R" H 3270 2155 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical" V 3130 2200 50  0001 C CNN
F 3 "~" H 3200 2200 50  0001 C CNN
	1    3200 2200
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0101
U 1 1 5E87FDEB
P 800 900
F 0 "#PWR0101" H 800 750 50  0001 C CNN
F 1 "+3.3V" H 815 1073 50  0000 C CNN
F 2 "" H 800 900 50  0001 C CNN
F 3 "" H 800 900 50  0001 C CNN
	1    800  900 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5E8808E3
P 3650 3150
F 0 "#PWR0102" H 3650 2900 50  0001 C CNN
F 1 "GND" H 3655 2977 50  0000 C CNN
F 2 "" H 3650 3150 50  0001 C CNN
F 3 "" H 3650 3150 50  0001 C CNN
	1    3650 3150
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0103
U 1 1 5E884FA8
P 3400 2000
F 0 "#PWR0103" H 3400 1850 50  0001 C CNN
F 1 "+3.3V" H 3415 2173 50  0000 C CNN
F 2 "" H 3400 2000 50  0001 C CNN
F 3 "" H 3400 2000 50  0001 C CNN
	1    3400 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	1000 1150 800  1150
Wire Wire Line
	800  1150 800  900 
$Comp
L power:GND #PWR0104
U 1 1 5E885B43
P 3100 1150
F 0 "#PWR0104" H 3100 900 50  0001 C CNN
F 1 "GND" H 3105 977 50  0000 C CNN
F 2 "" H 3100 1150 50  0001 C CNN
F 3 "" H 3100 1150 50  0001 C CNN
	1    3100 1150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 5E892205
P 4300 1250
F 0 "#PWR0105" H 4300 1000 50  0001 C CNN
F 1 "GND" H 4305 1077 50  0000 C CNN
F 2 "" H 4300 1250 50  0001 C CNN
F 3 "" H 4300 1250 50  0001 C CNN
	1    4300 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 2250 3400 2050
Connection ~ 3200 2350
Wire Wire Line
	3200 2050 3400 2050
Connection ~ 3400 2050
Wire Wire Line
	3400 2050 3400 2000
$Comp
L tiot:shield_relay S1
U 1 1 5E88B0D2
P 4450 3200
F 0 "S1" H 4425 3565 50  0000 C CNN
F 1 "shield_relay" H 4425 3474 50  0000 C CNN
F 2 "tiot:shield_relay" H 4650 2850 50  0001 C CNN
F 3 "~" H 4650 2850 50  0001 C CNN
	1    4450 3200
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0106
U 1 1 5E88F4C9
P 3900 2950
F 0 "#PWR0106" H 3900 2800 50  0001 C CNN
F 1 "+5V" H 3915 3123 50  0000 C CNN
F 2 "" H 3900 2950 50  0001 C CNN
F 3 "" H 3900 2950 50  0001 C CNN
	1    3900 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 3150 3650 3150
Wire Wire Line
	4050 3250 3900 3250
Wire Wire Line
	3900 3250 3900 2950
Wire Wire Line
	2600 2550 3200 2550
Wire Wire Line
	3200 2550 3200 3350
Wire Wire Line
	3200 3350 4050 3350
Text GLabel 5100 3150 2    50   Input ~ 0
out1
Text GLabel 5100 3250 2    50   Input ~ 0
out2
Text GLabel 5100 3350 2    50   Input ~ 0
out3
NoConn ~ 2600 2950
NoConn ~ 2600 2850
NoConn ~ 2600 2750
NoConn ~ 2600 2650
NoConn ~ 2600 1250
NoConn ~ 2600 1350
NoConn ~ 2600 1450
NoConn ~ 2600 1550
NoConn ~ 2600 1650
NoConn ~ 2600 1750
NoConn ~ 2600 1850
NoConn ~ 2600 1950
NoConn ~ 2600 2050
NoConn ~ 2600 2150
NoConn ~ 2600 2250
NoConn ~ 1000 1250
NoConn ~ 1000 1350
NoConn ~ 1000 1450
NoConn ~ 1000 1550
NoConn ~ 1000 1650
NoConn ~ 1000 1750
NoConn ~ 1000 1850
NoConn ~ 1000 1950
NoConn ~ 1000 2050
NoConn ~ 1000 2150
NoConn ~ 1000 2250
NoConn ~ 1000 2350
NoConn ~ 1000 2450
NoConn ~ 1000 2550
NoConn ~ 1000 2650
NoConn ~ 1000 2750
NoConn ~ 1000 2850
NoConn ~ 1000 2950
NoConn ~ 2600 2450
Wire Wire Line
	5100 3150 4800 3150
Wire Wire Line
	4800 3250 5100 3250
Wire Wire Line
	5100 3350 4800 3350
Wire Wire Line
	3100 1150 2600 1150
Wire Wire Line
	2600 2350 3200 2350
$Comp
L Sensor_Temperature:DS18B20 U?
U 1 1 5E9FA75B
P 3850 1500
F 0 "U?" H 3620 1546 50  0000 R CNN
F 1 "DS18B20" H 3620 1455 50  0000 R CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 2850 1250 50  0001 C CNN
F 3 "http://datasheets.maximintegrated.com/en/ds/DS18B20.pdf" H 3700 1750 50  0001 C CNN
	1    3850 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 2250 3850 1800
Wire Wire Line
	3400 2250 3850 2250
Wire Wire Line
	4150 2350 4150 1500
Wire Wire Line
	3200 2350 4150 2350
Wire Wire Line
	3850 1200 3850 1100
Wire Wire Line
	3850 1100 4300 1100
Wire Wire Line
	4300 1100 4300 1250
$EndSCHEMATC
