#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int roll;
    char name[50];
    float cgpa;
    int height;

    struct Node *left;
    struct Node *right;
};

int height(struct Node *node)
{
    return node ? node->height : 0;
}

int max(int a,int b)
{
    return (a>b)?a:b;
}

struct Node* createNode(int roll,char name[],float cgpa)
{
    struct Node *node=(struct Node*)malloc(sizeof(struct Node));

    node->roll=roll;
    strcpy(node->name,name);
    node->cgpa=cgpa;

    node->height=1;

    node->left=node->right=NULL;

    return node;
}

struct Node* rightRotate(struct Node *y)
{
    struct Node *x=y->left;
    struct Node *t=x->right;

    x->right=y;
    y->left=t;

    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;

    return x;
}

struct Node* leftRotate(struct Node *x)
{
    struct Node *y=x->right;
    struct Node *t=y->left;

    y->left=x;
    x->right=t;

    x->height=max(height(x->left),height(x->right))+1;
    y->height=max(height(y->left),height(y->right))+1;

    return y;
}

int getBalance(struct Node *node)
{
    if(node==NULL)
        return 0;

    return height(node->left)-height(node->right);
}

struct Node* insert(struct Node *node,int roll,char name[],float cgpa)
{
    if(node==NULL)
        return createNode(roll,name,cgpa);

    if(roll<node->roll)
        node->left=insert(node->left,roll,name,cgpa);

    else if(roll>node->roll)
        node->right=insert(node->right,roll,name,cgpa);

    else
        return node;

    node->height=1+max(height(node->left),height(node->right));

    int balance=getBalance(node);

    if(balance>1 && roll<node->left->roll)
        return rightRotate(node);

    if(balance<-1 && roll>node->right->roll)
        return leftRotate(node);

    if(balance>1 && roll>node->left->roll)
    {
        node->left=leftRotate(node->left);
        return rightRotate(node);
    }

    if(balance<-1 && roll<node->right->roll)
    {
        node->right=rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

struct Node* search(struct Node *root,int roll)
{
    if(root==NULL || root->roll==roll)
        return root;

    if(roll<root->roll)
        return search(root->left,roll);

    return search(root->right,roll);
}

void inorder(struct Node *root)
{
    if(root==NULL)
        return;

    inorder(root->left);

    printf("%d  %s  %.2f\n",
           root->roll,
           root->name,
           root->cgpa);

    inorder(root->right);
}

int main()
{
    struct Node *root=NULL;

    root=insert(root,105,"Rahul",8.5);
    root=insert(root,101,"Aman",9.1);
    root=insert(root,110,"Priya",8.9);
    root=insert(root,103,"Riya",8.3);
    root=insert(root,108,"Karan",7.9);

    printf("Student Database\n\n");

    inorder(root);

    int roll=103;

    struct Node *student=search(root,roll);

    if(student)
    {
        printf("\nFound\n");
        printf("Roll : %d\n",student->roll);
        printf("Name : %s\n",student->name);
        printf("CGPA : %.2f\n",student->cgpa);
    }
    else
    {
        printf("Student Not Found\n");
    }

    return 0;
}
