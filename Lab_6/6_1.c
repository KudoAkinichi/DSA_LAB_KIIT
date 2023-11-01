#include <stdio.h>

#define MAX_SIZE 100

struct Stack {
    int arr[MAX_SIZE];
    int top;
};

void init(struct Stack *s) {
    s->top = -1;
}

int isFull(struct Stack *s) {
    return s->top == MAX_SIZE - 1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

void push(struct Stack *s, int element) {
    if (isFull(s)) {
        printf("Stack is full. Cannot push element.\n");
    } else {
        s->arr[++s->top] = element;
        printf("%d pushed into the stack.\n", element);
    }
}

void pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot pop element.\n");
    } else {
        printf("%d deleted from Stack.\n", s->arr[s->top--]);
    }
}

void display(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack: ");
        for (int i = 0; i <= s->top; i++) {
            printf("%d ", s->arr[i]);
        }
        printf("\n");
    }
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
        printf("4. IsFull\n");
        printf("5. Traverse\n");
        printf("6. Exit\n");

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
                printf("Stack full: %s\n", isFull(&stack) ? "True" : "False");
                break;
            case 5:
                display(&stack);
                break;
            case 6:
                return 0;
            default:
                printf("Invalid option. Please enter a valid option.\n");
        }
    }
}
