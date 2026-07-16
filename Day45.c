#include <stdio.h>

#define MAX 100

int parent[MAX];
int rankArr[MAX];

void makeSet(int n)
{
    for(int i = 0; i < n; i++)
    {
        parent[i] = i;
        rankArr[i] = 0;
    }
}

int find(int x)
{
    if(parent[x] != x)
        parent[x] = find(parent[x]);

    return parent[x];
}

void unionSet(int x, int y)
{
    int px = find(x);
    int py = find(y);

    if(px == py)
    {
        printf("Already Connected.\n");
        return;
    }

    if(rankArr[px] < rankArr[py])
        parent[px] = py;

    else if(rankArr[px] > rankArr[py])
        parent[py] = px;

    else
    {
        parent[py] = px;
        rankArr[px]++;
    }

    printf("Stations Connected Successfully.\n");
}

void checkConnection(int x, int y)
{
    if(find(x) == find(y))
        printf("Stations are Connected.\n");
    else
        printf("Stations are NOT Connected.\n");
}

int main()
{
    int n;

    printf("Enter Number of Stations : ");
    scanf("%d",&n);

    makeSet(n);

    int choice;

    while(1)
    {
        printf("\n===== RAILWAY NETWORK =====\n");
        printf("1. Connect Stations\n");
        printf("2. Check Connectivity\n");
        printf("3. Exit\n");

        printf("Choice : ");
        scanf("%d",&choice);

        if(choice==1)
        {
            int u,v;

            printf("Enter Two Stations : ");
            scanf("%d%d",&u,&v);

            unionSet(u,v);
        }
        else if(choice==2)
        {
            int u,v;

            printf("Enter Two Stations : ");
            scanf("%d%d",&u,&v);

            checkConnection(u,v);
        }
        else
            break;
    }

    return 0;
}
