#include "../lib/vehicle.h"

Vehicle::Vehicle(wxStaticBitmap* carBitmap) : carBitmap(carBitmap), currentPointIndex(0) {
    loadPath();
}

void Vehicle::loadPath() {
    carPath.push_back(wxPoint(150, 100));
    carPath.push_back(wxPoint(200, 120));
    carPath.push_back(wxPoint(250, 140));
    carPath.push_back(wxPoint(300, 160));
    carPath.push_back(wxPoint(350, 180));
    carPath.push_back(wxPoint(400, 200));
    carPath.push_back(wxPoint(450, 220));
}

void Vehicle::followPath(wxTimer* carTimer, wxSpinCtrl* carSpeedControllerHandler) {
    carTimer->Start(100);

    carTimer->Bind(wxEVT_TIMER, [this, carSpeedControllerHandler](wxTimerEvent&) {
        if (currentPointIndex >= carPath.size()) {
            currentPointIndex = 0;
        }

        int speed = carSpeedControllerHandler->GetValue();

        wxPoint currentPos = carBitmap->GetPosition();
        posX = currentPos.x;
        posY = currentPos.y;
        wxPoint targetPos = carPath[currentPointIndex];

        int deltaX = targetPos.x - currentPos.x;
        int deltaY = targetPos.y - currentPos.y;

        if (abs(deltaX) <= speed && abs(deltaY) <= speed) {
            carBitmap->SetPosition(targetPos);
            currentPointIndex++;
        } else {
            double angle = atan2(deltaY, deltaX);
            int newX = currentPos.x + static_cast<int>(cos(angle) * speed);
            int newY = currentPos.y + static_cast<int>(sin(angle) * speed);
            carBitmap->SetPosition(wxPoint(newX, newY));
        }
    }, carTimer->GetId());
}
