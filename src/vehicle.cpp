#include "../lib/vehicle.h"

//loading carPath
void Vehicle::loadPath() {
    carPath.push_back(wxPoint(150, 100));
    carPath.push_back(wxPoint(200, 120));
    carPath.push_back(wxPoint(250, 140));
    carPath.push_back(wxPoint(300, 160));
    carPath.push_back(wxPoint(350, 180));
    carPath.push_back(wxPoint(400, 200));
    carPath.push_back(wxPoint(450, 220));
}

Vehicle::~Vehicle() {

}

Vehicle::Vehicle(int radarPosX, int radarPosY, int carSpeed) : radarPosX(radarPosX), radarPosY(radarPosY), carSpeed(carSpeed) {

}

void Vehicle::startSim() {
    loadPath();
    simulationInProgress = simulationLoop();

}

bool Vehicle::simulationLoop() {
    for(int i = 0; i<carPath.size(); i++){
        if(i+1 < carPath.size()){
            i = 0;
        }
        //create line to next point (current car pos, next pos) (return vector of points)
        for(1; 1; 1){ //for all points in line
            if(!true){ //start of sim
                //dopplerRadar startSim (start of sim = true)
            }
            //dopplerRadar calculateSpeed
            //move vehicle
            //refresh frame so the car will move on screen
            //wait (movement on screen should be continuous and slow/visible)
        }
        simulationInProgress = true;
    }
    simulationInProgress = false;
    return simulationInProgress;
}
