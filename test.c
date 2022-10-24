#include<stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int Partition(int A[],int low,int high)
{
    int pivot = A[low];
    int i = low+1;
    int j= high;
    int temp;
    do
    {
       while (A[i]<=pivot)
       {
        i++;
       }
       while (A[j]>pivot)
       {
        j--;
       }
       if (i<j)
       {
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
       }
       
       
       
    } while (i<j);
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;    
}

void Quicksort(int A[],int low,int high)
{
    int Partitionindex;
    if (low<high)
    {
        Partitionindex = Partition(A,low,high);
        Quicksort(A,low,Partitionindex-1);
        Quicksort(A,Partitionindex+1,high);
    }
    
}

int main()
{
    
    int A[] = {9, 4, 4, 8, 7, 5, 6};
    int n=7;
    Quicksort(A,0,n-1);
    printArray(A,n);
    return 0;
}