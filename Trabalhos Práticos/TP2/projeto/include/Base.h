#ifndef BASE_H
#define BASE_H

#include <string>

class Base {

    private:
        std::string planet;
        int distance;
    
    public:
        Base();
        Base(std::string planet, int distance);
        std::string getPlanet();
        int getDistance();
        void setPlanet(std::string _planet);
        void setDistance(int _distance);
        void print();

    friend class BasesManager;
};

#endif

