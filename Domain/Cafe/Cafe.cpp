#include "Cafe.h"

Cafe::Cafe(Menu* menu, Data* data) : menu(menu), data(data) {}

void Cafe::takeOrder(Order& order) {
    cout << endl;
    cout << "Order accepted. Thank you!\n";
}

Menu* Cafe::getMenu() {
    return menu;
}

double Cafe::calculateTotal(Order& order) {
    double total = 0;
    MenuItem* items = order.getItems();
    for (int i = 0; i < order.getSize(); i++) {
        total += items[i].price;
    }
    return total;
}


void Cafe::displayMenu() {
    menu->displayMenu(); 
}

MenuItem Cafe::getItem(int index) {
    return menu->getItem(index); 
}

void Cafe::completeOrder(const Order& order) {
    cout << "|<<<| Order completed successfully!" << endl;
}