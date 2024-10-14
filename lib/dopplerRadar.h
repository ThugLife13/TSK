#ifndef DOPPLERRADAR_H
#define DOPPLERRADAR_H

#include "vehicle.h"

class dopplerRadar {

private:
    //position of a radar
    int positionX;
    int positionY;

    //position of a vehicle
    int vehiclePositionX;
    int vehiclePositionY;
    int lastVehiclePositionX;
    int lastVehiclePositionY;

    //calculated speed of a vehicle
    int calculatedSpeed;

    vehicle* Vehicle;

public:
    //constructors
    dopplerRadar();
    dopplerRadar(int positionX, int positionY, vehicle* Vehicle);

    //getters for radar position
    int getPositionX() const;
    int getPositionY() const;

    //vehicle position
    void getVehiclePositionX();

    void getVehiclePositionY();

    //calculated speed
    int getCalculatedSpeed() const;

    //calculating speed
    void calculateSpeed(int vehiclePosX, int vehiclePosY);

    ~dopplerRadar() = default;
};



#endif //DOPPLERRADAR_H
