// Write a program to create a binary search tree of n data elements using linked list and perform the following menu driven operations:
// i. preorder traversal 
// ii. postorder traversal
// iii. inorder traversal
// iv. search an element

#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary search tree
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to perform preorder traversal
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d  ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function to perform postorder traversal
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d  ", root->data);
    }
}

// Function to perform inorder traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d  ", root->data);
        inorder(root->right);
    }
}

// Function to search for an element in the binary search tree
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

int main() {
    struct Node* root = NULL;
    int n, value, option;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements of BST: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("BST Created:\n\n");
    printf("MAIN MENU\n");
    do {
        printf("1. Preorder\n");
        printf("2. Postorder\n");
        printf("3. Inorder\n");
        printf("4. Search\n");
        printf("5. Exit\n");

        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;
            case 2:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;
            case 3:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Enter element to search: ");
                scanf("%d", &value);
                if (search(root, value) != NULL) {
                    printf("Element %d found in the BST.\n", value);
                } else {
                    printf("Element %d not found in the BST.\n", value);
                }
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option! Please enter a valid option.\n");
        }
    } while (option != 5);

    return 0;
}