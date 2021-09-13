import sys
from functools import reduce


def heapify(arr, n, i):
    largest = i  # Initialize largest as root
    l = 2 * i + 1     # left = 2*i + 1
    r = 2 * i + 2     # right = 2*i + 2
 
    # See if left child of root exists and is
    # greater than root 
    if l < n and arr[largest] < arr[l]:
        largest = l
 
    # See if right child of root exists and is
    # greater than root
    if r < n and arr[largest] < arr[r]:
        largest = r
 
    # Change root, if needed
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]  # swap
 
        # Heapify the root.
        heapify(arr, n, largest)
 
def heapSort(arr):
    n = len(arr)
 
    # Build a maxheap.
    for i in range(n//2 - 1, -1, -1):
        heapify(arr, n, i)
 
    # One by one extract elements
    for i in range(n-1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]  # swap
        heapify(arr, i, 0)
 
def bubbleSort (V):
    n = len(V)
    for k in range(0,n-1):
        for j in range(0,n-k-1):
            if V[j] > V[j+1]:
                V[j], V[j+1] = V[j+1], V[j] # swapping contents.

def selectionSort (V):
    n = len(V)
    for i in range(0,n-1):
        jmin = i
        for j in range(i+1,n):
            if V[jmin] > V[j]:
                jmin = j
        V[i], V[jmin] = V[jmin], V[i]


def insertionSort (V):
    n = len(V)
    for i in range(1,n):
        j = i-1 # will hold the position where the key will be inserted.
        key = V[i]
        while V[j] > key and j >= 0:
            V[j+1] = V[j]
            j -= 1
        V[j+1] = key # inserting
        
def merge (V, left, mid, right):
    L = V[left:mid+1]
    R = V[mid+1:right+1]

    L.append(sys.maxsize)
    R.append(sys.maxsize)
    
    i = j = 0
    for k in range(left,right+1):
        if L[i] <= R[j]:
            V[k] = L[i]
            i += 1
        else:
            V[k] = R[j]
            j += 1

def mergeSort2 (V, left, right):    
    if left < right:
        mid = (left + right) // 2
        mergeSort2(V, left, mid)
        mergeSort2(V, mid+1, right)
        merge(V, left, mid, right)

def mergeSort (V):
    mergeSort2(V,0,len(V)-1)
    
def partition (V, start, end):
    pivot = V[end]
    
    i = start # os elementos até i serão menores que o pivot.
    for j in range(start, end): # os elementos cujo indice é > que i e menor 
        if V[j] <= pivot:       # que j são maiores que o pivot
            V[j], V[i] = V[i], V[j]
            i += 1

    V[i], V[end] = V[end], V[i] # colocando o pivot no seu devido lugar.
    return i

def quickSort (V, start=0, end=None):
    if end == None:
        end = len(V)-1

    if start < end:
        p = partition(V,start,end)
        quickSort(V,start,p-1)
        quickSort(V,p+1,end)

# get number of digits in largest item
def __get_num_digits(A):
    m = 0
    for item in A:
        m = max(m, item)
    return len(str(m))

# flatten into a 1D List
from functools import reduce
def __flatten(A):
    return reduce(lambda x, y: x + y, A)

def radix(A):
    num_digits = __get_num_digits(A)
    for digit in range(0, num_digits):
        B = [[] for i in range(10)]
        for item in A:
            # num is the bucket number that the item will be put into
            num = item // 10 ** (digit) % 10
            B[num].append(item)
        A = __flatten(B)
    return A



    
