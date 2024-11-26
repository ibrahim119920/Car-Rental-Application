#pragma once
#define BOOKING_H 

#include <string>
#include "Car.h"
#include "Customer.h"

class Booking: public Customer, public Car
{
private:
    string bookingID;
    
public:
    Booking(/* args */);
    ~Booking();
};

Booking::Booking(/* args */)
{
}

Booking::~Booking()
{
}
