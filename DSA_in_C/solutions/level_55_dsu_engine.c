#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

// DSU Struct holding parent array and rank array
typedef struct
{
    int parent[MAX_NODES];
    int rank[MAX_NODES];
    int size;
} DSU;

// Helper: Initialize DSU with N elements (Each element is its own parent)
DSU *createDSU(int n)
{
    DSU *dsu = (DSU *)malloc(sizeof(DSU));
    dsu->size = n;
    for (int i = 0; i < n; i++)
    {
        dsu->parent[i] = i;
        dsu->rank[i] = 0;
    }
    return dsu;
}

// Task 1: findRoot with Path Compression in O(alpha(N))
int findRoot(DSU *dsu, int i)
{
    if (dsu->parent[i] == i)
    {
        return i;
    }
    return dsu->parent[i] = findRoot(dsu, dsu->parent[i]);
}

// Task 2: unionSets with Union by Rank in O(alpha(N))
void unionSets(DSU *dsu, int i, int j)
{
    // Write your code here!
    int rootI = findRoot(dsu, i);
    int rootJ = findRoot(dsu, j);

    if (rootI != rootJ)
    {
        if (dsu->rank[rootI] < dsu->rank[rootJ])
        {
            dsu->parent[rootI] = rootJ;
        }
        else if (dsu->rank[rootJ] < dsu->rank[rootI])
        {
            dsu->parent[rootJ] = rootI;
        }
        else
        {
            dsu->parent[rootJ] = rootI;
            dsu->rank[rootI]++;
        }
    }
}

// Task 3: Check if two nodes belong to the same connected set
bool isConnected(DSU *dsu, int i, int j)
{
    // Write your code here!
    return findRoot(dsu, i) == findRoot(dsu, j);
}

int main()
{
    int N = 6; // Nodes 0, 1, 2, 3, 4, 5
    DSU *dsu = createDSU(N);

    printf("--- Testing Disjoint Set Union (DSU) Engine ---\n");

    // Connect (0, 1) and (1, 2)
    unionSets(dsu, 0, 1);
    unionSets(dsu, 1, 2);

    // Connect (3, 4)
    unionSets(dsu, 3, 4);

    printf("Is 0 connected to 2? %s (Expected: Yes)\n", isConnected(dsu, 0, 2) ? "Yes" : "No");
    printf("Is 0 connected to 3? %s (Expected: No)\n", isConnected(dsu, 0, 3) ? "Yes" : "No");

    // Connect (2, 3) -> Merges set {0,1,2} and set {3,4}!
    unionSets(dsu, 2, 3);

    printf("Is 0 connected to 4 after merging (2,3)? %s (Expected: Yes)\n", isConnected(dsu, 0, 4) ? "Yes" : "No");
    printf("Is 0 connected to 5? %s (Expected: No)\n", isConnected(dsu, 0, 5) ? "Yes" : "No");

    return 0;
}
