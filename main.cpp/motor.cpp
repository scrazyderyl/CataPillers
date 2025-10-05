#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <Stepper.h>
#include <Arduino.h>
#include <Wire.h>

const int stepsPerRevolution = 2048;  // Most common steppers have 200 steps/revolution

// Initialize the stepper library on pins 2, 3, 4, 5
Stepper myStepper(stepsPerRevolution, 13, 14, 15, 26);

char command;

int currentSteps = 0;
const int stepsIncrement = 256;  // Move 51 steps each press

void releaseMotor() {
  digitalWrite(13, LOW);
  digitalWrite(14, LOW);
  digitalWrite(15, LOW);
  digitalWrite(25, LOW);
}

void resetPosition() {
  // Move back to zero position
  myStepper.step(2048 - currentSteps);
  releaseMotor();
  currentSteps = 0;
  Serial.println("Reset to position 0");
}

void moveSteps(char command) {
  // Move forward by 51 steps

  if (command == 't' || command == 'T') {
      myStepper.step(stepsIncrement);
      currentSteps += stepsIncrement;
      currentSteps %= 2048; // 2048 because 256* 8 capsules
      Serial.print("Moved 360 steps. Total steps: ");
      Serial.print(currentSteps);
      Serial.print(" (");
      Serial.print((currentSteps % stepsPerRevolution) * 360 / stepsPerRevolution);
      Serial.println("°)");
      releaseMotor();
    }
    else if (command == 'r' || command == 'R') {
      resetPosition();
    }
  
}

void moveTo(int capsule){
  
  resetPosition();
  for(int i = 0; i < capsule; i++){
    moveSteps('t');
    delay(300);
  }
}