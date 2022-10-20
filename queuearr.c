#include<stdio.h>
#define N 5
int queue[N];
int f=-1;
int r=-1;

void enqueue(int x)
{
    if (r==N-1)
    {
        printf("Overflow Condition");
    }
    else if(f==-1||r==-1)
    {
        f=r=0;
        queue[r]=x;

    }
    else{
        r++;
        queue[r]=x;
    }
    
}

void dequeue()
{
    if(f==-1||r==-1)
    {
        printf("QUeue EMPTY !!!");
    }
    else if (f==r)
    {
        f=r=-1;
    }
    else
    {
        f++;
    }
    
    

}
void display()
{
    int i;
    if (f == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = f; i <= r; i++)
        {
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}
int main()
{

enqueue(10);
enqueue(12);
dequeue();

display();





    return 0;
}