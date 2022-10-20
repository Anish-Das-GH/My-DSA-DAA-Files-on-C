#include<stdio.h>
int main()
{   int i;
    int *ptr;

    int a[10]={2,3,4,5,6,7,8};
    ptr=&a[6];
    for(i=0;i<7;i++)
    {
        printf("%d",*ptr);
        ptr--;
    }






    return 0;
}