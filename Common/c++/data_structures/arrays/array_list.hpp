#ifndef ARRAY_LIST_HPP
#define ARRAY_LIST_HPP

#include <iostream>
using namespace std;

template <typename T> class array_list{
public:
    array_list() {size = 1; capacity = 1; arr = new T[1];};
    array_list(int size, int capacity) {this->size = size; this->capacity = capacity; arr = new T[capacity];} 
    array_list(int size, int capacity, T * arr) {this->size = size; this->capacity = capacity; this->arr = arr;};
    int get_size() {return size;};
    int get_capacity() {return capacity;};
    T * get_array() {return arr;};
    T at(int index);
    int find(T value);
    void resize(int new_size);
    void set(int index, T value);
    void append(int value);
    void swap(int index1, int index2);
    void clear();
    void print();
    void print(int amount);

private:
    int size;
    int capacity;
    T * arr;
};

// allow negative indexing like in Python.
template <typename T> T array_list<T>::at(int index){
    if(abs(index) >= size){
        throw "index out of bounds!";
    }
    else if(index >= 0){
        return arr[index];
    }
    else{
        return arr[size+index];
    }
}

// returns the index of the element, or -1 if the element does not exist.
template <typename T> int array_list<T>::find(T value){
    for(int i = 0; i < size; i++){
        // == must be defined for type T
        if(arr[i] == value){
            return i;
        }
    }
    return -1;
}

template <typename T> void array_list<T>::resize(int new_size){
    cout << "resizing for: " << new_size << endl;
    T * new_arr = new T[new_size];
    for(int i = 0; i < size; i++){
        new_arr[i] = arr[i];
    }
    capacity = new_size;
    arr = new_arr;
}

template <typename T> 
void array_list<T>::set(int index, T value){
    if(index >= capacity){
        resize(2*capacity);
    }
    arr[index] = value;
    size = index+1;
}

template <typename T> void array_list<T>::append(int value){
    if(size+1 >= capacity){
        resize(2*capacity);
    }
    arr[size] = value;
    size++; 
}

template <typename T> void array_list<T>::swap(int index1, int index2){
    T temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}
    
template <typename T> void array_list<T>::clear(){
    size = 1;
    capacity = 1;
    arr = new T[1];
}

template <typename T> void array_list<T>::print(){
    cout << "printing arraylist" << endl;

    for(int i = 0; i < size; i++){
        cout << arr[i] << ", ";
    }
    cout << endl;
}

template <typename T> void array_list<T>::print(int amount){
    cout << "printing arraylist" << endl;

    for(int i = 0; i < amount; i++){
        cout << arr[i] << ", ";
    }
    cout << endl;
}

//int main(){
//    array_list<int> arr_list = array_list<int>();
//    arr_list.resize(10);
//    arr_list.print();
//    for(int i = 1; i < 5; i++){
//        arr_list.append(i);
//    }
//    arr_list.print();
//    arr_list.set(11, 15);
//    arr_list.print();
//    cout << "size: " << arr_list.get_size() << ", capacity: " << arr_list.get_capacity() << endl;
//    cout << arr_list.at(1) << endl;
//    cout << arr_list.at(-1) << endl;
//    cout << arr_list.at(arr_list.get_size()-10) << endl;
//    cout << arr_list.at(-10) << endl;
//
//
//    return 0;
//}

#endif
