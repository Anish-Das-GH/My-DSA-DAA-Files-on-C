#include<stdio.h>

void arraytraverse(int n,int *A)
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
    int j  =high;
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
    int partitionindex;
    if (low<high)
    {
        partitionindex = Partition(A,low,high);
        Quicksort(A,low,partitionindex-1);
        Quicksort(A,partitionindex+1,high);
    }
    
}

int main()
{

int A[]={12,5,7,8,9,3,98,6};
int n = 8;
Quicksort(A,0,n-1);
arraytraverse(n,A);




    return 0;
}