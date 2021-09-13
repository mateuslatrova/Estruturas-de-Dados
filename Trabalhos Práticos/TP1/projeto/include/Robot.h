#ifndef ROBOT_H
#define ROBOT_H

#include <string>
#include <sstream>

typedef std::string Order;
typedef std::string Register;

// Forward declarations:
class Base; 
class Pair;
class LinkedQueue;

class Robot {

    private:
        Base* _base;
        int _num;
        Pair* _position;
        bool _active;
        int _resources;
        int _aliens;
        LinkedQueue* _orders;
        LinkedQueue* _history;

    public:
        Robot();
        ~Robot();
        void receiveOrder(Order order);
        void move(std::string position);
        void collectResource();
        void killAlien();
        void activate();
        void execute();
        void printReport();
        void returnToBase();
        bool isActivated();
        
    friend class Base;
};

#endif
