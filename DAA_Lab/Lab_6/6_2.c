#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Edge
{
    int u, v, w;
};

struct Subset
{
    int parent;
    int rank;
};

int find(struct Subset subsets[], int i);
void Union(struct Subset subsets[], int x, int y);
int compareEdges(const void *a, const void *b);
void Kruskal(struct Edge edges[], int n, int m);

// Main function
int main()
{
    int n, m;
    printf("Enter number of nodes and edges (n m): ");
    scanf("%d %d", &n, &m);

    struct Edge edges[m];
    printf("Enter edges (u v w) where u and v are nodes and w is the weight:\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    Kruskal(edges, n, m);

    return 0;
}

int find(struct Subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(struct Subset subsets[], int x, int y)
{
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else
    {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

int compareEdges(const void *a, const void *b)
{
    struct Edge *edgeA = (struct Edge *)a;
    struct Edge *edgeB = (struct Edge *)b;
    return edgeA->w - edgeB->w;
}

// Function to implement Kruskal's algorithm
void Kruskal(struct Edge edges[], int n, int m)
{
    struct Edge result[MAX]; // Array to store the resultant MST
    int e = 0;               // Number of edges in the MST
    int i = 0;               // Index for sorted edges

    // Step 1: Sort all the edges in non-decreasing order of their weights
    qsort(edges, m, sizeof(edges[0]), compareEdges);

    // Allocate memory for creating subsets
    struct Subset *subsets = (struct Subset *)malloc(n * sizeof(struct Subset));

    // Create n subsets with single elements
    for (int v = 0; v < n; v++)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Step 2: Pick the smallest edge and check if it forms a cycle
    while (e < n - 1 && i < m)
    {
        // Pick the smallest edge
        struct Edge nextEdge = edges[i++];

        int x = find(subsets, nextEdge.u - 1);
        int y = find(subsets, nextEdge.v - 1);

        // If including this edge doesn't cause a cycle, include it in the result
        if (x != y)
        {
            result[e++] = nextEdge;
            Union(subsets, x, y);
        }
    }

    // Print the resultant MST
    printf("Edge    Cost\n");
    int totalWeight = 0;
    for (i = 0; i < e; i++)
    {
        printf("%d--%d    %d\n", result[i].u, result[i].v, result[i].w);
        totalWeight += result[i].w;
    }
    printf("Total Weight of the Spanning Tree: %d\n", totalWeight);

    free(subsets);
}
