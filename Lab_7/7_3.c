#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int front, rear;
    int size;
    int *arr;
};

void initialize(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));
}

int isFull(struct Queue *q)
{
    return ((q->rear + 1) % q->size == q->front);
}

int isEmpty(struct Queue *q)
{
    return (q->front == -1);
}

void enqueue(struct Queue *q, int x)
{
    if (isFull(q))
    {
        printf("Queue is Full\n");
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = x;
        if (q->front == -1)
        {
            q->front = 0;
        }
    }
}

int dequeue(struct Queue *q)
{
    int x = -1;
    if (isEmpty(q))
    {
        printf("Queue is Empty\n");
    }
    else
    {
        x = q->arr[q->front];
        if (q->front == q->rear)
        {
            q->front = q->rear = -1;
        }
        else
        {
            q->front = (q->front + 1) % q->size;
        }
    }
    return x;
}

void traverse(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Queue elements: ");
        int i = q->front;
        while (1)
        {
            printf("%d ", q->arr[i]);
            if (i == q->rear)
                break;
            i = (i + 1) % q->size;
        }
        printf("\n");
    }
}

int main()
{
    int choice, size, x;
    struct Queue q;

    printf("Enter Queue size: ");
    scanf("%d", &size);
    initialize(&q, size);

    while (1)
    {
        printf("\nMain Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. IsEmpty\n");
        printf("4. IsFull\n");
        printf("5. Traverse\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to be pushed: ");
            scanf("%d", &x);
            enqueue(&q, x);
            break;
        case 2:
            x = dequeue(&q);
            if (x != -1)
            {
                printf("%d is deleted from the queue\n", x);
            }
            break;
        case 3:
            if (isEmpty(&q))
            {
                printf("Queue is empty.\n");
            }
            else
            {
                printf("Queue is not empty.\n");
            }
            break;
        case 4:
            if (isFull(&q))
            {
                printf("Queue is full.\n");
            }
            else
            {
                printf("Queue is not full.\n");
            }
            break;
        case 5:
            traverse(&q);
            break;
        case 6:
            free(q.arr);
            exit(0);
            break;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
