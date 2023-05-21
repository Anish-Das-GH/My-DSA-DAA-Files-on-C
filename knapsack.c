#include <stdio.h>
#define MAX 100
void knapsack(int n,float weight[],float profit[],float capacity)
{
   float x[n];
   float tp = 0;
   int i, j;
   float u = capacity;
   for (i = 0; i < n; i++)
      {
          x[i] = 0;
      }
   for (i = 0; i < n; i++) 
   {
      if (weight[i] > u)
         break;
      else {
         x[i] = 1.0;
         tp = tp + profit[i];
         u = u - weight[i];
      }
   }

   if (i < n)
    {
        x[i] = u / weight[i];
    }

   tp = tp + (profit[i] * x[i]);
   printf("\nMaximum profit is : %f",tp);

}
int main()
{
   float weight[MAX], profit[MAX], capacity;
   int num, i, j;
   float ratio[MAX], temp;

   printf("\nEnter the no of objects : ");
   scanf("%d", &num);

   printf("\nEnter the weights each object: ");
   for (i = 0; i < num; i++) {
      scanf("%f", &weight[i]);
   }
   printf("\nEnter the profits  each object: ");
   for (i = 0; i < num; i++) {
      scanf("%f", &profit[i]);
   }

   printf("\nEnter the capacity of knapsack: ");
   scanf("%f", &capacity);

   for (i = 0; i < num; i++) {
      ratio[i] = profit[i] / weight[i];
   }

   for (i = 0; i < num; i++) {
      for (j = i + 1; j < num; j++) {
         if (ratio[i] < ratio[j]) {
            temp = ratio[j];
            ratio[j] = ratio[i];
            ratio[i] = temp;

            temp = weight[j];
            weight[j] = weight[i];
            weight[i] = temp;

            temp = profit[j];
            profit[j] = profit[i];
            profit[i] = temp;
         }
      }
   }
   printf("\nratio : ");
   for(i=0;i<num;i++)
   {
       printf(" %f ",ratio[i]);
   }

   knapsack(num, weight, profit, capacity);

}




