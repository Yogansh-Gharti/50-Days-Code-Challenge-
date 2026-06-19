#include <stdio.h>

#define V 5

void addEdge(int graph[V][V], int src, int dest)
{
    graph[src][dest] = 1;
    graph[dest][src] = 1;
}

void displayGraph(int graph[V][V])
{
    printf("Adjacency Matrix:\n\n");

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int graph[V][V] = {0};

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    displayGraph(graph);

    return 0;
}
