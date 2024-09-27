#include <stdio.h>

void prefixSum(int arr[], int n, int prefixArr[])
{
    prefixArr[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        prefixArr[i] = prefixArr[i - 1] + arr[i];
    }
}

int main()
{
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n], prefixArr[n];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    prefixSum(arr, n, prefixArr);

    printf("Prefix sum of the array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", prefixArr[i]);
    }
    printf("\n");

    return 0;
}
