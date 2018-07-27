#ifndef HBridge_h
#define HBridge_h

#include "Arduino.h"

class HBridge
{
  public:
    HBridge(int pinA, int pinB, float dead_band_fct);
    void set_signal(float signal);
  private:
    int _pinA;
    int _pinB;
    float _dead_band_fct;
};

#endif