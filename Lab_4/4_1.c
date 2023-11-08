#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* current = *head;
        for (int i = 1; i < position - 1 && current; i++)
            current = current->next;
        if (!current) {
            printf("Invalid position\n");
            free(newNode);
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    printf("Node inserted successfully\n");
}

void deleteNode(struct Node** head, int position) {
    if (!*head) {
        printf("List is empty, cannot delete\n");
        return;
    }
    struct Node* temp = NULL;
    if (position == 1) {
        temp = *head;
        *head = (*head)->next;
    } else {
        struct Node* current = *head;
        for (int i = 1; i < position - 1 && current; i++)
            current = current->next;
        if (!current || !current->next) {
            printf("Invalid position\n");
            return;
        }
        temp = current->next;
        current->next = temp->next;
    }
    free(temp);
    printf("Node deleted successfully\n");
}

int countNodes(struct Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

int searchElement(struct Node* head, int key) {
    int position = 1;
    while (head) {
        if (head->data == key)
            return position;
        position++;
        head = head->next;
    }
    return -1;
}

void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    printf("List reversed successfully\n");
}

void displayList(struct Node* head) {
    printf("The list is: ");
    while (head) {
        printf("%d", head->data);
        if (head->next)
            printf("->");
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position, count, key;

    printf("Enter number of nodes: ");    int numNodes;
    scanf("%d", &numNodes);

    printf("Enter the elements: ");
    for (int i = 0; i < numNodes; i++) {
        scanf("%d", &data);
        insertNode(&head, data, i + 1);
    }

    while (1) {
        printf("\nMENU:\n1. Insert the node at a position\n2. Delete a node from specific position\n");
        printf("3. Count\n4. Traversal\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertNode(&head, data, position);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteNode(&head, position);
                break;
            case 3:
                count = countNodes(head);
                printf("The total number of nodes: %d\n", count);
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}