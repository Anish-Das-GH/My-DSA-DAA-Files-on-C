#include<stdio.h>
#include<malloc.h>

struct node{
struct node* left;
struct node* right;
int data;


};
struct node* createroot(int data)
{
    struct node* root;
    root=(struct node*)malloc(sizeof(struct node));
    root->data = data;

}
int main()
{

}