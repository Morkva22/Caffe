#ifndef QUEUE_H
#define QUEUE_H

struct OrderEntry {
    string guestName;
    time_t orderTime;
    int itemCount;
};

class Queue {
public:
    Queue(int capacity);
    ~Queue();
    bool enqueue(const OrderEntry& entry);
    bool dequeue(OrderEntry& entry);
    bool isFull() const;
    bool isEmpty() const;
    bool processOrders(); 

private:
    OrderEntry* queue;
    int capacity;
    int front;
    int rear;
    int count;
};

#endif