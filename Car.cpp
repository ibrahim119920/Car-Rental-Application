#include <iostream>
#include <fstream>
#include <sstream>
#include "Car.h"

using namespace std;

// Inisialisasi array dinamis (vector) untuk menyimpan data mobil
vector<Car> Car::cars;

// Default constructor
Car::Car() : carID(""), model(""), brand(""), availability(false), rate(0) {}

// Parameterized constructor
Car::Car(string carID, string model, string brand, bool availability, int rate) 
    : carID(carID), model(model), brand(brand), availability(availability), rate(rate) {}

// Destructor
Car::~Car() {}

// Getter methods
string Car::get_carID() const { return carID; }
string Car::get_model() const { return model; }
string Car::get_brand() const { return brand; }
int Car::get_rate() const { return rate; }
bool Car::get_availability() const { return availability; }

// Fungsi untuk membaca data dari file dan mengisi array dinamis
void Car::loadCarsFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    string carID, model, brand;
    bool availability;
    int rate;

    // Membaca file baris demi baris
    while (inFile >> carID >> model >> brand >> availability >> rate) {
        // Membuat objek Car dan menambahkannya ke vector
        Car car(carID, model, brand, availability, rate);
        cars.push_back(car);
    }

    inFile.close();
    cout << "Data loaded successfully from " << filename << endl;
}

// Fungsi untuk mendapatkan semua mobil dari array dinamis
const vector<Car>& Car::getAllCars() {
    return cars;
}
