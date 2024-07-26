// Write a menu driven program to implement Deques (both Inputrestricted and output-restricted) 
// and performed operations such as Enqueue, Dequeue, Peek, IsEmpty, IsFull using static array.

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct Deque {
    int front, rear;
    int arr[MAX_SIZE];
};

void initDeque(struct Deque* dq) {
    dq->front = -1;
    dq->rear = -1;
}

int isFull(struct Deque* dq) {
    return ((dq->rear == MAX_SIZE - 1 && dq->front == 0) || (dq->front == dq->rear + 1));
}

int isEmpty(struct Deque* dq) {
    return (dq->front == -1);
}

void insertRight(struct Deque* dq, int element) {
    if (isFull(dq)) {
        printf("Deque is full. Cannot insert.\n");
    } else {
        if (dq->front == -1) {
            dq->front = 0;
            dq->rear = 0;
        } else if (dq->rear == MAX_SIZE - 1) {
            dq->rear = 0;
        } else {
            dq->rear++;
        }
        dq->arr[dq->rear] = element;
        printf("Inserted %d at the right end.\n", element);
    }
}

void deleteLeft(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty. Cannot delete.\n");
    } else {
        int deleted = dq->arr[dq->front];
        if (dq->front == dq->rear) {
            dq->front = -1;
            dq->rear = -1;
        } else if (dq->front == MAX_SIZE - 1) {
            dq->front = 0;
        } else {
            dq->front++;
        }
        printf("%d deleted from the left end.\n", deleted);
    }
}

void deleteRight(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty. Cannot delete.\n");
    } else {
        int deleted = dq->arr[dq->rear];
        if (dq->front == dq->rear) {
            dq->front = -1;
            dq->rear = -1;
        } else if (dq->rear == 0) {
            dq->rear = MAX_SIZE - 1;
        } else {
            dq->rear--;
        }
        printf("%d deleted from the right end.\n", deleted);
    }
}

void display(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
    } else {
        printf("Deque: ");
        int i = dq->front;
        while (1) {
            printf("%d", dq->arr[i]);
            if (i == dq->rear) {
                break;
            }
            i = (i + 1) % MAX_SIZE;
            printf(" ");
        }
        printf("\n");
    }
}

int main() {
    struct Deque dq;
    initDeque(&dq);

    int choice, element;

    printf("Input restricted Deque Menu\n");
    do {
        printf("1. Insert at right\n");
        printf("2. Delete from left\n");
        printf("3. Delete from right\n");
        printf("4. Display\n");
        printf("5. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &element);
                insertRight(&dq, element);
                break;
            case 2:
                deleteLeft(&dq);
                break;
            case 3:
                deleteRight(&dq);
                break;
            case 4:
                display(&dq);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}