#ifndef BASES_MANAGER_H
#define BASES_MANAGER_H

#include "../include/Base.h"
#include <fstream>

class BasesManager {

    public:
        
        // Input and output methods:
        void readFile(std::ifstream& file, int numLines, Base *bases);
        void printFirstBases(Base *bases);

        // Auxiliary methods:
        void swap(Base *a, Base *b);
        void rebuildHeap(Base arr[], int n, int root);
        void partition(int left, int right, int *i, int *j, Base *arr);
        void medianPartition(int left, int right, int *i, int *j, Base *arr);

        // Sorting algorithms:
        void insertionSort(Base arr[], int n);
        void heapSort(Base arr[], int n);
        void quickSort(Base arr[], int left, int right);
        void medianQuickSort(Base arr[], int left, int right);
        void shellSort(Base arr[], int n);
};

#endif