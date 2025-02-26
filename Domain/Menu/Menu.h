#ifndef MENU_H
#define MENU_H
#include "../../lib/lib.h"
struct MenuItem {
    string name;
    double price;
    string category;
};

class Menu {
public:
    Menu();
    void displayMenu();
    MenuItem getItem(int index);
    int getSize();

private:
    MenuItem items[50];
    int size;
    int displayCategory(const string& categoryName, int itemNumber);
};

#endif