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

std::vector<wxPoint> Vehicle::createLine(wxPoint start, wxPoint end) {
    std::vector<wxPoint> linePoints;
    int steps = 100;

    double deltaX = (end.x - start.x) / static_cast<double>(steps);
    double deltaY = (end.y - start.y) / static_cast<double>(steps);

    for (int i = 0; i <= steps; ++i) {
        int x = static_cast<int>(start.x + i * deltaX);
        int y = static_cast<int>(start.y + i * deltaY);
        linePoints.push_back(wxPoint(x, y));
    }
    return linePoints;
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
    dopplerRadar* DP = new dopplerRadar(radarPosX, radarPosY);
    for (int i = 0; i < carPath.size() - 1; ++i) {
        wxPoint currentPos = carPath[i];
        wxPoint nextPos = carPath[i + 1];

        // Create line points between the current position and the next position
        std::vector<wxPoint> linePoints = createLine(currentPos, nextPos);

        for (const auto& point : linePoints) {
            // Simulate vehicle movement to each point on the line
            moveVehicle(point);

            if (!simulationInProgress) {
                // Start the radar simulation if it's not already started
                DP->startSim(wxPoint(radarPosX, radarPosY));
                simulationInProgress = true;
            }

            // Calculate vehicle speed at each point (this could be expanded with more realistic calculations)
            DP->calculateSpeed(wxPoint(posX, posY));
        }
    }
    DP->calculateAverageSpeed();

    DP->lowestSpeed;
    DP->highestSpeed;

    simulationInProgress = false;
    return simulationInProgress;
}

void Vehicle::moveVehicle(const wxPoint& newPosition) {
    posX = newPosition.x;
    posY = newPosition.y;
}
