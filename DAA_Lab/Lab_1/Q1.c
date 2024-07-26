#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void find_second_smallest_largest(int *arr, int n, int *second_smallest, int *second_largest)
{
    int smallest, largest;

    if (n < 2)
    {
        printf("Array must have at least two elements.\n");
        return;
    }

    smallest = INT_MAX;
    largest = INT_MIN;
    *second_smallest = INT_MAX;
    *second_largest = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            *second_smallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] < *second_smallest && arr[i] != smallest)
        {
            *second_smallest = arr[i];
        }

        if (arr[i] > largest)
        {
            *second_largest = largest;
            largest = arr[i];
        }
        else if (arr[i] > *second_largest && arr[i] != largest)
        {
            *second_largest = arr[i];
        }
    }

    if (*second_smallest == INT_MAX)
    {
        printf("There is no second smallest element.\n");
        *second_smallest = -1;
    }
    if (*second_largest == INT_MIN)
    {
        printf("There is no second largest element.\n");
        *second_largest = -1;
    }
}

int main()
{
    FILE *file;
    int n;
    int *arr;
    int second_smallest, second_largest;

    // Open the file for reading
    file = fopen("input.txt", "r");
    if (file == NULL)
    {
        perror("Unable to open the file");
        return 1;
    }

    // Read the size of the array
    fscanf(file, "%d", &n);
    if (n <= 0)
    {
        printf("Invalid array size.\n");
        fclose(file);
        return 1;
    }

    // Allocate memory for the array
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        perror("Unable to allocate memory");
        fclose(file);
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);

    find_second_smallest_largest(arr, n, &second_smallest, &second_largest);

    if (second_smallest != -1)
    {
        printf("Second smallest element: %d\n", second_smallest);
    }
    if (second_largest != -1)
    {
        printf("Second largest element: %d\n", second_largest);
    }

    free(arr);

    return 0;
}
