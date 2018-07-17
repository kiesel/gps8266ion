#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "display.h"

BikeDisplay::BikeDisplay(LiquidCrystal_I2C *disp) {
    this->lcd = disp;
    currentSpeed = 0.0;
    elapsedTime = 0;
    activeTime = 0;
}

void BikeDisplay::setCurrentSpeed(float speed) {
    currentSpeed = speed;
}

float BikeDisplay::getCurrentSpeed() {
    return currentSpeed;
}

void BikeDisplay::setElapsedTime(int time) {
    elapsedTime = time;
}

void BikeDisplay::setActiveTime(int time) {
    activeTime = time;
}

void BikeDisplay::render() {
    char buf[16];
    // lcd->clear();
    lcd->home();

    sprintf(buf, "%02.1fkm/h", currentSpeed);
    lcd->print(String(buf));

    sprintf(buf, "%02d:%02dm", elapsedTime / 60, elapsedTime % 60);
    lcd->setCursor(16 - strlen(buf), 0);
    lcd->print(String(buf));
}