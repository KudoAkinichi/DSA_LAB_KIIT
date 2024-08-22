#include <stdio.h>

int binarySearch(int arr[], int low, int high, int target)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;

        // Check if the target is present at mid
        if (arr[mid] == target)
            return mid;

        // If target is smaller than mid, search the left subarray
        if (arr[mid] > target)
            return binarySearch(arr, low, mid - 1, target);

        // If target is larger than mid, search the right subarray
        return binarySearch(arr, mid + 1, high, target);
    }

    // Target is not present in the array
    return -1;
}

int main()
{
    int n, target;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements in sorted order:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &target);

    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found in the array\n");

    return 0;
}
