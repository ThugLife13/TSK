#include "../lib/vehicle.h"
#include <vector>
#include <thread>
#include <chrono>
#include <iostream>

Vehicle::Vehicle() : posX(0), posY(0), carSpeed(0) {}

void Vehicle::startSim(double radarPosX, double radarPosY, double carSpeed) {
    this->carSpeed = carSpeed;
    radar = DopplerRadar(radarPosX, radarPosY);
    move();
}

void Vehicle::move() {
    // Hardcoded array of positions (example positions) TODO
    const int numPositions = 2;
    double positionsX[numPositions] = {0.0, 1.0};
    double positionsY[numPositions] = {0.0, 0.0};

    // Convert speed from km/h to m/s
    double speed_m_per_s = (carSpeed * 1000) / 3600;

    // Calculate total distance between all points
    double totalDistance = 0.0;
    for (int i = 0; i < numPositions - 1; ++i) {
        double deltaX = positionsX[i + 1] - positionsX[i];
        double deltaY = positionsY[i + 1] - positionsY[i];
        totalDistance += sqrt(deltaX * deltaX + deltaY * deltaY);
    }

    // Calculate total time to travel the total distance
    double totalTime = totalDistance / speed_m_per_s;

    // Time between updates
    double timeStep = radar.getTimeStep();

    // Total number of steps
    int totalSteps = static_cast<int>(totalTime / timeStep);

    // Initialize starting position
    posX = positionsX[0];
    posY = positionsY[0];

    // Index of the next waypoint
    int nextPointIndex = 1;

    // Remaining distance to the next point
    double remainingDistance = 0.0;

    // Direction vector components
    double dirX = 0.0;
    double dirY = 0.0;

    for (int step = 0; step <= totalSteps; ++step) {
        // If we have reached the next point, update to the next segment
        if (remainingDistance <= 0.0 && nextPointIndex < numPositions) {
            double deltaX = positionsX[nextPointIndex] - posX;
            double deltaY = positionsY[nextPointIndex] - posY;
            double distanceToNextPoint = sqrt(deltaX * deltaX + deltaY * deltaY);

            // Calculate direction vector components (normalized)
            dirX = deltaX / distanceToNextPoint;
            dirY = deltaY / distanceToNextPoint;

            remainingDistance = distanceToNextPoint;
            nextPointIndex++;
        }

        // Move vehicle along the direction vector
        double distanceToTravel = speed_m_per_s * timeStep;

        // If the distance to travel is more than the remaining distance to the next point
        if (distanceToTravel > remainingDistance) {
            distanceToTravel = remainingDistance;
        }

        posX += dirX * distanceToTravel;
        posY += dirY * distanceToTravel;
        remainingDistance -= distanceToTravel;

        // Update the radar with the current position
        radar.detect(posX, posY);
    }

    // Output results
    std::cout << "Start\n";
    std::cout << "V: " << carSpeed << " km/h\n";
    std::cout << "posX: " << radar.radar_pos_x() << "\n";
    std::cout << "posY: " << radar.radar_pos_y()  << "\n";
    std::cout << "Minimum speed detected: " << radar.getMinSpeed() << " m/s\n";
    std::cout << "Maximum speed detected: " << radar.getMaxSpeed() << " m/s\n";
    std::cout << "Average speed detected: " << radar.getAverageSpeed() << " m/s\n\n";
}
