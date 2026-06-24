#include <stdio.h>
#include <stdlib.h>

struct Edge
{
    int src;
    int dest;
    int weight;
};

int parent[100];

int find(int i)
{
    while (parent[i] != i)
        i = parent[i];

    return i;
}

void unionSet(int a, int b)
{
    int rootA = find(a);
    int rootB = find(b);

    parent[rootA] = rootB;
}

void sortEdges(struct Edge edges[], int e)
{
    for (int i = 0; i < e - 1; i++)
    {
        for (int j = 0; j < e - i - 1; j++)
        {
            if (edges[j].weight > edges[j + 1].weight)
            {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

void kruskal(struct Edge edges[], int vertices, int edgesCount)
{
    sortEdges(edges, edgesCount);

    for (int i = 0; i < vertices; i++)
        parent[i] = i;

    printf("Edges in MST:\n");

    int totalCost = 0;

    for (int i = 0; i < edgesCount; i++)
    {
        int srcRoot = find(edges[i].src);
        int destRoot = find(edges[i].dest);

        if (srcRoot != destRoot)
        {
            printf("%d -- %d == %d\n",
                   edges[i].src,
                   edges[i].dest,
                   edges[i].weight);

            totalCost += edges[i].weight;

            unionSet(srcRoot, destRoot);
        }
    }

    printf("Total Cost = %d\n", totalCost);
}

int main()
{
    struct Edge edges[] =
    {
        {0,1,4},
        {0,2,3},
        {1,2,1},
        {1,3,2},
        {2,3,4},
        {3,4,2},
        {4,5,6}
    };

    int vertices = 6;
    int edgesCount = sizeof(edges) / sizeof(edges[0]);

    kruskal(edges, vertices, edgesCount);

    return 0;
}
