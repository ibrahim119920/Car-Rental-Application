#include <iostream>
#include "Booking.h"
#include "Car.h"
#include "Customer.h"

using namespace std;

extern vector<Car> Car::cars;

void Booking::bookCar(int bookedCarID, int custID) {
    int choice;
    cout << "Apakah anda ingin menyewa mobil " 
        << cars[bookedCarID].get_brand() << " " 
        << cars[bookedCarID].get_model() << "?\n"
        << "1. Ya, 2. Tidak, kembali ke daftar mobil.\n";
    cout << "Pilihan : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        Booking::calculateCost(bookedCarID, custID);
        

    case 2:
        Car::displayAllCars(custID);
        break;
        
    default:
        cout << "Pilihan tidak valid";
        Booking::bookCar(bookedCarID, custID);
        break;
    }


}

void Booking::calculateCost(int bookedCarID, int custID) {
    int days, price, choice;
    
    cout << "Berapa lama anda ingin menyewa? Masukkan jumlah hari : ";
    cin >> days;
    
    price = cars[bookedCarID].get_price() * days;

    cout << "Anda akan membayar sebesar " << price;
        cout << "1. Bayar\n" << "2. Kembali ke daftar mobil\n";
        cout << "Pilihan : ";
        cin >> choice;

    switch (choice)
    {
    case 1:
        /* code */
        break;

    case 2:
        Car::displayAllCars(custID);
        break;
    
    default:
        break;
    }
}

// void Booking::payCar() {

// }