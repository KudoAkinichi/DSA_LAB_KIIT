//WAP to create a 1-D array of n elements and perform the following menu based operations using function.
//a. insert a given element at specific position.
//b. delete an element from a specific position of the array.
//c. linear search to search an element
//d. traversal of the array 

#include <stdio.h>


void insertElement(int arr[], int *size, int position, int element) {
    if (*size >= position) {
        for (int i = *size; i >= position; i--) {
            arr[i] = arr[i - 1];
        }
        arr[position - 1] = element;
        (*size)++;
        printf("Element inserted successfully.\n");
    } else {
        printf("Invalid position for insertion.\n");
    }
}


void deleteElement(int arr[], int *size, int position) {
    if (*size > 0 && position >= 1 && position <= *size) {
        for (int i = position - 1; i < *size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        (*size)--;
        printf("Element deleted successfully.\n");
    } else {
        printf("Invalid position for deletion.\n");
    }
}

int linearSearch(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1; 
}


void traverseArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100],i;
    int size;
    int choice, element, position, index;
    
    printf("Enter the size of array: ");
    scanf("%d",&size);
    int a[size];
    for (i=0; i<size; i++){
        printf("Enter %d element: ",i);
        scanf("%d",&arr[i]);
    }

    do {
        printf("\n");
        printf("Menu:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Linear search\n");
        printf("4. Traverse the array\n");
        printf("5. Exit\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n");
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                insertElement(arr, &size, position, element);
                break;
            case 2:
                printf("\n");
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deleteElement(arr, &size, position);
                break;
            case 3:
                printf("\n");
                printf("Enter the element to search: ");
                scanf("%d", &element);
                index = linearSearch(arr, size, element);
                if (index != -1) {
                    printf("Element found at index %d.\n", index);
                } else {
                    printf("Element not found.\n");
                }
                break;
            case 4:
                printf("\n");
                traverseArray(arr, size);
                break;
            case 5:
                printf("\n");
                printf("Exiting the program.\n");
                printf("\n");
                break;
            default:
                printf("\n");
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}