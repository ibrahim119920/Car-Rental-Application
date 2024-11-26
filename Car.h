#pragma once
#define CAR_H 

#include <string>

using namespace std;

class Car
{
private:
    string carID;
    string model;
    string brand;
    bool availability;
    int rate;
public:
    Car(/* args */);
    ~Car();
    void updateAvailability();
};

