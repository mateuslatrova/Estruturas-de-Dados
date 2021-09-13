#ifndef STACK_H
#define STACK_H

template <class T> class Stack {
    
    protected:
        int _size;
    
    public:
        Stack() { this->_size = 0; }
        int getSize() { return this->_size; }
        bool empty() { return this->_size == 0; }

        virtual T pop() = 0;
        virtual void push(T elem) = 0;
        virtual void clean() = 0;
};

#endif
