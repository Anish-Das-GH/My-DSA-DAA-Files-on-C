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