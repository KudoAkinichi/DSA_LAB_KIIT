#include <stdio.h>
#include <stdlib.h>

struct Element // struct for non-zero element
{
    int i;
    int j;
    int x;
};

struct Sparse
{
    int m; // number of rows
    int n; // number of columns
    int num; // number of non-zero element
    struct Element *ele; // Dynamic Array
};

void create(struct Sparse *s)
{
    printf("Enter Dimension: ---\n");
    printf("Enter the value of m: ");
    scanf("%d", &s->m);
    printf("Enter the value of n: ");
    scanf("%d", &s->n);

    printf("Enter the number of non-zero element: ");
    scanf("%d", &s->num);

    s->ele = (struct Element *)malloc(s->num * sizeof(struct Element));

    printf("Enter all non-zero elements-----\n");

    for (int i = 0; i < s->num; i++)
    {
        scanf("%d", &s->ele[i].i);
        scanf("%d", &s->ele[i].j);
        scanf("%d", &s->ele[i].x);
    }
}

void display(struct Sparse s)
{
    int i, j, k = 0;
    for (i = 0; i < s.m; i++)
    {
        for (j = 0; j < s.n; j++)
        {
            if (i == s.ele[k].i && j == s.ele[k].j)
            {
                printf("%d ", s.ele[k++].x);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main()
{
    struct Sparse s;
    create(&s);
    display(s);

    return 0;
}
