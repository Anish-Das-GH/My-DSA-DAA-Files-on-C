#include <stdio.h>
#define MAX 100
int min(int a,int b)
{
    if(a<b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int main()
{
    int profit[MAX],n,job[MAX],deadline[MAX],i,j,temp,temp1,temp2;
    printf("Enter no of jobs : ");
    scanf("%d",&n);
    printf("Enter job id : ");
    for ( i = 1; i <= n; i++)
    {
        scanf("%d",&job[i]);
    }
     printf("Enter profits : ");
    for ( i = 1; i <= n; i++)
    {
        scanf("%d",&profit[i]);
    }
    
     printf("Enter Deadlines : ");
    for ( i = 1; i <= n; i++)
    {
        scanf("%d",&deadline[i]);
    }
    
    // Sort the Profits

    for ( i = 1; i <= n; i++)
    {
        for ( j = i+1; j <= n; j++)
        {
            if (profit[i]>profit[j])
            {
                temp = profit[i];
            profit[i] = profit[j];
            profit[j] = temp;

            temp1 = deadline[i];
            deadline[i] = deadline[j];
            deadline[j] = temp1;

            temp2 = job[i];
            job[i] = job[j];
            job[j] = temp2;
            }
            
            
        }
        
    }

    printf("Sorted Profits : ");
    for ( i = 1; i <= n; i++)
    {
        printf(" %d ",profit[i]);
    }
    int max = 0;
    for ( i = 1; i <= n; i++)
    {
        if(deadline[i]>max)
        {
            max = deadline[i];
        }
    }
    printf("\n max deadline : %d ",max);
    
    int timeslot[max];
    for(i=1;i<=max;i++)
    {
        timeslot[i]=-1;
    }
    int k;
    int totalprofit = 0;
    for(i=1;i<=n;i++)
    {
        k = min(max,deadline[i]);
        while (k>=1)
        {
            timeslot[k] = job[i];
            totalprofit = totalprofit + profit[i];
            break;
        }
        k = k-1;
        
    }
    printf("The total profit is  : %d ",totalprofit);
    for ( i = 1; i <= max; i++)
    {
        printf("%d",timeslot[i]);
    }
    return 0;
}