#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "Messages.h"
#include "TreeNode.h"
#include "LinkedStack.h"
#include <stdlib.h> // for rand().

template <class T>
class BinaryTree {

    private:
        TreeNode<T>* root;

        void predecessor(TreeNode<T>* &removed, TreeNode<T>* &predec);
        void recursiveInsert(TreeNode<T>* &currentNode, T val);
        void recursiveRemove(TreeNode<T>* &currentNode, T val);
        void recursiveClean(TreeNode<T>* &currentNode);
        bool recursiveSearch(TreeNode<T>* &currentNode, T val);
        void levelWalk();
        void preOrderWalk(TreeNode<T>* currentNode);
        void inOrderWalk(TreeNode<T>* currentNode);
        void postOrderWalk(TreeNode<T>* currentNode);

    public:
        BinaryTree();
        ~BinaryTree();
        void searchAndEncode(T valToBeEncoded, 
                             TreeNode<T>* &currentNode, 
                             EncodedMessage &encoded);
        void insert(T val);
        void remove(T val);
        void clean();
        bool search(T val);

    friend class ControlCenter;
};

// Implementation of the above class:
template <class T>
void BinaryTree<T>::predecessor(TreeNode<T>* &removed,
                                TreeNode<T>* &predec) {
    if (predec->rightChild != nullptr) {
        predecessor(removed, predec->rightChild);
        return;
    }

    removed->value = predec->value;
    removed = predec;
    predec = predec->leftChild;
    delete removed;
}

template <class T>
void BinaryTree<T>::recursiveInsert(TreeNode<T>* &currentNode, T val) {
    if (currentNode == nullptr) 
        currentNode = new TreeNode<T>(val);
    else {
        if (val < currentNode->value)
            recursiveInsert(currentNode->leftChild, val);
        else
            recursiveInsert(currentNode->rightChild, val);
    }
}

template <class T>
void BinaryTree<T>::recursiveRemove(TreeNode<T>* &currentNode, T val) {
    if (currentNode == nullptr) 
        throw "Value not present in the tree.";
    else {
        if (val < currentNode->value)
            recursiveRemove(currentNode->leftChild, val);
        else if (val > currentNode->value)
            recursiveRemove(currentNode->rightChild, val);
        else { // FOUND!
            if (currentNode->rightChild == nullptr) {
                T aux = currentNode;
                currentNode = currentNode->leftChild;
                delete aux;
            } else if (currentNode->leftChild == nullptr) {
                T aux = currentNode;
                currentNode = currentNode->rightChild;
                delete aux;
            } else
                predecessor(currentNode, currentNode->leftChild);
        }  
    }
}

template <class T>
void BinaryTree<T>::recursiveClean(TreeNode<T>* &currentNode) {
    if (currentNode != nullptr) {
        recursiveClean(currentNode->leftChild);
        recursiveClean(currentNode->rightChild);
        delete currentNode;
    }
}

template <class T>
bool BinaryTree<T>::recursiveSearch(TreeNode<T>* &currentNode, T val) {
    bool found;
    if (currentNode == nullptr) 
        return false;
    else {
        if (val < currentNode->value)
            found = recursiveSearch(currentNode->leftChild, val);
        else if (val > currentNode->value)
            found = recursiveSearch(currentNode->rightChild, val);
        else  
            return true;
    }
    return found;
}

template <class T>
void BinaryTree<T>::levelWalk() {
    LinkedStack<T>* stack = new LinkedStack<T>();
    TreeNode<T>* currentNode;

    stack->push(root);

    while (!stack->empty()) {
        currentNode = stack->pop();
        if (currentNode != nullptr) {
            currentNode->print();
            stack->push(currentNode->leftChild);
            stack->push(currentNode->rightChild);
        }
    }
}

template <class T>
void BinaryTree<T>::preOrderWalk(TreeNode<T>* currentNode) {
    if (currentNode != nullptr) {
        currentNode->print();
        preOrderWalk(currentNode->leftChild);
        preOrderWalk(currentNode->rightChild);
    }
}

template <class T>
void BinaryTree<T>::inOrderWalk(TreeNode<T>* currentNode) {
    if (currentNode != nullptr) {
        inOrderWalk(currentNode->leftChild);
        currentNode->print();
        inOrderWalk(currentNode->rightChild);
    }
}

template <class T>
void BinaryTree<T>::postOrderWalk(TreeNode<T>* currentNode) {
    if (currentNode != nullptr) {
        postOrderWalk(currentNode->leftChild);
        postOrderWalk(currentNode->rightChild);
        currentNode->print();
    }
}

template <class T>
BinaryTree<T>::BinaryTree() {
    root = nullptr;
}

template <class T>
BinaryTree<T>::~BinaryTree() {
    clean();
}

template <class T>
void BinaryTree<T>::searchAndEncode(T valToBeEncoded,
                                    TreeNode<T>* &currentNode,
                                    EncodedMessage &encoded) {
    
    EncodedMessage currentEncoding;
    int aux; // will hold the numbers that represent the path to the right char.

    if (currentNode == nullptr) 
        return;
    else {
        if (valToBeEncoded < currentNode->value) {
            aux = 2*(std::rand()%5) + 1; // must be odd.
            currentEncoding = std::to_string(aux);
            encoded.append(currentEncoding);
            searchAndEncode(valToBeEncoded,currentNode->leftChild, encoded);
        } else if (valToBeEncoded > currentNode->value) {
            aux = 2*(std::rand()%5); // must be even.
            currentEncoding = std::to_string(aux);
            encoded.append(currentEncoding);
            searchAndEncode(valToBeEncoded,currentNode->rightChild, encoded);
        }else // reached value to be encoded. Stop.
            return;
    }
}

template <class T>
void BinaryTree<T>::insert(T val) {
    recursiveInsert(root, val);
}

template <class T>
void BinaryTree<T>::remove(T val) {
    recursiveRemove(root, val);
}

template <class T>
void BinaryTree<T>::clean() {
    recursiveClean(root);
    root = nullptr;
}

template <class T>
bool BinaryTree<T>::search(T val) {
    bool found = recursiveSearch(root, val);
    return found;
}

#endif