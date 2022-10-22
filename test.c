#include <stdio.h>

void printarray(int *A,int n)
{
    int i;
    for ( i = 0; i < n; i++)
    {
        printf(" %d ",A[i]);

    }
    printf("\n");
    
}

int Partition(int A[],int low,int high)
{
    int pivot = A[low];
    int i = low+1;
    int j = high;
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
       A[j]=temp;
        }
        
    } while (i<j);
    temp = A[low];
    A[low]= A[j];
    A[j] = temp;
    return j;
}

void Quicksort(int A[],int low,int high)
{
    int Partitionindex;
    if(low<high)
    {
        Partitionindex = Partition(A,low,high);
        Quicksort(A,low,Partitionindex-1);
        Quicksort(A,Partitionindex+1,high);
    }
}

int main()
{
    int A[]={17,3,4,2,10,43,32,23,56};
    int n=9;
    Quicksort(A,0,n-1);
    printarray(A,n);

}