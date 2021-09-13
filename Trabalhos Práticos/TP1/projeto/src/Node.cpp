#include "../include/Node.h"

Node::Node() {
    this->_value = "";
    this->_next = nullptr;
}

Node::Node(std::string value) {
    this->_value = value;
    this->_next = nullptr;
}

std::string Node::getValue()  {
    return this->_value;
}

void Node::setValue(std::string value) {
    this->_value = value;
}