#include "../lib/eventHandlers.h"

void eventHandlers::startButtonHandler(wxCommandEvent& evt) {
    //tutaj startujemy symulację
    std::cout << "Start" << std::endl;
    std::cout << carSpeed << std::endl;

    //std::cout <<

    Vehicle *vehicle = new Vehicle(0, 0, carSpeed);

    vehicle->startSim();
}

// void eventHandlers::newWindowCheckBoxHandler(wxCommandEvent& evt) {
//     newWindow = evt.GetInt();
//     std::cout << evt.GetInt() << std::endl;
// }



void eventHandlers::carSpeedControllerHandler(wxCommandEvent& evt) {
    carSpeed = evt.GetInt();
    std::cout << evt.GetInt() << std::endl;
}


// void eventHandlers::radarPosXControllerHandler(wxCommandEvent &evt) {
//     radarPositionX = evt.GetInt();
// }
//
// void eventHandlers::radarPosYControllerHandler(wxCommandEvent &evt) {
//     radarPositionY = evt.GetInt();
// }
