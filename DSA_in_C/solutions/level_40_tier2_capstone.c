#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 10
#define INF 999999

struct EdgeNode
{
    int dest;
    int weight; // Driving time in minutes
    struct EdgeNode *next;
};

struct GPSMap
{
    char cityName[MAX_CITIES][30];
    struct EdgeNode *adjList[MAX_CITIES];
    int numCities;
};

// Add road between two cities (Undirected weighted edge)
void addRoad(struct GPSMap *map, int src, int dest, int weight)
{
    struct EdgeNode *newNode = (struct EdgeNode *)malloc(sizeof(struct EdgeNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = map->adjList[src];
    map->adjList[src] = newNode;

    newNode = (struct EdgeNode *)malloc(sizeof(struct EdgeNode));
    newNode->dest = src;
    newNode->weight = weight;
    newNode->next = map->adjList[dest];
    map->adjList[dest] = newNode;
}

// Recursive helper to reconstruct and print the turn-by-turn path from source to target
void printPath(struct GPSMap *map, int parent[], int city)
{
    if (parent[city] == -1)
    {
        printf("%s", map->cityName[city]);
        return;
    }
    printPath(map, parent, parent[city]);
    printf(" -> %s", map->cityName[city]);
}

// Task: Build real-world GPS Route Planner using Dijkstra's Algorithm with Path Reconstruction!
void planShortestRoute(struct GPSMap *map, int startCity, int endCity)
{

    if (map == NULL)
        return;

    int dist[MAX_CITIES];
    int visited[MAX_CITIES];
    int parent[MAX_CITIES];
    for (int i = 0; i < map->numCities; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1; // 👈 Initialize parent to -1!
    }

    dist[startCity] = 0;
    for (int i = 0; i < map->numCities - 1; i++)
    {
        int min = INF;
        int u = -1;
        for (int v = 0; v < map->numCities; v++)
        {
            if (visited[v] == 0 && dist[v] < min)
            {
                min = dist[v];
                u = v;
            }
        }

        visited[u] = 1;
        struct EdgeNode *i = map->adjList[u];
        while (i != NULL)
        {
            if (visited[i->dest] == 0 && i->weight + dist[u] < dist[i->dest])
            {
                dist[i->dest] = i->weight + dist[u];
                parent[i->dest] = u;
            }
            i = i->next;
        }
    }
    printf("Shortest Route from %s to %s:\n", map->cityName[startCity], map->cityName[endCity]);
    printf("Route: ");
    printPath(map, parent, endCity); // 👈 Reconstructs turn-by-turn route!
    printf("\nTotal Driving Time: %d mins\n", dist[endCity]);
}

int main()
{
    struct GPSMap map;
    map.numCities = 6;

    strcpy(map.cityName[0], "New York");
    strcpy(map.cityName[1], "Boston");
    strcpy(map.cityName[2], "Philadelphia");
    strcpy(map.cityName[3], "Washington DC");
    strcpy(map.cityName[4], "Pittsburgh");
    strcpy(map.cityName[5], "Chicago");

    for (int i = 0; i < map.numCities; i++)
    {
        map.adjList[i] = NULL;
    }

    // Add Highway Network (Driving time in minutes):
    addRoad(&map, 0, 1, 215); // New York <-> Boston (215 mins)
    addRoad(&map, 0, 2, 95);  // New York <-> Philadelphia (95 mins)
    addRoad(&map, 1, 4, 340); // Boston <-> Pittsburgh (340 mins)
    addRoad(&map, 2, 3, 140); // Philadelphia <-> Washington DC (140 mins)
    addRoad(&map, 2, 4, 300); // Philadelphia <-> Pittsburgh (300 mins)
    addRoad(&map, 3, 4, 240); // Washington DC <-> Pittsburgh (240 mins)
    addRoad(&map, 4, 5, 280); // Pittsburgh <-> Chicago (280 mins)

    printf("===========================================\n");
    printf("      GPS NAVIGATION ROUTE PLANNER     \n");
    printf("===========================================\n\n");

    // Challenge 1: Plan route from New York (0) to Chicago (5)
    // Expected Output:
    // Route: New York -> Philadelphia -> Pittsburgh -> Chicago
    // Total Driving Time: 675 mins (95 + 300 + 280)
    planShortestRoute(&map, 0, 5);

    printf("\n-------------------------------------------\n\n");

    // Challenge 2: Plan route from Boston (1) to Washington DC (3)
    // Expected Output:
    // Route: Boston -> New York -> Philadelphia -> Washington DC
    // Total Driving Time: 450 mins (215 + 95 + 140)
    planShortestRoute(&map, 1, 3);

    return 0;
}
