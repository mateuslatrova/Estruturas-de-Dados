#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include "Node.h"

class LinkedQueue {
    
    private:
        Node* _front;
        Node* _back;
        int _size;

    public:
        LinkedQueue();
        ~LinkedQueue();
        bool empty(); 
        void push(std::string elem);
        std::string pop();
        void jumpQueue(std::string elem);
        void print();
        void clean();
};

#endif