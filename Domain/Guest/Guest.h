#ifndef GUEST_H
#define GUEST_H

#include "../../lib/lib.h"

class Guest {
public:
    void registerGuest();
    string getName() const; 
    string getSurname() const; 

private:
    string name;
    string surname;
};

#endif