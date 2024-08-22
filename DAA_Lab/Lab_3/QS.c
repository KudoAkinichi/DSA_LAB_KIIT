#include <stdio.h>

void quickSort(int nums[], int low, int hi);
void printArray(int nums[], int size);

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, size - 1);

    printArray(arr, size);

    return 0;
}

// QuickSort function
void quickSort(int nums[], int low, int hi)
{
    if (low >= hi)
    {
        return;
    }

    int s = low;
    int e = hi;
    int m = s + (e - s) / 2;
    int pivot = nums[m];

    while (s <= e)
    {
        // Find the correct position for the pivot
        while (nums[s] < pivot)
        {
            s++;
        }
        while (nums[e] > pivot)
        {
            e--;
        }

        if (s <= e)
        {
            // Swap elements
            int temp = nums[s];
            nums[s] = nums[e];
            nums[e] = temp;
            s++;
            e--;
        }
    }

    quickSort(nums, low, e);
    quickSort(nums, s, hi);
}

// Function to print an array
void printArray(int nums[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
}
