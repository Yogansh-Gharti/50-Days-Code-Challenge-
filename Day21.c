#include <stdio.h>
#include <limits.h>

#define V 6

int minDistance(int dist[], int visited[])
{
    int min = INT_MAX;
    int minIndex;

    for (int v = 0; v < V; v++)
    {
        if (!visited[v] && dist[v] <= min)
        {
            min = dist[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    int visited[V];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, visited);

        visited[u] = 1;

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] &&
                graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Vertex\tDistance from Source\n");

    for (int i = 0; i < V; i++)
    {
        printf("%d\t%d\n", i, dist[i]);
    }
}

int main()
{
    int graph[V][V] =
    {
        {0,4,2,0,0,0},
        {4,0,1,5,0,0},
        {2,1,0,8,10,0},
        {0,5,8,0,2,6},
        {0,0,10,2,0,3},
        {0,0,0,6,3,0}
    };

    dijkstra(graph, 0);

    return 0;
}
