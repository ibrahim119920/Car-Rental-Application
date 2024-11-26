#pragma once
#define CAR_H 

#include <string>
#include ""

using namespace std;

class Car: public
{
private:
    static vector<Car> cars;
    string carID;
    string model;
    string brand;
    bool availability;
    int rate;
public:
    Car(/* args */);
    ~Car();
    void bookCar();
};

