#ifndef NODE_H
#define NODE_H

#include <iostream> // for cout.

// Forward declaration:
template <class T>
class LinkedStack;
 
template <class T>
class Node {

    private:
        T value;
        Node *next = nullptr;

    public:
        Node(T _value);
        void print();
    
    friend class LinkedStack<T>;
};

// Implementation of the above template class:

template <class T>
Node<T>::Node(T _value) {
    value = _value;
}

template <class T>
void Node<T>::print() {
    std::cout << value << '\n';
}

#endif