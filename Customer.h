#pragma once

#include <string>
#include <vector>
#include "Controller.h"

using namespace std;

class Customer: public Controller
{
private:
    static vector<Customer> customers; // Array dinamis untuk menyimpan pelanggan
    string customerID;
    string name;
    string email;
    string customerPassword;

public:
    Customer(string name1, string email1, string customerPassword1, string customerID1);
    Customer();
    static int checkDatabase(string name, string password); // Update in the header file
    string get_name(string name);
    string get_email(string email);
    string get_customerPassword(string password);
    string get_customerID(string customerID);
    static void customerRegister();
    // static void displayCustomers(); // Tambahkan metode untuk menampilkan daftar pelanggan
    static void customerLogin();
    static void customerMenu();
    static void viewAvailableCars();
    static int bookCar();
    static int extendRent();
    static void returnCar();
};
