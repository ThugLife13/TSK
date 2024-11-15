#ifndef EVENTHANDLERS_H
#define EVENTHANDLERS_H

#include <wx/wx.h>
#include <wx/spinctrl.h>

#include "vehicle.h"

class eventHandlers {
public:
    void startButtonHandler(wxCommandEvent& evt);
    void carSpeedControllerHandler(wxCommandEvent& evt);

    //void newWindowCheckBoxHandler(wxCommandEvent& evt);
    //void radarPosXControllerHandler(wxCommandEvent& evt);
    //void radarPosYControllerHandler(wxCommandEvent& evt);

    int carSpeed = 1;

    int radarPositionX = 0;
    int radarPositionY = 0;

    //bool newWindow = 0;

    // eventHandlers(int car_speed, bool new_window)
    //     : carSpeed(car_speed),
    //       newWindow(new_window) {
    // }

    eventHandlers(int car_speed) : carSpeed(car_speed){
    }

    ~eventHandlers() = default;
};



#endif //EVENTHANDLERS_H
