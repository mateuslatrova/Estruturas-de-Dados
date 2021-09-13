#include "LinkedStack.hpp"

template <class T>
LinkedStack<T>::~LinkedStack() {
    this->clean();
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
    Node<T>* newNode = new Node(elem);
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