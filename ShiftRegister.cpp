#include "Arduino.h"
#include "ShiftRegister.h"


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

void ShiftRegister::registerWrite(int pin, int state){
  if (pin >= 0 && pin <= 7) {
    digitalWrite(_latchPin, LOW);

    if (state == LOW) {
      _binTemp &= ~(1 << pin);
    } else if (state = HIGH) {
      _binTemp |= (1 << pin);
    }

    shiftOut(_dataPin, _clockPin, MSBFIRST, _binTemp);
    digitalWrite(_latchPin, HIGH);
  }
}

void ShiftRegister::setDebug(bool state){
  this->_debug = state;
}
