
#include<stdio.h>
#include<stdlib.h>


struct node{
struct node* next;
int data;
};

void traversal(struct node* ptr)
{
    while(ptr!=NULL)
    {
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    }
}

struct node* merge(struct node* h1,struct node* h2)
{
    if (h1==NULL)
        return h2;
    if (h2==NULL)
        return h1;
  
    // start with the linked list
    // whose head data is the least
    if (h1->data < h2->data) {
        h1->next = merge(h1->next, h2);
        return h1;
    }
    else {
        h2->next = merge(h1, h2->next);
        return h2;
    }
}
  

int main()
{
    struct node* h1;
    struct node* p1;
    struct node* p2;

h1= (struct node*)malloc(sizeof(struct node));
p1= (struct node*)malloc(sizeof(struct node));
p2= (struct node*)malloc(sizeof(struct node));

h1->data = 10;
h1->next = p1;

p1->data = 16;
p1->next= p2;

p2->data = 28;
p2->next = NULL;

    struct node* h2;
    struct node* p3;
    struct node* p4;

h2= (struct node*)malloc(sizeof(struct node));
p3= (struct node*)malloc(sizeof(struct node));
p4= (struct node*)malloc(sizeof(struct node));

h2->data = 21;
h2->next = p3;

p3->data = 34;
p3->next= p4;

p4->data = 45;
p4->next = NULL;

merge(h1,h2);
traversal(h1);

    return 0;
}