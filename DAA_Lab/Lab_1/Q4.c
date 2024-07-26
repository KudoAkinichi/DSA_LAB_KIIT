// Write a function to ROTATE_RIGHT(p1, p2 ) right an array for first p2 elements by 1 position using EXCHANGE(p, q) function that swaps/exchanges the numbers p & q. Parameter p1 be the starting address of the array and p2 be the number of elements to be rotated.

// Input:
// Enter an array A of size N (9): 11 22 33 44 55 66 77 88 99
// Call the function ROTATE_RIGHT(A, 5)
// Output:
// Before ROTATE: 	11 22 33 44 55 66 77 88 99
// After   ROTATE: 	55 11 22 33 44 66 77 88 99

#include <stdio.h>

void EXCHANGE(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

void ROTATE_RIGHT(int *arr, int p2)
{
    if (p2 > 1)
    {
        // Store the last element of the first p2 elements
        int last = arr[p2 - 1];

        // Shift elements to the right
        for (int i = p2 - 1; i > 0; i--)
        {
            EXCHANGE(&arr[i], &arr[i - 1]);
        }

        // Place the last element to the first position
        arr[0] = last;
    }
}

int main()
{
    int n = 9;
    int arr[] = {11, 22, 33, 44, 55, 66, 77, 88, 99};
    int p2 = 5;

    printf("Before ROTATE:\t");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    ROTATE_RIGHT(arr, p2);

    printf("After ROTATE:\t");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
