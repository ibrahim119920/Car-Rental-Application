#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <conio.h>
#include "Customer.h"
#include "Car.h"
#include "Booking.h"

using namespace std;

// Inisialisasi vector pelanggan
vector<Customer> Customer::customers;

Customer::Customer() {}

Customer::Customer(string name1, string email1, string customerPassword1, int customerID1, int isRenting1)
    : name(name1), email(email1), customerPassword(customerPassword1), customerID(customerID1), isRenting(isRenting1) {}

string Customer::get_name() const {
    return name;
}

string Customer::get_email() const {
    return email;
}

string Customer::get_customerPassword() const {
    return customerPassword;
}

int Customer::get_customerID() const {
    return customerID;
}

int Customer::get_isRenting() const {
    return isRenting;
}

void Customer::set_isRenting(int renting) {
    isRenting = renting;

    


}

int Customer::checkDatabase(string name, string password) {
    ifstream inFile("customerDatabase.txt");
    if (!inFile) {
        cerr << "Error: Unable to open file!" << endl;
        return 0;
    }

    string name1, email1, password1;
    int customerID1, isRenting1;
    while (inFile >> name1 >> email1 >> password1 >> customerID1 >> isRenting1) {
        if (name == name1 && password == password1) {
            inFile.close();
            return customerID1;
        }
    }

    inFile.close();
    return 0;
}

void Customer::returnCar(int bookedcarID, string custID) {
    
     // Temukan indeks pelanggan berdasarkan logika Anda
    // if (customers[custID].get_isRenting() == 0) {
    //     cout << "Anda tidak sedang menyewa mobil!\n";
    //     return;
    // }
    
     cout << "Apakah anda ingin mengembalikan mobil?" << Car :: cars[bookedcarID-1].get_brand()  << " " << Car ::cars[bookedcarID-1].get_model()  ;

    Car ::cars[bookedcarID-1].set_availability();


    // Logika pengembalian mobil
    // customers[custID].set_isRenting(0);
    // cout << "Mobil berhasil dikembalikan!\n";
    // saveCustomersToFile(); // Perbarui file

}

void Customer::customerMenu(int custID) {
    int choice;
    cout << "Pilih menu yang ingin diakses: \n";
    cout << "1. Lihat mobil yang tersedia.\n";
    cout << "2. Kembalikan mobil\n";
    cout << "3. Perpanjang mobil.\n";
    cout << "Pilihan: ";
    cin >> choice;
    switch (choice) {
    case 1:
        Car::displayAllCars(custID);
        break;
    case 2:
        // Customer::returnCar( ,  custID);
        break;
    case 3:
        // Logika perpanjangan penyewaan
        break;
    default:
        break;
    }
}

void Customer::customerLogin() {
    string nama2;
    string password2;

    do {
        cout << "Nama : ";
        cin >> nama2;
        cout << "Password : ";
        cin >> password2;

    } while (Customer::checkDatabase(nama2, password2) == 0);

    cout << "Berhasil login\n";
    int n = checkDatabase(nama2, password2);
    customers[n].customerMenu(n);
}

void Customer::loadCustomersFromFile() {
    ifstream inFile("customerDatabase.txt");
    if (!inFile) {
        cerr << "Error: Unable to open file!" << endl;
        return;
    }

    string name1, email1, password1;
    int customerID1, isRenting1;
    while (inFile >> name1 >> email1 >> password1 >> customerID1 >> isRenting1) {
        Customer newCustomer(name1, email1, password1, customerID1, isRenting1);
        customers.push_back(newCustomer);
    }

    inFile.close();
    cout << "Data pelanggan berhasil dimuat dari file.\n";
}

void Customer::customerRegister() {
    string name, email, password;
    int customerID;

    cout << "Masukkan nama: ";
    cin >> name;
    cout << "Masukkan email: ";
    cin >> email;
    cout << "Masukkan password: ";
    cin >> password;
    cout << "Masukkan ID pelanggan (angka): ";
    cin >> customerID;

    Customer newCustomer(name, email, password, customerID, 0); // Default isRenting = 0
    customers.push_back(newCustomer);

    ofstream newFile("customerDatabase.txt", ofstream::app);
    newFile << name << " "
            << email << " "
            << password << " "
            << customerID << " "
            << 0 << endl;

    cout << "Pelanggan berhasil didaftarkan!\n";
}

void Customer::saveCustomersToFile() {
    ofstream outFile("customerDatabase.txt");
    if (!outFile) {
        cerr << "Error: Unable to open file for writing!" << endl;
        return;
    }

    for (const Customer &c : customers) {
        outFile << c.name << " "
                << c.email << " "
                << c.customerPassword << " "
                << c.customerID << " "
                << c.isRenting << endl;
    }

    outFile.close();
    cout << "Data pelanggan berhasil disimpan ke file.\n";
}

void Customer::landingPage() {
    loadCustomersFromFile();
    Car::loadCarsFromFile("carList.txt");

    cout << customers[2].get_name();

    int i;
    cout << "Selamat datang di Rental Jogja!\n";
    cout << "1. Login ke akun yang sudah ada\n";
    cout << "2. Buat akun baru\n";
    cin >> i;
    switch (i) {
    case 1:
        Customer::customerLogin();
        break;
    case 2:
        Customer::customerRegister();
        break;
    default:
        break;
    }
}

 static void returnCar(int bookedcarID, string custID){
    
    
 };
