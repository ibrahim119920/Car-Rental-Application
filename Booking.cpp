#include <iostream>
#include "Booking.h"
#include "Car.h"
#include "Customer.h"

using namespace std;

extern vector<Car> Car::cars;

void Booking::bookCar(int bookedCarID, int custID) {
    int price, choice;
    price = Booking::calculateCost(bookedCarID, custID);
    
    cout << "Apakah anda ingin menyewa mobil " 
        << cars[bookedCarID - 1].get_brand() << " " 
        << cars[bookedCarID - 1].get_model() << "\n dengan biaya Rp"
        << price << "?" << endl
        << "1. Ya, 2. Tidak, kembali ke daftar mobil.\n";
    cout << "Pilihan : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        // payCar(bookedCarID, custID, price);
        break;

    case 2:
        Car::displayAllCars(custID);
        break;
        
    default:
        cout << "Pilihan tidak valid";
        Booking::bookCar(bookedCarID, custID);
        break;
    }


}

int Booking::calculateCost(int bookedCarID, int custID) {
    int days, price, choice;
    
    cout << "Berapa lama anda ingin menyewa? Masukkan jumlah hari : ";
    cin >> days;
    
    price = cars[bookedCarID - 1].get_price() * days;

    return price;
}

void Booking::payCar(int bookedCarID, int custID, int totalPrice) {
    int choice;
    cout << "Anda akan membayar sebesar Rp" << totalPrice << ".";
    cout << "1. Bayar, 2. Kembali ke daftar mobil\n";
    cout << "Pilihan : ";
    cin >> choice;
}