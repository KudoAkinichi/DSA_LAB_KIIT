#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

int isEmpty()
{
    return front == NULL;
}

void enqueue(int x)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
    {
        printf("\nQueue is Full");
    }
    else
    {
        t->data = x;
        t->next = NULL;
        if (front == NULL)
        {
            front = rear = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue()
{
    int x = -1;
    struct Node *p;
    if (isEmpty())
    {
        printf("\nQueue is Empty");
    }
    else
    {
        p = front;
        front = front->next;
        x = p->data;
        free(p);
    }
    return x;
}

void Display()
{
    struct Node *p = front;
    printf("\nElement of Queue is: \n");
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    int choice, x;
    while (choice != 5)
    {
        printf("\n");
        printf("Enter 1: For Enqueue\n");
        printf("Enter 2: For Dequeue\n");
        printf("Enter 3: For Display\n");
        printf("Enter 4: To Check if Queue is Empty\n");
        printf("Enter 5: For Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to be pushed: ");
            scanf("%d", &x);
            enqueue(x);
            break;
        case 2:
            x = dequeue();
            if (x != -1)
            {
                printf("%d is deleted from the queue\n", x);
            }
            break;
        case 3:
            Display();
            break;
        case 4:
            if (isEmpty())
            {
                printf("Queue is empty.\n");
            }
            else
            {
                printf("Queue is not empty.\n");
            }
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }
    }
    return 0;
}
