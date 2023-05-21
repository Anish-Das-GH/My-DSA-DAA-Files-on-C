#include <stdio.h>
#include <stdlib.h>

int main(){
	int n,i,j,min,a,b,u,v,mincost=0;
	printf("\nEnter the number of nodes:");
	scanf("%d",&n);
	int cost[n+1][n+1];
	printf("\nEnter the adjacency matrix:");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&cost[i][j]);
	}
}
for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(cost[i][j]==0)
				cost[i][j]=999;
			}}
int ne=1;
int parent[n+1];
for(i=0;i<=n;i++)
	parent[i]=0;
while(ne<n){
	for(i=1,min=999;i<=n;i++){
		for(j=1;j<=n;j++){
			if(cost[i][j]<min){
				min=cost[i][j];
				a=u=i;
				b=v=j;
			}
		}
	}
	while(parent[u]!=0)
		u=parent[u];
	while(parent[v]!=0)
		v=parent[v];
	if(u!=v){
		ne++;
		printf("\n%d\t%d\t%d\t%d",ne,a,b,min);
		mincost+=min;
		parent[v]=u;
	}
	cost[a][b]=cost[b][a]=999;
	}
	printf("\nMinimum Cost:%d",mincost);
}
