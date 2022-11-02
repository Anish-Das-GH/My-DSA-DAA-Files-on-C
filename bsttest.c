#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node* left;
struct node* right;

};

struct node* createroot(int data)
{
    struct node* root;
    root = (struct node*)malloc(sizeof(struct node));
    root ->data = data;
    root ->left = NULL;
    root ->right = NULL;
    return root;
    
}
void inorder(struct node* root)
{
    if (root!=NULL)
    {inorder(root->left);
    printf(" %d ",root->data);
    inorder(root->right);
    
    }
    
    

}
int main()
{
    struct node* p = createroot(10);
    struct node* p1 = createroot(12);
    struct node* p2 = createroot(15);

    p->left = p1;
    p->right = p2;

    inorder(p);

}