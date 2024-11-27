#pragma once
#include <string>
#include <vector>

using namespace std;

class Car {
private:
    static vector<Car> cars; // Array dinamis untuk menyimpan objek Car
    string carID;            // ID mobil
    string model;            // Model mobil
    string brand;            // Merek mobil
    bool availability;       // Ketersediaan mobil
    int rate;                // Tarif sewa per hari

public:
    // Default constructor
    Car();

    // Parameterized constructor
    Car(string carID, string model, string brand, bool availability, int rate);

    // Destructor
    ~Car();

    // Getter methods
    string get_carID() const;
    string get_model() const;
    string get_brand() const;
    int get_rate() const;
    bool get_availability() const;

    // Static methods
    static void loadCarsFromFile(const string& filename); // Membaca data dari file ke dalam array dinamis
    static const vector<Car>& getAllCars();              // Mendapatkan semua mobil dalam array dinamis
    static void displayAllCars();                        // Menampilkan semua mobil ke terminal

    // Non-static method
    void displayCar() const;                             // Menampilkan atribut mobil ini
};
