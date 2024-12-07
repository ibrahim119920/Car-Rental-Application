#include <iostream>
#include <string>
#include "Car.h"
#include "Customer.h"
#include "Booking.h"

using namespace std;

int main() {
    Customer :: loadCustomersFromFile();
    Car::loadCarsFromFile("carList.txt");
    Customer::landingPage();
    return 0;
}