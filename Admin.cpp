#include <iostream>
#include <string>
#include "Admin.h"
// #include "Car.h"

using namespace std;

// Admin::Admin() : admin(0) {}
Admin::Admin(int n): admin(n) {}

void Admin::adminMenu() {
    int choice;
    cout << "\n\nSelamat datang, Admin. Pilih menu yang diinginkan: \n";
    cout << "1. Perbarui stok mobil\n";
    cout << "2. Konfirmasi pembayaran\n";
    cout << "3. Konfirmasi pengembalian mobil\n";
    cout << "3. Logout";
    cin >> choice;
};

void Admin::adminLogin(const string& username, const string& password) {
    string usernameInput;
    string passwordInput;

    cout << "Masukkan Username : ";
    cin >> usernameInput;
    cout << "Masukkan Password : ";
    cin >> passwordInput;

    while (username != usernameInput || password != passwordInput)
    {
        cout << "\nUsername atau password salah, silakan coba lagi\n";
        cout << "Masukkan Username : ";
        cin >> usernameInput;
        cout << "Masukkan Password : ";
        cin >> passwordInput;
    }
    cout << "berhasil";
    adminMenu();

};


// void updateAvailableCars(Car& car);
// bool verifyCarReturn(string& bookingID);
// bool confirmPayment(string& bookingID);

