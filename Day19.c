#include <stdio.h>

#define V 6

int queue[100];
int front = 0;
int rear = 0;

void bfs(int graph[V][V], int start)
{
    int visited[V] = {0};

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear)
    {
        int current = queue[front++];

        printf("%d ", current);

        for (int i = 0; i < V; i++)
        {
            if (graph[current][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main()
{
    int graph[V][V] =
    {
        {0,1,1,0,0,0},
        {1,0,0,1,1,0},
        {1,0,0,0,1,0},
        {0,1,0,0,0,1},
        {0,1,1,0,0,1},
        {0,0,0,1,1,0}
    };

    printf("BFS Traversal: ");

    bfs(graph, 0);

    printf("\n");

    return 0;
}
