#ifndef EVENTHANDLERS_H
#define EVENTHANDLERS_H

#include <wx/wx.h>
#include <wx/spinctrl.h>

#include "vehicle.h"

class eventHandlers {
public:
    void startButtonHandler(wxCommandEvent& evt);
    void newWindowCheckBoxHandler(wxCommandEvent& evt);
    void carSpeedControllerHandler(wxCommandEvent& evt);

    int carSpeed = 1;
    bool newWindow = 0;

    eventHandlers(int car_speed, int sim_speed, bool new_window)
        : carSpeed(car_speed),
          simSpeed(sim_speed),
          newWindow(new_window) {
    }

    ~eventHandlers() = default;
};



#endif //EVENTHANDLERS_H
