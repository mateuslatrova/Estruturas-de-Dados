#include "../include/Base.h"
#include "../include/Map.h"
#include "../include/Pair.h"
#include "../include/Robot.h"
#include "../include/LinkedQueue.h"
#include <iostream>
#include <fstream>

int main (int argc, char* argv[]) {
    std::ifstream mapFile(argv[1]);
    std::ifstream orderFile(argv[2]);

    // Exception:
    if (!mapFile.is_open() || !orderFile.is_open()) {
        throw "Error opening files.\n";
        exit(EXIT_FAILURE);
    }

    Base base(mapFile);
    base.getRobots();
    base.getOrders(orderFile);
    base.sendOrders(); 

    // Robots do all their duties, report to the base, and return. 
    base.printFinalReport();

    mapFile.close();
    orderFile.close();

    return 0;
}
