#include "Customer.h"
#include "Car.h"
#include "Booking.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

// Inisialisasi vector statis
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
        string carID, model, brand;
        bool availability;
        int rate;

        // Parsing data dari baris
        ss >> carID >> model >> brand >> availability >> rate;

        // Menambahkan data ke vector cars
        cars.push_back(Car(carID, model, brand, availability, rate));
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
         << "Rp " << rate << endl;
}

// Display all cars
void Car::displayAllCars() {
    Car::loadCarsFromFile("carList.txt");
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
    cout << "Pilih ID mobil yang ingin disewa, atau ketik 0 untuk kembali:  ";
    int i;
    cin >> i;
    
    if (i <= 0)
    {
        Customer::customerMenu();
    }
    else if (i > 5)
    {
        cout << "Nomor tidak valid!";
    }
    else
    {
        int ii = stoi(cars[i].get_carID());
        // bookCar();
    }
    
    

    

}
