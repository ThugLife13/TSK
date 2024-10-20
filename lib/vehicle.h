#ifndef VEHICLE_H
#define VEHICLE_H

#include <vector>
#include <wx/wx.h>
#include <cmath>
#include <wx/msw/spinctrl.h>

class Vehicle {
public:
    Vehicle(wxStaticBitmap* carBitmap);
    void followPath(wxTimer* carTimer, wxSpinCtrl* carSpeedControllerHandler);

    int posX;
    int posY;

private:
    wxStaticBitmap* carBitmap;
    std::vector<wxPoint> carPath;
    size_t currentPointIndex;

    void loadPath();
};

#endif // VEHICLE_H
