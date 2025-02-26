#include "Queue.h"

using namespace std;

Queue::Queue(int capacity) : capacity(capacity), front(0), rear(0), count(0) {
    queue = new OrderEntry[capacity];
}

Queue::~Queue() {
    delete[] queue;
}

bool Queue::enqueue(const OrderEntry& entry) {
    if (isFull()) {
        return false;
    }
    queue[rear] = entry;
    rear = (rear + 1) % capacity;
    count++;
    return true;
}

bool Queue::dequeue(OrderEntry& entry) {
    if (isEmpty()) {
        return false;
    }
    entry = queue[front];
    front = (front + 1) % capacity;
    count--;
    return true;
}

bool Queue::isFull() const {
    return count == capacity;
}

bool Queue::isEmpty() const {
    return count == 0;
}

bool Queue::processOrders() {
    while (!isEmpty()) {
        OrderEntry entry;
        if (dequeue(entry)) {
            time_t endTime = entry.orderTime + entry.itemCount * 5;

            while (time(0) < endTime) {
                this_thread::sleep_for(chrono::milliseconds(100));
            }

            time_t now = time(0);
            tm ltm;

#ifdef _WIN32
            localtime_s(&ltm, &now);
#else
            localtime_r(&now, &ltm);
#endif

            stringstream ss;
            ss << setfill('0') << setw(2) << ltm.tm_hour << ":"
               << setfill('0') << setw(2) << ltm.tm_min << ":"
               << setfill('0') << setw(2) << ltm.tm_sec;

            cout << "|<<<| Order for " << entry.guestName << " is ready! Time spent: " << entry.itemCount * 5 << " seconds. Current Time: " << ss.str() << " Enjoy!" << endl;
        }
    }
    return true; 
}