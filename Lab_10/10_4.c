// WAP to create a directed graph using Adjacency Matrix Method and display the degree of each vertex.

#include <stdio.h>

int main() {
    int numVertices;

    // Get the number of vertices from the user
    printf("Enter number of vertices: ");
    scanf("%d", &numVertices);

    int inDegree[numVertices], outDegree[numVertices], totalDegree[numVertices];

    // Initialize degrees
    for (int i = 0; i < numVertices; ++i) {
        inDegree[i] = outDegree[i] = totalDegree[i] = 0;
    }

    // Create and populate the adjacency matrix
    int graph[numVertices][numVertices];
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            graph[i][j] = 0;
        }
    }

    // Populate the adjacency matrix and calculate degrees
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            char response;
            printf("Vertices %d & %d are Adjacent ? (Y/N) : ", i + 1, j + 1);
            scanf(" %c", &response);

            if (response == 'Y' || response == 'y') {
                graph[i][j] = 1;
                outDegree[i]++;
                inDegree[j]++;
                totalDegree[i]++;
                totalDegree[j]++;
            }
        }
    }

    // Display the degree of each vertex
    printf("\nVertex\t\tIn_Degree\tOut_Degree\tTotal_Degree\n");
    for (int i = 0; i < numVertices; ++i) {
        printf("     %d\t\t%d\t\t%d\t\t%d\n", i + 1, inDegree[i], outDegree[i], totalDegree[i]);
    }

    return 0;
}