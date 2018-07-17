#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include "display.h"

LiquidCrystal_I2C lcd(0x27, 20, 4);
BikeDisplay display(&lcd);
int runs = 0;

void readGps();

void setup() {
    randomSeed(analogRead(0));

    delay(1000);
    Serial.begin(9600);
    while (!Serial);

    Serial.write("Program started.\n");

    lcd.init();
    lcd.begin(16, 2);
    lcd.backlight();
}

void loop() {
    runs++;
    Serial.print("Program running ... ");
    Serial.print(runs);
    Serial.print("\n");
    Serial.flush();

    readGps();
    display.render();

    delay(1000 - (millis() % 1000));
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