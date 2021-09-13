#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include "Queue.hpp"
#include "Node.hpp"

template <class T> class LinkedQueue: public Queue<T> {
    
    private:
        Node<T>* _front;
        Node<T>* _back;

    public:
        LinkedQueue();
        ~LinkedQueue();
        void push(T elem);
        T pop();
        void clean();
        void FuraFila(T elem);
};

#endif