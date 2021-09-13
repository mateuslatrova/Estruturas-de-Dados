#ifndef SORTING_H
#define SORTING_H

#include "funcoes.h"


void selectionSort(int *v, int n)
{
    for (int i = 0; i < n-1 ; i++)
    {
        int iMin = i;
        
        for (int j = i+1; j < n; j++)
            if (v[j] < v[iMin]) iMin = j;
        
        swap(&v[i],&v[iMin]);
    }
}

void bubbleSort(int *v, int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1-i; j++)
            if (v[j] > v[j+1]) swap(&v[j],&v[j+1]);
    }
}

void bubbleSortRec(int *v, int n)
{
    if (n == 1) return;

    for (int j = 0; j < n-1; j++)
        if (v[j] > v[j+1]) swap(&v[j],&v[j+1]);
    bubbleSortRec(v,n-1);
}

void insertionSort(int *v, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = v[i], j = i-1;
        while (j >= 0 && v[j] < key)
        {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
    }
}

void merge(int *v, int start, int mid, int end)
{
    int size = end-start+1, lsize = mid-start+1, rsize = end-mid;
    
    // Temporary array(will be copied to the original):
    int *res = (int*) malloc(size*sizeof(int));

    int cl = start, cr = mid+1, cm = 0; // stand for count in the left array,
                                        //           count in the right array
                                        //       and count in the merged array.
    
    // Merging:
    while (cl < mid+1 && cr < size) {
        if (v[cl] <= v[cr]) {
            res[cm] = v[cl];
            cl++;
        }else {
            res[cm] = v[cr];
            cr++;
        }
        cm++;
    }

    // One of the subarrays is done. Just copy the remaining elements
    // of the other to the resulting array.
    if (cm < size) {
        while (cl < mid+1) {
            res[cm] = v[cl];
            cl++, cm++;
        }
        while (cr < size) {
            res[cm] = v[cr];
            cr++, cm++;
        }
    }

    // Copying to the original:
    int i, j;
    for (i = start, j = 0; j < size; i++, j++) {
        v[i] = res[j];
    }

    free(res);
}

void mergeSort(int *v, int start, int end)
{
    int mid;
    if (start < end) {
        mid = (start+end)/2;
        mergeSort(v, start, mid);
        mergeSort(v, mid+1, end);
        merge(v, start, mid, end);
    }
}

void partition (int left, int right, int *i, int *j, int *A) // l stands for left and r for right.
{                                                            // i and j are indexes.
    *i = left, *j = right;
    
    int pivot = A[(*i+*j)/2];
    
    do
    {
        while (A[*i] > pivot) 
            (*i)++;
        while (A[*j] < pivot) 
            (*j)--;
        if (*i <= *j) 
        {
            swap(&A[*i], &A[*j]);
            (*i)++, (*j)--;
        }
    } while (*i <= *j);
}

void quickSort(int *A, int left, int right)
{
    int i, j;
    partition(left, right, &i, &j, A);
    if (left < j) quickSort(A,left, j); //obs: if j == left, only the right subarray needs to be sorted.
    if (i < right) quickSort(A, i, right);
}

void medianPartition (int left, int right, int *i, int *j, int *A)
{
    *i = left, *j = right;
    int mid = (*i+*j)/2;

    int median[3] = {A[left], A[mid], A[right]};
    insertionSort(median,3);
    A[left] = median[0];
    A[mid] = median[1];
    A[right] = median[2];

    swap(&A[mid],&A[right-1]);

    *i = left+1;  // first and last element are already in the right partition
    *j = right-1; // (guaranteed by the median of 3 process above) so they don't
                  // need to participate in the rest of the process. 
                  
    
    int pivot = A[*j];
    
    do
    {
        while (A[*i] > pivot) 
            (*i)++;
        while (A[*j] < pivot) 
            (*j)--;
        if (*i <= *j) 
        {
            swap(&A[*i], &A[*j]);
            (*i)++, (*j)--;
        }
    } while (*i <= *j);
}

void medianQuickSort(int *A, int left, int right)
{
    int i, j;
    medianPartition(left, right, &i, &j, A);
    if (left < j) quickSort(A,left, j); //obs: if j == left, only the right subarray needs to be sorted.
    if (i < right) quickSort(A, i, right);
}

 
void heapify (int arr[], int n, int root)
{
    int maxIndex = root;

    int leftSon = 2*root + 1;
    int rightSon = 2*root + 2;

    if (leftSon < n && arr[maxIndex] > arr[leftSon])
        maxIndex = leftSon;

    if (rightSon < n && arr[rightSon] < arr[maxIndex])
        maxIndex = rightSon;

    if (maxIndex != root)
    {
        swap(&arr[root],&arr[maxIndex]);
        heapify(arr,n,maxIndex);
    }
}

void heapSort (int arr[], int n)
{
    // Building a max-heap
    for (int i = n/2-1; i >= 0; i--)
    {
        heapify(arr,n,i);
    }

    //
    for (int i = n-1; i > 0; i--)
    {
        swap(&arr[i],&arr[0]);
        heapify(arr,i,0);
    }
}

void shellSort(int *A, int n)
{
    int gap = n/2; // floor value
    int i, j;

    while (gap > 0) {
        j = gap;
        while (j < n) {
            i = j-gap;
            while (i >= 0) {
                if (A[i+gap] < A[i])
                    break;
                else
                    swap(&A[i+gap], &A[i]);
                i -= gap;
            }
            j++;
        }
        gap /= 2;
    }
}
  
#endif