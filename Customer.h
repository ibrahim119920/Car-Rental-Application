#pragma once

#include <string>
#include <vector>

using namespace std;

class Customer
{
private:
    int customerID;
    string name;
    string email;
    string customerPassword;

public:
    Customer(string name1, string email1, string customerPassword1, int customerID1);
    Customer();

    static vector<Customer> customers; // Array dinamis untuk menyimpan pelanggan

    string get_name() const;
    string get_email() const;
    string get_customerPassword() const;
    int get_customerID() const;

    static void loadCustomersFromFile();
    static void saveCustomersToFile();
    static void landingPage();
    static int checkDatabase(string name, string password);
    static void customerRegister();
    static void customerLogin();
    void customerMenu(int idCust);
    static void returnCar();
};
