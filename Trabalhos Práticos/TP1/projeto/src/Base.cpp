#include "../include/Base.h"
#include "../include/Robot.h"
#include "../include/Map.h"
#include "../include/LinkedQueue.h"

Base::Base(std::ifstream& mapFile) {
    this->_robots = new Robot[50];
    this->_map = new Map(mapFile);
    this->_aliens = 0;
    this->_resources = 0;
    this->_orders = new LinkedQueue();
}

Base::~Base() {
    delete[] this->_robots;
    delete this->_map;
    delete this->_orders;
}

void Base::getRobots() {
    for (int i = 0; i < 50; i++) {
        this->_robots[i]._num = i;
        this->_robots[i]._base = this;
    }
}

void Base::getOrders(std::ifstream& orderFile) {
    Order aux;
    while (getline(orderFile, aux)) {
        this->_orders->push(aux);
    }
}

void Base::sendOrders() {
    while (!this->_orders->empty()) {
        this->sendOrder();
    }
}

void Base::sendOrder() {
    Order order = this->_orders->pop(),
          aux;

    std::stringstream ordStream(order);

    ordStream >> aux >> aux; // reaching the number of the robot.
    int robotNum = std::stoi(aux);

    this->_robots[robotNum].receiveOrder(order);
}

void Base::addAliens(int aliens) {
    this->_aliens += aliens;
}

void Base::addResources(int resources) {
    this->_resources += resources;
}

void Base::printFinalReport() {
    std::cout << "BASE: TOTAL DE ALIENS " 
              << this->_aliens 
              << " RECURSOS "
              << this->_resources 
              << std::endl;
}