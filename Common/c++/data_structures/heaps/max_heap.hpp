#ifndef MAX_HEAP_HPP
#define MAX_HEAP_HPP

#include "../arrays/arrays.hpp"
#include <iostream>
using namespace std;

template <typename T> class max_heap{
public:
    max_heap(){this->size = 0; this->arr = array_list<T>();};
    max_heap(int size){this->size = size; this->arr = array_list<T>(size, 2*size);}; 
    max_heap(int size, array_list<T> arr){this->size = size; this->arr = arr;};
    T peek();   
    T pop();
    int find(T node);
    void insert(T node);
    void clear();
    void print();
private:
    int size;
    array_list<T> arr;
    void max_heapify(bool down=false);
};

template <typename T> void max_heap<T>::max_heapify(bool down){
    if(!down){
        int curr = size-1;
        int parent = curr/2 -1*(curr%2==0);
        while(parent >= 0){
            if(arr.at(curr) > arr.at(parent)){            
                arr.swap(curr, parent);
                curr = parent;
                parent = curr/2 -1*(curr%2==0);
            }
            else{
                break;
            }
        }
    }
    else{
        int curr = 0;
        int largest = 0;
        while(2*curr+2 < size){
            if(arr.at(largest) < arr.at(curr*2+1)){
                largest = curr*2+1; 
            }
            if(arr.at(largest) < arr.at(curr*2+2)){
                largest = curr*2+2;
            }
            if(curr == largest){
                break;
            }
            arr.swap(curr, largest);
            curr = largest;
        }
    }
}

template <typename T> T max_heap<T>::peek(){
    if(size > 0){
        return arr.at(0);
    }
    return T();
}

template <typename T> T max_heap<T>::pop(){
    if(size > 0){
        // Probably should add code to make it so we
        // are returning the actual object, and not a copy. Maybe
        // make this an option later to choose between them.
        T popped = arr.at(0);
        arr.swap(0, size-1);
        arr.set(size-1, T());
        size--;
        max_heapify(true);
        return popped;
    }
    return T();
}

template <typename T> void max_heap<T>::insert(T node){
    arr.set(size, node);
    size++;
    max_heapify();
}

// returns the index of the element in the internal array, or -1 if no such element exists.
template <typename T> int max_heap<T>::find(T node){
    return arr.find(node);
}
    
template <typename T> void max_heap<T>::clear(){
    size = 0;
    arr.clear();
}

template <typename T> void max_heap<T>::print(){
    arr.print(size);
}

struct test_struct{
    int val;
    test_struct(){};
    test_struct(int val){this->val = val;};
    bool operator>(const test_struct& a) const{
        return (this->val > a.val);
    }
    bool operator>=(const test_struct& a) const{
        return (this->val >= a.val);
    }
    bool operator<(const test_struct& a) const{
        return (this->val < a.val);
    }
    bool operator<=(const test_struct& a) const{
        return (this->val <= a.val);
    }
    bool operator==(const test_struct& a) const{
        return (this->val == a.val);
    }
    friend ostream& operator<<(ostream& os, const test_struct& a){
        return os << a.val;
    }

};

int main(){
    max_heap<int> int_heap =  max_heap<int>();
    int_heap.insert(1);
    int_heap.max_heap::print();
    int_heap.insert(2);
    int_heap.max_heap::print();
    int_heap.insert(3);
    int_heap.max_heap::print();
    int_heap.insert(4);
    int_heap.max_heap::print();
    int_heap.insert(5);
    int_heap.max_heap::print();
    int_heap.insert(6);
    int_heap.max_heap::print();
    int_heap.insert(7);
    int_heap.max_heap::print();
    int_heap.insert(8);
    int_heap.max_heap::print();
    // pretty sure it is working here
    int max = int_heap.pop();
    cout << "popped: " << max << endl;
    int_heap.max_heap::print();
    cout << "1 is at: " << int_heap.find(1) << endl;
    max = int_heap.pop();
    cout << "popped: " << max << endl;
    int_heap.max_heap::print();
    max = int_heap.pop();
    cout << "popped: " << max << endl;
    int_heap.max_heap::print();
    max = int_heap.pop();
    cout << "popped: " << max << endl;
    int_heap.max_heap::print();
    cout << "peeked: " << int_heap.peek() << endl;
    int_heap.clear();
    int_heap.max_heap::print();
    cout << "-------new heap-------" << endl;
    int n[5] = {1,2,3,4,5}; 
    max_heap<int> int_heap2 = max_heap<int>(5, array_list<int>(5, 10, n));
    int_heap2.print();
    test_struct a = test_struct(1);
    test_struct b = test_struct(2);
    bool greater = a > b;
    bool greater_equal = a >= b;
    bool lesser = a < b;
    bool lesser_equal = a <= b;
    bool equal = a == b;
    cout << greater << endl;
    cout << greater_equal << endl;
    cout << lesser << endl;
    cout << lesser_equal << endl;
    cout << equal << endl;
    a = b;
    cout << a.val << endl;
    cout << a << endl;

    max_heap<test_struct> test_heap = max_heap<test_struct>(); 
    test_heap.insert(test_struct(1));
    test_heap.print();
    test_heap.insert(test_struct(2));
    test_heap.print();
    test_heap.insert(test_struct(3));
    test_heap.print();
    test_heap.insert(test_struct(4));
    test_heap.print();
    cout << "peek: " << test_heap.peek() << endl;
    test_struct popped = test_heap.pop();
    cout << "pooped: " << popped << endl;
    test_heap.print();
    return 0;
}

#endif
