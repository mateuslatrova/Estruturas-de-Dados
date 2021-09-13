#include "ArrayQueue.hpp"

template <class T>
void ArrayQueue<T>::push(T elem) {
    if (this->_size == MAX)
        throw "ERROR: Queue is full.";
    this->_back = (this->_back + 1) % MAX;
    this->_elems[this->_back] = elem;
    this->_size++;
}

template <class T>
T ArrayQueue<T>::pop() {
    if (this->_size == 0)
        throw "ERROR: Queue is empty.";

    T elem = this->_elems[this->_front];
    this->_front = (this->_front + 1) % MAX;
    this->_size--;
}

template <class T>
void ArrayQueue<T>::clean() {
    this->_size = 0;
    this->_front = 0;
    this->_back = 0;
}