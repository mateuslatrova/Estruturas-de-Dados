#ifndef NODE_H
#define NODE_H

template <class T> class Node {

    private:
        T _value;
        Node *_next = nullptr;

    public:
        Node() = 0;
        Node(T value) { _value(value) };
    
    friend class LinkedList<T>;
    friend class LinkedStack<T>;
    friend class LinkedQueue<T>;
};

#endif