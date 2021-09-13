#ifndef MAP_H
#define MAP_H

#include <fstream>

class Pair;

class Map {
    private:
        Pair* _size;
        char** _map = nullptr;

    public:
        Map(std::ifstream& map);
        ~Map();
        char getContent(Pair position);
        void setContent(Pair position, char cont);
        Pair getSize();
        void print();
};

#endif