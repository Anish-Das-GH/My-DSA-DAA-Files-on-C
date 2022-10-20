#include<stdio.h>
int stack[100],i,x,n,choice=0;
int top=-1;
void push(void);
void pop(void);
void peek(void);
void display(void);
int main()
{
printf("\nEnter The size of the stack:");
scanf("%d",&n);
printf("\nStack ADT operations ---");
printf("\n1.Push");
printf("\n2.Pop");
printf("\n3.peek");
printf("\n4.Display");
while (choice!=4)
{
    printf("\nEnter your choice ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
    push();
    break;

    case 2:
    pop();
    break;

    case 3:
    peek();
    break;

    case 4:
    display();
    break;
    
    default:
    printf("\nEnter Correct Choice !!!");
        break;
    }
   
  }

}

void push()
{
   if (top==n-1)
   {
    printf("\nOverflow condition");
   }
   else
   {
    printf("\nEnter the value to be pushed ");
    scanf("%d",&x);
    top++;
    stack[top]=x;

   }
}

void pop()
{
    if (top==-1)
    {
    printf("\nUnderflow Condition");
    }
    else
    {
    printf("\nPopped element : %d",stack[top]);
    top--;
    }
}

void peek()
{
    if (top==-1)
    {
    printf("\nUnderflow Condition");

    }
    else
    {
    printf("\nTop element: %d",stack[top]);
    }
}

void display()
{
    if (top==-1)
    {
    printf("\nStack is empty");
    }
    else
    {
     printf("\nStack elements :");
     for(i=top;i>=0;i--)
    {
    printf("\n%d",stack[i]);
   
    } 
    printf("\n Press Next Choice");
    }



}
