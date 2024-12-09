#include <iostream>
#include <vector>
#include "Booking.h"
#include "Car.h"
#include "Customer.h"

using namespace std;

// Deklarasi vektor mobil
extern vector<Car> Car::cars;

void displayHeader3(const string &title) {
    cout << "=====================================\n";
    cout << "          " << title << "          \n";
    cout << "=====================================\n";
}

// Fungsi untuk melakukan pemesanan mobil
void Booking::bookCar(int bookedCarID, int custID) {
    int price = Booking::calculateCost(bookedCarID, custID);
    int choice;

    cout << "Apakah Anda ingin menyewa mobil " 
         << cars[bookedCarID].get_brand() << " " 
         << cars[bookedCarID].get_model() << " dengan biaya Rp" 
         << price << "?" << endl
         << "1. Ya\n2. Tidak, kembali ke daftar mobil.\n"
         << "Pilihan: ";
    cin >> choice;

    switch (choice) {
        case 1:
            Customer::clearScreen();
            Booking::payCar(bookedCarID, custID, price);
            break;
        case 2:
            Customer::clearScreen();
            Car::displayAllCars(custID);
            break;
        default:
            Customer::clearScreen();
            cout << "Pilihan tidak valid." << endl;
            Booking::bookCar(bookedCarID, custID);
            break;
    }
}

// Fungsi untuk menghitung biaya sewa mobil
int Booking::calculateCost(int bookedCarID, int custID) {
    displayHeader3("PEMESANAN MOBIL");
    int days;
    cout << "Berapa lama Anda ingin menyewa? \nMasukkan jumlah hari: ";
    cin >> days;

    return cars[bookedCarID].get_price() * days;
}

// Fungsi untuk menangani pembayaran
void Booking::payCar(int bookedCarID, int custID, int totalPrice) {

    displayHeader3("PEMBAYARAN");
    int choice;
    string paymentMethod;

    cout << "Anda akan membayar sebesar Rp" << totalPrice << ".\n"
         << "1. Bayar\n2. Kembali ke daftar mobil\n"
         << "Pilihan: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Pilih metode pembayaran:\n"
                 << "1. Dana\n2. BRI\n3. BNI\n4. Mandiri\n5. Gopay\n"
                 << "Pilihan: ";
            cin >> paymentMethod;

            cars[bookedCarID].set_availability();
            Customer::customers[custID].set_isRenting(bookedCarID);
            Customer::saveCustomersToFile();
            Customer::clearScreen();
            cout << "Pembayaran telah berhasil.\n\n";
            
            Booking::printReceipt(bookedCarID, custID, totalPrice);
            
            break;
        case 2:
            Customer::clearScreen();
            Car::displayAllCars(custID);
            break;
        default:
            Customer::clearScreen();
            cout << "Pilihan tidak valid." << endl;
            Booking::payCar(bookedCarID, custID, totalPrice);
            break;
    }
}

void Booking::printReceipt(int bookedCarID, int custID, int totalPrice) {
    displayHeader3("NOTA PEMBAYARAN\n          JOGJA CAR RENTAL");
    cout << "Nama \t: " << Customer::customers[custID].get_name() << endl
         << "Email \t: " << Customer::customers[custID].get_email() << endl
         << endl 
         << "Telah melakukan pembayaran untuk kendaraan sebagai berikut" << endl 
         << "Merk \t: " << Car::cars[bookedCarID].get_brand() << endl
         << "Model \t: " << Car::cars[bookedCarID].get_model() << endl
         << endl
         << "Lunas sebesar Rp" << totalPrice << endl
         << endl
         << "Hormat kami, \nJOGJA CAR RENTAL";

        cout << "\n\nKetik angka apa saja untuk kembali ke menu.\n";
        cout << "Pilihan: ";
            
        int choice2;
        cin >> choice2;
            
        switch (choice2)
        {
        default:
            Customer::clearScreen();
            Customer::customers[custID].customerMenu(custID);
            break;
        }
}
