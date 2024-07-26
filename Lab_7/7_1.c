// Write a menu driven program to create a linear queue using array and perform Enqueue, Dequeue, Traverse, IsEmpty, IsFull operations.

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent the queue
struct Queue {
    int front, rear, size;
    int array[MAX_SIZE];
};

// Function to create an empty queue
struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (!queue) {
        return NULL; // Memory allocation failed
    }
    queue->front = queue->size = 0;
    queue->rear = capacity - 1; // Initialize rear as the last index
    return queue;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->size == MAX_SIZE);
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Function to enqueue an element to the queue
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full. Enqueue operation failed.\n");
        return;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->array[queue->rear] = item;
    queue->size++;
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Dequeue operation failed.\n");
        return -1; // Return a special value to indicate the queue is empty
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
    queue->size--;
    return item;
}

// Function to traverse and print the queue
void traverse(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    int i;
    for (i = 0; i < queue->size; i++) {
        printf("%d", queue->array[(queue->front + i) % MAX_SIZE]);
        if (i < queue->size - 1) {
            printf("  ");
        }
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue(MAX_SIZE);
    int option, element;

    printf("Enter the size of Queue: %d\n", MAX_SIZE);

    do {
        printf("Main Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. IsEmpty\n");
        printf("4. IsFull\n");
        printf("5. Traverse\n");
        printf("6. Exit\n");

        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &element);
                enqueue(queue, element);
                break;
            case 2:
                element = dequeue(queue);
                if (element != -1) {
                    printf("Element %d dequeued\n", element);
                }
                break;
            case 3:
                if (isEmpty(queue)) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
            case 4:
                if (isFull(queue)) {
                    printf("Queue is full.\n");
                } else {
                    printf("Queue is not full.\n");
                }
                break;
            case 5:
                traverse(queue);
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (option != 6);

return 0;
}