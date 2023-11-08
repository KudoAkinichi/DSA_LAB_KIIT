// Write a program to create a circular linked list and display the elements of the list. 

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* insertNode(Node* head, int data) {
    Node* newNode = createNode(data);

    if (head == NULL) {
        newNode->next = newNode; // Point to itself for a single node circular list
        return newNode;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;

    return head;
}

void displayCircularLinkedList(Node* head) {
    if (head == NULL) {
        printf("Circular linked list is empty.\n");
        return;
    }

    Node* current = head;

    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);

    printf("\n");
}

int main() {
    Node* head = NULL;
    int n, data;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter info of node%d: ", i + 1);
        scanf("%d", &data);
        head = insertNode(head, data);
    }

    printf("Clinkedlist: ");
    displayCircularLinkedList(head);

    return 0;
}