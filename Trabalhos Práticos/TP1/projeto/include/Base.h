#ifndef BASE_H
#define BASE_H

#include <fstream>
#include <iostream>

class Map;
class Robot;
class LinkedQueue;

class Base {

    private:
        Map* _map;
        Robot* _robots;
        int _aliens;
        int _resources;
        LinkedQueue* _orders;
        
    public:
        Base(std::ifstream& mapFile);
        ~Base();
        void getRobots();
        void getOrders(std::ifstream& orderFile);
        void sendOrders();
        void sendOrder();
        void addAliens(int aliens);
        void addResources(int resources);
        void printFinalReport();

    friend class Robot;
};

#endif