#ifndef HBridge_h
#define HBridge_h

#include "Arduino.h"

class HBridge
{
  public:
    HBridge(int pinA, int pinB);
    HBridge(int pinA, int pinB, int pinEn);
    void set_dead_band_fct(float dead_band_fct);
    void set_signal(float signal);
  private:
    int _pinA;
    int _pinB;
    int _pinEn;
    float _dead_band_fct;
};

#endif
