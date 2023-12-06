// In addition to 10.1, display DFS traversal sequence of the undirected graph.
#include <stdio.h>

// Function to perform Depth First Search (DFS)
void DFS(int vertex, int numVertices, int graph[numVertices][numVertices], int visited[]) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    for (int i = 0; i < numVertices; ++i) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(i, numVertices, graph, visited);
        }
    }
}

int main() {
    int numVertices;

    // Get the number of vertices from the user
    printf("Enter number of vertices: ");
    scanf("%d", &numVertices);

    int graph[numVertices][numVertices];

    // Initialize the graph with zeros
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            graph[i][j] = 0;
        }
    }

    // Populate the adjacency matrix
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            printf("Adjacency Matrix[%d][%d]: ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }

    // Display the degree of each vertex
    printf("\nVertex\t\tDegree\n");
    for (int i = 0; i < numVertices; ++i) {
        int degree = 0;
        for (int j = 0; j < numVertices; ++j) {
            degree += graph[i][j];
        }
        printf("     %d\t\t%d\n", i, degree);
    }

    // Get the starting vertex for DFS
    int startVertex;
    printf("\nEnter start vertex for DFS: ");
    scanf("%d", &startVertex);

    // Initialize visited array
    int visited[numVertices];
    for (int i = 0; i < numVertices; ++i) {
        visited[i] = 0;
    }

    // Perform DFS traversal
    printf("Depth First Search: ");
    DFS(startVertex, numVertices, graph, visited);

    return 0;
}