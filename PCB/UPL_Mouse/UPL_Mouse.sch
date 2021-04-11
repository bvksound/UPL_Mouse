EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "UPL Mouse PS2 to Serial"
Date "2021-03-28"
Rev "1"
Comp "BVKSound"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector:DB9_Female J2
U 1 1 605F6215
P 10400 4900
F 0 "J2" H 10580 4946 50  0000 L CNN
F 1 "DB9_Female" H 10580 4855 50  0000 L CNN
F 2 "Connector_Dsub:DSUB-9_Female_Horizontal_P2.77x2.84mm_EdgePinOffset4.94mm_Housed_MountingHolesOffset7.48mm" H 10400 4900 50  0001 C CNN
F 3 " ~" H 10400 4900 50  0001 C CNN
	1    10400 4900
	1    0    0    -1  
$EndComp
$Comp
L BVKSound:5749180-1 J1
U 1 1 605F82B3
P 4300 2050
F 0 "J1" H 4542 2337 60  0000 C CNN
F 1 "PS2_5749180-1" H 4542 2231 60  0000 C CNN
F 2 "BVKSound:5749180-1" H 4700 1790 60  0001 C CNN
F 3 "" H 4300 2050 60  0000 C CNN
	1    4300 2050
	-1   0    0    -1  
$EndComp
$Comp
L BVKSound:MAX232DR U1
U 1 1 605FC6B2
P 5850 4550
F 0 "U1" H 7150 4937 60  0000 C CNN
F 1 "MAX232DR" H 7150 4831 60  0000 C CNN
F 2 "BVKSound:MAX232DR" H 7150 4790 60  0001 C CNN
F 3 "" H 5850 4550 60  0000 C CNN
	1    5850 4550
	1    0    0    -1  
$EndComp
$Comp
L BVKSound:10118193-0001LF J3
U 1 1 6060772D
P 2050 2650
F 0 "J3" H 2292 2937 60  0000 C CNN
F 1 "USB Micro_10118193-0001LF" H 2800 2850 60  0000 C CNN
F 2 "BVKSound:10118193-0001LF" H 2450 2390 60  0001 C CNN
F 3 "" H 2050 2650 60  0000 C CNN
	1    2050 2650
	-1   0    0    -1  
$EndComp
$Comp
L BVKSound:ATTINY85-20SH U2
U 1 1 6060919A
P 5250 2150
F 0 "U2" H 6350 2537 60  0000 C CNN
F 1 "ATTINY85-20SH" H 6350 2431 60  0000 C CNN
F 2 "BVKSound:ATTINY85-20SH" H 6350 2390 60  0001 C CNN
F 3 "" H 5250 2150 60  0000 C CNN
	1    5250 2150
	1    0    0    -1  
$EndComp
$Comp
L BVKSound:EEE-FC1V1R0R C1
U 1 1 6060D056
P 4850 4550
F 0 "C1" V 5054 4680 50  0000 L CNN
F 1 "EEE-FC1V1R0R" V 5145 4680 50  0000 L CNN
F 2 "CAPAE430X550N" H 5200 4600 50  0001 L CNN
F 3 "https://mouser.componentsearchengine.com/Datasheets/5/EEE-FC1V1R0R.pdf" H 5200 4500 50  0001 L CNN
F 4 "Aluminum Electrolytic Capacitors - SMD 1uF 35V" H 5200 4400 50  0001 L CNN "Description"
F 5 "5.5" H 5200 4300 50  0001 L CNN "Height"
F 6 "Panasonic" H 5200 4200 50  0001 L CNN "Manufacturer_Name"
F 7 "EEE-FC1V1R0R" H 5200 4100 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "667-EEE-FC1V1R0R" H 5200 4000 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Panasonic/EEE-FC1V1R0R/?qs=qE6bgDGEOCv6cHKT%2FPWEYQ%3D%3D" H 5200 3900 50  0001 L CNN "Mouser Price/Stock"
F 10 "EEE-FC1V1R0R" H 5200 3800 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/eee-fc1v1r0r/panasonic" H 5200 3700 50  0001 L CNN "Arrow Price/Stock"
	1    4850 4550
	0    1    1    0   
$EndComp
$Comp
L BVKSound:EEE-FC1V1R0R C2
U 1 1 6060DDEB
P 4850 5250
F 0 "C2" V 5054 5380 50  0000 L CNN
F 1 "EEE-FC1V1R0R" V 5145 5380 50  0000 L CNN
F 2 "CAPAE430X550N" H 5200 5300 50  0001 L CNN
F 3 "https://mouser.componentsearchengine.com/Datasheets/5/EEE-FC1V1R0R.pdf" H 5200 5200 50  0001 L CNN
F 4 "Aluminum Electrolytic Capacitors - SMD 1uF 35V" H 5200 5100 50  0001 L CNN "Description"
F 5 "5.5" H 5200 5000 50  0001 L CNN "Height"
F 6 "Panasonic" H 5200 4900 50  0001 L CNN "Manufacturer_Name"
F 7 "EEE-FC1V1R0R" H 5200 4800 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "667-EEE-FC1V1R0R" H 5200 4700 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Panasonic/EEE-FC1V1R0R/?qs=qE6bgDGEOCv6cHKT%2FPWEYQ%3D%3D" H 5200 4600 50  0001 L CNN "Mouser Price/Stock"
F 10 "EEE-FC1V1R0R" H 5200 4500 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/eee-fc1v1r0r/panasonic" H 5200 4400 50  0001 L CNN "Arrow Price/Stock"
	1    4850 5250
	0    1    1    0   
$EndComp
$Comp
L BVKSound:EEE-FC1V1R0R C3
U 1 1 6060E74F
P 4050 5250
F 0 "C3" V 4254 5380 50  0000 L CNN
F 1 "EEE-FC1V1R0R" V 4345 5380 50  0000 L CNN
F 2 "CAPAE430X550N" H 4400 5300 50  0001 L CNN
F 3 "https://mouser.componentsearchengine.com/Datasheets/5/EEE-FC1V1R0R.pdf" H 4400 5200 50  0001 L CNN
F 4 "Aluminum Electrolytic Capacitors - SMD 1uF 35V" H 4400 5100 50  0001 L CNN "Description"
F 5 "5.5" H 4400 5000 50  0001 L CNN "Height"
F 6 "Panasonic" H 4400 4900 50  0001 L CNN "Manufacturer_Name"
F 7 "EEE-FC1V1R0R" H 4400 4800 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "667-EEE-FC1V1R0R" H 4400 4700 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Panasonic/EEE-FC1V1R0R/?qs=qE6bgDGEOCv6cHKT%2FPWEYQ%3D%3D" H 4400 4600 50  0001 L CNN "Mouser Price/Stock"
F 10 "EEE-FC1V1R0R" H 4400 4500 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/eee-fc1v1r0r/panasonic" H 4400 4400 50  0001 L CNN "Arrow Price/Stock"
	1    4050 5250
	0    1    1    0   
$EndComp
$Comp
L BVKSound:EEE-FC1V1R0R C4
U 1 1 6060F3C9
P 4500 5750
F 0 "C4" V 4796 5620 50  0000 R CNN
F 1 "EEE-FC1V1R0R" V 4705 5620 50  0000 R CNN
F 2 "CAPAE430X550N" H 4850 5800 50  0001 L CNN
F 3 "https://mouser.componentsearchengine.com/Datasheets/5/EEE-FC1V1R0R.pdf" H 4850 5700 50  0001 L CNN
F 4 "Aluminum Electrolytic Capacitors - SMD 1uF 35V" H 4850 5600 50  0001 L CNN "Description"
F 5 "5.5" H 4850 5500 50  0001 L CNN "Height"
F 6 "Panasonic" H 4850 5400 50  0001 L CNN "Manufacturer_Name"
F 7 "EEE-FC1V1R0R" H 4850 5300 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "667-EEE-FC1V1R0R" H 4850 5200 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Panasonic/EEE-FC1V1R0R/?qs=qE6bgDGEOCv6cHKT%2FPWEYQ%3D%3D" H 4850 5100 50  0001 L CNN "Mouser Price/Stock"
F 10 "EEE-FC1V1R0R" H 4850 5000 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/eee-fc1v1r0r/panasonic" H 4850 4900 50  0001 L CNN "Arrow Price/Stock"
	1    4500 5750
	0    -1   -1   0   
$EndComp
$Comp
L Connector:AVR-ISP-6 J4
U 1 1 6060FCC4
P 4300 3700
F 0 "J4" H 3971 3796 50  0000 R CNN
F 1 "AVR-ISP-6" H 3971 3705 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x03_P2.54mm_Vertical" V 4050 3750 50  0001 C CNN
F 3 " ~" H 3025 3150 50  0001 C CNN
	1    4300 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 4550 5850 4550
Wire Wire Line
	5850 4750 5200 4750
Wire Wire Line
	5200 4750 5200 5050
Wire Wire Line
	5200 5050 4850 5050
Wire Wire Line
	4850 5250 5300 5250
Wire Wire Line
	5300 5250 5300 4850
Wire Wire Line
	5300 4850 5850 4850
Wire Wire Line
	5850 4950 5400 4950
Wire Wire Line
	5400 4950 5400 5750
Wire Wire Line
	5400 5750 4850 5750
Wire Wire Line
	4050 5250 4050 4650
Wire Wire Line
	4050 4650 5850 4650
Wire Wire Line
	4500 5250 4500 5150
Wire Wire Line
	4500 5150 5500 5150
Wire Wire Line
	5500 5150 5500 5050
Wire Wire Line
	5500 5050 5850 5050
$Comp
L power:GND #PWR?
U 1 1 606221A8
P 4050 6000
F 0 "#PWR?" H 4050 5750 50  0001 C CNN
F 1 "GND" H 4055 5827 50  0000 C CNN
F 2 "" H 4050 6000 50  0001 C CNN
F 3 "" H 4050 6000 50  0001 C CNN
	1    4050 6000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 6000 4050 5850
Wire Wire Line
	4500 5750 4500 5850
Wire Wire Line
	4500 5850 4050 5850
Connection ~ 4050 5850
Wire Wire Line
	4050 5850 4050 5750
$Comp
L power:GND #PWR?
U 1 1 60622EDC
P 8900 4650
F 0 "#PWR?" H 8900 4400 50  0001 C CNN
F 1 "GND" H 8905 4477 50  0000 C CNN
F 2 "" H 8900 4650 50  0001 C CNN
F 3 "" H 8900 4650 50  0001 C CNN
	1    8900 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	8450 4650 8900 4650
$Comp
L power:VCC #PWR?
U 1 1 60623AFF
P 8700 4350
F 0 "#PWR?" H 8700 4200 50  0001 C CNN
F 1 "VCC" H 8715 4523 50  0000 C CNN
F 2 "" H 8700 4350 50  0001 C CNN
F 3 "" H 8700 4350 50  0001 C CNN
	1    8700 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	8450 4550 8700 4550
Wire Wire Line
	8700 4550 8700 4350
Wire Wire Line
	8450 4850 9350 4850
Wire Wire Line
	5850 5150 5650 5150
Wire Wire Line
	5650 5150 5650 5750
Wire Wire Line
	5650 5750 9800 5750
Wire Wire Line
	9800 5750 9800 4700
Wire Wire Line
	9800 4700 10100 4700
Wire Wire Line
	10100 4900 9350 4900
Wire Wire Line
	9350 4900 9350 4850
Wire Wire Line
	10100 5300 10000 5300
Wire Wire Line
	10000 5300 10000 5750
$Comp
L power:GND #PWR?
U 1 1 6062E667
P 10000 5750
F 0 "#PWR?" H 10000 5500 50  0001 C CNN
F 1 "GND" H 10005 5577 50  0000 C CNN
F 2 "" H 10000 5750 50  0001 C CNN
F 3 "" H 10000 5750 50  0001 C CNN
	1    10000 5750
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 5250 5750 5250
Wire Wire Line
	5750 5250 5750 5650
Wire Wire Line
	5750 5650 9700 5650
Wire Wire Line
	9700 5650 9700 4800
Wire Wire Line
	9700 4800 10100 4800
Wire Wire Line
	7450 2350 7500 2350
Wire Wire Line
	9150 2350 9150 5150
Wire Wire Line
	9150 5150 8450 5150
Wire Wire Line
	7450 2450 7600 2450
Wire Wire Line
	9050 2450 9050 5250
Wire Wire Line
	9050 5250 8450 5250
Wire Wire Line
	8450 4950 9250 4950
Wire Wire Line
	9250 4950 9250 2250
Wire Wire Line
	9250 2250 7700 2250
$Comp
L power:VCC #PWR?
U 1 1 606321E9
P 7600 1950
F 0 "#PWR?" H 7600 1800 50  0001 C CNN
F 1 "VCC" H 7615 2123 50  0000 C CNN
F 2 "" H 7600 1950 50  0001 C CNN
F 3 "" H 7600 1950 50  0001 C CNN
	1    7600 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 2150 7600 2150
Wire Wire Line
	7600 2150 7600 1950
$Comp
L power:GND #PWR?
U 1 1 60633549
P 5050 2600
F 0 "#PWR?" H 5050 2350 50  0001 C CNN
F 1 "GND" H 5055 2427 50  0000 C CNN
F 2 "" H 5050 2600 50  0001 C CNN
F 3 "" H 5050 2600 50  0001 C CNN
	1    5050 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5050 2450 5250 2450
Wire Wire Line
	5250 2350 4600 2350
Wire Wire Line
	5250 2250 4700 2250
Wire Wire Line
	5050 2600 5050 2450
$Comp
L power:GND #PWR?
U 1 1 6063A025
P 4500 2700
F 0 "#PWR?" H 4500 2450 50  0001 C CNN
F 1 "GND" H 4505 2527 50  0000 C CNN
F 2 "" H 4500 2700 50  0001 C CNN
F 3 "" H 4500 2700 50  0001 C CNN
	1    4500 2700
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR?
U 1 1 6063A42F
P 3400 1950
F 0 "#PWR?" H 3400 1800 50  0001 C CNN
F 1 "VCC" H 3415 2123 50  0000 C CNN
F 2 "" H 3400 1950 50  0001 C CNN
F 3 "" H 3400 1950 50  0001 C CNN
	1    3400 1950
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR?
U 1 1 6063F512
P 4200 3100
F 0 "#PWR?" H 4200 2950 50  0001 C CNN
F 1 "VCC" H 4215 3273 50  0000 C CNN
F 2 "" H 4200 3100 50  0001 C CNN
F 3 "" H 4200 3100 50  0001 C CNN
	1    4200 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 3200 4200 3100
$Comp
L power:GND #PWR?
U 1 1 60640D5E
P 4200 4200
F 0 "#PWR?" H 4200 3950 50  0001 C CNN
F 1 "GND" H 4205 4027 50  0000 C CNN
F 2 "" H 4200 4200 50  0001 C CNN
F 3 "" H 4200 4200 50  0001 C CNN
	1    4200 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 4200 4200 4100
Wire Wire Line
	4950 3800 4950 2150
Wire Wire Line
	4950 2150 5250 2150
Wire Wire Line
	4700 3800 4950 3800
Wire Wire Line
	4700 3600 7600 3600
Wire Wire Line
	7600 3600 7600 2450
Connection ~ 7600 2450
Wire Wire Line
	7600 2450 9050 2450
Wire Wire Line
	4700 3500 7500 3500
Wire Wire Line
	7500 3500 7500 2350
Connection ~ 7500 2350
Wire Wire Line
	7500 2350 9150 2350
Wire Wire Line
	4700 3700 7700 3700
Wire Wire Line
	7700 3700 7700 2250
Connection ~ 7700 2250
Wire Wire Line
	7700 2250 7450 2250
$Comp
L power:VCC #PWR?
U 1 1 6064C29F
P 2200 2550
F 0 "#PWR?" H 2200 2400 50  0001 C CNN
F 1 "VCC" H 2215 2723 50  0000 C CNN
F 2 "" H 2200 2550 50  0001 C CNN
F 3 "" H 2200 2550 50  0001 C CNN
	1    2200 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	2050 2650 2200 2650
Wire Wire Line
	2200 2650 2200 2550
$Comp
L power:GND #PWR?
U 1 1 6064E5C9
P 2200 3100
F 0 "#PWR?" H 2200 2850 50  0001 C CNN
F 1 "GND" H 2205 2927 50  0000 C CNN
F 2 "" H 2200 3100 50  0001 C CNN
F 3 "" H 2200 3100 50  0001 C CNN
	1    2200 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2050 3050 2200 3050
Wire Wire Line
	2200 3050 2200 3100
Wire Wire Line
	3500 2050 3400 2050
Wire Wire Line
	3400 2050 3400 1950
Wire Wire Line
	4300 2250 4500 2250
Wire Wire Line
	4500 2250 4500 2700
Wire Wire Line
	3500 2150 3400 2150
Wire Wire Line
	3400 2150 3400 2450
Wire Wire Line
	3400 2450 4700 2450
Wire Wire Line
	4700 2450 4700 2250
Wire Wire Line
	4300 2050 4600 2050
Wire Wire Line
	4600 2050 4600 2350
$EndSCHEMATC
