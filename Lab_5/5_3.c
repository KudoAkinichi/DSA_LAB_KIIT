// Write a program to represent the given sparse matrix using header single linked list and display it.

#include <stdio.h>
#include <stdlib.h>

// Define a structure for each node in the linked list
struct Node {
    int row, col, value;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int row, int col, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to display the sparse matrix in 3-tuple format
void displaySparseMatrix(struct Node* head, int rows, int cols) {
    printf("Sparse matrix in 3-tuple format\n");
    printf("%d %d %d\n", rows, cols, head->value);
    struct Node* current = head->next;
    while (current != NULL) {
        printf("%d %d %d\n", current->row, current->col, current->value);
        current = current->next;
    }
}

int main() {
    int rows, cols;
    printf("Enter size of the sparse matrix: ");
    scanf("%d %d", &rows, &cols);

    struct Node* header = createNode(-1, -1, 0); // Create a header node
    struct Node* previous[cols]; // Array to keep track of the previous node in each column

    for (int i = 0; i < cols; i++) {
        previous[i] = header; // Initialize the previous nodes to the header
    }

    printf("Enter elements of sparse matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int value;
            scanf("%d", &value);

            if (value != 0) {
                struct Node* newNode = createNode(i, j, value);
                newNode->next = previous[j]->next;
                previous[j]->next = newNode;
                previous[j] = newNode; // Update the previous node for this column
            }
        }
    }

    displaySparseMatrix(header, rows, cols);

    // Free allocated memory
    struct Node* current = header;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}