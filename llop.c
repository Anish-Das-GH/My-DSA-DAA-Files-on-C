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
        printf("LL : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct node* insertbeg(struct node* head,int data)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> next = head;
    ptr -> data = data;
    return ptr;

}

struct node* insertend(struct node* head,int data)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> data = data;
    struct node* p = head;
    while (p->next != NULL)
    {
        p=p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
    
}

struct node* insertindex(struct node* head,int data,int index)
{ struct node* ptr = (struct node*)malloc(sizeof(struct node));
  struct node* p = head;
  ptr ->data = data;
  int i=0;
  while(i!=index-1)
  {
    p=p->next;
    i++;
  }
  ptr->next = p-> next;
  p->next = ptr;
  return head;

}

struct node* delbeg(struct node* head)
{
    struct node* ptr;
    ptr = head;
    head = head -> next;
    free(ptr);
    return head;
    
}
struct node* delatIndex(struct node*head, int index){
    struct node * p= head;
    struct node * q = head->next;
    for(int i=0;i<index-1;i++){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}
struct node* delatEnd(struct node*head){
    struct node * p= head;
    struct node * q = head->next;
    while(q->next!=NULL){
      p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}

int main()
{
    struct node* head;
    struct node* second;
    struct node* third;

head = (struct node*)malloc(sizeof(struct node));
second = (struct node*)malloc(sizeof(struct node));
third = (struct node*)malloc(sizeof(struct node));

head->data = 67;
head->next = second;

second->data = 89;
second->next= third;

third->data = 10;
third->next = NULL;

// head = insertbeg(head,90);
// head = insertend(head,69);
// head = insertindex(head,108,1);
// head = delbeg(head);
// head=delatFirst(head);
// head=delatIndex(head,2);
traversal(head);

    return 0;
}