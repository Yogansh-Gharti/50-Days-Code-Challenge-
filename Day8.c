#include <stdio.h>

#define SIZE 10

struct Element
{
    int data;
    int priority;
};

struct Element queue[SIZE];
int count = 0;

void enqueue(int data, int priority)
{
    if (count == SIZE)
    {
        printf("Priority Queue Overflow\n");
        return;
    }

    int i = count - 1;

    while (i >= 0 && queue[i].priority > priority)
    {
        queue[i + 1] = queue[i];
        i--;
    }

    queue[i + 1].data = data;
    queue[i + 1].priority = priority;

    count++;
}

void dequeue()
{
    if (count == 0)
    {
        printf("Priority Queue Underflow\n");
        return;
    }

    printf("Dequeued: %d\n", queue[0].data);

    for (int i = 0; i < count - 1; i++)
    {
        queue[i] = queue[i + 1];
    }

    count--;
}

void display()
{
    if (count == 0)
    {
        printf("Priority Queue is Empty\n");
        return;
    }

    printf("Element\tPriority\n");

    for (int i = 0; i < count; i++)
    {
        printf("%d\t%d\n", queue[i].data, queue[i].priority);
    }
}

int main()
{
    enqueue(100, 3);
    enqueue(200, 1);
    enqueue(300, 2);
    enqueue(400, 0);

    display();

    dequeue();

    printf("\nAfter Dequeue:\n");

    display();

    return 0;
}
