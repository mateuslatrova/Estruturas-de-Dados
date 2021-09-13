#include "../include/Base.h"
#include <iostream>

Base::Base() {
    this->planet = "";
    this->distance = 0;
}

Base::Base(std::string _planet, int _distance) {
    this->planet = _planet;
    this->distance = _distance;
}

std::string Base::getPlanet() {
    return this->planet;
}

int Base::getDistance() {
    return this->distance;
}

void Base::setPlanet(std::string _planet) {
    this->planet = _planet;
}

void Base::setDistance(int _distance) {
    this->distance = _distance;
}

void Base::print() {
    std::cout << this->planet << " " << this->distance << "\n";
}