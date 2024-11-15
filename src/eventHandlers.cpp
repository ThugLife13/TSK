#include "../lib/eventHandlers.h"

void eventHandlers::startButtonHandler(wxCommandEvent& evt) {
    //tutaj startujemy symulację
    std::cout << "Start" << std::endl;
    std::cout << carSpeed << std::endl;
    std::cout << radarPositionX << std::endl;
    std::cout << radarPositionY << std::endl;

    //teraz wrzucić metodę która poprowadzi samochód po trasie jednocześnie sprawdzając jego prędkość radarem dopplera
    Vehicle* vehicle = new Vehicle();
    vehicle->startSim(radarPositionX, radarPositionY, carSpeed);

    delete vehicle;
}

// void eventHandlers::newWindowCheckBoxHandler(wxCommandEvent& evt) {
//     newWindow = evt.GetInt();
//     std::cout << evt.GetInt() << std::endl;
// }



void eventHandlers::carSpeedControllerHandler(wxCommandEvent& evt) {
    carSpeed = evt.GetInt();
    //std::cout << evt.GetInt() << std::endl;
}


// void eventHandlers::radarPosXControllerHandler(wxCommandEvent &evt) {
//     radarPositionX = evt.GetInt();
// }
//
// void eventHandlers::radarPosYControllerHandler(wxCommandEvent &evt) {
//     radarPositionY = evt.GetInt();
// }
