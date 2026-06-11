#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(struct Node *node)
{
    if (node == NULL)
        return 0;

    return node->height;
}

struct Node *createNode(int value)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));

    node->data = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}

struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(struct Node *node)
{
    if (node == NULL)
        return 0;

    return height(node->left) - height(node->right);
}

struct Node *insert(struct Node *node, int value)
{
    if (node == NULL)
        return createNode(value);

    if (value < node->data)
        node->left = insert(node->left, value);
    else if (value > node->data)
        node->right = insert(node->right, value);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && value < node->left->data)
        return rightRotate(node);

    if (balance < -1 && value > node->right->data)
        return leftRotate(node);

    if (balance > 1 && value > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && value < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    struct Node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("Inorder Traversal:\n");
    inorder(root);

    printf("\n");

    return 0;
}
