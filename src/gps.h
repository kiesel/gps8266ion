#ifndef GPS_H
#define GPS_H

#include <TinyGPS.h>

class GPSTracker {
public:
    GPSTracker(SoftwareSerial*, int baud);
    void init();
    void delay(unsigned long ms);


private:
    void readPosition();
    
    TinyGPS *gps;
    SoftwareSerial *ss;
    int gpsBaud;

    float lat;
    float lon;
    unsigned long age;
};

#endif