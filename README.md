Project: Arduino_Henhouse_000 

Author: Henrik Hansen, Electronic And Code (EAC), Denmark

This repo is in alfa state and under construction (Start maj 2020). 

This repo is for a Arduino automated henhouse.

Part of Open Source code used from Makersguide.com:
Thanks to Benne de Bakker, for the guide at Makersguide.com
https://www.makerguides.com/28byj-48-stepper-motor-arduino-tutorial/

https://www.makerguides.com/wp-content/uploads/2019/04/28byj48-Stepper-Motor-Datasheet.pdf
Stepper motor: 28BYJ-48, 4096 step = 1 revolution

Project data:
PSU MCU: 5VDC
PSU motordriver / Steppermotor: 5VDC

Test load: 1000kg
Max speed with 1000kg load = 500
Current with load at speed 500 = 180mA
Recommanded speed for all load = 500

Test 260kg
Speed = 500
Current with load = 180mA


MCU: Arduino Mini Pro for test
(Upgrades to Arduino Nano 33 IoT)

OnBoard LED PIN 13 for MCU programming connection test
MCU PIN: D13

Motor Driver board: ULN2003 stepper motor driver and 28BYJ-48 - 5VDC Steppermotor. MOTOR TEST for henhouse door open/Close
MCU PIN: D8, D9, D10, D11 - OUTPUT

Photoresistor, light sensor
MCU PIN: A0 - INPUT

MagneticSensorSwitch, motor stop control
MCU PIN: D2 (Open), D3 (Closed) - INPUT

Push button, critical stop
MCU PIN: D4 - INPUT

Push button, manuel motor control for henhouse door Open/Close
MCU PIN: D5 (Open), D6 (Close) - INPUT

PushButton, manuel light on/off
MCU PIN: D7 (Toggle) - INPUT

230VAC 10A relay, power On/Off for 230VAC light
MCU PIN: D12 - OUTPUT

