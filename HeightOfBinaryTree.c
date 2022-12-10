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
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;

}

int Maxheight(struct node* root)
{
    if(root==NULL)
        return 0;
    else
    {
        int lheight = Maxheight(root->left);
        int rheight = Maxheight(root->right);
        if (lheight>rheight)
        {
            return lheight+1;
        }
        else
        {
            return rheight+1;
        }
        
    }
}

void preordertrav(struct node* root)
{
    if(root!=NULL)
    {
        printf(" %d ",root->data);
        preordertrav(root->left);
        preordertrav(root->right);

    }
}

int main()
{
    struct node* p=createroot(10);
    struct node* p1=createroot(8);
    struct node* p2=createroot(16);
    struct node* p3=createroot(5);
    struct node* p4=createroot(11);
    struct node* p5=createroot(15);
    struct node* p6=createroot(40);

    p->left = p1;
    p->right = p2;
    p1 -> left = p3;
    p1 -> right = p4;
    p2 -> left = p5;
    p2 -> right = p6;
    
    printf("\n Preorder Traversal : ");
    preordertrav(p);
    
    printf("\n Height of tree is %d", Maxheight(p));
  
    return 0;
}