#ifndef ORDER_H
#define ORDER_H

#include "../../Domain/Menu/Menu.h"
#include "../../Domain/Guest/Guest.h"
#include "../../Domain/Clock/Clock.h"

class Order {
public:
    Order(const Guest& guest);
    void addItem(const MenuItem& item);
    MenuItem* getItems();
    int getSize() const;
    Order(Order&& other) noexcept;
    Order& operator=(Order&& other) noexcept;
    void saveToFile(int orderNumber, const Clock& clock) const; // Додано saveToFile
    double calculateTotal() const; // Додано calculateTotal

private:
    Guest guest;
    MenuItem items[100];
    int size;
};

#endif