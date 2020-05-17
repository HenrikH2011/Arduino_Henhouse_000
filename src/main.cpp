/*
Project: Arduino_Henhouse_000 

Author/Editor: Henrik Hansen, Electronic And Code (EAC), Denmark

This code is in alfa state and under construction (Start maj 2020). 

This code is for a Arduino automated henhouse.

Part of Open Source code used from Makersguide.com:
Thanks to Benne de Bakker, for the guide at Makersguide.com
https://www.makerguides.com/28byj-48-stepper-motor-arduino-tutorial/

*/


/*
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(2000);                       // wait for a second
}
*/

/* Example sketch to control a 28BYJ-48 stepper motor with ULN2003 driver board, AccelStepper and Arduino UNO: number of steps/revolutions. More info: https://www.makerguides.com */
// Include the AccelStepper library:
#include <Arduino.h>
#include <AccelStepper.h>

// Magnetic Sensor pin definition:
#define magSensOpen 2      //Magnetic Sensor Up/Open
#define magSensClose 3      //Magnetic Sensor Down/Close

// Critical STOP PushButtom:
#define criticalStop 4    //Critical STOP SwitchButtom

// Manuel Henhouse door control - Open/Close:
#define manuelOpen 5      // Manuel Open SwitchButtom
#define manmuelClose 6    // Manuel Close SwitchButtom

// Manuel Light On/Off:
#define manuelLight 7     // Manuel Light On/Off SwitchButtom

// Motor pin definitions:
#define motorPin1  8      // IN1 on the ULN2003 driver
#define motorPin2  9      // IN2 on the ULN2003 driver
#define motorPin3  10     // IN3 on the ULN2003 driver
#define motorPin4  11     // IN4 on the ULN2003 driver
// Define the AccelStepper interface type; 4 wire motor in half step mode:
#define MotorInterfaceType 8
// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper library with 28BYJ-48 stepper motor:
AccelStepper stepper = AccelStepper(MotorInterfaceType, motorPin1, motorPin3, motorPin2, motorPin4);

const int lightSensorPin = A0; // OUTPUT, Analog read photoresistor

const int magneticSensorOpenPin = 2; // INPUT, Digital read magnetic senor for henhouse door open state
const int magneticSensorClosePin = 3; // INPUT, Digital read magnetic sensor for henhouse door close state

const int pushButtonCriticalStopPin = 4; //   INPUT, Digital read for henhouse door critical stop

const int pushButtonMotorUpPin = 5; // INPUT, Digital read pushbutton
const int pushButtonMotorDownPin = 6; // INPUT, Digital read pushbutton

const int pushButtonLightPin = 7; // INPUT, Digital read for light on/off. Indoor light in henhouse (230VAC lamp relay control)
const int lightRelayPin = 12; // OUTPUT, Digital write for 230VAC relay control board (indoor light in henhouse)


void setup() 
{
  // initialize digital pin LED_BUILTIN as an output. For MCU connection test
  pinMode(LED_BUILTIN, OUTPUT);
  
  // Set the maximum steps per second:
  stepper.setMaxSpeed(500); // MAX speed 500 with a load = 1000kg Recommanded load max 500kg
}

void loop() 
{
  //MCU connection test
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(2000);                       // wait for a second
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  
 
  // Set the current position to 0:
  stepper.setCurrentPosition(0);
  // Run the motor forward at x steps/second until the motor reaches y steps (4096 step = 1 revolution) UP/OPEN :
  while (stepper.currentPosition() != 25480) {
    stepper.setSpeed(500);
    stepper.runSpeed();
  }
  delay(1000);
  // Reset the position to 0:
  stepper.setCurrentPosition(0);
  // Run the motor backwards at x steps/second until the motor reaches -y steps (z revolution) DOWN/CLOSE : 
  while (stepper.currentPosition() != -25480) {
    stepper.setSpeed(-500);
    stepper.runSpeed();
  }
  delay(1000);

 /*
  // Reset the position to 0:
  stepper.setCurrentPosition(0);
  // Run the motor forward at 1000 steps/second until the motor reaches 8192 steps (2 revolutions):
  while (stepper.currentPosition() != 8192) {
    stepper.setSpeed(1000);
    stepper.runSpeed();

  
  }
 */  
 // delay(3000);


}