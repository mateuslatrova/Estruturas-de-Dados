#include "../include/Pair.h"

Pair::Pair() {
    this->_first = 0;
    this->_second = 0;
}

Pair::Pair(int f, int s) {
    this->_first = f;
    this->_second = s;
}

int Pair::getFirst() {
    return this->_first;
}

int Pair::getSecond() {
    return this->_second;
}

void Pair::printPair() {
    std::cout << "(" << this->_first << "," << this->_second << ")";
}