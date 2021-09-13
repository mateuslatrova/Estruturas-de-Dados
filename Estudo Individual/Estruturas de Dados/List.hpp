#ifndef LIST_H
#define LIST_H

template <class T> class List {
    
    protected:
        int _size;
    
    public:
        // General methods:
        List() { this->_size = 0; }
        int getSize() { return this->_size; }
        bool empty(){ return this->_size == 0; }
        
        // Specific methods:
        virtual T getElement(int pos) = 0;
        virtual void setElement(T elem, int pos) = 0;
        virtual void insertAtFirst(T elem) = 0;
        virtual void insertAtLast(T elem) = 0;
        virtual void insert(T elem, int pos) = 0;
        virtual T removeFirst() = 0;
        virtual T removeLast() = 0;
        virtual T remove(int pos) = 0;
        virtual T search(T elem) = 0;
        virtual void print() = 0;
        virtual void clean() = 0;
};

#endif