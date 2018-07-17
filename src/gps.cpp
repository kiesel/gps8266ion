#include <SoftwareSerial.h>
#include <TinyGPS.h>

#include "gps.h"

GPSTracker::GPSTracker(SoftwareSerial *ss, int baud) {
    this->gps = new TinyGPS();
    this->ss = ss;
    this->gpsBaud = baud;
}

void GPSTracker::init() {
    Serial.write("Initializing GPS (via SoftwareSerial)\n");
    ss->begin(gpsBaud);
}

void GPSTracker::delay(unsigned long ms) {
    unsigned long end = millis() + ms;
    do {
        while (ss->available()) {
            this->gps->encode(ss->read());
        }
    } while (millis() >= end);
}

unsigned long getAge() {
    float lat, lon;
    unsigned long age;
    gps->f_get_position(&lat, &lon, &age);

    if (lat != TinyGPS::GPS_INVALID_F_ANGLE) {
        this->lat = lat;
    }

    if (lon != TinyGPS::GPS_INVALID_F_ANGLE) {
        this->lon = lon;
    }

    if (age != TinyGPS::GPS_INVALID_AGE) {
        this->age = age;
    }


}
