#define BUZZER_PIN 25  // choose a free pin for your buzzer
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <Stepper.h>

const int stepsPerRevolution = 2048;  // Most common steppers have 200 steps/revolution

// Initialize the stepper library on pins 2, 3, 4, 5
Stepper myStepper(stepsPerRevolution, 13, 14, 15, 26);

char command;
int currentSteps = 0;
const int stepsIncrement = 256;  // Move 51 steps each press

void setup() {
  Serial.begin(115200);
  
  // Set the speed in RPM (Rotations Per Minute)
  myStepper.setSpeed(10);

  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT); 
  pinMode(25, OUTPUT);
  releaseMotor();
  
  Serial.println("Stepper Motor Ready");
  Serial.println("Send 't' to move 45 degrees forward");
  Serial.println("Send 'r' to reset to position 0");
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();
    Serial.println("enter t to turn or r to return");
    moveSteps(command);
    buzzer(command);
  }
}

void buzzer(char command){
   switch(command) {
      case '1':
        singleBeep();
        break;
      case '2':
        alarmSound();
        break;
      case '3':
        playMelody();
        break;
}

    releaseMotor();
}

void moveSteps(char command) {
  // Move forward by 51 steps

  if (command == 't' || command == 'T') {
      myStepper.step(stepsIncrement);
      currentSteps += stepsIncrement;
      currentSteps%= 2048;
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

void resetPosition() {
  // Move back to zero position
  myStepper.step((8*256)-currentSteps);
  releaseMotor();
  currentSteps = 0;
  Serial.println("Reset to position 0");
}

void singleBeep() {
  tone(BUZZER_PIN, 1000, 200);  // 1kHz for 200ms
  delay(250);                   // wait a bit before next action
}

void alarmSound() {
  for (int i = 0; i < 5; i++) {
    tone(BUZZER_PIN, 2000, 500); // 2kHz for 200ms
    delay(300);
  }
}

void playMelody() {
  int melody[] = { 262, 294, 330, 349, 392, 440, 494 }; // C D E F G A B
  int noteDurations = 200;

  for (int i = 0; i < 7; i++) {
    tone(BUZZER_PIN, melody[i], noteDurations);
    delay(noteDurations + 50);
  }
}

void releaseMotor() {
  digitalWrite(13, LOW);
  digitalWrite(14, LOW);
  digitalWrite(15, LOW);
  digitalWrite(25, LOW);
}