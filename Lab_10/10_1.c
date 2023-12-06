// WAP to create an un-directed graph using Adjacency Matrix Method and display the degree of each vertex. 
#include <stdio.h>

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
            if (i != j) {
                char response;
                printf("Vertices %d & %d are Adjacent ? (Y/N) : ", i + 1, j + 1);
                scanf(" %c", &response);
                if (response == 'Y' || response == 'y') {
                    graph[i][j] = 1;
                }
            }
        }
    }

    // Display the degree of each vertex
    printf("\nVertex\t\tDegree\n");
    for (int i = 0; i < numVertices; ++i) {
        int degree = 0;
        for (int j = 0; j < numVertices; ++j) {
            degree += graph[i][j];
        }
        printf("     %d\t\t%d\n", i + 1, degree);
    }

    return 0;
}