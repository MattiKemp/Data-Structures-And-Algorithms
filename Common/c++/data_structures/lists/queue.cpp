#include "queue.h"
#include "./deque.cpp"
#include <iostream>

using namespace std;

template<typename T> void queue<T>::enqueue(T val){
    this->inter_queue.append_left(val);
}

template<typename T> T queue<T>::dequeue(){
    return this->inter_queue.pop();
}

template<typename T> T queue<T>::peek(){
    return this->inter_queue.peek();
}

template<typename T> void queue<T>::print(){
    this->inter_queue.print();
}


int main(){
    cout << "queue main" << endl;
    queue<int> int_queue = queue<int>();
    int_queue.enqueue(1);
    int_queue.enqueue(2);
    int_queue.enqueue(3);
    int_queue.print();
    while(!int_queue.is_empty()){
        cout << int_queue.dequeue() << endl;
    }
    int_queue.enqueue(1);
    int_queue.dequeue();
    int_queue.enqueue(2);
    int_queue.enqueue(3);
    int_queue.print();


    return 0;
}
