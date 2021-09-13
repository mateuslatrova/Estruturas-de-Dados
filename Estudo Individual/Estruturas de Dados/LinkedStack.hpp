#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include "Stack.hpp"
#include "Node.hpp"

template <class T> class LinkedStack : public Stack<T> {
    
    private:
        Node<T>* _top;
    
    public:
        LinkedStack() : Stack() { this->_top = nullptr; };
        ~LinkedStack();
        T pop();
        void push(T elem);
        void clean();
};

#endif