#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <Stepper.h>

const int stepsPerRevolution = 2048;  // Most common steppers have 200 steps/revolution

// Initialize the stepper library on pins 2, 3, 4, 5
Stepper myStepper(stepsPerRevolution, 13, 14, 15, 25);

int currentSteps = 0;
const int stepsIncrement = 293;  // Move 51 steps each press

void setup() {
  Serial.begin(115200);
  
  // Set the speed in RPM (Rotations Per Minute)
  myStepper.setSpeed(10);
  
  Serial.println("Stepper Motor Ready");
  Serial.println("Send 't' to move 51 steps forward");
  Serial.println("Send 'r' to reset to position 0");
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    Serial.println("enter t to turn or r to return");
    if (command == 't' || command == 'T') {
      moveSteps();
    }
    else if (command == 'r' || command == 'R') {
      resetPosition();
    }
  }
}

void moveSteps() {
  // Move forward by 51 steps
  myStepper.step(stepsIncrement);
  currentSteps += stepsIncrement;
  
  Serial.print("Moved 51 steps. Total steps: ");
  Serial.print(currentSteps);
  Serial.print(" (");
  Serial.print((currentSteps % stepsPerRevolution) * 360 / stepsPerRevolution);
  Serial.println("°)");
}

void resetPosition() {
  // Move back to zero position
  myStepper.step(-currentSteps);
  currentSteps = 0;
  Serial.println("Reset to position 0");
}