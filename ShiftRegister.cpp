#include "Arduino.h"
#include "ShiftRegister.h"

/*
 * Constructor
*/
ShiftRegister::ShiftRegister(int dataPin, int latchPin, int clockPin){
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

  _latchPin = latchPin;
  _dataPin = dataPin;
  _clockPin = clockPin;
  _binTemp = 0;

  if (this->_debug) Serial.begin(9600);

}

/*
 * Write a register pin (From 0 - 7) to HIGH or LOW
*/

void ShiftRegister::registerWrite(int pin, int state){
  if (pin >= 0 && pin <= 7) {
    if (state == LOW) {
      _binTemp &= ~(1 << pin);
    } else if (state = HIGH) {
      _binTemp |= (1 << pin);
    }
    digitalWrite(_latchPin, LOW);
    shiftOut(_dataPin, _clockPin, MSBFIRST, _binTemp);
    digitalWrite(_latchPin, HIGH);
  }
}

/*
 * Switch all pins to a certain state
*/
void ShiftRegister::registerWriteAll(int state){
  if (state == HIGH) {
    _binTemp |= 2^8;
  else {
    _binTemp &= 0;
  }
  
    digitalWrite(_latchPin, LOW);
    shiftOut(_dataPin, _clockPin, MSBFIRST, _binTemp);
    digitalWrite(_latchPin, HIGH);
  
}


void ShiftRegister::setDebug(bool state){
  this->_debug = state;
}
