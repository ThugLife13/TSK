#include "../lib/eventHandlers.h"

void eventHandlers::startButtonHandler(wxCommandEvent& evt) {
    //tutaj startujemy symulację
    std::cout << "Start" << std::endl;
    std::cout << newWindow << std::endl;
    std::cout << carSpeed << std::endl;
    std::cout << simSpeed << std::endl;
}

void eventHandlers::newWindowCheckBoxHandler(wxCommandEvent& evt) {
    newWindow = evt.GetInt();
    std::cout << evt.GetInt() << std::endl;
}

void eventHandlers::carSpeedControllerHandler(wxCommandEvent& evt) {
    carSpeed = evt.GetInt();
    std::cout << evt.GetInt() << std::endl;
}

void eventHandlers::simSpeedControllerHandler(wxCommandEvent &evt) {
    simSpeed = evt.GetInt();
    std::cout << evt.GetInt() << std::endl;
}