#ifndef STACK_H
#define STACK_H
#include "./deque.h"

template<typename T> class stack{
public:
    stack(){inter_deque = deque<T>();};
    //~stack();
    bool is_empty(){return this->inter_deque.is_empty();};
    int get_size(){return this->inter_deque.get_size();};
    void insert(T val);
    T pop();
    T peek();
    void print();
private:
    deque<T> inter_deque; 
};

#endif
