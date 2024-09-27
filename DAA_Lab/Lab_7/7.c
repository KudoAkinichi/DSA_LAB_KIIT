#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

// Function prototypes
int minDistance(int dist[], int sptSet[], int n);
void printSolution(int dist[], int n, int parent[], int src);
void printPath(int parent[], int j);

// Dijkstra's algorithm
void dijkstra(int graph[MAX][MAX], int src, int n)
{
    int dist[MAX];   // Array to hold the shortest distance from the source
    int sptSet[MAX]; // Array to keep track of vertices included in the shortest path tree
    int parent[MAX]; // Array to store the shortest path tree

    // Initialize distances and parent for the path
    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
        sptSet[i] = 0;
        parent[i] = -1;
    }

    // Distance from the source to itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < n - 1; count++)
    {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, sptSet, n);

        // Mark the picked vertex as processed
        sptSet[u] = 1;

        // Update dist[] for the adjacent vertices of the picked vertex
        for (int v = 0; v < n; v++)
        {
            // Update dist[v] only if:
            // - v is not in sptSet
            // - there is an edge from u to v
            // - total weight of path from src to v through u is smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u; // Store the parent of vertex v
            }
        }
    }

    // Print the solution
    printSolution(dist, n, parent, src);
}

// Utility function to find the vertex with the minimum distance
int minDistance(int dist[], int sptSet[], int n)
{
    int min = INF, min_index;

    for (int v = 0; v < n; v++)
    {
        if (!sptSet[v] && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Utility function to print the path from the source to a vertex
void printPath(int parent[], int j)
{
    // Base case: If the vertex is the source itself
    if (parent[j] == -1)
    {
        return;
    }

    // Recurse for the parent
    printPath(parent, parent[j]);

    // Print the current vertex
    printf("->%d", j + 1);
}

// Utility function to print the result
void printSolution(int dist[], int n, int parent[], int src)
{
    printf("Source\tDestination\tCost\tPath\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t", src + 1, i + 1);

        if (dist[i] == INF)
        {
            printf("INF\t-\n");
        }
        else
        {
            printf("%d\t%d", dist[i], src + 1);
            if (i != src)
            {
                printPath(parent, i);
            }
            else
            {
                printf("-");
            }
            printf("\n");
        }
    }
}

int main()
{
    int n;
    int src;

    FILE *file = fopen("inDiAdjMat1.dat", "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the source vertex: ");
    scanf("%d", &src);
    src--; // Adjust for zero-based index

    int graph[MAX][MAX];

    // Reading the adjacency matrix from the file
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(file, "%d", &graph[i][j]);
        }
    }

    fclose(file);

    // Apply Dijkstra's algorithm
    dijkstra(graph, src, n);

    return 0;
}
