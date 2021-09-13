#include "LinkedQueue.hpp"

template <class T>
LinkedQueue<T>::LinkedQueue(): Queue() {
    this->_front = new Node<T>(); // head node.
    this->_back = this->_front;
}

template <class T>
LinkedQueue<T>::~LinkedQueue() {
    this->clean();
    delete this->_front;
}

template <class T>
void LinkedQueue<T>::push(T elem) {
    Node<T>* newNode = new Node(elem);
    this->_back->_next = newNode;
    this->_back = newNode;
    this->_size++;
}

template <class T>
T LinkedQueue<T>::pop() {
    if (this->_size == 0)  
        throw "ERROR: Queue is empty.";
    
    Node<T>* popped = this->_front;
    T elem = popped->_next->_value;
    
    this->_front = this->_front->_next;
    delete popped;
    this->_size--;
    return elem;
}

template <class T>
void LinkedQueue<T>::clean() {
    Node<T>* test = this->_front->_next;

    while (test != nullptr) {
        this->_front->_next = test->_next;
        delete test;
        test = this->_front->_next;
    }

    this->_size = 0;
    this->_back = this->_front;
}

template <class T>
void LinkedQueue<T>::FuraFila(T elem) {
    LinkedQueue<T>* aux = new LinkedQueue<T>();
    T popped, saved;

    // Remove os elementos da fila original e guarda na auxiliar
    // retirando o item com chave c se encontrar 
    while (!this->empty()) {
        popped = this->pop();
        if (popped == elem)
            saved = popped;
        else
            aux->push(popped);
    }

    // Insere o furador de fila no início da fila original
    if (saved == elem)
       this->push(saved);

    // Reinsere os elementos da fila original de volta 
    while (!aux->empty()) {
        popped = aux->pop();
        this->push(popped);
    }

    delete aux;
}