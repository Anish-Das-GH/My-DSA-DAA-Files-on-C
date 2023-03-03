// Iterative Method 
#include <stdio.h>

int binarysearch(int arr[],int size,int element)
{
    int low ,mid,high;
    low=0;
    high=size-1;
    mid=low+high/2;
    while (low<=high)
    {
      if (arr[mid]==element)
      {
        return mid;
      }
      
      else if (element>arr[mid])
      {
        high = mid-1;
      }
      else
      {
        low = mid-1;
      }
      
    }
    
    

}

int main()
{
    int arr[]={2,3,4,7,12,34,56};
    int size = sizeof(arr)/sizeof(int);
    int element = 7;
    int index = binarysearch(arr,size,element);
     printf("The element %d was found at index %d \n", element, index);
    return 0;


}

// Recursive Method -----
// #include <stdio.h>
// #define MAX 100
// int binarysearch(int A[],int low,int high,int key)
// {
//     int mid=(low+high)/2;
//     while(low<=high)
//     {
//         if(A[mid]==key)
//         {
//             return mid;
//         }
//         else if(A[mid]<key)
//         {
//             return binarysearch(A,mid+1,high,key);
//         }
//         else
//         {
//             return binarysearch(A,0,mid-1,key);
//         }
//     }
//     return -1;
    
// }

// int main()
// {
//     int arr[MAX] = {1,2,4,5,6,9};
//     int n = 6;
//     int x = binarysearch(arr,0,n-1,0);
//     (x == -1) ? printf("Element not found") : printf("Element found at %d",x);
// }