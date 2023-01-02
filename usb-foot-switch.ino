/*
  USB foot switch test for Emacs

  For the Arduino Leonardo

  Sends a META or CTRL when pedal pressed.
  An additonal bonus pedal is also included.
  RSI begone.

  The circuit is described in diagrams/circuit-diagram.jpg

  created 10 July 2022, 6 Aug 2022
  updated 2 January 2023
  by J. Clark

  Based on the tutorial code
  http://www.arduino.cc/en/Tutorial/KeyboardMessage
*/

#include "Keyboard.h"

const int ctrlPin = 2;
const int metaPin = 5;
const int bonusPin = 7;
int prevCtrlSwitchState = LOW;
int prevMetaSwitchState = LOW;
int prevBonusSwitchState = LOW;

void setup() {
  pinMode(ctrlPin, INPUT);
  pinMode(metaPin, INPUT);
  pinMode(bonusPin, INPUT);
  Keyboard.begin();
  Serial.begin(9600);
}

void loop() {
  // read switch states:
  int ctrlSwitchState = digitalRead(ctrlPin);
  int metaSwitchState = digitalRead(metaPin);
  int bonusSwitchState = digitalRead(bonusPin);
  // CTRL check
  if ((ctrlSwitchState != prevCtrlSwitchState) && (ctrlSwitchState == HIGH)) {
    Keyboard.press(KEY_LEFT_CTRL);
    Serial.println("PRESSED CTRL");
  }
  if ((ctrlSwitchState != prevCtrlSwitchState) && (ctrlSwitchState == LOW)) {
    Keyboard.release(KEY_LEFT_CTRL);
    Serial.println("RELEASED CTRL");
    delay(1);
  }
  // META check
  if ((metaSwitchState != prevMetaSwitchState) && (metaSwitchState == HIGH)) {
    Keyboard.press(KEY_LEFT_ALT);
    Serial.println("PRESSED ALT");
  }
  if ((metaSwitchState != prevMetaSwitchState) && (metaSwitchState == LOW)) {
    Keyboard.release(KEY_LEFT_ALT);
    Serial.println("RELEASED ALT");
    delay(1);
  }
  // BONUS check
  if ((bonusSwitchState != prevBonusSwitchState) && (bonusSwitchState == HIGH)) {
    Keyboard.press(KEY_PAGE_DOWN);
    Serial.println("PRESSED PAGE DOWN");
  }
  if ((bonusSwitchState != prevBonusSwitchState) && (bonusSwitchState == LOW)) {
    Keyboard.release(KEY_PAGE_DOWN);
    Serial.println("RELEASED PAGE DOWN");
    delay(1);
  }
  // save the current switch state for comparison:
  prevCtrlSwitchState = ctrlSwitchState;
  prevMetaSwitchState = metaSwitchState;
  prevBonusSwitchState = bonusSwitchState;
}
