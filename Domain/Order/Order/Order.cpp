#include "Order.h"
#include "../../Data/Data.h"
#include "../../Clock/Clock.h"

Order::Order(const Guest& guest) : guest(guest), size(0) {}

void Order::addItem(const MenuItem& item) {
    items[size++] = item;
}

MenuItem* Order::getItems() {
    return items;
}

int Order::getSize() const {
    return size;
}

Order::Order(Order&& other) noexcept : guest(other.guest), size(other.size) {
    for (int i = 0; i < size; ++i) {
        items[i] = other.items[i];
    }
    other.size = 0;
}

Order& Order::operator=(Order&& other) noexcept {
    if (this != &other) {
        size = other.size;
        for (int i = 0; i < size; ++i) {
            items[i] = other.items[i];
        }
        other.size = 0;
    }
    return *this;
}

void Order::saveToFile(int orderNumber, const Clock& clock) const {
    Data data;
    std::stringstream ss;
    
    ss << "Ім'я - " << guest.getName() << ".\n";
    ss << "Замовлення:\n";

    for (int i = 0; i < size; ++i) {
        ss << "- " << items[i].name << " (" << items[i].price << "$)\n";
    }

    ss << "Замовлення було зроблено о " << clock.getCurrentTime() <<endl;
    ss << "Сума замовлення - " << calculateTotal() << "$.\n\n";

    data.saveData(ss.str());
}

double Order::calculateTotal() const {
    double total = 0;
    for (int i = 0; i < size; ++i) {
        total += items[i].price;
    }
    return total;
}