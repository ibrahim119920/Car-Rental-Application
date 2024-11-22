#pragma once
#define CUSTOMER_H 

#include <string>

using namespace std;

class Customer
{
private:
    int customer;
    string customerID;
    string name;
    string email;
    string customerPassword;
public:
    Customer(int j);
    void customerRegister();
    void customerLogin();
    void viewAvailableCars();
    int bookCar();
    int extendRent();
    void returnCar();
};