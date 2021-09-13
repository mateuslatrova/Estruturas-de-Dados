#include "../include/BasesManager.h"

void BasesManager::readFile(std::ifstream& file, int numLines, Base* bases) {
    std::string planet;
    int distance;
    for (int i = 0; i < numLines; i++) {
        file >> planet >> distance;
        bases[i].setPlanet(planet);
        bases[i].setDistance(distance);
    }
}

void BasesManager::printFirstBases(Base *bases) {
    for (int i = 0; i < 7; i++) {
        bases[i].print();
    }
}

void BasesManager::swap(Base *a, Base *b) {
    Base temp = *b;
    *b = *a;
    *a = temp;
}

void BasesManager::rebuildHeap(Base arr[], int n, int root) {
    int minIndex = root;

    int leftSon = 2*root + 1;
    int rightSon = 2*root + 2;

    if (leftSon < n && arr[minIndex].distance > arr[leftSon].distance)
        minIndex = leftSon;

    if (rightSon < n && arr[rightSon].distance < arr[minIndex].distance)
        minIndex = rightSon;

    if (minIndex != root)
    {
        swap(&arr[root],&arr[minIndex]);
        rebuildHeap(arr, n, minIndex);
    }
}

void BasesManager::partition(int left, int right, int *i, int *j, Base *arr) {
    *i = left, *j = right;
    
    Base pivot = arr[(*i+*j)/2];
    
    do
    {
        while (arr[*i].distance > pivot.distance) 
            (*i)++;
        while (arr[*j].distance < pivot.distance) 
            (*j)--;
        if (*i <= *j) 
        {
            swap(&arr[*i], &arr[*j]);
            (*i)++, (*j)--;
        }
    } while (*i <= *j);
}

void BasesManager::medianPartition(int left, int right, int *i, int *j, Base *arr) {
    *i = left, *j = right;
    int mid = (*i+*j)/2;

    // Median of 3 process:
    Base median[3] = {arr[left], arr[mid], arr[right]};
    insertionSort(median,3);
    arr[left] = median[0];
    arr[mid] = median[1];
    arr[right] = median[2];

    swap(&arr[mid],&arr[right-1]);

    *i = left+1;  // first and last element are already in the right partition
    *j = right-1; // (guaranteed by the median of 3 process above) so they don't
                  // need to participate in the rest of the process. 
                  
    Base pivot = arr[*j];
    
    do
    {
        while (arr[*i].distance > pivot.distance) 
            (*i)++;
        while (arr[*j].distance < pivot.distance) 
            (*j)--;
        if (*i <= *j) 
        {
            swap(&arr[*i], &arr[*j]);
            (*i)++, (*j)--;
        }
    } while (*i <= *j);

}

void BasesManager::insertionSort(Base arr[], int n) {
    for (int i = 1; i < n; i++)
    {
        Base key = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j].distance <= key.distance)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void BasesManager::heapSort(Base arr[], int n) {
    // Building a min-heap
    for (int i = n/2-1; i >= 0; i--)
    {
        rebuildHeap(arr,n,i);
    }

    for (int i = n-1; i > 0; i--)
    {
        swap(&arr[i],&arr[0]); // the min(first) of each iteration goes to proper position(end).
        rebuildHeap(arr,i,0); 
    }
}


void BasesManager::quickSort(Base arr[], int left, int right) {
    int i, j;
    partition(left, right, &i, &j, arr);
    if (left < j) quickSort(arr,left, j); 
    if (i < right) quickSort(arr, i, right);
}


void BasesManager::medianQuickSort(Base arr[], int left, int right) {
    int i, j;
    medianPartition(left, right, &i, &j, arr);
    if (left < j) quickSort(arr,left, j); 
    if (i < right) quickSort(arr, i, right);
}

void BasesManager::shellSort(Base arr[], int n) {
    int gap = n/2; // floor value
    int i, j;

    while (gap > 0) {
        j = gap;
        while (j < n) {
            i = j-gap;
            while (i >= 0) {
                if (arr[i+gap].distance < arr[i].distance)
                    break;
                else
                    swap(&arr[i+gap], &arr[i]);
                i -= gap;
            }
            j++;
        }
        gap /= 2;
    }
}