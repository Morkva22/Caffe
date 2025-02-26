#include "Guest.h"

void Guest::registerGuest() {
    cout << "|<<<| Enter your name: ";
    cin >> name;
}

string Guest::getName() const { 
    return name;
}