#include "Customer.h"
#include "Car.h"
#include "Booking.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

// Default constructor
Car::Car() : carID(0), model(""), brand(""), availability(false), price(0) {}

// Parameterized constructor
Car::Car(int carID, string model, string brand, bool availability, int rate)
    : carID(carID), model(model), brand(brand), availability(availability), price(rate) {}

// Destructor
Car::~Car() {}

// Getter methods
int Car::get_carID() const { return carID; }
string Car::get_model() const { return model; }
string Car::get_brand() const { return brand; }
int Car::get_price() const { return price; }
bool Car::get_availability() const { return availability; }

// Setter method
void Car::set_availability() {
    if (availability == 0)
    {
        availability = 1;
    
    }
    else availability = 0;
    Car::saveCarsToFile();
    
};

void Car::saveCarsToFile() {
    ofstream file("carList.txt"); // Membuka file untuk menulis
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << endl;
        return;
    }

    for (const auto& cars : cars) {
        file << cars.carID << " " 
             << cars.model << " " 
             << cars.brand << " " 
             << cars.availability << " " 
             << cars.price << endl; // Pastikan konsisten dengan properti `rate`
    }

    file.close(); // Menutup file
}



// Load cars from file
void Car::loadCarsFromFile(const string& filename) {
    ifstream file(filename); // Membuka file
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line); // Membaca setiap baris file
        int carID, price;
        string model, brand;
        bool availability;

        // Parsing data dari baris
        ss >> carID >> model >> brand >> availability >> price;

        // Menambahkan data ke vector cars
        cars.push_back(Car(carID, model, brand, availability, price));
    }

    file.close(); // Menutup file
}

// Get all cars
const vector<Car>& Car::getAllCars() {
    return cars;
}

// Display a single car's attributes
void Car::displayCar() const {
    cout << left << setw(10) << carID
         << setw(15) << model
         << setw(15) << brand
         << setw(15) << (availability ? "Available" : "Not Available")
         << "Rp " << price << endl;
}

// Display all cars
void Car::displayAllCars(int custID) {
    cout << "List of Cars:" << endl;
    cout << left << setw(10) << "CarID"
         << setw(15) << "Model"
         << setw(15) << "Brand"
         << setw(15) << "Availability"
         << "Rate" << endl;
    cout << string(70, '-') << endl;

    for (const auto& car : cars) {
        car.displayCar();
    }

    cout << "Pilih ID mobil yang ingin disewa, atau ketik 0 untuk kembali: ";
    int bookedCarID;
    cin >> bookedCarID;

    if (bookedCarID <= 0) {
        Customer::customers[custID].customerMenu(custID);
    } else {
    
        Booking::bookCar(bookedCarID, custID);
    }
}
