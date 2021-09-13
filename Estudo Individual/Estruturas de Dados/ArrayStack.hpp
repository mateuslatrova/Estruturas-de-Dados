#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include "Stack.hpp"
#define MAX 100

template <class T> class ArrayStack : public Stack<T> {
    
    private:
        T _elems[MAX];
        T _top;
    
    public:
        ArrayStack() : Stack() { this->_top = -1; }
        T pop();
        void push(T elem);
        void clean();
};

#endif