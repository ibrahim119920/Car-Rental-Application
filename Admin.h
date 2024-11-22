#pragma once
#define ADMIN_H 

#include <string>
// #include "Car.h"
using namespace std;

class Admin
{
private:
    int admin;
    // string adminID;
    // string username;       
    // string password;
public:
    Admin(int i);
    void adminMenu();
    void adminLogin(const string& username, const string& password);
    // void updateAvailableCars(const Car& car);
    // bool verifyCarReturn(const string& bookingID);
    // bool confirmPayment(const string& bookingID);
};
