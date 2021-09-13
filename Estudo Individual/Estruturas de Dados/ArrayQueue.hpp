#ifndef QUEUE_H
#define QUEUE_H

#include "Queue.hpp"
#define MAX 100

template <class T> class ArrayQueue: public Queue<T> {
    
    private:
        T _elems[MAX];
        int _front;
        int _back;

    public:
        ArrayQueue() : Queue() { _front(0), _back(0);}
        void push(T elem);
        T pop();
        void clean();
};

#endif