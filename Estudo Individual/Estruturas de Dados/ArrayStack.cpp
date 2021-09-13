#include "ArrayStack.hpp"

template <class T>
T ArrayStack<T>::pop() {
    if (this->_size == 0)
        throw "ERROR: Stack is empty.";
    T ret = this->_elems[this->_top];
    this->_size--;
    this->_top--;
    return ret;
}

template <class T>
void ArrayStack<T>::push(T elem) {
    if (this->_size == MAX)
        throw "ERROR: Stack is full."
    this->_size++;
    this->_top++;
    this->_elems[this->_top] = elem;
}

template <class T>
void ArrayStack<T>::clean() {
    this->_size = 0;
    this->_top = -1;
}