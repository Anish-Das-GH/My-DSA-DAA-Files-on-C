#include<stdio.h>

void Printarr(int *A,int n){
    int i;
    for ( i = 0; i < n; i++)
    {
       printf(" %d ",A[i]);
    }
    printf("\n");
    

}

void Merge(int A[],int low,int mid,int high)
{
    int i = low;
    int j = mid+1;
    int k = low;
    int B[100];
    while (i<=mid && j<=high)
    {
        if (A[i]<A[j])
        {
            B[k] = A[j];
            i++;
            j++;
        }

        else
        {
            B[k] = A[j];
            k++;
            j++;
        }
        
    }
    while(i<=mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j<=high)
    {
        B[k] = A[j];
        j++;
        k++;
    }
    for ( i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
    
}

void Mergesort(int A[],int low,int high)
{
    int mid;
    if (low<high)
    {
        mid = (low+high)/2;
        Mergesort(A,low,mid);
        Mergesort(A,mid+1,high);
        Merge(A,low,mid,high);

    }
    
}
int main()
{
    int A[] = {1,32,30,65,41};
    int n=5;
    Mergesort(A,0,n-1);
    Printarr(A,n);
}