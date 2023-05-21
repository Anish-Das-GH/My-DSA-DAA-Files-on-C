#include<stdio.h>
void main()
{
    int n,i,j,min,a,b,u,v,mincost=0;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);
    int cost[n+1][n+1];
    printf("\nEnter the adjacency matrix :\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            scanf("%d",&cost[i][j]);
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    }
    int visited[n+1];
    for(i=1;i<=n;i++)
        visited[i]=0;
    visited[1]=1;
    int ne=1;
    while(ne<n)
    {
        for(i=1,min=999;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]<min)
                {
                    if(visited[i]!=0)
                    {
                        min=cost[i][j];
                        a=u=i;
                        b=v=j;
                    }
                }
            }
        }
        if(visited[u]==0 || visited[v]==0)
        {
            printf("\n%d\t%d\t%d\t%d",ne++,a,b,min);
            mincost+=min;
            visited[b]=1;
        }
        cost[a][b]=cost[b][a]=999;
    }
    printf("\nMinimum cost is : %d",mincost);
}
