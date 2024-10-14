//
// Created by mateu on 14.10.2024.
//

#ifndef VEHICLE_H
#define VEHICLE_H



class vehicle {
private:
    int speed;
    int positionX;
    int positionY;
public:
    explicit vehicle(int speed, int positionX, int positionY);

    ~vehicle();

    int get_speed();

    int get_positionX();
    int get_positionY();
};



#endif //VEHICLE_H
