#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include "List.hpp"
#define MAX 100

template <class T> class ArrayList : public List<T> {
    
    private:
        T _elems[MAX];
    
    public: 
        ArrayList() : List() {} ;
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
};

#endif