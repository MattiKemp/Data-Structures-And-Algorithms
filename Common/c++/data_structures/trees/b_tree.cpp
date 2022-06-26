#include "b_tree.h"
#include "../lists/stack.cpp"
#include <iostream>

using namespace std;

template<typename T> b_tree<T>::~b_tree(){
    //cout << "b_tree destroyed" << endl;
    stack<b_tree_node<T>> fill_stack = stack<b_tree_node<T>>();
    int curr_level = 1;
    int next_level = 0;
    fill_stack.insert(*this->head);
    //cout << (this->head == nullptr) << endl;
    //cout << this->size << endl;
    fill_stack.print();
    while(fill_stack.get_size() > 0){
        b_tree_node<T> popped = fill_stack.pop();
        //cout << popped.val << endl;
        if(popped.left != nullptr){
            fill_stack.insert(*popped.left);
            next_level++;
        }
        if(popped.right != nullptr){
            fill_stack.insert(*popped.right);
            next_level++;
        }
        curr_level--;
        if(curr_level == 0){
            curr_level = next_level;
            next_level = 0;
        }
        //delete popped;
    }
}

template<typename T> void b_tree<T>::insert(T val){
    if(this->head == nullptr){
        this->head = new b_tree_node<T>(val);
    }
    else{
        b_tree_node<T> * temp = this->head;
        this->head = new b_tree_node<T>(val);
        this->head->left = temp->left;
        this->head->right = temp;
    }
    size++;
}

template<typename T> void b_tree<T>::insert(b_tree_node<T> * node){
}

template<typename T> void b_tree<T>::fill(T val){
    if(this->head == nullptr){
        this->head = new b_tree_node<T>(val);
        return;
    }
    stack<b_tree_node<T>*> fill_stack = stack<b_tree_node<T>*>();
    int curr_level = 1;
    int next_level = 0;
    fill_stack.insert(this->head);
    while(fill_stack.get_size() > 0){
        b_tree_node<T>* popped = fill_stack.pop();
        if(popped->left == nullptr){
            popped->left = new b_tree_node<T>(val);
            return;
        }
        else{
            fill_stack.insert(popped->left);
            next_level++;
        }
        if(popped->right == nullptr){
            popped->right = new b_tree_node<T>(val);
            return;
        }
        else{
            fill_stack.insert(popped->right);
            next_level++;
        }
        curr_level--;
        if(curr_level == 0){
            curr_level = next_level;
            next_level = 0;
        }
    }
}

template<typename T> void b_tree<T>::append(b_tree_node<T> * parent, b_tree_node<T> * node){
//    stack<b_tree_node<T>*> print_stack = stack<b_tree_node<T>*>();
//    int curr_level = 1;
//    int next_level = 0;
//    if(this->head != nullptr){
//        print_stack.insert(*this->head);
//    }
//    else{
//        this->head = b_tree_node<T>(
//    }
}

template<typename T> void b_tree<T>::prune_left(b_tree_node<T> * node){
}

template<typename T> void b_tree<T>::prune_right(b_tree_node<T> * node){
}

//print the tree by level.
template<typename T> void b_tree<T>::print(){
    stack<b_tree_node<T>> print_stack = stack<b_tree_node<T>>();
    int curr_level = 1;
    int next_level = 0;
    if(this->head != nullptr){
        print_stack.insert(*this->head);
    }
    while(print_stack.get_size() > 0){
        b_tree_node<T> popped = print_stack.pop();
        cout << popped.val << " ";
        if(popped.left != nullptr){
            print_stack.insert(*popped.left);
            next_level++;
        }
        if(popped.right != nullptr){
            print_stack.insert(*popped.right);
            next_level++;
        }
        curr_level--;
        if(curr_level==0){
            curr_level = next_level;
            next_level = 0;
            cout << endl;
        }
    }
    cout << endl;
}




int main(){
    //cout << "binary tree main" << endl;
    b_tree<int> int_tree = b_tree<int>();
    int_tree.insert(1);
    int_tree.print(); 
    int_tree.insert(2);
    int_tree.insert(3);
    int_tree.insert(4);
    int_tree.print(); 
    // this is broken.
    // destructor isn't working properly and fill isn't working properly
    // or maybe print is working properly, idk.
    //int_tree = b_tree<int>();
    cout << "fill test" << endl;
    b_tree<int> int_tree2 = b_tree<int>();
    int_tree2.fill(1);
    int_tree2.fill(2);
    int_tree2.fill(3);
    int_tree2.fill(4);
    int_tree2.print(); 
    int_tree2.fill(5);
    int_tree2.fill(6);
    int_tree2.fill(7);
    int_tree2.print(); 
    cout << "done" << endl;

    
    return 0;
}
