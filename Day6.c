#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int value)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
        front = 0;

    queue[++rear] = value;
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        return;
    }

    printf("Dequeued: %d\n", queue[front++]);

    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
}

void peek()
{
    if (front == -1)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Front Element: %d\n", queue[front]);
}

void display()
{
    if (front == -1)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue Elements:\n");

    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    display();

    peek();

    dequeue();

    display();

    return 0;
}
