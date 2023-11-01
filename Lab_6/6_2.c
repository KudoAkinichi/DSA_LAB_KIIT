#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

void init(struct Stack* stack) {
    stack->top = NULL;
}

int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

void push(struct Stack* stack, int element) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot push element.\n");
        return;
    }
    newNode->data = element;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("%d pushed into the stack.\n", element);
}

void pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop element.\n");
        return;
    }
    struct Node* temp = stack->top;
    stack->top = stack->top->next;
    printf("%d deleted from Stack.\n", temp->data);
    free(temp);
}

void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack: ");
    struct Node* current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    init(&stack);
    int option, element;

    while (1) {
        printf("\nMain Menu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. IsEmpty\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");

        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter element to be pushed into the stack: ");
                scanf("%d", &element);
                push(&stack, element);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                printf("Stack empty: %s\n", isEmpty(&stack) ? "True" : "False");
                break;
            case 4:
                display(&stack);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid option. Please enter a valid option.\n");
        }
    }
}
