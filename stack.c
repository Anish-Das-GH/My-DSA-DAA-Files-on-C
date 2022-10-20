#include <stdio.h>
int i, n;
int top = -1;
int Max = 5;
int stack[100];
int push(int data)
{
    if (top == Max - 1)
    {
        printf("\nStack Overflow");
    }
    else
    {
        top++;
        stack[top] = data;
    }
}

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow");
    }
    else
    {
        printf("Popped Element : %d", stack[top]);
        top--;
    }
}

int display()
{
    if (top == -1)
    {
        printf("The stack u want to print is empty !!!!");
    }
    else
    {
        for (i = top; i >= 0; i--)
        {
            printf("Stack Elements :%d ", stack[i]);
            printf("\n");
        }
    }
}
int main()
{

    push(45);
    push(34);
    push(73);
    push(89);
    push(56);
    pop();
    display();

    return 0;
}