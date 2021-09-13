#include "../include/Robot.h"
#include "../include/Base.h"
#include "../include/Map.h"
#include "../include/Pair.h"
#include "../include/LinkedQueue.h"

Robot::Robot() {
    this->_base = nullptr;
    this->_position = new Pair();
    this->_active = false;
    this->_resources = 0;
    this->_aliens = 0;
    this->_orders = new LinkedQueue();
    this->_history = new LinkedQueue();
}

Robot::~Robot() {
    this->_base = nullptr;
    delete this->_position;
    delete this->_history;
    delete this->_orders;
}

void Robot::receiveOrder(Order order) {
    std::stringstream ordStream(order);
    std::string orderType;

    ordStream >> orderType;

    // Command orders:
    if (orderType == "MOVER")
        this->_orders->push(order);
    else if (orderType == "*MOVER")
        this->_orders->jumpQueue(order);
    else if (orderType == "COLETAR")
        this->_orders->push(order);
    else if (orderType == "*COLETAR")
        this->_orders->jumpQueue(order);
    else if (orderType == "ELIMINAR")
        this->_orders->push(order);
    else if (orderType == "*ELIMINAR")
        this->_orders->jumpQueue(order);
    
    // Direct commands:
    else if (orderType == "ATIVAR")
        this->activate();
    else if (orderType == "EXECUTAR")
        this->execute();
    else if (orderType == "RELATORIO")
        this->printReport();
    else if (orderType == "RETORNAR")
        this->returnToBase();
}

void Robot::move(std::string position) {
    std::string strFirst, strSecond;
    
    // Getting first element of the pair:
    int i = 1;
    while (position[i] != ',') {
        strFirst += position[i];
        i++;
    }

    // Getting second element of the pair:
    i++;
    while (position[i] != ')') {
        strSecond += position[i];
        i++;
    }

    int first = std::stoi(strFirst), 
        second = std::stoi(strSecond);

    Pair newPosition = Pair(first, second);
    
    Register newRegister;
    
    if (this->_base->_map->getContent(newPosition) == 'O') {
        newRegister = "ROBO " + 
                       std::to_string(this->_num) + 
                       ": IMPOSSIVEL MOVER PARA (" + 
                       strFirst + 
                       "," + 
                       strSecond + 
                       ")";
        this->_history->push(newRegister);
    } else {
        newRegister = "ROBO " + 
                       std::to_string(this->_num) + 
                       ": MOVEU PARA (" + 
                       strFirst + 
                       "," + 
                       strSecond + 
                       ")";
        this->_history->push(newRegister);
        *this->_position = newPosition;
    }
}

void Robot::collectResource() {
    Register newRegister;
    if (this->_base->_map->getContent(*this->_position) != 'R') {
        newRegister = "ROBO " + 
                      std::to_string(this->_num) + 
                      ": IMPOSSIVEL COLETAR RECURSOS EM (" + 
                      std::to_string(this->_position->getFirst()) + 
                      "," + 
                      std::to_string(this->_position->getSecond()) + 
                      ")"; 
        this->_history->push(newRegister);  
    } else {
        this->_resources++;
        this->_base->_map->setContent(*this->_position, '.');
        newRegister = "ROBO " + 
                      std::to_string(this->_num) + 
                      ": RECURSOS COLETADOS EM (" + 
                      std::to_string(this->_position->getFirst()) + 
                      "," + 
                      std::to_string(this->_position->getSecond()) + 
                      ")";
        this->_history->push(newRegister);
    }
}

void Robot::killAlien() {
    Register newRegister;
    if (this->_base->_map->getContent(*this->_position) != 'H') {
        newRegister = "ROBO " + 
                      std::to_string(this->_num) + 
                      ": IMPOSSIVEL ELIMINAR ALIEN EM (" + 
                      std::to_string(this->_position->getFirst()) + 
                      "," +
                      std::to_string(this->_position->getSecond()) + 
                      ")"; 
        this->_history->push(newRegister); 
    } else {
        this->_aliens++;
        this->_base->_map->setContent(*this->_position, '.');
        newRegister = "ROBO " + 
                      std::to_string(this->_num) + 
                      ": ALIEN ELIMINADO EM (" + 
                      std::to_string(this->_position->getFirst()) + 
                      "," + 
                      std::to_string(this->_position->getSecond()) + 
                      ")"; 
        this->_history->push(newRegister);
    }
}

void Robot::activate() {
    if (this->isActivated()) {
        std::cout << "BASE: ROBO " << this->_num << " JA ESTA EM MISSAO\n";
    } else {
        this->_active = true;
        std::cout << "BASE: ROBO " << this->_num << " SAIU EM MISSAO\n";
    }
}

void Robot::execute() {
    if (this->isActivated()) {
        while (!this->_orders->empty()) {
            Order order(this->_orders->pop());
            std::stringstream ordStream(order);
            std::string orderType;

            ordStream >> orderType;

            if (orderType == "MOVER" || orderType == "*MOVER") {
                std::string position;
                ordStream >> position >> position;
                this->move(position);
            } else if (orderType == "COLETAR" || orderType == "*COLETAR") {
                this->collectResource();
            } else if (orderType == "ELIMINAR" || orderType == "*ELIMINAR") {
                this->killAlien();
            }
        }
    } else {
        std::cout << "BASE: ROBO " << this->_num << " NAO ESTA EM MISSAO\n";
    }
}

void Robot::printReport() {
    this->_history->print();
}

void Robot::returnToBase() {
    if (!this->isActivated()) {
        std::cout << "BASE: ROBO " << this->_num << " NAO ESTA EM MISSAO\n";
    } else {
        std::cout << "BASE: ROBO " 
                  << this->_num 
                  << " RETORNOU ALIENS "
                  << this->_aliens 
                  << " RECURSOS " 
                  << this->_resources 
                  << std::endl;
        *this->_position = Pair();
        this->_history->clean();
        this->_base->addAliens(this->_aliens);
        this->_aliens = 0;
        this->_base->addResources(this->_resources);
        this->_resources = 0;
        this->_active = false;
    }
}

bool Robot::isActivated() {
    return this->_active;
}