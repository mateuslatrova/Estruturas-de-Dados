#ifndef FUNCOES_H
#define FUNCOES_H
#include <cmath>

// Soma dos n primeiros naturais.
int recursiveSum (int n)
{
    if (n == 1) return 1;
    return n + recursiveSum(n-1);
}

// Potência de x^n
int recursivePow (int x, int n)
{
    if (n == 0) return 1;
    return x*recursivePow(x, n-1);
}

// Máximo de um vetor de n elementos
int max (int v[], int n) 
{
    int max = v[0];
    for (int i = 1; i < n; i++) {
        if (max < v[i]) max = v[i];
    }
    return max;
}

// Mínimo de um vetor de n elementos
int min (int v[], int n) 
{
    int min = v[0];
    for (int i = 1; i < n; i++) {
        if (min > v[i]) min = v[i];
    }
    return min;
}

int fatorialIter (int n)
{
    int fat = 1;
    for (int i = 1; i <= n; i++) {
        fat *= i;
    }
    return fat;
}

int fatorialRec (int n)
{
    if (n == 0) return 1;
    return n*fatorialRec(n-1);
}

// Verifica se n é primo ou não.
bool primo (int n) 
{
    if (n == 1) return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0) 
        {
            return false;
        }
    }
    return true;
}

int binToDec (int bin)
{
    int dec = 0, i = 0;
    int digit = bin%10;
    while (bin > 0)
    {
        dec += digit * pow(2,i);
        i++;
        bin /= 10;
        digit = bin%10;
    }
    return dec;
}

int decToBin (int dec)
{
    int bin = 0, i = 0;
    int digit = dec % 2;
    while (dec > 0)
    {
        bin += digit * pow(10,i);
        i++;
        dec /= 2;
        digit = dec % 2;
    }
    return bin;
}

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

// Dado um vetor de n inteiros, retorna o comprimento de um segmento crescente
// de comprimento máximo.
int maxOrderedPiece (int *v, int n)
{
    int max = 1, test = 1;
    for (int i = 0; i < n-1; i++)
    {
        if (v[i] < v[i+1]) test++;
        else test = 1;
        if (test > max) max = test;
    }
    return max;
}

// Conta quantas vezes o digito d aparece no numero n.
int digitFreq(int n, int d)
{
    int res = 0;
    while (n > 0)
    {
        if (n%10 == d) res++;
        n /= 10;
    }
    return res;
}

// Retorna a quantidade de algarismos de um número.
int digits(int n) 
{
    int digits = 0;
    while (n > 0)
    {
        n /= 10;
        digits++;
    }
    return digits;
}

// Verifica se um número é palíndromo.
bool isPalindrome(int n)
{
    bool res = true;
    int d = digits(n);
    for (int i = 0; i < d/2; i++)
    {
        int aux1 = n, aux2 = n;
        for (int j = 0; j < i; j++) aux1 /= 10;
        for (int j = 0; j < d-i-1; j++) aux2 /= 10;
        if (!(aux1%10 == aux2%10)) 
        {
            res = false;
            break;
        }
    }
    return res;
}

// Transforma n num vetor com os algarismos de n em cada posição.
void intToArray (int n, int *v, int size)
{
    int elem = 0;

    for (int i = size-1; i >= 0; i--)
    {
        elem = n % 10;
        v[i] = elem;
        n /= 10;
    }
}

// Recursive Euclid's algorithm for the GCD.
int gcdRec(int a, int b) // a > b, always.
{
    if (b == 0) return a;
    else return gcdRec(b,a%b);
}

// Iterative Euclid's algorithm for the GCD.
int gcd (int a, int b)
{
    int dividend = (a >= b) ? a : b;
    int divisor = (a <= b) ? a : b;
    while (divisor != 0)
    {
        int remainder = dividend%divisor;
        dividend = divisor;
        divisor = remainder;
    }
    return dividend;
}

int binarySearchRec(int A[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        // If the element is at the middle, return its position.
        if (A[mid] == x) return mid;
        
        // If x is smaller than the middle element, it is
        // located in the left subarray.
        if (A[mid] > x)
            return binarySearchRec(A, l, mid-1, x);
    
        // Else the element can only be in the right subarray.
        return binarySearchRec(A, mid+1, r, x);
    }
    return -1; // x is not in the array;
}

int 
buscaBinaria (int x, int n, int v[]) { 
    int e = -1, d = n; // atenção!
    while (e < d-1) {  
        int m = (e + d)/2;
        if (v[m] < x) e = m;
        else d = m; 
    }
    return d;
}

int linearSearch(int A[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (A[i] == x) return i;
    }
    return -1; // x is not in the array.
}

#endif