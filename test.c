#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int min(int a,int b)
{
    if(a <b)
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
    int i,j,k,max=0,n,temp;
    int profit[MAX],deadline[MAX],jobs[MAX];
    printf("Enter the no of jobs : ");
    scanf("%d",&n);
    printf("Enter the profits : ");
    for ( i = 1; i <= n; i++)
    {
        scanf("%d",&profit[i]);   
    }
    printf("Enter the job ids : ");
    for ( i = 1; i <= n; i++)
    {
        scanf("%d",&jobs[i]);   
    }
    printf("Enter the deadlines : ");
    for ( i = 1; i <= n; i++)
    {
        scanf("%d",&deadline[i]);   
    }
    for ( i = 1; i <= n; i++)
    {
        for ( j = i+1; i <=n; i++)
        {
           if(profit[i]>profit[j])
           {
            temp = profit[i];
            profit[i] = profit[j];
            profit[j] = profit[i];

            temp = jobs[i];
            jobs[i] = jobs[j];
            jobs[j] = temp;

            temp = deadline[i];
            deadline[i] = deadline[j];
            deadline[j] = temp;
           }
        }
        
    }
    
    for ( i = 1; i <= n; i++)
    {
        if(deadline[i]>max)
        {
            max = deadline[i];
        }
    }

    int timeslot[max];
    for ( i = 1; i <= max; i++)
    {
        timeslot[i] = -1;
    }
    int tp=0;
    for ( i = 1; i <=n; i++)
    {
        k = min(max,deadline[i]);
        while (k>=0)
        {
            timeslot[k]=jobs[i];
            tp = tp+profit[i];
            break;

        }
        k = k-1;
        
    }
    printf("timeslot : ");
    for(i=1;i<=max;i++)
    {
    printf(" %d ",timeslot[i]);
    }
    printf("Max profit : %d",tp);
    return 0;
}