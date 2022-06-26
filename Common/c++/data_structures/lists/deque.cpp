#include "deque.h"
#include <iostream>
#include <type_traits>

using namespace std;

template<typename T> deque<T>::~deque(){
    //cout << "destroying deque" << endl;
    //cout << is_pointer<T>::value << endl;
    deque_node<T>* temp = this->head;
    deque_node<T>* next;
    while(temp!=nullptr){
        next = temp->next;
        //delete temp;
        temp->next = nullptr;
        temp->prev = nullptr;
        temp = next;
    }
}

template <typename T> void deque<T>::append(T val){
    if(this->head == nullptr){
        this->head = new deque_node<T>(val);
        this->end = this->head;
    }
    else{
        this->end->next = new deque_node<T>(val, nullptr, this->end);
        this->end = this->end->next;
    }
    this->size++;
}

template <typename T> T deque<T>::pop(){
    //cout << "pop" << endl;
    T temp = this->end->val;
    //cout << is_pointer<T>::value << endl;
    //cout << this->head << endl;
    //cout << (this->head->next == nullptr) << endl;
    if(this->head->next == nullptr){
        this->head = nullptr;
        delete this->end;
        this->end = nullptr;
        //cout << "head next done" << endl;
    }
    else{
        deque_node<T> * temp_node = this->end->prev;
        this->end->prev->next = nullptr;
        delete this->end;
        this->end = temp_node;
    }
    this->size--;
    //cout << "returning" << endl;
    return temp;
}

template <typename T> T deque<T>::peek(){
    return this->end->val;
}

template <typename T> void deque<T>::append_left(T val){
    if(this->head == nullptr){
        this->head = new deque_node<T>(val);
        this->end = this->head;
    }
    else{
        this->head->prev = new deque_node<T>(val, this->head, nullptr);
        this->head = this->head->prev;
    }
    this->size++;
}

template <typename T> T deque<T>::pop_left(){
    T temp = this->head->val;
    if(this->head == this->end){
        this->head = nullptr;
        delete this->end;
        this->end = nullptr;
    }
    else{
        deque_node<T> * temp_node = this->head->next;
        temp_node->prev = nullptr;
        delete this->head;
        this->head = temp_node;
    }
    this->size--;
    return temp;
}

template <typename T> T deque<T>::peek_left(){
    return this->head->val;
}

template <typename T> void deque<T>::print(){
    deque_node<T> * temp = this->head;
    while(temp != nullptr){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}


//int main(){
//    cout << "deque main" << endl;
//    deque<int> int_deque = deque<int>();
//    int_deque.append(1);
//    int_deque.append(2);
//    int_deque.append(3);
//    int_deque.append(4);
//    int_deque.print();
//    int popped = int_deque.pop();
//    cout << popped << endl;
//    int_deque.print();
//    int_deque.append_left(5);
//    int_deque.append_left(6);
//    int_deque.append_left(7);
//    int_deque.print();
//    cout << "deque size: " << int_deque.get_size() << endl;
//    while(!int_deque.is_empty() > 0){
//        int_deque.pop();
//        int_deque.print();
//    }
//    cout << "deque size: " << int_deque.get_size() << endl;
//    return 0;
//}
