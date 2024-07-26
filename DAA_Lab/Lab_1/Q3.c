// Write a program to read ‘n’ integers from a disc file that must contain some duplicate values and store them into an array. Perform the following operations on the array.
// a)	Find out the total number of duplicate elements.
// b)	Find out the most repeating element in the array.

// Input:
// Enter how many numbers you want to read from file: 15

// Output:
// The content of the array: 10 40 35 47 68 22 40 10 98 10 50 35 68 40 10
// Total number of duplicate values = 4
// The most repeating element in the array = 10

#include <stdio.h>
#include <stdlib.h>

int count_duplicates(int *arr, int n)
{
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                break;
            }
        }
    }
    return count;
}

int most_repeating_element(int *arr, int n)
{
    int max_count = 0;
    int most_repeated = arr[0];

    for (int i = 0; i < n; i++)
    {
        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count > max_count)
        {
            max_count = count;
            most_repeated = arr[i];
        }
    }
    return most_repeated;
}

int main()
{
    FILE *file;
    int n;

    printf("Enter how many numbers you want to read from file: ");
    scanf("%d", &n);

    // Allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        perror("Unable to allocate memory");
        return 1;
    }

    file = fopen("input1.txt", "r");
    if (file == NULL)
    {
        perror("Unable to open the file");
        free(arr);
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);

    printf("The content of the array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int total_duplicates = count_duplicates(arr, n);
    printf("Total number of duplicate values = %d\n", total_duplicates);

    int most_repeated = most_repeating_element(arr, n);
    printf("The most repeating element in the array = %d\n", most_repeated);

    free(arr);

    return 0;
}
