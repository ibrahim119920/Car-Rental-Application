#pragma once

#include <string>
#include <vector>

using namespace std;

class Customer
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
    string get_name();
    string get_email();
    string get_customerPassword();
    string get_customerID();
    static void customerRegister();
    // static void displayCustomers(); // Tambahkan metode untuk menampilkan daftar pelanggan
    static void customerLogin();
    void viewAvailableCars();
    int bookCar();
    int extendRent();
    void returnCar();
};
