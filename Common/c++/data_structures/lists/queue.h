#ifndef QUEUE_H
#define QUEUE_H
#include "deque.h"

template<typename T> class queue{
public:
    queue(){this->inter_queue = deque<T>();};
    bool is_empty(){return this->inter_queue.is_empty();};
    bool get_size(){return this->inter_queue.get_size();};
    void enqueue(T val);
    T dequeue();
    T peek();
    void print();
private:
    deque<T> inter_queue;
};

#endif 
