#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    struct Node *next;
};

struct Stack {
    struct Node *top;
};

void push(struct Stack *s, char x) {
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL) {
        printf("\nStack Overflow\n");
    } else {
        t->data = x;
        t->next = s->top;
        s->top = t;
    }
}

char pop(struct Stack *s) {
    struct Node *p;
    char x = -1;
    if (s->top == NULL) {
        printf("Stack is Empty");
    } else {
        p = s->top;
        s->top = s->top->next;
        x = p->data;
        free(p);
    }
    return x;
}

void Display(struct Stack s) {
    struct Node *p = s.top;
    printf("Stack:\n");
    while (p != NULL) {
        printf("  +-----+\n");
        printf("  | %c  |\n", p->data);
        p = p->next;
    }
    printf("  +-----+\n");
}

char stackTop(struct Stack s) {
    if (s.top != NULL) {
        return s.top->data;
    }
    return -1;
}

int isEmpty(struct Stack s) {
    return s.top != NULL ? 0 : 1;
}

int isOperand(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/') {
        return 0;
    } else {
        return 1;
    }
}

int precedence(char x) {
    if (x == '+' || x == '-') {
        return 1;
    } else if (x == '*' || x == '/') {
        return 2;
    }
    return 0;
}

char *infix_to_postfix(struct Stack *s, char *infix) {
    char *postfix = (char *)malloc(strlen(infix) + 1);
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        if (isOperand(infix[i])) {
            postfix[j++] = infix[i++];
        } else {
            if (precedence(infix[i]) > precedence(stackTop(*s))) {
                push(s, infix[i++]);
            } else {
                postfix[j++] = pop(s);
            }
        }
    }
    while (!isEmpty(*s)) {
        postfix[j++] = pop(s);
    }
    postfix[j] = '\0';
    return postfix;
}

int main() {
    char infix[100];
    struct Stack s1;
    s1.top = NULL;
    printf("Enter the expression: ");
    scanf("%s", infix);
    char *postfix = infix_to_postfix(&s1, infix);
    printf("Postfix Expression is: %s\n", postfix);
    free(postfix);

    return 0;
}
