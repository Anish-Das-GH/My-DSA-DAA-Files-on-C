#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* left;
    struct node* right;
    int data;
};

struct node* Createnode(int data)
{
    struct node* root;
    root = (struct node*)malloc(sizeof(struct node));
    root -> data = data;
    root ->left = NULL;
    root ->right = NULL;
};

void Inorder(struct node* root)
{
    if (root!=NULL)
    {
        Inorder(root->left);
        printf(" %d ",root->data);
        Inorder(root->right);
        
    }
    

}


int main(){

struct node* p1 = Createnode(10);
struct node* p2 = Createnode(23);
struct node* p3 = Createnode(26);

p1->left = p2;
p1->right = p3;
Inorder(p1);




    return 0;
}