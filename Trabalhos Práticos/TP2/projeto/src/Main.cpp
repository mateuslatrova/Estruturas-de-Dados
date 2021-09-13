#include <fstream>
#include <iostream>
#include <string>
#include "../include/Base.h"
#include "../include/BasesManager.h"

int main (int argc, char *argv[])
{
    int numLines = std::stoi(argv[2]); // number N from the specifications.
    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cout << "Erro na abertura do arquivo.\n";
        exit(EXIT_FAILURE);
    }

    Base *bases = (Base*) malloc(numLines*sizeof(Base));
    if (bases == NULL) 
        exit(EXIT_FAILURE);

    BasesManager manager;
    manager.readFile(file,numLines,bases);

    // Sorting bases:
    manager.shellSort(bases,numLines);
    // Other options to sort:
    // manager.insertionSort(bases,numLines);
    // manager.heapSort(bases,numLines);
    // manager.quickSort(bases,0,numLines-1);
    // manager.medianQuickSort(bases,0,numLines-1);

    manager.printFirstBases(bases);

    free(bases);
    file.close();

    return 0;
}