#include <iostream>
#include "sorting.h"

using namespace std;

int main ()
{
    int A[] = {11,10,9,8,7,6,5,4,3,2,1};
    int B[] = {2,2,2,2,1,1,1,1,6,6,0};
    int C[] = {1,2,3,4,5,6,7,8,9,10,11};
    int D[] = {5,2,7,1,9,0,2,1,4,6,2};
    
    shellSort(A,11);
    shellSort(B,11);
    shellSort(C,11);
    shellSort(D,11);
    
    cout << "A: ";
    for (int i = 0; i < 11; i++)
        cout << A[i] << " ";
    cout << endl;

    cout << "B: ";
    for (int i = 0; i < 11; i++)
        cout << B[i] << " ";
    cout << endl;

    cout << "C: ";
    for (int i = 0; i < 11; i++)
        cout << C[i] << " ";
    cout << endl;

    cout << "D: ";
    for (int i = 0; i < 11; i++)
        cout << D[i] << " ";
    cout << endl;
    
    return 0;
}