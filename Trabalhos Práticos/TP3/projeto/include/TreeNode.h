#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <iostream> // for cout.

// Forward declarations:
template <class T>
class BinaryTree;

class ControlCenter;

template <class T>
class TreeNode {

    private:
        T value;
        TreeNode<T>* leftChild;
        TreeNode<T>* rightChild;

    public:
        TreeNode(T _value);
        T getValue();
        void print();

    friend class BinaryTree<T>;
    friend class ControlCenter;
};

// Implementation of the above template class:

template <class T>
TreeNode<T>::TreeNode(T _value) {
    value = _value; 
    leftChild = nullptr;
    rightChild = nullptr;
}

template <class T>
T TreeNode<T>::getValue() {
    return value;
}

template <class T>
void TreeNode<T>::print() {
    std::cout << value << '\n';
}

#endif