
#include "ui.h"
#include "../../Domain/Menu/Menu.h"
#include "../../Domain/Clock/Clock.h"
#include "../../Domain/Guest/Guest.h"
#include "../../Domain/Order/Queue/Queue.h"

UI::UI(Cafe* cafe, Logger* logger) : cafe(cafe), logger(logger) {}

void UI::run() {
    Clock clock;
    Guest guest;
    Queue orderQueue(10);
    int orderNumber = 1;

    cout << "< < < < < < < < < Welcome to the Cafe > > > > > > > > >" << endl;
    cout << "                       Current Time: " << clock.getCurrentTime() << endl;

    while (true) {
        guest.registerGuest();
        cout << endl;
        displayMenu();
        Order order(guest);

        order = takeOrder(guest);

        if (order.getSize() > 0) {
            double total = cafe->calculateTotal(order);
            cout << "Total: " << total << "$" << endl;

            int paymentAttempts = 0;
            while (paymentAttempts < 3) {
                double payment;
                string input;
                cout << "|<<<| Enter payment amount: ";
                getline(cin, input);
                stringstream ss(input);

                if (ss >> payment) {
                    if (payment >= total) {
                        double change = payment - total;
                        cafe->completeOrder(order);
                        if (change > 0) {
                            cout << "|<<<| Your change is: " << change << "$" << endl;
                        }
                        cout << "                                                                              Current Time: " << clock.getCurrentTime() << endl;
                        cout << "|<<<| Thank you, " << guest.getName() << "!" << endl;

                        cout << "|<<<| Your order:" << endl;
                        MenuItem* orderedItems = order.getItems();
                        int orderSize = order.getSize();
                        for (int i = 0; i < orderSize; i++) {
                            cout << "- " << orderedItems[i].name << " (" << orderedItems[i].price << "$)" << endl;
                        }

                        OrderEntry entry;
                        entry.guestName = guest.getName();
                        entry.orderTime = time(0);
                        entry.itemCount = order.getSize();

                        if (orderQueue.isFull()) {
                            cout << "|<<<| Order queue is full. Order added to file only." << endl;
                            order.saveToFile(orderNumber++, clock);
                        } else {
                            if (!orderQueue.enqueue(entry)) {
                                cerr << "|<<<| Error adding order to queue for " << guest.getName() << endl;
                                order.saveToFile(orderNumber++, clock);
                            } else {
                                if (!orderQueue.processOrders()) {
                                    cerr << "|<<<| Error processing orders." << endl;
                                }
                                order.saveToFile(orderNumber++, clock);
                            }
                        }

                        string repeatChoiceStr;
                        cout << "\n|<<<| Do you want to place another order? (y/n): ";
                        getline(cin, repeatChoiceStr);

                        if (!repeatChoiceStr.empty() && (repeatChoiceStr[0] == 'y' || repeatChoiceStr[0] == 'Y')) {
                            break;
                        } else {
                            cout << "|<<<| Thank you for your visit!" << endl;
                            this_thread::sleep_for(seconds(2));
                            return; 
                        }
                    } else {
                        cout << "|<<<| Payment failed. Insufficient funds." << endl;
                        paymentAttempts++;
                    }
                } else {
                    cout << "|<<<| Invalid input." << endl;
                    paymentAttempts++;
                }
            }

            if (paymentAttempts >= 3) {
                cout << "|<<<| Too many payment attempts. Try again later." << endl;
            }

        } else {
            cout << "|<<<| No items were ordered." << endl;
            string repeatChoiceStr;
            cout << "\n|<<<| Do you want to place another order? (y/n): ";
            getline(cin, repeatChoiceStr);

            if (!repeatChoiceStr.empty() && (repeatChoiceStr[0] == 'y' || repeatChoiceStr[0] == 'Y')) {
                continue; 
            } else {
                cout << "|<<<| Thank you for your visit!" << endl;
                this_thread::sleep_for(seconds(2));
                return; 
            }
        }
    }
}

void UI::displayMenu() {
    cafe->displayMenu();
}

Order UI::takeOrder(Guest& guest) {
    Order order(guest);
    int choice;
    string input;

    cout << "|<<<| Enter item number to order (0 to finish):" << endl;
    while (true) {
        getline(cin, input);
        stringstream ss(input);
        if (ss >> choice) {
            if (choice == 0) {
                break;
            }

            MenuItem item = cafe->getItem(choice - 1);
            if (!item.name.empty()) {
                order.addItem(item);
                cout << item.name << " added to order." << endl;
            } else {
                cout << "|<<<| Invalid input" << endl;
            }
        }
    }
    return order;
}
