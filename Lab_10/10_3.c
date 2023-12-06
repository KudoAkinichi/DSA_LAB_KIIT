// In addition to 10.1, display BFS traversal sequence of the undirected graph.

#include <stdio.h>
#include <stdlib.h>

// Function to perform Breadth First Search (BFS)
void BFS(int startVertex, int numVertices, int graph[][numVertices]) {
    int visited[numVertices];
    for (int i = 0; i < numVertices; ++i)
        visited[i] = 0;

    visited[startVertex] = 1;
    printf("Breadth First Search: %d ", startVertex);

    int queue[numVertices];
    int front = -1, rear = -1;

    queue[++rear] = startVertex;

    while (front != rear) {
        int currentVertex = queue[++front];

        for (int i = 0; i < numVertices; ++i) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                printf("%d ", i);
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

int main() {
    int numVertices;

    // Get the number of vertices from the user
    printf("Enter number of vertices: ");
    scanf("%d", &numVertices);

    int graph[numVertices][numVertices];

    // Populate the adjacency matrix
    printf("Enter Adjacency Matrix:\n");
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            printf("Is there an edge between Vertex %d and Vertex %d? (1 for Yes, 0 for No): ", i, j);
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

    // Get the starting vertex for BFS
    int startVertex;
    printf("\nEnter start vertex for BFS: ");
    scanf("%d", &startVertex);

    // Perform BFS traversal
    BFS(startVertex, numVertices, graph);

    return 0;
}