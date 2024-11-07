#ifndef DOPPLERRADAR_H
#define DOPPLERRADAR_H
#include <wx/wx.h>


class dopplerRadar {
public:
    int positionX = 0;
    int positionY = 0;

    dopplerRadar(int position_x, int position_y)
        : positionX(position_x),
          positionY(position_y) {
    }

    ~dopplerRadar() = default;

    // Start the simulation by taking the initial position of the car
    void startSim(const wxPoint& initialPos);

    // Calculate the speed based on Doppler wave frequency change
    void calculateSpeed(const wxPoint& carPos);

    // Output the highest and lowest speed statistics
    void checkSpeedStatistics();

    // Calculate and output the average speed
    double calculateAverageSpeed();

    double highestSpeed = std::numeric_limits<double>::min();
    double lowestSpeed = std::numeric_limits<double>::max();

private:
    bool simulationStarted = false;
    bool isFirstMeasurement = true;

    // Utility function to calculate the Doppler frequency shift
    double calculateDopplerShift(double transmittedFrequency, double receivedFrequency);

    // Constants
    constexpr static double SPEED_OF_LIGHT = 299792458.0; // m/s
    constexpr static double RADAR_FREQUENCY = 24.0e9; // 24 GHz (typical radar frequency)

    // Speed statistics

    double totalSpeed = 0;
    int speedCounter = 0;

};



#endif //DOPPLERRADAR_H

