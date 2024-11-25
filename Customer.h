#pragma once


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
    void customerRegister(const string &username , const string &password);
    void customerLogin();
    void viewAvailableCars();
    int bookCar();
    int extendRent();
    void returnCar();
};