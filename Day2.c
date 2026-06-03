#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtEnd(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    struct Node *temp = head;

    while (temp->next != NULL) 
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void displayForward()
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void displayBackward()
{
    struct Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }

    printf("NULL\n");
}

int main()
{
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);

    printf("Forward Traversal:\n");
    displayForward();

    printf("Backward Traversal:\n");
    displayBackward();

    return 0;
}
