#include "../include/Map.h"
#include "../include/Pair.h"

Map::Map(std::ifstream& map) {
    int lines, columns;
    map >> lines >> columns;

    this->_size = new Pair(lines,columns);

    this->_map = new char*[lines];
    for (int i = 0; i < lines; i++)
        this->_map[i] = new char[columns];
    
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            map >> this->_map[i][j];
        }
    }
}

Map::~Map() {
    for (int i = 0; i < this->_size->_first; i++) {
        delete[] this->_map[i];
    }
    delete[] _map;
    delete _size;
}

char Map::getContent(Pair position) {
    return this->_map[position._first][position._second];
}

void Map::setContent(Pair position, char cont) {
    this->_map[position.getFirst()][position.getSecond()] = cont;
}

Pair Map::getSize() {
    return *this->_size;
}

void Map::print() {
    for (int i = 0; i < this->_size->_first; i++) {
        for (int j = 0; j < this->_size->_second; j++) {
            std::cout << this->_map[i][j] << " ";
        }
        std::cout << std::endl;
    }
}