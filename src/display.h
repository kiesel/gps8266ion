#ifndef BIKEDISPLAY_H
#define BIKEDISPLAY_H

#include "LiquidCrystal_I2C.h"

class BikeDisplay {
public:
    BikeDisplay(LiquidCrystal_I2C*);
    void setCurrentSpeed(float speed);
    float getCurrentSpeed();
    void setElapsedTime(int time);
    void setActiveTime(int time);
    void render();

private:
    LiquidCrystal_I2C *lcd;
    float currentSpeed;
    int elapsedTime;
    int activeTime; 
};

#endif