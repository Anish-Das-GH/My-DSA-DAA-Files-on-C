#include<stdio.h>
int main()
{  int i,n,pos,size,a[100],num;
printf("\nEnter size");
scanf("%d",&size);
printf("Enter elements of the array :");
for ( i = 0; i < size; i++)
{
    scanf("%d",&a[i]);
}
printf("\nEnter the position where u want to insert the element");
scanf("%d",&pos);
printf("\nEnter the number :");
scanf("%d",&num);
for ( i = size-1; i >=pos; i--)
{
   a[i+1]=a[i];
}
a[pos-1]=num;
size++;
for ( i = 0; i < size; i++)
{
    printf(" %d ",a[i]);
}







    return 0;
}