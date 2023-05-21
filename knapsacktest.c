#include <stdio.h>
#define MAX 100
void knapsack(int n,float profit[],float weight[],float capacity)
{
    int i,j;
    float x[n];
    float u = capacity;
    float tp=0;
    for(i=0;i<n;i++)
    {
        x[i]=0;

    }
    for(i=0;i<n;i++)
    {
        if(weight[i]>u)
        {
            break;
        }
        else
        {
            x[i]=1.0;
            tp = tp-profit[i];
            u = u-weight[i];
        }
    }
    if(i<n)
    {
        x[i] = u/weight[i];

    }
    tp = tp + (x[i] * profit[i]);

    printf("Total profit : %f",tp);
}
int main()
{
    int i,j,n;
    float temp, profit[MAX],weight[MAX],ratio[MAX],capacity;
    
   printf("\nEnter the no of objects : ");
   scanf("%d", &n);

   printf("\nEnter the weights each object: ");
   for (i = 0; i < n; i++) {
      scanf("%f", &weight[i]);
   }
   printf("\nEnter the profits  each object: ");
   for (i = 0; i < n; i++) {
      scanf("%f", &profit[i]);
   }

   printf("\nEnter the capacity of knapsack: ");
   scanf("%f", &capacity);

for ( i = 0; i < n; i++)
{
    ratio[i] = profit[i] / weight[i];
}
for(i=0;i<n;i++)
{
    for(j=i+1;j<n;j++)
    {
        if(ratio[i]<ratio[j])
        {
            temp = ratio[i];
            ratio[i] = ratio[j];
            ratio[j] = temp;

            temp = profit[i];
            profit[i] = profit[j];
            profit[j] = temp;

            temp = weight[i];
            weight[i] = weight[j];
            weight[j] = temp;
        }
    }
}

printf("\nratio : ");
   for(i=0;i<n;i++)
   {
       printf(" %f ",ratio[i]);
   }

   knapsack(n,profit,weight,capacity);

}