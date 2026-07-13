#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct Node
{
    int vertex;
    struct Node *next;
}Node;

Node *graph[MAX];

void addEdge(int u,int v)
{
    Node *temp=(Node*)malloc(sizeof(Node));
    temp->vertex=v;
    temp->next=graph[u];
    graph[u]=temp;

    temp=(Node*)malloc(sizeof(Node));
    temp->vertex=u;
    temp->next=graph[v];
    graph[v]=temp;
}

void bfs(int source,int destination,int vertices)
{
    int visited[MAX]={0};
    int parent[MAX];
    int queue[MAX];

    for(int i=0;i<vertices;i++)
        parent[i]=-1;

    int front=0,rear=0;

    queue[rear++]=source;
    visited[source]=1;

    while(front<rear)
    {
        int current=queue[front++];

        if(current==destination)
            break;

        Node *temp=graph[current];

        while(temp)
        {
            if(!visited[temp->vertex])
            {
                visited[temp->vertex]=1;
                parent[temp->vertex]=current;
                queue[rear++]=temp->vertex;
            }

            temp=temp->next;
        }
    }

    if(!visited[destination])
    {
        printf("\nNo Route Available.\n");
        return;
    }

    int path[MAX];
    int count=0;

    for(int v=destination;v!=-1;v=parent[v])
        path[count++]=v;

    printf("\nShortest Route\n\n");

    for(int i=count-1;i>=0;i--)
    {
        printf("Router %d",path[i]);

        if(i)
            printf(" -> ");
    }

    printf("\n\nTotal Hops : %d\n",count-1);
}

int main()
{
    int vertices,edges;

    printf("Enter Number of Routers : ");
    scanf("%d",&vertices);

    printf("Enter Number of Connections : ");
    scanf("%d",&edges);

    printf("\nEnter Connections\n");

    for(int i=0;i<edges;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        addEdge(u,v);
    }

    int source,destination;

    printf("\nSource Router : ");
    scanf("%d",&source);

    printf("Destination Router : ");
    scanf("%d",&destination);

    bfs(source,destination,vertices);

    return 0;
}
