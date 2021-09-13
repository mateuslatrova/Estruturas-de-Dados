#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "List.hpp"
#include "Node.hpp"

template <class T> class LinkedList : public List<T> {
    
    private:
        Node<T>* _head = nullptr;
        Node<T>* _tail = nullptr;
        Node<T>* position(int pos, bool before);
    
    public: 
        LinkedList();
        ~LinkedList();
        T getElement(int pos);
        void setElement(T elem, int pos);
        void insertAtFirst(T elem);
        void insertAtLast(T elem);
        void insert(T elem, int pos);
        T removeFirst();
        T removeLast();
        T remove(int pos);
        int search(T elem);
        void print();
        void clean();
        void invert();
        void MoveMenor();
};

#endif