Project: Arduino_Henhouse_000 

Author: Henrik Hansen, Electronic And Code (EAC), Denmark

This repo is in alfa state and under construction (Start maj 2020). 

This repo is for a Arduino automated henhouse.

Part of Open Source code used from Makersguide.com:
Thanks to Benne de Bakker, for the guide at Makersguide.com
https://www.makerguides.com/28byj-48-stepper-motor-arduino-tutorial/



MCU: Arduino Mini Pro for test
(Upgrades to Arduino Nano 33 IoT)

OnBoard LED PIN 13 for MCU programming connection test
MCU PIN: D13

Motor Driver board: ULN2003 stepper motor driver and 28BYJ-48 - 5VDC Steppermotor. MOTOR TEST for henhouse door open/Close
MCU PIN: D8, D9, D10, D11 - OUTPUT

Photoresistor, light sensor
MCU PIN: A0 - INPUT

MagneticSensorSwitch, motor stop control
MCU PIN: D2, D3 - INPUT

Push button, critical stop
MCU PIN: D4 - INPUT

Push button, manuel motor control for henhouse door Open/Close
MCU PIN: D5, D6 - INPUT

PushButton, manuel light on/off
MCU PIN: D7 - INPUT

230VAC 10A relay, power On/Off for 230VAC light
MCU PIN: D12 - OUTPUT

