//
// Created by mateu on 14.10.2024.
//

#include "../lib/dopplerRadar.h"

dopplerRadar::dopplerRadar() {
}

dopplerRadar::dopplerRadar(int positionX, int positionY, vehicle *Vehicle) {
}

int dopplerRadar::getPositionX() const {
    return positionX;
}

int dopplerRadar::getPositionY() const {
    return positionY;
}

void dopplerRadar::getVehiclePositionX() {
    vehiclePositionX = Vehicle->get_positionX();
}

void dopplerRadar::getVehiclePositionY() {
    vehiclePositionY = Vehicle->get_positionY();
}

int dopplerRadar::getCalculatedSpeed() const {
    return calculatedSpeed;
}

void dopplerRadar::calculateSpeed(int vehiclePosX, int vehiclePosY) {

}

