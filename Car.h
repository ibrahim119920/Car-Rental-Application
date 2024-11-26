#pragma once
#define CAR_H

#include <string>
#include <vector>

using namespace std;

class Car {
private:
    static vector<Car> cars; // Array dinamis untuk menyimpan objek Car
    string carID;
    string model;
    string brand;
    bool availability;
    int rate;

public:
    Car(); // Default constructor
    Car(string carID, string model, string brand, bool availability, int rate); // Constructor parameterized
    ~Car();

    // Fungsi untuk mendapatkan data dari array dinamis
    string get_carID() const;
    string get_model() const;
    string get_brand() const;
    int get_rate() const;
    bool get_availability() const;

    // Fungsi statis untuk membaca data dari file ke dalam array dinamis
    static void loadCarsFromFile(const string& filename);

    // Fungsi statis untuk mendapatkan semua mobil yang dimuat ke dalam array dinamis
    static const vector<Car>& getAllCars();
};
