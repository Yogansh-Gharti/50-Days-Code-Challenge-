#include <stdio.h>
#include <stdlib.h>

#define V 5

struct Node
{
    int vertex;
    struct Node *next;
};

struct Node *graph[V];

struct Node *createNode(int vertex)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->vertex = vertex;
    newNode->next = NULL;

    return newNode;
}

void addEdge(int src, int dest)
{
    struct Node *newNode = createNode(dest);
    newNode->next = graph[src];
    graph[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph[dest];
    graph[dest] = newNode;
}

void displayGraph()
{
    for (int i = 0; i < V; i++)
    {
        struct Node *temp = graph[i];

        printf("Vertex %d: ", i);

        while (temp != NULL)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

int main()
{
    for (int i = 0; i < V; i++)
        graph[i] = NULL;

    addEdge(0, 1);
    addEdge(0, 4);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 3);
    addEdge(3, 4);

    displayGraph();

    return 0;
}
