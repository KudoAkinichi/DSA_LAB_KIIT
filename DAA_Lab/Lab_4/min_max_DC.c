#include <stdio.h>

void findMinAndMax(int arr[], int low, int high, int *min, int *max)
{
    // If there is only one element
    if (low == high)
    {
        *min = arr[low];
        *max = arr[low];
        return;
    }

    // If there are two elements
    if (high == low + 1)
    {
        if (arr[low] < arr[high])
        {
            *min = arr[low];
            *max = arr[high];
        }
        else
        {
            *min = arr[high];
            *max = arr[low];
        }
        return;
    }

    // If there are more than two elements
    int mid = (low + high) / 2;

    int min1, max1, min2, max2;

    // Recur for left half
    findMinAndMax(arr, low, mid, &min1, &max1);

    // Recur for right half
    findMinAndMax(arr, mid + 1, high, &min2, &max2);

    // Combine results
    *min = (min1 < min2) ? min1 : min2;
    *max = (max1 > max2) ? max1 : max2;
}

int main()
{
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int min, max;
    findMinAndMax(arr, 0, n - 1, &min, &max);

    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);

    return 0;
}
