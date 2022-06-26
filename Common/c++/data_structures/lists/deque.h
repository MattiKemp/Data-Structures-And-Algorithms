#ifndef DEQUE_H
#define DEQUE_H

template<typename T> struct deque_node{
    T val;
    deque_node<T> * next;
    deque_node<T> * prev;
    deque_node(){next = nullptr; prev = nullptr;};
    deque_node(T val){this->val = val; next = nullptr; prev = nullptr;};
    deque_node(T val, deque_node * next, deque_node * prev){this->val = val; this->next = next; this->prev = prev;};
};

template<typename T> class deque{
public:
    deque(){head = nullptr; end = nullptr;};
    deque(deque_node<T> * node){head = node; end = node;};
    ~deque();
    int get_size(){return this->size;};
    bool is_empty(){return this->size==0;};
    void append(T val);
    T pop();
    T peek();
    void append_left(T val);
    T pop_left();
    T peek_left();
    void print();
private:
    deque_node<T> * head;
    deque_node<T> * end;
    int size = 0;
};

#endif
