#ifndef DOPPLERRADAR_H
#define DOPPLERRADAR_H

#include <chrono>

class DopplerRadar {
public:
    DopplerRadar(double radarPosX = 0, double radarPosY = 0);
    void detect(double vehiclePosX, double vehiclePosY, double currentTime = 0);
    double getMinSpeed() const;
    double getMaxSpeed() const;
    double getAverageSpeed() const;

    double getTimeStep() const { return timeStep; }

    [[nodiscard]] double radar_pos_x() const {
        return radarPosX;
    }

    [[nodiscard]] double radar_pos_y() const {
        return radarPosY;
    }

private:
    double radarPosX, radarPosY;
    double minSpeed, maxSpeed, totalSpeed;
    int count;
    double prevDistance;
    bool hasPrevPos;

    // Add these member variables
    double prevPosX;
    double prevPosY;

    double timeStep = 0.1; // Time between detections in seconds
    void calculateSpeed(double vehiclePosX, double vehiclePosY);
};

#endif // DOPPLERRADAR_H
