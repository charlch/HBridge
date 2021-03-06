#include "Arduino.h"
#include "HBridge.h"

HBridge::HBridge(int pinA, int pinB)
{
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  _pinA = pinA;
  _pinB = pinB;
  _pinEn = -1;
  _dead_band_fct = 0.01;
  set_signal(0.0);
}

HBridge::HBridge(int pinA, int pinB, int pinEn)
{
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinEn, OUTPUT);
  _pinA = pinA;
  _pinB = pinB;
  _pinEn = pinEn;
  _dead_band_fct = 0.01;
  set_signal(0.0);
}

void HBridge::set_dead_band_fct(float dead_band_fct)
{
  _dead_band_fct = dead_band_fct;
}

void HBridge::set_signal(float signal)
{

  if (abs(signal)<_dead_band_fct)
  {
    /* Braking */
    signal = 0;
  }
  
  int inSig;

  if (_pinEn > -1)
  {
    analogWrite(_pinEn, (int)255*abs(signal));
    inSig = 255;
  }
  else
  {
    inSig = (int)255*abs(signal);
  }

  if (signal > 0)
  {
    analogWrite(_pinA, inSig);
    analogWrite(_pinB, 0);
  }
  else
  {
    analogWrite(_pinB, inSig);
    analogWrite(_pinA, 0);
  }
}
