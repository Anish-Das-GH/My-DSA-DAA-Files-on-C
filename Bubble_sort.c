#include<stdio.h>
#define MAX 100
int main()
{
    int n,i,j,x,a[MAX];
    printf("\n Enter the size of array :");
    scanf("%d",&n);
    printf("\n Enter the content of the array:");
    for(i=0;i<n;i++)
    {
      scanf("%d",&a[i]);
    }
    for(i=0;i<(n-1);i++)
      {
      for(j=i+1;j<n;j++)
       {
         if (a[i]>a[j])
         { 
           x = a[i];
           a[i]=a[j];
           a[j]=x;
         }
      }
      }
       printf("\nThe sorted array in Ascending order : ");
     for(i=0;i<n;i++)
      printf(" %d ",a[i]);
     


}
