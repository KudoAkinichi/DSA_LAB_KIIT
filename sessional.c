#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct StackNode {
    struct Node *node;
    struct StackNode *next;
};

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void push(struct StackNode **top_ref, struct Node *node) {
    struct StackNode *new_stack_node = (struct StackNode *)malloc(sizeof(struct StackNode));
    new_stack_node->node = node;
    new_stack_node->next = *top_ref;
    *top_ref = new_stack_node;
}

int isEmpty(struct StackNode *top) {
    return top == NULL;
}

struct Node *pop(struct StackNode **top_ref) {
    if (isEmpty(*top_ref)) {
        return NULL;
    }
    struct StackNode *temp = *top_ref;
    struct Node *popped = temp->node;
    *top_ref = temp->next;
    free(temp);
    return popped;
}

void preorderTraversal(struct Node *root) {
    if (root == NULL) {
        return;
    }

    struct StackNode *stack = NULL;
    push(&stack, root);

    while (!isEmpty(stack)) {
        struct Node *current = pop(&stack);
        printf("%d ", current->data);

        if (current->right != NULL) {
            push(&stack, current->right);
        }
        if (current->left != NULL) {
            push(&stack, current->left);
        }
    }
}

void freeTree(struct Node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct Node *root = NULL;
    int value;

    printf("Enter the value for the root node: ");
    scanf("%d", &value);
    root = createNode(value);

    struct StackNode *stack = NULL;
    push(&stack, root);

    while (!isEmpty(stack)) {
        struct Node *current = pop(&stack);

        printf("Enter left child value for node %d (or -1 if no left child): ", current->data);
        scanf("%d", &value);
        if (value != -1) {
            current->left = createNode(value);
            push(&stack, current->left);
        }

        printf("Enter right child value for node %d (or -1 if no right child): ", current->data);
        scanf("%d", &value);
        if (value != -1) {
            current->right = createNode(value);
            push(&stack, current->right);
        }
    }

    
    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    
    freeTree(root);

    return 0;
}
