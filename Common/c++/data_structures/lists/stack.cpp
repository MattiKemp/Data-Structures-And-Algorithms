#include "stack.h"
#include "./deque.cpp"
#include <iostream>

using namespace std;

template<typename T> void stack<T>::insert(T val){
    this->inter_deque.append(val);
}

template<typename T> T stack<T>::pop(){
    return this->inter_deque.pop();
}

template<typename T> T stack<T>::peek(){
    return this->inter_deque.peek();
}

template<typename T> void stack<T>::print(){
    this->inter_deque.print();
}

//int main(){
//    cout << "stack main" << endl;
//    stack<int> int_stack = stack<int>();
//    int_stack.insert(1);
//    int_stack.insert(2);
//    int_stack.insert(3);
//    int_stack.print();
//    while(!int_stack.is_empty()){
//        cout << int_stack.pop() << " " << endl;
//    }
//    return 0;
//}
