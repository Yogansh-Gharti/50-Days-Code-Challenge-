#include <stdio.h>

#define MAX 100

struct Edge
{
    int src, dest, weight;
};

struct Edge edge[MAX];

int parent[MAX];

void makeSet(int n)
{
    for(int i = 0; i < n; i++)
        parent[i] = i;
}

int find(int x)
{
    if(parent[x] != x)
        parent[x] = find(parent[x]);

    return parent[x];
}

void unionSet(int x, int y)
{
    parent[find(x)] = find(y);
}

void sortEdges(int e)
{
    for(int i = 0; i < e - 1; i++)
    {
        for(int j = 0; j < e - i - 1; j++)
        {
            if(edge[j].weight > edge[j + 1].weight)
            {
                struct Edge temp = edge[j];
                edge[j] = edge[j + 1];
                edge[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int vertices, edges;

    printf("Enter Number of Locations : ");
    scanf("%d", &vertices);

    printf("Enter Number of Roads : ");
    scanf("%d", &edges);

    printf("\nEnter Source Destination Cost\n");

    for(int i = 0; i < edges; i++)
    {
        scanf("%d%d%d",
              &edge[i].src,
              &edge[i].dest,
              &edge[i].weight);
    }

    sortEdges(edges);

    makeSet(vertices);

    int totalCost = 0;

    printf("\nMinimum Delivery Network\n\n");

    for(int i = 0; i < edges; i++)
    {
        int u = edge[i].src;
        int v = edge[i].dest;

        if(find(u) != find(v))
        {
            printf("%d -- %d  Cost = %d\n",
                   u,
                   v,
                   edge[i].weight);

            totalCost += edge[i].weight;

            unionSet(u, v);
        }
    }

    printf("\nTotal Minimum Cost = %d\n", totalCost);

    return 0;
}
