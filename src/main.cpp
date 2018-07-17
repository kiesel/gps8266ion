#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

#include "display.h"
#include "gps.h"
#include "config.h"

BikeDisplay display(new LiquidCrystal_I2C(LC_ADDR, 20, 4));
GPSTracker gps(new SoftwareSerial(PIN_GPS_RX, PIN_GPS_TX), GPS_BAUDRATE);

void readGps();

void setup() {
    randomSeed(analogRead(0));
    delay(1000);

    Serial.begin(9600);
    while (!Serial);

    Serial.write("Initializing program ...\n");

    display.init();
    gps.init();

    display.setStatus(BikeDisplay::WAITING_GPS);
}

void loop() {
    readGps();
    display.render();

    gps.delay(1000 - (millis() % 1000));
}

void readGps() {
    float speed = display.getCurrentSpeed();
    int rnd = random(0, 30);
    if (rnd >= speed) {
        speed += 1;
    } else {
        speed -= 1;
    }

    display.setCurrentSpeed(speed);
    display.setElapsedTime(millis() / 1000);
}