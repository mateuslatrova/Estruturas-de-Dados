#ifndef PAIR_H
#define PAIR_H

#include <iostream>

class Pair {
    
    private:
        int _first;
        int _second;

    public:
        Pair();
        Pair(int f, int s);
        int getFirst();
        int getSecond();
        void printPair();

    friend class Map;
};

#endif