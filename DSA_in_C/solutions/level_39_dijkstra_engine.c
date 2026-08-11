#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10
#define INF 999999

struct Node
{
    int dest;
    int weight;
    struct Node *next;
};

struct Graph
{
    struct Node *adjList[MAX_VERTICES];
    int numVertices;
};

void addWeightedEdge(struct Graph *graph, int src, int dest, int weight)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->dest = src;
    newNode->weight = weight;
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void printdist(int max, int dist[])
{
    for (int i = 0; i < max; i++)
    {
        printf("%d: %d\n", i, dist[i]);
    }
}

// Task 1: Dijkstra's Shortest Path Algorithm
void dijkstra(struct Graph *graph, int startVertex)
{
    if (graph == NULL)
        return;

    int dist[MAX_VERTICES];
    int visited[MAX_VERTICES];

    // 1. Initialize
    for (int i = 0; i < graph->numVertices; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[startVertex] = 0;

    // 2. Main Dijkstra Loop
    for (int count = 0; count < graph->numVertices - 1; count++)
    {
        // Find unvisited node u with smallest dist[u]
        int min = INF;
        int u = -1;
        for (int v = 0; v < graph->numVertices; v++)
        {
            if (visited[v] == 0 && dist[v] <= min)
            {
                min = dist[v];
                u = v;
            }
        }

        if (u == -1)
            break;
        visited[u] = 1;

        // Relax all outgoing edges of u
        struct Node *adj = graph->adjList[u];
        while (adj != NULL)
        {
            int v = adj->dest;
            int weight = adj->weight;
            if (visited[v] == 0 && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight; // ⚡ RELAXATION!
            }
            adj = adj->next;
        }
    }

    // 3. Print distances
    printdist(graph->numVertices, dist);
}

int main()
{
    struct Graph graph;
    graph.numVertices = 5;
    for (int i = 0; i < graph.numVertices; i++)
    {
        graph.adjList[i] = NULL;
    }

    addWeightedEdge(&graph, 0, 1, 4);
    addWeightedEdge(&graph, 0, 2, 2);
    addWeightedEdge(&graph, 1, 2, 1);
    addWeightedEdge(&graph, 1, 3, 5);
    addWeightedEdge(&graph, 2, 3, 8);
    addWeightedEdge(&graph, 2, 4, 10);
    addWeightedEdge(&graph, 3, 4, 2);

    // Challenge:
    // Run Dijkstra starting from 0.
    // Expected Shortest Distances from 0:
    // Vertex 0: 0
    // Vertex 1: 3  (Path: 0 -> 2 -> 1, cost = 2 + 1 = 3)
    // Vertex 2: 2  (Path: 0 -> 2, cost = 2)
    // Vertex 3: 8  (Path: 0 -> 2 -> 1 -> 3, cost = 2 + 1 + 5 = 8)
    // Vertex 4: 10 (Path: 0 -> 2 -> 1 -> 3 -> 4, cost = 2 + 1 + 5 + 2 = 10)

    dijkstra(&graph, 0);

    return 0;
}
