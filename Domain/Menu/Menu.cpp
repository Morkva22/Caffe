#include "Menu.h"   
Menu::Menu() : size(50) {

    items[35] = {"Coffee", 5.0, "Drinks"};
    items[36] = {"Tea", 4.0, "Drinks"};
    items[37] = {"Juice", 6.0, "Drinks"};
    items[38] = {"Water", 1.0, "Drinks"};
    items[39] = {"Lemonade", 10.0, "Drinks"};

    items[30] = {"Cake", 12.0, "Desserts"};
    items[31] = {"Ice cream", 8.0, "Desserts"};
    items[32] = {"Pancake", 12.0, "Desserts"};
    items[33] = {"Brownie", 20.0, "Desserts"};
    items[34] = {"Muffin", 18.0, "Desserts"};

    items[0] = {"Soup", 25.0, "First Dishes"};
    items[1] = {"Borsch", 30.0, "First Dishes"};
    items[2] = {"Mushroom soup", 28.0, "First Dishes"};
    items[3] = {"Chicken broth", 25.0, "First Dishes"};
    items[4] = {"Vegetable soup", 30.0, "First Dishes"};

    items[5] = {"Pasta", 20.0, "Second Dishes"};
    items[6] = {"Steak", 70.0, "Second Dishes"};
    items[7] = {"Fish", 60.0, "Second Dishes"};
    items[8] = {"Chicken", 40.0, "Second Dishes"};
    items[9] = {"Rice", 19.0, "Second Dishes"};

    items[10] = {"Salad", 30.0, "Appetizers"};
    items[11] = {"Sandwich", 10.0, "Appetizers"};
    items[12] = {"Fries", 18.0, "Appetizers"};
    items[13] = {"Onion rings", 26.0, "Appetizers"};
    items[14] = {"Nachos", 15.0, "Appetizers"};

    items[15] = {"Pizza Margherita", 30.0, "Pizza"};
    items[16] = {"Pizza Pepperoni", 36.0, "Pizza"};
    items[17] = {"Pizza Vegetarian", 47.0, "Pizza"};
    items[18] = {"Pizza Meat Lovers", 50.0, "Pizza"};
    items[19] = {"Pizza Seafood", 52.0, "Pizza"};

    items[20] = {"Burger", 40.0, "Fast Food"};
    items[21] = {"Hot dog", 34.0, "Fast Food"};
    items[22] = {"Taco", 25.0, "Fast Food"};
    items[23] = {"Burrito", 30.0, "Fast Food"};
    items[24] = {"Shawarma", 28.0, "Fast Food"};
    
    items[25] = {"Chocolate cake", 25.0, "Desserts"};
    items[26] = {"Cheesecake", 30, "Desserts"};
    items[27] = {"Tiramisu", 35, "Desserts"};
    items[28] = {"Panna cotta", 50, "Desserts"};
    items[29] = {"Fruit salad", 40, "Desserts"};
    
    items[40] = {"Beer", 20, "Bar"};
    items[41] = {"Wine", 60.0, "Bar"};
    items[42] = {"Cocktail", 90.0, "Bar"};
    items[43] = {"Whiskey", 100.0, "Bar"};
    items[44] = {"Rum", 120.0, "Bar"};
    items[45] = {"Tequila", 130.0, "Bar"};
    items[46] = {"Gin", 110.0, "Bar"};
    items[47] = {"Vodka", 80.0, "Bar"};
    items[48] = {"Sambuca", 150.0, "Bar"};
    items[49] = {"Martini", 180.0, "Bar"};
}

void Menu::displayMenu() {
    cout << "< < < < < < < < < Restaurant Menu > > > > > > > > > > >" << endl;
    int itemNumber = 1;

    cout << "\n\n\n           |<<<| First Dishes |>>>|" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    itemNumber = displayCategory("First Dishes", itemNumber);
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\n\n\n           |<<<| Second Dishes |>>>|" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    itemNumber = displayCategory("Second Dishes", itemNumber);
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\n\n\n           |<<<| Appetizers |>>>|" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    itemNumber = displayCategory("Appetizers", itemNumber);
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\n\n\n           |<<<| Pizza |>>>|" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    itemNumber = displayCategory("Pizza", itemNumber);
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\n\n\n           |<<<| Fast Food |>>>|" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    itemNumber = displayCategory("Fast Food", itemNumber);
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\n\n\n           |<<<| Desserts |>>>|" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    itemNumber = displayCategory("Desserts", itemNumber);
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\n\n\n           |<<<| Drinks |>>>|" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    itemNumber = displayCategory("Drinks", itemNumber);
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\n\n\n    |<*> <*> <*> | Bar | <*> <*> <*>|  " << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    displayCategory("Bar", itemNumber);
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
}

int Menu::displayCategory(const string& categoryName, int itemNumber) {
    for (int i = 0; i < size; ++i) {
        if (items[i].category == categoryName) {
            stringstream ss;
            ss << setw(3) << left << itemNumber << ". " << setw(25) << left << items[i].name << setw(10) << right << items[i].price << "$";
            cout << "|<<<| " << ss.str() << endl;
            ++itemNumber;
        }
    }
    return itemNumber;
}

MenuItem Menu::getItem(int index) {
    if (index >= 0 && index < size) {
        return items[index];
    } else {
        return {"", 0.0, ""};
    }
}

int Menu::getSize() {
    return size;
}