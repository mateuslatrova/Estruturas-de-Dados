#ifndef QUEUE_H
#define QUEUE_H

template <class T> class Queue {

    protected:
        int _size;

    public:
        Queue() { this->_size = 0; }
        int getSize() { return this->_size;}
        bool empty() { return this->_size == 0 }
        virtual void push(T elem) = 0;
        virtual T pop() = 0;
        virtual void clean() = 0;
};

#endif