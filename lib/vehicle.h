#ifndef VEHICLE_H
#define VEHICLE_H

#include "dopplerRadar.h"

class Vehicle {
public:
    Vehicle();
    void startSim(double radarPosX, double radarPosY, double carSpeed);
private:
    DopplerRadar radar;
    double carSpeed; // in km/h
    double posX, posY;
    void move();
};

#endif // VEHICLE_H

