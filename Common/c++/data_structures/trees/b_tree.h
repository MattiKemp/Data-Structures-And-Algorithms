#ifndef B_TREE_H
#define B_TREE_H

#include <iostream>
//there really isn't a point to this level of abstraction for just
//a binary tree.

template<typename T> struct b_tree_node{
    T val;
    b_tree_node<T> * left;
    b_tree_node<T> * right;
    b_tree_node(){left = nullptr; right = nullptr;};
    b_tree_node(T val){this->val = val; this->left = nullptr; this->right = nullptr;};
    b_tree_node(b_tree_node<T> * left, b_tree_node<T> * right){this->left = left; this->right = right;};
    friend std::ostream& operator<<(std::ostream& os, const b_tree_node& a){ 
        return os << a.val;
    }
};

template<typename T> class b_tree{
public:
    b_tree(){head = nullptr;};
    b_tree(b_tree_node<T> * head){this->head = head; size = 1;};
    ~b_tree();
    b_tree_node<T> * get_head(){return this->head;};
    int get_size(){return this->size;};
    // inserts at head, moving current head to the right.
    void insert(T val);
    void insert(b_tree_node<T> * node);
    // inserts at the left most open spot.
    void fill(T val);
    void fill(b_tree_node<T> * node);
    // appends the given tree, node, to the given parent.
    void append(b_tree_node<T> * parent, b_tree_node<T> * node);
    void prune_left(b_tree_node<T> * node);
    void prune_right(b_tree_node<T> * node);
    void print();

private:
    b_tree_node<T> * head;
    int size = 0;
};

#endif
