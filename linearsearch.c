#include <stdio.h>
#define MAX 100
int linearsearch(int A[],int key,int n)
{
    int i;
    for ( i = 0; i < n; i++)
    {
        if (A[i]==key)
        {
            return i;
        }
        
    }
    return -1;
    
}
int main()
{ 
    int arr[]={2,3,4,7,12,34,56};
    int size = 7;
    int index = linearsearch(arr,34,size);
    (index == -1) ? printf("Element not Found") : printf("The element was found at index %d \n",index);
    return 0;


}