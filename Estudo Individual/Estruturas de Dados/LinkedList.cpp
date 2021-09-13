#include "LinkedList.hpp"
#include <iostream>

template <class T>
LinkedList<T>::LinkedList() {
    this = new List();
    this->_head = new Node();
    this->_tail = _head;
}

template <class T>
LinkedList<T>::~LinkedList() {
    this->clean();
    delete this->_head;
}

template <class T>
Node<T>* LinkedList<T>::position(int pos, bool before=false) {
    Node<T>* p = this->_head->_next;
    int i = 0;
    
    if (before)
        pos--;

    while (i != pos) {
        p = p->_next;
        i++;
    }

    return p;
}

template <class T>
T LinkedList<T>::getElement(int pos) {
    if (pos > this->_size-1 || pos < 0)
        throw "ERROR: List is empty.";
    Node<T>* elem = position(pos);
    return elem->_value;
}

template <class T>
void LinkedList<T>::setElement(T elem, int pos) {
    Node<T>* n = position(pos);
    n->_value = elem;
}

template <class T>
void LinkedList<T>::insertAtFirst(T elem) {
    Node<T>* newNode = new Node(elem);
    newNode->_next = this->_head->_next;
    this->_head->_next = newNode;
    if (this->_tail == this->_head) {
        this->_tail = newNode;
    }
    this->_size++;
}

template <class T>
void LinkedList<T>::insertAtLast(T elem) {
    Node<T>* newNode = new Node(elem);
    this->_tail->_next = newNode;
    this->_tail = newNode;
    this->_size++;
}

template <class T>
void LinkedList<T>::insert(T elem, int pos) {
    Node<T>* newNode = new Node(elem);
    Node<T>* prev = position(pos,true);
    newNode->_next = prev->_next;
    prev->_next = newNode;
}

template <class T>
T LinkedList<T>::removeFirst() {
    if (this->_size == 0) 
        throw "ERROR: List is empty.";

    Node<T>* rem = this->head->next;
    this->_head->_next = rem->_next;
    delete rem;
    this->_size--;
}

template <class T>
T LinkedList<T>::removeLast() {
    Node<T>* aux = position(this->_size-1,true);
    aux->_next = nullptr;
    delete this->_tail;
    this->_tail = aux;
    this->_size--;
}

template <class T>
T LinkedList<T>::remove(int pos) {
    Node<T>* prev = position(pos,true);
    Node<T>* rem = prev->_next;
    prev->_next = rem->_next;
    T ret = rem->_value;
    delete rem;
    return ret;
}

template <class T>
int LinkedList<T>::search(T elem) {
    Node<T>* p = this->_head->_next;
    int i = 0;
    while (p != nullptr) {
        if (p->_value == elem)
            return i;
        p = p->_next;
    }
    return -1; // Element is not in the list.
}

template <class T>
void LinkedList<T>::print() {
    Node<T>* p = this->_head->_next;
    while (p != nullptr) {
        std::cout << p->_value << " ";
    }
    std::cout << std::endl;
}

template <class T>
void LinkedList<T>::clean() {
    Node<T>* p = this->_head->_next;
    while (p != nullptr) {
        this->_head->_next = p->_next;
        delete p;
    }
    this->_tail = this->_head;
    this->_size = 0;
}

template <class T>
void LinkedList<T>::invert() {
    T cur;
    for (int i = 0; i < this->_size-1; i++) {
        cur = this->removeLast();
        this->insert(cur,i)
    }
}

template <class T>
void LinkedList<T>::MoveMenor() {
    if (this->empty())
        return;
    else {
        Node<T> p = this->_head->_next;
        Node<T> befMin = this->_head;
        while (p->_next != nullptr) {
            if (p->_next->_value < befMin->_next->_value) {
                befMin = p;
            }
            p = p->_next;
        }
        Node<T> min = befMin->_next;
        befMin->_next = min->_next;
        min->_next = this->_head->_next;
        this->_head->_next = min;
    }
}