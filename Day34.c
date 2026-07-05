#include <stdio.h>
#include <stdlib.h>

#define SIZE 4
#define HASH 100

typedef struct Node
{
    int page;
    struct Node *prev;
    struct Node *next;
}Node;

Node *head=NULL,*tail=NULL;
Node *map[HASH];
int count=0;

void moveToFront(Node *node)
{
    if(node==head)
        return;

    if(node->prev)
        node->prev->next=node->next;

    if(node->next)
        node->next->prev=node->prev;

    if(node==tail)
        tail=node->prev;

    node->prev=NULL;
    node->next=head;

    if(head)
        head->prev=node;

    head=node;

    if(tail==NULL)
        tail=head;
}

void insertFront(int page)
{
    Node *temp=(Node*)malloc(sizeof(Node));

    temp->page=page;
    temp->prev=NULL;
    temp->next=head;

    if(head)
        head->prev=temp;

    head=temp;

    if(tail==NULL)
        tail=temp;

    map[page]=temp;

    count++;
}

void removeLast()
{
    if(tail==NULL)
        return;

    map[tail->page]=NULL;

    Node *temp=tail;

    if(head==tail)
    {
        head=NULL;
        tail=NULL;
    }
    else
    {
        tail=tail->prev;
        tail->next=NULL;
    }

    free(temp);
    count--;
}

void accessPage(int page)
{
    if(map[page]!=NULL)
    {
        printf("Cache Hit\n");
        moveToFront(map[page]);
    }
    else
    {
        printf("Cache Miss\n");

        if(count==SIZE)
            removeLast();

        insertFront(page);
    }
}

void display()
{
    Node *temp=head;

    printf("\nCache : ");

    while(temp)
    {
        printf("%d ",temp->page);
        temp=temp->next;
    }

    printf("\n");
}

int main()
{
    int choice,page;

    while(1)
    {
        printf("\n1.Access Page\n2.Display Cache\n3.Exit\n");

        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Page : ");
                scanf("%d",&page);
                accessPage(page);
                break;

            case 2:
                display();
                break;

            case 3:
                return 0;
        }
    }
}
