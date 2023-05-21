#include<stdio.h>
void display(int matrix[3][3], int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",matrix[i][j]);
        printf("\n");
    }
}

int minimum(int a, int b)
{
    if(a<=b)
        return a;
    else
        return b;
}

void main()
{
    int n,i,j,k;
    printf("Enter the number of vertices : ");
    scanf("%d",&n);
    int adj[n][n];
    printf("\nEnter the adjacency matrix :\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&adj[i][j]);
    }
    printf("\n\nAdjacency matrix is : \n");
    display(adj,n);
    int path[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(adj[i][j]==999)
                path[i][j]=999;
            else
                path[i][j]=adj[i][j];
        }
    }
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                path[i][j]=minimum(path[i][j],(path[i][k]+path[k][j]));
            }
        }
    }
    printf("\n\nPath Matrix is :\n");
    display(path,n);
}
