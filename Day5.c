#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }

    struct Node *temp = top;

    printf("Popped: %d\n", top->data);

    top = top->next;

    free(temp);
}

void peek()
{
    if (top == NULL)
    {
        printf("Stack is Empty\n");
        return;
    }

    printf("Top Element: %d\n", top->data);
}

void display()
{
    if (top == NULL)
    {
        printf("Stack is Empty\n");
        return;
    }

    struct Node *temp = top;

    printf("Stack Elements:\n");

    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);

    display();

    peek();

    pop();

    display();

    return 0;
}
