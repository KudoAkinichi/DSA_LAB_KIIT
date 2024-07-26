// Given an array arr[] of size N, find the prefix sum of the array. A prefix sum array is another array prefixSum[] of the same size, such that the value of prefixSum[i] is arr[0] + arr[1] + arr[2] . . . arr[i].

// Input Array: 	3 	4 	5 	1	 2
// Output Array: 	3 	7 	12 	13 	15

#include <stdio.h>
#include <stdlib.h>

void compute_prefix_sum(int *arr, int *prefix_sum, int n)
{
    prefix_sum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefix_sum[i] = prefix_sum[i - 1] + arr[i];
    }
}

int main()
{
    int n = 10;
    int arr[] = {3, 4, 5, 1, 2, 23, 45, 1, 1, 9};
    int prefix_sum[n];

    compute_prefix_sum(arr, prefix_sum, n);

    printf("Prefix Sum Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", prefix_sum[i]);
    }
    printf("\n");

    return 0;
}
