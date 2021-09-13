#include "ArrayList.hpp"
#include <iostream>

template <class T>
T ArrayList<T>::getElement(int pos) {
    if (pos > this->_size-1 || pos < 0)
        throw "ERROR: Invalid position.";
    return this->_elems[pos];
}

template <class T>
void ArrayList<T>::setElement(T elem, int pos) {
    if (pos > this->_size || pos < 0)
        throw "ERROR: Invalid position.";
    this->_elems[pos] = elem;
}

template <class T>
void ArrayList<T>::insertAtFirst(T elem) {
    if (this->_size == MAX) 
        throw "ERROR: List is full.";
    for (int i = this->_size; i > 0; i--) {
        this->_elems[i] = this->_elems[i-1];
    }
    this->_elems[0] = elem;
    this->_size++;
}

template <class T>
void ArrayList<T>::insertAtLast(T elem) {
    if (this->_size == MAX)
        throw "ERROR: List is full.";
    this->_elems[this->_size] = elem;
    this->_size++;
}

template <class T>
void ArrayList<T>::insert(T elem, int pos) {
    if (pos > this->_size || pos < 0)
        throw "ERROR: Invalid position.";
    if (this->_size == MAX)
        throw "ERROR: List is full.";

    this->_size++;
    for (int i = _size-1; i > pos; i++) {
        this->_elems[i] = this->_elems[i-1];
    }
    this->_elems[pos] = elem;
}

template <class T>
T ArrayList<T>::removeFirst() {
    if (this->_size == 0)
        throw "ERROR: List is empty.";
    T rem = this->_elems[0];
    for (int i = 1; i < _size; i++) {
        this->_elems[i-1] = this->_elems[i];
    }
    this->_size--;
    return rem;
}

template <class T>
T ArrayList<T>::removeLast() {
    if (this->_size == 0)
        throw "ERROR: List is empty.";
    T aux = this->_elems[this->size-1]
    _size--;
    return aux;
}

template <class T>
T ArrayList<T>::remove(int pos) {
    if (this->_size == 0)
        throw "ERROR: List is empty.";
    
    T rem = this->_elems[pos];
    for (int i = pos; i < this->_size-1) {
        this->_elems[i] = this->_elems[i+1]
    }
    this->_size--;
    return rem;
}

template <class T>
int ArrayList<T>::search(T elem) {
    for (int i = 0; i < this->_size; i++) {
        if (this->_elems[i] == elem)
            return i;
    }
    return -1; // Element not in the list.
}

template <class T>
void ArrayList<T>::print() {
    for (int i = 0; i < this->_size; i++) {
        std::cout << this->_elems[i] << " ";
    }
    std::cout << std::endl;
}

template <class T>
void ArrayList<T>::clean() {
    this->_size = 0;
}
