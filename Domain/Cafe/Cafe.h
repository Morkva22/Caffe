
#ifndef CAFE_H
#define CAFE_H

#include "../../Domain/Order/Order/Order.h"
#include "../../Domain/Menu/Menu.h"
#include "../../Data/Data.h"

class Cafe {
public:
    Cafe(Menu* menu, Data* data);
    void takeOrder(Order& order);
    Menu* getMenu();
    double calculateTotal(Order& order);
    
    void displayMenu();
    MenuItem getItem(int index);
    void completeOrder(const Order& order);

private:
    Menu* menu;
    Data* data;
};

#endif