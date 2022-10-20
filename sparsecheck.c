#include<stdio.h>
int main ()
{
 int r,c,i,j,count=0;
 int arr[100][100];
 printf("Enter The Rows and cols of Matrix");
 scanf("%d %d",&r,&c);
 printf("Enter The elements");
 for (i = 0; i < r; i++)
 {
    for ( j = 0; j <c; j++)
    {
        scanf("%d",&arr[i][j]);
        if (arr[i][j]==0)
        {
            count++;
        }
        
    }
 }
    if(count > ((r*c)/2))  
        printf("Given matrix is a sparse matrix");  
    else  
        printf("Given matrix is not a sparse matrix");  
          
    return 0;  
    
 
 




    return 0;

}
