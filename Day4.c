#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    stack[++top] = value;
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }

    printf("Popped: %d\n", stack[top--]);
}

void peek()
{
    if (top == -1)
    {
        printf("Stack is Empty\n");
        return;
    }

    printf("Top Element: %d\n", stack[top]);
}

void display()
{
    if (top == -1)
    {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack Elements:\n");

    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
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
