#ifndef UI_H
#define UI_H

#include "../../Domain/Cafe/Cafe.h"
#include "../../Domain/Order/Order/Order.h"
#include "../Logger/Logger.h"
#include "../../Domain/Guest/Guest.h"

class UI {
public:
    UI(Cafe* cafe, Logger* logger);
    void run();
    void displayMenu();
    Order takeOrder(Guest& guest); 
    bool payOrder(double total);

private:
    Cafe* cafe;
    Logger* logger;
};

#endif