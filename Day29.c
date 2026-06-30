#include <stdio.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int parent[MAX];
int queue[MAX];

int vertices;

void addConnection(int u,int v)
{
    graph[u][v]=1;
    graph[v][u]=1;
}

void displayGraph()
{
    printf("\nAdjacency Matrix\n\n");

    for(int i=0;i<vertices;i++)
    {
        for(int j=0;j<vertices;j++)
        {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}

void shortestPath(int start,int end)
{
    int front=0,rear=0;

    for(int i=0;i<vertices;i++)
    {
        visited[i]=0;
        parent[i]=-1;
    }

    visited[start]=1;
    queue[rear++]=start;

    while(front<rear)
    {
        int current=queue[front++];

        if(current==end)
            break;

        for(int i=0;i<vertices;i++)
        {
            if(graph[current][i] && !visited[i])
            {
                visited[i]=1;
                parent[i]=current;
                queue[rear++]=i;
            }
        }
    }

    if(!visited[end])
    {
        printf("\nNo Route Found.\n");
        return;
    }

    int path[MAX];
    int count=0;

    for(int v=end;v!=-1;v=parent[v])
        path[count++]=v;

    printf("\nShortest Route:\n");

    for(int i=count-1;i>=0;i--)
    {
        printf("Station %d",path[i]);

        if(i!=0)
            printf(" -> ");
    }

    printf("\n");
    printf("Stations Travelled : %d\n",count-1);
}

int main()
{
    int edges;

    printf("Enter Number of Stations : ");
    scanf("%d",&vertices);

    printf("Enter Number of Connections : ");
    scanf("%d",&edges);

    printf("\nEnter Connections (u v)\n");

    for(int i=0;i<edges;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        addConnection(u,v);
    }

    int choice;

    while(1)
    {
        printf("\n====== SMART METRO ======\n");
        printf("1.Display Network\n");
        printf("2.Find Shortest Route\n");
        printf("3.Exit\n");

        printf("Choice : ");
        scanf("%d",&choice);

        if(choice==1)
        {
            displayGraph();
        }
        else if(choice==2)
        {
            int s,d;

            printf("Source Station : ");
            scanf("%d",&s);

            printf("Destination Station : ");
            scanf("%d",&d);

            shortestPath(s,d);
        }
        else
        {
            break;
        }
    }

    return 0;
}
