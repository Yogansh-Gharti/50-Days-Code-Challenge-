#include <stdio.h>
#include <string.h>

#define SIZE 5

typedef struct
{
    char message[100];
} Message;

Message queue[SIZE];

int front = -1;
int rear = -1;

int isFull()
{
    return (rear + 1) % SIZE == front;
}

int isEmpty()
{
    return front == -1;
}

void enqueue()
{
    if(isFull())
    {
        printf("\nQueue Overflow! Server Buffer Full.\n");
        return;
    }

    if(front == -1)
        front = 0;

    rear = (rear + 1) % SIZE;

    printf("Enter Message : ");
    scanf(" %[^\n]", queue[rear].message);

    printf("Message Sent Successfully.\n");
}

void dequeue()
{
    if(isEmpty())
    {
        printf("\nNo Pending Messages.\n");
        return;
    }

    printf("\nDelivered Message : %s\n", queue[front].message);

    if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
    }
}

void display()
{
    if(isEmpty())
    {
        printf("\nQueue Empty.\n");
        return;
    }

    printf("\nPending Messages\n");

    int i = front;

    while(1)
    {
        printf("- %s\n", queue[i].message);

        if(i == rear)
            break;

        i = (i + 1) % SIZE;
    }
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n===== CHAT SERVER =====\n");
        printf("1. Send Message\n");
        printf("2. Deliver Message\n");
        printf("3. Display Pending Messages\n");
        printf("4. Exit\n");

        printf("Choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}  
