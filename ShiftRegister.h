#include "Arduino.h"

class ShiftRegister{
  public:
    ShiftRegister(int dataPin, int latchPin, int clockPin);
    void init();
    void registerWrite(int pin, int state);
    void setDebug(bool state);

  private:
    int _dataPin;
    int _latchPin;
    int _clockPin;
    int _binTemp;
    bool _debug = false;

};
