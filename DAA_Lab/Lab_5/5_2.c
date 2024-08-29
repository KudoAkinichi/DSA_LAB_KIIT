#include <stdio.h>
#include <stdlib.h>

// Define the SYMBOL structure
struct SYMBOL
{
    char alphabet;
    int frequency;
};

// Define the Huffman Tree Node structure
struct Node
{
    char alphabet;
    int frequency;
    struct Node *left, *right;
};

// Function prototypes
struct Node *createNode(char alphabet, int frequency);
void insertMinHeap(struct Node *heap[], int *size, struct Node *node);
struct Node *extractMin(struct Node *heap[], int *size);
void buildHuffmanTree(struct SYMBOL symbols[], int n);
void inOrderTraversal(struct Node *root);

int main()
{
    int n;

    printf("Enter the number of distinct alphabets: ");
    scanf("%d", &n);

    struct SYMBOL symbols[n];

    printf("Enter the alphabets: ");
    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &symbols[i].alphabet); // space before %c to consume newline
    }

    printf("Enter its frequencies: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &symbols[i].frequency);
    }

    // Build the Huffman Tree
    buildHuffmanTree(symbols, n);

    return 0;
}

// Function to create a new node
struct Node *createNode(char alphabet, int frequency)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->alphabet = alphabet;
    node->frequency = frequency;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a node into the Min-Heap
void insertMinHeap(struct Node *heap[], int *size, struct Node *node)
{
    int i = (*size)++;
    while (i && node->frequency < heap[(i - 1) / 2]->frequency)
    {
        heap[i] = heap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap[i] = node;
}

// Function to extract the node with the minimum frequency from the Min-Heap
struct Node *extractMin(struct Node *heap[], int *size)
{
    struct Node *temp = heap[0];
    heap[0] = heap[--(*size)];
    int i = 0, smallest = 0;

    do
    {
        i = smallest;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < *size && heap[left]->frequency < heap[smallest]->frequency)
            smallest = left;
        if (right < *size && heap[right]->frequency < heap[smallest]->frequency)
            smallest = right;
        if (smallest != i)
        {
            struct Node *t = heap[i];
            heap[i] = heap[smallest];
            heap[smallest] = t;
        }
    } while (smallest != i);

    return temp;
}

// Function to build the Huffman Tree
void buildHuffmanTree(struct SYMBOL symbols[], int n)
{
    struct Node *minHeap[n];
    int size = 0;

    // Create a leaf node for each symbol and insert it into the Min-Heap
    for (int i = 0; i < n; i++)
    {
        minHeap[i] = createNode(symbols[i].alphabet, symbols[i].frequency);
        size++;
    }

    // Build the Huffman Tree
    while (size > 1)
    {
        struct Node *left = extractMin(minHeap, &size);
        struct Node *right = extractMin(minHeap, &size);

        struct Node *top = createNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, &size, top);
    }

    // The remaining node is the root of the Huffman Tree
    struct Node *root = extractMin(minHeap, &size);

    // Print in-order traversal of the Huffman Tree
    printf("In-order traversal of the tree (Huffman): ");
    inOrderTraversal(root);
    printf("\n");
}

// Function for in-order traversal of the Huffman Tree
void inOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        if (root->alphabet != '$') // Skip internal nodes represented by '$'
            printf("%c ", root->alphabet);
        inOrderTraversal(root->right);
    }
}
