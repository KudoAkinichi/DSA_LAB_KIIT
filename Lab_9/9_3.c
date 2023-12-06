// In addition to 9.2, perform deletion of an element in the BST using function.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left, *right;
};

struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int key) {
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;

    if (key < root->key)
        return search(root->left, key);

    return search(root->right, key);
}

struct Node* createBST() {
    struct Node* root = NULL;
    int n, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements of BST: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        root = insert(root, key);
    }

    return root;
}

void printTree(struct Node* root, int space) {
    if (root == NULL)
        return;

    space += 4;

    printTree(root->right, space);

    printf("\n");
    for (int i = 4; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);

    printTree(root->left, space);
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;

        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

int main() {
    struct Node* root = createBST();

    printf("\nBST Created:\n");
    printTree(root, 0);

    int option;
    do {
        printf("\nMAIN MENU\n");
        printf("1. Preorder\n");
        printf("2. Postorder\n");
        printf("3. Inorder\n");
        printf("4. Search\n");
        printf("5. Insert\n");
        printf("6. Delete\n");
        printf("7. Largest\n");
        printf("8. Smallest\n");
        printf("9. Height\n");
        printf("10. Count leaf nodes\n");
        printf("11. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Preorder: ");
                preorder(root);
                break;
            case 2:
                printf("Postorder: ");
                postorder(root);
                break;
            case 3:
                printf("Inorder: ");
                inorder(root);
                break;
            case 4:
                printf("Enter element to search: ");
                scanf("%d", &option);
                if (search(root, option) != NULL)
                    printf("Element found\n");
                else
                    printf("Element not found\n");
                break;
            case 5:
                printf("Enter element to insert in BST: ");
                scanf("%d", &option);
                root = insert(root, option);
                printf("Element inserted\n");
                break;
            case 6:
                printf("Enter element to delete: ");
                scanf("%d", &option);
                root = deleteNode(root, option);
                printf("Element deleted\n");
                break;
            case 7:
                printf("Largest element in BST: %d\n", findLargest(root));
                break;
            case 8:
                printf("Smallest element in BST: %d\n", findSmallest(root));
                break;
            case 9:
                printf("Enter element to find height: ");
                scanf("%d", &option);
                printf("Height of node %d: %d\n", option, findHeight(search(root, option)));
                break;
            case 10:
                printf("Number of leaf nodes: %d\n", countLeafNodes(root));
                break;
            case 11:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid option\n");
        }
    } while (option != 11);

    return 0;
}