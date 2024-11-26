#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
#include <conio.h>
#include "Customer.h"

using namespace std;

// Inisialisasi vector pelanggan
vector<Customer> Customer::customers;

Customer::Customer(string name1, string email1, string customerPassword1, string customerID1) 
    : name(name1), email(email1), customerPassword(customerPassword1), customerID(customerID1) {}
string Customer :: get_name(string name){
    return name ;
};
string Customer :: get_email(string email){
    return email ;
};
string Customer :: get_customerPassword(string password){
    return password ;
};
string Customer :: get_customerID(string CustomerID){
    return customerID;
};


void Customer::customerRegister() {
    string name, email, password, customerID;

    cout << "Masukkan nama: ";
    cin >> name;
    cout << "Masukkan email: ";
    cin >> email;
    cout << "Masukkan password: ";
    cin >> password;
    cout << "Masukkan ID pelanggan: ";
    cin >> customerID;

    // Buat objek Customer baru dan tambahkan ke vector
    Customer newCustomer(name, email, password, customerID);
    customers.push_back(newCustomer);

    ofstream newFile("customerDatabase.txt", ofstream::app);
    newFile << name << " "
            << email << " " 
            << password << " "
            << customerID << endl;

    cout << "Pelanggan berhasil didaftarkan!\n";
}

int Customer::checkDatabase(string name, string password) {
    ifstream inFile("customerDatabase.txt");
    if (!inFile) {
        cerr << "Error: Unable to open file!" << endl;
        return 0; // Mengembalikan 0 jika file tidak dapat dibuka
    }

    string name1, email1, password1, customerID1;
    while (inFile >> name1 >> email1 >> password1 >> customerID1) {
        if (name == name1 && password == password1) {
            inFile.close();
            return 1; // Berhasil menemukan nama dan kata sandi yang cocok
        }
    }

    inFile.close();
    return 0; // Nama dan kata sandi tidak ditemukan
}

// string Customer::get_email();
// string Customer::get_customerPassword();
// string Customer::get_customerID();

void Customer::customerLogin() {
    string nama2;
    string password2;

    do
    {
        cout << "Nama : ";
        cin >> nama2;
        cout << "Password : ";
        cin >> password2;

    } while (Customer::checkDatabase(nama2, password2) == 0);
    
    cout << "Berhasil login";

};



void Customer::viewAvailableCars() {
    ifstream inFile("carList.txt");
    if (!inFile) {
        cerr << "Error: Unable to open file!" << endl;
         // Menghentikan fungsi jika file tidak dapat dibuka
    }

    string carID1, model1, brand1;
    bool status;
    double rate1;

    cout << "======================================" << endl;
    cout << "    Available Cars Information        " << endl;
    cout << "======================================" << endl;
    cout << "CarID\tModel\tBrand\tRate\tStatus" << endl;
    cout << "--------------------------------------" << endl;

    while (inFile >> carID1 >> model1 >> brand1 >> status >> rate1) {
        // Tampilkan hanya jika status adalah true (1)
        if (status) {
            cout << carID1 << "\t" << model1 << "\t" << brand1 << "\t" 
                 << rate1 << "\t" << (status ? "Ready" : "Not Ready") << endl;
        }
    }

    inFile.close();
    cout << "======================================" << endl;
}




// void Customer::displayCustomers() {
//     cout << "\nDaftar Pelanggan Terdaftar:\n";
//     if (customers.empty()) {
//         cout << "Belum ada pelanggan yang terdaftar.\n";
//         return;
//     }

//     for (const auto &customer : customers) {
//         cout << "Nama: " << customer.name
//              << ", Email: " << customer.email
//              << ", ID: " << customer.customerID << "\n";
//     }
// }

int main() {
    // Customer::customerLogin();
    // Customer::customerRegister();
    // Customer::displayCustomers();
    Customer ::viewAvailableCars();
    return 0;
}