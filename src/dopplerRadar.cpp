#include "../lib/dopplerRadar.h"
#include "../lib/vehicle.h"
#include <limits>
#include <cmath>
#include <iostream>

void dopplerRadar::startSim(const wxPoint& initialPos) {
    // Start simulation by setting initial state
    positionX = initialPos.x;
    positionY = initialPos.y;
    simulationStarted = true;
    isFirstMeasurement = true;
    std::cout << "Simulation started with radar at position: (" << positionX << ", " << positionY << ")" << std::endl;
}

void dopplerRadar::calculateSpeed(const wxPoint& carPos) {
    if (!simulationStarted) {
        return;
    }

    // Calculate distance between radar and car
    double deltaX = carPos.x - positionX;
    double deltaY = carPos.y - positionY;
    double distance = std::sqrt(deltaX * deltaX + deltaY * deltaY); // Distance in meters

    // Assuming radar sends waves and receives reflected waves, calculate Doppler shift
    double relativeSpeed = distance / 0.1; // Example time interval of 0.1 seconds (can be adjusted)
    double dopplerShift = (2 * relativeSpeed * RADAR_FREQUENCY) / SPEED_OF_LIGHT;

    // Calculate speed based on Doppler shift: v = (c * Δf) / (2 * f)
    double speedInMs = (SPEED_OF_LIGHT * dopplerShift) / (2 * RADAR_FREQUENCY);

    // Update speed statistics
    if (speedInMs > highestSpeed) {
        highestSpeed = speedInMs;
    }
    if (speedInMs < lowestSpeed) {
        lowestSpeed = speedInMs;
    }

    // Add speed for average speed calculation and increase counter
    totalSpeed += speedInMs;
    ++speedCounter;

    // Output current speed
    std::cout << "Current Speed: " << speedInMs << " m/s" << std::endl;
}

void dopplerRadar::checkSpeedStatistics() {
    // Function to output or use highest and lowest speed information
    std::cout << "Highest Speed: " << highestSpeed << " m/s" << std::endl;
    std::cout << "Lowest Speed: " << lowestSpeed << " m/s" << std::endl;
}

double dopplerRadar::calculateAverageSpeed() {
    if (speedCounter == 0) {
        std::cout << "No speed data to calculate average." << std::endl;
        return 0;
    }

    double avgSpeed = totalSpeed / speedCounter;
    std::cout << "Average Speed: " << avgSpeed << " m/s" << std::endl;
    return avgSpeed;
}

// Utility function to calculate the Doppler frequency shift
double dopplerRadar::calculateDopplerShift(double transmittedFrequency, double receivedFrequency) {
    return receivedFrequency - transmittedFrequency;
}
