#include <stdio.h>
#include <limits.h>

#define V 5

int minKey(int key[], int mstSet[])
{
    int min = INT_MAX;
    int minIndex = -1;

    for (int i = 0; i < V; i++)
    {
        if (mstSet[i] == 0 && key[i] < min)
        {
            min = key[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void printMST(int parent[], int graph[V][V])
{
    int totalCost = 0;

    printf("Edge\tWeight\n");

    for (int i = 1; i < V; i++)
    {
        printf("%d - %d\t%d\n", parent[i], i, graph[i][parent[i]]);
        totalCost += graph[i][parent[i]];
    }

    printf("Total Cost = %d\n", totalCost);
}

void primMST(int graph[V][V])
{
    int parent[V];
    int key[V];
    int mstSet[V];

    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet);

        mstSet[u] = 1;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] &&
                mstSet[v] == 0 &&
                graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main()
{
    int graph[V][V] =
    {
        {0,2,0,6,0},
        {2,0,3,8,5},
        {0,3,0,0,7},
        {6,8,0,0,9},
        {0,5,7,9,0}
    };

    primMST(graph);

    return 0;
}
