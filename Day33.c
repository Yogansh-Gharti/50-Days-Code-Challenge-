#include <stdio.h>
#include <stdlib.h>

#define MAX 20

struct Node
{
    int vertex;
    struct Node *next;
};

struct Node *graph[MAX];

struct Node* createNode(int v)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->vertex = v;
    temp->next = NULL;
    return temp;
}

void addFriend(int u,int v)
{
    struct Node *node = createNode(v);
    node->next = graph[u];
    graph[u] = node;

    node = createNode(u);
    node->next = graph[v];
    graph[v] = node;
}

int isFriend(int u,int v)
{
    struct Node *temp = graph[u];

    while(temp)
    {
        if(temp->vertex == v)
            return 1;

        temp = temp->next;
    }

    return 0;
}

void displayFriends(int user)
{
    printf("\nFriends of User %d\n",user);

    struct Node *temp = graph[user];

    while(temp)
    {
        printf("%d ",temp->vertex);
        temp = temp->next;
    }

    printf("\n");
}

void recommendFriends(int user,int totalUsers)
{
    int mutual[MAX]={0};

    struct Node *friendList = graph[user];

    while(friendList)
    {
        struct Node *friendsFriend = graph[friendList->vertex];

        while(friendsFriend)
        {
            int candidate = friendsFriend->vertex;

            if(candidate!=user && !isFriend(user,candidate))
            {
                mutual[candidate]++;
            }

            friendsFriend = friendsFriend->next;
        }

        friendList = friendList->next;
    }

    printf("\nRecommended Friends\n\n");

    int found=0;

    for(int i=0;i<totalUsers;i++)
    {
        if(mutual[i]>0)
        {
            printf("User %d (%d Mutual Friends)\n",i,mutual[i]);
            found=1;
        }
    }

    if(!found)
        printf("No Recommendations Available.\n");
}

int main()
{
    int users,edges;

    printf("Enter Number of Users : ");
    scanf("%d",&users);

    printf("Enter Friend Connections : ");
    scanf("%d",&edges);

    printf("\nEnter Pairs\n");

    for(int i=0;i<edges;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);

        addFriend(u,v);
    }

    int user;

    printf("\nEnter User ID : ");
    scanf("%d",&user);

    displayFriends(user);

    recommendFriends(user,users);

    return 0;
}
