# HBridge 


Example:
```
#include <HBridge.h>

const float DEAD_BAND_FRC = 0.01;

//Create the motor driver, setting it's pins and dead band fraction
HBridge motor(1, 2, DEAD_BAND_FRC);


//Drive the motor forward at 50%
motor.set_signal(0.5);
```
