#include <stdio.h>
#include <stdlib.h>

// Define the ITEM structure
struct ITEM
{
    int item_id;
    float item_profit;
    float item_weight;
    float profit_weight_ratio;
};

// Function prototypes
void heapify(struct ITEM arr[], int n, int i);
void heapSort(struct ITEM arr[], int n);
void fractional_knapsack(struct ITEM items[], int n, float capacity);

int main()
{
    int n;
    float capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct ITEM items[n];

    // Input item data
    for (int i = 0; i < n; i++)
    {
        items[i].item_id = i + 1;
        printf("Enter the profit and weight of item no %d: ", i + 1);
        scanf("%f %f", &items[i].item_profit, &items[i].item_weight);
        items[i].profit_weight_ratio = items[i].item_profit / items[i].item_weight;
    }

    printf("Enter the capacity of knapsack: ");
    scanf("%f", &capacity);

    // Sort the items using heap sort based on profit/weight ratio
    heapSort(items, n);

    // Calculate the maximum profit using the fractional knapsack algorithm
    fractional_knapsack(items, n, capacity);

    return 0;
}

// Function to heapify a subtree rooted with node i
void heapify(struct ITEM arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = left;

    if (right < n && arr[right].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = right;

    if (largest != i)
    {
        struct ITEM temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

// Function to perform heap sort
void heapSort(struct ITEM arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        struct ITEM temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

// Function to calculate the maximum profit using the fractional knapsack algorithm
void fractional_knapsack(struct ITEM items[], int n, float capacity)
{
    float total_profit = 0.0;
    float remaining_capacity = capacity;

    printf("\nItem No\t\tProfit\t\tWeight\t\tAmount to be taken\n");

    for (int i = 0; i < n; i++)
    {
        if (items[i].item_weight <= remaining_capacity)
        {
            remaining_capacity -= items[i].item_weight;
            total_profit += items[i].item_profit;
            printf("%d\t\t%.6f\t\t%.6f\t\t1.000000\n", items[i].item_id, items[i].item_profit, items[i].item_weight);
        }
        else
        {
            float fraction = remaining_capacity / items[i].item_weight;
            total_profit += items[i].item_profit * fraction;
            printf("%d\t\t%.6f\t\t%.6f\t\t%.6f\n", items[i].item_id, items[i].item_profit, items[i].item_weight, fraction);
            break;
        }
    }

    printf("Maximum profit: %.6f\n", total_profit);
}
