//Network Broadcast
#include <stdio.h>
#include <stdlib.h>
#define max 100
struct Graph 
{
    int vertices;
    int **adjacencyMatrix;
};
typedef struct Graph *graphs; 
struct Queue 
{
    int front, rear;
    int capacity;
    int *elements;
};
typedef struct Queue *que;
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
void addEdge(graphs graph, int source, int dest) 
{
    graph->adjacencyMatrix[source][dest] = 1;
    graph->adjacencyMatrix[dest][source] = 1;
}
que createQueue(int capacity) 
{
    que queue = (que)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = -1;
    queue->rear = -1;
    queue->elements = (int*)malloc(capacity * sizeof(int));
    return queue;
}
int isEmpty(que queue) 
{
    return queue->front == -1;
}

void enqueue(que queue, int item) 
{
    if (queue->rear == queue->capacity - 1)
        return;
    if (queue->front == -1)
        queue->front = 0;
    queue->rear++;
    queue->elements[queue->rear] = item;
}
int dequeue(que queue) 
{
    if (isEmpty(queue))
        return -1;
    int item = queue->elements[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
    }
    return item;
}
void network_broadcast(graphs graph, int src_vertex) 
{
    int visited[max] = {0};
    que queue = createQueue(max);

    visited[src_vertex] = 1;
    enqueue(queue, src_vertex);

    printf("Network Broadcast starts %d:\n", src_vertex);

    while (!isEmpty(queue)) 
    {
        int currentVertex = dequeue(queue);
        printf("Broadcasting from vertex %d\n", currentVertex);

        for (int i = 0; i < graph->vertices; i++) 
        {
            if (graph->adjacencyMatrix[currentVertex][i] == 1 && visited[i] == 0) 
            {
                visited[i] = 1;
                enqueue(queue, i);
            }
        }
    }
    free(queue);
}
int main() 
{
    int vertices = 7;
    struct Graph* graph = create(vertices);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 2, 5);
    addEdge(graph, 3, 6);
    addEdge(graph, 4, 6);
    addEdge(graph, 5, 6);
    int src_vertex = 0;
    network_broadcast(graph, src_vertex);
    return 0;
}
/*
Network Broadcast starts 0:
Broadcasting from vertex 0
Broadcasting from vertex 1
Broadcasting from vertex 2
Broadcasting from vertex 3
Broadcasting from vertex 4
Broadcasting from vertex 5
Broadcasting from vertex 6
*/
