#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void Heapify(int A[],int n,int i)
{
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if (left<n && A[left]>A[largest])
    {
        largest = left;
    }

     if (right<n && A[right]>A[largest])
    {
        largest = right;
    }

    if(largest != i)
    {
        int temp = A[largest];
        A[largest] = A[i];
        A[i] = temp;
        
        Heapify(A,n,largest);
    }
    
    
}

void Heapsort(int A[],int n)
{
    int i;
    int temp;
    for ( i = n/2-1; i >= 0; i--)
    {
        Heapify(A,n,i);
    }

    for ( i = n-1; i >= 0; i--)
    {
        temp = A[0];
        A[0] = A[i];
        A[i] = temp;

        Heapify(A,i,0);
    }
}

int main()
{
    int arr[] = { 10, 30, 5, 63, 22, 12, 56, 33 };
    int n = 8;
 

 
    Heapsort(arr, n);
    printArray(arr, n);
 
}