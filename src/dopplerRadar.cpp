#include "../lib/dopplerRadar.h"
#include <cmath>
#include <limits>

const double SPEED_OF_LIGHT = 3e8; // Speed of light in m/s
const double RADAR_FREQUENCY = 24e9; // Radar frequency in Hz (24 GHz)

DopplerRadar::DopplerRadar(double radarPosX, double radarPosY)
    : radarPosX(radarPosX), radarPosY(radarPosY), minSpeed(std::numeric_limits<double>::max()),
      maxSpeed(0), totalSpeed(0), count(0), hasPrevPos(false) {
    prevPosX = 0.0;
    prevPosY = 0.0;
    prevDistance = 0.0;
}

void DopplerRadar::detect(double vehiclePosX, double vehiclePosY, double currentTime) {
    calculateSpeed(vehiclePosX, vehiclePosY);
}

void DopplerRadar::calculateSpeed(double vehiclePosX, double vehiclePosY) {
    // If we have a previous position, we can calculate the vehicle's velocity vector
    if (hasPrevPos) {
        // Vehicle's displacement vector
        double deltaX = vehiclePosX - prevPosX;
        double deltaY = vehiclePosY - prevPosY;

        // Time between detections
        double timeSec = timeStep;

        // Vehicle's velocity vector components
        double vX = deltaX / timeSec;
        double vY = deltaY / timeSec;

        // Vehicle's speed magnitude
        double vehicleSpeed = sqrt(vX * vX + vY * vY);

        // Line of sight vector from radar to vehicle
        double losX = vehiclePosX - radarPosX;
        double losY = vehiclePosY - radarPosY;
        double losDistance = sqrt(losX * losX + losY * losY);

        // Normalize line of sight vector
        double losUnitX = losX / losDistance;
        double losUnitY = losY / losDistance;

        // Calculate radial velocity (projection of vehicle velocity onto line of sight)
        double radialVelocity = vX * losUnitX + vY * losUnitY;

        // Calculate frequency shift using Doppler effect
        double deltaFrequency = (2 * radialVelocity * RADAR_FREQUENCY) / SPEED_OF_LIGHT;

        // Calculate estimated speed from frequency shift
        double estimatedSpeed = fabs((deltaFrequency * SPEED_OF_LIGHT) / (2 * RADAR_FREQUENCY));

        // Update min, max, and average speeds
        minSpeed = std::min(minSpeed, estimatedSpeed);
        maxSpeed = std::max(maxSpeed, estimatedSpeed);
        totalSpeed += estimatedSpeed;
        count++;
    }

    prevPosX = vehiclePosX;
    prevPosY = vehiclePosY;
    hasPrevPos = true;
}



double DopplerRadar::getMinSpeed() const {
    return minSpeed;
}

double DopplerRadar::getMaxSpeed() const {
    return maxSpeed;
}

double DopplerRadar::getAverageSpeed() const {
    return (count > 0) ? (totalSpeed / count) : 0;
}
