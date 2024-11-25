#include <iostream>
#include <string>
#include "Customer.h"
// #include "Car.h"

using namespace std;
 // Alokasi dinamis untuk 10 Customer





Customer::Customer(): customer() {}

void Customer::customerRegister(const string &username , const string &password) {
    string username1 ;
    string password1 ;    
    
    cout << "Masukkan UserName njenengan : " ;
    cin >> username1 ;

    
};

void Customer  :: set_name(string username1){
    Customer customer[1];
    
    this->name = username1; // Mengubah atribut 'name' dari objek saat ini


};


void addCustomer(){
    Customer* customers = new Customer[];
}