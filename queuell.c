#include <stdio.h>
#include <malloc.h>

struct node *front = NULL;
struct node *rear = NULL;

struct node
{

    struct node *next;
    int data;
};

void enqueue(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if (front == NULL || rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue()
{
    struct node* temp;
    temp = front;
    if (front==NULL||rear==NULL)
    {
        printf("Queue is Empty !");
    }
    else
    {
        front=front->next;
        free(temp);
    }
    
}

void queuetrav(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    enqueue(34);
    enqueue(45);
    enqueue(67);
    enqueue(5);
    enqueue(40);
    queuetrav(front);
    dequeue();
    printf("After Dequeue\n");
    queuetrav(front);
    return 0;
}
