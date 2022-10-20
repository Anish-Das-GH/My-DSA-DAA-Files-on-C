#include <stdio.h>
#include <malloc.h>

struct node{
    struct node* left;
    struct node* right;
    int data;
};

struct node* createroot(int data)
{
struct node* root;
root = (struct node*)malloc(sizeof(struct node));
root->data = data;
root->left = NULL;
root->right= NULL;
return root;

}

int findmin(struct node* root)
{
    if(root==NULL)
    {
        printf("Tree is empty");

    }
    else
        {
            while (root->left!=NULL)
            {
               root = root->left;

                
            }
            printf("\n Minimum Element : %d ",root->data);
        }
}

int findmax(struct node* root)
{
    if(root==NULL)
    {
        printf("Tree is empty");

    }
    else
        {
            while (root->right!=NULL)
            {
               root = root->right;

                
            }
            printf("\n Maximum Element : %d ",root->data);
        }
}
void preordertrav(struct node* root)
{
    if(root!=NULL)
    {   printf(" %d ",root->data);
        preordertrav(root->left);
        preordertrav(root->right);
    }
}

void inordertrav(struct node* root)
{
    if(root!=NULL)
    {   inordertrav(root->left);
        printf(" %d ",root->data);
        inordertrav(root->right);
    }
}

void postordertrav(struct node* root)
{
    if(root!=NULL)
    {   postordertrav(root->left);
        postordertrav(root->right);
        printf(" %d ",root->data);
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
    
    printf("\n Inorder Traversal : ");
    inordertrav(p);
    
    printf("\n Postorder Traversal : ");
    postordertrav(p);
    
    findmin(p);
    findmax(p);

    return 0;

}
