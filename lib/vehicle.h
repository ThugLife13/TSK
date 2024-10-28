#ifndef VEHICLE_H
#define VEHICLE_H

#include <vector>
#include <wx/wx.h>
#include <cmath>
#include <wx/msw/spinctrl.h>

#include "dopplerRadar.h"

class Vehicle {
public:
    int posX;
    int posY;

    int radarPosX;
    int radarPosY;

    int carSpeed;

    void startSim();

    Vehicle(int radarPosX, int radarPosY, int carSpeed);

    virtual ~Vehicle();

    bool simulationInProgress;
private:
    std::vector<wxPoint> carPath;
    int currentPointIndex;

    void loadPath();

    bool simulationLoop();
};

#endif // VEHICLE_H
