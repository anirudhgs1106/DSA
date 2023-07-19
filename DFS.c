//Detecting Cyclye
#include <stdio.h>
#include <stdlib.h>
#define max 100
struct Graph 
{
    int vertices;
    int** adjacencyMatrix;
};
typedef struct Graph *graphs;
graphs create(int vertices) 
{
    graphs graph = (graphs)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->adjacencyMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) 
    {
        graph->adjacencyMatrix[i] = (int*)calloc(vertices, sizeof(int));
    }
    return graph;
}
void addEdge(struct Graph* graph, int source, int dest) 
{
    graph->adjacencyMatrix[source][dest] = 1;
}
int dfs(struct Graph* graph, int vertex, int* visited, int parent) 
{
    visited[vertex] = 1;
    for (int i = 0; i < graph->vertices; i++) 
    {
        if (graph->adjacencyMatrix[vertex][i] == 1) 
        {
            if (visited[i] == 0)
            {
                if (dfs(graph, i, visited, vertex) == 1)
                    return 1;
            }
            else if (i != parent) 
                return 1;
        }
    }
    return 0;
}
int detect(struct Graph* graph) 
{
    int visited[max] = {0};
    for (int i = 0; i < graph->vertices; i++) 
    {
        if (visited[i] == 0) 
        {
            if (dfs(graph, i, visited, -1) == 1)
                return 1;
        }
    }
    return 0;
}

int main() 
{
    int vertices = 6;
    graphs graph = create(vertices);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 1);
    int hasCycle = detect(graph);
    if (hasCycle)
        printf("The graph contains a cycle.\n");
    else
        printf("The graph does not contain a cycle.\n");
    return 0;
}
/*
The graph contains a cycle.
*/