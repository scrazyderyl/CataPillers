#define BUZZER_PIN 25  // choose a free pin for your buzzer
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <Stepper.h>
#include "buzzer.h"

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