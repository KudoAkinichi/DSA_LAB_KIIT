#include <stdio.h>
#include <limits.h>

#define INF 9999999

void primMST(int graph[100][100], int n, int start)
{
    int parent[100]; // Array to store constructed MST
    int key[100];    // Key values used to pick minimum weight edge
    int mstSet[100]; // To represent set of vertices included in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < n; i++)
    {
        key[i] = INF;
        mstSet[i] = 0;
    }

    // Start from the given vertex (convert to zero-indexed)
    start--;
    key[start] = 0;     // Key of starting vertex is set to 0 so that it is picked first
    parent[start] = -1; // First node is always the root of MST

    // The MST will have n vertices
    for (int count = 0; count < n - 1; count++)
    {
        // Find the vertex with the minimum key value from the set of vertices not yet included in MST
        int min = INF, minIndex;

        for (int v = 0; v < n; v++)
        {
            if (mstSet[v] == 0 && key[v] < min)
            {
                min = key[v];
                minIndex = v;
            }
        }

        int u = minIndex;
        mstSet[u] = 1; // Add the picked vertex to the MST Set

        // Update key values and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the MST
    int mstGraph[100][100] = {0};
    int totalWeight = 0;
    printf("Cost Adjacency Matrix of the Minimum Spanning Tree:\n");

    for (int i = 1; i < n; i++)
    {
        int u = parent[i];
        int v = i;
        mstGraph[u][v] = mstGraph[v][u] = graph[u][v];
        totalWeight += graph[u][v];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", mstGraph[i][j]);
        }
        printf("\n");
    }

    printf("Total Weight of the Spanning Tree: %d\n", totalWeight);
}

int main()
{
    FILE *inputFile;
    inputFile = fopen("inUnAdjMat.dat", "r");

    if (inputFile == NULL)
    {
        printf("Error in opening input file!\n");
        return 1;
    }

    int graph[100][100], n, start;

    // Read the number of vertices
    printf("Enter the Number of Vertices: ");
    scanf("%d", &n);

    // Read the starting vertex
    printf("Enter the Starting Vertex: ");
    scanf("%d", &start);

    // Read the adjacency matrix from the file
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(inputFile, "%d", &graph[i][j]);
        }
    }

    fclose(inputFile);

    // Apply Prim's algorithm
    primMST(graph, n, start);

    return 0;
}
