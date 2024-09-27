#include <stdio.h>
#include <limits.h>

void findSecondSmallestAndLargest(int arr[], int n)
{
    int firstSmallest, secondSmallest, firstLargest, secondLargest;

    firstSmallest = secondSmallest = INT_MAX;
    firstLargest = secondLargest = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < firstSmallest)
        {
            secondSmallest = firstSmallest;
            firstSmallest = arr[i];
        }
        else if (arr[i] < secondSmallest && arr[i] != firstSmallest)
        {
            secondSmallest = arr[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > firstLargest)
        {
            secondLargest = firstLargest;
            firstLargest = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] != firstLargest)
        {
            secondLargest = arr[i];
        }
    }

    if (secondSmallest == INT_MAX)
    {
        printf("There is no second smallest element.\n");
    }
    else
    {
        printf("The second smallest element is %d\n", secondSmallest);
    }

    if (secondLargest == INT_MIN)
    {
        printf("There is no second largest element.\n");
    }
    else
    {
        printf("The second largest element is %d\n", secondLargest);
    }
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

    findSecondSmallestAndLargest(arr, n);

    return 0;
}
