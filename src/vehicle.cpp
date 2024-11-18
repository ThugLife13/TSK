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
    // Hardcoded array of positions (example positions)
    // Used ChatGPT to generate points on the track based on uploaded image
    const int numPositions = 364;
    double positionsX[numPositions] = {157, 160, 161, 163, 166, 166, 169, 173, 180, 185, 185, 195, 205, 205, 208, 213,
        218, 223, 226, 227, 228, 231, 239, 239, 242, 244, 248, 249, 251, 257, 262, 262, 264, 265, 270, 271, 273, 273,
        278, 279, 282, 283, 291, 292, 294, 295, 302, 310, 311, 314, 315, 325, 336, 337, 339, 340, 348, 356, 357, 358,
        359, 368, 368, 371, 371, 377, 380, 384, 385, 387, 388, 392, 394, 399, 401, 404, 406, 410, 412, 415, 417, 420,
        420, 422, 425, 431, 431, 434, 434, 440, 447, 455, 463, 462, 470, 476, 483, 486, 493, 494, 497, 496, 500, 509,
        512, 513, 515, 524, 534, 536, 548, 552, 554, 558, 560, 564, 566, 570, 572, 575, 576, 578, 579, 581, 582, 584,
        585, 587, 588, 590, 591, 593, 594, 596, 597, 600, 602, 605, 606, 608, 609, 611, 612, 614, 618, 620, 624, 626,
        637, 639, 640, 642, 643, 645, 646, 648, 648, 655, 659, 661, 662, 664, 667, 669, 671, 674, 674, 682, 684, 692,
        696, 699, 699, 702, 705, 708, 713, 716, 723, 731, 742, 753, 764, 766, 775, 776, 779, 778, 779, 778, 774, 771,
        767, 766, 765, 762, 761, 756, 751, 750, 751, 750, 748, 748, 747, 742, 743, 742, 741, 739, 737, 736, 737, 736,
        735, 735, 732, 732, 731, 730, 729, 728, 727, 726, 726, 724, 725, 723, 723, 722, 721, 720, 721, 719, 719, 718,
        717, 716, 717, 716, 715, 715, 714, 714, 715, 714, 713, 712, 712, 712, 713, 712, 711, 710, 710, 710, 710, 710,
        710, 710, 710, 711, 710, 709, 708, 708, 709, 709, 708, 708, 707, 706, 706, 707, 706, 705, 704, 705, 704, 703,
        702, 703, 702, 701, 700, 701, 700, 698, 698, 697, 696, 697, 696, 695, 695, 693, 689, 684, 679, 673, 667, 667,
        661, 660, 651, 643, 634, 626, 618, 609, 601, 592, 584, 576, 567, 559, 551, 542, 534, 525, 517, 509, 500, 492,
        483, 475, 467, 458, 450, 442, 433, 425, 416, 408, 400, 391, 383, 374, 366, 358, 349, 341, 333, 324, 316, 307,
        299, 291, 282, 274, 265, 257, 249, 240, 232, 224, 215, 207, 198, 190, 182, 173, 165, 157};

    double positionsY[numPositions] = {76, 73, 72, 72, 71, 69, 68, 66, 63, 59, 58, 53, 49, 48, 49, 46, 43, 40, 41, 40,
        39, 39, 35, 34, 35, 33, 33, 32, 30, 29, 29, 28, 27, 26, 27, 26, 25, 24, 25, 24, 23, 22, 23, 22, 21, 20, 20, 21,
        20, 19, 18, 18, 18, 19, 20, 21, 20, 20, 21, 22, 23, 23, 22, 25, 24, 25, 27, 26, 27, 28, 29, 28, 30, 31, 33, 32,
        34, 35, 37, 37, 39, 39, 38, 41, 41, 45, 44, 45, 44, 49, 51, 56, 61, 58, 64, 66, 71, 74, 77, 78, 81, 78, 82, 87,
        88, 91, 91, 97, 104, 104, 112, 116, 116, 120, 120, 124, 124, 128, 128, 131, 132, 132, 135, 135, 136, 136, 139,
        139, 140, 140, 143, 143, 144, 144, 147, 148, 148, 151, 152, 152, 155, 155, 156, 156, 160, 160, 164, 164, 173,
        173, 174, 174, 177, 177, 178, 178, 180, 183, 187, 187, 188, 188, 191, 193, 193, 194, 196, 200, 200, 206, 208,
        209, 211, 212, 213, 214, 219, 220, 223, 229, 234, 239, 244, 246, 253, 256, 261, 261, 275, 276, 285, 295, 300,
        303, 306, 307, 310, 320, 331, 331, 334, 334, 336, 339, 340, 351, 354, 354, 356, 366, 368, 369, 372, 373, 374,
        378, 381, 386, 387, 389, 400, 401, 403, 404, 409, 412, 418, 422, 428, 429, 432, 432, 440, 444, 454, 455, 457,
        458, 471, 473, 474, 476, 475, 484, 494, 495, 496, 497, 508, 519, 530, 531, 533, 534, 547, 561, 575, 589, 602,
        616, 630, 644, 645, 646, 647, 660, 673, 677, 675, 678, 680, 681, 688, 696, 697, 700, 701, 710, 711, 714, 715,
        721, 722, 724, 725, 730, 731, 734, 739, 741, 741, 746, 746, 748, 752, 754, 768, 777, 788, 796, 804, 806, 812,
        812, 799, 787, 775, 762, 750, 738, 726, 713, 701, 689, 677, 664, 652, 640, 628, 615, 603, 591, 578, 566, 554,
        542, 529, 517, 505, 493, 480, 468, 456, 444, 431, 419, 407, 394, 382, 370, 358, 345, 333, 321, 309, 296, 284,
        272, 260, 247, 235, 223, 210, 198, 186, 174, 161, 149, 137, 125, 112, 100, 88, 76};

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
    std::cout << "Minimum speed detected: " << (radar.getMinSpeed()*3600) / 1000 << " km/h\n";
    std::cout << "Maximum speed detected: " << (radar.getMaxSpeed()*3600) / 1000 << " km/h\n";
    std::cout << "Average speed detected: " << (radar.getAverageSpeed()*3600) / 1000 << " km/h\n\n";
}
