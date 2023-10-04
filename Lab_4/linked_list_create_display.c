// Linked list creation

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node)); // Creating a temp node
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void insertAtFirst(struct Node *p, int x) {
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if (!t) {
        // Handle memory allocation failure if necessary
        return;
    }
    t->data = x;
    t->next = *p;
    *p = t;
}

void insertAtMiddle(struct Node *p, int index, int x) {
    if (index < 0) {
        // Handle invalid index if necessary
        return;
    }

    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if (!t) {
        // Handle memory allocation failure if necessary
        return;
    }
    t->data = x;

    if (index == 0) {
        // Inserting before the first node
        t->next = p;
        return;
    }

    for (int i = 0; i < index - 1 && p; i++) {
        p = p->next;
    }

    if (p) {
        t->next = p->next;
        p->next = t;
    }
}


void insertLast(struct Node *p, int x)
{
    struct Node *t, *last;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (first == NULL) // Insert at first
    {
        first = last = t;
    }
    else
    {
        last = p;
        while (last->next)
        {
            last = last->next;
        }
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);

        p = p->next;
    }
}

int main()
{
    int A[] = {1, 24, 5, 6, 7, 7, 20};
    create(A, 5);
    insertAtFirst(first, 999);
    insertLast(first, 12);
    insertLast(first, 1233);
    insertLast(first, 124534);
    Display(first);

    return 0;
}
