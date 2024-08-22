#include <stdio.h>
#include <stdlib.h>

void mergeSort(int arr[], int start, int end);
void merge(int arr[], int start, int mid, int end);

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {23, 323, 435, 345, 324, 567};
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, size);

    printArray(arr, size);

    return 0;
}

// Merge sort function
void mergeSort(int arr[], int start, int end)
{
    if (end - start < 2)
    {
        return;
    }

    int mid = (start + end) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid, end);

    merge(arr, start, mid, end);
}

// Merge function
void merge(int arr[], int start, int mid, int end)
{
    int *temp = (int *)malloc((end - start) * sizeof(int));
    int i = start, j = mid, k = 0;

    while (i < mid && j < end)
    {
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while (i < mid)
    {
        temp[k++] = arr[i++];
    }

    while (j < end)
    {
        temp[k++] = arr[j++];
    }

    for (i = start, k = 0; i < end; i++, k++)
    {
        arr[i] = temp[k];
    }

    free(temp);
}
