#ifndef NODE_H
#define NODE_H

#include <string>

//typedef std::string Order;

class Node {

    private:
        std::string _value;
        Node* _next;

    public:
        Node();
        Node(std::string value);
        void setValue(std::string value);
        std::string getValue();
    
    friend class LinkedQueue;
};

#endif