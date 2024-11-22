#include <iostream>
#include <string>
#include "Admin.h"

using namespace std;

int main() {
    string username = "admin";
    string password = "admin";
    Admin tes(1);
    tes.login(username, password);

    return 0;
}