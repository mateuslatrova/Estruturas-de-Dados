#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include "Node.h"

template <class T>
class LinkedStack {
    
    private:
        Node<T> top;
        int size;
    
    public:
        LinkedStack();
        ~LinkedStack();
        int getSize();
        bool empty();
        T pop();
        void push(T elem);
        void clean();
};

// Implementation of the above template class:

template <class T>
LinkedStack<T>::LinkedStack() {
    top = new Node<T>;
    size = 0;
}

template <class T>
LinkedStack<T>::~LinkedStack() {
    this->clean();
}

template <class T>
int LinkedStack<T>::getSize() {
    return size;
}

template <class T>
bool LinkedStack<T>::empty() {
    return size == 0;
}

template <class T>
T LinkedStack<T>::pop() {
    if (this->_size == 0)
        throw "ERROR: Stack is empty.";
    Node<T>* popped = this->_top;
    T elem = popped->_value;
    delete popped;
    this->_top = this->_top->_next;
    this->_size--;
    return elem;
}

template <class T>
void LinkedStack<T>::push(T elem) {
    Node<T>* newNode = new Node<T>(elem);
    newNode->_next = this->_top;
    this->_top = newNode;
    this->_size++;
}

template <class T>
void LinkedStack<T>::clean() {
    T elem;
    while (!this->empty)
        elem = this->pop();
    this->_top = nullptr;
}

#endif