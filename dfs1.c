#include <stdio.h>
#include <stdlib.h>
#define max 4
int graph[][max]={{0,1,1,0},{1,0,0,1},{1,0,0,1},{0,1,1,0}};
void dfs(int visited[max],int src)
{
    visited[src]=1;
    printf("%d-->",src);
    for(int i=0;i<max;i++)
    {
        if(!visited[i] && graph[src][i])
            dfs(visited,i);
    }
}
int main()
{
    int visited[max];
    for(int i=0;i<max;i++)
        visited[i]=0;
    int src=0;
    dfs(visited,src);
    return 0;
}