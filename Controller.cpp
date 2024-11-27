#include <iostream>
#include "Controller.h"

using namespace std;

Controller::Controller(/* args */)
{
}

Controller::~Controller()
{
}

void Controller::gettingStart() {
    int i;
    cout << "Sudah memiliki akun?\n";
    cout << "1. Sudah, lanjutkan ke login\n";
    cout << "2. Belum, saya ingin mendaftar\n";
    cout << "Pilihan: ";
    cin >> i;
    switch (i)
    {
    case 1:
        customerLogin();
        break;
    
    default:
        break;
    }
}
