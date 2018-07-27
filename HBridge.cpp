#include "Arduino.h"
#include "HBridge.h"

HBridge::HBridge(int pinA, int pinB, float dead_band_fct)
{
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  _pinA = pinA;
  _pinB = pinB;
  _dead_band_fct = dead_band_fct;
  set_signal(0.0);
}

void HBridge::set_signal(float signal)
{

  if (abs(signal)<_dead_band_fct)
  {
    /* Braking */
    signal = 0;
  }

  if (signal > 0)
  {
    analogWrite(_pinA, (int)255*signal);
    analogWrite(_pinB, 0);
  }
  else
  {
    analogWrite(_pinB, (int)255*signal);
    analogWrite(_pinA, 0);
  }
}