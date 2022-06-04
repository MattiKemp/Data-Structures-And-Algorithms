#ifndef ARRAY_LIST_INT_HPP
#define ARRAY_LIST_INT_HPP

#include <iostream>
using namespace std;

class array_list_int{
public:
    array_list_int() {size = 1; capacity = 1; arr = new int[1];};
    array_list_int(int size, int capacity) {this->size = size; this->capacity = capacity; arr = new int[capacity];} 
    array_list_int(int size, int capacity, int * arr) {this->size = size; this->capacity = capacity; this->arr = arr;};
    int get_size() {return size;};
    int get_capacity() {return capacity;};
    int * get_array() {return arr;};
    int at(int index);
    int find(int value);
    void resize(int new_size);
    void set(int index, int value);
    void append(int value); 
    void swap(int index1, int index2);
    void clear();
    void print();
    void print(int amount);

private:
    int size;
    int capacity;
    int * arr;
};

// allow negative indexing like in Python.
int array_list_int::at(int index){
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

int array_list_int::find(int value){
    for(int i = 0; i < size; i++){
        if(arr[i] == value){
            return i;
        }
    }
    return -1;
}

void array_list_int::resize(int new_size){
    cout << "resizing for: " << new_size << endl;
    int * new_arr = new int[new_size];
    for(int i = 0; i < size; i++){
        new_arr[i] = arr[i];
    }
    capacity = new_size;
    arr = new_arr;
}

void array_list_int::set(int index, int value){
    if(index >= capacity){
        resize(2*capacity);
    }
    arr[index] = value;
    size = index+1;
}

void array_list_int::append(int value){
    if(size+1 >= capacity){
        resize(2*capacity);
    }
    arr[size] = value;
    size++; 
}

void array_list_int::swap(int index1, int index2){
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

void array_list_int::clear(){
    size = 1;
    capacity = 1;
    arr = new int[1];
}

void array_list_int::print(){
    cout << "printing arraylist" << endl;
    for(int i = 0; i < size; i++){
        cout << arr[i] << ", ";
    }
    cout << endl;
}

void array_list_int::print(int amount){
    cout << "printing arraylist" << endl;
    for(int i = 0; i < amount; i++){
        cout << arr[i] << ", ";
    }
    cout << endl;
}

//int main(){
//    array_list_int arr_list = array_list_int();
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

#endif
