// Write a menu driven program to implement priority queue operations such as Enqueue, Dequeue, Traverse using linked list.

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the priority queue
struct Node {
    int data;
    int priority;
    struct Node* next;
};

struct Node* front = NULL;

// Function to create a new node
struct Node* createNode(int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

// Function to enqueue an element with a given priority
void enqueue(int data, int priority) {
    struct Node* newNode = createNode(data, priority);

    if (front == NULL || priority < front->priority) {
        newNode->next = front;
        front = newNode;
    } else {
        struct Node* temp = front;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    printf("Enqueued element: %d with priority %d\n", data, priority);
}

// Function to dequeue the element with the highest priority
void dequeue() {
    if (front == NULL) {
        printf("Priority Queue is empty. Cannot dequeue.\n");
        return;
    }
    struct Node* temp = front;
    printf("Dequeued element: %d with priority %d\n", temp->data, temp->priority);
    front = front->next;
    free(temp);
}

// Function to traverse and display the priority queue
void traverse() {
    if (front == NULL) {
        printf("Priority Queue is empty.\n");
    } else {
        printf("Priority Queue:\n");
        printf("Priority   Item\n");
        struct Node* temp = front;
        while (temp != NULL) {
            printf("%-10d %d\n", temp->priority, temp->data);
            temp = temp->next;
        }
    }
}

int main() {
    int choice, data, priority;

    printf("Main Menu\n");
    do {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &data);
                printf("Enter priority: ");
                scanf("%d", &priority);
                enqueue(data, priority);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                traverse();
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}