#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

struct Node
{
    int dest;
    struct Node *next;
};

struct Graph
{
    struct Node *adjList[MAX_VERTICES];
    int numVertices;
};

// Add undirected edge between src and dest
void addEdge(struct Graph *graph, int src, int dest)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->dest = src;
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Task 1: Breadth-First Search (BFS) starting from startVertex using a Queue
void BFS(struct Graph *graph, int startVertex)
{
    if (graph == NULL)
        return;
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = 0;
    int back = 0;
    // 1. Mark startVertex visited IMMEDIATELY when enqueuing!
    visited[startVertex] = 1;
    queue[back++] = startVertex;
    printf("BFS Traversal: ");
    while (front < back)
    {
        int curr = queue[front++]; // 👈 Use front++
        printf("%d->", curr);
        struct Node *i = graph->adjList[curr];
        while (i != NULL)
        {
            int neighbor = i->dest;
            if (visited[neighbor] == 0)
            {
                visited[neighbor] = 1;    // 👈 Mark visited IMMEDIATELY!
                queue[back++] = neighbor; // 👈 Enqueue!
            }
            i = i->next;
        }
    }
    printf("END\n");
}
// Task 2: Depth-First Search (DFS) helper recursive function
void DFSUtil(struct Graph *graph, int vertex, int visited[])
{
    // Write your code here!
    if (visited[vertex] == 1)
    {
        return;
    }
    visited[vertex] = 1;
    printf("%d->", vertex);
    struct Node *i = graph->adjList[vertex];
    while (i != NULL)
    {
        DFSUtil(graph, i->dest, visited);
        i = i->next;
    }
}

void DFS(struct Graph *graph, int startVertex)
{
    int visited[MAX_VERTICES] = {0};
    printf("DFS Traversal: ");
    DFSUtil(graph, startVertex, visited);
    printf("END");
}

int main()
{
    struct Graph graph;
    graph.numVertices = 6;
    for (int i = 0; i < graph.numVertices; i++)
    {
        graph.adjList[i] = NULL;
    }

    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 1, 4);
    addEdge(&graph, 2, 5);

    // Challenge:
    // 1. Run BFS starting from 0.
    // 2. Run DFS starting from 0.

    BFS(&graph, 0);
    DFS(&graph, 0);

    return 0;
}
