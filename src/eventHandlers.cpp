#include "../lib/eventHandlers.h"

void eventHandlers::startButtonHandler(wxCommandEvent& evt) {
    //tutaj startujemy symulację
    std::cout << "Start" << std::endl;
    std::cout << newWindow << std::endl;
    std::cout << carSpeed << std::endl;

    Vehicle *vehicle = new Vehicle(0, 0, carSpeed);

    vehicle->startSim();
}

void eventHandlers::newWindowCheckBoxHandler(wxCommandEvent& evt) {
    newWindow = evt.GetInt();
    std::cout << evt.GetInt() << std::endl;
}

void eventHandlers::carSpeedControllerHandler(wxCommandEvent& evt) {
    carSpeed = evt.GetInt();
    std::cout << evt.GetInt() << std::endl;
}