#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define V 7
int min(int dist[V],int visited[V])
{
    int min=INT_MAX,min_index;
    for(int i=0;i<V;i++)
    {
        if(dist[i]<INT_MAX && !visited[i])
        {
            min=dist[i];
            min_index=i;
        }
    }
    return min_index;
}
void djkistra(int graph[V][V],int u)
{
    int dist[V],visited[V];
    for(int i=0;i<V;i++)
    {
        dist[i]=INT_MAX;
        visited[i]=0;
    }
    dist[u]=0;
    for(int count=0;count<V-1;count++)
    {
        int s=min(dist,visited);
        visited[s]=1;
        for(int i=0;i<V;i++)
        {
            if(!visited[i] && graph[s][i] && (dist[s]!=INT_MAX) && (dist[s]+graph[s][i]<dist[i]))
                dist[i]=dist[s]+graph[s][i];
        }
    }
    for(int i=0;i<V;i++)
        printf("%d-->",dist[i]);
}
int main()
{
    int graph[V][V]={{0,0,1,2,0,0,0},
                     {0,0,2,0,0,3,0},
                     {1,2,0,1,3,0,0},
                     {2,0,1,0,0,0,1},
                     {0,0,3,0,0,2,0},
                     {0,3,0,0,2,0,1},
                     {0,0,0,1,0,1,0}};
    int u=0;
    djkistra(graph,u);
    return 0;
}