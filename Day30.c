#include <stdio.h>

#define MAX 10
#define INF 999999

int graph[MAX][MAX];

void dijkstra(int n, int source)
{
    int dist[MAX];
    int visited[MAX];

    for(int i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[source] = 0;

    for(int count = 0; count < n - 1; count++)
    {
        int min = INF;
        int u = -1;

        for(int i = 0; i < n; i++)
        {
            if(!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        if(u == -1)
            break;

        visited[u] = 1;

        for(int v = 0; v < n; v++)
        {
            if(graph[u][v] != 0 &&
               !visited[v] &&
               dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("\nShortest Distance From Restaurant %d\n\n", source);

    for(int i = 0; i < n; i++)
    {
        printf("To Location %d : %d\n", i, dist[i]);
    }
}

int main()
{
    int n;

    printf("Enter Number of Locations : ");
    scanf("%d", &n);

    printf("\nEnter Weighted Adjacency Matrix\n");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    int source;

    printf("\nEnter Restaurant Location : ");
    scanf("%d", &source);

    dijkstra(n, source);

    return 0;
}
