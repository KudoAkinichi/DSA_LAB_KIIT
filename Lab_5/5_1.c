// WAP to insert , delete and traverse in a double linked list.

//Write a program to create a double linked list and perform the following menu based operations on it:
//i. insert an element at specific position 
//ii. delete an element from specific position
//iii. Traverse the list

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

typedef struct Node Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertNodeAtPosition(Node** head, int data, int position) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    if (position == 1) {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    Node* current = *head;
    int currentPosition = 1;

    while (currentPosition < position - 1 && current->next != NULL) {
        current = current->next;
        currentPosition++;
    }

    if (currentPosition == position - 1) {
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;
    } else {
        printf("Invalid position\n");
    }
}

void deleteNodeAtPosition(Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (position == 1) {
        Node* temp = *head;
        *head = (*head)->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }

    Node* current = *head;
    int currentPosition = 1;

    while (currentPosition < position && current != NULL) {
        current = current->next;
        currentPosition++;
    }

    if (currentPosition == position && current != NULL) {
        current->prev->next = current->next;
        if (current->next != NULL) {
            current->next->prev = current->prev;
        }
        free(current);
    } else {
        printf("Invalid position\n");
    }
}

void traverseList(Node* head) {
    printf("The list is: ");
    while (head != NULL) {
        printf("%d-> ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int n, data, position, choice;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertNodeAtPosition(&head, data, i + 1);
    }

    do {
        printf("MENU:\n");
        printf("1. Insert a node at a position\n");
        printf("2. Delete a node from a specific position\n");
        printf("3. Traversal\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertNodeAtPosition(&head, data, position);
                printf("Node inserted\n");
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteNodeAtPosition(&head, position);
                printf("Node deleted\n");
                break;
            case 3:
                traverseList(head);
                break;
            case 4:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}

