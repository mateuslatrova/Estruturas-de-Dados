#include "../include/LinkedQueue.h"
#include <iostream>

LinkedQueue::LinkedQueue() {
    this->_size = 0;
    this->_front = new Node();
    this->_back = this->_front;
}

LinkedQueue::~LinkedQueue() {
    this->clean();
    delete this->_front;
}

bool LinkedQueue::empty() {
    return this->_size == 0; 
}

void LinkedQueue::push(std::string elem) {
    Node* newNode = new Node(elem);
    this->_back->_next = newNode;
    this->_back = newNode;
    this->_size++;
}

std::string LinkedQueue::pop() {
    if (this->_size == 0)  
        throw "ERROR: Queue is empty.";

    Node* popped = this->_front;
    std::string elem = popped->_next->_value;

    this->_front = this->_front->_next;
    delete popped;
    this->_size--;
    return elem;
}

void LinkedQueue::jumpQueue(std::string elem) {
    Node* newNode = new Node(elem);
    newNode->_next = this->_front->_next;
    this->_front->_next = newNode;
    this->_size++;
    if (newNode->_next == nullptr) {
        this->_back = newNode;
    }
}

void LinkedQueue::print() {
    Node* aux = this->_front->_next;
    while (aux != nullptr) {
        std::cout << aux->_value << std::endl;
        aux = aux->_next;
    }
}

void LinkedQueue::clean() {
    Node* test = this->_front->_next;

    while (test != nullptr) {
        this->_front->_next = test->_next;
        delete test;
        test = this->_front->_next;
    }

    this->_size = 0;
    this->_back = this->_front;
}
