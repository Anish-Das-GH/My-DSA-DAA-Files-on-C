#include<stdio.h>

void Printarray(int* A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", A[i]);
    }
}
 
void heapify(int* arr, int n, int i)
{
    // store largest as the root element
    int largest = i;
 
    int left = 2 * i + 1;
    int right  = 2 * i + 2;
 
    // now check whether the right and left right is larger than the root or not
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
 
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
 
    // if the root is smaller than the children then swap it with the largest children's value
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
 
        // again heapify that side of the heap where the root has gone
        heapify(arr, n, largest);
    }
}
 
 
/* sorts the given array of n size */
void heapsort(int* arr, int n)
{
    // build the binary max heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
 
    // sort the max heap
    for (int i = n - 1; i >= 0; i--)
    {
        // swap the root node and the last leaf node
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
 
        // again heapify the max heap from the root 
        heapify(arr, i, 0);
    }
}
 


int main()
{
    int arr[] = { 10, 30, 5, 63, 22, 12, 56, 33 };
    int n = 8;
 
    printf("\nArray before sorting:\n");
    Printarray(arr, n);
 
    heapsort(arr, n);
 
    printf("\n\nArray after sorting:\n");
    Printarray(arr, n);
 
    return 0;
}
