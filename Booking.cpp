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
        Booking :: payCar(bookedCarID, custID , price);
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
    string pay, doit;
    cout << "Anda akan membayar sebesar Rp" << totalPrice << ".\n";
    cout << "1. Bayar\n" << "2. Kembali ke daftar mobil\n";
    cout << "Pilihan : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout<<"Pilih metode pembayaran : "<<endl;
    cout<<"1. Dana\n2. BRI\n3. BNI\n4. Mandiri\n5. Gopay"<<endl;
    cout<<"Pilihan : ";
    cin>>doit;

    cout<<"Pembayaran Telah Berhasil"<<endl;

        // pay = "Lakukan proses pembayaran";
        cars[bookedCarID-1].set_availability();
        Customer :: customers[custID-1].set_isRenting(bookedCarID);
        Customer :: saveCustomersToFile();
        Customer :: customers[custID].customerMenu(custID);
        
        break;

    case 2:
        Car::displayAllCars(custID);      
        break;
        
    default:
        cout << "Pilihan tidak valid";
        Booking::payCar(bookedCarID, custID, totalPrice);
        break;
    }

    
   

    


}