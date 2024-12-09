#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>
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

string Customer::get_name() const { return name; }
string Customer::get_email() const { return email; }
string Customer::get_customerPassword() const { return customerPassword; }
int Customer::get_customerID() const { return customerID; }
int Customer::get_isRenting() const { return isRenting; }
void Customer::set_isRenting(int renting) { isRenting = renting; }

void Customer::clearScreen() {
    cout << "\033[2J\033[H"; // ANSI escape code untuk membersihkan layar
    cout.flush();
}

void displayHeader(const string &title) {
    cout << "=====================================\n";
    cout << "          " << title << "          \n";
    cout << "=====================================\n";
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

void Customer::returnCar(int custID) {
    int bookedCarID = customers[custID].get_isRenting();
    int choice;

    if (bookedCarID == -1) {
        Customer::clearScreen();
        cout << "Anda tidak sedang menyewa mobil!\n";
        customers[custID].customerMenu(custID);
        return;
    }

    displayHeader("PENGEMBALIAN MOBIL");

    cout << "Apakah anda ingin mengembalikan mobil "
         << Car::cars[bookedCarID].get_brand() << " "
         << Car::cars[bookedCarID].get_model() << "?\n";
    cout << "Ketik 1 jika Iya\nKetik 0 untuk kembali ke Menu.\n";
    cout << "Pilihan: ";
    cin >> choice;

    if (choice == 1) {
        Car::cars[bookedCarID].set_availability();
        customers[custID].set_isRenting(-1);
        Car::cars[custID].saveCarsToFile();
        saveCustomersToFile();
        Customer::clearScreen();
        cout << "Mobil berhasil dikembalikan.\n";
        customers[custID].customerMenu(custID);
    } else if (choice == 0) {
        customers[custID].customerMenu(custID);
    } else {
        cout << "Pilihan tidak valid!\n";
        returnCar(custID);
    }
}

void Customer::extendCar(int custID) {
    int bookedCarID = customers[custID].get_isRenting();
    if (bookedCarID == -1) {
        clearScreen();
        cout << "Anda belum menyewa mobil.\n";

        customers[custID].customerMenu(custID);
        return;
    }

    displayHeader("PERPANJANG MASA PINJAM");

    int choice, days, price, pembayaran;
    cout << "Apakah anda ingin memperpanjang sewa "
         << Car::cars[bookedCarID].get_brand() << " "
         << Car::cars[bookedCarID].get_model() << "?\n";
    cout << "Ketik 1 untuk lanjut dan 0 untuk kembali\n";
    cout << "Pilihan: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Berapa lama anda ingin memperpanjang sewa? \nMasukkan jumlah hari: ";
        cin >> days;

        price = Car::cars[bookedCarID].get_price() * days;
        Customer::clearScreen();
        displayHeader("PEMBAYARAN");
        cout << "Anda akan membayar sebesar Rp" << price << ".\n";
        cout << "1. Bayar\n2. Kembali ke daftar mobil\n";
        cout << "Pilihan: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Pilih metode pembayaran:\n";
            cout << "1. Dana\n2. BRI\n3. BNI\n4. Mandiri\n5. Gopay\n";
            cout << "Pilihan: ";
            cin >> pembayaran;
            Customer::clearScreen();
            cout << "Pembayaran berhasil!\n";
            Booking::printReceipt(bookedCarID, custID, price);
        }
    }
    Customer::clearScreen();
    customers[custID].customerMenu(custID);
}

void Customer::logOut() {
    landingPage();
}

void Customer::customerMenu(int custID) {

    displayHeader("RENTAL JOGJA");

    int choice;
    cout << "Selamat datang, " << customers[custID].get_name() << ". ";
    cout << "Pilih menu yang ingin diakses:\n";
    cout << "1. Lihat mobil yang tersedia\n";
    cout << "2. Kembalikan mobil\n";
    cout << "3. Perpanjang mobil\n";
    cout << "4. Log Out\n";
    cout << "Pilihan: ";
    cin >> choice;

    switch (choice) {
        case 1:
            clearScreen();
            Car::displayAllCars(custID);
            break;
        case 2:
            clearScreen();
            returnCar(custID);
            break;
        case 3:
            clearScreen();
            extendCar(custID);
            break;
        case 4:
            clearScreen();
            logOut();
            break;
        default:
            cout << "Pilihan tidak valid!\n";
            customerMenu(custID);
            break;
    }
}

void Customer::customerLogin() {
    string name, password;
    int customerID = -1;

    displayHeader("LOGIN CUSTOMER");

    do {
        cout << "Nama: ";
        cin >> name;
        cout << "Password: ";
        cin >> password;

        customerID = checkDatabase(name, password);
        if (customerID == 0) {
            cout << "Nama atau password salah!\n";
        }
    } while (customerID == 0);

    clearScreen();
    cout << "Berhasil login\n";
    customers[customerID - 1].customerMenu(customerID - 1);
}

void Customer::loadCustomersFromFile() {
    ifstream inFile("customerDatabase.txt");
    if (!inFile) {
        cerr << "Error: Unable to open file!" << endl;
        return;
    }

    string name, email, password;
    int customerID, isRenting;
    while (inFile >> name >> email >> password >> customerID >> isRenting) {
        customers.emplace_back(name, email, password, customerID, isRenting);
    }

    inFile.close();
}

void Customer::customerRegister() {
    string name, email, password;
    int customerID = customers.size() + 1;

    displayHeader("PENDAFTARAN CUSTOMER");

    cout << "Masukkan nama: ";
    cin >> name;
    cout << "Masukkan email: ";
    cin >> email;
    cout << "Masukkan password: ";
    cin >> password;

    customers.emplace_back(name, email, password, customerID, -1);
    ofstream newFile("customerDatabase.txt", ofstream::app);
    newFile << name << " " << email << " " << password << " " << customerID << " " << -1 << endl;

    clearScreen();
    cout << "Pelanggan berhasil didaftarkan!\n";
    landingPage();
}

void Customer::saveCustomersToFile() {
    ofstream outFile("customerDatabase.txt");
    if (!outFile) {
        cerr << "Error: Unable to open file for writing!" << endl;
        return;
    }

    for (const auto &c : customers) {
        outFile << c.name << " " << c.email << " " << c.customerPassword << " "
                << c.customerID << " " << c.isRenting << endl;
    }

    outFile.close();
}

void Customer::landingPage() {
    int choice;
    displayHeader("RENTAL JOGJA APP");
    cout << "Selamat datang di Rental Jogja!\n";
    cout << "1. Login ke akun yang sudah ada\n";
    cout << "2. Buat akun baru\n";
    cout << "Pilihan: ";
    cin >> choice;

    switch (choice) {
        case 1:
            clearScreen();
            customerLogin();
            break;
        case 2:
            clearScreen();
            customerRegister();
            break;
        default:
            clearScreen();
            cout << "Pilihan tidak valid!\n";
            landingPage();
            break;
    }
}
